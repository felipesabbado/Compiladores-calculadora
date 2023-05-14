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

struct var expr[256];
int count_expr = 0;
struct var regvar[128];
int count = 0;
%}

%union {
	int i;
	double d;
	char *s;
}

%token	<i>	INTEIRO
%token	<d>	REAL
%token	<s> POTENCIA
%token	<s> BSLEFT BSRIGHT
%token	<s> INCREMENTO DECREMENTO
%token	<s> CASTINT
%token	<s>	VARIAVEL

%type	<i> var_id inicio expr

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
				  if(expr[$2].type == 0) {
					printf("Resultado: %d\n", expr[$2].i);
				  }
				  else {
					printf("Resultado: %f\n", expr[$2].d);
				  }
				}
		|	inicio CASTINT expr '\n'
				{ $$ = 0;
				  if(expr[$3].type == 0) {
					printf("Resultado: %d\n", expr[$3].i);
				  }
				  else {
					printf("Resultado: %d\n", (int) expr[$3].d);
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
			  }
			}
		;
		
expr:		expr '+' expr
				{ if(expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i + expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[$1].type == 0 && expr[$3].type == 1) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].i + expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[$1].type == 1 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d + expr[$3].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d + expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		|	INTEIRO
				{ $$ = count_expr;
				  expr[count_expr].i = $1;
				  expr[count_expr].type = 0;
				  count_expr++;
				}
		|	REAL
				{ $$ = count_expr;
				  expr[count_expr].d = $1;
				  expr[count_expr].type = 1;
				  count_expr++;
				}
		|	var_id
				{ if(regvar[$1].type == 0) {
					$$ = count_expr;
					expr[count_expr].id = count_expr;
					expr[count_expr].i = regvar[$1].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].id = count_expr;
					expr[count_expr].d = regvar[$1].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		;

%%

extern int yylex();
extern int yyerror(char *s);
