%option noyywrap

%{
#include "y.tab.h"
%}

%%

[-+*/^~&|()%=]			return yytext[0];
[*]{2}					{yylval.s=strdup(yytext); return POTENCIA;}
[<]{2}					{yylval.s=strdup(yytext); return BSLEFT;}
[>]{2}					{yylval.s=strdup(yytext); return BSRIGHT;}
[+]{2}					{yylval.s=strdup(yytext); return INCREMENTO;}
[-]{2}					{yylval.s=strdup(yytext); return DECREMENTO;}
"(int)"					return CASTINT;
[A-Za-z][A-Za-z0-9]*	{yylval.s=strdup(yytext); return VARIAVEL;}
[0-9]+					{yylval.final_value.value.i=atoi(yytext); return INTEIRO;}
[0-9]+\.[0-9]+			{yylval.final_value.value.d=atof(yytext); return REAL;}

\n						return yytext[0];
