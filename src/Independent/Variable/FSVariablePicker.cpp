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
#include <Variable/FSVariablePicker.h>

// FridgeScript headers
#include <Variable/FSVariable.h>

// C/C++ headers
#include <string.h>

void FSVariablePicker::AddVariable(const char* const& name)
{
    for( unsigned int i = 0; i < vars.GetCount(); ++i )
    {
        if( !strcmp( vars[i]->name, name ) )
        {
            // no need to add a variable - one already exists
            return;
        }
    }
    vars.Push( new FSVariable( name ) );
}

void FSVariablePicker::visitMain(Main* main)
{
    main->listblock_->accept( this );
}

void FSVariablePicker::visitBStmt(BStmt* bstmt)
{
    bstmt->liststatement_->accept( this );
}

void FSVariablePicker::visitListBlock(ListBlock* listblock)
{
    while( listblock )
    {
        listblock->block_->accept( this );
        listblock = listblock->listblock_;
    }
}

void FSVariablePicker::visitListStatement(ListStatement* liststatement)
{
    while( liststatement )
    {
        liststatement->statement_->accept( this );
        liststatement = liststatement->liststatement_;
    }
}

void FSVariablePicker::visitSExp(SExp* sexp)
{
    sexp->expression_->accept( this );
}

void FSVariablePicker::visitSScope(SScope* sscope)
{
    sscope->liststatement_->accept( this );
}

void FSVariablePicker::visitSRet(SRet* sret)
{
    sret->expression_->accept( this );
}

void FSVariablePicker::visitSIf(SIf* sif)
{
    sif->expression_->accept( this );
    sif->liststatement_->accept( this );
}

void FSVariablePicker::visitSIfElse(SIfElse* sifelse)
{
    sifelse->expression_->accept( this );
    sifelse->liststatement_1->accept( this );
    sifelse->liststatement_2->accept( this );
}

void FSVariablePicker::visitSWhile(SWhile* swhile)
{
    swhile->expression_->accept( this );
    swhile->liststatement_->accept( this );
}

void FSVariablePicker::visitSUntil(SUntil* suntil)
{
    suntil->expression_->accept( this );
    suntil->liststatement_->accept( this );
}

void FSVariablePicker::visitSFor(SFor* sfor)
{
    sfor->listexpression_1->accept( this );
    sfor->listexpression_2->accept( this );
    sfor->expression_->accept( this );
    sfor->liststatement_->accept( this );
}

void FSVariablePicker::visitEVar(EVar *p)
{
    AddVariable( p->ident_ );
}

void FSVariablePicker::visitECall(ECall* ecall)
{
    ecall->listexpression_->accept( this );
}

void FSVariablePicker::visitEPostInc(EPostInc* epostinc)
{
    AddVariable( epostinc->ident_ );
}

void FSVariablePicker::visitEPostDec(EPostDec* epostdec)
{
    AddVariable( epostdec->ident_ );
}

void FSVariablePicker::visitEAbs(EAbs* eabs)
{
    eabs->expression_->accept( this );
}

void FSVariablePicker::visitEPow(EPow* epow)
{
    epow->expression_1->accept( this );
    epow->expression_2->accept( this );
}

void FSVariablePicker::visitESqrt(ESqrt* esqrt)
{
    esqrt->expression_->accept( this );
}

void FSVariablePicker::visitEExp(EExp* eexp)
{
    eexp->expression_->accept( this );
}

void FSVariablePicker::visitELog(ELog* elog)
{
    elog->expression_->accept( this );
}

void FSVariablePicker::visitELogD(ELogD* elogd)
{
    elogd->expression_->accept( this );
}

void FSVariablePicker::visitESin(ESin* esin)
{
    esin->expression_->accept( this );
}

void FSVariablePicker::visitECos(ECos* ecos)
{
    ecos->expression_->accept( this );
}

void FSVariablePicker::visitETan(ETan* etan)
{
    etan->expression_->accept( this );
}

void FSVariablePicker::visitEAtan(EAtan* eatan)
{
    eatan->expression_->accept( this );
}

void FSVariablePicker::visitEAtanT(EAtanT* eatant)
{
    eatant->expression_1->accept( this );
    eatant->expression_2->accept( this );
}

void FSVariablePicker::visitEAsin(EAsin* easin)
{
    easin->expression_->accept( this );
}

void FSVariablePicker::visitEAcos(EAcos* eacos)
{
    eacos->expression_->accept( this );
}

void FSVariablePicker::visitELnot(ELnot* elnot)
{
    elnot->expression_->accept( this );
}    

void FSVariablePicker::visitEPreInc(EPreInc* epreinc)
{
    AddVariable( epreinc->ident_ );
}

void FSVariablePicker::visitEPreDec(EPreDec* epredec)
{
    AddVariable( epredec->ident_ );
}

