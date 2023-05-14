%token	<i>	INTEIRO
%token	<d>	REAL
%token	<s> POTENCIA
%token	<s> BSLEFT BSRIGHT
%token	<s> INCREMENTO DECREMENTO
%token	<s> CASTINT
%token	<s>	VARIAVEL

%type	<i> var_id inicio
%type	<n> expr

%{
#include <stdio.h>
#include <math.h>
#include <string.h>

struct var {
	int id;
	int type;
	char name[20];
	union {
		int i;
		double d;
	};
};

struct var regvar[128];
int count = 0;
%}

%union {
	int i;
	double d;
	char *s;
	struct var n;
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

inicio:	
				{ $$ = 0; }
		|	inicio expr '\n'
				{ $$ = 0;
				  if($2.type == 0) {
					printf("Resultado: %d\n", $2.i);
				  }
				  else {
					printf("Resultado: %f\n", $2.d);
				  }
				}
		|	inicio CASTINT expr '\n'
				{ $$ = 0;
				  if($3.type == 0) {
					printf("Resultado: %d\n", $3.i);
				  }
				  else {
					printf("Resultado: %d\n", (int) $3.d);
				  }
				}
		| 	inicio VARIAVEL '=' INTEIRO '\n'
				{ $$ = 0;
				  strcpy(regvar[count].name, $2);
				  regvar[count].i = $4;
				  regvar[count].type = 0;
				  regvar[count].id = count;
				  printf("\t%d\n", regvar[count].i);
				  count++;
				}
		|	inicio VARIAVEL '=' REAL '\n'
				{ $$ = 0;
				  strcpy(regvar[count].name, $2);
				  regvar[count].d = $4;
				  regvar[count].type = 1;
				  regvar[count].id = count;
				  printf("\t%f\n", regvar[count].d);
				  count++;
				}
		|	inicio VARIAVEL '\n'
				{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, $2) == 0) {
						printf("Name: %s\n", regvar[i].name);
						if(regvar[i].type == 0) {
							printf("%d\n", regvar[i].i);
						}
						else {
							printf("%f\n", regvar[i].d);
						}
						break;
					}
				  }
				}
		;
		
var_id:		VARIAVEL
			{ for(int i = 0; i < count; i++) {
				if(strcmp(regvar[i].name, $1) == 0) {
					$$ = regvar[i].id;
					break;
				}
				else {
					yyerror("A variável non ecziste!");
				}
			  }
			}
		;
		
expr:		expr '+' expr
				{ if($1.type == 0 && $3.type == 0) {
					$$.type = 0;
					$$.i = $1.i + $3.i;
				  }
				  else if($1.type == 0 && $3.type == 1) {
					$$.type = 1;
					$$.d = $1.i + $3.d;
				  }
				  else if($1.type == 1 && $3.type == 0) {
					$$.type = 1;
					$$.d = $1.d + $3.i;
				  }
				  else {
					$$.type = 1;
					$$.d = $1.d + $3.d;
				  }
				}
		|	INTEIRO
				{ $$.i = $1; $$.type = 0; }
		|	REAL
				{ $$.d = $1; $$.type = 1; }
		|	var_id
				{ if(regvar[$1].type == 0) {
					$$.i = regvar[$1].i;
					$$.type = 0;
				  }
				  else {
					$$.d = regvar[$1].d;
					$$.type = 1;
				  }
				}
		;

%%

extern int yylex();
extern int yyerror(char *s);
