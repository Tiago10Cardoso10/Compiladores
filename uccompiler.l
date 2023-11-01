%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679

*/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int linha = 1;
int coluna = 1;
int linhareserved = 0;
int colunareserved = 0;
int l_flag = 0;

%}

%{
#include "y.tab.h"
int yyparse(void);
%}

digit       [0-9]
notdigit    [a-zA-Z_]
alltypes    [a-zA-Z_0-9] 
signal      ("+"|"-")
expoente    ("e"|"E")
notaccepted [^\'\\\n]
chrlit      {notaccepted}|"\\n"|"\\t"|"\\\\"|"\\\'"|"\\\""|"\\"[0-7]{1,3}|\t
reserved    ("char"|"else"|"while"|"if"|"int"|"short"|"double"|"return"|"void"|"&"|"|"|"^"|"&&"|"="|"*"|","|"/"|"=="|">="|">"|"{"|"<="|"("|")"|"<"|"-"|"%"|"!="|"!"|"||"|"+"|"}"|";"|"["|"]"|"++"|"--"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"restrict"|"_Bool"|"_Complex"|"_Imaginary")
enter       (\n|\r|\n\r)

%X COMMENT
%X COMMENT2

%%

{reserved}              {   coluna+=yyleng;
                                if(strcmp(yytext,"char") == 0 && l_flag)          {printf("CHAR\n");
                            } else if (strcmp(yytext,"else") == 0 && l_flag)      {printf("ELSE\n");
                            } else if (strcmp(yytext,"while") == 0 && l_flag)     {printf("WHILE\n");
                            } else if (strcmp(yytext,"if") == 0 && l_flag)        {printf("IF\n");
                            } else if (strcmp(yytext,"int") == 0 && l_flag)       {printf("INT\n");
                            } else if (strcmp(yytext,"short") == 0 && l_flag)     {printf("SHORT\n");
                            } else if (strcmp(yytext,"double") == 0 && l_flag)    {printf("DOUBLE\n");
                            } else if (strcmp(yytext,"return") == 0 && l_flag)    {printf("RETURN\n");
                            } else if (strcmp(yytext,"void") == 0 && l_flag)      {printf("VOID\n");
                            } else if (strcmp(yytext,"&") == 0 && l_flag)         {printf("BITWISEAND\n");
                            } else if (strcmp(yytext,"|") == 0 && l_flag)         {printf("BITWISEOR\n");
                            } else if (strcmp(yytext,"^") == 0 && l_flag)         {printf("BITWISEXOR\n");
                            } else if (strcmp(yytext,"&&") == 0 && l_flag)        {printf("AND\n");
                            } else if (strcmp(yytext,"=") == 0 && l_flag)         {printf("ASSIGN\n");
                            } else if (strcmp(yytext,"*") == 0 && l_flag)         {printf("MUL\n");
                            } else if (strcmp(yytext,",") == 0 && l_flag)         {printf("COMMA\n");
                            } else if (strcmp(yytext,"/") == 0 && l_flag)         {printf("DIV\n");
                            } else if (strcmp(yytext,"==") == 0 && l_flag)        {printf("EQ\n");
                            } else if (strcmp(yytext,">=") == 0 && l_flag)        {printf("GE\n");
                            } else if (strcmp(yytext,">") == 0 && l_flag)         {printf("GT\n");
                            } else if (strcmp(yytext,"{") == 0 && l_flag)         {printf("LBRACE\n");
                            } else if (strcmp(yytext,"<=") == 0 && l_flag)        {printf("LE\n");
                            } else if (strcmp(yytext,"(") == 0 && l_flag)         {printf("LPAR\n");
                            } else if (strcmp(yytext,"<") == 0 && l_flag)         {printf("LT\n");
                            } else if (strcmp(yytext,"-") == 0 && l_flag)         {printf("MINUS\n");
                            } else if (strcmp(yytext,"%") == 0 && l_flag)         {printf("MOD\n");
                            } else if (strcmp(yytext,"!=") == 0 && l_flag)        {printf("NE\n");
                            } else if (strcmp(yytext,"!") == 0 && l_flag)         {printf("NOT\n");
                            } else if (strcmp(yytext,"||") == 0 && l_flag)        {printf("OR\n");
                            } else if (strcmp(yytext,"+") == 0 && l_flag)         {printf("PLUS\n");
                            } else if (strcmp(yytext,"}") == 0 && l_flag)         {printf("RBRACE\n");
                            } else if (strcmp(yytext,")") == 0 && l_flag)         {printf("RPAR\n");
                            } else if (strcmp(yytext,";") == 0 && l_flag)         {printf("SEMI\n");
                            } else if (strcmp(yytext,"[") == 0 && l_flag)        {printf("RESERVED([)\n");
                            } else if (strcmp(yytext,"]") == 0 && l_flag)         {printf("RESERVED(])\n");
                            } else if (strcmp(yytext,"--") == 0 && l_flag)        {printf("RESERVED(--)\n");
                            } else if (strcmp(yytext,"++") == 0 && l_flag)        {printf("RESERVED(++)\n");
                            } else if (strcmp(yytext,"auto") == 0 && l_flag)      {printf("RESERVED(auto)\n");
                            } else if (strcmp(yytext,"break") == 0 && l_flag)     {printf("RESERVED(break)\n");
                            } else if (strcmp(yytext,"case") == 0 && l_flag)      {printf("RESERVED(case)\n");
                            } else if (strcmp(yytext,"const") == 0 && l_flag)     {printf("RESERVED(const)\n");
                            } else if (strcmp(yytext,"continue") == 0 && l_flag)  {printf("RESERVED(continue)\n");
                            } else if (strcmp(yytext,"default") == 0 && l_flag)   {printf("RESERVED(default)\n");
                            } else if (strcmp(yytext,"do") == 0 && l_flag)        {printf("RESERVED(do)\n");
                            } else if (strcmp(yytext,"long") == 0 && l_flag)      {printf("RESERVED(long)\n");
                            } else if (strcmp(yytext,"register") == 0 && l_flag)  {printf("RESERVED(register)\n");
                            } else if (strcmp(yytext,"signed") == 0 && l_flag)    {printf("RESERVED(signed)\n");
                            } else if (strcmp(yytext,"sizeof") == 0 && l_flag)    {printf("RESERVED(sizeof)\n");
                            } else if (strcmp(yytext,"static") == 0 && l_flag)    {printf("RESERVED(static)\n");
                            } else if (strcmp(yytext,"struct") == 0 && l_flag)    {printf("RESERVED(struct)\n");
                            } else if (strcmp(yytext,"switch") == 0 && l_flag)    {printf("RESERVED(switch)\n");
                            } else if (strcmp(yytext,"typedef") == 0 && l_flag)   {printf("RESERVED(typedef)\n");
                            } else if (strcmp(yytext,"union") == 0 && l_flag)     {printf("RESERVED(union)\n");
                            } else if (strcmp(yytext,"unsigned") == 0 && l_flag)  {printf("RESERVED(unsigned)\n");
                            } else if (strcmp(yytext,"volatile") == 0 && l_flag)  {printf("RESERVED(volatile)\n");
                            } else if (strcmp(yytext,"enum") == 0 && l_flag)      {printf("RESERVED(enum)\n");
                            } else if (strcmp(yytext,"extern") == 0 && l_flag)    {printf("RESERVED(extern)\n");
                            } else if (strcmp(yytext,"float") == 0 && l_flag)     {printf("RESERVED(float)\n");
                            } else if (strcmp(yytext,"for") == 0 && l_flag)       {printf("RESERVED(for)\n");
                            } else if (strcmp(yytext,"goto") == 0 && l_flag)      {printf("RESERVED(goto)\n");
                            } else if (strcmp(yytext,"inline") == 0 && l_flag)    {printf("RESERVED(inline)\n");
                            } else if (strcmp(yytext,"restrict") == 0 && l_flag)  {printf("RESERVED(restrict)\n");
                            } else if (strcmp(yytext,"_Bool") == 0 && l_flag)     {printf("RESERVED(_Bool)\n");
                            } else if (strcmp(yytext,"_Complex") == 0 && l_flag)  {printf("RESERVED(_Complex)\n");
                            } else if (strcmp(yytext,"_Imaginary") == 0 && l_flag){printf("RESERVED(_Imaginary)\n");
                            }
                        }

{notdigit}+{alltypes}*                          {   if(l_flag)printf("IDENTIFIER(%s)\n",yytext); coluna+=yyleng;}

{digit}+                                        {   if(l_flag)printf("NATURAL(%s)\n",yytext);coluna+=yyleng;}

{digit}+"."{digit}*{expoente}{signal}?{digit}+  {   if(l_flag)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;}

"."{digit}+{expoente}{signal}?{digit}+          {   if(l_flag)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;}

{digit}+{expoente}{signal}?{digit}+             {   if(l_flag)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;}

{digit}*"."{digit}+                             {   if(l_flag)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng; }

{digit}+"."{digit}*                             {   if(l_flag)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng; }

{enter}                 {   linha++;coluna = 1;}

[ \t\n]                 {   coluna+=yyleng;}

"/*"                    {   BEGIN(COMMENT); colunareserved = coluna; linhareserved = linha; coluna+=yyleng;}
"//"                    {   BEGIN(COMMENT2); colunareserved = coluna; linhareserved = linha; coluna+=yyleng;}

<COMMENT>\n|\r|(\n\r)             {   coluna = 1; linha++;}

<COMMENT>"*/"           {   BEGIN(INITIAL); coluna+=yyleng;}

<COMMENT>.              {   coluna+= yyleng; }

<COMMENT><<EOF>>        {   
                            printf("Line %d, column %d: unterminated comment\n",linhareserved,colunareserved);
                            yyterminate();
                        }

<COMMENT2>.             {   coluna+=yyleng;}
<COMMENT2>\n|\r|(\n\r)  {   BEGIN(INITIAL); coluna = 1; linha++;}

\'{chrlit}\'                        {if(l_flag) printf("CHRLIT(%s)\n", yytext); coluna += yyleng;}
'(({chrlit})*|([^\n\r'])*)          {printf("Line %d, column %d: unterminated char constant\n", linha, coluna); coluna += yyleng; }
'({chrlit}|\\[^\n'])*'              {printf("Line %d, column %d: invalid char constant (%s)\n", linha, coluna, yytext); coluna += yyleng; }
.                                   { 
                                        printf("Line %d, column %d: unrecognized character (%s)\n",linha,coluna,yytext);
                                        coluna+=yyleng;  
                                    }

%%

extern int yylex();
int main(int argc, char* argv[]) {
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "-l") == 0){
            l_flag = 1;
        }else{
            printf("Invalid argument: %s\n", argv[i]);
        }
    }
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
