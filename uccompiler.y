%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/
    int yylex(void);
    extern void yyerror(const char *s);

    #include "tree.h"
    int nr_erro = 0;
    int vazio = 0;
    int conta = 0;
    struct node *raiz;
    struct node *novo;
%}

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

%type <no> Expr2 Expr3 Statement3 Program FunctionsAndDeclarations FunctionsAndDeclarations2 FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterList2 ParameterDeclaration Declaration Declaration2 TypeSpec Declarator StatementsERROR StatementERROR Statement2 Expr

%left  UNARY


%right  IF

%left   COMMA
%right  ASSIGN
%left   OR
%left   AND
%left   BITWISEOR
%left   BITWISEXOR
%left   BITWISEAND
%left   EQ NE
%left   LT GT LE GE
%left   MOD
%left   PLUS MINUS

%right  NOT
%left   RPAR LPAR

%nonassoc ELSE


/* Colocar erro = 0, em todos os casos aceites */

%start Program

%%
Program:             
    error                                                   {   nr_erro = 1;}
    | FunctionsAndDeclarations                              {   
                                                                $$ = raiz = criar_no(no_raiz,"Program",NULL);
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
                                                                adicionar_irmao($$,$2);
                                                                
                                                            }
    | FunctionDeclaration FunctionsAndDeclarations2         {
                                                                adicionar_irmao($$,$2);
                                                                
                                                            }
    | Declaration  FunctionsAndDeclarations2                {
                                                                adicionar_irmao($$,$2);
                                                                
                                                            }
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {   
                                                                
                                                                $$ = criar_no(no_funcoes,"FuncDefinition",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_filho($$,$2);
                                                                adicionar_filho($$,$3);
                                                            }
    ;

FunctionBody: 
    LBRACE RBRACE                                           {
                                                                $$ = criar_no(no_funcoes,"FuncBody",NULL);
                                                            }
    | LBRACE DeclarationsAndStatements RBRACE               {
                                                                
                                                                $$ = criar_no(no_funcoes,"FuncBody",NULL);
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
                                                                adicionar_filho($$,$1);
                                                                adicionar_filho($$,$2);
                                                                

                                                            }
    ;

FunctionDeclarator:
    IDENTIFIER LPAR ParameterList RPAR                      {
                                                                
                                                                $$ = criar_no(no_terminais,"Identifier",$1);
                                                                adicionar_irmao($$,$3);
                                                                
                                                            }
    ;

ParameterList:
    ParameterDeclaration ParameterList2                     {
                                                                
                                                                $$ = criar_no(no_funcoes,"ParamList",NULL);
                                                                adicionar_filho($$,$1);
                                                                
                                                                if ($2 != NULL){
                                                                    adicionar_filho($$,$2);
                                                                }
                                                                
                                                                
                                                            }      
    ;

ParameterList2: /* empty */                                 {   $$ = NULL;
                                                                
                                                            }
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
                                                                adicionar_filho($$,$1);
                                                                
                                                            }
    | TypeSpec IDENTIFIER                                   {
                                                                
                                                                $$ = criar_no(no_funcoes,"ParamDeclaration",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_filho($$,criar_no(no_terminais,"Identifier",$2));
                                                                
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
                                                            }
    | INT                                                   {
                                                                $$ = criar_no(no_terminais,"Int",NULL);
                                                            }
    | VOID                                                  {
                                                                $$ = criar_no(no_terminais,"Void",NULL);
                                                            }
    | SHORT                                                 {
                                                                $$ = criar_no(no_terminais,"Short",NULL);
                                                            }
    | DOUBLE                                                {
                                                                $$ = criar_no(no_terminais,"Double",NULL);
                                                            }
    ;

Declarator:
    IDENTIFIER                                              {
                                                                $$ = criar_no(no_declaracao,"Declaration",NULL);
                                                                adicionar_filho($$,criar_no(no_terminais,"Identifier",$1));
                                                            }
    | IDENTIFIER ASSIGN Expr2                                {
                                                                $$ = criar_no(no_declaracao,"Declaration",NULL);
                                                                adicionar_filho($$,criar_no(no_terminais,"Identifier",$1));
                                                                adicionar_filho($$,$3);
                                                            }
    ;

StatementsERROR:
    SEMI                                                    {
                                                                $$ = NULL;
                                                            }
    | Expr2 SEMI                                             {
                                                                $$ = $1;
                                                            }

    | LBRACE Statement2 RBRACE                              {
                                                                $$ = $2;
                                                            }

    | IF LPAR Expr2 RPAR StatementERROR ELSE StatementERROR  {
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho($$,$3);
                                                                
                                                                
                                                                if ($5 != NULL && $7 != NULL){
                                                                    adicionar_filho($$, $5);
                                                                    adicionar_filho($$, $7);
                                                                } else if ($5 == NULL) {
                                                                        adicionar_filho($$, criar_no(no_especial, "Null", NULL));
                                                                        adicionar_filho($$, $7);
                                                                }
                                                                
                                                            }
    | IF LPAR Expr2 RPAR StatementERROR                      {
                                                                
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5==NULL){
                                                                        adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                        adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho($$,$5);
                                                                    adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                }
                                                                
                                                                
                                                                
                                                            }

    | WHILE LPAR Expr2 RPAR StatementERROR                   {
                                                                
                                                                $$ = criar_no(no_statments,"While",NULL);
                                                                adicionar_filho($$,$3);
                                                                
                                                                if ($5 == NULL){
                                                                    adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho($$,$5);
                                                                }
                                                            }

    | RETURN Expr2 SEMI                                      {
                                                                
                                                                
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                adicionar_filho($$,$2);
                                                                
                                                                vazio = 1;
                                                            }
    | RETURN SEMI                                           {
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                novo = criar_no(no_especial, "Null",NULL);
                                                                adicionar_filho($$,novo); 
                                                            }

    | LBRACE error RBRACE                                   {   $$ = NULL; nr_erro = 1;}
    ;

