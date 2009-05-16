/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"

void Skeleton::visitCode(Code* code) {} //abstract class

void Skeleton::visitMain(Main* main)
{
  /* Code For Main Goes Here */

  if (main->listoperation_) {main->listoperation_->accept(this);}
}

void Skeleton::visitListOperation(ListOperation* listoperation)
{
  while(listoperation!= 0)
  {
    /* Code For ListOperation Goes Here */
    listoperation->operation_->accept(this);
    listoperation = listoperation->listoperation_;
  }
}

void Skeleton::visitOperation(Operation* operation) {} //abstract class

void Skeleton::visitOAddC(OAddC* oaddc)
{
  /* Code For OAddC Goes Here */

  oaddc->register_->accept(this);
  visitInteger(oaddc->integer_);
}

void Skeleton::visitOSubC(OSubC* osubc)
{
  /* Code For OSubC Goes Here */

  osubc->register_->accept(this);
  visitInteger(osubc->integer_);
}

void Skeleton::visitOLbl(OLbl* olbl)
{
  /* Code For OLbl Goes Here */

  visitIdent(olbl->ident_);
}

void Skeleton::visitOJmp(OJmp* ojmp)
{
  /* Code For OJmp Goes Here */

  ojmp->operand_->accept(this);
}

void Skeleton::visitOJb(OJb* ojb)
{
  /* Code For OJb Goes Here */

  ojb->operand_->accept(this);
}

void Skeleton::visitOJbe(OJbe* ojbe)
{
  /* Code For OJbe Goes Here */

  ojbe->operand_->accept(this);
}

void Skeleton::visitOJe(OJe* oje)
{
  /* Code For OJe Goes Here */

  oje->operand_->accept(this);
}

void Skeleton::visitOJne(OJne* ojne)
{
  /* Code For OJne Goes Here */

  ojne->operand_->accept(this);
}

void Skeleton::visitOJz(OJz* ojz)
{
  /* Code For OJz Goes Here */

  ojz->operand_->accept(this);
}

void Skeleton::visitOJnz(OJnz* ojnz)
{
  /* Code For OJnz Goes Here */

  ojnz->operand_->accept(this);
}

void Skeleton::visitOCall(OCall* ocall)
{
  /* Code For OCall Goes Here */

  ocall->operand_->accept(this);
}

void Skeleton::visitORet(ORet* oret)
{
  /* Code For ORet Goes Here */

}

void Skeleton::visitOPush(OPush* opush)
{
  /* Code For OPush Goes Here */

  opush->operand_->accept(this);
}

void Skeleton::visitOPop(OPop* opop)
{
  /* Code For OPop Goes Here */

  opop->operand_->accept(this);
}

void Skeleton::visitOFadd(OFadd* ofadd)
{
  /* Code For OFadd Goes Here */

}

void Skeleton::visitOFaddp(OFaddp* ofaddp)
{
  /* Code For OFaddp Goes Here */

}

void Skeleton::visitOFsub(OFsub* ofsub)
{
  /* Code For OFsub Goes Here */

}

void Skeleton::visitOFsubp(OFsubp* ofsubp)
{
  /* Code For OFsubp Goes Here */

}

void Skeleton::visitOFsubrp(OFsubrp* ofsubrp)
{
  /* Code For OFsubrp Goes Here */

}

void Skeleton::visitOFmulp(OFmulp* ofmulp)
{
  /* Code For OFmulp Goes Here */

}

void Skeleton::visitOFdivp(OFdivp* ofdivp)
{
  /* Code For OFdivp Goes Here */

}

void Skeleton::visitOFdivrp(OFdivrp* ofdivrp)
{
  /* Code For OFdivrp Goes Here */

}

void Skeleton::visitOFchs(OFchs* ofchs)
{
  /* Code For OFchs Goes Here */

}

void Skeleton::visitOFsin(OFsin* ofsin)
{
  /* Code For OFsin Goes Here */

}

void Skeleton::visitOFcos(OFcos* ofcos)
{
  /* Code For OFcos Goes Here */

}

void Skeleton::visitOFprem(OFprem* ofprem)
{
  /* Code For OFprem Goes Here */

}

