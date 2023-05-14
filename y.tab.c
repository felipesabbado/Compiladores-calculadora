/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20220114

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#undef YYBTYACC
#define YYBTYACC 0
#define YYDEBUGSTR YYPREFIX "debug"
#define YYPREFIX "yy"

#define YYPURE 0

#line 1 "calculos.y"

#include <stdio.h>
#include <math.h>
#include <string.h>

struct var {
		int type;
		char name[20];
		union {
			int i;
			double d;
		};
	};

struct var expr[256];
int count_expr = 0;
struct var regvar[128];
int count = 0;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 21 "calculos.y"
typedef union YYSTYPE {
	int i;
	double d;
	char *s;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEIRO 257
#define REAL 258
#define POTENCIA 259
#define BSLEFT 260
#define BSRIGHT 261
#define INCREMENTO 262
#define DECREMENTO 263
#define CASTINT 264
#define VARIAVEL 265
#define CLEAR 266
#define CLEARINT 267
#define CLEARREAL 268
#define LIST 269
#define LISTINT 270
#define LISTREAL 271
#define UMINUS 272
#define YYERRCODE 256
typedef int YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    2,    2,    2,
};
static const YYINT yylen[] = {                            2,
    0,    3,    4,    5,    3,    4,    4,    3,    4,    3,
    3,    3,    4,    3,    3,    1,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    2,    3,
    1,    1,    1,
};
static const YYINT yydefred[] = {                         1,
    0,   31,   32,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   33,    0,    0,    0,
   16,    0,    0,    5,    0,    8,   10,   11,    0,   12,
   14,   15,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    2,    6,    7,    3,
    0,    9,   13,   30,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,
};
#if defined(YYDESTRUCT_CALL) || defined(YYSTYPE_TOSTRING)
static const YYINT yystos[] = {                           0,
  274,  257,  258,  262,  263,  264,  265,  266,  267,  268,
  269,  270,  271,   45,  126,   40,  275,  276,  265,  265,
  265,  276,   61,   10,  257,   10,   10,   10,  257,   10,
   10,   10,  276,  276,  276,  259,  260,  261,  124,   94,
   38,   43,   45,   42,   47,   37,   10,   10,   10,   10,
  276,   10,   10,   41,  276,  276,  276,  276,  276,  276,
  276,  276,  276,  276,  276,   10,
};
#endif /* YYDESTRUCT_CALL || YYSTYPE_TOSTRING */
static const YYINT yydgoto[] = {                          1,
   17,   18,
};
static const YYINT yysindex[] = {                         0,
  -32,    0,    0, -262, -261,  -38,    2,   -9,   -4,    4,
   -5,    5,    6,  -38,  -38,  -38,    0,  -10,    7,    8,
    0,    1,  -38,    0,   11,    0,    0,    0,   13,    0,
    0,    0, -249, -249,  159,  -38,  -38,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,    0,    0,    0,    0,
   12,    0,    0,    0, -249,  262,  262,  148,  244,  255,
  -18,  -18, -249, -249, -249,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,  170,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   24,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   60,   58,   94,   10,   -1,  291,
   15,  134,   79,  100,  120,    0,
};
#if YYBTYACC
static const YYINT yycindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#endif
static const YYINT yygindex[] = {                         0,
    0,  327,
};
#define YYTABLESIZE 521
static const YYINT yytable[] = {                         47,
   26,   16,   19,   20,   30,   27,   14,   16,   23,   36,
   50,   24,   14,   28,   31,   32,   48,   49,   46,   24,
   52,   66,   53,   44,   17,    0,   46,   41,   45,    0,
    0,   44,   42,   29,   43,    0,   45,   46,   41,   23,
    0,    0,   44,   42,   28,   43,    0,   45,   46,   41,
   24,    0,   17,   44,   42,   17,   43,   17,   45,   17,
   29,   29,   23,    0,   29,   29,   29,   27,   29,   21,
   29,   28,   28,    0,    0,   28,   28,   28,    0,   28,
    0,   28,    0,   40,    0,    0,    0,   15,   19,    0,
    0,    0,   23,   15,   40,   27,   21,   21,   27,    0,
   21,   21,   21,   26,   21,   40,   21,    0,   17,   20,
    0,    0,    0,   39,    0,   19,   19,   29,    0,   19,
   19,   19,   23,   19,   39,   19,    0,    0,   28,   22,
    0,   26,    0,   24,   26,   39,   20,   20,   17,    0,
   20,   20,   20,   18,   20,    0,   20,   29,    0,    0,
    0,   27,    0,   21,    0,    0,   22,   22,   28,    0,
   22,   22,   22,    0,   22,    0,   22,    0,    0,    0,
    0,   18,   19,    0,   18,    0,   18,    0,   18,    0,
    0,   27,    0,   21,   46,   41,    0,   26,    0,   44,
   42,    0,   43,   20,   45,   46,   41,    0,    0,   54,
   44,   42,   19,   43,    0,   45,   16,   16,    0,    0,
    0,   16,   16,   22,   16,    0,   16,   26,    2,    3,
    0,    0,    0,   20,    2,    3,   21,   18,    0,    4,
    5,    6,    7,    8,    9,   10,   11,   12,   13,    0,
   36,   40,    0,   22,    0,    0,    0,   25,   36,   37,
   38,   29,   40,    0,    0,    0,    0,   18,    0,   36,
   37,   38,    0,   16,    0,    0,    0,    0,    0,    0,
   36,   37,   38,    0,   17,   17,    0,    0,    0,    0,
   46,   41,   39,   29,   29,   44,   42,    0,   43,    0,
   45,   46,    0,   16,   28,   28,   44,   42,   46,   43,
   25,   45,    0,   44,   42,    0,   43,    0,   45,    0,
    0,    0,    0,    0,    0,    0,    0,   27,   27,   21,
   21,    0,    0,    0,    0,    0,    0,    0,   25,    0,
    0,   25,   22,    0,    0,    0,    0,    0,   19,   19,
   33,   34,   35,    0,    0,    0,    0,    0,    0,   51,
    0,    0,    0,   26,   26,    0,    0,    0,    0,   20,
   20,    0,   55,   56,   57,   58,   59,   60,   61,   62,
   63,   64,   65,    0,    0,    0,    0,    0,    0,   22,
   22,    0,    0,    0,   25,    0,    0,    0,    0,    0,
    0,    0,    0,   18,   18,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   36,   37,   38,    0,
    0,    0,    0,    0,   25,    0,    0,   36,   37,   38,
    0,    0,    0,    0,    0,    0,    0,    0,   16,   16,
   16,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   36,   37,   38,    0,    0,    0,    0,    0,
    0,    0,    0,   36,   37,   38,    0,    0,    0,    0,
   36,
};
static const YYINT yycheck[] = {                         10,
   10,   40,  265,  265,   10,   10,   45,   40,   10,  259,
   10,   10,   45,   10,   10,   10,   10,   10,   37,   10,
   10,   10,   10,   42,   10,   -1,   37,   38,   47,   -1,
   -1,   42,   43,   10,   45,   -1,   47,   37,   38,   41,
   -1,   -1,   42,   43,   10,   45,   -1,   47,   37,   38,
   41,   -1,   38,   42,   43,   41,   45,   43,   47,   45,
   37,   38,   61,   -1,   41,   42,   43,   10,   45,   10,
   47,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   94,   -1,   -1,   -1,  126,   10,   -1,
   -1,   -1,   94,  126,   94,   38,   37,   38,   41,   -1,
   41,   42,   43,   10,   45,   94,   47,   -1,   94,   10,
   -1,   -1,   -1,  124,   -1,   37,   38,   94,   -1,   41,
   42,   43,  124,   45,  124,   47,   -1,   -1,   94,   10,
   -1,   38,   -1,  124,   41,  124,   37,   38,  124,   -1,
   41,   42,   43,   10,   45,   -1,   47,  124,   -1,   -1,
   -1,   94,   -1,   94,   -1,   -1,   37,   38,  124,   -1,
   41,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   38,   94,   -1,   41,   -1,   43,   -1,   45,   -1,
   -1,  124,   -1,  124,   37,   38,   -1,   94,   -1,   42,
   43,   -1,   45,   94,   47,   37,   38,   -1,   -1,   41,
   42,   43,  124,   45,   -1,   47,   37,   38,   -1,   -1,
   -1,   42,   43,   94,   45,   -1,   47,  124,  257,  258,
   -1,   -1,   -1,  124,  257,  258,  265,   94,   -1,  262,
  263,  264,  265,  266,  267,  268,  269,  270,  271,   -1,
  259,   94,   -1,  124,   -1,   -1,   -1,  257,  259,  260,
  261,  257,   94,   -1,   -1,   -1,   -1,  124,   -1,  259,
  260,  261,   -1,   94,   -1,   -1,   -1,   -1,   -1,   -1,
  259,  260,  261,   -1,  260,  261,   -1,   -1,   -1,   -1,
   37,   38,  124,  260,  261,   42,   43,   -1,   45,   -1,
   47,   37,   -1,  124,  260,  261,   42,   43,   37,   45,
   10,   47,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  260,  261,  260,
  261,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,   -1,
   -1,   41,    6,   -1,   -1,   -1,   -1,   -1,  260,  261,
   14,   15,   16,   -1,   -1,   -1,   -1,   -1,   -1,   23,
   -1,   -1,   -1,  260,  261,   -1,   -1,   -1,   -1,  260,
  261,   -1,   36,   37,   38,   39,   40,   41,   42,   43,
   44,   45,   46,   -1,   -1,   -1,   -1,   -1,   -1,  260,
  261,   -1,   -1,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  260,  261,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  259,  260,  261,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,  259,  260,  261,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  259,  260,
  261,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  259,  260,  261,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  259,  260,  261,   -1,   -1,   -1,   -1,
  259,
};
#if YYBTYACC
static const YYINT yyctable[] = {                        -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
};
#endif
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 272
#define YYUNDFTOKEN 277
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"$end",0,0,0,0,0,0,0,0,0,"'\\n'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
0,0,0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"error","INTEIRO","REAL","POTENCIA","BSLEFT","BSRIGHT",
"INCREMENTO","DECREMENTO","CASTINT","VARIAVEL","CLEAR","CLEARINT","CLEARREAL",
"LIST","LISTINT","LISTREAL","UMINUS","$accept","inicio","var_id","expr",
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : inicio",
"inicio :",
"inicio : inicio expr '\\n'",
"inicio : inicio CASTINT expr '\\n'",
"inicio : inicio VARIAVEL '=' expr '\\n'",
"inicio : inicio VARIAVEL '\\n'",
"inicio : inicio INCREMENTO VARIAVEL '\\n'",
"inicio : inicio DECREMENTO VARIAVEL '\\n'",
"inicio : inicio CLEAR '\\n'",
"inicio : inicio CLEAR INTEIRO '\\n'",
"inicio : inicio CLEARINT '\\n'",
"inicio : inicio CLEARREAL '\\n'",
"inicio : inicio LIST '\\n'",
"inicio : inicio LIST INTEIRO '\\n'",
"inicio : inicio LISTINT '\\n'",
"inicio : inicio LISTREAL '\\n'",
"var_id : VARIAVEL",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr POTENCIA expr",
"expr : expr '%' expr",
"expr : expr '^' expr",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : expr BSRIGHT expr",
"expr : expr BSLEFT expr",
"expr : '~' expr",
"expr : '-' expr",
"expr : '(' expr ')'",
"expr : INTEIRO",
"expr : REAL",
"expr : var_id",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
YYLTYPE  yyloc; /* position returned by actions */
YYLTYPE  yylloc; /* position from the lexer */
#endif

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
#ifndef YYLLOC_DEFAULT
#define YYLLOC_DEFAULT(loc, rhs, n) \
do \
{ \
    if (n == 0) \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 0).last_line; \
        (loc).first_column = YYRHSLOC(rhs, 0).last_column; \
        (loc).last_line    = YYRHSLOC(rhs, 0).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, 0).last_column; \
    } \
    else \
    { \
        (loc).first_line   = YYRHSLOC(rhs, 1).first_line; \
        (loc).first_column = YYRHSLOC(rhs, 1).first_column; \
        (loc).last_line    = YYRHSLOC(rhs, n).last_line; \
        (loc).last_column  = YYRHSLOC(rhs, n).last_column; \
    } \
} while (0)
#endif /* YYLLOC_DEFAULT */
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#if YYBTYACC

