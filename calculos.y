%token	<final_value> INTEIRO REAL
%token	<s> POTENCIA
%token	<s> BSLEFT BSRIGHT
%token	<s> INCREMENTO DECREMENTO
%token	<s> CASTINT
%token 	<s>	VARIAVEL

%type	<final_value>  program exp term

%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


typedef struct number {
	int id;
	char type;
	char name[20];
	union {
		int i;
		double d;
	} value;
} NUMBER;

char INT_TYPE = 1;
char FLOAT_TYPE = 2;
%}

%union {
	NUMBER final_value;
	char *s;
}

%right	'='
%left	'|'
%left	'^'
%left	'&'
%left	BSLEFT BSRIGHT
%left	'+' '-'
%left	'*' '/' '%'
%right	'~'
%left	INCREMENTO DECREMENTO
%right	POTENCIA

%%

program : exp { 
	if ($1.type == INT_TYPE)
		printf("%d\n", $1.value.i);
	else if ($1.type == FLOAT_TYPE)
		printf("%f\n", $1.value.d);
	else
		printf("error\n");
 }
		;

exp : exp '+' term {
	if ($1.type == INT_TYPE && $3.type == INT_TYPE)
   {
      $$.type = INT_TYPE;
      $$.value.i = $1.value.i + $3.value.i;
   }
   else if ($1.type == INT_TYPE && $3.type == FLOAT_TYPE)
   {
      // this is a sort of implicit conversion to float
      $$.type = FLOAT_TYPE; 
      $$.value.d = $1.value.i + $3.value.d;
   }
   else if ($1.type == FLOAT_TYPE && $3.type == INT_TYPE)
   {
	  // this is a sort of implicit conversion to float
	  $$.type = FLOAT_TYPE; 
	  $$.value.d = $1.value.d + $3.value.i;
   }
   else if ($1.type == FLOAT_TYPE && $3.type == FLOAT_TYPE)
   {
	  $$.type = FLOAT_TYPE;
	  $$.value.d = $1.value.d + $3.value.d;
   }
   else
   {
	  // error
   };
}

%%

extern int yylex()
{
   int c;
   while( (c=getchar()) == ' ');
   if( isdigit(c) )
   {
      ungetc(c, stdin);
      float f1;
      scanf("%f", &f1);
      int i1 = (int) f1;
      if(f1 == 0){
     	yylval.final_value.type = INT_TYPE;
     	yylval.final_value.value.i = 0;
	 }
      else if( (((float) i1) / f1 ) == 1)
      {
		yylval.final_value.value.i = i1;
		return INTEIRO;
      }
      else{
		yylval.final_value.value.d = f1;
		return REAL;
      }
      //scanf("%f",&yylval.final_value.value.d);
      //return(NUMBER);
   }
   if(c == '\n') return 0;
   return c;
}
extern int yyerror(char *s);
