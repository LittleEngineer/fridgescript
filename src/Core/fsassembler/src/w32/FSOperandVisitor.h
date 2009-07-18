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

#ifndef __FSOperandVisitor_h
#define __FSOperandVisitor_h

#include "FSAssemblerVisitor.h"
#include "SimpleStructures.h"

///////////////////////////////////////////////
// FSOperandVisitor : Assembles operands
///////////////////////////////////////////////

class FSOperandVisitor : public FSAssemblerVisitor
{
private:
    enum Reg
    {
        EAX = 0,
        ECX = 1,
        EDX = 2,
        EBX = 3,
        ESP = 4,
        EBP = 5,
        ESI = 6,
        EDI = 7
    } lastRegister;
    Simple::ANSIString lastLabel;

public:
    enum FSOVType
    {
        JMP,
        PUSH,
        POP,
        FILD,
        FIST,
        FISTP,
        FLD,
        FST,
        FSTP
    } otype;

    FSOperandVisitor(FSOVType t) : otype(t), FSAssemblerVisitor() {}
    ~FSOperandVisitor() {}

    Simple::ANSIString GetLastLabel() const { return lastLabel; }

    void visitREax(REax* reax);
    void visitREcx(REcx* recx);
    void visitREdx(REdx* redx);
    void visitREbx(REbx* rebx);
    void visitREsp(REsp* resp);
    void visitREbp(REbp* rebp);
    void visitREsi(REsi* resi);
    void visitREdi(REdi* redi);
    void visitOReg(OReg* oreg);
    void visitOHex(OHex* ohex);
    void visitOLab(OLab* olab);
    void visitOLitAdd(OLitAdd* olitadd);
    void visitORegAdd(ORegAdd* oregadd);
    void visitORelAddP(ORelAddP* oreladdp);
    void visitORelAddS(ORelAddS* oreladds);
};

#endif