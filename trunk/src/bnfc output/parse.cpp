/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     _ERROR_ = 258,
     _SYMB_0 = 259,
     _SYMB_1 = 260,
     _SYMB_2 = 261,
     _SYMB_3 = 262,
     _SYMB_4 = 263,
     _SYMB_5 = 264,
     _SYMB_6 = 265,
     _SYMB_7 = 266,
     _SYMB_8 = 267,
     _SYMB_9 = 268,
     _SYMB_10 = 269,
     _SYMB_11 = 270,
     _SYMB_12 = 271,
     _SYMB_13 = 272,
     _SYMB_14 = 273,
     _SYMB_15 = 274,
     _SYMB_16 = 275,
     _SYMB_17 = 276,
     _SYMB_18 = 277,
     _SYMB_19 = 278,
     _SYMB_20 = 279,
     _SYMB_21 = 280,
     _SYMB_22 = 281,
     _SYMB_23 = 282,
     _SYMB_24 = 283,
     _SYMB_25 = 284,
     _SYMB_26 = 285,
     _SYMB_27 = 286,
     _SYMB_28 = 287,
     _SYMB_29 = 288,
     _SYMB_30 = 289,
     _SYMB_31 = 290,
     _SYMB_32 = 291,
     _SYMB_33 = 292,
     _SYMB_34 = 293,
     _SYMB_35 = 294,
     _SYMB_36 = 295,
     _SYMB_37 = 296,
     _SYMB_38 = 297,
     _SYMB_39 = 298,
     _SYMB_40 = 299,
     _SYMB_41 = 300,
     _SYMB_42 = 301,
     _SYMB_43 = 302,
     _SYMB_44 = 303,
     _SYMB_45 = 304,
     _SYMB_46 = 305,
     _SYMB_47 = 306,
     _SYMB_48 = 307,
     _SYMB_49 = 308,
     _SYMB_50 = 309,
     _SYMB_51 = 310,
     _SYMB_52 = 311,
     _SYMB_53 = 312,
     _SYMB_54 = 313,
     _SYMB_55 = 314,
     _SYMB_56 = 315,
     _SYMB_57 = 316,
     _SYMB_58 = 317,
     _SYMB_59 = 318,
     _SYMB_60 = 319,
     _SYMB_61 = 320,
     _SYMB_62 = 321,
     _SYMB_63 = 322,
     _SYMB_64 = 323,
     _INTEGER_ = 324,
     _DOUBLE_ = 325,
     _IDENT_ = 326
   };
#endif
/* Tokens.  */
#define _ERROR_ 258
#define _SYMB_0 259
#define _SYMB_1 260
#define _SYMB_2 261
#define _SYMB_3 262
#define _SYMB_4 263
#define _SYMB_5 264
#define _SYMB_6 265
#define _SYMB_7 266
#define _SYMB_8 267
#define _SYMB_9 268
#define _SYMB_10 269
#define _SYMB_11 270
#define _SYMB_12 271
#define _SYMB_13 272
#define _SYMB_14 273
#define _SYMB_15 274
#define _SYMB_16 275
#define _SYMB_17 276
#define _SYMB_18 277
#define _SYMB_19 278
#define _SYMB_20 279
#define _SYMB_21 280
#define _SYMB_22 281
#define _SYMB_23 282
#define _SYMB_24 283
#define _SYMB_25 284
#define _SYMB_26 285
#define _SYMB_27 286
#define _SYMB_28 287
#define _SYMB_29 288
#define _SYMB_30 289
#define _SYMB_31 290
#define _SYMB_32 291
#define _SYMB_33 292
#define _SYMB_34 293
#define _SYMB_35 294
#define _SYMB_36 295
#define _SYMB_37 296
#define _SYMB_38 297
#define _SYMB_39 298
#define _SYMB_40 299
#define _SYMB_41 300
#define _SYMB_42 301
#define _SYMB_43 302
#define _SYMB_44 303
#define _SYMB_45 304
#define _SYMB_46 305
#define _SYMB_47 306
#define _SYMB_48 307
#define _SYMB_49 308
#define _SYMB_50 309
#define _SYMB_51 310
#define _SYMB_52 311
#define _SYMB_53 312
#define _SYMB_54 313
#define _SYMB_55 314
#define _SYMB_56 315
#define _SYMB_57 316
#define _SYMB_58 317
#define _SYMB_59 318
#define _SYMB_60 319
#define _SYMB_61 320
#define _SYMB_62 321
#define _SYMB_63 322
#define _SYMB_64 323
#define _INTEGER_ 324
#define _DOUBLE_ 325
#define _IDENT_ 326




