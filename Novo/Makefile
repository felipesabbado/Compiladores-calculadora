calculos: y.tab.o lex.yy.o calc.o
	gcc -o calculos y.tab.o lex.yy.o calc.o -lm

y.tab.o: y.tab.c
	gcc -c y.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

calc.o: calc.c
	gcc -c calc.c

y.tab.c: calculos.y
	byacc -d calculos.y

lex.yy.c: calculos.l y.tab.h
	flex calculos.l
