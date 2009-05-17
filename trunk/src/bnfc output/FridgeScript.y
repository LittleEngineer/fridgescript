/* This Bison file was machine-generated by BNFC */%glr-parser
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "Absyn.H"
int yyparse(void);
int yylex(void);
int yy_mylinenumber;
int initialize_lexer(FILE * inp);
int yywrap(void)
{
  return 1;
}
void yyerror(const char *str)
{
  std::cout << "line " << yy_mylinenumber + 1 << std::endl ;
  fprintf(stderr,"error: %s\n",str);
}


Program* YY_RESULT_Program_ = 0;
Program* pProgram(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Program_;
  }
}

Block* YY_RESULT_Block_ = 0;
Block* pBlock(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Block_;
  }
}

Function* YY_RESULT_Function_ = 0;
Function* pFunction(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Function_;
  }
}

Parameter* YY_RESULT_Parameter_ = 0;
Parameter* pParameter(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Parameter_;
  }
}

ListBlock* YY_RESULT_ListBlock_ = 0;
ListBlock* pListBlock(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListBlock_;
  }
}

ListFunction* YY_RESULT_ListFunction_ = 0;
ListFunction* pListFunction(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListFunction_;
  }
}

ListStatement* YY_RESULT_ListStatement_ = 0;
ListStatement* pListStatement(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListStatement_;
  }
}

ListParameter* YY_RESULT_ListParameter_ = 0;
ListParameter* pListParameter(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListParameter_;
  }
}

Statement* YY_RESULT_Statement_ = 0;
Statement* pStatement(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Statement_;
  }
}

Expression* YY_RESULT_Expression_ = 0;
Expression* pExpression(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Expression_;
  }
}

ListExpression* YY_RESULT_ListExpression_ = 0;
ListExpression* pListExpression(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListExpression_;
  }
}


