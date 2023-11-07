%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/

<<<<<<< HEAD
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

 typedef enum{
        no_raiz,
        no_declaracao,
        no_metodos,
        no_statements,
=======
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
>>>>>>> TiagoCardoso
        no_operadores,
        no_terminais,
        no_id
    } tipo_no;

<<<<<<< HEAD
    typedef struct no * node;
=======
typedef struct no * node;
>>>>>>> TiagoCardoso
    typedef struct no{
        node pai;
        node filho;
        node irmao;
        tipo_no no_tipo;
        char *valor;           
        char *tipo;            
        int num_filhos;
    } no;

<<<<<<< HEAD
    int yylex(void);
    void yyerror(const char *s);
=======
>>>>>>> TiagoCardoso

%}

%union {
    char *v;
    struct no *no;
}

<<<<<<< HEAD
%token PLUS MINUS MUL DIV ASSIGN COMMA SEMI LPAR RPAR LBRACE RBRACE CHAR INT VOID SHORT DOUBLE IF ELSE WHILE RETURN RESERVED
%token <v> IDENTIFIER NATURAL DECIMAL CHRLIT

%type <no> FunctionsAndDeclarations FunctionOrDeclaration FunctionDefinition FunctionBody OpcionalDeclarationAndStatements DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclarations Parameter Declaration DeclaratorList TypeSpecifier Declarator Statements Expr ArgumentExpr 
=======
%token PLUS MINUS MUL DIV ASSIGN COMMA SEMI LPAR RPAR LBRACE RBRACE CHAR INT VOID SHORT DOUBLE IF ELSE WHILE RETURN
%token <v> RESERVED IDENTIFIER NATURAL DECIMAL CHRLIT

%type <no> FunctionsAndDeclarations FunctionAndDeclarations2 FunctionDefinition FunctionBody DeclarationAndStatement2 DeclarationsAndStatement FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration Declaration2 TypeSpec Declarator Statement Statement2 Expr Expr2
>>>>>>> TiagoCardoso

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
<<<<<<< HEAD
    FunctionOrDeclaration                                   {}
    | FunctionsAndDeclarations FunctionOrDeclaration        {}
    ;

FunctionOrDeclaration:
=======
    FunctionAndDeclarations2                                {}
    | FunctionsAndDeclarations FunctionAndDeclarations2     {}
    ;

FunctionAndDeclarations2:
>>>>>>> TiagoCardoso
    FunctionDefinition                                      {}
    | FunctionDeclaration                                   {}
    | Declaration                                           {}
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {}
    ;

FunctionBody:
<<<<<<< HEAD
    LBRACE OpcionalDeclarationAndStatements RBRACE          {}
    ;

OpcionalDeclarationAndStatements:
    | DeclarationsAndStatements                             {}
    ;

DeclarationsAndStatements:
    Statement DeclarationsAndStatements                     {}
    | Declaration DeclarationsAndStatements                 {}
=======
    LBRACE DeclarationAndStatement2 RBRACE                  {}
    ;

DeclarationAndStatement2:
    DeclarationsAndStatement                                {}
    ;

DeclarationsAndStatement:
    Statement DeclarationsAndStatement                      {}
    | Declaration DeclarationsAndStatement                  {}
>>>>>>> TiagoCardoso
    | Statement                                             {}
    | Declaration                                           {}
    ;

FunctionDeclaration:
<<<<<<< HEAD
    TypeSpec FunctionDeclarator SEMI                       {}
=======
    TypeSpec FunctionDeclarator SEMI                        {}
>>>>>>> TiagoCardoso
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
<<<<<<< HEAD
    TypeSpec DeclaratorList SEMI                            {}
    ;

DeclaratorList:
    Declarator                                              {}
    | DeclaratorList COMMA Declarator                       {}
=======
    TypeSpec Declaration2 SEMI                              {}
    ;

Declaration2:
    Declarator                                              {}
    | Declaration2 COMMA Declarator                         {}
>>>>>>> TiagoCardoso
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
<<<<<<< HEAD
    | LBRACE Statements RBRACE                              {}
=======
    | Statement2 RBRACE                                     {}
>>>>>>> TiagoCardoso
    | IF LPAR Expr RPAR Statement                           {}
    | IF LPAR Expr RPAR Statement ELSE Statement            {}
    | WHILE LPAR Expr RPAR Statement                        {}
    | RETURN SEMI                                           {}
    | RETURN Expr SEMI                                      {}
    ;

<<<<<<< HEAD
Statements:
    | Statements Statement                                  {}
=======
Statement2:
    LBRACE
    | LBRACE Statement2 Statement                           {}
>>>>>>> TiagoCardoso
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
<<<<<<< HEAD
    | MINUS ArgumentExpr                                    {}
    | NOT Expr                                              {}

    | IDENTIFIER LPAR RPAR                                  {}               
    | IDENTIFIER LPAR ArgumentExpr RPAR                     {}
=======
    | MINUS Expr2                                           {}
    | NOT Expr                                              {}

    | IDENTIFIER LPAR RPAR                                  {}               
    | IDENTIFIER LPAR Expr2 RPAR                            {}
>>>>>>> TiagoCardoso

    | IDENTIFIER                                            {}                               
    | NATURAL                                               {}                         
    | CHRLIT                                                {}                           
    | DECIMAL                                               {}                                     
    | LPAR Expr RPAR                                        {}               
    ;

<<<<<<< HEAD
ArgumentExpr:
    Expr                                                    {}
    | ArgumentExpr COMMA Expr                               {}
    ;
    

%%

void yyerror(const char* message) {
    fprintf(stderr, "Syntax Error: %s\n", message);
}
=======
Expr2:
    Expr                                                    {}
    | Expr2 COMMA Expr                                      {}
    ;

%%
>>>>>>> TiagoCardoso
