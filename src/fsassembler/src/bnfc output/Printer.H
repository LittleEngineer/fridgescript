#ifndef PRINTER_HEADER
#define PRINTER_HEADER

#include "Absyn.H"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Certain applications may improve performance by changing the buffer size */
#define BUFFER_INITIAL 2000
/* You may wish to change _L_PAREN or _R_PAREN */
#define _L_PAREN '('
#define _R_PAREN ')'

class PrintAbsyn : public Visitor
{
 protected:
  int _n_, _i_;
  /* The following are simple heuristics for rendering terminals */
  /* You may wish to change them */
  void render(Char c);
  void render(String s);
  void indent(void);
  void backup(void);
 public:
  PrintAbsyn(void);
  ~PrintAbsyn(void);
  char* print(Visitable* v);

  void visitCode(Code *p); /* abstract class */
  void visitMain(Main *p);
  void visitListOperation(ListOperation* p);
  void visitOperation(Operation *p); /* abstract class */
  void visitOAddC(OAddC *p);
  void visitOSubC(OSubC *p);
  void visitOLbl(OLbl *p);
  void visitOJmp(OJmp *p);
  void visitOJb(OJb *p);
  void visitOJbe(OJbe *p);
  void visitOJe(OJe *p);
  void visitOJne(OJne *p);
  void visitOJz(OJz *p);
  void visitOJnz(OJnz *p);
  void visitOCall(OCall *p);
  void visitORet(ORet *p);
  void visitOPush(OPush *p);
  void visitOPop(OPop *p);
  void visitOFadd(OFadd *p);
  void visitOFaddp(OFaddp *p);
  void visitOFsub(OFsub *p);
  void visitOFsubp(OFsubp *p);
  void visitOFsubrp(OFsubrp *p);
  void visitOFmulp(OFmulp *p);
  void visitOFdivp(OFdivp *p);
  void visitOFdivrp(OFdivrp *p);
  void visitOFchs(OFchs *p);
  void visitOFsin(OFsin *p);
  void visitOFcos(OFcos *p);
  void visitOFprem(OFprem *p);
  void visitOFptan(OFptan *p);
  void visitOFpatan(OFpatan *p);
  void visitOFsqrt(OFsqrt *p);
  void visitOFrndint(OFrndint *p);
  void visitOFscale(OFscale *p);
  void visitOFtxmo(OFtxmo *p);
  void visitOFyltx(OFyltx *p);
  void visitOFyltxpo(OFyltxpo *p);
  void visitOFcomi(OFcomi *p);
  void visitOFcmovb(OFcmovb *p);
  void visitOFcmovbe(OFcmovbe *p);
  void visitOFcmove(OFcmove *p);
  void visitOFcmovnb(OFcmovnb *p);
  void visitOFcmovnbe(OFcmovnbe *p);
  void visitOFcmovne(OFcmovne *p);
  void visitOFcmovnu(OFcmovnu *p);
  void visitOFcmovu(OFcmovu *p);
  void visitOFld(OFld *p);
  void visitOFild(OFild *p);
  void visitOFldt(OFldt *p);
  void visitOFldn(OFldn *p);
  void visitOFldz(OFldz *p);
  void visitOFldo(OFldo *p);
  void visitOFldpi(OFldpi *p);
  void visitOFldlte(OFldlte *p);
  void visitOFldlnt(OFldlnt *p);
  void visitOFldlgt(OFldlgt *p);
  void visitOFst(OFst *p);
  void visitOFist(OFist *p);
  void visitOFstp(OFstp *p);
  void visitOFistp(OFistp *p);
  void visitOFstpt(OFstpt *p);
  void visitOFfree(OFfree *p);
  void visitOFfreea(OFfreea *p);
  void visitOFfreeb(OFfreeb *p);
  void visitOFfreec(OFfreec *p);
  void visitOFfreed(OFfreed *p);
  void visitOFfreee(OFfreee *p);
  void visitOFfreef(OFfreef *p);
  void visitOFfreeg(OFfreeg *p);
  void visitOFxchg(OFxchg *p);
  void visitOFincstp(OFincstp *p);
  void visitOFdecstp(OFdecstp *p);
  void visitRegister(Register *p); /* abstract class */
  void visitREax(REax *p);
  void visitREcx(REcx *p);
  void visitREdx(REdx *p);
  void visitREbx(REbx *p);
  void visitREsp(REsp *p);
  void visitREbp(REbp *p);
  void visitREsi(REsi *p);
  void visitREdi(REdi *p);
  void visitOperand(Operand *p); /* abstract class */
  void visitOReg(OReg *p);
  void visitOHex(OHex *p);
  void visitOLab(OLab *p);
  void visitOLitAdd(OLitAdd *p);
  void visitORegAdd(ORegAdd *p);
  void visitORelAddP(ORelAddP *p);
  void visitORelAddS(ORelAddS *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



class ShowAbsyn : public Visitor
{
 public:
  ShowAbsyn(void);
  ~ShowAbsyn(void);
  char* show(Visitable* v);

  void visitCode(Code *p); /* abstract class */
  void visitMain(Main *p);
  void visitListOperation(ListOperation* p);
  void visitOperation(Operation *p); /* abstract class */
  void visitOAddC(OAddC *p);
  void visitOSubC(OSubC *p);
  void visitOLbl(OLbl *p);
  void visitOJmp(OJmp *p);
  void visitOJb(OJb *p);
  void visitOJbe(OJbe *p);
  void visitOJe(OJe *p);
  void visitOJne(OJne *p);
  void visitOJz(OJz *p);
  void visitOJnz(OJnz *p);
  void visitOCall(OCall *p);
  void visitORet(ORet *p);
  void visitOPush(OPush *p);
  void visitOPop(OPop *p);
  void visitOFadd(OFadd *p);
  void visitOFaddp(OFaddp *p);
  void visitOFsub(OFsub *p);
  void visitOFsubp(OFsubp *p);
  void visitOFsubrp(OFsubrp *p);
  void visitOFmulp(OFmulp *p);
  void visitOFdivp(OFdivp *p);
  void visitOFdivrp(OFdivrp *p);
  void visitOFchs(OFchs *p);
  void visitOFsin(OFsin *p);
  void visitOFcos(OFcos *p);
  void visitOFprem(OFprem *p);
  void visitOFptan(OFptan *p);
  void visitOFpatan(OFpatan *p);
  void visitOFsqrt(OFsqrt *p);
  void visitOFrndint(OFrndint *p);
  void visitOFscale(OFscale *p);
  void visitOFtxmo(OFtxmo *p);
  void visitOFyltx(OFyltx *p);
  void visitOFyltxpo(OFyltxpo *p);
  void visitOFcomi(OFcomi *p);
  void visitOFcmovb(OFcmovb *p);
  void visitOFcmovbe(OFcmovbe *p);
  void visitOFcmove(OFcmove *p);
  void visitOFcmovnb(OFcmovnb *p);
  void visitOFcmovnbe(OFcmovnbe *p);
  void visitOFcmovne(OFcmovne *p);
  void visitOFcmovnu(OFcmovnu *p);
  void visitOFcmovu(OFcmovu *p);
  void visitOFld(OFld *p);
  void visitOFild(OFild *p);
  void visitOFldt(OFldt *p);
  void visitOFldn(OFldn *p);
  void visitOFldz(OFldz *p);
  void visitOFldo(OFldo *p);
  void visitOFldpi(OFldpi *p);
  void visitOFldlte(OFldlte *p);
  void visitOFldlnt(OFldlnt *p);
  void visitOFldlgt(OFldlgt *p);
  void visitOFst(OFst *p);
  void visitOFist(OFist *p);
  void visitOFstp(OFstp *p);
  void visitOFistp(OFistp *p);
  void visitOFstpt(OFstpt *p);
  void visitOFfree(OFfree *p);
  void visitOFfreea(OFfreea *p);
  void visitOFfreeb(OFfreeb *p);
  void visitOFfreec(OFfreec *p);
  void visitOFfreed(OFfreed *p);
  void visitOFfreee(OFfreee *p);
  void visitOFfreef(OFfreef *p);
  void visitOFfreeg(OFfreeg *p);
  void visitOFxchg(OFxchg *p);
  void visitOFincstp(OFincstp *p);
  void visitOFdecstp(OFdecstp *p);
  void visitRegister(Register *p); /* abstract class */
  void visitREax(REax *p);
  void visitREcx(REcx *p);
  void visitREdx(REdx *p);
  void visitREbx(REbx *p);
  void visitREsp(REsp *p);
  void visitREbp(REbp *p);
  void visitREsi(REsi *p);
  void visitREdi(REdi *p);
  void visitOperand(Operand *p); /* abstract class */
  void visitOReg(OReg *p);
  void visitOHex(OHex *p);
  void visitOLab(OLab *p);
  void visitOLitAdd(OLitAdd *p);
  void visitORegAdd(ORegAdd *p);
  void visitORelAddP(ORelAddP *p);
  void visitORelAddS(ORelAddS *p);

  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
  void visitIdent(String s);
 protected:
  void inline bufAppend(const char* s)
  {
    int len = strlen(s);
    while (cur_ + len > buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    for(int n = 0; n < len; n++)
    {
      buf_[cur_ + n] = s[n];
    }
    cur_ += len;
    buf_[cur_] = 0;
  }
  void inline bufAppend(const char c)
  {
    if (cur_ == buf_size)
    {
      buf_size *= 2; /* Double the buffer size */
      resizeBuffer();
    }
    buf_[cur_] = c;
    cur_++;
    buf_[cur_] = 0;
  }
  void inline bufReset(void)
  {
    cur_ = 0;
    buf_size = BUFFER_INITIAL;
    resizeBuffer();
    memset(buf_, 0, buf_size);
  }
  void inline resizeBuffer(void)
  {
    char* temp = (char*) malloc(buf_size);
    if (!temp)
    {
      fprintf(stderr, "Error: Out of memory while attempting to grow buffer!\n");
      exit(1);
    }
    if (buf_)
    {
      strcpy(temp, buf_);
      free(buf_);
    }
    buf_ = temp;
  }
  char *buf_;
  int cur_, buf_size;
};



#endif

