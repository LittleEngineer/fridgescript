/*
    This file is part of FSAssembler.

    FSAssembler is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FSAssembler is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with FSAssembler.  If not, see <http://www.gnu.org/licenses/>
*/

#include "FSAssembler.h"

#include <stdio.h>
#include <string.h>

#include "FSOperandVisitor.h"
#include "Parser.H"

#define _export extern "C" unsigned int __declspec(dllexport) __stdcall
#define _exportbptr extern "C" unsigned char __declspec(dllexport)* __stdcall

///////////////////////////////////////////////
// E X P O R T E D    F U N C T I O N S
///////////////////////////////////////////////

///////////////////////////////////////////////
// FSAssemble : Generates bytes from assembler
///////////////////////////////////////////////

_exportbptr FSAssemble(const char* const& source, unsigned int& length)
{
    // write to a temporary file
    // this can probably be cleaned up
    FILE* pTmpFile = tmpfile();

    fwrite(source, 1, strlen(source), pTmpFile);

    rewind(pTmpFile);

    // parse
    Code* code = pCode(pTmpFile);
    bool error = false;
    FSAssembler parseTree = FSAssembler();

    // assemble
    if(code)
    {    
        code->accept(&parseTree);
    }
    else
    {
        // error
        error = true;
        length = 0;
    }

    // cleanup file
    fclose(pTmpFile);
    
    if(error) return 0;

    // create the output string
    length = parseTree.GetBytes().GetCount();

    unsigned char* ret = new unsigned char[length];
    for(unsigned int i = 0; i < length; ++i) ret[i] = parseTree.GetBytes()[i];
    return ret;
}

///////////////////////////////////////////////
// FSAFree : To free the result of FSAssemble
///////////////////////////////////////////////

_export FSAFree(unsigned char* ptr)
{
    delete[] ptr;

    return 0;
}

///////////////////////////////////////////////
// H E L P E R    F U N C T I O N S
///////////////////////////////////////////////

void FSAssembler::AddLabel(const char* const& name, unsigned int position)
{
    // if it already exists just update position, this lets labels be referenced, e.g. by JMP, before they are defined ...
    for(unsigned int i = 0; i < labels.GetCount(); ++i)
    {
        if(labels[i]->name == name)
        {
            if(position) labels[i]->location = position;
            return;
        }
    }

    // ... otherwise, just add a new label
    labels.Push(new FSALabel(name, position));
}

void FSAssembler::AddLabelReference(const char* const& name, unsigned int position)
{
    // if the label already exists, add this pointer to its reference list ...
    for(unsigned int i = 0; i < labels.GetCount(); ++i)
    {
        if(labels[i]->name == name)
        {
            labels[i]->refs.Push(position);
            return;
        }
    }

    // ... otherwise, add a new label and then add a reference.
    // this allows labels to be used before their positions are known, e.g. for forward jumps.
    AddLabel(name, 0);
    labels[labels.GetCount() - 1]->refs.Push(position);
}

void FSAssembler::ResolveLabels()
{
    // for each label ...
    for(unsigned int i = 0; i < labels.GetCount(); ++i)
    {
        // for each reference to the label ...
        for(unsigned int j = 0; j < labels[i]->refs.GetCount(); ++j)
        {
            // find the relative location in bytes (unsigned chars)
            // -4 to adjust for the length of the relative offset itself
            int val = static_cast<int>(labels[i]->location) - static_cast<int>(labels[i]->refs[j]) - 4;
            // convert it into a pointer to the bytes in the integer
            unsigned char* rel = reinterpret_cast<unsigned char*>(&val);
            // replace the dummy value in code with the relative offset
            for(unsigned int k = 0; k < 4; ++k) out[labels[i]->refs[j] + k] = rel[k];
        }
    }
}

///////////////////////////////////////////////
// A S S E M B L E R
///////////////////////////////////////////////

///////////////////////////////////////////////
// Main : The whole program
///////////////////////////////////////////////

void FSAssembler::visitMain(Main* main)
{
    main->listoperation_->accept(this);
    ResolveLabels();
}

void FSAssembler::visitListOperation(ListOperation* listoperation)
{
    while(listoperation)
    {
        listoperation->operation_->accept(this);
        listoperation = listoperation->listoperation_;
    }
}

void FSAssembler::visitOAddC(OAddC* oAddC)
{
}

void FSAssembler::visitOSubC(OSubC* oSubC)
{
}

void FSAssembler::visitOLbl(OLbl* oLbl)
{
    // store the label position
    // it should never be a duplicate... the assembler is only really meant for FridgeScript output...
    AddLabel(oLbl->ident_, out.GetCount());
}

