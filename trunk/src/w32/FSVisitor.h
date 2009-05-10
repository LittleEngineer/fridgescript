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

#ifndef __FSVisitor_h
#define __FSVisitor_h

#include "Absyn.h"

class FSVisitor : public Visitor
{
protected:
public:
    FSVisitor() {}
    virtual ~FSVisitor() {}
    virtual void visitProgram(Program* program) {} /* abstract class */
    virtual void visitMain(Main* main) {}
    virtual void visitBlock(Block* block) {} /* abstract class */
    virtual void visitBFunc(BFunc* bfunc) {}
    virtual void visitBStmt(BStmt* bstmt) {}
    virtual void visitFunction(Function* function) {} /* abstract class */
    virtual void visitDTFunc(DTFunc* dtfunc) {}
    virtual void visitParameter(Parameter* parameter) {} /* abstract class */
    virtual void visitDTParam(DTParam* dtparam) {}
    virtual void visitListBlock(ListBlock* listblock) {}
    virtual void visitListFunction(ListFunction* listfunction) {}
    virtual void visitListStatement(ListStatement* liststatement) {}
    virtual void visitListParameter(ListParameter* listparameter) {}
    virtual void visitStatement(Statement* statement) {} /* abstract class */
    virtual void visitSExp(SExp* sexp) {}
    virtual void visitSScope(SScope* sscope) {}
    virtual void visitSRet(SRet* sret) {}
    virtual void visitSIf(SIf* sif) {}
    virtual void visitSIfElse(SIfElse* sifelse) {}
    virtual void visitSWhile(SWhile* swhile) {}
    virtual void visitSUntil(SUntil* suntil) {}
    virtual void visitSFor(SFor* sfor) {}
    virtual void visitSBreak(SBreak* sbreak) {}
    virtual void visitSContinue(SContinue* scontinue) {}
    virtual void visitExpression(Expression* expression) {} /* abstract class */
    virtual void visitECDbl(ECDbl* ecdbl) {}
    virtual void visitECInt(ECInt* ecint) {}
    virtual void visitEVar(EVar *p) {}
    virtual void visitEPi(EPi *p) {}
    virtual void visitECall(ECall* ecall) {}
    virtual void visitEPostInc(EPostInc* epostinc) {}
    virtual void visitEPostDec(EPostDec* epostdec) {}
    virtual void visitEPow(EPow* epow) {}
    virtual void visitESqrt(ESqrt* esqrt) {}
    virtual void visitEExp(EExp* eexp) {}
    virtual void visitELog(ELog* elog) {}
    virtual void visitELogD(ELogD* elogd) {}
    virtual void visitESin(ESin* esin) {}
    virtual void visitECos(ECos* ecos) {}
    virtual void visitETan(ETan* etan) {}
    virtual void visitEAtan(EAtan* eatan) {}
    virtual void visitEAtanT(EAtanT* eatant) {}
    virtual void visitEAsin(EAsin* easin) {}
    virtual void visitEAcos(EAcos* eacos) {}
    virtual void visitELnot(ELnot* elnot) {}
    virtual void visitEPreInc(EPreInc* epreinc) {}
    virtual void visitEPreDec(EPreDec* epredec) {}
    virtual void visitENeg(ENeg* eneg) {}
    virtual void visitEBnot(EBnot* ebnot) {}
    virtual void visitEPos(EPos* epos) {}
    virtual void visitEMul(EMul* emul) {}
    virtual void visitEDiv(EDiv* ediv) {}
    virtual void visitEMod(EMod* emod) {}
    virtual void visitEAdd(EAdd* eadd) {}
    virtual void visitESub(ESub* esub) {}
    virtual void visitELSh(ELSh* elsh) {}
    virtual void visitERSh(ERSh* ersh) {}
    virtual void visitELT(ELT* elt) {}
    virtual void visitEGT(EGT* egt) {}
    virtual void visitELE(ELE* ele) {}
    virtual void visitEGE(EGE* ege) {}
    virtual void visitEE(EE* ee) {}
    virtual void visitENE(ENE* ene) {}
    virtual void visitEBand(EBand* eband) {}
    virtual void visitEBor(EBor* ebor) {}
    virtual void visitEBxor(EBxor* ebxor) {}
    virtual void visitELand(ELand* eland) {}
    virtual void visitELor(ELor* elor) {}
    virtual void visitELxor(ELxor* elxor) {}
    virtual void visitECon(ECon* econ) {}
    virtual void visitEAss(EAss* eass) {}
    virtual void visitEAddAss(EAddAss* eaddass) {}
    virtual void visitESubAss(ESubAss* esubass) {}
    virtual void visitEMulAss(EMulAss* emulass) {}
    virtual void visitEDivAss(EDivAss* edivass) {}
    virtual void visitEModAss(EModAss* emodass) {}
    virtual void visitEAndAss(EAndAss* eandass) {}
    virtual void visitEOrAss(EOrAss* eorass) {}
    virtual void visitEXorAss(EXorAss* exorass) {}
    virtual void visitELShAss(ELShAss* elshass) {}
    virtual void visitERShAss(ERShAss* ershass) {}
    virtual void visitListExpression(ListExpression* listexpression) {}

    virtual void visitIdent(String s) {}
    virtual void visitInteger(Integer i) {}
    virtual void visitDouble(Double d) {}
    virtual void visitChar(Char c) {}
    virtual void visitString(String s) {}
};

#endif