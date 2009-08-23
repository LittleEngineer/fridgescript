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
void PrintAbsyn::visitProgram(Program*p) {} //abstract class

void PrintAbsyn::visitMain(Main* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listblock_) {_i_ = 0; p->listblock_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBlock(Block*p) {} //abstract class

void PrintAbsyn::visitBFunc(BFunc* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->listfunction_) {_i_ = 0; p->listfunction_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitBStmt(BStmt* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}
  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitFunction(Function*p) {} //abstract class

void PrintAbsyn::visitDTFunc(DTFunc* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render('(');
  if(p->listparameter_) {_i_ = 0; p->listparameter_->accept(this);}  render(')');
  render('{');
  if(p->listblock_) {_i_ = 0; p->listblock_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitParameter(Parameter*p) {} //abstract class

void PrintAbsyn::visitDTParam(DTParam* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListBlock(ListBlock *listblock)
{
  while(listblock!= 0)
  {
    if (listblock->listblock_ == 0)
    {
      listblock->block_->accept(this);
      render("");
      listblock = 0;
    }
    else
    {
      listblock->block_->accept(this);
      render("");
      listblock = listblock->listblock_;
    }
  }
}

void PrintAbsyn::visitListFunction(ListFunction *listfunction)
{
  while(listfunction!= 0)
  {
    if (listfunction->listfunction_ == 0)
    {
      listfunction->function_->accept(this);

      listfunction = 0;
    }
    else
    {
      listfunction->function_->accept(this);
      render("");
      listfunction = listfunction->listfunction_;
    }
  }
}

void PrintAbsyn::visitListStatement(ListStatement *liststatement)
{
  while(liststatement!= 0)
  {
    if (liststatement->liststatement_ == 0)
    {
      liststatement->statement_->accept(this);

      liststatement = 0;
    }
    else
    {
      liststatement->statement_->accept(this);
      render("");
      liststatement = liststatement->liststatement_;
    }
  }
}

void PrintAbsyn::visitListParameter(ListParameter *listparameter)
{
  while(listparameter!= 0)
  {
    if (listparameter->listparameter_ == 0)
    {
      listparameter->parameter_->accept(this);

      listparameter = 0;
    }
    else
    {
      listparameter->parameter_->accept(this);
      render(',');
      listparameter = listparameter->listparameter_;
    }
  }
}

void PrintAbsyn::visitStatement(Statement*p) {} //abstract class

void PrintAbsyn::visitSExp(SExp* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  _i_ = 0; p->expression_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSScope(SScope* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSRet(SRet* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("return");
  _i_ = 0; p->expression_->accept(this);
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSIf(SIf* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');
  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSIfElse(SIfElse* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("if");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');
  render('{');
  if(p->liststatement_1) {_i_ = 0; p->liststatement_1->accept(this);}  render('}');
  render("else");
  render('{');
  if(p->liststatement_2) {_i_ = 0; p->liststatement_2->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSLoop(SLoop* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("loop");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');
  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSWhile(SWhile* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("loop while");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');
  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSUntil(SUntil* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("loop until");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');
  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSFor(SFor* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("loop for");
  render('(');
  if(p->listexpression_1) {_i_ = 0; p->listexpression_1->accept(this);}  render(';');
  _i_ = 0; p->expression_->accept(this);
  render(';');
  if(p->listexpression_2) {_i_ = 0; p->listexpression_2->accept(this);}  render(')');
  render('{');
  if(p->liststatement_) {_i_ = 0; p->liststatement_->accept(this);}  render('}');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSBreak(SBreak* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("break");
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitSContinue(SContinue* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  render("continue");
  render(';');

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitExpression(Expression*p) {} //abstract class

void PrintAbsyn::visitECDbl(ECDbl* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  visitDouble(p->double_);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitECInt(ECInt* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  visitInteger(p->integer_);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEVar(EVar* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  visitIdent(p->ident_);

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPi(EPi* p)
{
  int oldi = _i_;
  if (oldi > 11) render(_L_PAREN);

  render("pi");

  if (oldi > 11) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESimpleCall(ESimpleCall* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  visitIdent(p->ident_);
  render('(');
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitECall(ECall* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  visitIdent(p->ident_);
  render('(');
  if(p->listexpression_) {_i_ = 0; p->listexpression_->accept(this);}  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPostInc(EPostInc* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  visitIdent(p->ident_);
  render("++");

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPostDec(EPostDec* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  visitIdent(p->ident_);
  render("--");

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAbs(EAbs* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("abs");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPow(EPow* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("pow");
  render('(');
  _i_ = 0; p->expression_1->accept(this);
  render(',');
  _i_ = 0; p->expression_2->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESqrt(ESqrt* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("sqrt");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEExp(EExp* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("exp");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELog(ELog* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("log");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELogD(ELogD* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("log10");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESin(ESin* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("sin");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitECos(ECos* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("cos");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitETan(ETan* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("tan");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAtan(EAtan* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("atan");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAtanT(EAtanT* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("atan2");
  render('(');
  _i_ = 0; p->expression_1->accept(this);
  render(',');
  _i_ = 0; p->expression_2->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAsin(EAsin* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("asin");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAcos(EAcos* p)
{
  int oldi = _i_;
  if (oldi > 10) render(_L_PAREN);

  render("acos");
  render('(');
  _i_ = 0; p->expression_->accept(this);
  render(')');

  if (oldi > 10) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELnot(ELnot* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('!');
  _i_ = 10; p->expression_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPreInc(EPreInc* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render("++");
  visitIdent(p->ident_);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPreDec(EPreDec* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render("--");
  visitIdent(p->ident_);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENeg(ENeg* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('-');
  _i_ = 10; p->expression_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEBnot(EBnot* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('~');
  _i_ = 10; p->expression_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEPos(EPos* p)
{
  int oldi = _i_;
  if (oldi > 9) render(_L_PAREN);

  render('+');
  _i_ = 10; p->expression_->accept(this);

  if (oldi > 9) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMul(EMul* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->expression_1->accept(this);
  render('*');
  _i_ = 9; p->expression_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDiv(EDiv* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->expression_1->accept(this);
  render('/');
  _i_ = 9; p->expression_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMod(EMod* p)
{
  int oldi = _i_;
  if (oldi > 8) render(_L_PAREN);

  _i_ = 8; p->expression_1->accept(this);
  render('%');
  _i_ = 9; p->expression_2->accept(this);

  if (oldi > 8) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAdd(EAdd* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  _i_ = 7; p->expression_1->accept(this);
  render('+');
  _i_ = 8; p->expression_2->accept(this);

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESub(ESub* p)
{
  int oldi = _i_;
  if (oldi > 7) render(_L_PAREN);

  _i_ = 7; p->expression_1->accept(this);
  render('-');
  _i_ = 8; p->expression_2->accept(this);

  if (oldi > 7) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELSh(ELSh* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 6; p->expression_1->accept(this);
  render("<<");
  _i_ = 7; p->expression_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERSh(ERSh* p)
{
  int oldi = _i_;
  if (oldi > 6) render(_L_PAREN);

  _i_ = 6; p->expression_1->accept(this);
  render(">>");
  _i_ = 7; p->expression_2->accept(this);

  if (oldi > 6) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELT(ELT* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 6; p->expression_1->accept(this);
  render('<');
  _i_ = 6; p->expression_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGT(EGT* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 6; p->expression_1->accept(this);
  render('>');
  _i_ = 6; p->expression_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELE(ELE* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 6; p->expression_1->accept(this);
  render("<=");
  _i_ = 6; p->expression_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEGE(EGE* p)
{
  int oldi = _i_;
  if (oldi > 5) render(_L_PAREN);

  _i_ = 6; p->expression_1->accept(this);
  render(">=");
  _i_ = 6; p->expression_2->accept(this);

  if (oldi > 5) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEE(EE* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 5; p->expression_1->accept(this);
  render("==");
  _i_ = 5; p->expression_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitENE(ENE* p)
{
  int oldi = _i_;
  if (oldi > 4) render(_L_PAREN);

  _i_ = 5; p->expression_1->accept(this);
  render("!=");
  _i_ = 5; p->expression_2->accept(this);

  if (oldi > 4) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEBand(EBand* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->expression_1->accept(this);
  render('&');
  _i_ = 4; p->expression_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEBor(EBor* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->expression_1->accept(this);
  render('|');
  _i_ = 4; p->expression_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEBxor(EBxor* p)
{
  int oldi = _i_;
  if (oldi > 3) render(_L_PAREN);

  _i_ = 3; p->expression_1->accept(this);
  render('^');
  _i_ = 4; p->expression_2->accept(this);

  if (oldi > 3) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELand(ELand* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 3; p->expression_1->accept(this);
  render("&&");
  _i_ = 3; p->expression_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELor(ELor* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 3; p->expression_1->accept(this);
  render("||");
  _i_ = 3; p->expression_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELxor(ELxor* p)
{
  int oldi = _i_;
  if (oldi > 2) render(_L_PAREN);

  _i_ = 3; p->expression_1->accept(this);
  render("^^");
  _i_ = 3; p->expression_2->accept(this);

  if (oldi > 2) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitECon(ECon* p)
{
  int oldi = _i_;
  if (oldi > 1) render(_L_PAREN);

  _i_ = 2; p->expression_1->accept(this);
  render('?');
  _i_ = 2; p->expression_2->accept(this);
  render(':');
  _i_ = 2; p->expression_3->accept(this);

  if (oldi > 1) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAss(EAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render('=');
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAddAss(EAddAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("+=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitESubAss(ESubAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("-=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEMulAss(EMulAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("*=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEDivAss(EDivAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("/=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEModAss(EModAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("%=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEAndAss(EAndAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("&=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEOrAss(EOrAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("|=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitEXorAss(EXorAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("^=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitELShAss(ELShAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render("<<=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitERShAss(ERShAss* p)
{
  int oldi = _i_;
  if (oldi > 0) render(_L_PAREN);

  visitIdent(p->ident_);
  render(">>=");
  _i_ = 0; p->expression_->accept(this);

  if (oldi > 0) render(_R_PAREN);

  _i_ = oldi;
}

void PrintAbsyn::visitListExpression(ListExpression *listexpression)
{
  while(listexpression!= 0)
  {
    if (listexpression->listexpression_ == 0)
    {
      listexpression->expression_->accept(this);

      listexpression = 0;
    }
    else
    {
      listexpression->expression_->accept(this);
      render(',');
      listexpression = listexpression->listexpression_;
    }
  }
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
void ShowAbsyn::visitProgram(Program* p) {} //abstract class

void ShowAbsyn::visitMain(Main* p)
{
  bufAppend('(');
  bufAppend("Main");
  bufAppend(' ');
  bufAppend('[');
  if (p->listblock_)  p->listblock_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitBlock(Block* p) {} //abstract class

void ShowAbsyn::visitBFunc(BFunc* p)
{
  bufAppend('(');
  bufAppend("BFunc");
  bufAppend(' ');
  bufAppend('[');
  if (p->listfunction_)  p->listfunction_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitBStmt(BStmt* p)
{
  bufAppend('(');
  bufAppend("BStmt");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitFunction(Function* p) {} //abstract class

void ShowAbsyn::visitDTFunc(DTFunc* p)
{
  bufAppend('(');
  bufAppend("DTFunc");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listparameter_)  p->listparameter_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->listblock_)  p->listblock_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitParameter(Parameter* p) {} //abstract class

void ShowAbsyn::visitDTParam(DTParam* p)
{
  bufAppend('(');
  bufAppend("DTParam");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitListBlock(ListBlock *listblock)
{
  while(listblock!= 0)
  {
    if (listblock->listblock_)
    {
      listblock->block_->accept(this);
      bufAppend(", ");
      listblock = listblock->listblock_;
    }
    else
    {
      listblock->block_->accept(this);
      listblock = 0;
    }
  }
}

void ShowAbsyn::visitListFunction(ListFunction *listfunction)
{
  while(listfunction!= 0)
  {
    if (listfunction->listfunction_)
    {
      listfunction->function_->accept(this);
      bufAppend(", ");
      listfunction = listfunction->listfunction_;
    }
    else
    {
      listfunction->function_->accept(this);
      listfunction = 0;
    }
  }
}

void ShowAbsyn::visitListStatement(ListStatement *liststatement)
{
  while(liststatement!= 0)
  {
    if (liststatement->liststatement_)
    {
      liststatement->statement_->accept(this);
      bufAppend(", ");
      liststatement = liststatement->liststatement_;
    }
    else
    {
      liststatement->statement_->accept(this);
      liststatement = 0;
    }
  }
}

void ShowAbsyn::visitListParameter(ListParameter *listparameter)
{
  while(listparameter!= 0)
  {
    if (listparameter->listparameter_)
    {
      listparameter->parameter_->accept(this);
      bufAppend(", ");
      listparameter = listparameter->listparameter_;
    }
    else
    {
      listparameter->parameter_->accept(this);
      listparameter = 0;
    }
  }
}

void ShowAbsyn::visitStatement(Statement* p) {} //abstract class

void ShowAbsyn::visitSExp(SExp* p)
{
  bufAppend('(');
  bufAppend("SExp");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSScope(SScope* p)
{
  bufAppend('(');
  bufAppend("SScope");
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSRet(SRet* p)
{
  bufAppend('(');
  bufAppend("SRet");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSIf(SIf* p)
{
  bufAppend('(');
  bufAppend("SIf");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSIfElse(SIfElse* p)
{
  bufAppend('(');
  bufAppend("SIfElse");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->liststatement_1->accept(this);
  bufAppend(' ');
  p->liststatement_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSLoop(SLoop* p)
{
  bufAppend('(');
  bufAppend("SLoop");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSWhile(SWhile* p)
{
  bufAppend('(');
  bufAppend("SWhile");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSUntil(SUntil* p)
{
  bufAppend('(');
  bufAppend("SUntil");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSFor(SFor* p)
{
  bufAppend('(');
  bufAppend("SFor");
  bufAppend(' ');
  p->listexpression_1->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  p->listexpression_2->accept(this);
  bufAppend(' ');
  bufAppend('[');
  if (p->liststatement_)  p->liststatement_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitSBreak(SBreak* p)
{
  bufAppend("SBreak");
}
void ShowAbsyn::visitSContinue(SContinue* p)
{
  bufAppend("SContinue");
}
void ShowAbsyn::visitExpression(Expression* p) {} //abstract class

void ShowAbsyn::visitECDbl(ECDbl* p)
{
  bufAppend('(');
  bufAppend("ECDbl");
  bufAppend(' ');
  visitDouble(p->double_);
  bufAppend(')');
}
void ShowAbsyn::visitECInt(ECInt* p)
{
  bufAppend('(');
  bufAppend("ECInt");
  bufAppend(' ');
  visitInteger(p->integer_);
  bufAppend(')');
}
void ShowAbsyn::visitEVar(EVar* p)
{
  bufAppend('(');
  bufAppend("EVar");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitEPi(EPi* p)
{
  bufAppend("EPi");
}
void ShowAbsyn::visitESimpleCall(ESimpleCall* p)
{
  bufAppend('(');
  bufAppend("ESimpleCall");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitECall(ECall* p)
{
  bufAppend('(');
  bufAppend("ECall");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->listexpression_)  p->listexpression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEPostInc(EPostInc* p)
{
  bufAppend('(');
  bufAppend("EPostInc");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEPostDec(EPostDec* p)
{
  bufAppend('(');
  bufAppend("EPostDec");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEAbs(EAbs* p)
{
  bufAppend('(');
  bufAppend("EAbs");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEPow(EPow* p)
{
  bufAppend('(');
  bufAppend("EPow");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitESqrt(ESqrt* p)
{
  bufAppend('(');
  bufAppend("ESqrt");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEExp(EExp* p)
{
  bufAppend('(');
  bufAppend("EExp");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitELog(ELog* p)
{
  bufAppend('(');
  bufAppend("ELog");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitELogD(ELogD* p)
{
  bufAppend('(');
  bufAppend("ELogD");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitESin(ESin* p)
{
  bufAppend('(');
  bufAppend("ESin");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitECos(ECos* p)
{
  bufAppend('(');
  bufAppend("ECos");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitETan(ETan* p)
{
  bufAppend('(');
  bufAppend("ETan");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEAtan(EAtan* p)
{
  bufAppend('(');
  bufAppend("EAtan");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEAtanT(EAtanT* p)
{
  bufAppend('(');
  bufAppend("EAtanT");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEAsin(EAsin* p)
{
  bufAppend('(');
  bufAppend("EAsin");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitEAcos(EAcos* p)
{
  bufAppend('(');
  bufAppend("EAcos");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(' ');
  bufAppend(')');
}
void ShowAbsyn::visitELnot(ELnot* p)
{
  bufAppend('(');
  bufAppend("ELnot");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEPreInc(EPreInc* p)
{
  bufAppend('(');
  bufAppend("EPreInc");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitEPreDec(EPreDec* p)
{
  bufAppend('(');
  bufAppend("EPreDec");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(')');
}
void ShowAbsyn::visitENeg(ENeg* p)
{
  bufAppend('(');
  bufAppend("ENeg");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEBnot(EBnot* p)
{
  bufAppend('(');
  bufAppend("EBnot");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEPos(EPos* p)
{
  bufAppend('(');
  bufAppend("EPos");
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEMul(EMul* p)
{
  bufAppend('(');
  bufAppend("EMul");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEDiv(EDiv* p)
{
  bufAppend('(');
  bufAppend("EDiv");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEMod(EMod* p)
{
  bufAppend('(');
  bufAppend("EMod");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAdd(EAdd* p)
{
  bufAppend('(');
  bufAppend("EAdd");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitESub(ESub* p)
{
  bufAppend('(');
  bufAppend("ESub");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELSh(ELSh* p)
{
  bufAppend('(');
  bufAppend("ELSh");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitERSh(ERSh* p)
{
  bufAppend('(');
  bufAppend("ERSh");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELT(ELT* p)
{
  bufAppend('(');
  bufAppend("ELT");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGT(EGT* p)
{
  bufAppend('(');
  bufAppend("EGT");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELE(ELE* p)
{
  bufAppend('(');
  bufAppend("ELE");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEGE(EGE* p)
{
  bufAppend('(');
  bufAppend("EGE");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEE(EE* p)
{
  bufAppend('(');
  bufAppend("EE");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitENE(ENE* p)
{
  bufAppend('(');
  bufAppend("ENE");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEBand(EBand* p)
{
  bufAppend('(');
  bufAppend("EBand");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEBor(EBor* p)
{
  bufAppend('(');
  bufAppend("EBor");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEBxor(EBxor* p)
{
  bufAppend('(');
  bufAppend("EBxor");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELand(ELand* p)
{
  bufAppend('(');
  bufAppend("ELand");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELor(ELor* p)
{
  bufAppend('(');
  bufAppend("ELor");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitELxor(ELxor* p)
{
  bufAppend('(');
  bufAppend("ELxor");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitECon(ECon* p)
{
  bufAppend('(');
  bufAppend("ECon");
  bufAppend(' ');
  p->expression_1->accept(this);
  bufAppend(' ');
  p->expression_2->accept(this);
  bufAppend(' ');
  p->expression_3->accept(this);
  bufAppend(')');
}
void ShowAbsyn::visitEAss(EAss* p)
{
  bufAppend('(');
  bufAppend("EAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEAddAss(EAddAss* p)
{
  bufAppend('(');
  bufAppend("EAddAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitESubAss(ESubAss* p)
{
  bufAppend('(');
  bufAppend("ESubAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEMulAss(EMulAss* p)
{
  bufAppend('(');
  bufAppend("EMulAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEDivAss(EDivAss* p)
{
  bufAppend('(');
  bufAppend("EDivAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEModAss(EModAss* p)
{
  bufAppend('(');
  bufAppend("EModAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEAndAss(EAndAss* p)
{
  bufAppend('(');
  bufAppend("EAndAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEOrAss(EOrAss* p)
{
  bufAppend('(');
  bufAppend("EOrAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitEXorAss(EXorAss* p)
{
  bufAppend('(');
  bufAppend("EXorAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitELShAss(ELShAss* p)
{
  bufAppend('(');
  bufAppend("ELShAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitERShAss(ERShAss* p)
{
  bufAppend('(');
  bufAppend("ERShAss");
  bufAppend(' ');
  visitIdent(p->ident_);
  bufAppend(' ');
  bufAppend('[');
  if (p->expression_)  p->expression_->accept(this);
  bufAppend(']');
  bufAppend(')');
}
void ShowAbsyn::visitListExpression(ListExpression *listexpression)
{
  while(listexpression!= 0)
  {
    if (listexpression->listexpression_)
    {
      listexpression->expression_->accept(this);
      bufAppend(", ");
      listexpression = listexpression->listexpression_;
    }
    else
    {
      listexpression->expression_->accept(this);
      listexpression = 0;
    }
  }
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

