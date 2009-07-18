/*
    This file is part of FridgeScript.

    FridgeScript is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FridgeScript is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with FridgeScript.  If not, see <http://www.gnu.org/licenses/>
*/

// main header
#include <Core/FridgeScript.h>

// this file's header
#include <Code/FSAssemblerComment.h>

void FSAssemblerComment::visitEPi(EPi* epi)
{
    comment += "pi";
}

void FSAssemblerComment::visitECDbl(ECDbl* ecdbl)
{
    comment += "<double constant>";
}

void FSAssemblerComment::visitECInt(ECInt* ecint)
{
    comment.AppendInt( ecint->integer_ );
}

void FSAssemblerComment::visitEVar(EVar *p)
{
    comment += p->ident_;
}

void FSAssemblerComment::visitECall(ECall* ecall)
{
    comment += ecall->ident_;
    comment += "( ";
    ecall->listexpression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitEPostInc(EPostInc* epostinc)
{
    comment += epostinc->ident_;
    comment += "++";
}

void FSAssemblerComment::visitEPostDec(EPostDec* epostdec)
{
    comment += epostdec->ident_;
    comment += "--";
}

void FSAssemblerComment::visitEAbs(EAbs* eabs)
{
    comment += "abs( ";
    eabs->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitEPow(EPow* epow)
{
}

void FSAssemblerComment::visitESqrt(ESqrt* esqrt)
{
    comment += "sqrt( ";
    esqrt->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitEExp(EExp* eexp)
{
    comment += "sqrt( ";
    eexp->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitELog(ELog* elog)
{
    comment += "log( ";
    elog->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitELogD(ELogD* elogd)
{
    comment += "log10( ";
    elogd->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitESin(ESin* esin)
{
    comment += "sin( ";
    esin->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitECos(ECos* ecos)
{
    comment += "cos( ";
    ecos->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitETan(ETan* etan)
{
    comment += "tan( ";
    etan->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitEAtan(EAtan* eatan)
{
    comment += "atan( ";
    eatan->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitEAtanT(EAtanT* eatant)
{
}

void FSAssemblerComment::visitEAsin(EAsin* easin)
{
    comment += "asin( ";
    easin->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitEAcos(EAcos* eacos)
{
    comment += "acos( ";
    eacos->expression_->accept( this );
    comment += " )";
}

void FSAssemblerComment::visitELnot(ELnot* elnot)
{
    comment += "!";
    elnot->expression_->accept( this );
}

void FSAssemblerComment::visitEPreInc(EPreInc* epreinc)
{
    comment += "++";
    comment += epreinc->ident_;
}

void FSAssemblerComment::visitEPreDec(EPreDec* epredec)
{
    comment += "--";
    comment += epredec->ident_;
}

void FSAssemblerComment::visitENeg(ENeg* eneg)
{
    comment += "-";
    eneg->expression_->accept( this );
}

void FSAssemblerComment::visitEBnot(EBnot* ebnot)
{
    comment += "~";
    ebnot->expression_->accept( this );
}

void FSAssemblerComment::visitEPos(EPos* epos)
{
    comment += "+";
    epos->expression_->accept( this );
}

void FSAssemblerComment::visitEMul(EMul* emul)
{
    emul->expression_1->accept( this );
    comment += " * ";
    emul->expression_2->accept( this );
}

void FSAssemblerComment::visitEDiv(EDiv* ediv)
{
    ediv->expression_1->accept( this );
    comment += " / ";
    ediv->expression_2->accept( this );
}

void FSAssemblerComment::visitEMod(EMod* emod)
{
    emod->expression_1->accept( this );
    comment += " % ";
    emod->expression_2->accept( this );
}

void FSAssemblerComment::visitEAdd(EAdd* eadd)
{
    eadd->expression_1->accept( this );
    comment += " + ";
    eadd->expression_2->accept( this );
}

void FSAssemblerComment::visitESub(ESub* esub)
{
    esub->expression_1->accept( this );
    comment += " - ";
    esub->expression_2->accept( this );
}

void FSAssemblerComment::visitELSh(ELSh* elsh)
{
}

void FSAssemblerComment::visitERSh(ERSh* ersh)
{
}

void FSAssemblerComment::visitELT(ELT* elt)
{
    elt->expression_1->accept( this );
    comment += " < ";
    elt->expression_2->accept( this );
}

void FSAssemblerComment::visitEGT(EGT* egt)
{
    egt->expression_1->accept( this );
    comment += " > ";
    egt->expression_2->accept( this );
}

void FSAssemblerComment::visitELE(ELE* ele)
{
    ele->expression_1->accept( this );
    comment += " <= ";
    ele->expression_2->accept( this );
}

void FSAssemblerComment::visitEGE(EGE* ege)
{
    ege->expression_1->accept( this );
    comment += " >= ";
    ege->expression_2->accept( this );
}

void FSAssemblerComment::visitEE(EE* ee)
{
    ee->expression_1->accept( this );
    comment += " == ";
    ee->expression_2->accept( this );
}

void FSAssemblerComment::visitENE(ENE* ene)
{
    ene->expression_1->accept( this );
    comment += " != ";
    ene->expression_2->accept( this );
}

void FSAssemblerComment::visitEBand(EBand* eband)
{
    eband->expression_1->accept( this );
    comment += " & ";
    eband->expression_2->accept( this );
}

void FSAssemblerComment::visitEBor(EBor* ebor)
{
    ebor->expression_1->accept( this );
    comment += " | ";
    ebor->expression_2->accept( this );
}

void FSAssemblerComment::visitEBxor(EBxor* ebxor)
{
    ebxor->expression_1->accept( this );
    comment += " ^ ";
    ebxor->expression_2->accept( this );
}

void FSAssemblerComment::visitELand(ELand* eland)
{
    eland->expression_1->accept( this );
    comment += " && ";
    eland->expression_2->accept( this );
}

void FSAssemblerComment::visitELor(ELor* elor)
{
    elor->expression_1->accept( this );
    comment += " || ";
    elor->expression_2->accept( this );
}

void FSAssemblerComment::visitELxor(ELxor* elxor)
{
    elxor->expression_1->accept( this );
    comment += " ^^ ";
    elxor->expression_2->accept( this );
}

void FSAssemblerComment::visitECon(ECon* econ)
{
}

void FSAssemblerComment::visitEAss(EAss* eass)
{
    comment += eass->ident_;
    comment += " = ";
    eass->expression_->accept( this );
}

void FSAssemblerComment::visitEAddAss(EAddAss* eaddass)
{
    comment += eaddass->ident_;
    comment += " += ";
    eaddass->expression_->accept( this );
}

void FSAssemblerComment::visitESubAss(ESubAss* esubass)
{
    comment += esubass->ident_;
    comment += " -= ";
    esubass->expression_->accept( this );
}

void FSAssemblerComment::visitEMulAss(EMulAss* emulass)
{
    comment += emulass->ident_;
    comment += " *= ";
    emulass->expression_->accept( this );
}

void FSAssemblerComment::visitEDivAss(EDivAss* edivass)
{
    comment += edivass->ident_;
    comment += " /= ";
    edivass->expression_->accept( this );
}

void FSAssemblerComment::visitEModAss(EModAss* emodass)
{
    comment += emodass->ident_;
    comment += " %= ";
    emodass->expression_->accept( this );
}

void FSAssemblerComment::visitEAndAss(EAndAss* eandass)
{
    comment += eandass->ident_;
    comment += " &= ";
    eandass->expression_->accept( this );
}

void FSAssemblerComment::visitEOrAss(EOrAss* eorass)
{
    comment += eorass->ident_;
    comment += " |= ";
    eorass->expression_->accept( this );
}

void FSAssemblerComment::visitEXorAss(EXorAss* exorass)
{
    comment += exorass->ident_;
    comment += " ^= ";
    exorass->expression_->accept( this );
}

void FSAssemblerComment::visitELShAss(ELShAss* elshass)
{
}

void FSAssemblerComment::visitERShAss(ERShAss* ershass)
{
}

void FSAssemblerComment::visitListExpression(ListExpression* listexpression)
{
    while( listexpression )
    {
        // convert each expression to assembler and emit
        listexpression->expression_->accept( this );
        
        if( listexpression->listexpression_ )
        {
            comment += ", ";
        }
        
        // iterate over the list
        listexpression = listexpression->listexpression_;
    }
}
