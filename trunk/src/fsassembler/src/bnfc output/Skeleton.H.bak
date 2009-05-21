#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"

class Skeleton : public Visitor
{
 public:

  void visitCode(Code* code); /* abstract class */
  void visitMain(Main* main);
  void visitListOperation(ListOperation* listoperation);  void visitOperation(Operation* operation); /* abstract class */
  void visitOAddC(OAddC* oaddc);
  void visitOSubC(OSubC* osubc);
  void visitOLbl(OLbl* olbl);
  void visitOJmp(OJmp* ojmp);
  void visitOJb(OJb* ojb);
  void visitOJbe(OJbe* ojbe);
  void visitOJe(OJe* oje);
  void visitOJne(OJne* ojne);
  void visitOJz(OJz* ojz);
  void visitOJnz(OJnz* ojnz);
  void visitOCall(OCall* ocall);
  void visitORet(ORet* oret);
  void visitOPush(OPush* opush);
  void visitOPop(OPop* opop);
  void visitOFabs(OFabs* ofabs);
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
  void visitRegister(Register* register); /* abstract class */
  void visitREax(REax* reax);
  void visitREcx(REcx* recx);
  void visitREdx(REdx* redx);
  void visitREbx(REbx* rebx);
  void visitREsp(REsp* resp);
  void visitREbp(REbp* rebp);
  void visitREsi(REsi* resi);
  void visitREdi(REdi* redi);
  void visitOperand(Operand* operand); /* abstract class */
  void visitOReg(OReg* oreg);
  void visitOHex(OHex* ohex);
  void visitOLab(OLab* olab);
  void visitOLitAdd(OLitAdd* olitadd);
  void visitORegAdd(ORegAdd* oregadd);
  void visitORelAddP(ORelAddP* oreladdp);
  void visitORelAddS(ORelAddS* oreladds);

  void visitHexconstant(HexConstant p);
  void visitIdent(String s);
  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
};

#endif

