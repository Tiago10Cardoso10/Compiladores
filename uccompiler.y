%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/
    #include "tree.h"

    int yylex(void);
    void yyerror(const char* s);

    extern int opcao;
        int pontos = 0;
        int erro = 0;
        no raiz;
        no novo;


%}

%union {
    char *v;
    struct no *no;
}

%token PLUS MINUS MUL DIV ASSIGN COMMA SEMI LPAR RPAR LBRACE RBRACE CHAR INT VOID SHORT DOUBLE IF ELSE WHILE RETURN
%token <v> RESERVED IDENTIFIER NATURAL DECIMAL CHRLIT

%type <no> FunctionsAndDeclarations FunctionsAndDeclarations2 FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterList2 ParameterDeclaration Declaration Declaration2 TypeSpec Declarator Statement Statement2 Expr Expr2  

%left   LPAR RPAR
%left   UNARY
%left   PLUS MINUS
%left   DIV MUL MOD
%left   BITWISEAND BITWISEOR BITWISEXOR
%left   EQ NE
%left   LT GT LE GE
%left   COMMA  
%left   AND
%left   OR
%right  NOT
%right  ASSIGN
%right  ELSE



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
    | MINUS Expr                                            {}
    | NOT Expr                                              {}

    
    | IDENTIFIER LPAR RPAR                                  {}
    | IDENTIFIER LPAR Expr Expr2 RPAR                       {}
    
    | IDENTIFIER                                            {}
    | NATURAL                                               {}
    | CHRLIT                                                {}
    | DECIMAL                                               {}
    | LPAR Expr RPAR                                        {}
    ;
    
Expr2:
    /* empty */                                             {}
    | COMMA Expr2                                           {}
    ;

%%