void FSAssembler::visitOJmp(OJmp* oJmp)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::JMP);
    out.Push(0xE9);
    oJmp->operand_->accept(&operand);
    // the address now starts at the next stack position
    AddLabelReference(operand.GetLastLabel().GetPointer(), out.GetCount());
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOJb(OJb* oJb)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::JMP);
    out.Push(0x0F);
    out.Push(0x82);
    oJb->operand_->accept(&operand);
    // the address now starts at the next stack position
    AddLabelReference(operand.GetLastLabel().GetPointer(), out.GetCount());
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOJbe(OJbe* oJbe)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::JMP);
    out.Push(0x0F);
    out.Push(0x86);
    oJbe->operand_->accept(&operand);
    // the address now starts at the next stack position
    AddLabelReference(operand.GetLastLabel().GetPointer(), out.GetCount());
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOJe(OJe* oJe)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::JMP);
    out.Push(0x0F);
    out.Push(0x84);
    oJe->operand_->accept(&operand);
    // the address now starts at the next stack position
    AddLabelReference(operand.GetLastLabel().GetPointer(), out.GetCount());
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOJne(OJne* oJne)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::JMP);
    out.Push(0x0F);
    out.Push(0x85);
    oJne->operand_->accept(&operand);
    // the address now starts at the next stack position
    AddLabelReference(operand.GetLastLabel().GetPointer(), out.GetCount());
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOJz(OJz* oJz)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::JMP);
    out.Push(0x0F);
    out.Push(0x84);
    oJz->operand_->accept(&operand);
    // the address now starts at the next stack position
    AddLabelReference(operand.GetLastLabel().GetPointer(), out.GetCount());
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOJnz(OJnz* oJnz)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::JMP);
    out.Push(0x0F);
    out.Push(0x85);
    oJnz->operand_->accept(&operand);
    // the address now starts at the next stack position
    AddLabelReference(operand.GetLastLabel().GetPointer(), out.GetCount());
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOCall(OCall* oCall) {}

void FSAssembler::visitORet(ORet* oRet)
{
    out.Push(0xC3);
}
 
void FSAssembler::visitOPush(OPush* opush)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::PUSH);
    opush->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOPop(OPop* opop)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::POP);
    opop->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOFabs(OFabs* ofabs)
{
    out.Push(0xD9);
    out.Push(0xE1);
}

void FSAssembler::visitOFadd(OFadd* ofadd)
{
    out.Push(0xD8);
    out.Push(0xC1);
}

void FSAssembler::visitOFaddp(OFaddp* ofaddp)
{
    out.Push(0xDE);
    out.Push(0xC1);
}

void FSAssembler::visitOFsub(OFsub* ofsub)
{
    out.Push(0xDC);
    out.Push(0xE9);
}

void FSAssembler::visitOFsubp(OFsubp* ofsubp)
{
    out.Push(0xDE);
    out.Push(0xE9);
}

void FSAssembler::visitOFsubrp(OFsubrp* ofsubrp)
{
    out.Push(0xDE);
    out.Push(0xE1);
}

void FSAssembler::visitOFmulp(OFmulp* ofmulp)
{
    out.Push(0xDE);
    out.Push(0xC9);
}

void FSAssembler::visitOFdivp(OFdivp* ofdivp)
{
    out.Push(0xDE);
    out.Push(0xF9);
}

void FSAssembler::visitOFdivrp(OFdivrp* ofdivrp)
{
    out.Push(0xDE);
    out.Push(0xF1);
}

void FSAssembler::visitOFchs(OFchs* ofchs)
{
    out.Push(0xD9);
    out.Push(0xE0);
}

void FSAssembler::visitOFsin(OFsin* ofsin)
{
    out.Push(0xD9);
    out.Push(0xFE);
}

void FSAssembler::visitOFcos(OFcos* ofcos)
{
    out.Push(0xD9);
    out.Push(0xFF);
}

void FSAssembler::visitOFprem(OFprem* ofprem)
{
    out.Push(0xD9);
    out.Push(0xF8);
}

void FSAssembler::visitOFptan(OFptan* ofptan)
{
    out.Push(0xD9);
    out.Push(0xF2);
}

void FSAssembler::visitOFpatan(OFpatan* ofpatan)
{
    out.Push(0xD9);
    out.Push(0xF3);
}

void FSAssembler::visitOFsqrt(OFsqrt* ofsqrt)
{
    out.Push(0xD9);
    out.Push(0xFA);
}

void FSAssembler::visitOFrndint(OFrndint* ofrndint)
{
    out.Push(0xD9);
    out.Push(0xFC);
}

void FSAssembler::visitOFscale(OFscale* ofscale)
{
    out.Push(0xD9);
    out.Push(0xFD);
}

void FSAssembler::visitOFtxmo(OFtxmo* oftxmo)
{
    out.Push(0xD9);
    out.Push(0xF0);
}

void FSAssembler::visitOFyltx(OFyltx* ofyltx)
{
    out.Push(0xD9);
    out.Push(0xF1);
}

void FSAssembler::visitOFyltxpo(OFyltxpo* ofyltxpo)
{
    out.Push(0xD9);
    out.Push(0xF9);
}

void FSAssembler::visitOFcomi(OFcomi* ofcomi)
{
    out.Push(0xDB);
    out.Push(0xF1);
}

