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


%}

%token PLUS MINUS MUL DIV ASSIGN COMMA SEMI LPAR RPAR LBRACE RBRACE CHAR INT VOID SHORT DOUBLE IF ELSE WHILE RETURN
%token <id> RESERVED IDENTIFIER NATURAL DECIMAL CHRLIT

%type <no> FunctionsAndDeclarations FunctionAndDeclaration2 FunctionDefinition FunctionBody DeclarationAndStatement2Opcional DeclarationsAndStatement2 FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration Declaration2 TypeSpec Declarator Statement Statement2 Expr Expr2

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
    FunctionAndDeclaration2                                   {}
    | FunctionsAndDeclarations FunctionAndDeclaration       {}
    ;

FunctionAndDeclaration2:
    FunctionDefinition                                      {}
    | FunctionDeclaration                                   {}
    | Declaration                                           {}
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {}
    ;

FunctionBody:
    LBRACE DeclarationAndStatement2Opcional RBRACE          {}
    ;

DeclarationAndStatement2Opcional:
    | DeclarationsAndStatement2                             {}
    ;

DeclarationsAndStatement2:
    Statement DeclarationsAndStatement2                     {}
    | Declaration DeclarationsAndStatement2                 {}
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
    TypeSpec Declaration2 SEMI                            {}
    ;

Declaration2:
    Declarator                                              {}
    | Declaration2 COMMA Declarator                       {}
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
    | IF LPAR Expr RPAR Statement                           {}
    | IF LPAR Expr RPAR Statement ELSE Statement            {}
    | WHILE LPAR Expr RPAR Statement                        {}
    | RETURN SEMI                                           {}
    | RETURN Expr SEMI                                      {}
    ;

Statement2:
    | Statement2 Statement                                  {}
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
    | MINUS Expr2                                    {}
    | NOT Expr                                              {}

    | IDENTIFIER LPAR RPAR                                  {}               
    | IDENTIFIER LPAR Expr2 RPAR                     {}

    | IDENTIFIER                                            {}                               
    | NATURAL                                               {}                         
    | CHRLIT                                                {}                           
    | DECIMAL                                               {}                                     
    | LPAR Expr RPAR                                        {}               
    ;

Expr2:
    Expr                                                    {}
    | Expr2 COMMA Expr                               {}
    ;


%%

void yyerror ( char * s ) {
    printf ( " Line %d ,column %d : %s : % s\n " , < num linha > ,<num coluna > , s , yytext );
}

int main() {
    yyparse();
    return 0;
}
