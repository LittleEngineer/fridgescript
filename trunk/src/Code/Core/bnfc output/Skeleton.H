#ifndef SKELETON_HEADER
#define SKELETON_HEADER
/* You might want to change the above name. */

#include "Absyn.H"

class Skeleton : public Visitor
{
 public:

  void visitProgram(Program* program); /* abstract class */
  void visitMain(Main* main);
  void visitBlock(Block* block); /* abstract class */
  void visitBFunc(BFunc* bfunc);
  void visitBStmt(BStmt* bstmt);
  void visitFunction(Function* function); /* abstract class */
  void visitDTFunc(DTFunc* dtfunc);
  void visitParameter(Parameter* parameter); /* abstract class */
  void visitDTParam(DTParam* dtparam);
  void visitListBlock(ListBlock* listblock);  void visitListFunction(ListFunction* listfunction);  void visitListStatement(ListStatement* liststatement);  void visitListParameter(ListParameter* listparameter);  void visitStatement(Statement* statement); /* abstract class */
  void visitSExp(SExp* sexp);
  void visitSScope(SScope* sscope);
  void visitSRet(SRet* sret);
  void visitSIf(SIf* sif);
  void visitSIfElse(SIfElse* sifelse);
  void visitSWhile(SWhile* swhile);
  void visitSUntil(SUntil* suntil);
  void visitSFor(SFor* sfor);
  void visitSBreak(SBreak* sbreak);
  void visitSContinue(SContinue* scontinue);
  void visitExpression(Expression* expression); /* abstract class */
  void visitECDbl(ECDbl* ecdbl);
  void visitECInt(ECInt* ecint);
  void visitEVar(EVar* evar);
  void visitEPi(EPi* epi);
  void visitESimpleCall(ESimpleCall* esimplecall);
  void visitECall(ECall* ecall);
  void visitEPostInc(EPostInc* epostinc);
  void visitEPostDec(EPostDec* epostdec);
  void visitEAbs(EAbs* eabs);
  void visitEPow(EPow* epow);
  void visitESqrt(ESqrt* esqrt);
  void visitEExp(EExp* eexp);
  void visitELog(ELog* elog);
  void visitELogD(ELogD* elogd);
  void visitESin(ESin* esin);
  void visitECos(ECos* ecos);
  void visitETan(ETan* etan);
  void visitEAtan(EAtan* eatan);
  void visitEAtanT(EAtanT* eatant);
  void visitEAsin(EAsin* easin);
  void visitEAcos(EAcos* eacos);
  void visitELnot(ELnot* elnot);
  void visitEPreInc(EPreInc* epreinc);
  void visitEPreDec(EPreDec* epredec);
  void visitENeg(ENeg* eneg);
  void visitEBnot(EBnot* ebnot);
  void visitEPos(EPos* epos);
  void visitEMul(EMul* emul);
  void visitEDiv(EDiv* ediv);
  void visitEMod(EMod* emod);
  void visitEAdd(EAdd* eadd);
  void visitESub(ESub* esub);
  void visitELSh(ELSh* elsh);
  void visitERSh(ERSh* ersh);
  void visitELT(ELT* elt);
  void visitEGT(EGT* egt);
  void visitELE(ELE* ele);
  void visitEGE(EGE* ege);
  void visitEE(EE* ee);
  void visitENE(ENE* ene);
  void visitEBand(EBand* eband);
  void visitEBor(EBor* ebor);
  void visitEBxor(EBxor* ebxor);
  void visitELand(ELand* eland);
  void visitELor(ELor* elor);
  void visitELxor(ELxor* elxor);
  void visitECon(ECon* econ);
  void visitEAss(EAss* eass);
  void visitEAddAss(EAddAss* eaddass);
  void visitESubAss(ESubAss* esubass);
  void visitEMulAss(EMulAss* emulass);
  void visitEDivAss(EDivAss* edivass);
  void visitEModAss(EModAss* emodass);
  void visitEAndAss(EAndAss* eandass);
  void visitEOrAss(EOrAss* eorass);
  void visitEXorAss(EXorAss* exorass);
  void visitELShAss(ELShAss* elshass);
  void visitERShAss(ERShAss* ershass);
  void visitListExpression(ListExpression* listexpression);

  void visitIdent(String s);
  void visitInteger(Integer i);
  void visitDouble(Double d);
  void visitChar(Char c);
  void visitString(String s);
};

#endif

