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

#ifndef __FSAssemblerVisitor_h
#define __FSAssemblerVisitor_h

#include "Absyn.h"
#include "SimpleStructures.h"

///////////////////////////////////////////////
// FSAssemblerVisitor : Base class visitor
///////////////////////////////////////////////

class FSAssemblerVisitor : public Visitor
{
protected:
    Simple::Stack<unsigned char> out;
public:
    FSAssemblerVisitor() : out() {}
    virtual ~FSAssemblerVisitor() {}

    Simple::Stack<unsigned char>& GetBytes() { return out; }

    virtual void visitMain(Main *p) {}
    virtual void visitListOperation(ListOperation *p) {}
    virtual void visitOAddC(OAddC *p) {}
    virtual void visitOSubC(OSubC *p) {}
    virtual void visitOLbl(OLbl *p) {}
    virtual void visitOJmp(OJmp *p) {}
    virtual void visitOJb(OJb *p) {}
    virtual void visitOJbe(OJbe *p) {}
    virtual void visitOJe(OJe *p) {}
    virtual void visitOJne(OJne *p) {}
    virtual void visitOJz(OJz *p) {}
    virtual void visitOJnz(OJnz *p) {}
    virtual void visitOCall(OCall *p) {}
    virtual void visitORet(ORet *p) {}
    virtual void visitOPush(OPush *p) {}
    virtual void visitOPop(OPop *p) {}
    virtual void visitOFadd(OFadd *p) {}
    virtual void visitOFaddp(OFaddp *p) {}
    virtual void visitOFsub(OFsub *p) {}
    virtual void visitOFsubp(OFsubp *p) {}
    virtual void visitOFsubrp(OFsubrp *p) {}
    virtual void visitOFmulp(OFmulp *p) {}
    virtual void visitOFdivp(OFdivp *p) {}
    virtual void visitOFdivrp(OFdivrp *p) {}
    virtual void visitOFchs(OFchs *p) {}
    virtual void visitOFsin(OFsin *p) {}
    virtual void visitOFcos(OFcos *p) {}
    virtual void visitOFprem(OFprem *p) {}
    virtual void visitOFptan(OFptan *p) {}
    virtual void visitOFpatan(OFpatan *p) {}
    virtual void visitOFsqrt(OFsqrt *p) {}
    virtual void visitOFrndint(OFrndint *p) {}
    virtual void visitOFscale(OFscale *p) {}
    virtual void visitOFtxmo(OFtxmo *p) {}
    virtual void visitOFyltx(OFyltx *p) {}
    virtual void visitOFyltxpo(OFyltxpo *p) {}
    virtual void visitOFcomi(OFcomi *p) {}
    virtual void visitOFcmovb(OFcmovb *p) {}
    virtual void visitOFcmovbe(OFcmovbe *p) {}
    virtual void visitOFcmove(OFcmove *p) {}
    virtual void visitOFcmovnb(OFcmovnb *p) {}
    virtual void visitOFcmovnbe(OFcmovnbe *p) {}
    virtual void visitOFcmovne(OFcmovne *p) {}
    virtual void visitOFcmovnu(OFcmovnu *p) {}
    virtual void visitOFcmovu(OFcmovu *p) {}
    virtual void visitOFld(OFld *p) {}
    virtual void visitOFild(OFild *p) {}
    virtual void visitOFldt(OFldt *p) {}
    virtual void visitOFldn(OFldn *p) {}
    virtual void visitOFldz(OFldz *p) {}
    virtual void visitOFldo(OFldo *p) {}
    virtual void visitOFldpi(OFldpi *p) {}
    virtual void visitOFldlte(OFldlte *p) {}
    virtual void visitOFldlnt(OFldlnt *p) {}
    virtual void visitOFldlgt(OFldlgt *p) {}
    virtual void visitOFst(OFst *p) {}
    virtual void visitOFist(OFist *p) {}
    virtual void visitOFstp(OFstp *p) {}
    virtual void visitOFistp(OFistp *p) {}
    virtual void visitOFstpt(OFstpt *p) {}
    virtual void visitOFfree(OFfree *p) {}
    virtual void visitOFfreea(OFfreea *p) {}
    virtual void visitOFfreeb(OFfreeb *p) {}
    virtual void visitOFfreec(OFfreec *p) {}
    virtual void visitOFfreed(OFfreed *p) {}
    virtual void visitOFfreee(OFfreee *p) {}
    virtual void visitOFfreef(OFfreef *p) {}
    virtual void visitOFfreeg(OFfreeg *p) {}
    virtual void visitOFxchg(OFxchg *p) {}
    virtual void visitOFincstp(OFincstp *p) {}
    virtual void visitOFdecstp(OFdecstp *p) {}
    virtual void visitREax(REax *p) {}
    virtual void visitREcx(REcx *p) {}
    virtual void visitREdx(REdx *p) {}
    virtual void visitREbx(REbx *p) {}
    virtual void visitREsp(REsp *p) {}
    virtual void visitREbp(REbp *p) {}
    virtual void visitREsi(REsi *p) {}
    virtual void visitREdi(REdi *p) {}
    virtual void visitOReg(OReg *p) {}
    virtual void visitOHex(OHex *p) {}
    virtual void visitOLab(OLab *p) {}
    virtual void visitOLitAdd(OLitAdd *p) {}
    virtual void visitORegAdd(ORegAdd *p) {}
    virtual void visitORelAddP(ORelAddP *p) {}
    virtual void visitORelAddS(ORelAddS *p) {}
    virtual void visitCode(Code *p) {}
    virtual void visitOperation(Operation *p) {}
    virtual void visitRegister(Register *p) {}
    virtual void visitOperand(Operand *p) {}

    virtual void visitInteger(Integer i) {}
    virtual void visitDouble(Double d) {}
    virtual void visitChar(Char c) {}
    virtual void visitString(String s) {}
};

#endif