%token	<i>	INTEIRO
%token	<d>	REAL
%token	<s> POTENCIA
%token	<s> BSLEFT BSRIGHT
%token	<s> INCREMENTO DECREMENTO
%token	<s> CASTINT
%token	<s>	VARIAVEL

%type	<i> int var_id
%type	<d>	expr real var

%{
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct var {
	int id;
	int type;
	char name[20];
	double value;
} NUMBER;

NUMBER regvar[128];
int count = 0;
%}

%union {
	int i;
	double d;
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

expr:	
				{ $$ = 0; }
		|	expr int '\n'
				{ $$ = 0; printf("Resultado: %d\n", $2); }
		|	expr real '\n'
				{ $$ = 0; printf("Resultado: %f\n", $2); }
		|	expr CASTINT real '\n'
				{ $$ = 0; printf("Resultado: %d\n", (int) $3); }
		| 	expr VARIAVEL '=' int '\n'
				{ $$ = 0;
					strcpy(regvar[count].name, $2);
					regvar[count].value = $4;
					regvar[count].type = 0;
					regvar[count].id = count;
					printf("\t%d\n", (int) regvar[count].value);
					count++;
				}
		|	expr VARIAVEL '=' real '\n'
				{ $$ = 0;
					strcpy(regvar[count].name, $2);
					regvar[count].value = $4;
					regvar[count].type = 1;
					regvar[count].id = count;
					printf("\t%f\n", regvar[count].value);
					count++;
				}
		|	expr VARIAVEL '\n'
				{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, $2) == 0) {
						printf("Name: %s\n", regvar[i].name);
						if(regvar[i].type == 0) {
							printf("%d\n", (int) regvar[i].value);
						}
						else {
							printf("%f\n", regvar[i].value);
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

var:		var_id
				{ $$ = regvar[$1].value; }
		;

int:		int '|' int
				{ $$ = $1 | $3; }
		|	int '^' int
				{ $$ = $1 ^ $3; }
		|	int '&' int
				{ $$ = $1 & $3; }
		|	int BSLEFT int
				{ $$ = $1 << $3; }
		|	int BSRIGHT int
				{ $$ = $1 >> $3; }
		|	'~' int
				{ $$ = ~$2; }
		|	int '+' int
				{ $$ = $1 + $3; }
		|	int '-' int
				{ $$ = $1 - $3; }
		|	int '*' int
				{ $$ = $1 * $3; }
		|	int '/' int
				{ $$ = $1 / $3; }
		|	int '%' int
				{ $$ = $1 % $3; }
		|	'-' int %prec '~'
				{ $$ = -$2; }
		|	int INCREMENTO
				{ $$ = $1 + 1; }
		|	int DECREMENTO
				{ $$ = $1 - 1; }
		|	int POTENCIA int
				{ $$ = pow($1, $3); }
		|	'(' int ')'
				{ $$ = ($2); }
		|	INTEIRO
				{ $$ = $1; }
		|	var
				{ $$ = (int) $1; }
		;

real:		real '+' real
				{ $$ = $1 + $3; }
		|	real '-' real
				{ $$ = $1 - $3; }
		|	real '*' real
				{ $$ = $1 * $3; }
		|	real '/' real
				{ $$ = $1 / $3; }
		|	real POTENCIA real
				{ $$ = pow($1, $3); }
		|	real '+' int
				{ $$ = $1 + $3; }
		|	real '-' int
				{ $$ = $1 - $3; }
		|	real '*' int
				{ $$ = $1 * $3; }
		|	real '/' int
				{ $$ = $1 / $3; }
		|	real POTENCIA int
				{ $$ = pow($1, $3); }
		|	int '+' real
				{ $$ = $1 + $3; }
		|	int '-' real
				{ $$ = $1 - $3; }
		|	int '*' real
				{ $$ = $1 * $3; }
		|	int '/' real
				{ $$ = $1 / $3; }
		|	int POTENCIA real
				{ $$ = pow($1, $3); }
		|	'-' real %prec '~'
				{ $$ = -$2; }
		|	'(' real ')'
				{ $$ = ($2); }
		|	REAL
				{ $$ = $1; }
		|	var
				{ $$ = $1; }
		;

%%

extern int yylex();
extern int yyerror(char *s);