StatementERROR:
    SEMI                                                    {
                                                                
                                                                $$ = criar_no(no_especial,"Null",NULL);
                                                                
                                                            }
    | Expr2 SEMI                                             {
                                                                $$ = $1;
                                                                vazio = 1;
                                                            }
    | LBRACE Statement2 RBRACE                              {
                                                                $$ = $2;
                                                            }
    | IF LPAR Expr2 RPAR StatementERROR ELSE StatementERROR  {
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho($$,$3);
                                                                
                                                                
                                                                if ($5 != NULL && $7 != NULL){
                                                                    adicionar_filho($$, $5);
                                                                    adicionar_filho($$, $7);
                                                                } else if ($5 == NULL) {
                                                                        adicionar_filho($$, criar_no(no_especial, "Null", NULL));
                                                                        adicionar_filho($$, $7);
                                                                }
                                                            }
    | IF LPAR Expr2 RPAR StatementERROR                      {
                                                                
                                                                $$ = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho($$,$3);
                                                                
                                                                if($5==NULL){
                                                                        adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                        adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho($$,$5);
                                                                    adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                }
                                                                
                                                            }
    
    | WHILE LPAR Expr2 RPAR StatementERROR                   {
                                                                
                                                                $$ = criar_no(no_statments,"While",NULL);
                                                                adicionar_filho($$,$3);
                                                                
                                                                if ($5 == NULL){
                                                                    adicionar_filho($$,criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho($$,$5);
                                                                }
                                                                

                                                            }
    | RETURN Expr2 SEMI                                      {
                                                                
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                adicionar_filho($$,$2);
                                                                vazio = 1;
                                                                
                                                            }
    | RETURN SEMI                                           {
                                                                $$ = criar_no(no_statments,"Return",NULL);
                                                                novo = criar_no(no_especial, "Null",NULL);
                                                                adicionar_filho($$,novo);
                                                            }
    

    | LBRACE error RBRACE                                   {  $$ = NULL;nr_erro = 1;}
    | error SEMI                                            {  $$ = NULL;nr_erro = 1;}
    ;

Statement2: /* empty */                                     {   
                                                                $$ = NULL;
                                                            }
    | StatementsERROR Statement3                             {
                                                                
                                                                if ($2 != NULL){
                                                                    $$ = criar_no(no_statments,"StatList",NULL);
                                                                    adicionar_filho($$,$1);
                                                                    adicionar_filho($$,$2);
                                                                
                                                                } else {
                                                                    $$ = $1;
                                                                }
                                                                
                                                            }
    ;

Statement3: /* empty */                                     {   
                                                                $$ = NULL;
                                                            } 
    
    | StatementsERROR Statement3                              {
                                                                    $$ = $1;
                                                                    adicionar_irmao($$,$2);
                                                                
                                                            }

Expr:
    Expr ASSIGN Expr                                        {
                                                                
                                                                $$ = criar_no(no_operadores,"Store",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    
    | Expr PLUS Expr                                        {
                                                                
                                                                $$ = criar_no(no_operadores,"Add",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr MINUS Expr                                       {   
                                                                
                                                                $$ = criar_no(no_operadores,"Sub",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr MUL Expr                                         {
                                                                
                                                                $$ = criar_no(no_operadores,"Mul",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr DIV Expr                                         {   
                                                                
                                                                $$ = criar_no(no_operadores,"Div",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr MOD Expr                                         {   
                                                                
                                                                $$ = criar_no(no_operadores,"Mod",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }

    | Expr OR Expr                                          {
                                                                
                                                                $$ = criar_no(no_operadores,"Or",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr AND Expr                                         {
                                                                
                                                                $$ = criar_no(no_operadores,"And",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr BITWISEAND Expr                                  {
                                                                
                                                                $$ = criar_no(no_operadores,"BitWiseAnd",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr BITWISEOR Expr                                   {
                                                                
                                                                $$ = criar_no(no_operadores,"BitWiseOr",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr BITWISEXOR Expr                                  {
                                                                
                                                                $$ = criar_no(no_operadores,"BitWiseXor",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }

    | Expr EQ Expr                                          {
                                                                
                                                                $$ = criar_no(no_operadores,"Eq",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr NE Expr                                          {   
                                                                
                                                                $$ = criar_no(no_operadores,"Ne",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr LE Expr                                          {
                                                                
                                                                $$ = criar_no(no_operadores,"Le",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr GE Expr                                          {
                                                                
                                                                $$ = criar_no(no_operadores,"Ge",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr LT Expr                                          {
                                                                
                                                                
                                                                $$ = criar_no(no_operadores,"Lt",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }
    | Expr GT Expr                                          {
                                                                
                                                                $$ = criar_no(no_operadores,"Gt",NULL);
                                                                adicionar_filho($$,$1);
                                                                adicionar_irmao($1,$3);
                                                                
                                                            }

    | PLUS Expr                                             {
                                                                
                                                                $$ = criar_no(no_operadores,"Plus",NULL);
                                                                adicionar_filho($$,$2);
                                                                
                                                            }
    | MINUS Expr                                            {   
                                                                
                                                                $$ = criar_no(no_operadores,"Minus",NULL);
                                                                adicionar_filho($$,$2);
                                                            }
    | NOT Expr                                              {
                                                                
                                                                $$ = criar_no(no_operadores,"Not",NULL);
                                                                adicionar_filho($$,$2);
                                                                
                                                            }

    | IDENTIFIER LPAR Expr Expr3 RPAR                             {
                                                                
                                                                $$ = criar_no(no_operadores,"Call",NULL);
                                                                novo = criar_no(no_terminais,"Identifier",$1);
                                                                adicionar_filho($$,novo);
                                                                adicionar_filho($$,$3);
                                                                adicionar_filho($$,$4);
                                                                
                                                            }
    | IDENTIFIER LPAR RPAR                                  {
                                                                $$ = criar_no(no_operadores,"Call",NULL);
                                                                novo = criar_no(no_terminais,"Identifier",$1);
                                                                adicionar_filho($$,novo);
                                                            }

    | IDENTIFIER %prec UNARY                                {
                                                                
                                                                $$ = criar_no(no_terminais,"Identifier",$1);
                                                                
                                                            }
    | NATURAL                                               {
                                                                
                                                                $$ = criar_no(no_terminais,"Natural",$1);
                                                                
                                                            }
    | CHRLIT                                                {
                                                                
                                                                $$ = criar_no(no_terminais,"ChrLit",$1);
                                                                
                                                            }
    | DECIMAL                                               {
                                                                
                                                                $$ = criar_no(no_terminais,"Decimal",$1);
                                                                
                                                            }
    | LPAR Expr2 RPAR                                        {
                                                                
                                                                $$ = $2;
                                                                
                                                            }
    
    | IDENTIFIER LPAR error RPAR                            {   $$ = NULL; nr_erro = 1;}
    | LPAR error RPAR                                       {   $$ = NULL; nr_erro = 1;}
    ;
    

Expr2:
    Expr {$$ = $1;}
    | Expr2 COMMA Expr {    if($1 != NULL){
                                $$ = criar_no(no_operadores,"Comma",NULL);
                                adicionar_filho($$,$1);
                                adicionar_irmao($1,$3);
                            } else {
                                $$ = $3;
                                
                                
                            }
                        }
    ;

Expr3:
    {$$ = NULL;}
    | Expr3 COMMA Expr  {
                            if($1 != NULL){
                                $$ = $1;
                                
                                adicionar_irmao($$,$3);
                        }else {
                                $$ = $3;
                                
                                
                            }
                    
    }
%%
