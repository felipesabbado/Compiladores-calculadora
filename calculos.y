%{
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
%token	<s>	CLEAR CLEARINT CLEARREAL LIST LISTINT LISTREAL
%token	<s>	ESPACO

%type	<i> var_id inicio expr
%type	<s> lines

%right	'=' 
%left	'|' 
%left	'^'
%left	'&' 
%left	BSLEFT BSRIGHT
%left	'+' '-'
%left	'*' '/' '%'
%right	'~' UMINUS
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
		|	inicio VARIAVEL '=' expr '\n'
				{ $$ = 0;
				  if(expr[$4].type == 0) {
					strcpy(regvar[count].name, $2);
					regvar[count].i = expr[$4].i;
					regvar[count].type = 0;
					printf("\t%d\n", regvar[count].i);
				  }
				  else {
					strcpy(regvar[count].name, $2);
					regvar[count].d = expr[$4].d;
					regvar[count].type = 1;
					printf("\t%f\n", regvar[count].d);
				  }
				  count++;
				}
		|	inicio VARIAVEL '\n'
				{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, $2) == 0) {
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
		|	inicio INCREMENTO VARIAVEL '\n'
				{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, $3) == 0) {
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
		|	inicio DECREMENTO VARIAVEL '\n'
				{ for(int i = 0; i < count; i++) {
					if(strcmp(regvar[i].name, $3) == 0) {
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
		|	inicio CLEAR '\n'
				{ $$ = 0; count = 0; }
		|	inicio CLEAR INTEIRO '\n'
				{ $$ = 0; count--;
				  memmove(&regvar[$3], &regvar[$3 + 1], (count - $3) * sizeof(struct var));
				}
		|	inicio CLEARINT '\n'
				{ $$ = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 0) {
						count--;
						memmove(&regvar[i], &regvar[i + 1], (count - i) * sizeof(struct var));
						i--;
					}
				  }
				}
		|	inicio CLEARREAL '\n'
				{ $$ = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 1) {
						count--;
						memmove(&regvar[i], &regvar[i + 1], (count - i) * sizeof(struct var));
						i--;
					}
				  }
				}
		|	inicio LIST '\n'
				{ $$ = 0;
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
		|	inicio LIST INTEIRO '\n'
				{ $$ = 0;
				  printf("id %d - Nome: %s | ", $3, regvar[$3].name);
					if(regvar[$3].type == 0) {
						printf("Tipo: INT | Valor: %d\n", regvar[$3].i);
					}
					else {
						printf("Tipo: REAL | Valor: %f\n", regvar[$3].d);
					}
				}
		|	inicio LISTINT '\n'
				{ $$ = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 0) {
						printf("id %d - Nome: %s=%d\n", i, regvar[i].name, regvar[i].i);
					}
				  }
				}
		|	inicio LISTREAL '\n'
				{ $$ = 0;
				  for(int i = 0; i < count; i++) {
					if(regvar[i].type == 1) {
						printf("id %d - Nome: %s=%f\n", i, regvar[i].name, regvar[i].d);
					}
				  }
				}
		|	inicio lines '\n'
				{ $$ = 0; 
				printf("ESPACO\n");
				}
		;			
		

lines:		/* empty */
			{ $$ = 0; }
		|	ESPACO
			{ $$ = 0; }
		;
var_id:		VARIAVEL
			{ for(int i = 0; i < count; i++) {
				if(strcmp(regvar[i].name, $1) == 0) {
					$$ = i;
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
		|	expr '-' expr
				{ if(expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i - expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[$1].type == 0 && expr[$3].type == 1) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].i - expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[$1].type == 1 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d - expr[$3].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d - expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		|	expr '*' expr
				{ if(expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i * expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[$1].type == 0 && expr[$3].type == 1) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].i * expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[$1].type == 1 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d * expr[$3].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d * expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		|	expr '/' expr
				{ if(expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i / expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[$1].type == 0 && expr[$3].type == 1) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].i / expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[$1].type == 1 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d / expr[$3].i;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].d = expr[$1].d / expr[$3].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		|	expr POTENCIA expr
				{ if(expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = pow(expr[$1].i, expr[$3].i);
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else if(expr[$1].type == 0 && expr[$3].type == 1) {
					$$ = count_expr;
					expr[count_expr].d = pow(expr[$1].i, expr[$3].d);
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else if(expr[$1].type == 1 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].d = pow(expr[$1].d, expr[$3].i);
					expr[count_expr].type = 1;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].d = pow(expr[$1].d, expr[$3].d);
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		|	expr '%' expr
				{ if (expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i % expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary %");
					exit(1);
				  }
				}
		|	expr '^' expr
				{ if (expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = pow(expr[$1].i, expr[$3].i);
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary ^");
					exit(1);
				  }
				} 
		|	expr '|' expr 
				{ if (expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i | expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary |");
					//exit(1);
				  }
				}
		|	expr '&' expr
				{ if (expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i & expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary &");
					exit(1);
				  }
				}
		|	expr BSRIGHT expr
				{ if (expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i >> expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary >>");
					exit(1);
				  }
				}
		|	expr BSLEFT expr
				{ if (expr[$1].type == 0 && expr[$3].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = expr[$1].i << expr[$3].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operands to binary <<");
					exit(1);
				  }
				}
		|	'~' expr
				{ if (expr[$2].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = ~expr[$2].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					yyerror("error: invalid operand to binary ~");
					exit(1);
				  }
				}
		|	'-' expr %prec UMINUS
				{ if (expr[$2].type == 0) {
					$$ = count_expr;
					expr[count_expr].i = -expr[$2].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].d = -expr[$2].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		|	'(' expr ')'
				{ $$ = ($2); }
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
					expr[count_expr].i = regvar[$1].i;
					expr[count_expr].type = 0;
					count_expr++;
				  }
				  else {
					$$ = count_expr;
					expr[count_expr].d = regvar[$1].d;
					expr[count_expr].type = 1;
					count_expr++;
				  }
				}
		;

%%

extern int yylex();
extern int yyerror(char *s);
