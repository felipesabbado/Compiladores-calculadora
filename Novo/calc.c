#include <stdio.h>
#include <ctype.h>

extern int yyparse();

int yyerror(char *s) {
	printf("%s\n", s);
}

int main() {
	yyparse();
}
