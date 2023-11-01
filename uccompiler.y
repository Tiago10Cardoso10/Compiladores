%{
#include <stdio.h>
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
%}

%token CHAR INT VOID SHORT DOUBLE
%token IDENTIFIER NATURAL CHRLIT DECIMAL
%token LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET SEMI COMMA
%token ASSIGN PLUS MINUS MUL DIV MOD OR AND BITWISEAND BITWISEOR BITWISEXOR
%token EQ NE LE GE LT GT NOT IF ELSE WHILE RETURN
%token LOWER_THAN_ELSE 
%left '+' '-'

%%

FunctionsAndDeclarations: FunctionDefinition
                       | FunctionDeclaration
                       | Declaration
                       | FunctionsAndDeclarations FunctionDefinition
                       | FunctionsAndDeclarations FunctionDeclaration
                       | FunctionsAndDeclarations Declaration;

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody;

FunctionBody: LBRACE DeclarationsAndStatements RBRACE;

DeclarationsAndStatements: Statement DeclarationsAndStatements
                          | Declaration DeclarationsAndStatements
                          | Statement
                          | Declaration;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI;

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR;

ParameterList: ParameterDeclaration
             | ParameterDeclaration COMMA ParameterList;

ParameterDeclaration: TypeSpec IDENTIFIER
                    | TypeSpec;

Declaration: TypeSpec DeclaratorList SEMI;

TypeSpec: CHAR
        | INT
        | VOID
        | SHORT
        | DOUBLE;

DeclaratorList: Declarator
              | Declarator COMMA DeclaratorList;

Declarator: IDENTIFIER
          | IDENTIFIER ASSIGN Expr;

Statement: Expr SEMI
         | LBRACE Statements RBRACE
         | IF LPAR Expr RPAR Statement LOWER_THAN_ELSE
         | IF LPAR Expr RPAR Statement ELSE Statement
         | WHILE LPAR Expr RPAR Statement
         | RETURN SEMI
         | RETURN Expr SEMI;

Statements: Statement
          | Statement Statements;

Expr: Expr ASSIGN Expr
     | Expr COMMA Expr
     | Expr PLUS Expr
     | Expr MINUS Expr
     | Expr MUL Expr
     | Expr DIV Expr
     | Expr MOD Expr
     | Expr OR Expr
     | Expr AND Expr
     | Expr BITWISEAND Expr
     | Expr BITWISEOR Expr
     | Expr BITWISEXOR Expr
     | Expr EQ Expr
     | Expr NE Expr
     | Expr LE Expr
     | Expr GE Expr
     | Expr LT Expr
     | Expr GT Expr
     | PLUS Expr    
     | MINUS Expr 
     | NOT Expr 
     | IDENTIFIER LPAR ExprList RPAR
     | IDENTIFIER
     | NATURAL
     | CHRLIT
     | DECIMAL
     | LPAR Expr RPAR;

ExprList: Expr
        | Expr COMMA ExprList;

%%

void yyerror(char *error) {
    printf("%s '%s'\n", error, yytext);
}
