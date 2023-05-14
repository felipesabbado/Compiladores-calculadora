#ifndef _yy_defines_h_
#define _yy_defines_h_

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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
	int i;
	double d;
	char *s;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
