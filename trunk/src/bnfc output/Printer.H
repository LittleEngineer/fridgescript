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

  void visitProgram(Program *p); /* abstract class */
  void visitMain(Main *p);
  void visitBlock(Block *p); /* abstract class */
  void visitBFunc(BFunc *p);
  void visitBStmt(BStmt *p);
  void visitFunction(Function *p); /* abstract class */
  void visitDTFunc(DTFunc *p);
  void visitParameter(Parameter *p); /* abstract class */
  void visitDTParam(DTParam *p);
  void visitListBlock(ListBlock* p);
  void visitListFunction(ListFunction* p);
  void visitListStatement(ListStatement* p);
  void visitListParameter(ListParameter* p);
  void visitStatement(Statement *p); /* abstract class */
  void visitSExp(SExp *p);
  void visitSScope(SScope *p);
  void visitSRet(SRet *p);
  void visitSIf(SIf *p);
  void visitSIfElse(SIfElse *p);
  void visitSLoop(SLoop *p);
  void visitSWhile(SWhile *p);
  void visitSUntil(SUntil *p);
  void visitSFor(SFor *p);
  void visitSBreak(SBreak *p);
  void visitSContinue(SContinue *p);
  void visitExpression(Expression *p); /* abstract class */
  void visitECDbl(ECDbl *p);
  void visitECInt(ECInt *p);
  void visitEVar(EVar *p);
  void visitEPi(EPi *p);
  void visitESimpleCall(ESimpleCall *p);
  void visitECall(ECall *p);
  void visitEPostInc(EPostInc *p);
  void visitEPostDec(EPostDec *p);
  void visitEAbs(EAbs *p);
  void visitEPow(EPow *p);
  void visitESqrt(ESqrt *p);
  void visitEExp(EExp *p);
  void visitELog(ELog *p);
  void visitELogD(ELogD *p);
  void visitESin(ESin *p);
  void visitECos(ECos *p);
  void visitETan(ETan *p);
  void visitEAtan(EAtan *p);
  void visitEAtanT(EAtanT *p);
  void visitEAsin(EAsin *p);
  void visitEAcos(EAcos *p);
  void visitELnot(ELnot *p);
  void visitEPreInc(EPreInc *p);
  void visitEPreDec(EPreDec *p);
  void visitENeg(ENeg *p);
  void visitEBnot(EBnot *p);
  void visitEPos(EPos *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitEMod(EMod *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitELSh(ELSh *p);
  void visitERSh(ERSh *p);
  void visitELT(ELT *p);
  void visitEGT(EGT *p);
  void visitELE(ELE *p);
  void visitEGE(EGE *p);
  void visitEE(EE *p);
  void visitENE(ENE *p);
  void visitEBand(EBand *p);
  void visitEBor(EBor *p);
  void visitEBxor(EBxor *p);
  void visitELand(ELand *p);
  void visitELor(ELor *p);
  void visitELxor(ELxor *p);
  void visitECon(ECon *p);
  void visitEAss(EAss *p);
  void visitEAddAss(EAddAss *p);
  void visitESubAss(ESubAss *p);
  void visitEMulAss(EMulAss *p);
  void visitEDivAss(EDivAss *p);
  void visitEModAss(EModAss *p);
  void visitEAndAss(EAndAss *p);
  void visitEOrAss(EOrAss *p);
  void visitEXorAss(EXorAss *p);
  void visitELShAss(ELShAss *p);
  void visitERShAss(ERShAss *p);
  void visitListExpression(ListExpression* p);

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

  void visitProgram(Program *p); /* abstract class */
  void visitMain(Main *p);
  void visitBlock(Block *p); /* abstract class */
  void visitBFunc(BFunc *p);
  void visitBStmt(BStmt *p);
  void visitFunction(Function *p); /* abstract class */
  void visitDTFunc(DTFunc *p);
  void visitParameter(Parameter *p); /* abstract class */
  void visitDTParam(DTParam *p);
  void visitListBlock(ListBlock* p);
  void visitListFunction(ListFunction* p);
  void visitListStatement(ListStatement* p);
  void visitListParameter(ListParameter* p);
  void visitStatement(Statement *p); /* abstract class */
  void visitSExp(SExp *p);
  void visitSScope(SScope *p);
  void visitSRet(SRet *p);
  void visitSIf(SIf *p);
  void visitSIfElse(SIfElse *p);
  void visitSLoop(SLoop *p);
  void visitSWhile(SWhile *p);
  void visitSUntil(SUntil *p);
  void visitSFor(SFor *p);
  void visitSBreak(SBreak *p);
  void visitSContinue(SContinue *p);
  void visitExpression(Expression *p); /* abstract class */
  void visitECDbl(ECDbl *p);
  void visitECInt(ECInt *p);
  void visitEVar(EVar *p);
  void visitEPi(EPi *p);
  void visitESimpleCall(ESimpleCall *p);
  void visitECall(ECall *p);
  void visitEPostInc(EPostInc *p);
  void visitEPostDec(EPostDec *p);
  void visitEAbs(EAbs *p);
  void visitEPow(EPow *p);
  void visitESqrt(ESqrt *p);
  void visitEExp(EExp *p);
  void visitELog(ELog *p);
  void visitELogD(ELogD *p);
  void visitESin(ESin *p);
  void visitECos(ECos *p);
  void visitETan(ETan *p);
  void visitEAtan(EAtan *p);
  void visitEAtanT(EAtanT *p);
  void visitEAsin(EAsin *p);
  void visitEAcos(EAcos *p);
  void visitELnot(ELnot *p);
  void visitEPreInc(EPreInc *p);
  void visitEPreDec(EPreDec *p);
  void visitENeg(ENeg *p);
  void visitEBnot(EBnot *p);
  void visitEPos(EPos *p);
  void visitEMul(EMul *p);
  void visitEDiv(EDiv *p);
  void visitEMod(EMod *p);
  void visitEAdd(EAdd *p);
  void visitESub(ESub *p);
  void visitELSh(ELSh *p);
  void visitERSh(ERSh *p);
  void visitELT(ELT *p);
  void visitEGT(EGT *p);
  void visitELE(ELE *p);
  void visitEGE(EGE *p);
  void visitEE(EE *p);
  void visitENE(ENE *p);
  void visitEBand(EBand *p);
  void visitEBor(EBor *p);
  void visitEBxor(EBxor *p);
  void visitELand(ELand *p);
  void visitELor(ELor *p);
  void visitELxor(ELxor *p);
  void visitECon(ECon *p);
  void visitEAss(EAss *p);
  void visitEAddAss(EAddAss *p);
  void visitESubAss(ESubAss *p);
  void visitEMulAss(EMulAss *p);
  void visitEDivAss(EDivAss *p);
  void visitEModAss(EModAss *p);
  void visitEAndAss(EAndAss *p);
  void visitEOrAss(EOrAss *p);
  void visitEXorAss(EXorAss *p);
  void visitELShAss(ELShAss *p);
  void visitERShAss(ERShAss *p);
  void visitListExpression(ListExpression* p);

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

