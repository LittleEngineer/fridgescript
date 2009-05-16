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


Code* YY_RESULT_Code_ = 0;
Code* pCode(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Code_;
  }
}

ListOperation* YY_RESULT_ListOperation_ = 0;
ListOperation* pListOperation(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_ListOperation_;
  }
}

Operation* YY_RESULT_Operation_ = 0;
Operation* pOperation(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Operation_;
  }
}

Register* YY_RESULT_Register_ = 0;
Register* pRegister(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Register_;
  }
}

Operand* YY_RESULT_Operand_ = 0;
Operand* pOperand(FILE *inp)
{
  initialize_lexer(inp);
  if (yyparse())
  { /* Failure */
    return 0;
  }
  else
  { /* Success */
    return YY_RESULT_Operand_;
  }
}


ListOperation* reverseListOperation(ListOperation *l)
{
  ListOperation *prev = 0;
  ListOperation *tmp = 0;
  while (l)
  {
    tmp = l->listoperation_;
    l->listoperation_ = prev;
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
  Code* code_;
  ListOperation* listoperation_;
  Operation* operation_;
  Register* register_;
  Operand* operand_;

}

%token _ERROR_
%token _SYMB_0    //   ,
%token _SYMB_1    //   :
%token _SYMB_2    //   st(0)
%token _SYMB_3    //   st(1)
%token _SYMB_4    //   st(2)
%token _SYMB_5    //   st(3)
%token _SYMB_6    //   st(4)
%token _SYMB_7    //   st(5)
%token _SYMB_8    //   st(6)
%token _SYMB_9    //   st(7)
%token _SYMB_10    //   [
%token _SYMB_11    //   ]
%token _SYMB_12    //   +
%token _SYMB_13    //   -
%token _SYMB_14    //   add
%token _SYMB_15    //   call
%token _SYMB_16    //   eax
%token _SYMB_17    //   ebp
%token _SYMB_18    //   ebx
%token _SYMB_19    //   ecx
%token _SYMB_20    //   edi
%token _SYMB_21    //   edx
%token _SYMB_22    //   esi
%token _SYMB_23    //   esp
%token _SYMB_24    //   f2xm1
%token _SYMB_25    //   fadd
%token _SYMB_26    //   faddp
%token _SYMB_27    //   fchs
%token _SYMB_28    //   fcmovb
%token _SYMB_29    //   fcmovbe
%token _SYMB_30    //   fcmove
%token _SYMB_31    //   fcmovnb
%token _SYMB_32    //   fcmovnbe
%token _SYMB_33    //   fcmovne
%token _SYMB_34    //   fcmovnu
%token _SYMB_35    //   fcmovu
%token _SYMB_36    //   fcomi
%token _SYMB_37    //   fcos
%token _SYMB_38    //   fdecstp
%token _SYMB_39    //   fdivp
%token _SYMB_40    //   fdivrp
%token _SYMB_41    //   ffree
%token _SYMB_42    //   fild
%token _SYMB_43    //   fincstp
%token _SYMB_44    //   fist
%token _SYMB_45    //   fistp
%token _SYMB_46    //   fld
%token _SYMB_47    //   fld1
%token _SYMB_48    //   fldl2e
%token _SYMB_49    //   fldlg2
%token _SYMB_50    //   fldln2
%token _SYMB_51    //   fldpi
%token _SYMB_52    //   fldz
%token _SYMB_53    //   fmulp
%token _SYMB_54    //   fpatan
%token _SYMB_55    //   fprem
%token _SYMB_56    //   fptan
%token _SYMB_57    //   frndint
%token _SYMB_58    //   fscale
%token _SYMB_59    //   fsin
%token _SYMB_60    //   fsqrt
%token _SYMB_61    //   fst
%token _SYMB_62    //   fstp
%token _SYMB_63    //   fsub
%token _SYMB_64    //   fsubp
%token _SYMB_65    //   fsubrp
%token _SYMB_66    //   fxch
%token _SYMB_67    //   fyl2x
%token _SYMB_68    //   fyl2xp1
%token _SYMB_69    //   jb
%token _SYMB_70    //   jbe
%token _SYMB_71    //   je
%token _SYMB_72    //   jmp
%token _SYMB_73    //   jne
%token _SYMB_74    //   jnz
%token _SYMB_75    //   jz
%token _SYMB_76    //   pop
%token _SYMB_77    //   push
%token _SYMB_78    //   ret
%token _SYMB_79    //   sub
%token<string_> _SYMB_80    //   HexConstant

%type <code_> Code
%type <listoperation_> ListOperation
%type <operation_> Operation
%type <register_> Register
%type <operand_> Operand

%token<int_> _INTEGER_
%token<string_> _IDENT_

%%
Code : ListOperation { $$ = new Main(reverseListOperation($1)); YY_RESULT_Code_= $$; } 
;
ListOperation : /* empty */ { $$ = 0;  } 
  | ListOperation Operation { $$ = new ListOperation($2, $1);  }
;
Operation : _SYMB_14 Register _SYMB_0 _INTEGER_ { $$ = new OAddC($2, $4);  } 
  | _SYMB_79 Register _SYMB_0 _INTEGER_ { $$ = new OSubC($2, $4);  }
  | _IDENT_ _SYMB_1 { $$ = new OLbl($1);  }
  | _SYMB_72 Operand { $$ = new OJmp($2);  }
  | _SYMB_69 Operand { $$ = new OJb($2);  }
  | _SYMB_70 Operand { $$ = new OJbe($2);  }
  | _SYMB_71 Operand { $$ = new OJe($2);  }
  | _SYMB_73 Operand { $$ = new OJne($2);  }
  | _SYMB_75 Operand { $$ = new OJz($2);  }
  | _SYMB_74 Operand { $$ = new OJnz($2);  }
  | _SYMB_15 Operand { $$ = new OCall($2);  }
  | _SYMB_78 { $$ = new ORet();  }
  | _SYMB_77 Operand { $$ = new OPush($2);  }
  | _SYMB_76 Operand { $$ = new OPop($2);  }
  | _SYMB_25 { $$ = new OFadd();  }
  | _SYMB_26 { $$ = new OFaddp();  }
  | _SYMB_63 { $$ = new OFsub();  }
  | _SYMB_64 { $$ = new OFsubp();  }
  | _SYMB_65 { $$ = new OFsubrp();  }
  | _SYMB_53 { $$ = new OFmulp();  }
  | _SYMB_39 { $$ = new OFdivp();  }
  | _SYMB_40 { $$ = new OFdivrp();  }
  | _SYMB_27 { $$ = new OFchs();  }
  | _SYMB_59 { $$ = new OFsin();  }
  | _SYMB_37 { $$ = new OFcos();  }
  | _SYMB_55 { $$ = new OFprem();  }
  | _SYMB_56 { $$ = new OFptan();  }
  | _SYMB_54 { $$ = new OFpatan();  }
  | _SYMB_60 { $$ = new OFsqrt();  }
  | _SYMB_57 { $$ = new OFrndint();  }
  | _SYMB_58 { $$ = new OFscale();  }
  | _SYMB_24 { $$ = new OFtxmo();  }
  | _SYMB_67 { $$ = new OFyltx();  }
  | _SYMB_68 { $$ = new OFyltxpo();  }
  | _SYMB_36 { $$ = new OFcomi();  }
  | _SYMB_28 { $$ = new OFcmovb();  }
  | _SYMB_29 { $$ = new OFcmovbe();  }
  | _SYMB_30 { $$ = new OFcmove();  }
  | _SYMB_31 { $$ = new OFcmovnb();  }
  | _SYMB_32 { $$ = new OFcmovnbe();  }
  | _SYMB_33 { $$ = new OFcmovne();  }
  | _SYMB_34 { $$ = new OFcmovnu();  }
  | _SYMB_35 { $$ = new OFcmovu();  }
  | _SYMB_46 Operand { $$ = new OFld($2);  }
  | _SYMB_42 Operand { $$ = new OFild($2);  }
  | _SYMB_46 _SYMB_2 { $$ = new OFldt();  }
  | _SYMB_46 _SYMB_3 { $$ = new OFldn();  }
  | _SYMB_52 { $$ = new OFldz();  }
  | _SYMB_47 { $$ = new OFldo();  }
  | _SYMB_51 { $$ = new OFldpi();  }
  | _SYMB_48 { $$ = new OFldlte();  }
  | _SYMB_50 { $$ = new OFldlnt();  }
  | _SYMB_49 { $$ = new OFldlgt();  }
  | _SYMB_61 Operand { $$ = new OFst($2);  }
  | _SYMB_44 Operand { $$ = new OFist($2);  }
  | _SYMB_62 Operand { $$ = new OFstp($2);  }
  | _SYMB_45 Operand { $$ = new OFistp($2);  }
  | _SYMB_62 _SYMB_2 { $$ = new OFstpt();  }
  | _SYMB_41 _SYMB_2 { $$ = new OFfree();  }
  | _SYMB_41 _SYMB_3 { $$ = new OFfreea();  }
  | _SYMB_41 _SYMB_4 { $$ = new OFfreeb();  }
  | _SYMB_41 _SYMB_5 { $$ = new OFfreec();  }
  | _SYMB_41 _SYMB_6 { $$ = new OFfreed();  }
  | _SYMB_41 _SYMB_7 { $$ = new OFfreee();  }
  | _SYMB_41 _SYMB_8 { $$ = new OFfreef();  }
  | _SYMB_41 _SYMB_9 { $$ = new OFfreeg();  }
  | _SYMB_66 { $$ = new OFxchg();  }
  | _SYMB_43 { $$ = new OFincstp();  }
  | _SYMB_38 { $$ = new OFdecstp();  }
;
Register : _SYMB_16 { $$ = new REax();  } 
  | _SYMB_19 { $$ = new REcx();  }
  | _SYMB_21 { $$ = new REdx();  }
  | _SYMB_18 { $$ = new REbx();  }
  | _SYMB_23 { $$ = new REsp();  }
  | _SYMB_17 { $$ = new REbp();  }
  | _SYMB_22 { $$ = new REsi();  }
  | _SYMB_20 { $$ = new REdi();  }
;
Operand : Register { $$ = new OReg($1);  } 
  | _SYMB_80 { $$ = new OHex($1);  }
  | _IDENT_ { $$ = new OLab($1);  }
  | _SYMB_10 _SYMB_80 _SYMB_11 { $$ = new OLitAdd($2);  }
  | _SYMB_10 Register _SYMB_11 { $$ = new ORegAdd($2);  }
  | _SYMB_10 Register _SYMB_12 _INTEGER_ _SYMB_11 { $$ = new ORelAddP($2, $4);  }
  | _SYMB_10 Register _SYMB_13 _INTEGER_ _SYMB_11 { $$ = new ORelAddS($2, $4);  }
;