#ifndef YYLVQUEUEGROWTH
#define YYLVQUEUEGROWTH 32
#endif
#endif /* YYBTYACC */

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#ifndef YYINITSTACKSIZE
#define YYINITSTACKSIZE 200
#endif

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  *p_base;
    YYLTYPE  *p_mark;
#endif
} YYSTACKDATA;
#if YYBTYACC

struct YYParseState_s
{
    struct YYParseState_s *save;    /* Previously saved parser state */
    YYSTACKDATA            yystack; /* saved parser stack */
    int                    state;   /* saved parser state */
    int                    errflag; /* saved error recovery status */
    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */
    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */
};
typedef struct YYParseState_s YYParseState;
#endif /* YYBTYACC */
/* variables for the parser stack */
static YYSTACKDATA yystack;
#if YYBTYACC

/* Current parser state */
static YYParseState *yyps = 0;

/* yypath != NULL: do the full parse, starting at *yypath parser state. */
static YYParseState *yypath = 0;

/* Base of the lexical value queue */
static YYSTYPE *yylvals = 0;

/* Current position at lexical value queue */
static YYSTYPE *yylvp = 0;

/* End position of lexical value queue */
static YYSTYPE *yylve = 0;

/* The last allocated position at the lexical value queue */
static YYSTYPE *yylvlim = 0;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
/* Base of the lexical position queue */
static YYLTYPE *yylpsns = 0;