void FSAssembler::visitOFcmovb(OFcmovb* ofcmovb)
{
    out.Push(0xDA);
    out.Push(0xC1);
}

void FSAssembler::visitOFcmovbe(OFcmovbe* ofcmovbe)
{
    out.Push(0xDA);
    out.Push(0xD1);
}

void FSAssembler::visitOFcmove(OFcmove* ofcmove)
{
    out.Push(0xDA);
    out.Push(0xC9);
}

void FSAssembler::visitOFcmovnb(OFcmovnb* ofcmovnb)
{
    out.Push(0xDB);
    out.Push(0xC1);
}

void FSAssembler::visitOFcmovnbe(OFcmovnbe* ofcmovnbe)
{
    out.Push(0xDB);
    out.Push(0xD1);
}

void FSAssembler::visitOFcmovne(OFcmovne* ofcmovne)
{
    out.Push(0xDB);
    out.Push(0xC9);
}

void FSAssembler::visitOFcmovnu(OFcmovnu* ofcmovnu)
{
    out.Push(0xDB);
    out.Push(0xD9);
}

void FSAssembler::visitOFcmovu(OFcmovu* ofcmovu)
{
    out.Push(0xDA);
    out.Push(0xD9);
}

void FSAssembler::visitOFld(OFld* ofld)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::FLD);
    out.Push(0xDD);
    ofld->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOFild(OFild* ofild)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::FILD);
    out.Push(0xDB);
    ofild->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOFldt(OFldt* ofldt)
{
    out.Push(0xD9);
    out.Push(0xC0);
}

void FSAssembler::visitOFldn(OFldn* ofldn)
{
    out.Push(0xD9);
    out.Push(0xC1);
}

void FSAssembler::visitOFldz(OFldz* ofldz)
{
    out.Push(0xD9);
    out.Push(0xEE);
}

void FSAssembler::visitOFldo(OFldo* ofldo)
{
    out.Push(0xD9);
    out.Push(0xE8);
}

void FSAssembler::visitOFldpi(OFldpi* ofldpi)
{
    out.Push(0xD9);
    out.Push(0xEB);
}

void FSAssembler::visitOFldlte(OFldlte* ofldlte)
{
    out.Push(0xD9);
    out.Push(0xEA);
}

void FSAssembler::visitOFldlnt(OFldlnt* ofldlnt)
{
    out.Push(0xD9);
    out.Push(0xED);
}

void FSAssembler::visitOFldlgt(OFldlgt* ofldlgt)
{
    out.Push(0xD9);
    out.Push(0xEC);
}

void FSAssembler::visitOFst(OFst* ofst)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::FST);
    out.Push(0xDD);
    ofst->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOFist(OFist* ofist)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::FIST);
    out.Push(0xDB);
    ofist->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOFstp(OFstp* ofstp)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::FSTP);
    out.Push(0xDD);
    ofstp->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOFistp(OFistp* ofistp)
{
    FSOperandVisitor operand = FSOperandVisitor(FSOperandVisitor::FSOVType::FISTP);
    out.Push(0xDB);
    ofistp->operand_->accept(&operand);
    for(unsigned int i = 0; i < operand.GetBytes().GetCount(); ++i)
    {
        out.Push(operand.GetBytes()[i]);
    }
}

void FSAssembler::visitOFstpt(OFstpt* ofstpt)
{
    out.Push(0xDD);
    out.Push(0xD8);
}

void FSAssembler::visitOFfree(OFfree* offree)
{
    out.Push(0xDD);
    out.Push(0xC0);
}

void FSAssembler::visitOFfreea(OFfreea* offreea)
{
    out.Push(0xDD);
    out.Push(0xC1);
}

void FSAssembler::visitOFfreeb(OFfreeb* offreeb)
{
    out.Push(0xDD);
    out.Push(0xC2);
}

void FSAssembler::visitOFfreec(OFfreec* offreec)
{
    out.Push(0xDD);
    out.Push(0xC3);
}

void FSAssembler::visitOFfreed(OFfreed* offreed)
{
    out.Push(0xDD);
    out.Push(0xC4);
}

void FSAssembler::visitOFfreee(OFfreee* offreee)
{
    out.Push(0xDD);
    out.Push(0xC5);
}

void FSAssembler::visitOFfreef(OFfreef* offreef)
{
    out.Push(0xDD);
    out.Push(0xC6);
}

void FSAssembler::visitOFfreeg(OFfreeg* offreeg)
{
    out.Push(0xDD);
    out.Push(0xC7);
}


void FSAssembler::visitOFxchg(OFxchg* ofxchg)
{
    out.Push(0xD9);
    out.Push(0xC9);
}

void FSAssembler::visitOFincstp(OFincstp* ofincstp)
{
    out.Push(0xD9);
    out.Push(0xF7);
}

void FSAssembler::visitOFdecstp(OFdecstp* ofdecstp)
{
    out.Push(0xD9);
    out.Push(0xF6);
}