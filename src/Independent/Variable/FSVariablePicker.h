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

#ifndef __FSVariablePicker_h
#define __FSVariablePicker_h

#include <Core/FSVisitor.h>

#include "Absyn.h"
#include <Core/SimpleStructures.h>

class FSContext;
class FSVariable;

class FSVariablePicker : public FSVisitor
{
private:
    FSContext*  context;
    Simple::Stack<FSVariable*> vars;

    void AddVariable(const char* const& name);
public:
    FSVariablePicker(FSContext* c) : context(c) {}

    Simple::Stack<FSVariable*>* GetVariableStackPtr() { return &vars; }

    void visitMain(Main* main);
    void visitBStmt(BStmt* bstmt);
    void visitListBlock(ListBlock* listblock);
    void visitListStatement(ListStatement* liststatement);
    void visitSExp(SExp* sexp);
    void visitSScope(SScope* sscope);
    void visitSRet(SRet* sret);
    void visitSIf(SIf* sif);
    void visitSIfElse(SIfElse* sifelse);
    void visitSWhile(SWhile* swhile);
    void visitSUntil(SUntil* suntil);
    void visitSFor(SFor* sfor);
    void visitEVar(EVar *p);
    void visitECall(ECall* ecall);
    void visitEPostInc(EPostInc* epostinc);
    void visitEPostDec(EPostDec* epostdec);
    void visitEAbs(EAbs* eabs);
    void visitEPow(EPow* epow);
    void visitESqrt(ESqrt* esqrt);
    void visitEExp(EExp* eexp);
    void visitELog(ELog* elog);
    void visitELogD(ELogD* elogd);
    void visitESin(ESin* esin);
    void visitECos(ECos* ecos);
    void visitETan(ETan* etan);
    void visitEAtan(EAtan* eatan);
    void visitEAtanT(EAtanT* eatant);
    void visitEAsin(EAsin* easin);
    void visitEAcos(EAcos* eacos);
    void visitELnot(ELnot* elnot);
    void visitEPreInc(EPreInc* epreinc);
    void visitEPreDec(EPreDec* epredec);
    void visitENeg(ENeg* eneg);
    void visitEBnot(EBnot* ebnot);
    void visitEPos(EPos* epos);
    void visitEMul(EMul* emul);
    void visitEDiv(EDiv* ediv);
    void visitEMod(EMod* emod);
    void visitEAdd(EAdd* eadd);
    void visitESub(ESub* esub);
    void visitELSh(ELSh* elsh);
    void visitERSh(ERSh* ersh);
    void visitELT(ELT* elt);
    void visitEGT(EGT* egt);
    void visitELE(ELE* ele);
    void visitEGE(EGE* ege);
    void visitEE(EE* ee);
    void visitENE(ENE* ene);
    void visitEBand(EBand* eband);
    void visitEBor(EBor* ebor);
    void visitEBxor(EBxor* ebxor);
    void visitELand(ELand* eland);
    void visitELor(ELor* elor);
    void visitELxor(ELxor* elxor);
    void visitECon(ECon* econ);
    void visitEAss(EAss* eass);
    void visitEAddAss(EAddAss* eaddass);
    void visitESubAss(ESubAss* esubass);
    void visitEMulAss(EMulAss* emulass);
    void visitEDivAss(EDivAss* edivass);
    void visitEModAss(EModAss* emodass);
    void visitEAndAss(EAndAss* eandass);
    void visitEOrAss(EOrAss* eorass);
    void visitEXorAss(EXorAss* exorass);
    void visitELShAss(ELShAss* elshass);
    void visitERShAss(ERShAss* ershass);
    void visitListExpression(ListExpression* listexpression);
};

#endif