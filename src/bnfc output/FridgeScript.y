/* This Bison file was machine-generated by BNFC */
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
%token _SYMB_6    //   loop while
%token _SYMB_7    //   loop until
%token _SYMB_8    //   loop for
%token _SYMB_9    //   ++
%token _SYMB_10    //   --
%token _SYMB_11    //   !
%token _SYMB_12    //   -
%token _SYMB_13    //   ~
%token _SYMB_14    //   +
%token _SYMB_15    //   *
%token _SYMB_16    //   /
%token _SYMB_17    //   %
%token _SYMB_18    //   <<
%token _SYMB_19    //   >>
%token _SYMB_20    //   <
%token _SYMB_21    //   >
%token _SYMB_22    //   <=
%token _SYMB_23    //   >=
%token _SYMB_24    //   ==
%token _SYMB_25    //   !=
%token _SYMB_26    //   &
%token _SYMB_27    //   |
%token _SYMB_28    //   ^
%token _SYMB_29    //   &&
%token _SYMB_30    //   ||
%token _SYMB_31    //   ^^
%token _SYMB_32    //   ?
%token _SYMB_33    //   :
%token _SYMB_34    //   =
%token _SYMB_35    //   +=
%token _SYMB_36    //   -=
%token _SYMB_37    //   *=
%token _SYMB_38    //   /=
%token _SYMB_39    //   %=
%token _SYMB_40    //   &=
%token _SYMB_41    //   |=
%token _SYMB_42    //   ^=
%token _SYMB_43    //   <<=
%token _SYMB_44    //   >>=
%token _SYMB_45    //   abs
%token _SYMB_46    //   acos
%token _SYMB_47    //   asin
%token _SYMB_48    //   atan
%token _SYMB_49    //   atan2
%token _SYMB_50    //   break
%token _SYMB_51    //   continue
%token _SYMB_52    //   cos
%token _SYMB_53    //   else
%token _SYMB_54    //   exp
%token _SYMB_55    //   if
%token _SYMB_56    //   log
%token _SYMB_57    //   log10
%token _SYMB_58    //   loop
%token _SYMB_59    //   pi
%token _SYMB_60    //   pow
%token _SYMB_61    //   return
%token _SYMB_62    //   sin
%token _SYMB_63    //   sqrt
%token _SYMB_64    //   tan

%type <program_> Program
%type <block_> Block
%type <function_> Function
%type <parameter_> Parameter
%type <listblock_> ListBlock
%type <listfunction_> ListFunction
%type <liststatement_> ListStatement
%type <listparameter_> ListParameter
%type <statement_> Statement
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
Function : _IDENT_ _SYMB_0 ListParameter _SYMB_1 _SYMB_2 ListBlock _SYMB_3 { $$ = new DTFunc($1, $3, reverseListBlock($6));  } 
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
  | _SYMB_61 Expression _SYMB_5 { $$ = new SRet($2);  }
  | _SYMB_55 _SYMB_0 Expression _SYMB_1 _SYMB_2 ListStatement _SYMB_3 { $$ = new SIf($3, $6);  }
  | _SYMB_55 _SYMB_0 Expression _SYMB_1 _SYMB_2 ListStatement _SYMB_3 _SYMB_53 _SYMB_2 ListStatement _SYMB_3 { $$ = new SIfElse($3, $6, $10);  }
  | _SYMB_58 _SYMB_0 Expression _SYMB_1 _SYMB_2 ListStatement _SYMB_3 { $$ = new SLoop($3, $6);  }
  | _SYMB_6 _SYMB_0 Expression _SYMB_1 _SYMB_2 ListStatement _SYMB_3 { $$ = new SWhile($3, $6);  }
  | _SYMB_7 _SYMB_0 Expression _SYMB_1 _SYMB_2 ListStatement _SYMB_3 { $$ = new SUntil($3, $6);  }
  | _SYMB_8 _SYMB_0 ListExpression _SYMB_5 Expression _SYMB_5 ListExpression _SYMB_1 _SYMB_2 ListStatement _SYMB_3 { $$ = new SFor($3, $5, $7, $10);  }
  | _SYMB_50 _SYMB_5 { $$ = new SBreak();  }
  | _SYMB_51 _SYMB_5 { $$ = new SContinue();  }
;
Expression11 : _DOUBLE_ { $$ = new ECDbl($1);  } 
  | _INTEGER_ { $$ = new ECInt($1);  }
  | _IDENT_ { $$ = new EVar($1);  }
  | _SYMB_59 { $$ = new EPi();  }
  | _SYMB_0 Expression _SYMB_1 { $$ = $2;  }
