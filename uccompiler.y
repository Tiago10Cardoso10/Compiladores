%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

 typedef enum{
        no_raiz,
        no_declaracao,
        no_metodos,
        no_statements,
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

    int yylex(void);
    void yyerror(const char *s);

%}

%union {
    char *v;
    struct no *no;
}

%token PLUS MINUS MUL DIV ASSIGN COMMA SEMI LPAR RPAR LBRACE RBRACE CHAR INT VOID SHORT DOUBLE IF ELSE WHILE RETURN RESERVED
%token <v> IDENTIFIER NATURAL DECIMAL CHRLIT

%type <no> FunctionsAndDeclarations FunctionOrDeclaration FunctionDefinition FunctionBody OpcionalDeclarationAndStatements DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclarations Parameter Declaration DeclaratorList TypeSpecifier Declarator Statements Expr ArgumentExpr 

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


%%

FunctionsAndDeclarations:
    FunctionOrDeclaration                                   {}
    | FunctionsAndDeclarations FunctionOrDeclaration        {}
    ;

FunctionOrDeclaration:
    FunctionDefinition                                      {}
    | FunctionDeclaration                                   {}
    | Declaration                                           {}
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {}
    ;

FunctionBody:
    LBRACE OpcionalDeclarationAndStatements RBRACE          {}
    ;

OpcionalDeclarationAndStatements:
    | DeclarationsAndStatements                             {}
    ;

DeclarationsAndStatements:
    Statement DeclarationsAndStatements                     {}
    | Declaration DeclarationsAndStatements                 {}
    | Statement                                             {}
    | Declaration                                           {}
    ;

FunctionDeclaration:
    TypeSpec FunctionDeclarator SEMI                       {}
    ;

FunctionDeclarator:
    IDENTIFIER LPAR ParameterList RPAR                      {}
    ;

ParameterList:
    ParameterDeclaration                                    {}
    | ParameterList COMMA ParameterDeclaration              {}
    ;

ParameterDeclaration: 
    TypeSpec IDENTIFIER                                     {}
    | TypeSpec                                              {}
    ;

Declaration:
    TypeSpec DeclaratorList SEMI                            {}
    ;

DeclaratorList:
    Declarator                                              {}
    | DeclaratorList COMMA Declarator                       {}
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
    | LBRACE Statements RBRACE                              {}
    | IF LPAR Expr RPAR Statement                           {}
    | IF LPAR Expr RPAR Statement ELSE Statement            {}
    | WHILE LPAR Expr RPAR Statement                        {}
    | RETURN SEMI                                           {}
    | RETURN Expr SEMI                                      {}
    ;

Statements:
    | Statements Statement                                  {}
    ;

Expr:
    Expr ASSIGN Expr                                        {}                       
    | Expr COMMA Expr                                       {}                                                            

    | Expr PLUS Expr                                        {}                       
    | Expr MINUS Expr                                       {}                       
    | Expr MUL Expr                                         {} 
    | Expr DIV Expr                                         {} 
    | Expr MOD Expr                                         {}

    | Expr OR Expr                                          {}  
    | Expr AND Expr                                         {}    
    | Expr BITWISEAND Expr                                  {}    
    | Expr BITWISEOR Expr                                   {}   
    | Expr BITWISEXOR Expr                                  {}

    | Expr EQ Expr                                          {}  
    | Expr NE Expr                                          {}   
    | Expr LE Expr                                          {}   
    | Expr GE Expr                                          {}   
    | Expr LT Expr                                          {}   
    | Expr GT Expr                                          {}    

    | PLUS Expr                                             {}
    | MINUS ArgumentExpr                                    {}
    | NOT Expr                                              {}

    | IDENTIFIER LPAR RPAR                                  {}               
    | IDENTIFIER LPAR ArgumentExpr RPAR                     {}

    | IDENTIFIER                                            {}                               
    | NATURAL                                               {}                         
    | CHRLIT                                                {}                           
    | DECIMAL                                               {}                                     
    | LPAR Expr RPAR                                        {}               
    ;

ArgumentExpr:
    Expr                                                    {}
    | ArgumentExpr COMMA Expr                               {}
    ;
    

%%

void yyerror(const char* message) {
    fprintf(stderr, "Syntax Error: %s\n", message);
}