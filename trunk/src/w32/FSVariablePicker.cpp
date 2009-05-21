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

#include "FSVariable.h"
#include "FSVariablePicker.h"

#include <string.h>

void FSVariablePicker::AddVariable(const char* const& name)
{
    for(unsigned int i = 0; i < vars.GetCount(); ++i)
    {
        if(!strcmp(vars[i]->name, name))
        {
            // no need to add a variable - one already exists
            return;
        }
    }
    vars.Push(new FSVariable(name));
}

void FSVariablePicker::visitMain(Main* main)
{
    main->listblock_->accept(this);
}

void FSVariablePicker::visitBStmt(BStmt* bstmt)
{
    bstmt->liststatement_->accept(this);
}

void FSVariablePicker::visitListBlock(ListBlock* listblock)
{
    while(listblock)
    {
        listblock->block_->accept(this);
        listblock = listblock->listblock_;
    }
}

void FSVariablePicker::visitListStatement(ListStatement* liststatement)
{
    while(liststatement)
    {
        liststatement->statement_->accept(this);
        liststatement = liststatement->liststatement_;
    }
}

void FSVariablePicker::visitSExp(SExp* sexp)
{
    sexp->expression_->accept(this);
}

void FSVariablePicker::visitSRet(SRet* sret)
{
    sret->expression_->accept(this);
}

void FSVariablePicker::visitSIf(SIf* sif)
{
    sif->expression_->accept(this);
    sif->statement_->accept(this);
}

void FSVariablePicker::visitSIfElse(SIfElse* sifelse)
{
    sifelse->expression_->accept(this);
    sifelse->statement_1->accept(this);
    sifelse->statement_2->accept(this);
}

void FSVariablePicker::visitSWhile(SWhile* swhile)
{
    swhile->expression_->accept(this);
    swhile->statement_->accept(this);
}

void FSVariablePicker::visitSUntil(SUntil* suntil)
{
    suntil->expression_->accept(this);
    suntil->statement_->accept(this);
}

void FSVariablePicker::visitSFor(SFor* sfor)
{
    sfor->listexpression_1->accept(this);
    sfor->listexpression_2->accept(this);
    sfor->expression_->accept(this);
    sfor->statement_->accept(this);
}

void FSVariablePicker::visitEVar(EVar *p)
{
    AddVariable(p->ident_);
}

void FSVariablePicker::visitECall(ECall* ecall)
{
    ecall->listexpression_->accept(this);
}

void FSVariablePicker::visitEPostInc(EPostInc* epostinc)
{
    AddVariable(epostinc->ident_);
}

void FSVariablePicker::visitEPostDec(EPostDec* epostdec)
{
    AddVariable(epostdec->ident_);
}

void FSVariablePicker::visitEPreInc(EPreInc* epreinc)
{
    AddVariable(epreinc->ident_);
}

void FSVariablePicker::visitEPreDec(EPreDec* epredec)
{
    AddVariable(epredec->ident_);
}

void FSVariablePicker::visitEAss(EAss* eass)
{
    AddVariable(eass->ident_);
}

void FSVariablePicker::visitEAddAss(EAddAss* eaddass)
{
    AddVariable(eaddass->ident_);
}

void FSVariablePicker::visitESubAss(ESubAss* esubass)
{
    AddVariable(esubass->ident_);
}

void FSVariablePicker::visitEMulAss(EMulAss* emulass)
{
    AddVariable(emulass->ident_);
}

void FSVariablePicker::visitEDivAss(EDivAss* edivass)
{
    AddVariable(edivass->ident_);
}

void FSVariablePicker::visitEModAss(EModAss* emodass)
{
    AddVariable(emodass->ident_);
}

void FSVariablePicker::visitEAndAss(EAndAss* eandass)
{
    AddVariable(eandass->ident_);
}

void FSVariablePicker::visitEOrAss(EOrAss* eorass)
{
    AddVariable(eorass->ident_);
}

void FSVariablePicker::visitEXorAss(EXorAss* exorass)
{
    AddVariable(exorass->ident_);
}

void FSVariablePicker::visitELShAss(ELShAss* elshass)
{
    AddVariable(elshass->ident_);
}

void FSVariablePicker::visitERShAss(ERShAss* ershass)
{
    AddVariable(ershass->ident_);
}

void FSVariablePicker::visitListExpression(ListExpression* listexpression)
{
    while(listexpression)
    {
        listexpression->expression_->accept(this);
        listexpression = listexpression->listexpression_;
    }
}