void Skeleton::visitOFptan(OFptan* ofptan)
{
  /* Code For OFptan Goes Here */

}

void Skeleton::visitOFpatan(OFpatan* ofpatan)
{
  /* Code For OFpatan Goes Here */

}

void Skeleton::visitOFsqrt(OFsqrt* ofsqrt)
{
  /* Code For OFsqrt Goes Here */

}

void Skeleton::visitOFrndint(OFrndint* ofrndint)
{
  /* Code For OFrndint Goes Here */

}

void Skeleton::visitOFscale(OFscale* ofscale)
{
  /* Code For OFscale Goes Here */

}

void Skeleton::visitOFtxmo(OFtxmo* oftxmo)
{
  /* Code For OFtxmo Goes Here */

}

void Skeleton::visitOFyltx(OFyltx* ofyltx)
{
  /* Code For OFyltx Goes Here */

}

void Skeleton::visitOFyltxpo(OFyltxpo* ofyltxpo)
{
  /* Code For OFyltxpo Goes Here */

}

void Skeleton::visitOFcomi(OFcomi* ofcomi)
{
  /* Code For OFcomi Goes Here */

}

void Skeleton::visitOFcmovb(OFcmovb* ofcmovb)
{
  /* Code For OFcmovb Goes Here */

}

void Skeleton::visitOFcmovbe(OFcmovbe* ofcmovbe)
{
  /* Code For OFcmovbe Goes Here */

}

void Skeleton::visitOFcmove(OFcmove* ofcmove)
{
  /* Code For OFcmove Goes Here */

}

void Skeleton::visitOFcmovnb(OFcmovnb* ofcmovnb)
{
  /* Code For OFcmovnb Goes Here */

}

void Skeleton::visitOFcmovnbe(OFcmovnbe* ofcmovnbe)
{
  /* Code For OFcmovnbe Goes Here */

}

void Skeleton::visitOFcmovne(OFcmovne* ofcmovne)
{
  /* Code For OFcmovne Goes Here */

}

void Skeleton::visitOFcmovnu(OFcmovnu* ofcmovnu)
{
  /* Code For OFcmovnu Goes Here */

}

void Skeleton::visitOFcmovu(OFcmovu* ofcmovu)
{
  /* Code For OFcmovu Goes Here */

}

void Skeleton::visitOFld(OFld* ofld)
{
  /* Code For OFld Goes Here */

  ofld->operand_->accept(this);
}

void Skeleton::visitOFild(OFild* ofild)
{
  /* Code For OFild Goes Here */

  ofild->operand_->accept(this);
}

void Skeleton::visitOFldt(OFldt* ofldt)
{
  /* Code For OFldt Goes Here */

}

void Skeleton::visitOFldn(OFldn* ofldn)
{
  /* Code For OFldn Goes Here */

}

void Skeleton::visitOFldz(OFldz* ofldz)
{
  /* Code For OFldz Goes Here */

}

void Skeleton::visitOFldo(OFldo* ofldo)
{
  /* Code For OFldo Goes Here */

}

void Skeleton::visitOFldpi(OFldpi* ofldpi)
{
  /* Code For OFldpi Goes Here */

}

void Skeleton::visitOFldlte(OFldlte* ofldlte)
{
  /* Code For OFldlte Goes Here */

}

void Skeleton::visitOFldlnt(OFldlnt* ofldlnt)
{
  /* Code For OFldlnt Goes Here */

}

void Skeleton::visitOFldlgt(OFldlgt* ofldlgt)
{
  /* Code For OFldlgt Goes Here */

}

void Skeleton::visitOFst(OFst* ofst)
{
  /* Code For OFst Goes Here */

  ofst->operand_->accept(this);
}

void Skeleton::visitOFist(OFist* ofist)
{
  /* Code For OFist Goes Here */

  ofist->operand_->accept(this);
}

void Skeleton::visitOFstp(OFstp* ofstp)
{
  /* Code For OFstp Goes Here */

  ofstp->operand_->accept(this);
}

void Skeleton::visitOFistp(OFistp* ofistp)
{
  /* Code For OFistp Goes Here */

  ofistp->operand_->accept(this);
}

void Skeleton::visitOFstpt(OFstpt* ofstpt)
{
  /* Code For OFstpt Goes Here */

}

