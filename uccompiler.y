
%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/
    
    

    int yylex(void);
    extern void yyerror(const char *s);

    #include "tree.h"
    int nr_erro = 0;
    int teste = 1;
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

%type <no> FunctionsAndDeclarations FunctionsAndDeclarations2 FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterList2 ParameterDeclaration Declaration Declaration2 TypeSpec Declarator StatementsERROR StatementERROR Statement2 Expr

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



%%
FunctionsAndDeclarations: 
    FunctionDefinition FunctionsAndDeclarations2            {   
                                                                $$ = raiz = criar_no(no_raiz,"Program",NULL);
                                                                novo = criar_no(no_funcoes,"FunctionDefinition",NULL);
                                                                adicionar_filho(raiz,novo);
                                                                adicionar_filho(raiz,$2);
                                                            }
    | FunctionDeclaration FunctionsAndDeclarations2         {   
                                                                $$ = raiz = criar_no(no_raiz,"Program",NULL);
                                                                novo = criar_no(no_funcoes,"FunctionDeclaration",NULL);
                                                                adicionar_filho(raiz,novo);
                                                                adicionar_filho(raiz,$2);
                                                            }
    | Declaration  FunctionsAndDeclarations2                {   
                                                                $$ = raiz = criar_no(no_raiz,"Program",NULL);
                                                                
                                                                adicionar_filho(raiz,$1);
                                                                adicionar_filho(raiz,$2);
                                                                
                                                            }
    ;

FunctionsAndDeclarations2:  /* empty */                     {   $$ = NULL;}
    | FunctionDefinition FunctionsAndDeclarations2          {   
                                                                $$ = novo = criar_no(no_funcoes,"FunctionDefinition",NULL);
                                                                adicionar_irmao(novo,$2);
                                                            }
    | FunctionDeclaration FunctionsAndDeclarations2         {
                                                                $$ = novo = criar_no(no_funcoes,"FunctionDeclaration",NULL);
                                                                adicionar_irmao(novo,$2);
                                                            }
    | Declaration  FunctionsAndDeclarations2                {
                                                                adicionar_irmao($$,$2);
                                                            }
    ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody                {   
                                                                ;
                                                            }
    ;

FunctionBody: 
    LBRACE RBRACE                                           {
                                                                ;
                                                            }
    | LBRACE DeclarationsAndStatements RBRACE               {
                                                                ;
                                                            }
    ;

DeclarationsAndStatements:
    StatementsERROR DeclarationsAndStatements               { 
                                                                ;
                                                            }
    | Declaration DeclarationsAndStatements                 {
                                                                ;
                                                            }
    | StatementsERROR                                       {
                                                                ;
                                                            }
    | Declaration                                           {
                                                                ;
                                                            }  
    ;

FunctionDeclaration:
    TypeSpec FunctionDeclarator SEMI                        {
                                                                ;
                                                            }
    ;

FunctionDeclarator:
    IDENTIFIER LPAR ParameterList RPAR                      {
                                                                ;
                                                            }
    ;

ParameterList:
    ParameterDeclaration ParameterList2                     {
                                                                ;
                                                            }      
    ;

ParameterList2: /* empty */                                 {   ; }
    | COMMA ParameterDeclaration ParameterList2             {
                                                                ;
                                                            }
    ;

ParameterDeclaration: 
    TypeSpec                                                {
                                                                ;
                                                            }
    | TypeSpec IDENTIFIER                                   {
                                                                ;
                                                            }
    ;

Declaration:
    TypeSpec Declarator Declaration2 SEMI                   {
                                                                $$ = novo = criar_no(no_funcoes,"Declaration",NULL);
                                                                adicionar_filho(novo,$1);
                                                                adicionar_filho(novo,$2);

                                                                if ($3 != NULL) {
                                                                    struct node *novo2;
                                                                    novo2 = criar_no(no_funcoes,"Declaration",NULL);
                                                                    adicionar_irmao(novo,novo2);
                                                                    adicionar_filho(novo2,$1);
                                                                    adicionar_filho(novo2,$3);
                                                                }
                                                                
                                                            }
    
    | error SEMI                                            {  $$ = NULL; nr_erro = 1;}
    ;

Declaration2: /* empty */                                   {  $$ = NULL;}
    | COMMA Declarator Declaration2                         {
                                                                if ($3 != NULL){
                                                                    $$ = $2;
                                                                }
                                                            }
    ;

TypeSpec: 
    CHAR                                                    {
                                                                $$ = criar_no(no_nterminais,"Char",NULL);
                                                            }
    | INT                                                   {
                                                                $$ = criar_no(no_nterminais,"Int",NULL);
                                                            }
    | VOID                                                  {
                                                                $$ = criar_no(no_nterminais,"Void",NULL);
                                                            }
    | SHORT                                                 {
                                                                $$ = criar_no(no_nterminais,"Short",NULL);
                                                            }
    | DOUBLE                                                {
                                                                $$ = criar_no(no_nterminais,"Double",NULL);
                                                            }
    ;

