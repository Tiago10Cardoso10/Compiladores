%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/
    int yylex(void);
    extern void yyerror(const char *s);

    #include "uccompiler.h"
    int nr_erro = 0;
    int vazio = 0;
    int conta = 0;
    struct node *raiz;
    struct node *novo;
%}

%locations

%union {
    char *v;
    struct node *no;
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

%type <no> Program FunctionsAndDeclarations FunctionsAndDeclarations2 FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterList2 ParameterDeclaration Declaration Declaration2 TypeSpec Declarator StatementsERROR StatementERROR Statement2 Expr Expr2 Expr3 

%left   COMMA
%right  ASSIGN
%left   OR
%left   AND
%left   BITWISEOR
%left   BITWISEXOR
%left   BITWISEAND
%left   EQ NE 
%left   LT GT LE GE
%left   PLUS MINUS
%left   MOD MUL DIV 
%right  NOT
%left   RPAR LPAR

%right IF ELSE


/* Colocar erro = 0, em todos os casos aceites */

%start Program

%%
Program:             
    error                                                   {   nr_erro = 1;}
    | FunctionsAndDeclarations                              {   
                                                                $$ = raiz = criar_no(no_raiz,"Program",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                            }


FunctionsAndDeclarations: 
    FunctionDefinition FunctionsAndDeclarations2            {   
                                                                $$ = $1;
                                                                adicionar_irmao($1,$2);
                                                            }
    | FunctionDeclaration FunctionsAndDeclarations2         {   
                                                                $$ = $1;
                                                                adicionar_irmao($1,$2);
                                                            }
    | Declaration  FunctionsAndDeclarations2                {   
                                                                $$ = $1;
                                                                adicionar_irmao($1,$2);
                                                            }
    ;

FunctionsAndDeclarations2:  /* empty */                     {   
                                                                $$ = NULL;
                                                            }
    | FunctionDefinition FunctionsAndDeclarations2          {   
                                                                $$ = $1;
                                                                adicionar_irmao($$,$2);
                                                            }
    | FunctionDeclaration FunctionsAndDeclarations2         {
                                                                $$ = $1;
                                                                adicionar_irmao($$,$2);
                                                            }
    | Declaration  FunctionsAndDeclarations2                {
                                                                $$ = $1;
                                                                adicionar_irmao($$,$2);
                                                            }
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {   
                                                                
                                                                $$ = criar_no(no_funcoes,"FuncDefinition",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_filho($$,$2);
                                                                adicionar_filho($$,$3);
                                                            }
    ;

FunctionBody: 
    LBRACE RBRACE                                           {
                                                                $$ = criar_no(no_funcoes,"FuncBody",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | LBRACE DeclarationsAndStatements RBRACE               {
                                                                $$ = criar_no(no_funcoes,"FuncBody",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$2);
                                                            }
    ;

DeclarationsAndStatements:
    StatementsERROR DeclarationsAndStatements               { 
                                                                if($1 == NULL){
                                                                    $$ = $2;
                                                                } else {
                                                                    $$ = $1;
                                                                    adicionar_irmao($$,$2);
                                                                }
                                                            }
    | Declaration DeclarationsAndStatements                 {
                                                                $$ = $1;
                                                                adicionar_irmao($$,$2);
                                                            }
    | StatementsERROR                                       {
                                                                $$ = $1;
                                                            }
    | Declaration                                           {
                                                                $$ = $1;
                                                            }  
    ;

FunctionDeclaration:
    TypeSpec FunctionDeclarator SEMI                        {
                                                                $$ = criar_no(no_funcoes,"FuncDeclaration",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_filho($$,$2);
                                                            }
    ;

FunctionDeclarator:
    IDENTIFIER LPAR ParameterList RPAR                      {
                                                                $$ = criar_no(no_terminais,"Identifier",$1);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_irmao($$,$3);
                                                            }
    ;

ParameterList:
    ParameterDeclaration ParameterList2                     {
                                                                $$ = criar_no(no_funcoes,"ParamList",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                
                                                                if ($2 != NULL){
                                                                    adicionar_filho($$,$2);
                                                                }
                                                            }      
    ;

ParameterList2: /* empty */                                 {   $$ = NULL;}
    | COMMA ParameterDeclaration ParameterList2             {
                                                                $$ = $2;
                                                                if($3 != NULL){
                                                                    adicionar_irmao($$,$3);
                                                                }
                                                            }
    ;

ParameterDeclaration: 
    TypeSpec                                                {
                                                                $$ = criar_no(no_funcoes,"ParamDeclaration",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                            }
    | TypeSpec IDENTIFIER                                   {
                                                                $$ = criar_no(no_funcoes,"ParamDeclaration",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                novo = criar_no(no_terminais,"Identifier",$2);
                                                                novo->linha = @2.first_line;
                                                                novo->coluna= @2.first_column;
                                                                adicionar_filho($$,novo);
                                                            }
    ;

Declaration:
    TypeSpec Declaration2 SEMI                              {  
                                                                $$ = $2;
                                                                adiciona_primeiro($$,$1);
                                                            }
    | error SEMI                                            {  $$ = NULL; nr_erro = 1;}
    ;

Declaration2: 
    Declarator                                              {  $$ = $1;}
    | Declaration2 COMMA Declarator                         {
                                                                if ($1 != NULL){
                                                                    $$ = $1;
                                                                    adicionar_irmao($$,$3);
                                                                } else {
                                                                    $$ = $3;
                                                                }
                                                            }
    ;

TypeSpec: 
    CHAR                                                    {
                                                                $$ = criar_no(no_terminais,"Char",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | INT                                                   {
                                                                $$ = criar_no(no_terminais,"Int",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | VOID                                                  {
                                                                $$ = criar_no(no_terminais,"Void",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | SHORT                                                 {
                                                                $$ = criar_no(no_terminais,"Short",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | DOUBLE                                                {
                                                                $$ = criar_no(no_terminais,"Double",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    ;

Declarator:
    IDENTIFIER                                              {
                                                                $$ = criar_no(no_declaracao,"Declaration",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                novo = criar_no(no_terminais,"Identifier",$1);
                                                                novo->linha = @1.first_line;
                                                                novo->coluna= @1.first_column;
                                                                adicionar_filho($$,novo);
                                                            }
    | IDENTIFIER ASSIGN Expr2                               {
                                                                $$ = criar_no(no_declaracao,"Declaration",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                novo = criar_no(no_terminais,"Identifier",$1);
                                                                novo->linha = @1.first_line;
                                                                novo->coluna= @1.first_column;
                                                                adicionar_filho($$,novo);
                                                                adicionar_filho($$,$3);
                                                            }
    ;

StatementsERROR:
    SEMI                                                    {
                                                                $$ = NULL;
                                                            }
    | Expr2 SEMI                                            {
                                                                $$ = $1;
                                                            }

    | LBRACE Statement2 RBRACE                              {
                                                                if ($2!=NULL && $2->irmaos!=NULL){
                                                                    $$ = criar_no (no_statments,"StatList",NULL);
                                                                    $$->linha = @1.first_line;
                                                                    $$->coluna= @1.first_column;
                                                                    adicionar_filho($$,$2);
                                                                } else {
                                                                    $$=$2;
                                                                }
                                                            }
    
    | LBRACE RBRACE                                         {
                                                                $$ = NULL;
                                                            }

    | IF LPAR Expr2 RPAR StatementERROR ELSE StatementERROR {
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5 == NULL){
                                                                        adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                                    } else if($5->irmaos != NULL){
                                                                        novo = criar_no(no_statments,"StatList",NULL);
                                                                        novo->linha = @1.first_line;
                                                                        novo->coluna= @1.first_column;
                                                                        adicionar_filho($$, novo);
                                                                        adicionar_irmao(novo->filhos->no, $5);
                                                                    } else {
                                                                        adicionar_filho($$, $5);
                                                                    }
                                                                if($7 == NULL){
                                                                    adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                                } else if($7->irmaos != NULL){
                                                                    novo = criar_no(no_statments,"StatList",NULL);
                                                                    novo->linha = @1.first_line;
                                                                    novo->coluna= @1.first_column;
                                                                    adicionar_filho($$, novo);
                                                                    adicionar_irmao(novo->filhos->no, $7);
                                                                } else {
                                                                    adicionar_filho($$, $7);
                                                                }
                                                            }
    | IF LPAR Expr2 RPAR StatementERROR                     {
                                                                
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5 == NULL){
                                                                    adicionar_irmao($3, criar_no(no_especial,"Null",NULL));
                                                                } else if ($5->irmaos != NULL){ 
                                                                    novo = criar_no(no_statments,"StatList",NULL);
                                                                    novo->linha = @1.first_line;
                                                                    novo->coluna= @1.first_column;
                                                                    adicionar_filho($$,novo);
                                                                    adicionar_irmao(novo->filhos->no,$5);
                                                                } else{
                                                                    adicionar_filho($$, $5);
                                                                }
                                                                
                                                                adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                            }

    | WHILE LPAR Expr2 RPAR StatementERROR                  {
                                                                
                                                                $$ = criar_no(no_statments,"While",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5 == NULL){
                                                                    
                                                                    adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho($$,$5);
                                                                }
                                                            }
                                                            

    | RETURN Expr2 SEMI                                     {
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$2);
                                                            }
    | RETURN SEMI                                           {
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                novo = criar_no(no_especial, "Null",NULL);
                                                                novo->linha = @1.first_line;
                                                                novo->coluna= @1.first_column;
                                                                adicionar_filho($$,novo); 
                                                            }

    | LBRACE error RBRACE                                   {   $$ = NULL; nr_erro = 1;}
    ;

StatementERROR:
    SEMI                                                    {
                                                                
                                                                $$ = NULL;
                                                                
                                                            }
    | Expr2 SEMI                                            {
                                                                $$ = $1;
                                                                
                                                            }
    | LBRACE Statement2 RBRACE                              {
                                                                if ($2!=NULL && $2->irmaos!=NULL){
                                                                    $$ = criar_no (no_statments,"StatList",NULL);
                                                                    $$->linha = @1.first_line;
                                                                    $$->coluna= @1.first_column;
                                                                    adicionar_filho($$,$2);
                                                                } else {
                                                                    $$=$2;
                                                                }
                                                            }
    | LBRACE RBRACE                                         {
                                                                $$ = NULL;
                                                            }
    | IF LPAR Expr2 RPAR StatementERROR ELSE StatementERROR {
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5 == NULL){
                                                                        
                                                                        adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                                    } else if($5->irmaos != NULL){
                                                                        novo = criar_no(no_statments,"StatList",NULL);
                                                                        novo->linha = @1.first_line;
                                                                        novo->coluna= @1.first_column;
                                                                        adicionar_filho($$, novo);
                                                                        adicionar_irmao(novo->filhos->no, $5);
                                                                    } else {
                                                                        adicionar_filho($$, $5);
                                                                    }
                                                                if($7 == NULL){
                                                                    
                                                                    adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                                } else if($7->irmaos != NULL){
                                                                    novo = criar_no(no_statments,"StatList",NULL);
                                                                    novo->linha = @1.first_line;
                                                                    novo->coluna= @1.first_column;
                                                                    adicionar_filho($$, novo);
                                                                    adicionar_irmao(novo->filhos->no, $7);
                                                                } else {
                                                                    adicionar_filho($$, $7);
                                                                }
                                                            }
    | IF LPAR Expr2 RPAR StatementERROR                      {
                                                                
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5 == NULL){
                                                                    
                                                                    adicionar_irmao($3, criar_no(no_especial,"Null",NULL));
                                                                } else if ($5->irmaos != NULL){ 
                                                                    novo = criar_no(no_statments,"StatList",NULL);
                                                                    novo->linha = @1.first_line;
                                                                    novo->coluna= @1.first_column;
                                                                    adicionar_filho($$,novo);
                                                                    adicionar_irmao(novo->filhos->no,$5);
                                                                } else{
                                                                    adicionar_filho($$, $5);
                                                                }
                                                                
                                                                adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                            }
    
    | WHILE LPAR Expr2 RPAR StatementERROR                  {
                                                                
                                                                $$ = criar_no(no_statments,"While",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5 == NULL){
                                                                
                                                                    adicionar_filho($$, criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho($$,$5);
                                                                }
                                                            }
    | RETURN Expr2 SEMI                                     {
                                                                
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$2);
                                                            }
    | RETURN SEMI                                           {
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                novo = criar_no(no_especial, "Null",NULL);
                                                                novo->linha = @1.first_line;
                                                                novo->coluna= @1.first_column;
                                                                adicionar_filho($$,novo);
                                                            }
    

    | LBRACE error RBRACE                                   {  $$ = NULL;nr_erro = 1;}
    | error SEMI                                            {  $$ = NULL;nr_erro = 1;}
    ;

Statement2:
    StatementERROR                                          {  $$ = $1;}


    | StatementERROR  Statement2                            {
                                                                if ($1 != NULL) {
                                                                    $$ = $1;
                                                                    adicionar_irmao($$,$2);
                                                                } else {
                                                                    $$ = $2;
                                                                }
                                                            }
    ;



Expr:
    Expr ASSIGN Expr                                        {
                                                                
                                                                $$ = criar_no(no_operadores,"Store",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    
    | Expr PLUS Expr                                        {
                                                                
                                                                $$ = criar_no(no_operadores,"Add",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr MINUS Expr                                       {   
                                                                
                                                                $$ = criar_no(no_operadores,"Sub",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr MUL Expr                                         {
                                                                
                                                                $$ = criar_no(no_operadores,"Mul",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr DIV Expr                                         {   
                                                                
                                                                $$ = criar_no(no_operadores,"Div",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr MOD Expr                                         {   
                                                                
                                                                $$ = criar_no(no_operadores,"Mod",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }

    | Expr OR Expr                                          {
                                                                
                                                                $$ = criar_no(no_operadores,"Or",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr AND Expr                                         {
                                                                
                                                                $$ = criar_no(no_operadores,"And",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr BITWISEAND Expr                                  {
                                                                
                                                                $$ = criar_no(no_operadores,"BitWiseAnd",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr BITWISEOR Expr                                   {
                                                                $$ = criar_no(no_operadores,"BitWiseOr",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                            }
    | Expr BITWISEXOR Expr                                  {
                                                                $$ = criar_no(no_operadores,"BitWiseXor",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                            }

    | Expr EQ Expr                                          {
                                                                $$ = criar_no(no_operadores,"Eq",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                            }
    | Expr NE Expr                                          {   
                                                                $$ = criar_no(no_operadores,"Ne",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                            }
    | Expr LE Expr                                          {
                                                                
                                                                $$ = criar_no(no_operadores,"Le",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr GE Expr                                          {
                                                                $$ = criar_no(no_operadores,"Ge",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                            }
    | Expr LT Expr                                          {
                                                                $$ = criar_no(no_operadores,"Lt",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr GT Expr                                          {
                                                                $$ = criar_no(no_operadores,"Gt",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                            }

    | PLUS Expr   %prec MUL                             {
                                                                
                                                                $$ = criar_no(no_operadores,"Plus",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$2);
                                                                
                                                            }
    | MINUS Expr  %prec MUL                             {   
                                                                
                                                                $$ = criar_no(no_operadores,"Minus",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$2);
                                                            }
    | NOT Expr                                   {
                                                                
                                                                $$ = criar_no(no_operadores,"Not",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                adicionar_filho($$,$2);
                                                                
                                                            }

    | IDENTIFIER LPAR Expr Expr3 RPAR                       {
                                                                
                                                                $$ = criar_no(no_operadores,"Call",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                novo = criar_no(no_terminais,"Identifier",$1);
                                                                novo->linha = @1.first_line;
                                                                novo->coluna= @1.first_column;
                                                                adicionar_filho($$,novo);
                                                                adicionar_filho($$,$3);
                                                                adicionar_filho($$,$4);
                                                                
                                                            }
    | IDENTIFIER LPAR RPAR                                  {
                                                                $$ = criar_no(no_operadores,"Call",NULL);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                                novo = criar_no(no_terminais,"Identifier",$1);
                                                                novo->linha = @1.first_line;
                                                                novo->coluna= @1.first_column;
                                                                adicionar_filho($$,novo);
                                                                
                                                            }

    | IDENTIFIER                                            {
                                                                
                                                                $$ = criar_no(no_terminais,"Identifier",$1);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | NATURAL                                               {
                                                                
                                                                $$ = criar_no(no_terminais,"Natural",$1);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | CHRLIT                                                {
                                                                
                                                                $$ = criar_no(no_terminais,"ChrLit",$1);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | DECIMAL                                               {
                                                                
                                                                $$ = criar_no(no_terminais,"Decimal",$1);
                                                                $$->linha = @1.first_line;
                                                                $$->coluna= @1.first_column;
                                                            }
    | LPAR Expr2 RPAR                                       {
                                                                
                                                                $$ = $2;
                                                                
                                                            }
    
    | IDENTIFIER LPAR error RPAR                            {   $$ = NULL; nr_erro = 1;}
    | LPAR error RPAR                                       {   $$ = NULL; nr_erro = 1;}
    ;
    

Expr2:
    Expr                                                    {   $$ = $1;}
    | Expr2 COMMA Expr                                      {   if($1 != NULL){
                                                                    $$ = criar_no(no_operadores,"Comma",NULL);
                                                                    $$->linha = @1.first_line;
                                                                    $$->coluna= @1.first_column;
                                                                    adicionar_filho($$,$1);
                                                                    adicionar_irmao($1,$3);
                                                                } else {
                                                                    $$ = $3;
                                                                }
                                                            }
    ;

Expr3: /* empty */                                          {   $$ = NULL;}
    | Expr3 COMMA Expr                                      {
                                                                if($1 != NULL){
                                                                    $$ = $1;
                                                                    adicionar_irmao($$,$3);
                                                                }else {
                                                                    $$ = $3;
                                                                }
                                                            }
%%