/* Current position at lexical position queue */
static YYLTYPE *yylpp = 0;

/* End position of lexical position queue */
static YYLTYPE *yylpe = 0;

/* The last allocated position at the lexical position queue */
static YYLTYPE *yylplim = 0;
#endif

/* Current position at lexical token queue */
static YYINT  *yylexp = 0;

static YYINT  *yylexemes = 0;
#endif /* YYBTYACC */
#line 465 "calculos.y"


extern int yylex();
extern int yyerror(char *s);
#line 538 "y.tab.c"

/* For use in generated program */
#define yydepth (int)(yystack.s_mark - yystack.s_base)
#if YYBTYACC
#define yytrial (yyps->save)
#endif /* YYBTYACC */

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE *newps;
#endif

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));
    if (newps == 0)
        return YYENOMEM;

    data->p_base = newps;
    data->p_mark = newps + i;
#endif

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;

#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%sdebug: stack size increased to %d\n", YYPREFIX, newsize);
#endif
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    free(data->p_base);
#endif
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif /* YYPURE || defined(YY_NO_LEAKS) */
#if YYBTYACC

static YYParseState *
yyNewState(unsigned size)
{
    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));
    if (p == NULL) return NULL;

    p->yystack.stacksize = size;
    if (size == 0)
    {
        p->yystack.s_base = NULL;
        p->yystack.l_base = NULL;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        p->yystack.p_base = NULL;
#endif
        return p;
    }
    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));
    if (p->yystack.s_base == NULL) return NULL;
    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));
    if (p->yystack.l_base == NULL) return NULL;
    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));
    if (p->yystack.p_base == NULL) return NULL;
    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));
