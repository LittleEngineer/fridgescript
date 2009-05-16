/* This FLex file was machine-generated by the BNF converter */
%{
#include <string.h>
#include "Parser.H"
#define YY_BUFFER_LENGTH 4096
extern int yy_mylinenumber ;
char YY_PARSED_STRING[YY_BUFFER_LENGTH];
void YY_BUFFER_APPEND(char *s)
{
  strcat(YY_PARSED_STRING, s); //Do something better here!
}
void YY_BUFFER_RESET(void)
{
  for(int x = 0; x < YY_BUFFER_LENGTH; x++)
    YY_PARSED_STRING[x] = 0;
}

%}

LETTER [a-zA-Z]
CAPITAL [A-Z]
SMALL [a-z]
DIGIT [0-9]
IDENT [a-zA-Z0-9'_]
%START YYINITIAL COMMENT CHAR CHARESC CHAREND STRING ESCAPED
%%

<YYINITIAL>"("      	 return _SYMB_0;
<YYINITIAL>")"      	 return _SYMB_1;
<YYINITIAL>"{"      	 return _SYMB_2;
<YYINITIAL>"}"      	 return _SYMB_3;
<YYINITIAL>","      	 return _SYMB_4;
<YYINITIAL>";"      	 return _SYMB_5;
<YYINITIAL>"++"      	 return _SYMB_6;
<YYINITIAL>"--"      	 return _SYMB_7;
<YYINITIAL>"!"      	 return _SYMB_8;
<YYINITIAL>"-"      	 return _SYMB_9;
<YYINITIAL>"~"      	 return _SYMB_10;
<YYINITIAL>"+"      	 return _SYMB_11;
<YYINITIAL>"*"      	 return _SYMB_12;
<YYINITIAL>"/"      	 return _SYMB_13;
<YYINITIAL>"%"      	 return _SYMB_14;
<YYINITIAL>"<<"      	 return _SYMB_15;
<YYINITIAL>">>"      	 return _SYMB_16;
<YYINITIAL>"<"      	 return _SYMB_17;
<YYINITIAL>">"      	 return _SYMB_18;
<YYINITIAL>"<="      	 return _SYMB_19;
<YYINITIAL>">="      	 return _SYMB_20;
<YYINITIAL>"=="      	 return _SYMB_21;
<YYINITIAL>"!="      	 return _SYMB_22;
<YYINITIAL>"&"      	 return _SYMB_23;
<YYINITIAL>"|"      	 return _SYMB_24;
<YYINITIAL>"^"      	 return _SYMB_25;
<YYINITIAL>"&&"      	 return _SYMB_26;
<YYINITIAL>"||"      	 return _SYMB_27;
<YYINITIAL>"^^"      	 return _SYMB_28;
<YYINITIAL>"?"      	 return _SYMB_29;
<YYINITIAL>":"      	 return _SYMB_30;
<YYINITIAL>"="      	 return _SYMB_31;
<YYINITIAL>"+="      	 return _SYMB_32;
<YYINITIAL>"-="      	 return _SYMB_33;
<YYINITIAL>"*="      	 return _SYMB_34;
<YYINITIAL>"/="      	 return _SYMB_35;
<YYINITIAL>"%="      	 return _SYMB_36;
<YYINITIAL>"&="      	 return _SYMB_37;
<YYINITIAL>"|="      	 return _SYMB_38;
<YYINITIAL>"^="      	 return _SYMB_39;
<YYINITIAL>"<<="      	 return _SYMB_40;
<YYINITIAL>">>="      	 return _SYMB_41;
<YYINITIAL>"acos"      	 return _SYMB_42;
<YYINITIAL>"asin"      	 return _SYMB_43;
<YYINITIAL>"atan"      	 return _SYMB_44;
<YYINITIAL>"atan2"      	 return _SYMB_45;
<YYINITIAL>"break"      	 return _SYMB_46;
<YYINITIAL>"continue"      	 return _SYMB_47;
<YYINITIAL>"cos"      	 return _SYMB_48;
<YYINITIAL>"else"      	 return _SYMB_49;
<YYINITIAL>"exp"      	 return _SYMB_50;
<YYINITIAL>"for"      	 return _SYMB_51;
<YYINITIAL>"if"      	 return _SYMB_52;
<YYINITIAL>"log"      	 return _SYMB_53;
<YYINITIAL>"log10"      	 return _SYMB_54;
<YYINITIAL>"pi"      	 return _SYMB_55;
<YYINITIAL>"pow"      	 return _SYMB_56;
<YYINITIAL>"return"      	 return _SYMB_57;
<YYINITIAL>"sin"      	 return _SYMB_58;
<YYINITIAL>"sqrt"      	 return _SYMB_59;
<YYINITIAL>"tan"      	 return _SYMB_60;
<YYINITIAL>"until"      	 return _SYMB_61;
<YYINITIAL>"while"      	 return _SYMB_62;

<YYINITIAL>"//"[^\n]*\n  ++yy_mylinenumber ; 	 /* BNFC single-line comment */;
<YYINITIAL>"/*"      	 BEGIN COMMENT;
<COMMENT>"*/"      	 BEGIN YYINITIAL;
<COMMENT>.      	 /* BNFC multi-line comment */;
<COMMENT>[\n]   ++yy_mylinenumber ; 	 /* BNFC multi-line comment */;

<YYINITIAL>{DIGIT}+"."{DIGIT}+("e"(\-)?{DIGIT}+)?      	 yylval.double_ = atof(yytext); return _DOUBLE_;
<YYINITIAL>{DIGIT}+      	 yylval.int_ = atoi(yytext); return _INTEGER_;
<YYINITIAL>{LETTER}{IDENT}*      	 yylval.string_ = strdup(yytext); return _IDENT_;
\n  ++yy_mylinenumber ;
<YYINITIAL>[ \t\r\n\f]      	 /* ignore white space. */;
<YYINITIAL>.      	 return _ERROR_;
%%
int initialize_lexer(FILE *inp) { yyin = inp; BEGIN YYINITIAL; }
int yywrap(void) { return 1; }
