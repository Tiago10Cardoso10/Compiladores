all: uccompiler

uccompiler: lex.yy.c y.tab.c
	cc lex.yy.c y.tab.c -o uccompiler -ll

lex.yy.c: uccompiler.l
	lex uccompiler.l

y.tab.c: uccompiler.y
	yacc -dv uccompiler.y

clean:
	rm -f lex.yy.c y.tab.c y.tab.h uccompiler y.output

.PHONY: clean