#endif

    return p;
}

static void
yyFreeState(YYParseState *p)
{
    yyfreestack(&p->yystack);
    free(p);
}
#endif /* YYBTYACC */

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab
#if YYBTYACC
#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)
#define YYVALID_NESTED do { if (yyps->save && \
                                yyps->save->save == 0) goto yyvalid; } while(0)
#endif /* YYBTYACC */

int
YYPARSE_DECL()
{
    int yym, yyn, yystate, yyresult;
#if YYBTYACC
    int yynewerrflag;
    YYParseState *yyerrctx = NULL;
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    YYLTYPE  yyerror_loc_range[3]; /* position of error start/end (0 unused) */
#endif
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
    if (yydebug)
        fprintf(stderr, "%sdebug[<# of symbols on state stack>]\n", YYPREFIX);
#endif
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));
#endif

#if YYBTYACC
    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;
    yyps->save = 0;
#endif /* YYBTYACC */
    yym = 0;
    /* yyn is set below */
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base;
#endif
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
#if YYBTYACC
        do {
        if (yylvp < yylve)
        {
            /* we're currently re-reading tokens */
            yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc = *yylpp++;
#endif
            yychar = *yylexp++;
            break;
        }
        if (yyps->save)
        {
            /* in trial mode; save scanner results for future parse attempts */
            if (yylvp == yylvlim)
            {   /* Enlarge lexical value queue */
                size_t p = (size_t) (yylvp - yylvals);
                size_t s = (size_t) (yylvlim - yylvals);

                s += YYLVQUEUEGROWTH;
                if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;
                if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;
#endif
                yylvp   = yylve = yylvals + p;
                yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp   = yylpe = yylpsns + p;
                yylplim = yylpsns + s;
#endif
                yylexp  = yylexemes + p;
            }
            *yylexp = (YYINT) YYLEX;
            *yylvp++ = yylval;
            yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *yylpp++ = yylloc;
            yylpe++;
#endif
            yychar = *yylexp++;
            break;
        }
        /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
        yychar = YYLEX;
#if YYBTYACC
        } while (0);
#endif /* YYBTYACC */
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, " <%s>", YYSTYPE_TOSTRING(yychar, yylval));
#endif
            fputc('\n', stderr);
        }
#endif
    }
#if YYBTYACC

    /* Do we have a conflict? */
    if (((yyn = yycindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
        yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        YYINT ctry;

        if (yypath)
        {
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: CONFLICT in state %d: following successful trial parse\n",
                                YYDEBUGSTR, yydepth, yystate);
#endif
            /* Switch to the next conflict context */
            save = yypath;
            yypath = save->save;
            save->save = NULL;
            ctry = save->ctry;
            if (save->state != yystate) YYABORT;
            yyFreeState(save);

        }
        else
        {

            /* Unresolved conflict - start/continue trial parse */
            YYParseState *save;
#if YYDEBUG
            if (yydebug)
            {
                fprintf(stderr, "%s[%d]: CONFLICT in state %d. ", YYDEBUGSTR, yydepth, yystate);
                if (yyps->save)
                    fputs("ALREADY in conflict, continuing trial parse.\n", stderr);
                else
                    fputs("Starting trial parse.\n", stderr);
            }
#endif
            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (save == NULL) goto yyenomem;
            save->save            = yyps->save;
            save->state           = yystate;
            save->errflag         = yyerrflag;
            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            ctry                  = yytable[yyn];
            if (yyctable[ctry] == -1)
            {
#if YYDEBUG
                if (yydebug && yychar >= YYEOF)
                    fprintf(stderr, "%s[%d]: backtracking 1 token\n", YYDEBUGSTR, yydepth);
#endif
                ctry++;
            }
            save->ctry = ctry;
            if (yyps->save == NULL)
            {
                /* If this is a first conflict in the stack, start saving lexemes */
                if (!yylexemes)
                {
                    yylexemes = (YYINT *) malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));
                    if (yylexemes == NULL) goto yyenomem;
                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));
                    if (yylvals == NULL) goto yyenomem;
                    yylvlim   = yylvals + YYLVQUEUEGROWTH;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));
                    if (yylpsns == NULL) goto yyenomem;
                    yylplim   = yylpsns + YYLVQUEUEGROWTH;
#endif
                }
                if (yylvp == yylve)
                {
                    yylvp  = yylve = yylvals;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp  = yylpe = yylpsns;
#endif
                    yylexp = yylexemes;
                    if (yychar >= YYEOF)
                    {
                        *yylve++ = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                        *yylpe++ = yylloc;
#endif
                        *yylexp  = (YYINT) yychar;
                        yychar   = YYEMPTY;
                    }
                }
            }
            if (yychar >= YYEOF)
            {
                yylvp--;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp--;
#endif
                yylexp--;
                yychar = YYEMPTY;
            }
            save->lexeme = (int) (yylvp - yylvals);
            yyps->save   = save;
        }
        if (yytable[yyn] == ctry)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);