void FSVariablePicker::visitENeg(ENeg* eneg)
{
    eneg->expression_->accept( this );
}

void FSVariablePicker::visitEBnot(EBnot* ebnot)
{
    ebnot->expression_->accept( this );
}

void FSVariablePicker::visitEPos(EPos* epos)
{
    epos->expression_->accept( this );
}

void FSVariablePicker::visitEMul(EMul* emul)
{
    emul->expression_1->accept( this );
    emul->expression_2->accept( this );
}

void FSVariablePicker::visitEDiv(EDiv* ediv)
{
    ediv->expression_1->accept( this );
    ediv->expression_2->accept( this );
}

void FSVariablePicker::visitEMod(EMod* emod)
{
    emod->expression_1->accept( this );
    emod->expression_2->accept( this );
}

void FSVariablePicker::visitEAdd(EAdd* eadd)
{
    eadd->expression_1->accept( this );
    eadd->expression_2->accept( this );
}

void FSVariablePicker::visitESub(ESub* esub)
{
    esub->expression_1->accept( this );
    esub->expression_2->accept( this );
}

void FSVariablePicker::visitELSh(ELSh* elsh)
{
    elsh->expression_1->accept( this );
    elsh->expression_2->accept( this );
}

void FSVariablePicker::visitERSh(ERSh* ersh)
{
    ersh->expression_1->accept( this );
    ersh->expression_2->accept( this );
}

void FSVariablePicker::visitELT(ELT* elt)
{
    elt->expression_1->accept( this );
    elt->expression_2->accept( this );
}

void FSVariablePicker::visitEGT(EGT* egt)
{
    egt->expression_1->accept( this );
    egt->expression_2->accept( this );
}

void FSVariablePicker::visitELE(ELE* ele)
{
    ele->expression_1->accept( this );
    ele->expression_2->accept( this );
}

void FSVariablePicker::visitEGE(EGE* ege)
{
    ege->expression_1->accept( this );
    ege->expression_2->accept( this );
}

void FSVariablePicker::visitEE(EE* ee)
{
    ee->expression_1->accept( this );
    ee->expression_2->accept( this );
}

void FSVariablePicker::visitENE(ENE* ene)
{
    ene->expression_1->accept( this );
    ene->expression_2->accept( this );
}

void FSVariablePicker::visitEBand(EBand* eband)
{
    eband->expression_1->accept( this );
    eband->expression_2->accept( this );
}

void FSVariablePicker::visitEBor(EBor* ebor)
{
    ebor->expression_1->accept( this );
    ebor->expression_2->accept( this );
}

void FSVariablePicker::visitEBxor(EBxor* ebxor)
{
    ebxor->expression_1->accept( this );
    ebxor->expression_2->accept( this );
}

void FSVariablePicker::visitELand(ELand* eland)
{
    eland->expression_1->accept( this );
    eland->expression_2->accept( this );
}

void FSVariablePicker::visitELor(ELor* elor)
{
    elor->expression_1->accept( this );
    elor->expression_2->accept( this );
}

void FSVariablePicker::visitELxor(ELxor* elxor)
{
    elxor->expression_1->accept( this );
    elxor->expression_2->accept( this );
}

void FSVariablePicker::visitECon(ECon* econ)
{
    econ->expression_1->accept( this );
    econ->expression_2->accept( this );
    econ->expression_3->accept( this );
}

void FSVariablePicker::visitEAss(EAss* eass)
{
    AddVariable( eass->ident_ );
}

void FSVariablePicker::visitEAddAss(EAddAss* eaddass)
{
    AddVariable( eaddass->ident_ );
}

void FSVariablePicker::visitESubAss(ESubAss* esubass)
{
    AddVariable( esubass->ident_ );
}

void FSVariablePicker::visitEMulAss(EMulAss* emulass)
{
    AddVariable( emulass->ident_ );
}

void FSVariablePicker::visitEDivAss(EDivAss* edivass)
{
    AddVariable( edivass->ident_ );
}

void FSVariablePicker::visitEModAss(EModAss* emodass)
{
    AddVariable( emodass->ident_ );
}

void FSVariablePicker::visitEAndAss(EAndAss* eandass)
{
    AddVariable( eandass->ident_ );
}

void FSVariablePicker::visitEOrAss(EOrAss* eorass)
{
    AddVariable( eorass->ident_ );
}

void FSVariablePicker::visitEXorAss(EXorAss* exorass)
{
    AddVariable( exorass->ident_ );
}

void FSVariablePicker::visitELShAss(ELShAss* elshass)
{
    AddVariable( elshass->ident_ );
}

void FSVariablePicker::visitERShAss(ERShAss* ershass)
{
    AddVariable( ershass->ident_ );
}

void FSVariablePicker::visitListExpression(ListExpression* listexpression)
{
    while( listexpression )
    {
        listexpression->expression_->accept( this );
        listexpression = listexpression->listexpression_;
    }
}