void Skeleton::visitOFfree(OFfree* offree)
{
  /* Code For OFfree Goes Here */

}

void Skeleton::visitOFfreea(OFfreea* offreea)
{
  /* Code For OFfreea Goes Here */

}

void Skeleton::visitOFfreeb(OFfreeb* offreeb)
{
  /* Code For OFfreeb Goes Here */

}

void Skeleton::visitOFfreec(OFfreec* offreec)
{
  /* Code For OFfreec Goes Here */

}

void Skeleton::visitOFfreed(OFfreed* offreed)
{
  /* Code For OFfreed Goes Here */

}

void Skeleton::visitOFfreee(OFfreee* offreee)
{
  /* Code For OFfreee Goes Here */

}

void Skeleton::visitOFfreef(OFfreef* offreef)
{
  /* Code For OFfreef Goes Here */

}

void Skeleton::visitOFfreeg(OFfreeg* offreeg)
{
  /* Code For OFfreeg Goes Here */

}

void Skeleton::visitOFxchg(OFxchg* ofxchg)
{
  /* Code For OFxchg Goes Here */

}

void Skeleton::visitOFincstp(OFincstp* ofincstp)
{
  /* Code For OFincstp Goes Here */

}

void Skeleton::visitOFdecstp(OFdecstp* ofdecstp)
{
  /* Code For OFdecstp Goes Here */

}

void Skeleton::visitRegister(Register* register) {} //abstract class

void Skeleton::visitREax(REax* reax)
{
  /* Code For REax Goes Here */

}

void Skeleton::visitREcx(REcx* recx)
{
  /* Code For REcx Goes Here */

}

void Skeleton::visitREdx(REdx* redx)
{
  /* Code For REdx Goes Here */

}

void Skeleton::visitREbx(REbx* rebx)
{
  /* Code For REbx Goes Here */

}

void Skeleton::visitREsp(REsp* resp)
{
  /* Code For REsp Goes Here */

}

void Skeleton::visitREbp(REbp* rebp)
{
  /* Code For REbp Goes Here */

}

void Skeleton::visitREsi(REsi* resi)
{
  /* Code For REsi Goes Here */

}

void Skeleton::visitREdi(REdi* redi)
{
  /* Code For REdi Goes Here */

}

void Skeleton::visitOperand(Operand* operand) {} //abstract class

void Skeleton::visitOReg(OReg* oreg)
{
  /* Code For OReg Goes Here */

  oreg->register_->accept(this);
}

void Skeleton::visitOHex(OHex* ohex)
{
  /* Code For OHex Goes Here */

  visitHexconstant(ohex->hexconstant_);
}

void Skeleton::visitOLab(OLab* olab)
{
  /* Code For OLab Goes Here */

  visitIdent(olab->ident_);
}

void Skeleton::visitOLitAdd(OLitAdd* olitadd)
{
  /* Code For OLitAdd Goes Here */

  visitHexconstant(olitadd->hexconstant_);
}

void Skeleton::visitORegAdd(ORegAdd* oregadd)
{
  /* Code For ORegAdd Goes Here */

  oregadd->register_->accept(this);
}

void Skeleton::visitORelAddP(ORelAddP* oreladdp)
{
  /* Code For ORelAddP Goes Here */

  oreladdp->register_->accept(this);
  visitInteger(oreladdp->integer_);
}

void Skeleton::visitORelAddS(ORelAddS* oreladds)
{
  /* Code For ORelAddS Goes Here */

  oreladds->register_->accept(this);
  visitInteger(oreladds->integer_);
}

void Skeleton::visitHexconstant(HexConstant p)
{
  /* Code for HexConstant Goes Here */
}
void Skeleton::visitIdent(Ident i)
{
  /* Code for Ident Goes Here */
}
void Skeleton::visitInteger(Integer i)
{
  /* Code for Integers Goes Here */
}
void Skeleton::visitDouble(Double d)
{
  /* Code for Doubles Goes Here */
}
void Skeleton::visitChar(Char c)
{
  /* Code for Chars Goes Here */
}
void Skeleton::visitString(String s)
{
  /* Code for Strings Goes Here */
}