#endif
            if (yychar < 0)
            {
                yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylpp++;
#endif
                yylexp++;
            }
            if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                goto yyoverflow;
            yystate = yyctable[ctry];
            *++yystack.s_mark = (YYINT) yystate;
            *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            *++yystack.p_mark = yylloc;
#endif
            yychar  = YYEMPTY;
            if (yyerrflag > 0) --yyerrflag;
            goto yyloop;
        }
        else
        {
            yyn = yyctable[ctry];
            goto yyreduce;
        }
    } /* End of code dealing with conflicts */
#endif /* YYBTYACC */
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: state %d, shifting to state %d\n",
                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yylloc;
#endif
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;
#if YYBTYACC

    yynewerrflag = 1;
    goto yyerrhandler;
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */

yyerrlab:
    /* explicit YYERROR from an action -- pop the rhs of the rule reduced
     * before looking for error recovery */
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif

    yynewerrflag = 0;
yyerrhandler:
    while (yyps->save)
    {
        int ctry;
        YYParseState *save = yyps->save;
#if YYDEBUG
        if (yydebug)
            fprintf(stderr, "%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\n",
                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,
                    (int)(yylvp - yylvals - yyps->save->lexeme));
#endif
        /* Memorize most forward-looking error state in case it's really an error. */
        if (yyerrctx == NULL || yyerrctx->lexeme < yylvp - yylvals)
        {
            /* Free old saved error context state */
            if (yyerrctx) yyFreeState(yyerrctx);
            /* Create and fill out new saved error context state */
            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));
            if (yyerrctx == NULL) goto yyenomem;
            yyerrctx->save           = yyps->save;
            yyerrctx->state          = yystate;
            yyerrctx->errflag        = yyerrflag;
            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);
            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);
            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);
            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yyerrctx->lexeme         = (int) (yylvp - yylvals);
        }
        yylvp          = yylvals   + save->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yylpp          = yylpsns   + save->lexeme;
#endif
        yylexp         = yylexemes + save->lexeme;
        yychar         = YYEMPTY;
        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);
        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);
        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);
        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
        ctry           = ++save->ctry;
        yystate        = save->state;
        /* We tried shift, try reduce now */
        if ((yyn = yyctable[ctry]) >= 0) goto yyreduce;
        yyps->save     = save->save;
        save->save     = NULL;
        yyFreeState(save);

        /* Nothing left on the stack -- error */
        if (!yyps->save)
        {
#if YYDEBUG
            if (yydebug)
                fprintf(stderr, "%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\n",
                                YYPREFIX, yydepth);
#endif
            /* Restore state as it was in the most forward-advanced error */
            yylvp          = yylvals   + yyerrctx->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylpp          = yylpsns   + yyerrctx->lexeme;
#endif
            yylexp         = yylexemes + yyerrctx->lexeme;
            yychar         = yylexp[-1];
            yylval         = yylvp[-1];
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yylloc         = yylpp[-1];
#endif
            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);
            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);
            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);
            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
            yystate        = yyerrctx->state;
            yyFreeState(yyerrctx);
            yyerrctx       = NULL;
        }
        yynewerrflag = 1;
    }
    if (yynewerrflag == 0) goto yyinrecovery;
#endif /* YYBTYACC */

    YYERROR_CALL("syntax error");
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yyerror_loc_range[1] = yylloc; /* lookahead position is error start position */
#endif

#if !YYBTYACC
    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
#endif
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: state %d, error recovery shifting to state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* lookahead position is error end position */
                yyerror_loc_range[2] = yylloc;
                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */
                *++yystack.p_mark = yyloc;
#endif
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    fprintf(stderr, "%s[%d]: error recovery discarding state %d\n",
                                    YYDEBUGSTR, yydepth, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                /* the current TOS position is the error start position */
                yyerror_loc_range[1] = *yystack.p_mark;
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
                if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);
#else
                    YYDESTRUCT_CALL("error: discarding state",
                                    yystos[*yystack.s_mark], yystack.l_mark);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
                --yystack.s_mark;
                --yystack.l_mark;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                --yystack.p_mark;
#endif
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            fprintf(stderr, "%s[%d]: state %d, error recovery discarding token %d (%s)\n",
                            YYDEBUGSTR, yydepth, yystate, yychar, yys);
        }
#endif
#if defined(YYDESTRUCT_CALL)
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval, &yylloc);
#else
            YYDESTRUCT_CALL("error: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
#endif /* defined(YYDESTRUCT_CALL) */
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
    yym = yylen[yyn];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: state %d, reducing by rule %d (%s)",
                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            if (yym > 0)
            {
                int i;
                fputc('<', stderr);
                for (i = yym; i > 0; i--)
                {
                    if (i != yym) fputs(", ", stderr);
                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],
                                           yystack.l_mark[1-i]), stderr);
                }
                fputc('>', stderr);
            }
#endif
        fputc('\n', stderr);
    }
#endif
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)

    /* Perform position reduction */
    memset(&yyloc, 0, sizeof(yyloc));
#if YYBTYACC
    if (!yytrial)
