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
int flag = 0;

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
                                if(strcmp(yytext,"char") == 0 && flag == 1)          {printf("CHAR\n");return CHAR;
                            } else if (strcmp(yytext,"else") == 0 && flag == 1)      {printf("ELSE\n");return ELSE;
                            } else if (strcmp(yytext,"while") == 0 && flag == 1)     {printf("WHILE\n");return WHILE;
                            } else if (strcmp(yytext,"if") == 0 && flag == 1)        {printf("IF\n"); return IF;
                            } else if (strcmp(yytext,"int") == 0 && flag == 1)       {printf("INT\n");return INT;
                            } else if (strcmp(yytext,"short") == 0 && flag == 1)     {printf("SHORT\n");return SHORT;
                            } else if (strcmp(yytext,"double") == 0 && flag == 1)    {printf("DOUBLE\n");return DOUBLE;
                            } else if (strcmp(yytext,"return") == 0 && flag == 1)    {printf("RETURN\n");return RETURN;
                            } else if (strcmp(yytext,"void") == 0 && flag == 1)      {printf("VOID\n");return VOID;
                            } else if (strcmp(yytext,"&") == 0 && flag == 1)         {printf("BITWISEAND\n");return BITWISEAND;
                            } else if (strcmp(yytext,"|") == 0 && flag == 1)         {printf("BITWISEOR\n");return BITWISEOR;
                            } else if (strcmp(yytext,"^") == 0 && flag == 1)         {printf("BITWISEXOR\n");return BITWISEXOR;
                            } else if (strcmp(yytext,"&&") == 0 && flag == 1)        {printf("AND\n");return AND;
                            } else if (strcmp(yytext,"=") == 0 && flag == 1)         {printf("ASSIGN\n");return ASSIGN;
                            } else if (strcmp(yytext,"*") == 0 && flag == 1)         {printf("MUL\n");return MUL;
                            } else if (strcmp(yytext,",") == 0 && flag == 1)         {printf("COMMA\n");return COMMA;
                            } else if (strcmp(yytext,"/") == 0 && flag == 1)         {printf("DIV\n");return DIV;
                            } else if (strcmp(yytext,"==") == 0 && flag == 1)        {printf("EQ\n");return EQ;
                            } else if (strcmp(yytext,">=") == 0 && flag == 1)        {printf("GE\n");return GE;
                            } else if (strcmp(yytext,">") == 0 && flag == 1)         {printf("GT\n");return GT;
                            } else if (strcmp(yytext,"{") == 0 && flag == 1)         {printf("LBRACE\n");return LBRACE;
                            } else if (strcmp(yytext,"<=") == 0 && flag == 1)        {printf("LE\n");return LE;
                            } else if (strcmp(yytext,"(") == 0 && flag == 1)         {printf("LPAR\n");return LPAR;
                            } else if (strcmp(yytext,"<") == 0 && flag == 1)         {printf("LT\n");return LT;
                            } else if (strcmp(yytext,"-") == 0 && flag == 1)         {printf("MINUS\n");return MINUS;
                            } else if (strcmp(yytext,"%") == 0 && flag == 1)         {printf("MOD\n");return MOD;
                            } else if (strcmp(yytext,"!=") == 0 && flag == 1)        {printf("NE\n");return NE;
                            } else if (strcmp(yytext,"!") == 0 && flag == 1)         {printf("NOT\n");return NOT;
                            } else if (strcmp(yytext,"||") == 0 && flag == 1)        {printf("OR\n");return OR;
                            } else if (strcmp(yytext,"+") == 0 && flag == 1)         {printf("PLUS\n");return PLUS;
                            } else if (strcmp(yytext,"}") == 0 && flag == 1)         {printf("RBRACE\n");return RBRACE;
                            } else if (strcmp(yytext,")") == 0 && flag == 1)         {printf("RPAR\n");return RPAR;
                            } else if (strcmp(yytext,";") == 0 && flag == 1)         {printf("SEMI\n");return SEMI;
                            } else if (strcmp(yytext,"[") == 0 && flag == 1)         {printf("RESERVED([)\n");return RESERVED;
                            } else if (strcmp(yytext,"]") == 0 && flag == 1)         {printf("RESERVED(])\n");return RESERVED;
                            } else if (strcmp(yytext,"--") == 0 && flag == 1)        {printf("RESERVED(--)\n");return RESERVED;
                            } else if (strcmp(yytext,"++") == 0 && flag == 1)        {printf("RESERVED(++)\n");return RESERVED;
                            } else if (strcmp(yytext,"auto") == 0 && flag == 1)      {printf("RESERVED(auto)\n");return RESERVED;
                            } else if (strcmp(yytext,"break") == 0 && flag == 1)     {printf("RESERVED(break)\n");return RESERVED;
                            } else if (strcmp(yytext,"case") == 0 && flag == 1)      {printf("RESERVED(case)\n");return RESERVED;
                            } else if (strcmp(yytext,"const") == 0 && flag == 1)     {printf("RESERVED(const)\n");return RESERVED;
                            } else if (strcmp(yytext,"continue") == 0 && flag == 1)  {printf("RESERVED(continue)\n");return RESERVED;
                            } else if (strcmp(yytext,"default") == 0 && flag == 1)   {printf("RESERVED(default)\n");return RESERVED;
                            } else if (strcmp(yytext,"do") == 0 && flag == 1)        {printf("RESERVED(do)\n");return RESERVED;
                            } else if (strcmp(yytext,"long") == 0 && flag == 1)      {printf("RESERVED(long)\n");return RESERVED;
                            } else if (strcmp(yytext,"register") == 0 && flag == 1)  {printf("RESERVED(register)\n");return RESERVED;
                            } else if (strcmp(yytext,"signed") == 0 && flag == 1)    {printf("RESERVED(signed)\n");return RESERVED;
                            } else if (strcmp(yytext,"sizeof") == 0 && flag == 1)    {printf("RESERVED(sizeof)\n");return RESERVED;
                            } else if (strcmp(yytext,"static") == 0 && flag == 1)    {printf("RESERVED(static)\n");return RESERVED;
                            } else if (strcmp(yytext,"struct") == 0 && flag == 1)    {printf("RESERVED(struct)\n");return RESERVED;
                            } else if (strcmp(yytext,"switch") == 0 && flag == 1)    {printf("RESERVED(switch)\n");return RESERVED;
                            } else if (strcmp(yytext,"typedef") == 0 && flag == 1)   {printf("RESERVED(typedef)\n");return RESERVED;
                            } else if (strcmp(yytext,"union") == 0 && flag == 1)     {printf("RESERVED(union)\n");return RESERVED;
                            } else if (strcmp(yytext,"unsigned") == 0 && flag == 1)  {printf("RESERVED(unsigned)\n");return RESERVED;
                            } else if (strcmp(yytext,"volatile") == 0 && flag == 1)  {printf("RESERVED(volatile)\n");return RESERVED;
                            } else if (strcmp(yytext,"enum") == 0 && flag == 1)      {printf("RESERVED(enum)\n");return RESERVED;
                            } else if (strcmp(yytext,"extern") == 0 && flag == 1)    {printf("RESERVED(extern)\n");return RESERVED;
                            } else if (strcmp(yytext,"float") == 0 && flag == 1)     {printf("RESERVED(float)\n");return RESERVED;
                            } else if (strcmp(yytext,"for") == 0 && flag == 1)       {printf("RESERVED(for)\n");return RESERVED;
                            } else if (strcmp(yytext,"goto") == 0 && flag == 1)      {printf("RESERVED(goto)\n");return RESERVED;
                            } else if (strcmp(yytext,"inline") == 0 && flag == 1)    {printf("RESERVED(inline)\n");return RESERVED;
                            } else if (strcmp(yytext,"restrict") == 0 && flag == 1)  {printf("RESERVED(restrict)\n");return RESERVED;
                            } else if (strcmp(yytext,"_Bool") == 0 && flag == 1)     {printf("RESERVED(_Bool)\n");return RESERVED;
                            } else if (strcmp(yytext,"_Complex") == 0 && flag == 1)  {printf("RESERVED(_Complex)\n");return RESERVED;
                            } else if (strcmp(yytext,"_Imaginary") == 0 && flag == 1){printf("RESERVED(_Imaginary)\n");return RESERVED;
                            }
                        }

{notdigit}+{alltypes}*                          {   if(flag == 1)printf("IDENTIFIER(%s)\n",yytext); coluna+=yyleng;return IDENTIFIER; } 

{digit}+                                        {   if(flag == 1)printf("NATURAL(%s)\n",yytext);coluna+=yyleng;return NATURAL; } 

{digit}+"."{digit}*{expoente}{signal}?{digit}+  {   if(flag == 1)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;return DECIMAL;}

"."{digit}+{expoente}{signal}?{digit}+          {   if(flag == 1)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;return DECIMAL;}

{digit}+{expoente}{signal}?{digit}+             {   if(flag == 1)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;return DECIMAL;}

{digit}*"."{digit}+                             {   if(flag == 1)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;return DECIMAL; }

{digit}+"."{digit}*                             {   if(flag == 1)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;return DECIMAL;}

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

\'{chrlit}\'                        {if(flag == 1) printf("CHRLIT(%s)\n", yytext); coluna += yyleng;return CHRLIT}
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
            flag = 1;
        }else if (strcmp(argv[i], "-t") == 0){
            flag = 2;
        } else{
            printf("Invalid argument: %s\n", argv[i]);
        }
    }
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}