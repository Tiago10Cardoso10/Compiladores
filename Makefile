# Definições
CC = gcc
LEX = lex
YACC = yacc
OUTPUT = uccompiler
LEX_FILE = uccompiler.l
YACC_FILE = uccompiler.y

# Regra padrão
all: $(OUTPUT)

$(OUTPUT): lex.yy.c
	$(CC) lex.yy.c  y.tab.c -o $(OUTPUT) -ll

lex.yy.c: $(LEX_FILE)
	$(LEX) $(LEX_FILE)

y.tab.c:$(YACC_FILE)
	$(YACC) -dv (YACC_FILE)

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	rm -f lex.yy.c $(OUTPUT)

