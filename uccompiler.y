
%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/
    #include <stdio.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdarg.h>
    

    int yylex(void);
    void yyerror(const char *s);
    
%}

%union {
    char *v;
    struct no *no;
}
%token CHAR
%token ELSE
%token WHILE
%token IF
%token INT
%token SHORT
%token DOUBLE
%token RETURN
%token VOID
%token BITWISEAND
%token BITWISEOR
%token BITWISEXOR
%token AND
%token ASSIGN
%token MUL
%token COMMA
%token DIV
%token EQ
%token GE
%token GT
%token LBRACE
%token LE
%token LPAR
%token LT
%token MINUS
%token MOD
%token NE
%token NOT
%token OR
%token PLUS
%token RBRACE 
%token RPAR
%token SEMI
%token RESERVED

%token<v> IDENTIFIER
%token<v> NATURAL
%token<v> DECIMAL
%token<v> CHRLIT

%type <no> Program /* FunctionsAndDeclarations FunctionsAndDeclarations2 FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterList2 ParameterDeclaration Declaration Declaration2 TypeSpec Declarator Statement Statement2 Expr Expr2  
*/
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

%nonassoc IF
%nonassoc ELSE

%start Program

%%
Program:
    PLUS {printf("asdasd\n");}
    | {}
    ;

/*
FunctionsAndDeclarations: 
    FunctionDefinition FunctionsAndDeclarations2            {}
    | FunctionDeclaration FunctionsAndDeclarations2         {}
    | Declaration  FunctionsAndDeclarations2                {}
    ;

FunctionsAndDeclarations2:                       {}
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

ParameterList2:                                  {  }
    | COMMA ParameterDeclaration ParameterList2             {  }
    ;

ParameterDeclaration: 
    TypeSpec                                                {  }
    | TypeSpec IDENTIFIER                                   {  }
    ;

Declaration:
    TypeSpec Declarator Declaration2 SEMI                   {  }
    
    | error SEMI                                            {  }
    ;

Declaration2:                                    {  }
    | COMMA Declarator Declaration2                         {  }
    ;

TypeSpec: 
    CHAR                                                    {  }
    | INT                                                   {  }
    | VOID                                                  {  }
    | SHORT                                                 {  }
    | DOUBLE                                                {  }
    ;

Declarator:
    IDENTIFIER                                              {  }
    | IDENTIFIER ASSIGN Expr                                {  }
    ;

Statement:
    SEMI                                                    {  }
    | Expr SEMI                                             {  }
    | LBRACE Statement2 RBRACE                              {  }
    | IF LPAR Expr RPAR Statement ELSE Statement            {  }
    | IF LPAR Expr RPAR Statement                {  }
    
    | WHILE LPAR Expr RPAR Statement                        {  }
    | RETURN Expr SEMI                                      {  } 

    | LBRACE error RBRACE                                   {  }
    
    ;

Statement2:        {  }
    | Statement Statement2                                  {  }
    ;

Expr:
    Expr ASSIGN Expr                                        { }
    | Expr COMMA Expr                                        { }
    | Expr PLUS Expr { }
    | Expr MINUS Expr { }
    | Expr MUL Expr { }
    | Expr DIV Expr { }
    | Expr MOD Expr { }

    | Expr OR Expr { }
    | Expr AND Expr { }
    | Expr BITWISEAND Expr { }
    | Expr BITWISEOR Expr { }
    | Expr BITWISEXOR Expr { }

    | Expr EQ Expr { }
    | Expr NE Expr { }
    | Expr LE Expr { }
    | Expr GE Expr { }
    | Expr LT Expr { }
    | Expr GT Expr {}

    | PLUS Expr {}
    | MINUS Expr {}
    | NOT Expr  {}

    | IDENTIFIER LPAR RPAR {}
    | IDENTIFIER LPAR Expr Expr2 RPAR {}
    | IDENTIFIER %prec UNARY {}
    
    | NATURAL {}
    | CHRLIT {}
    | DECIMAL {}
    | LPAR Expr RPAR {}
    
    | IDENTIFIER LPAR error RPAR {}
    | LPAR error RPAR {}
    ;
    
Expr2:
    {}
    | COMMA Expr2 {}
    ;
*/
%%
