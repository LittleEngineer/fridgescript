/*** BNFC-Generated Visitor Design Pattern Skeleton. ***/
/* This implements the common visitor design pattern.
   Note that this method uses Visitor-traversal of lists, so
   List->accept() does NOT traverse the list. This allows different
   algorithms to use context information differently. */

#include "Skeleton.H"

void Skeleton::visitProgram(Program* program) {} //abstract class

void Skeleton::visitMain(Main* main)
{
  /* Code For Main Goes Here */

  if (main->listblock_) {main->listblock_->accept(this);}
}

void Skeleton::visitBlock(Block* block) {} //abstract class

void Skeleton::visitBFunc(BFunc* bfunc)
{
  /* Code For BFunc Goes Here */

  if (bfunc->listfunction_) {bfunc->listfunction_->accept(this);}
}

void Skeleton::visitBStmt(BStmt* bstmt)
{
  /* Code For BStmt Goes Here */

  if (bstmt->liststatement_) {bstmt->liststatement_->accept(this);}
}

void Skeleton::visitFunction(Function* function) {} //abstract class

void Skeleton::visitDTFunc(DTFunc* dtfunc)
{
  /* Code For DTFunc Goes Here */

  visitIdent(dtfunc->ident_);
  if (dtfunc->listparameter_) {dtfunc->listparameter_->accept(this);}
  if (dtfunc->listblock_) {dtfunc->listblock_->accept(this);}
}

void Skeleton::visitParameter(Parameter* parameter) {} //abstract class

void Skeleton::visitDTParam(DTParam* dtparam)
{
  /* Code For DTParam Goes Here */

  visitIdent(dtparam->ident_);
}

void Skeleton::visitListBlock(ListBlock* listblock)
{
  while(listblock!= 0)
  {
    /* Code For ListBlock Goes Here */
    listblock->block_->accept(this);
    listblock = listblock->listblock_;
  }
}

void Skeleton::visitListFunction(ListFunction* listfunction)
{
  while(listfunction!= 0)
  {
    /* Code For ListFunction Goes Here */
    listfunction->function_->accept(this);
    listfunction = listfunction->listfunction_;
  }
}

void Skeleton::visitListStatement(ListStatement* liststatement)
{
  while(liststatement!= 0)
  {
    /* Code For ListStatement Goes Here */
    liststatement->statement_->accept(this);
    liststatement = liststatement->liststatement_;
  }
}

void Skeleton::visitListParameter(ListParameter* listparameter)
{
  while(listparameter!= 0)
  {
    /* Code For ListParameter Goes Here */
    listparameter->parameter_->accept(this);
    listparameter = listparameter->listparameter_;
  }
}

void Skeleton::visitStatement(Statement* statement) {} //abstract class

void Skeleton::visitSExp(SExp* sexp)
{
  /* Code For SExp Goes Here */

  sexp->expression_->accept(this);
}

void Skeleton::visitSScope(SScope* sscope)
{
  /* Code For SScope Goes Here */

  if (sscope->liststatement_) {sscope->liststatement_->accept(this);}
}

void Skeleton::visitSRet(SRet* sret)
{
  /* Code For SRet Goes Here */

  sret->expression_->accept(this);
}

void Skeleton::visitSIf(SIf* sif)
{
  /* Code For SIf Goes Here */

  sif->expression_->accept(this);
  if (sif->liststatement_) {sif->liststatement_->accept(this);}
}

void Skeleton::visitSIfElse(SIfElse* sifelse)
{
  /* Code For SIfElse Goes Here */

  sifelse->expression_->accept(this);
  if (sifelse->liststatement_1) {sifelse->liststatement_1->accept(this);}
  if (sifelse->liststatement_2) {sifelse->liststatement_2->accept(this);}
}

void Skeleton::visitSWhile(SWhile* swhile)
{
  /* Code For SWhile Goes Here */

  swhile->expression_->accept(this);
  if (swhile->liststatement_) {swhile->liststatement_->accept(this);}
}

void Skeleton::visitSUntil(SUntil* suntil)
{
  /* Code For SUntil Goes Here */

  suntil->expression_->accept(this);
  if (suntil->liststatement_) {suntil->liststatement_->accept(this);}
}

void Skeleton::visitSFor(SFor* sfor)
{
  /* Code For SFor Goes Here */

  if (sfor->listexpression_1) {sfor->listexpression_1->accept(this);}
  sfor->expression_->accept(this);
  if (sfor->listexpression_2) {sfor->listexpression_2->accept(this);}
  if (sfor->liststatement_) {sfor->liststatement_->accept(this);}
}

void Skeleton::visitSBreak(SBreak* sbreak)
{
  /* Code For SBreak Goes Here */

}

void Skeleton::visitSContinue(SContinue* scontinue)
{
  /* Code For SContinue Goes Here */

}

void Skeleton::visitExpression(Expression* expression) {} //abstract class

void Skeleton::visitECDbl(ECDbl* ecdbl)
{
  /* Code For ECDbl Goes Here */

  visitDouble(ecdbl->double_);
}

