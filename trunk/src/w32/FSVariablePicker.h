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

#include "FSVisitor.h"

#include "Absyn.h"
#include "SimpleStructures.h"

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
    void visitEPreInc(EPreInc* epreinc);
    void visitEPreDec(EPreDec* epredec);
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