Declarator:
    IDENTIFIER                                              {
                                                                $$ = criar_no(no_terminais,"Identifier",$1);
                                                            }
    | IDENTIFIER ASSIGN Expr                                {
                                                                $$ = criar_no(no_terminais,"Identifier",$1);
                                                                adicionar_irmao($$,$3);
                                                            }
    ;

StatementsERROR:
    SEMI                                                    {
                                                                ;
                                                            }
    | Expr SEMI                                             {
                                                                ;
                                                            }

    | LBRACE Statement2 RBRACE                              {
                                                                ;
                                                            }

    | IF LPAR Expr RPAR StatementERROR ELSE StatementERROR  {
                                                                ;
                                                            }
    | IF LPAR Expr RPAR StatementERROR                      {
                                                                ;
                                                            }

    | WHILE LPAR Expr RPAR StatementERROR                   {
                                                                ;
                                                            }

    | RETURN Expr SEMI                                      {
                                                                ;
                                                            }
    | RETURN SEMI                                           {
                                                                ;
                                                            }

    | LBRACE error RBRACE                                   {   $$ = NULL; nr_erro = 1;}
    ;

StatementERROR:
    SEMI                                                    {
                                                                ;
                                                            }
    | Expr SEMI                                             {
                                                                ;
                                                            }
    | LBRACE Statement2 RBRACE                              {
                                                                ;
                                                            }
    | IF LPAR Expr RPAR StatementERROR ELSE StatementERROR  {
                                                                ;
                                                            }
    | IF LPAR Expr RPAR StatementERROR                      {
                                                                ;
                                                            }
    
    | WHILE LPAR Expr RPAR StatementERROR                   {
                                                                ;
                                                            }
    | RETURN Expr SEMI                                      {
                                                                ;
                                                            }
    | RETURN SEMI                                           {
                                                                ;
                                                            }
    

    | LBRACE error RBRACE                                   {  $$ = NULL; nr_erro = 1;}
    | error SEMI                                            {  $$ = NULL; nr_erro = 1;}
    ;

Statement2: /* empty */                                     {   ; }
    | StatementERROR Statement2                             {
                                                                ;
                                                            }
    ;

Expr:
    Expr ASSIGN Expr                                        {
                                                                ;
                                                            }
    | Expr COMMA Expr                                       {
                                                                ;
                                                            }
    | Expr PLUS Expr                                        {
                                                                ;
                                                            }
    | Expr MINUS Expr                                       {   
                                                                ;
                                                            }
    | Expr MUL Expr                                         {
                                                                ;
                                                            }
    | Expr DIV Expr                                         {   
                                                                ;
                                                            }
    | Expr MOD Expr                                         {   
                                                                ;
                                                            }

    | Expr OR Expr                                          {
                                                                ;
                                                            }
    | Expr AND Expr                                         {
                                                                ;
                                                            }
    | Expr BITWISEAND Expr                                  {
                                                                ;
                                                            }
    | Expr BITWISEOR Expr                                   {
                                                                ;
                                                            }
    | Expr BITWISEXOR Expr                                  {
                                                                ;
                                                            }

    | Expr EQ Expr                                          {
                                                                ;
                                                            }
    | Expr NE Expr                                          {   
                                                                ;
                                                            }
    | Expr LE Expr                                          {
                                                                ;
                                                            }
    | Expr GE Expr                                          {
                                                                ;
                                                            }
    | Expr LT Expr                                          {
                                                                ;
                                                            }
    | Expr GT Expr                                          {
                                                                ;
                                                            }

    | PLUS Expr                                             {
                                                                ;
                                                            }
    | MINUS Expr                                            {   
                                                                ;
                                                            }
    | NOT Expr                                              {
                                                                ;
                                                            }

    | IDENTIFIER LPAR Expr RPAR                             {
                                                                ;
                                                            }
    | IDENTIFIER LPAR RPAR                                  {
                                                                ;
                                                            }
    
    | IDENTIFIER %prec UNARY                                {
                                                                ;
                                                            }
    | NATURAL                                               {
                                                                ;
                                                            }
    | CHRLIT                                                {
                                                                ;
                                                            }
    | DECIMAL                                               {
                                                                ;
                                                            }
    | LPAR Expr RPAR                                        {
                                                                ;
                                                            }
    
    | IDENTIFIER LPAR error RPAR                            {   $$ = NULL; nr_erro = 1;}
    | LPAR error RPAR                                       {   $$ = NULL; nr_erro = 1;}
    ;
    

%%