#endif /* YYBTYACC */
    {
        YYLLOC_DEFAULT(yyloc, &yystack.p_mark[-yym], yym);
        /* just in case YYERROR is invoked within the action, save
           the start of the rhs as the error start position */
        yyerror_loc_range[1] = yystack.p_mark[1-yym];
    }
#endif

    switch (yyn)
    {
case 1:
#line 52 "calculos.y"
	{ yyval.i = 0; }
#line 1211 "y.tab.c"
break;
case 2:
#line 54 "calculos.y"
	{ yyval.i = 0;
				  if(expr[yystack.l_mark[-1].i].type == 0) {
					printf("Resultado: %d\n", expr[yystack.l_mark[-1].i].i);
				  }
				  else {
					printf("Resultado: %f\n", expr[yystack.l_mark[-1].i].d);
				  }
				}
#line 1223 "y.tab.c"
break;
case 3:
#line 63 "calculos.y"
	{ yyval.i = 0;
				  if(expr[yystack.l_mark[-1].i].type == 0) {
					printf("Resultado: %d\n", expr[yystack.l_mark[-1].i].i);
				  }
				  else {
					printf("Resultado: %d\n", (int) expr[yystack.l_mark[-1].i].d);
				  }
				}
#line 1235 "y.tab.c"
break;
case 4:
#line 72 "calculos.y"
	{ yyval.i = 0;
				  if(expr[yystack.l_mark[-1].i].type == 0) {
					strcpy(regvar[count].name, yystack.l_mark[-3].s);
					regvar[count].i = expr[yystack.l_mark[-1].i].i;
					regvar[count].type = 0;
					printf("\t%d\n", regvar[count].i);
				  }
				  else {
					strcpy(regvar[count].name, yystack.l_mark[-3].s);
					regvar[count].d = expr[yystack.l_mark[-1].i].d;
					regvar[count].type = 1;
					printf("\t%f\n", regvar[count].d);
				  }
				  count++;
				}
#line 1254 "y.tab.c"
break;
case 5:
#line 88 "calculos.y"
	{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, yystack.l_mark[-1].s) == 0) {
						printf("id %d - Nome: %s | ", i, regvar[i].name);
						if(regvar[i].type == 0) {
							printf("Tipo: INT | Valor: %d\n", regvar[i].i);
						}
						else {
							printf("Tipo: REAL | Valor: %f\n", regvar[i].d);
						}
						break;
					}
				  }
				}
#line 1271 "y.tab.c"
break;
case 6:
#line 102 "calculos.y"
	{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, yystack.l_mark[-1].s) == 0) {
						if(regvar[i].type == 0) {
							regvar[i].i++;
							printf("%d\n", regvar[i].i);
						}
						else {
							regvar[i].d++;
							printf("%f\n", regvar[i].d);
						}
						break;
					}
				  }
				}
#line 1289 "y.tab.c"
break;
case 7:
#line 117 "calculos.y"
	{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, yystack.l_mark[-1].s) == 0) {
						if(regvar[i].type == 0) {
							regvar[i].i--;
							printf("%d\n", regvar[i].i);
						}
						else {
							regvar[i].d--;
							printf("%f\n", regvar[i].d);
						}
						break;
					}
				  }
				}
#line 1307 "y.tab.c"
break;
case 8:
#line 132 "calculos.y"
	{ yyval.i = 0; count = 0; }
#line 1312 "y.tab.c"
break;
case 9:
#line 134 "calculos.y"
	{ yyval.i = 0; count--;
				  memmove(&regvar[yystack.l_mark[-1].i], &regvar[yystack.l_mark[-1].i + 1], (count - yystack.l_mark[-1].i) * sizeof(struct var));
				}
#line 1319 "y.tab.c"
break;
case 10:
#line 138 "calculos.y"
	{ yyval.i = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 0) {
						count--;
						memmove(&regvar[i], &regvar[i + 1], (count - i) * sizeof(struct var));
						i--;
					}
				  }
				}
#line 1332 "y.tab.c"
break;
case 11:
#line 148 "calculos.y"
	{ yyval.i = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 1) {
						count--;
						memmove(&regvar[i], &regvar[i + 1], (count - i) * sizeof(struct var));
						i--;
					}
				  }
				}
#line 1345 "y.tab.c"
break;
case 12:
#line 158 "calculos.y"
	{ yyval.i = 0;
				  for(int i = 0; i < count; i++) {
					printf("id %d - Nome: %s | ", i, regvar[i].name);
					if(regvar[i].type == 0) {
						printf("Tipo: INT | Valor: %d\n", regvar[i].i);
					}
					else {
						printf("Tipo: REAL | Valor: %f\n", regvar[i].d);
					}
				  }
				}
#line 1360 "y.tab.c"
break;
case 13:
#line 170 "calculos.y"
	{ yyval.i = 0;
				  printf("id %d - Nome: %s | ", yystack.l_mark[-1].i, regvar[yystack.l_mark[-1].i].name);
					if(regvar[yystack.l_mark[-1].i].type == 0) {
						printf("Tipo: INT | Valor: %d\n", regvar[yystack.l_mark[-1].i].i);
					}
					else {
						printf("Tipo: REAL | Valor: %f\n", regvar[yystack.l_mark[-1].i].d);
					}
				}