;
Expression10 : _IDENT_ _SYMB_0 _SYMB_1 { $$ = new ESimpleCall($1);  } 
  | _IDENT_ _SYMB_0 ListExpression _SYMB_1 { $$ = new ECall($1, $3);  }
  | _IDENT_ _SYMB_9 { $$ = new EPostInc($1);  }
  | _IDENT_ _SYMB_10 { $$ = new EPostDec($1);  }
  | _SYMB_45 _SYMB_0 Expression _SYMB_1 { $$ = new EAbs($3);  }
  | _SYMB_60 _SYMB_0 Expression _SYMB_4 Expression _SYMB_1 { $$ = new EPow($3, $5);  }
  | _SYMB_63 _SYMB_0 Expression _SYMB_1 { $$ = new ESqrt($3);  }
  | _SYMB_54 _SYMB_0 Expression _SYMB_1 { $$ = new EExp($3);  }
  | _SYMB_56 _SYMB_0 Expression _SYMB_1 { $$ = new ELog($3);  }
  | _SYMB_57 _SYMB_0 Expression _SYMB_1 { $$ = new ELogD($3);  }
  | _SYMB_62 _SYMB_0 Expression _SYMB_1 { $$ = new ESin($3);  }
  | _SYMB_52 _SYMB_0 Expression _SYMB_1 { $$ = new ECos($3);  }
  | _SYMB_64 _SYMB_0 Expression _SYMB_1 { $$ = new ETan($3);  }
  | _SYMB_48 _SYMB_0 Expression _SYMB_1 { $$ = new EAtan($3);  }
  | _SYMB_49 _SYMB_0 Expression _SYMB_4 Expression _SYMB_1 { $$ = new EAtanT($3, $5);  }
  | _SYMB_47 _SYMB_0 Expression _SYMB_1 { $$ = new EAsin($3);  }
  | _SYMB_46 _SYMB_0 Expression _SYMB_1 { $$ = new EAcos($3);  }
  | Expression11 { $$ = $1;  }
;
Expression9 : _SYMB_11 Expression10 { $$ = new ELnot($2);  } 
  | _SYMB_9 _IDENT_ { $$ = new EPreInc($2);  }
  | _SYMB_10 _IDENT_ { $$ = new EPreDec($2);  }
  | _SYMB_12 Expression10 { $$ = new ENeg($2);  }
  | _SYMB_13 Expression10 { $$ = new EBnot($2);  }
  | _SYMB_14 Expression10 { $$ = new EPos($2);  }
  | Expression10 { $$ = $1;  }
;
Expression8 : Expression8 _SYMB_15 Expression9 { $$ = new EMul($1, $3);  } 
  | Expression8 _SYMB_16 Expression9 { $$ = new EDiv($1, $3);  }
  | Expression8 _SYMB_17 Expression9 { $$ = new EMod($1, $3);  }
  | Expression9 { $$ = $1;  }
;
Expression7 : Expression7 _SYMB_14 Expression8 { $$ = new EAdd($1, $3);  } 
  | Expression7 _SYMB_12 Expression8 { $$ = new ESub($1, $3);  }
  | Expression8 { $$ = $1;  }
;
Expression6 : Expression6 _SYMB_18 Expression7 { $$ = new ELSh($1, $3);  } 
  | Expression6 _SYMB_19 Expression7 { $$ = new ERSh($1, $3);  }
  | Expression7 { $$ = $1;  }
;
Expression5 : Expression6 _SYMB_20 Expression6 { $$ = new ELT($1, $3);  } 
  | Expression6 _SYMB_21 Expression6 { $$ = new EGT($1, $3);  }
  | Expression6 _SYMB_22 Expression6 { $$ = new ELE($1, $3);  }
  | Expression6 _SYMB_23 Expression6 { $$ = new EGE($1, $3);  }
  | Expression6 { $$ = $1;  }
;
Expression4 : Expression5 _SYMB_24 Expression5 { $$ = new EE($1, $3);  } 
  | Expression5 _SYMB_25 Expression5 { $$ = new ENE($1, $3);  }
  | Expression5 { $$ = $1;  }
;
Expression3 : Expression3 _SYMB_26 Expression4 { $$ = new EBand($1, $3);  } 
  | Expression3 _SYMB_27 Expression4 { $$ = new EBor($1, $3);  }
  | Expression3 _SYMB_28 Expression4 { $$ = new EBxor($1, $3);  }
  | Expression4 { $$ = $1;  }
;
Expression2 : Expression3 _SYMB_29 Expression3 { $$ = new ELand($1, $3);  } 
  | Expression3 _SYMB_30 Expression3 { $$ = new ELor($1, $3);  }
  | Expression3 _SYMB_31 Expression3 { $$ = new ELxor($1, $3);  }
  | Expression3 { $$ = $1;  }
;
Expression1 : Expression2 _SYMB_32 Expression2 _SYMB_33 Expression2 { $$ = new ECon($1, $3, $5);  } 
  | Expression2 { $$ = $1;  }
;
Expression : _IDENT_ _SYMB_34 Expression { $$ = new EAss($1, $3);  } 
  | _IDENT_ _SYMB_35 Expression { $$ = new EAddAss($1, $3);  }
  | _IDENT_ _SYMB_36 Expression { $$ = new ESubAss($1, $3);  }
  | _IDENT_ _SYMB_37 Expression { $$ = new EMulAss($1, $3);  }
  | _IDENT_ _SYMB_38 Expression { $$ = new EDivAss($1, $3);  }
  | _IDENT_ _SYMB_39 Expression { $$ = new EModAss($1, $3);  }
  | _IDENT_ _SYMB_40 Expression { $$ = new EAndAss($1, $3);  }
  | _IDENT_ _SYMB_41 Expression { $$ = new EOrAss($1, $3);  }
  | _IDENT_ _SYMB_42 Expression { $$ = new EXorAss($1, $3);  }
  | _IDENT_ _SYMB_43 Expression { $$ = new ELShAss($1, $3);  }
  | _IDENT_ _SYMB_44 Expression { $$ = new ERShAss($1, $3);  }
  | Expression1 { $$ = $1;  }
;
ListExpression : Expression { $$ = new ListExpression($1);  } 
  | Expression _SYMB_4 ListExpression { $$ = new ListExpression($1, $3);  }
;