void Skeleton::visitECInt(ECInt* ecint)
{
  /* Code For ECInt Goes Here */

  visitInteger(ecint->integer_);
}

void Skeleton::visitEVar(EVar* evar)
{
  /* Code For EVar Goes Here */

  visitIdent(evar->ident_);
}

void Skeleton::visitEPi(EPi* epi)
{
  /* Code For EPi Goes Here */

}

void Skeleton::visitESimpleCall(ESimpleCall* esimplecall)
{
  /* Code For ESimpleCall Goes Here */

  visitIdent(esimplecall->ident_);
}

void Skeleton::visitECall(ECall* ecall)
{
  /* Code For ECall Goes Here */

  visitIdent(ecall->ident_);
  if (ecall->listexpression_) {ecall->listexpression_->accept(this);}
}

void Skeleton::visitEPostInc(EPostInc* epostinc)
{
  /* Code For EPostInc Goes Here */

  visitIdent(epostinc->ident_);
}

void Skeleton::visitEPostDec(EPostDec* epostdec)
{
  /* Code For EPostDec Goes Here */

  visitIdent(epostdec->ident_);
}

void Skeleton::visitEAbs(EAbs* eabs)
{
  /* Code For EAbs Goes Here */

  eabs->expression_->accept(this);
}

void Skeleton::visitEPow(EPow* epow)
{
  /* Code For EPow Goes Here */

  epow->expression_1->accept(this);
  epow->expression_2->accept(this);
}

void Skeleton::visitESqrt(ESqrt* esqrt)
{
  /* Code For ESqrt Goes Here */

  esqrt->expression_->accept(this);
}

void Skeleton::visitEExp(EExp* eexp)
{
  /* Code For EExp Goes Here */

  eexp->expression_->accept(this);
}

void Skeleton::visitELog(ELog* elog)
{
  /* Code For ELog Goes Here */

  elog->expression_->accept(this);
}

void Skeleton::visitELogD(ELogD* elogd)
{
  /* Code For ELogD Goes Here */

  elogd->expression_->accept(this);
}

void Skeleton::visitESin(ESin* esin)
{
  /* Code For ESin Goes Here */

  esin->expression_->accept(this);
}

void Skeleton::visitECos(ECos* ecos)
{
  /* Code For ECos Goes Here */

  ecos->expression_->accept(this);
}

void Skeleton::visitETan(ETan* etan)
{
  /* Code For ETan Goes Here */

  etan->expression_->accept(this);
}

void Skeleton::visitEAtan(EAtan* eatan)
{
  /* Code For EAtan Goes Here */

  eatan->expression_->accept(this);
}

void Skeleton::visitEAtanT(EAtanT* eatant)
{
  /* Code For EAtanT Goes Here */

  eatant->expression_1->accept(this);
  eatant->expression_2->accept(this);
}

void Skeleton::visitEAsin(EAsin* easin)
{
  /* Code For EAsin Goes Here */

  easin->expression_->accept(this);
}

void Skeleton::visitEAcos(EAcos* eacos)
{
  /* Code For EAcos Goes Here */

  eacos->expression_->accept(this);
}

void Skeleton::visitELnot(ELnot* elnot)
{
  /* Code For ELnot Goes Here */

  elnot->expression_->accept(this);
}

void Skeleton::visitEPreInc(EPreInc* epreinc)
{
  /* Code For EPreInc Goes Here */

  visitIdent(epreinc->ident_);
}

void Skeleton::visitEPreDec(EPreDec* epredec)
{
  /* Code For EPreDec Goes Here */

  visitIdent(epredec->ident_);
}

void Skeleton::visitENeg(ENeg* eneg)
{
  /* Code For ENeg Goes Here */

  eneg->expression_->accept(this);
}

void Skeleton::visitEBnot(EBnot* ebnot)
{
  /* Code For EBnot Goes Here */

  ebnot->expression_->accept(this);
}

void Skeleton::visitEPos(EPos* epos)
{
  /* Code For EPos Goes Here */

  epos->expression_->accept(this);
}

void Skeleton::visitEMul(EMul* emul)
{
  /* Code For EMul Goes Here */

  emul->expression_1->accept(this);
  emul->expression_2->accept(this);
}

void Skeleton::visitEDiv(EDiv* ediv)
{
  /* Code For EDiv Goes Here */

  ediv->expression_1->accept(this);
  ediv->expression_2->accept(this);
}

void Skeleton::visitEMod(EMod* emod)
{
  /* Code For EMod Goes Here */

  emod->expression_1->accept(this);
  emod->expression_2->accept(this);
}

void Skeleton::visitEAdd(EAdd* eadd)
{
  /* Code For EAdd Goes Here */

  eadd->expression_1->accept(this);
  eadd->expression_2->accept(this);
}

void Skeleton::visitESub(ESub* esub)
{
  /* Code For ESub Goes Here */

  esub->expression_1->accept(this);
  esub->expression_2->accept(this);
}

void Skeleton::visitELSh(ELSh* elsh)
{
  /* Code For ELSh Goes Here */

  elsh->expression_1->accept(this);
  elsh->expression_2->accept(this);
}