#line 1373 "y.tab.c"
break;
case 14:
#line 180 "calculos.y"
	{ yyval.i = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 0) {
						printf("id %d - Nome: %s=%d\n", i, regvar[i].name, regvar[i].i);
					}
				  }
				}
#line 1384 "y.tab.c"
break;
case 15:
#line 188 "calculos.y"
	{ yyval.i = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 1) {
						printf("id %d - Nome: %s=%f\n", i, regvar[i].name, regvar[i].d);
					}
				  }
				}
#line 1395 "y.tab.c"
break;
case 16:
#line 198 "calculos.y"
	{ for(int i = 0; i < count; i++) {
				if(strcmp(regvar[i].name, yystack.l_mark[0].s) == 0) {
					yyval.i = i;
					break;
				}
			  }
			}
#line 1406 "y.tab.c"
break;
case 17:
#line 208 "calculos.y"
	{ if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i + expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 1) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].i + expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 1 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d + expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d + expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
#line 1435 "y.tab.c"
break;
case 18:
#line 234 "calculos.y"
	{ if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i - expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 1) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].i - expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 1 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d - expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d - expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
#line 1464 "y.tab.c"
break;
case 19:
#line 260 "calculos.y"
	{ if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i * expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 1) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].i * expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 1 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d * expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d * expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
#line 1493 "y.tab.c"
break;
case 20:
#line 286 "calculos.y"
	{ if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i / expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 1) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].i / expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 1 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d / expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					yyval.i = count_expr;
					expr[count_expr].d = expr[yystack.l_mark[-2].i].d / expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
#line 1522 "y.tab.c"
break;
case 21:
#line 312 "calculos.y"
	{ if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = pow(expr[yystack.l_mark[-2].i].i, expr[yystack.l_mark[0].i].i);
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 1) {
					yyval.i = count_expr;
					expr[count_expr].d = pow(expr[yystack.l_mark[-2].i].i, expr[yystack.l_mark[0].i].d);
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[yystack.l_mark[-2].i].type == 1 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].d = pow(expr[yystack.l_mark[-2].i].d, expr[yystack.l_mark[0].i].i);
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					yyval.i = count_expr;
					expr[count_expr].d = pow(expr[yystack.l_mark[-2].i].d, expr[yystack.l_mark[0].i].d);
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
#line 1551 "y.tab.c"
break;
case 22:
#line 338 "calculos.y"
	{ if (expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i % expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary %");
					exit(1);
				  }
				}
#line 1566 "y.tab.c"
break;
case 23:
#line 350 "calculos.y"
	{ if (expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = pow(expr[yystack.l_mark[-2].i].i, expr[yystack.l_mark[0].i].i);
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary ^");
					exit(1);
				  }
				}
#line 1581 "y.tab.c"
break;
case 24:
#line 362 "calculos.y"
	{ if (expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i | expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary |");
					/*exit(1);*/
				  }
				}
#line 1596 "y.tab.c"
break;
case 25:
#line 374 "calculos.y"
	{ if (expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i & expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary &");
					exit(1);
				  }
				}
#line 1611 "y.tab.c"
break;
case 26:
#line 386 "calculos.y"
	{ if (expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i >> expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary >>");
					exit(1);
				  }
				}
#line 1626 "y.tab.c"
break;
case 27:
#line 398 "calculos.y"
	{ if (expr[yystack.l_mark[-2].i].type == 0 && expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = expr[yystack.l_mark[-2].i].i << expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary <<");
					exit(1);
				  }
				}
#line 1641 "y.tab.c"
break;
case 28:
#line 410 "calculos.y"
	{ if (expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = ~expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operand to binary ~");
					exit(1);
				  }
				}