/* Copy the first part of user declarations.  */
#line 2 "FridgeScript.y"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 247 "FridgeScript.y"
typedef union YYSTYPE {
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

} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 490 "parse.cpp"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 502 "parse.cpp"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   526

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  23
/* YYNRULES -- Number of rules. */
#define YYNRULES  97
/* YYNRULES -- Number of states. */
#define YYNSTATES  240

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    17,    19,    20,    23,
      25,    28,    30,    33,    35,    39,    42,    46,    50,    58,
      70,    78,    86,    94,   106,   109,   112,   114,   116,   118,
     120,   124,   128,   133,   136,   139,   144,   151,   156,   161,
     166,   171,   176,   181,   186,   191,   198,   203,   208,   210,
     213,   216,   219,   222,   225,   228,   230,   234,   238,   242,
     244,   248,   252,   254,   258,   262,   264,   268,   272,   276,
     280,   282,   286,   290,   292,   296,   300,   304,   306,   310,
     314,   318,   320,   326,   328,   332,   336,   340,   344,   348,
     352,   356,   360,   364,   368,   372,   374,   376
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      73,     0,    -1,    77,    -1,    78,    -1,    79,    -1,    71,
       4,    80,     5,     6,    77,     7,    -1,    71,    -1,    -1,
      77,    74,    -1,    75,    -1,    75,    78,    -1,    81,    -1,
      81,    79,    -1,    76,    -1,    76,     8,    80,    -1,    93,
       9,    -1,     6,    79,     7,    -1,    65,    93,     9,    -1,
      59,     4,    93,     5,     6,    79,     7,    -1,    59,     4,
      93,     5,     6,    79,     7,    57,     6,    79,     7,    -1,
      62,     4,    93,     5,     6,    79,     7,    -1,    10,     4,
      93,     5,     6,    79,     7,    -1,    11,     4,    93,     5,
       6,    79,     7,    -1,    12,     4,    94,     9,    93,     9,
      94,     5,     6,    79,     7,    -1,    54,     9,    -1,    55,
       9,    -1,    70,    -1,    69,    -1,    71,    -1,    63,    -1,
       4,    93,     5,    -1,    71,     4,     5,    -1,    71,     4,
      94,     5,    -1,    71,    13,    -1,    71,    14,    -1,    49,
       4,    93,     5,    -1,    64,     4,    93,     8,    93,     5,
      -1,    67,     4,    93,     5,    -1,    58,     4,    93,     5,
      -1,    60,     4,    93,     5,    -1,    61,     4,    93,     5,
      -1,    66,     4,    93,     5,    -1,    56,     4,    93,     5,
      -1,    68,     4,    93,     5,    -1,    52,     4,    93,     5,
      -1,    53,     4,    93,     8,    93,     5,    -1,    51,     4,
      93,     5,    -1,    50,     4,    93,     5,    -1,    82,    -1,
      15,    83,    -1,    13,    71,    -1,    14,    71,    -1,    16,
      83,    -1,    17,    83,    -1,    18,    83,    -1,    83,    -1,
      85,    19,    84,    -1,    85,    20,    84,    -1,    85,    21,
      84,    -1,    84,    -1,    86,    18,    85,    -1,    86,    16,
      85,    -1,    85,    -1,    87,    22,    86,    -1,    87,    23,
      86,    -1,    86,    -1,    87,    24,    87,    -1,    87,    25,
      87,    -1,    87,    26,    87,    -1,    87,    27,    87,    -1,
      87,    -1,    88,    28,    88,    -1,    88,    29,    88,    -1,
      88,    -1,    90,    30,    89,    -1,    90,    31,    89,    -1,
      90,    32,    89,    -1,    89,    -1,    90,    33,    90,    -1,
      90,    34,    90,    -1,    90,    35,    90,    -1,    90,    -1,
      91,    36,    91,    37,    91,    -1,    91,    -1,    71,    38,
      93,    -1,    71,    39,    93,    -1,    71,    40,    93,    -1,
      71,    41,    93,    -1,    71,    42,    93,    -1,    71,    43,
      93,    -1,    71,    44,    93,    -1,    71,    45,    93,    -1,
      71,    46,    93,    -1,    71,    47,    93,    -1,    71,    48,
      93,    -1,    92,    -1,    93,    -1,    93,     8,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   361,   361,   363,   364,   366,   368,   370,   371,   373,
     374,   376,   377,   379,   380,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   394,   395,   396,   397,
     398,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   419,
     420,   421,   422,   423,   424,   425,   427,   428,   429,   430,
     432,   433,   434,   436,   437,   438,   440,   441,   442,   443,
     444,   446,   447,   448,   450,   451,   452,   453,   455,   456,
     457,   458,   460,   461,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   476,   477
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "_ERROR_", "_SYMB_0", "_SYMB_1",
  "_SYMB_2", "_SYMB_3", "_SYMB_4", "_SYMB_5", "_SYMB_6", "_SYMB_7",
  "_SYMB_8", "_SYMB_9", "_SYMB_10", "_SYMB_11", "_SYMB_12", "_SYMB_13",
  "_SYMB_14", "_SYMB_15", "_SYMB_16", "_SYMB_17", "_SYMB_18", "_SYMB_19",
  "_SYMB_20", "_SYMB_21", "_SYMB_22", "_SYMB_23", "_SYMB_24", "_SYMB_25",
  "_SYMB_26", "_SYMB_27", "_SYMB_28", "_SYMB_29", "_SYMB_30", "_SYMB_31",
  "_SYMB_32", "_SYMB_33", "_SYMB_34", "_SYMB_35", "_SYMB_36", "_SYMB_37",
  "_SYMB_38", "_SYMB_39", "_SYMB_40", "_SYMB_41", "_SYMB_42", "_SYMB_43",
  "_SYMB_44", "_SYMB_45", "_SYMB_46", "_SYMB_47", "_SYMB_48", "_SYMB_49",
  "_SYMB_50", "_SYMB_51", "_SYMB_52", "_SYMB_53", "_SYMB_54", "_SYMB_55",
  "_SYMB_56", "_SYMB_57", "_SYMB_58", "_SYMB_59", "_SYMB_60", "_SYMB_61",
  "_SYMB_62", "_SYMB_63", "_SYMB_64", "_INTEGER_", "_DOUBLE_", "_IDENT_",
  "$accept", "Program", "Block", "Function", "Parameter", "ListBlock",
  "ListFunction", "ListStatement", "ListParameter", "Statement",
  "Expression11", "Expression10", "Expression9", "Expression8",
  "Expression7", "Expression6", "Expression5", "Expression4",
  "Expression3", "Expression2", "Expression1", "Expression",
  "ListExpression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    72,    73,    74,    74,    75,    76,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    85,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    88,    88,    88,    88,
      88,    89,    89,    89,    90,    90,    90,    90,    91,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     1,     7,     1,     0,     2,     1,
       2,     1,     2,     1,     3,     2,     3,     3,     7,    11,
       7,     7,     7,    11,     2,     2,     1,     1,     1,     1,
       3,     3,     4,     2,     2,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     1,     2,
       2,     2,     2,     2,     2,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     5,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       7,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,    27,    26,    28,     8,     9,     3,
       4,    11,    48,    55,    59,    62,    65,    70,    73,    77,
      81,    83,    95,     0,    28,     0,     0,     0,     0,     0,
      50,    51,    28,    49,    52,    53,    54,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,    30,    16,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,    31,    28,    13,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,    56,    57,    58,    61,    60,    63,    64,
      66,    67,    68,    69,    71,    72,    74,    75,    76,    78,
      79,    80,     0,     0,     0,     0,     0,    35,    47,    46,
      44,     0,    42,    38,     0,    39,    40,     0,     0,    41,
      37,    43,     0,     0,    32,     6,     0,     0,     0,    97,
       0,     0,     0,     0,     0,    14,     7,    82,     0,     0,
       0,    45,     0,     0,    36,     0,    21,    22,     0,    18,
      20,     5,     0,     0,     0,     0,     0,     0,    23,    19
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    37,    38,   148,     2,    39,    40,   149,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,   150
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const short int yypact[] =
{
    -111,    26,   231,  -111,   383,   299,     2,    59,   104,    39,
      46,    74,    74,    74,    74,   114,   115,   117,   118,   125,
     122,   124,   132,   135,   142,   148,   149,   151,  -111,   153,
     383,   156,   166,   167,  -111,  -111,   467,  -111,   101,  -111,
    -111,   299,  -111,  -111,  -111,   -11,    91,    -6,     6,  -111,
      -2,   137,  -111,   165,   478,   170,   169,   383,   383,   383,
    -111,  -111,     1,  -111,  -111,  -111,  -111,   383,   383,   383,
     383,   383,  -111,  -111,   383,   383,   383,   383,   383,   383,
     383,   168,   383,   383,   383,    98,  -111,  -111,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   174,
    -111,  -111,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,  -111,   322,  -111,  -111,   175,   176,   171,   177,
     179,   180,   182,   184,   183,   185,   187,   188,   189,   191,
     192,   190,  -111,   194,   195,   196,  -111,    -1,   197,   199,
     201,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,   138,  -111,  -111,  -111,   -11,   -11,    91,    91,
      30,    30,    30,    30,  -111,  -111,  -111,  -111,  -111,    27,
      27,    27,   173,   205,   207,   383,   383,  -111,  -111,  -111,
    -111,   383,  -111,  -111,   210,  -111,  -111,   221,   383,  -111,
    -111,  -111,   138,   222,  -111,  -111,   406,   299,   299,  -111,
     223,   226,   299,   299,   228,  -111,  -111,  -111,   227,   229,
     383,  -111,   232,   233,  -111,   208,  -111,  -111,   245,   181,
    -111,  -111,   246,   247,   299,   299,   244,   248,  -111,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -111,  -111,  -111,  -111,  -111,    38,   218,    -5,    63,  -111,
    -111,    11,   -42,   -36,   -24,   -61,   -13,   -18,   -14,  -110,
    -111,    -3,   -57
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -7
static const short int yytable[] =
{
      56,    55,   129,   123,    -6,   123,    57,    -6,   102,   103,
     104,   182,    86,    87,    86,    87,   107,   108,   109,   110,
     111,   112,    63,    64,    65,    66,     3,    81,   115,   116,
     117,   118,   119,   120,   113,   114,   101,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   170,   171,
     172,   173,   107,   108,   126,   127,   128,   115,   116,   117,
     163,   164,   165,    58,   130,   131,   132,   133,   134,   166,
     167,   135,   136,   137,   138,   139,   140,   141,     4,   143,
     144,   145,   128,   168,   169,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   217,   176,   177,   178,
     174,   175,     4,   146,   179,   180,   181,   105,    59,   106,
      60,     9,    10,    11,    12,    13,    14,    61,    67,    68,
     128,    69,    70,    15,    16,    17,    18,    19,   209,    71,
      22,    72,    23,    73,    25,    26,    74,    28,    29,    75,
      31,    32,    33,    34,    35,    62,    76,    15,    16,    17,
      18,    19,    77,    78,    22,    79,    23,    80,    25,    26,
      82,    28,    29,   228,    31,    32,    33,    34,    35,   147,
      83,    84,    99,   121,   122,   124,   125,   142,   162,   185,
     183,   184,   128,   210,   187,   188,   186,   189,   211,   190,
     192,   191,   193,   194,   195,   214,   196,   197,   198,   199,
     200,   201,   218,   219,   203,   202,   204,   222,   223,   205,
     206,   207,     4,   208,     5,   231,   212,   128,     6,     7,
       8,     9,    10,    11,    12,    13,    14,   213,   216,   236,
     237,   221,   220,   224,   226,     4,   227,     5,   233,   229,
     230,     6,     7,     8,     9,    10,    11,    12,    13,    14,
     232,   238,   234,   235,   225,   239,   100,    15,    16,    17,
      18,    19,    20,    21,    22,   215,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      15,    16,    17,    18,    19,    20,    21,    22,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     4,     0,     5,     0,     0,     0,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     4,   146,     0,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,    15,    16,
      17,    18,    19,    20,    21,    22,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      54,    15,    16,    17,    18,    19,     0,     0,    22,     0,
      23,     0,    25,    26,     0,    28,    29,     4,    31,    32,
      33,    34,    35,    54,     0,     0,     9,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,     0,     0,    22,
       0,    23,     0,    25,    26,     0,    28,    29,     0,    31,
      32,    33,    34,    35,    54,    15,    16,    17,    18,    19,
       0,     0,    22,     0,    23,     0,    25,    26,     0,    28,
      29,    85,    31,    32,    33,    34,    35,    62,     0,     0,
      86,    87,   123,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98
};

static const short int yycheck[] =
{
       5,     4,    59,     4,     5,     4,     4,     8,    19,    20,
      21,   121,    13,    14,    13,    14,    22,    23,    24,    25,
      26,    27,    11,    12,    13,    14,     0,    30,    30,    31,
      32,    33,    34,    35,    28,    29,    41,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,   109,   110,
     111,   112,    22,    23,    57,    58,    59,    30,    31,    32,
     102,   103,   104,     4,    67,    68,    69,    70,    71,   105,
     106,    74,    75,    76,    77,    78,    79,    80,     4,    82,
      83,    84,    85,   107,   108,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   206,   115,   116,   117,
     113,   114,     4,     5,   118,   119,   120,    16,     4,    18,
      71,    13,    14,    15,    16,    17,    18,    71,     4,     4,
     123,     4,     4,    49,    50,    51,    52,    53,   185,     4,
      56,     9,    58,     9,    60,    61,     4,    63,    64,     4,
      66,    67,    68,    69,    70,    71,     4,    49,    50,    51,
      52,    53,     4,     4,    56,     4,    58,     4,    60,    61,
       4,    63,    64,   220,    66,    67,    68,    69,    70,    71,
       4,     4,    71,    36,     9,     5,     7,     9,     4,     8,
       5,     5,   185,   186,     5,     5,     9,     5,   191,     5,
       5,     8,     5,     5,     5,   198,     5,     5,     8,     5,
       5,     5,   207,   208,     5,     8,     5,   212,   213,    71,
      37,     6,     4,     6,     6,     7,     6,   220,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     6,     6,   234,
     235,     5,     9,     5,     7,     4,     7,     6,    57,     7,
       7,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       5,     7,     6,     6,   216,     7,    38,    49,    50,    51,
      52,    53,    54,    55,    56,   202,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     4,    -1,     6,    -1,    -1,    -1,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    49,    50,    51,    52,    53,    -1,    -1,    56,    -1,
      58,    -1,    60,    61,    -1,    63,    64,     4,    66,    67,
      68,    69,    70,    71,    -1,    -1,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    58,    -1,    60,    61,    -1,    63,    64,    -1,    66,
      67,    68,    69,    70,    71,    49,    50,    51,    52,    53,
      -1,    -1,    56,    -1,    58,    -1,    60,    61,    -1,    63,
      64,     4,    66,    67,    68,    69,    70,    71,    -1,    -1,
      13,    14,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    73,    77,     0,     4,     6,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    49,    50,    51,    52,    53,
      54,    55,    56,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    74,    75,    78,
      79,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    71,    93,    79,     4,     4,     4,
      71,    71,    71,    83,    83,    83,    83,     4,     4,     4,
       4,     4,     9,     9,     4,     4,     4,     4,     4,     4,
       4,    93,     4,     4,     4,     4,    13,    14,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    71,
      78,    79,    19,    20,    21,    16,    18,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     9,     4,     5,     7,    93,    93,    93,    94,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,     9,    93,    93,    93,     5,    71,    76,    80,
      94,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,     4,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    90,
      90,    90,    91,     5,     5,     8,     9,     5,     5,     5,
       5,     8,     5,     5,     5,     5,     5,     5,     8,     5,
       5,     5,     8,     5,     5,    71,    37,     6,     6,    94,
      93,    93,     6,     6,    93,    80,     6,    91,    79,    79,
       9,     5,    79,    79,     5,    77,     7,     7,    94,     7,
       7,     7,     5,    57,     6,     6,    79,    79,     7,     7
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 361 "FridgeScript.y"
    { (yyval.program_) = new Main(reverseListBlock((yyvsp[0].listblock_))); YY_RESULT_Program_= (yyval.program_); ;}
    break;

  case 3:
#line 363 "FridgeScript.y"
    { (yyval.block_) = new BFunc((yyvsp[0].listfunction_));  ;}
    break;

  case 4:
#line 364 "FridgeScript.y"
    { (yyval.block_) = new BStmt((yyvsp[0].liststatement_));  ;}
    break;

  case 5:
#line 366 "FridgeScript.y"
    { (yyval.function_) = new DTFunc((yyvsp[-6].string_), (yyvsp[-4].listparameter_), reverseListBlock((yyvsp[-1].listblock_)));  ;}
    break;

  case 6:
#line 368 "FridgeScript.y"
    { (yyval.parameter_) = new DTParam((yyvsp[0].string_));  ;}
    break;

  case 7:
#line 370 "FridgeScript.y"
    { (yyval.listblock_) = 0;  ;}
    break;

  case 8:
#line 371 "FridgeScript.y"
    { (yyval.listblock_) = new ListBlock((yyvsp[0].block_), (yyvsp[-1].listblock_));  ;}
    break;

  case 9:
#line 373 "FridgeScript.y"
    { (yyval.listfunction_) = new ListFunction((yyvsp[0].function_));  ;}
    break;

  case 10:
#line 374 "FridgeScript.y"
    { (yyval.listfunction_) = new ListFunction((yyvsp[-1].function_), (yyvsp[0].listfunction_));  ;}
    break;

  case 11:
#line 376 "FridgeScript.y"
    { (yyval.liststatement_) = new ListStatement((yyvsp[0].statement_));  ;}
    break;

  case 12:
#line 377 "FridgeScript.y"
    { (yyval.liststatement_) = new ListStatement((yyvsp[-1].statement_), (yyvsp[0].liststatement_));  ;}
    break;

  case 13:
#line 379 "FridgeScript.y"
    { (yyval.listparameter_) = new ListParameter((yyvsp[0].parameter_));  ;}
    break;

  case 14:
#line 380 "FridgeScript.y"
    { (yyval.listparameter_) = new ListParameter((yyvsp[-2].parameter_), (yyvsp[0].listparameter_));  ;}
    break;

  case 15:
#line 382 "FridgeScript.y"
    { (yyval.statement_) = new SExp((yyvsp[-1].expression_));  ;}
    break;

  case 16:
#line 383 "FridgeScript.y"
    { (yyval.statement_) = new SScope((yyvsp[-1].liststatement_));  ;}
    break;

  case 17:
#line 384 "FridgeScript.y"
    { (yyval.statement_) = new SRet((yyvsp[-1].expression_));  ;}
    break;

  case 18:
#line 385 "FridgeScript.y"
    { (yyval.statement_) = new SIf((yyvsp[-4].expression_), (yyvsp[-1].liststatement_));  ;}
    break;

  case 19:
#line 386 "FridgeScript.y"
    { (yyval.statement_) = new SIfElse((yyvsp[-8].expression_), (yyvsp[-5].liststatement_), (yyvsp[-1].liststatement_));  ;}
    break;

  case 20:
#line 387 "FridgeScript.y"
    { (yyval.statement_) = new SLoop((yyvsp[-4].expression_), (yyvsp[-1].liststatement_));  ;}
    break;

  case 21:
#line 388 "FridgeScript.y"
    { (yyval.statement_) = new SWhile((yyvsp[-4].expression_), (yyvsp[-1].liststatement_));  ;}
    break;

  case 22:
#line 389 "FridgeScript.y"
    { (yyval.statement_) = new SUntil((yyvsp[-4].expression_), (yyvsp[-1].liststatement_));  ;}
    break;

  case 23:
#line 390 "FridgeScript.y"
    { (yyval.statement_) = new SFor((yyvsp[-8].listexpression_), (yyvsp[-6].expression_), (yyvsp[-4].listexpression_), (yyvsp[-1].liststatement_));  ;}
    break;

  case 24:
#line 391 "FridgeScript.y"
    { (yyval.statement_) = new SBreak();  ;}
    break;

  case 25:
#line 392 "FridgeScript.y"
    { (yyval.statement_) = new SContinue();  ;}
    break;

  case 26:
#line 394 "FridgeScript.y"
    { (yyval.expression_) = new ECDbl((yyvsp[0].double_));  ;}
    break;

  case 27:
#line 395 "FridgeScript.y"
    { (yyval.expression_) = new ECInt((yyvsp[0].int_));  ;}
    break;

  case 28:
#line 396 "FridgeScript.y"
    { (yyval.expression_) = new EVar((yyvsp[0].string_));  ;}
    break;

  case 29:
#line 397 "FridgeScript.y"
    { (yyval.expression_) = new EPi();  ;}
    break;

  case 30:
#line 398 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[-1].expression_);  ;}
    break;

  case 31:
#line 400 "FridgeScript.y"
    { (yyval.expression_) = new ESimpleCall((yyvsp[-2].string_));  ;}
    break;

  case 32:
#line 401 "FridgeScript.y"
    { (yyval.expression_) = new ECall((yyvsp[-3].string_), (yyvsp[-1].listexpression_));  ;}
    break;

  case 33:
#line 402 "FridgeScript.y"
    { (yyval.expression_) = new EPostInc((yyvsp[-1].string_));  ;}
    break;

  case 34:
#line 403 "FridgeScript.y"
    { (yyval.expression_) = new EPostDec((yyvsp[-1].string_));  ;}
    break;

  case 35:
#line 404 "FridgeScript.y"
    { (yyval.expression_) = new EAbs((yyvsp[-1].expression_));  ;}
    break;

  case 36:
#line 405 "FridgeScript.y"
    { (yyval.expression_) = new EPow((yyvsp[-3].expression_), (yyvsp[-1].expression_));  ;}
    break;

  case 37:
#line 406 "FridgeScript.y"
    { (yyval.expression_) = new ESqrt((yyvsp[-1].expression_));  ;}
    break;

  case 38:
#line 407 "FridgeScript.y"
    { (yyval.expression_) = new EExp((yyvsp[-1].expression_));  ;}
    break;

  case 39:
#line 408 "FridgeScript.y"
    { (yyval.expression_) = new ELog((yyvsp[-1].expression_));  ;}
    break;

  case 40:
#line 409 "FridgeScript.y"
    { (yyval.expression_) = new ELogD((yyvsp[-1].expression_));  ;}
    break;

  case 41:
#line 410 "FridgeScript.y"
    { (yyval.expression_) = new ESin((yyvsp[-1].expression_));  ;}
    break;

  case 42:
#line 411 "FridgeScript.y"
    { (yyval.expression_) = new ECos((yyvsp[-1].expression_));  ;}
    break;

  case 43:
#line 412 "FridgeScript.y"
    { (yyval.expression_) = new ETan((yyvsp[-1].expression_));  ;}
    break;

  case 44:
#line 413 "FridgeScript.y"
    { (yyval.expression_) = new EAtan((yyvsp[-1].expression_));  ;}
    break;

  case 45:
#line 414 "FridgeScript.y"
    { (yyval.expression_) = new EAtanT((yyvsp[-3].expression_), (yyvsp[-1].expression_));  ;}
    break;

  case 46:
#line 415 "FridgeScript.y"
    { (yyval.expression_) = new EAsin((yyvsp[-1].expression_));  ;}
    break;

  case 47:
#line 416 "FridgeScript.y"
    { (yyval.expression_) = new EAcos((yyvsp[-1].expression_));  ;}
    break;

  case 48:
#line 417 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 49:
#line 419 "FridgeScript.y"
    { (yyval.expression_) = new ELnot((yyvsp[0].expression_));  ;}
    break;

  case 50:
#line 420 "FridgeScript.y"
    { (yyval.expression_) = new EPreInc((yyvsp[0].string_));  ;}
    break;

  case 51:
#line 421 "FridgeScript.y"
    { (yyval.expression_) = new EPreDec((yyvsp[0].string_));  ;}
    break;

  case 52:
#line 422 "FridgeScript.y"
    { (yyval.expression_) = new ENeg((yyvsp[0].expression_));  ;}
    break;

  case 53:
#line 423 "FridgeScript.y"
    { (yyval.expression_) = new EBnot((yyvsp[0].expression_));  ;}
    break;

  case 54:
#line 424 "FridgeScript.y"
    { (yyval.expression_) = new EPos((yyvsp[0].expression_));  ;}
    break;

  case 55:
#line 425 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 56:
#line 427 "FridgeScript.y"
    { (yyval.expression_) = new EMul((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 57:
#line 428 "FridgeScript.y"
    { (yyval.expression_) = new EDiv((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 58:
#line 429 "FridgeScript.y"
    { (yyval.expression_) = new EMod((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 59:
#line 430 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 60:
#line 432 "FridgeScript.y"
    { (yyval.expression_) = new EAdd((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 61:
#line 433 "FridgeScript.y"
    { (yyval.expression_) = new ESub((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 62:
#line 434 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 63:
#line 436 "FridgeScript.y"
    { (yyval.expression_) = new ELSh((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 64:
#line 437 "FridgeScript.y"
    { (yyval.expression_) = new ERSh((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 65:
#line 438 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 66:
#line 440 "FridgeScript.y"
    { (yyval.expression_) = new ELT((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 67:
#line 441 "FridgeScript.y"
    { (yyval.expression_) = new EGT((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 68:
#line 442 "FridgeScript.y"
    { (yyval.expression_) = new ELE((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 69:
#line 443 "FridgeScript.y"
    { (yyval.expression_) = new EGE((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 70:
#line 444 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 71:
#line 446 "FridgeScript.y"
    { (yyval.expression_) = new EE((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 72:
#line 447 "FridgeScript.y"
    { (yyval.expression_) = new ENE((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 73:
#line 448 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 74:
#line 450 "FridgeScript.y"
    { (yyval.expression_) = new EBand((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 75:
#line 451 "FridgeScript.y"
    { (yyval.expression_) = new EBor((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 76:
#line 452 "FridgeScript.y"
    { (yyval.expression_) = new EBxor((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 77:
#line 453 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 78:
#line 455 "FridgeScript.y"
    { (yyval.expression_) = new ELand((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 79:
#line 456 "FridgeScript.y"
    { (yyval.expression_) = new ELor((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 80:
#line 457 "FridgeScript.y"
    { (yyval.expression_) = new ELxor((yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 81:
#line 458 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 82:
#line 460 "FridgeScript.y"
    { (yyval.expression_) = new ECon((yyvsp[-4].expression_), (yyvsp[-2].expression_), (yyvsp[0].expression_));  ;}
    break;

  case 83:
#line 461 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 84:
#line 463 "FridgeScript.y"
    { (yyval.expression_) = new EAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 85:
#line 464 "FridgeScript.y"
    { (yyval.expression_) = new EAddAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 86:
#line 465 "FridgeScript.y"
    { (yyval.expression_) = new ESubAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 87:
#line 466 "FridgeScript.y"
    { (yyval.expression_) = new EMulAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 88:
#line 467 "FridgeScript.y"
    { (yyval.expression_) = new EDivAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 89:
#line 468 "FridgeScript.y"
    { (yyval.expression_) = new EModAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 90:
#line 469 "FridgeScript.y"
    { (yyval.expression_) = new EAndAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 91:
#line 470 "FridgeScript.y"
    { (yyval.expression_) = new EOrAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 92:
#line 471 "FridgeScript.y"
    { (yyval.expression_) = new EXorAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 93:
#line 472 "FridgeScript.y"
    { (yyval.expression_) = new ELShAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 94:
#line 473 "FridgeScript.y"
    { (yyval.expression_) = new ERShAss((yyvsp[-2].string_), (yyvsp[0].expression_));  ;}
    break;

  case 95:
#line 474 "FridgeScript.y"
    { (yyval.expression_) = (yyvsp[0].expression_);  ;}
    break;

  case 96:
#line 476 "FridgeScript.y"
    { (yyval.listexpression_) = new ListExpression((yyvsp[0].expression_));  ;}
    break;

  case 97:
#line 477 "FridgeScript.y"
    { (yyval.listexpression_) = new ListExpression((yyvsp[-2].expression_), (yyvsp[0].listexpression_));  ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2235 "parse.cpp"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