void Skeleton::visitERSh(ERSh* ersh)
{
  /* Code For ERSh Goes Here */

  ersh->expression_1->accept(this);
  ersh->expression_2->accept(this);
}

void Skeleton::visitELT(ELT* elt)
{
  /* Code For ELT Goes Here */

  elt->expression_1->accept(this);
  elt->expression_2->accept(this);
}

void Skeleton::visitEGT(EGT* egt)
{
  /* Code For EGT Goes Here */

  egt->expression_1->accept(this);
  egt->expression_2->accept(this);
}

void Skeleton::visitELE(ELE* ele)
{
  /* Code For ELE Goes Here */

  ele->expression_1->accept(this);
  ele->expression_2->accept(this);
}

void Skeleton::visitEGE(EGE* ege)
{
  /* Code For EGE Goes Here */

  ege->expression_1->accept(this);
  ege->expression_2->accept(this);
}

void Skeleton::visitEE(EE* ee)
{
  /* Code For EE Goes Here */

  ee->expression_1->accept(this);
  ee->expression_2->accept(this);
}

void Skeleton::visitENE(ENE* ene)
{
  /* Code For ENE Goes Here */

  ene->expression_1->accept(this);
  ene->expression_2->accept(this);
}

void Skeleton::visitEBand(EBand* eband)
{
  /* Code For EBand Goes Here */

  eband->expression_1->accept(this);
  eband->expression_2->accept(this);
}

void Skeleton::visitEBor(EBor* ebor)
{
  /* Code For EBor Goes Here */

  ebor->expression_1->accept(this);
  ebor->expression_2->accept(this);
}

void Skeleton::visitEBxor(EBxor* ebxor)
{
  /* Code For EBxor Goes Here */

  ebxor->expression_1->accept(this);
  ebxor->expression_2->accept(this);
}

void Skeleton::visitELand(ELand* eland)
{
  /* Code For ELand Goes Here */

  eland->expression_1->accept(this);
  eland->expression_2->accept(this);
}

void Skeleton::visitELor(ELor* elor)
{
  /* Code For ELor Goes Here */

  elor->expression_1->accept(this);
  elor->expression_2->accept(this);
}

void Skeleton::visitELxor(ELxor* elxor)
{
  /* Code For ELxor Goes Here */

  elxor->expression_1->accept(this);
  elxor->expression_2->accept(this);
}

void Skeleton::visitECon(ECon* econ)
{
  /* Code For ECon Goes Here */

  econ->expression_1->accept(this);
  econ->expression_2->accept(this);
  econ->expression_3->accept(this);
}

void Skeleton::visitEAss(EAss* eass)
{
  /* Code For EAss Goes Here */

  visitIdent(eass->ident_);
  eass->expression_->accept(this);
}

void Skeleton::visitEAddAss(EAddAss* eaddass)
{
  /* Code For EAddAss Goes Here */

  visitIdent(eaddass->ident_);
  eaddass->expression_->accept(this);
}

void Skeleton::visitESubAss(ESubAss* esubass)
{
  /* Code For ESubAss Goes Here */

  visitIdent(esubass->ident_);
  esubass->expression_->accept(this);
}

void Skeleton::visitEMulAss(EMulAss* emulass)
{
  /* Code For EMulAss Goes Here */

  visitIdent(emulass->ident_);
  emulass->expression_->accept(this);
}

void Skeleton::visitEDivAss(EDivAss* edivass)
{
  /* Code For EDivAss Goes Here */

  visitIdent(edivass->ident_);
  edivass->expression_->accept(this);
}

void Skeleton::visitEModAss(EModAss* emodass)
{
  /* Code For EModAss Goes Here */

  visitIdent(emodass->ident_);
  emodass->expression_->accept(this);
}

void Skeleton::visitEAndAss(EAndAss* eandass)
{
  /* Code For EAndAss Goes Here */

  visitIdent(eandass->ident_);
  eandass->expression_->accept(this);
}

void Skeleton::visitEOrAss(EOrAss* eorass)
{
  /* Code For EOrAss Goes Here */

  visitIdent(eorass->ident_);
  eorass->expression_->accept(this);
}

void Skeleton::visitEXorAss(EXorAss* exorass)
{
  /* Code For EXorAss Goes Here */

  visitIdent(exorass->ident_);
  exorass->expression_->accept(this);
}

void Skeleton::visitELShAss(ELShAss* elshass)
{
  /* Code For ELShAss Goes Here */

  visitIdent(elshass->ident_);
  elshass->expression_->accept(this);
}

void Skeleton::visitERShAss(ERShAss* ershass)
{
  /* Code For ERShAss Goes Here */

  visitIdent(ershass->ident_);
  ershass->expression_->accept(this);
}

void Skeleton::visitListExpression(ListExpression* listexpression)
{
  while(listexpression!= 0)
  {
    /* Code For ListExpression Goes Here */
    listexpression->expression_->accept(this);
    listexpression = listexpression->listexpression_;
  }
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

