/*** BNFC-Generated Pretty Printer and Abstract Syntax Viewer ***/

#include "Printer.H"

//You may wish to change render
void PrintAbsyn::render(Char c)
{
  if (c == '{')
  {
     bufAppend('\n');
     indent();
     bufAppend(c);
     _n_ = _n_ + 2;
     bufAppend('\n');
     indent();
  }
  else if (c == '(' || c == '[')
     bufAppend(c);
  else if (c == ')' || c == ']')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == '}')
  {
     _n_ = _n_ - 2;
     backup();
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == ',')
  {
     backup();
     bufAppend(c);
     bufAppend(' ');
  }
  else if (c == ';')
  {
     backup();
     bufAppend(c);
     bufAppend('\n');
     indent();
  }
  else if (c == 0) return;
  else
  {
     bufAppend(c);
     bufAppend(' ');
  }
}
void PrintAbsyn::render(String s)
{
  if(strlen(s) > 0)
  {
    bufAppend(s);
    bufAppend(' ');
  }
}
void PrintAbsyn::indent()
{
  int n = _n_;
  while (n > 0)
  {
    bufAppend(' ');
    n--;
  }
}
void PrintAbsyn::backup()
{
  if (buf_[cur_ - 1] == ' ')
  {
    buf_[cur_ - 1] = 0;
    cur_--;
  }
}
PrintAbsyn::PrintAbsyn(void)
{
  _i_ = 0; _n_ = 0;
  buf_ = 0;
  bufReset();
}

PrintAbsyn::~PrintAbsyn(void)
{
}

char* PrintAbsyn::print(Visitable *v)
{
  _i_ = 0; _n_ = 0;
  bufReset();
  v->accept(this);
  return buf_;
}
void PrintAbsyn::visitCode(Code*p) {} //abstract class