ListBlock* reverseListBlock(ListBlock *l)
{
  ListBlock *prev = 0;
  ListBlock *tmp = 0;
  while (l)
  {
    tmp = l->listblock_;
    l->listblock_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListFunction* reverseListFunction(ListFunction *l)
{
  ListFunction *prev = 0;
  ListFunction *tmp = 0;
  while (l)
  {
    tmp = l->listfunction_;
    l->listfunction_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListStatement* reverseListStatement(ListStatement *l)
{
  ListStatement *prev = 0;
  ListStatement *tmp = 0;
  while (l)
  {
    tmp = l->liststatement_;
    l->liststatement_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListParameter* reverseListParameter(ListParameter *l)
{
  ListParameter *prev = 0;
  ListParameter *tmp = 0;
  while (l)
  {
    tmp = l->listparameter_;
    l->listparameter_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}
ListExpression* reverseListExpression(ListExpression *l)
{
  ListExpression *prev = 0;
  ListExpression *tmp = 0;
  while (l)
  {
    tmp = l->listexpression_;
    l->listexpression_ = prev;
    prev = l;
    l = tmp;
  }
  return prev;
}

%}

%union
{
  int int_;
  char char_;
  double double_;
  char* string_;
  Program* program_;
  Block* block_;
  Function* function_;
  Parameter* parameter_;
  ListBlock* listblock_;
  ListFunction* listfunction_;
  ListStatement* liststatement_;
  ListParameter* listparameter_;
  Statement* statement_;
  Expression* expression_;
  ListExpression* listexpression_;

}

%token _ERROR_
%token _SYMB_0    //   (
%token _SYMB_1    //   )
%token _SYMB_2    //   {
%token _SYMB_3    //   }
%token _SYMB_4    //   ,
%token _SYMB_5    //   ;
%token _SYMB_6    //   ++
%token _SYMB_7    //   --
%token _SYMB_8    //   !
%token _SYMB_9    //   -
%token _SYMB_10    //   ~
%token _SYMB_11    //   +
%token _SYMB_12    //   *
%token _SYMB_13    //   /
%token _SYMB_14    //   %
%token _SYMB_15    //   <<
%token _SYMB_16    //   >>
%token _SYMB_17    //   <
%token _SYMB_18    //   >
%token _SYMB_19    //   <=
%token _SYMB_20    //   >=
%token _SYMB_21    //   ==
%token _SYMB_22    //   !=
%token _SYMB_23    //   &
%token _SYMB_24    //   |
%token _SYMB_25    //   ^
%token _SYMB_26    //   &&
%token _SYMB_27    //   ||
%token _SYMB_28    //   ^^
%token _SYMB_29    //   ?
%token _SYMB_30    //   :
%token _SYMB_31    //   =
%token _SYMB_32    //   +=
%token _SYMB_33    //   -=
%token _SYMB_34    //   *=
%token _SYMB_35    //   /=
%token _SYMB_36    //   %=
%token _SYMB_37    //   &=
%token _SYMB_38    //   |=
%token _SYMB_39    //   ^=
%token _SYMB_40    //   <<=
%token _SYMB_41    //   >>=
%token _SYMB_42    //   acos
%token _SYMB_43    //   asin
%token _SYMB_44    //   atan
%token _SYMB_45    //   atan2
%token _SYMB_46    //   break
%token _SYMB_47    //   continue
%token _SYMB_48    //   cos
%token _SYMB_49    //   else
%token _SYMB_50    //   exp
%token _SYMB_51    //   for
%token _SYMB_52    //   if
%token _SYMB_53    //   log
%token _SYMB_54    //   log10
%token _SYMB_55    //   pi
%token _SYMB_56    //   pow
%token _SYMB_57    //   return
%token _SYMB_58    //   sin
%token _SYMB_59    //   sqrt
%token _SYMB_60    //   tan
%token _SYMB_61    //   until
%token _SYMB_62    //   while

%type <program_> Program
%type <block_> Block
%type <function_> Function
%type <parameter_> Parameter
%type <listblock_> ListBlock
%type <listfunction_> ListFunction
%type <liststatement_> ListStatement
%type <listparameter_> ListParameter
%type <statement_> Statement
%type <expression_> Expression12
%type <expression_> Expression11
%type <expression_> Expression10
%type <expression_> Expression9
%type <expression_> Expression8
%type <expression_> Expression7
%type <expression_> Expression6
%type <expression_> Expression5
%type <expression_> Expression4
%type <expression_> Expression3
%type <expression_> Expression2
%type <expression_> Expression1
%type <expression_> Expression
%type <listexpression_> ListExpression

%token<int_> _INTEGER_
%token<double_> _DOUBLE_
%token<string_> _IDENT_

%%
Program : ListBlock { $$ = new Main(reverseListBlock($1)); YY_RESULT_Program_= $$; } 
;
Block : ListFunction { $$ = new BFunc($1);  } 
  | ListStatement { $$ = new BStmt($1);  }
;
Function : _IDENT_ _SYMB_0 ListParameter _SYMB_1 _SYMB_2 ListStatement _SYMB_3 { $$ = new DTFunc($1, $3, $6);  } 
;
Parameter : _IDENT_ { $$ = new DTParam($1);  } 
;
ListBlock : /* empty */ { $$ = 0;  } 
  | ListBlock Block { $$ = new ListBlock($2, $1);  }
;
ListFunction : Function { $$ = new ListFunction($1);  } 
  | Function ListFunction { $$ = new ListFunction($1, $2);  }
;
ListStatement : Statement { $$ = new ListStatement($1);  } 
  | Statement ListStatement { $$ = new ListStatement($1, $2);  }
;
ListParameter : Parameter { $$ = new ListParameter($1);  } 
  | Parameter _SYMB_4 ListParameter { $$ = new ListParameter($1, $3);  }
;
Statement : Expression _SYMB_5 { $$ = new SExp($1);  } 
  | _SYMB_2 ListStatement _SYMB_3 { $$ = new SScope($2);  }
  | _SYMB_57 Expression _SYMB_5 { $$ = new SRet($2);  }
  | _SYMB_52 _SYMB_0 Expression _SYMB_1 Statement { $$ = new SIf($3, $5);  }
  | _SYMB_52 _SYMB_0 Expression _SYMB_1 Statement _SYMB_49 Statement { $$ = new SIfElse($3, $5, $7);  }
  | _SYMB_62 _SYMB_0 Expression _SYMB_1 Statement { $$ = new SWhile($3, $5);  }
  | _SYMB_61 _SYMB_0 Expression _SYMB_1 Statement { $$ = new SUntil($3, $5);  }
  | _SYMB_51 _SYMB_0 Expression _SYMB_5 Expression _SYMB_5 Expression _SYMB_1 Statement { $$ = new SFor($3, $5, $7, $9);  }
  | _SYMB_46 _SYMB_5 { $$ = new SBreak();  }
  | _SYMB_47 _SYMB_5 { $$ = new SContinue();  }
;
Expression12 : _DOUBLE_ { $$ = new ECDbl($1);  } 
  | _INTEGER_ { $$ = new ECInt($1);  }
  | _IDENT_ { $$ = new EVar($1);  }
  | _SYMB_55 { $$ = new EPi();  }
  | _SYMB_0 Expression _SYMB_1 { $$ = $2;  }
;
Expression11 : _IDENT_ _SYMB_0 ListExpression _SYMB_1 { $$ = new ECall($1, $3);  } 
  | _IDENT_ _SYMB_6 { $$ = new EPostInc($1);  }
  | _IDENT_ _SYMB_7 { $$ = new EPostDec($1);  }
  | _SYMB_56 _SYMB_0 Expression _SYMB_4 Expression _SYMB_1 { $$ = new EPow($3, $5);  }
  | _SYMB_59 _SYMB_0 Expression _SYMB_1 { $$ = new ESqrt($3);  }
  | _SYMB_50 _SYMB_0 Expression _SYMB_1 { $$ = new EExp($3);  }
  | _SYMB_53 _SYMB_0 Expression _SYMB_1 { $$ = new ELog($3);  }
  | _SYMB_54 _SYMB_0 Expression _SYMB_1 { $$ = new ELogD($3);  }
  | _SYMB_58 _SYMB_0 Expression _SYMB_1 { $$ = new ESin($3);  }
  | _SYMB_48 _SYMB_0 Expression _SYMB_1 { $$ = new ECos($3);  }
  | _SYMB_60 _SYMB_0 Expression _SYMB_1 { $$ = new ETan($3);  }
  | _SYMB_44 _SYMB_0 Expression _SYMB_1 { $$ = new EAtan($3);  }
  | _SYMB_45 _SYMB_0 Expression _SYMB_4 Expression _SYMB_1 { $$ = new EAtanT($3, $5);  }
  | _SYMB_43 _SYMB_0 Expression _SYMB_1 { $$ = new EAsin($3);  }
  | _SYMB_42 _SYMB_0 Expression _SYMB_1 { $$ = new EAcos($3);  }
  | Expression12 { $$ = $1;  }
;
Expression10 : _SYMB_8 Expression { $$ = new ELnot($2);  } 
  | _SYMB_6 _IDENT_ { $$ = new EPreInc($2);  }
  | _SYMB_7 _IDENT_ { $$ = new EPreDec($2);  }
  | _SYMB_9 Expression { $$ = new ENeg($2);  }
  | _SYMB_10 Expression { $$ = new EBnot($2);  }
  | _SYMB_11 Expression { $$ = new EPos($2);  }
  | Expression11 { $$ = $1;  }
;
Expression9 : Expression _SYMB_12 Expression { $$ = new EMul($1, $3);  } 
  | Expression _SYMB_13 Expression { $$ = new EDiv($1, $3);  }
  | Expression _SYMB_14 Expression { $$ = new EMod($1, $3);  }
  | Expression10 { $$ = $1;  }
;
Expression8 : Expression _SYMB_11 Expression { $$ = new EAdd($1, $3);  } 
  | Expression _SYMB_9 Expression { $$ = new ESub($1, $3);  }
  | Expression9 { $$ = $1;  }
;
Expression7 : Expression _SYMB_15 Expression { $$ = new ELSh($1, $3);  } 
  | Expression _SYMB_16 Expression { $$ = new ERSh($1, $3);  }
  | Expression8 { $$ = $1;  }
;
Expression6 : Expression _SYMB_17 Expression { $$ = new ELT($1, $3);  } 
  | Expression _SYMB_18 Expression { $$ = new EGT($1, $3);  }
  | Expression _SYMB_19 Expression { $$ = new ELE($1, $3);  }
  | Expression _SYMB_20 Expression { $$ = new EGE($1, $3);  }
  | Expression7 { $$ = $1;  }
;
Expression5 : Expression _SYMB_21 Expression { $$ = new EE($1, $3);  } 
  | Expression _SYMB_22 Expression { $$ = new ENE($1, $3);  }
  | Expression6 { $$ = $1;  }
;
Expression4 : Expression _SYMB_23 Expression { $$ = new EBand($1, $3);  } 
  | Expression _SYMB_24 Expression { $$ = new EBor($1, $3);  }
  | Expression _SYMB_25 Expression { $$ = new EBxor($1, $3);  }
  | Expression5 { $$ = $1;  }
;
Expression3 : Expression _SYMB_26 Expression { $$ = new ELand($1, $3);  } 
  | Expression _SYMB_27 Expression { $$ = new ELor($1, $3);  }
  | Expression _SYMB_28 Expression { $$ = new ELxor($1, $3);  }
  | Expression4 { $$ = $1;  }
;
Expression2 : Expression _SYMB_29 Expression _SYMB_30 Expression { $$ = new ECon($1, $3, $5);  } 
  | Expression3 { $$ = $1;  }
;
Expression1 : _IDENT_ _SYMB_31 Expression { $$ = new EAss($1, $3);  } 
  | _IDENT_ _SYMB_32 Expression { $$ = new EAddAss($1, $3);  }
  | _IDENT_ _SYMB_33 Expression { $$ = new ESubAss($1, $3);  }
  | _IDENT_ _SYMB_34 Expression { $$ = new EMulAss($1, $3);  }
  | _IDENT_ _SYMB_35 Expression { $$ = new EDivAss($1, $3);  }
  | _IDENT_ _SYMB_36 Expression { $$ = new EModAss($1, $3);  }
  | _IDENT_ _SYMB_37 Expression { $$ = new EAndAss($1, $3);  }
  | _IDENT_ _SYMB_38 Expression { $$ = new EOrAss($1, $3);  }
  | _IDENT_ _SYMB_39 Expression { $$ = new EXorAss($1, $3);  }
  | _IDENT_ _SYMB_40 Expression { $$ = new ELShAss($1, $3);  }
  | _IDENT_ _SYMB_41 Expression { $$ = new ERShAss($1, $3);  }
  | Expression2 { $$ = $1;  }
;
Expression : Expression1 { $$ = $1;  } 
;
ListExpression : /* empty */ { $$ = 0;  } 
  | Expression { $$ = new ListExpression($1);  }
  | Expression _SYMB_4 ListExpression { $$ = new ListExpression($1, $3);  }
;

