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

%type <no> FunctionsAndDeclarations FunctionAndDeclarations2 FunctionDefinition FunctionBody DeclarationAndStatement2 DeclarationsAndStatement FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration Declaration2 TypeSpec Declarator Statement Statement2 Expr Expr2

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
    FunctionAndDeclarations2                                {}
    | FunctionsAndDeclarations FunctionAndDeclarations2     {}
    ;

FunctionAndDeclarations2:
    FunctionDefinition                                      {}
    | FunctionDeclaration                                   {}
    | Declaration                                           {}
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {}
    ;

FunctionBody:
    LBRACE DeclarationAndStatement2 RBRACE                  {}
    ;

DeclarationAndStatement2:
    DeclarationsAndStatement                                {}
    ;

DeclarationsAndStatement:
    Statement DeclarationsAndStatement                      {}
    | Declaration DeclarationsAndStatement                  {}
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
    ParameterDeclaration                                    {}
    | ParameterList COMMA ParameterDeclaration              {}
    ;

ParameterDeclaration: 
    TypeSpec IDENTIFIER                                     {}
    | TypeSpec                                              {}
    ;

Declaration:
    TypeSpec Declaration2 SEMI                              {}
    ;

Declaration2:
    Declarator                                              {}
    | Declaration2 COMMA Declarator                         {}
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
    | Statement2 RBRACE                                     {}
    | IF LPAR Expr RPAR Statement                           {}
    | IF LPAR Expr RPAR Statement ELSE Statement            {}
    | WHILE LPAR Expr RPAR Statement                        {}
    | RETURN SEMI                                           {}
    | RETURN Expr SEMI                                      {}
    ;

Statement2:
    LBRACE
    | LBRACE Statement2 Statement                           {}
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
    | MINUS Expr2                                           {}
    | NOT Expr                                              {}

    | IDENTIFIER LPAR RPAR                                  {}               
    | IDENTIFIER LPAR Expr2 RPAR                            {}

    | IDENTIFIER                                            {}                               
    | NATURAL                                               {}                         
    | CHRLIT                                                {}                           
    | DECIMAL                                               {}                                     
    | LPAR Expr RPAR                                        {}               
    ;

Expr2:
    Expr                                                    {}
    | Expr2 COMMA Expr                                      {}
    ;

%%