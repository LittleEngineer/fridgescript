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

#ifndef __FSAssembler_h
#define __FSAssembler_h

#include "FSAssemblerVisitor.h"
#include "SimpleStructures.h"

class FSALabel
{
public:
    Simple::ANSIString name;
    unsigned int location;
    Simple::Stack<unsigned int> refs;
    
    FSALabel() : name(), location(), refs() {}
    ~FSALabel() {}
    FSALabel(const char* n, unsigned int l) : name(n), location(l), refs() {}    
    FSALabel(const FSALabel& lbl) : name(lbl.name), location(lbl.location), refs()
    {
        for(unsigned int i = 0; i < lbl.refs.GetCount(); ++i)
        {
            refs.Push(lbl.refs[i]);
        }
    }

    FSALabel& operator =(const FSALabel& lbl)
    {
        name = Simple::ANSIString(lbl.name);
        location = lbl.location;
        for(unsigned int i = 0; i < lbl.refs.GetCount(); ++i)
        {
            refs.Push(lbl.refs[i]);
        }
        return *this;
    }
};

class FSAssembler : public FSAssemblerVisitor
{
private:    
    Simple::Stack<FSALabel*> labels;

public:
    FSAssembler() : FSAssemblerVisitor() {}
    ~FSAssembler()
    {
        for(unsigned int i = 0; i < labels.GetCount(); ++i)
            delete labels[i];
    }

    void ResolveLabels();
    void AddLabel(const char* const& name, unsigned int position);
    void AddLabelReference(const char* const& name, unsigned int position);

    void visitMain(Main* main);
    void visitListOperation(ListOperation* listoperation);
    void visitOAddC(OAddC* oAddC);
    void visitOSubC(OSubC* oSubC);
    void visitOLbl(OLbl* oLbl);
    void visitOJmp(OJmp* oJmp);
    void visitOJb(OJb* oJb);
    void visitOJbe(OJbe* oJbe);
    void visitOJe(OJe* oJe);
    void visitOJne(OJne* oJne);
    void visitOJz(OJz* oJz);
    void visitOJnz(OJnz* oJnz);
    void visitOCall(OCall* oCall);
    void visitORet(ORet* oRet);
    void visitOPush(OPush* opush);
    void visitOPop(OPop* opop);
    void visitOFadd(OFadd* ofadd);
    void visitOFaddp(OFaddp* ofaddp);
    void visitOFsub(OFsub* ofsub);
    void visitOFsubp(OFsubp* ofsubp);
    void visitOFsubrp(OFsubrp* ofsubrp);
    void visitOFmulp(OFmulp* ofmulp);
    void visitOFdivp(OFdivp* ofdivp);
    void visitOFdivrp(OFdivrp* ofdivrp);
    void visitOFchs(OFchs* ofchs);
    void visitOFsin(OFsin* ofsin);
    void visitOFcos(OFcos* ofcos);
    void visitOFprem(OFprem* ofprem);
    void visitOFptan(OFptan* ofptan);
    void visitOFpatan(OFpatan* ofpatan);
    void visitOFsqrt(OFsqrt* ofsqrt);
    void visitOFrndint(OFrndint* ofrndint);
    void visitOFscale(OFscale* ofscale);
    void visitOFtxmo(OFtxmo* oftxmo);
    void visitOFyltx(OFyltx* ofyltx);
    void visitOFyltxpo(OFyltxpo* ofyltxpo);
    void visitOFcomi(OFcomi* ofcomi);
    void visitOFcmovb(OFcmovb* ofcmovb);
    void visitOFcmovbe(OFcmovbe* ofcmovbe);
    void visitOFcmove(OFcmove* ofcmove);
    void visitOFcmovnb(OFcmovnb* ofcmovnb);
    void visitOFcmovnbe(OFcmovnbe* ofcmovnbe);
    void visitOFcmovne(OFcmovne* ofcmovne);
    void visitOFcmovnu(OFcmovnu* ofcmovnu);
    void visitOFcmovu(OFcmovu* ofcmovu);
    void visitOFld(OFld* ofld);
    void visitOFild(OFild* ofild);
    void visitOFldt(OFldt* ofldt);
    void visitOFldn(OFldn* ofldn);
    void visitOFldz(OFldz* ofldz);
    void visitOFldo(OFldo* ofldo);
    void visitOFldpi(OFldpi* ofldpi);
    void visitOFldlte(OFldlte* ofldlte);
    void visitOFldlnt(OFldlnt* ofldlnt);
    void visitOFldlgt(OFldlgt* ofldlgt);
    void visitOFst(OFst* ofst);
    void visitOFist(OFist* ofist);
    void visitOFstp(OFstp* ofstp);
    void visitOFistp(OFistp* ofistp);
    void visitOFstpt(OFstpt* ofstpt);
    void visitOFfree(OFfree* offree);
    void visitOFfreea(OFfreea* offreea);
    void visitOFfreeb(OFfreeb* offreeb);
    void visitOFfreec(OFfreec* offreec);
    void visitOFfreed(OFfreed* offreed);
    void visitOFfreee(OFfreee* offreee);
    void visitOFfreef(OFfreef* offreef);
    void visitOFfreeg(OFfreeg* offreeg);
    void visitOFxchg(OFxchg* ofxchg);
    void visitOFincstp(OFincstp* ofincstp);
    void visitOFdecstp(OFdecstp* ofdecstp);
};

#endif