#line 1656 "y.tab.c"
break;
case 29:
#line 422 "calculos.y"
	{ if (expr[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = -expr[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyval.i = count_expr;
					expr[count_expr].d = -expr[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
#line 1673 "y.tab.c"
break;
case 30:
#line 436 "calculos.y"
	{ yyval.i = (yystack.l_mark[-1].i); }
#line 1678 "y.tab.c"
break;
case 31:
#line 438 "calculos.y"
	{ yyval.i = count_expr;
				  expr[count_expr].i = yystack.l_mark[0].i;
				  expr[count_expr].type = 0;
				  count_expr++;
				}
#line 1687 "y.tab.c"
break;
case 32:
#line 444 "calculos.y"
	{ yyval.i = count_expr;
				  expr[count_expr].d = yystack.l_mark[0].d;
				  expr[count_expr].type = 1;
				  count_expr++;
				}
#line 1696 "y.tab.c"
break;
case 33:
#line 450 "calculos.y"
	{ if(regvar[yystack.l_mark[0].i].type == 0) {
					yyval.i = count_expr;
					expr[count_expr].i = regvar[yystack.l_mark[0].i].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyval.i = count_expr;
					expr[count_expr].d = regvar[yystack.l_mark[0].i].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
#line 1713 "y.tab.c"
break;
#line 1715 "y.tab.c"
    default:
        break;
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark -= yym;
#endif
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
        {
            fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
            if (!yytrial)
#endif /* YYBTYACC */
                fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));
#endif
            fprintf(stderr, "shifting from state 0 to final state %d\n", YYFINAL);
        }
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        *++yystack.p_mark = yyloc;
#endif
        if (yychar < 0)
        {
#if YYBTYACC
            do {
            if (yylvp < yylve)
            {
                /* we're currently re-reading tokens */
                yylval = *yylvp++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                yylloc = *yylpp++;
#endif
                yychar = *yylexp++;
                break;
            }
            if (yyps->save)
            {
                /* in trial mode; save scanner results for future parse attempts */
                if (yylvp == yylvlim)
                {   /* Enlarge lexical value queue */
                    size_t p = (size_t) (yylvp - yylvals);
                    size_t s = (size_t) (yylvlim - yylvals);

                    s += YYLVQUEUEGROWTH;
                    if ((yylexemes = (YYINT *)realloc(yylexemes, s * sizeof(YYINT))) == NULL)
                        goto yyenomem;
                    if ((yylvals   = (YYSTYPE *)realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)
                        goto yyenomem;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    if ((yylpsns   = (YYLTYPE *)realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)
                        goto yyenomem;
#endif
                    yylvp   = yylve = yylvals + p;
                    yylvlim = yylvals + s;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                    yylpp   = yylpe = yylpsns + p;
                    yylplim = yylpsns + s;
#endif
                    yylexp  = yylexemes + p;
                }
                *yylexp = (YYINT) YYLEX;
                *yylvp++ = yylval;
                yylve++;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
                *yylpp++ = yylloc;
                yylpe++;
#endif
                yychar = *yylexp++;
                break;
            }
            /* normal operation, no conflict encountered */
#endif /* YYBTYACC */
            yychar = YYLEX;
#if YYBTYACC
            } while (0);
#endif /* YYBTYACC */
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                fprintf(stderr, "%s[%d]: state %d, reading token %d (%s)\n",
                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
    {
        fprintf(stderr, "%s[%d]: after reduction, ", YYDEBUGSTR, yydepth);
#ifdef YYSTYPE_TOSTRING
#if YYBTYACC
        if (!yytrial)
#endif /* YYBTYACC */
            fprintf(stderr, "result is <%s>, ", YYSTYPE_TOSTRING(yystos[yystate], yyval));
#endif
        fprintf(stderr, "shifting from state %d to state %d\n", *yystack.s_mark, yystate);
    }
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    *++yystack.p_mark = yyloc;
#endif
    goto yyloop;
#if YYBTYACC

    /* Reduction declares that this path is valid. Set yypath and do a full parse */
yyvalid:
    if (yypath) YYABORT;
    while (yyps->save)
    {
        YYParseState *save = yyps->save;
        yyps->save = save->save;
        save->save = yypath;
        yypath = save;
    }
#if YYDEBUG
    if (yydebug)
        fprintf(stderr, "%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\n",
                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));
#endif
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    yylvp          = yylvals + yypath->lexeme;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yylpp          = yylpsns + yypath->lexeme;
#endif
    yylexp         = yylexemes + yypath->lexeme;
    yychar         = YYEMPTY;
    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);
    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));
    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);
    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);
    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));
#endif
    yystate        = yypath->state;
    goto yyloop;
#endif /* YYBTYACC */

yyoverflow:
    YYERROR_CALL("yacc stack overflow");
#if YYBTYACC
    goto yyabort_nomem;
yyenomem:
    YYERROR_CALL("memory exhausted");
yyabort_nomem:
#endif /* YYBTYACC */
    yyresult = 2;
    goto yyreturn;

yyabort:
    yyresult = 1;
    goto yyreturn;

yyaccept:
#if YYBTYACC
    if (yyps->save) goto yyvalid;
#endif /* YYBTYACC */
    yyresult = 0;

yyreturn:
#if defined(YYDESTRUCT_CALL)
    if (yychar != YYEOF && yychar != YYEMPTY)
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval, &yylloc);
#else
        YYDESTRUCT_CALL("cleanup: discarding token", yychar, &yylval);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */

    {
        YYSTYPE *pv;
#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)
        YYLTYPE *pp;

        for (pv = yystack.l_base, pp = yystack.p_base; pv <= yystack.l_mark; ++pv, ++pp)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);
#else
        for (pv = yystack.l_base; pv <= yystack.l_mark; ++pv)
             YYDESTRUCT_CALL("cleanup: discarding state",
                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);
#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */
    }
#endif /* defined(YYDESTRUCT_CALL) */

#if YYBTYACC
    if (yyerrctx)
    {
        yyFreeState(yyerrctx);
        yyerrctx = NULL;
    }
    while (yyps)
    {
        YYParseState *save = yyps;
        yyps = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
    while (yypath)
    {
        YYParseState *save = yypath;
        yypath = save->save;
        save->save = NULL;
        yyFreeState(save);
    }
#endif /* YYBTYACC */
    yyfreestack(&yystack);
    return (yyresult);
}