void PrintAbsyn::visitMain(Main* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listoperation_) {_i_ = 0; p->listoperation_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListOperation(ListOperation *listoperation)
{
  while(listoperation!= 0)
  {
    if (listoperation->listoperation_ == 0)
    {
      listoperation->operation_->accept(this);
      render("");
      listoperation = 0;
    }
    else
    {
      listoperation->operation_->accept(this);
      render("");
      listoperation = listoperation->listoperation_;
    }
  }
}

void PrintAbsyn::visitOperation(Operation*p) {} //abstract class

void PrintAbsyn::visitOAddC(OAddC* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("add");
  _i_ = 0; p->register_->accept(this);
  render(',');
  visitInteger(p->integer_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOSubC(OSubC* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("sub");
  _i_ = 0; p->register_->accept(this);
  render(',');
  visitInteger(p->integer_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOLbl(OLbl* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render(':');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOJmp(OJmp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("jmp");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOJb(OJb* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("jb");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOJbe(OJbe* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("jbe");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOJe(OJe* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("je");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOJne(OJne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("jne");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOJz(OJz* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("jz");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOJnz(OJnz* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("jnz");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOCall(OCall* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("call");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitORet(ORet* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ret");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOPush(OPush* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("push");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOPop(OPop* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("pop");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFadd(OFadd* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fadd");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFaddp(OFaddp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("faddp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFsub(OFsub* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fsub");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFsubp(OFsubp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fsubp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFsubrp(OFsubrp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fsubrp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFmulp(OFmulp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fmulp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFdivp(OFdivp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fdivp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFdivrp(OFdivrp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fdivrp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFchs(OFchs* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fchs");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFsin(OFsin* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fsin");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcos(OFcos* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcos");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFprem(OFprem* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fprem");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFptan(OFptan* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fptan");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFpatan(OFpatan* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fpatan");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFsqrt(OFsqrt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fsqrt");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFrndint(OFrndint* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("frndint");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFscale(OFscale* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fscale");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFtxmo(OFtxmo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("f2xm1");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFyltx(OFyltx* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fyl2x");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFyltxpo(OFyltxpo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fyl2xp1");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcomi(OFcomi* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcomi");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmovb(OFcmovb* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmovb");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmovbe(OFcmovbe* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmovbe");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmove(OFcmove* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmove");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmovnb(OFcmovnb* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmovnb");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmovnbe(OFcmovnbe* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmovnbe");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmovne(OFcmovne* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmovne");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmovnu(OFcmovnu* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmovnu");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFcmovu(OFcmovu* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fcmovu");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFld(OFld* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fld");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFild(OFild* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fild");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldt(OFldt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fld");
  render("st(0)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldn(OFldn* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fld");
  render("st(1)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldz(OFldz* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fldz");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldo(OFldo* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fld1");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldpi(OFldpi* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fldpi");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldlte(OFldlte* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fldl2e");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldlnt(OFldlnt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fldln2");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFldlgt(OFldlgt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fldlg2");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFst(OFst* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fst");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFist(OFist* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fist");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFstp(OFstp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fstp");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFistp(OFistp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fistp");
  _i_ = 0; p->operand_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFstpt(OFstpt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fstp");
  render("st(0)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfree(OFfree* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(0)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfreea(OFfreea* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(1)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfreeb(OFfreeb* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(2)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfreec(OFfreec* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(3)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfreed(OFfreed* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(4)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfreee(OFfreee* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(5)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfreef(OFfreef* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(6)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFfreeg(OFfreeg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ffree");
  render("st(7)");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFxchg(OFxchg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fxch");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFincstp(OFincstp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fincstp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOFdecstp(OFdecstp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("fdecstp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitRegister(Register*p) {} //abstract class

void PrintAbsyn::visitREax(REax* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("eax");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitREcx(REcx* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ecx");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitREdx(REdx* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("edx");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitREbx(REbx* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ebx");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitREsp(REsp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("esp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitREbp(REbp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("ebp");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitREsi(REsi* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("esi");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitREdi(REdi* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("edi");

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOperand(Operand*p) {} //abstract class

void PrintAbsyn::visitOReg(OReg* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->register_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOHex(OHex* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->hexconstant_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOLab(OLab* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitOLitAdd(OLitAdd* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  visitIdent(p->hexconstant_);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitORegAdd(ORegAdd* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  _i_ = 0; p->register_->accept(this);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitORelAddP(ORelAddP* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  _i_ = 0; p->register_->accept(this);
  render('+');
  visitInteger(p->integer_);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitORelAddS(ORelAddS* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('[');
  _i_ = 0; p->register_->accept(this);
  render('-');
  visitInteger(p->integer_);
  render(']');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void PrintAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void PrintAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void PrintAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void PrintAbsyn::visitIdent(String s)
{
  render(s);
}

ShowAbsyn::ShowAbsyn(void)
{
  buf_ = 0;
  bufReset();
}

ShowAbsyn::~ShowAbsyn(void)
{
}

char* ShowAbsyn::show(Visitable *v)
{
  bufReset();
  v->accept(this);
  return buf_;
}
void ShowAbsyn::visitCode(Code* p) {} //abstract class

void ShowAbsyn::visitMain(Main* p)
{
  bufAppend('(');
  bufAppend("Main");
  bufAppend(' ');
  bufAppend('[');
  if (p->listoperation_)  p->listoperation_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListOperation(ListOperation *listoperation)
{
  while(listoperation!= 0)
  {
    if (listoperation->listoperation_)
    {
      listoperation->operation_->accept(this);
      bufAppend(", ");
      listoperation = listoperation->listoperation_;
    }
    else
    {
      listoperation->operation_->accept(this);
      listoperation = 0;
    }
  }
}

void ShowAbsyn::visitOperation(Operation* p) {} //abstract class

void ShowAbsyn::visitOAddC(OAddC* p)
{
  bufAppend('(');
  bufAppend("OAddC");
  bufAppend(' ');
  bufAppend('[');
  if (p->register_)  p->register_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitOSubC(OSubC* p)
{
  bufAppend('(');
  bufAppend("OSubC");
  bufAppend(' ');
  bufAppend('[');
  if (p->register_)  p->register_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitOLbl(OLbl* p)
{
  bufAppend('(');
  bufAppend("OLbl");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitOJmp(OJmp* p)
{
  bufAppend('(');
  bufAppend("OJmp");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOJb(OJb* p)
{
  bufAppend('(');
  bufAppend("OJb");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOJbe(OJbe* p)
{
  bufAppend('(');
  bufAppend("OJbe");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOJe(OJe* p)
{
  bufAppend('(');
  bufAppend("OJe");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOJne(OJne* p)
{
  bufAppend('(');
  bufAppend("OJne");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOJz(OJz* p)
{
  bufAppend('(');
  bufAppend("OJz");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOJnz(OJnz* p)
{
  bufAppend('(');
  bufAppend("OJnz");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOCall(OCall* p)
{
  bufAppend('(');
  bufAppend("OCall");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitORet(ORet* p)
{
  bufAppend("ORet");
}
void ShowAbsyn::visitOPush(OPush* p)
{
  bufAppend('(');
  bufAppend("OPush");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOPop(OPop* p)
{
  bufAppend('(');
  bufAppend("OPop");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOFadd(OFadd* p)
{
  bufAppend("OFadd");
}
void ShowAbsyn::visitOFaddp(OFaddp* p)
{
  bufAppend("OFaddp");
}
void ShowAbsyn::visitOFsub(OFsub* p)
{
  bufAppend("OFsub");
}
void ShowAbsyn::visitOFsubp(OFsubp* p)
{
  bufAppend("OFsubp");
}
void ShowAbsyn::visitOFsubrp(OFsubrp* p)
{
  bufAppend("OFsubrp");
}
void ShowAbsyn::visitOFmulp(OFmulp* p)
{
  bufAppend("OFmulp");
}
void ShowAbsyn::visitOFdivp(OFdivp* p)
{
  bufAppend("OFdivp");
}
void ShowAbsyn::visitOFdivrp(OFdivrp* p)
{
  bufAppend("OFdivrp");
}
void ShowAbsyn::visitOFchs(OFchs* p)
{
  bufAppend("OFchs");
}
void ShowAbsyn::visitOFsin(OFsin* p)
{
  bufAppend("OFsin");
}
void ShowAbsyn::visitOFcos(OFcos* p)
{
  bufAppend("OFcos");
}
void ShowAbsyn::visitOFprem(OFprem* p)
{
  bufAppend("OFprem");
}
void ShowAbsyn::visitOFptan(OFptan* p)
{
  bufAppend("OFptan");
}
void ShowAbsyn::visitOFpatan(OFpatan* p)
{
  bufAppend("OFpatan");
}
void ShowAbsyn::visitOFsqrt(OFsqrt* p)
{
  bufAppend("OFsqrt");
}
void ShowAbsyn::visitOFrndint(OFrndint* p)
{
  bufAppend("OFrndint");
}
void ShowAbsyn::visitOFscale(OFscale* p)
{
  bufAppend("OFscale");
}
void ShowAbsyn::visitOFtxmo(OFtxmo* p)
{
  bufAppend("OFtxmo");
}
void ShowAbsyn::visitOFyltx(OFyltx* p)
{
  bufAppend("OFyltx");
}
void ShowAbsyn::visitOFyltxpo(OFyltxpo* p)
{
  bufAppend("OFyltxpo");
}
void ShowAbsyn::visitOFcomi(OFcomi* p)
{
  bufAppend("OFcomi");
}
void ShowAbsyn::visitOFcmovb(OFcmovb* p)
{
  bufAppend("OFcmovb");
}
void ShowAbsyn::visitOFcmovbe(OFcmovbe* p)
{
  bufAppend("OFcmovbe");
}
void ShowAbsyn::visitOFcmove(OFcmove* p)
{
  bufAppend("OFcmove");
}
void ShowAbsyn::visitOFcmovnb(OFcmovnb* p)
{
  bufAppend("OFcmovnb");
}
void ShowAbsyn::visitOFcmovnbe(OFcmovnbe* p)
{
  bufAppend("OFcmovnbe");
}
void ShowAbsyn::visitOFcmovne(OFcmovne* p)
{
  bufAppend("OFcmovne");
}
void ShowAbsyn::visitOFcmovnu(OFcmovnu* p)
{
  bufAppend("OFcmovnu");
}
void ShowAbsyn::visitOFcmovu(OFcmovu* p)
{
  bufAppend("OFcmovu");
}
void ShowAbsyn::visitOFld(OFld* p)
{
  bufAppend('(');
  bufAppend("OFld");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOFild(OFild* p)
{
  bufAppend('(');
  bufAppend("OFild");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOFldt(OFldt* p)
{
  bufAppend("OFldt");
}
void ShowAbsyn::visitOFldn(OFldn* p)
{
  bufAppend("OFldn");
}
void ShowAbsyn::visitOFldz(OFldz* p)
{
  bufAppend("OFldz");
}
void ShowAbsyn::visitOFldo(OFldo* p)
{
  bufAppend("OFldo");
}
void ShowAbsyn::visitOFldpi(OFldpi* p)
{
  bufAppend("OFldpi");
}
void ShowAbsyn::visitOFldlte(OFldlte* p)
{
  bufAppend("OFldlte");
}
void ShowAbsyn::visitOFldlnt(OFldlnt* p)
{
  bufAppend("OFldlnt");
}
void ShowAbsyn::visitOFldlgt(OFldlgt* p)
{
  bufAppend("OFldlgt");
}
void ShowAbsyn::visitOFst(OFst* p)
{
  bufAppend('(');
  bufAppend("OFst");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOFist(OFist* p)
{
  bufAppend('(');
  bufAppend("OFist");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOFstp(OFstp* p)
{
  bufAppend('(');
  bufAppend("OFstp");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOFistp(OFistp* p)
{
  bufAppend('(');
  bufAppend("OFistp");
  bufAppend(' ');
  bufAppend('[');
  if (p->operand_)  p->operand_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOFstpt(OFstpt* p)
{
  bufAppend("OFstpt");
}
void ShowAbsyn::visitOFfree(OFfree* p)
{
  bufAppend("OFfree");
}
void ShowAbsyn::visitOFfreea(OFfreea* p)
{
  bufAppend("OFfreea");
}
void ShowAbsyn::visitOFfreeb(OFfreeb* p)
{
  bufAppend("OFfreeb");
}
void ShowAbsyn::visitOFfreec(OFfreec* p)
{
  bufAppend("OFfreec");
}
void ShowAbsyn::visitOFfreed(OFfreed* p)
{
  bufAppend("OFfreed");
}
void ShowAbsyn::visitOFfreee(OFfreee* p)
{
  bufAppend("OFfreee");
}
void ShowAbsyn::visitOFfreef(OFfreef* p)
{
  bufAppend("OFfreef");
}
void ShowAbsyn::visitOFfreeg(OFfreeg* p)
{
  bufAppend("OFfreeg");
}
void ShowAbsyn::visitOFxchg(OFxchg* p)
{
  bufAppend("OFxchg");
}
void ShowAbsyn::visitOFincstp(OFincstp* p)
{
  bufAppend("OFincstp");
}
void ShowAbsyn::visitOFdecstp(OFdecstp* p)
{
  bufAppend("OFdecstp");
}
void ShowAbsyn::visitRegister(Register* p) {} //abstract class

void ShowAbsyn::visitREax(REax* p)
{
  bufAppend("REax");
}
void ShowAbsyn::visitREcx(REcx* p)
{
  bufAppend("REcx");
}
void ShowAbsyn::visitREdx(REdx* p)
{
  bufAppend("REdx");
}
void ShowAbsyn::visitREbx(REbx* p)
{
  bufAppend("REbx");
}
void ShowAbsyn::visitREsp(REsp* p)
{
  bufAppend("REsp");
}
void ShowAbsyn::visitREbp(REbp* p)
{
  bufAppend("REbp");
}
void ShowAbsyn::visitREsi(REsi* p)
{
  bufAppend("REsi");
}
void ShowAbsyn::visitREdi(REdi* p)
{
  bufAppend("REdi");
}
void ShowAbsyn::visitOperand(Operand* p) {} //abstract class

void ShowAbsyn::visitOReg(OReg* p)
{
  bufAppend('(');
  bufAppend("OReg");
  bufAppend(' ');
  bufAppend('[');
  if (p->register_)  p->register_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitOHex(OHex* p)
{
  bufAppend('(');
  bufAppend("OHex");
  bufAppend(' ');
  visitIdent(p->hexconstant_);
  bufAppend(')');
}
void ShowAbsyn::visitOLab(OLab* p)
{
  bufAppend('(');
  bufAppend("OLab");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitOLitAdd(OLitAdd* p)
{
  bufAppend('(');
  bufAppend("OLitAdd");
  bufAppend(' ');
  visitIdent(p->hexconstant_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitORegAdd(ORegAdd* p)
{
  bufAppend('(');
  bufAppend("ORegAdd");
  bufAppend(' ');
  bufAppend('[');
  if (p->register_)  p->register_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitORelAddP(ORelAddP* p)
{
  bufAppend('(');
  bufAppend("ORelAddP");
  bufAppend(' ');
  bufAppend('[');
  if (p->register_)  p->register_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitORelAddS(ORelAddS* p)
{
  bufAppend('(');
  bufAppend("ORelAddS");
  bufAppend(' ');
  bufAppend('[');
  if (p->register_)  p->register_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitInteger(Integer i)
{
  char tmp[16];
  sprintf(tmp, "%d", i);
  bufAppend(tmp);
}
void ShowAbsyn::visitDouble(Double d)
{
  char tmp[16];
  sprintf(tmp, "%g", d);
  bufAppend(tmp);
}
void ShowAbsyn::visitChar(Char c)
{
  bufAppend('\'');
  bufAppend(c);
  bufAppend('\'');
}
void ShowAbsyn::visitString(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}
void ShowAbsyn::visitIdent(String s)
{
  bufAppend('\"');
  bufAppend(s);
  bufAppend('\"');
}

