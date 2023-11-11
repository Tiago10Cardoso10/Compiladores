%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


int yylex(void);
void yyerror(const char* s);

typedef enum{
        // Falta descobrir para que é isto
        no_raiz,
        no_declaracao,
        no_metodos,
        no_Statement2,
        no_operadores,
        no_terminais,
        no_id
    } tipo_no;

typedef struct no * node;
    typedef struct no{
        node pai;
        node filho;
        node irmao;
        tipo_no no_tipo;
        char *valor;           
        char *tipo;            
        int num_filhos;
    } no;


%}

%union {
    char *v;
    struct no *no;
}

%token PLUS MINUS MUL DIV ASSIGN COMMA SEMI LPAR RPAR LBRACE RBRACE CHAR INT VOID SHORT DOUBLE IF ELSE WHILE RETURN
%token <v> RESERVED IDENTIFIER NATURAL DECIMAL CHRLIT

%type <no> FunctionsAndDeclarations FunctionsAndDeclarations2 FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterList2 ParameterDeclaration Declaration Declaration2 TypeSpec Declarator Statement Statement2 Expr Expr2  

%left  UNARY

%left   COMMA
%left   OR
%left   AND
%left   BITWISEOR
%left   BITWISEXOR
%left   BITWISEAND
%left   EQ NE
%left   LT GT LE GE
%left   PLUS MINUS
%left   DIV MUL MOD
%left   RPAR LPAR
%right  NOT
%right  ASSIGN

%right ELSE



%%
FunctionsAndDeclarations: 
    FunctionDefinition FunctionsAndDeclarations2            {}
    | FunctionDeclaration FunctionsAndDeclarations2         {}
    | Declaration  FunctionsAndDeclarations2                {}
    ;

FunctionsAndDeclarations2: /* empty*/                       {}
    | FunctionDefinition FunctionsAndDeclarations2          {}
    | FunctionDeclaration FunctionsAndDeclarations2         {}
    | Declaration  FunctionsAndDeclarations2                {}
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {}
    ;

FunctionBody: 
    LBRACE RBRACE                                           {}
    | LBRACE DeclarationsAndStatements RBRACE               {}
    ;

DeclarationsAndStatements:
    Statement DeclarationsAndStatements                     {}
    | Declaration DeclarationsAndStatements                 {}
    | Statement                                             {}
    | Declaration                                           {}  
    ;

FunctionDeclaration:
    TypeSpec FunctionDeclarator SEMI                        {}
    ;

FunctionDeclarator:
    IDENTIFIER LPAR ParameterList RPAR                      {}
    ;

ParameterList:
    ParameterDeclaration ParameterList2                     {}
    ;

ParameterList2: /* empty */                                 {}
    | COMMA ParameterDeclaration ParameterList2             {}
    ;

ParameterDeclaration: 
    TypeSpec                                                {}
    | TypeSpec IDENTIFIER                                   {}
    ;

Declaration:
    TypeSpec Declarator Declaration2 SEMI                   {}
    
    | error SEMI                                            {}
    ;

Declaration2:   /* empty */                                 {}
    | COMMA Declarator Declaration2                         {}
    ;

TypeSpec: 
    CHAR                                                    {}
    | INT                                                   {}
    | VOID                                                  {}
    | SHORT                                                 {}
    | DOUBLE                                                {}
    ;

Declarator:
    IDENTIFIER                                              {}
    | IDENTIFIER ASSIGN Expr                                {}
    ;

Statement:
    SEMI                                                    {}
    | Expr SEMI                                             {}
    | LBRACE Statement2 RBRACE                              {}
    | IF LPAR Expr RPAR Statement ELSE Statement            {}
    | IF LPAR Expr RPAR Statement %prec ELSE                {}
    
    | WHILE LPAR Expr RPAR Statement                        {}
    | RETURN Expr SEMI                                      {} 

    | LBRACE error RBRACE                                   {}
    ;

Statement2: 
    /* empty */                                             {}
    | Statement Statement2                                  {}
    ;

Expr:
    Expr ASSIGN Expr                                        {}
    | Expr COMMA Expr                                        {}
    | Expr PLUS Expr {}
    | Expr MINUS Expr {}
    | Expr MUL Expr {}
    | Expr DIV Expr {}
    | Expr MOD Expr {}

    | Expr OR Expr {}
    | Expr AND Expr {}
    | Expr BITWISEAND Expr {}
    | Expr BITWISEOR Expr{}
    | Expr BITWISEXOR Expr {}

    | Expr EQ Expr {}
    | Expr NE Expr {}
    | Expr LE Expr {}
    | Expr GE Expr {}
    | Expr LT Expr {}
    | Expr GT Expr {}

    | PLUS Expr {}
    | MINUS Expr {}
    | NOT Expr  {}

    
    | IDENTIFIER LPAR RPAR {}
    | IDENTIFIER LPAR Expr Expr2 RPAR {}
    | IDENTIFIER %prec UNARY{}
    
    | NATURAL {}
    | CHRLIT {}
    | DECIMAL {}
    | LPAR Expr RPAR {}
    ;
    
Expr2:
    /* empty */ {}
    | COMMA Expr2 {}
    ;

%%
