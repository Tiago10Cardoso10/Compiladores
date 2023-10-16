%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int linha = 1;
int coluna = 0;
int comment = 0;
int linhareserved = 0;
int colunareserved = 0;
int more = 0;

char agrupar[100];

%}

digit       [0-9]
notdigit    [a-zA-Z_]
alltypes    [a-zA-Z_0-9] 
signal      ("+"|"-")
expoente    ("e"|"E")


reserved    ("char"|"else"|"while"|"if"|"int"|"short"|"double"|"return"|"void"|"&"|"|"|"^"|"&&"|"="|"*"|","|"/"|"=="|">="|">"|"{"|"<="|"("|")"|"<"|"-"|"%"|"!="|"!"|"||"|"+"|"}"|";"|"["|"]"|"++"|"--")

%X COMMENT
%X COMMENT2
%X CHRLIT

enter ("\n"|"\r")

%%

"/*"                    {   comment = 1; BEGIN(COMMENT); colunareserved = coluna + 1; linhareserved = linha; coluna+=2;}
"//"                    {   BEGIN(COMMENT2); colunareserved = coluna + 1; linhareserved = linha; coluna+=2;}
"'"                     {   BEGIN(CHRLIT); colunareserved = coluna + 1; linhareserved = linha; coluna++;}

<COMMENT>\n             {   coluna = 0; linha++;}

<COMMENT>"*/"           {   comment = 0; BEGIN(INITIAL); coluna+=2;}

<COMMENT>.              {   coluna++; }

<COMMENT><<EOF>>        {   if (comment){
                                printf("Line %d, column %d: unterminated comment\n",linhareserved,colunareserved);
                            }   
                            yyterminate();}

<COMMENT2>. {coluna++;}
<COMMENT2>\n {BEGIN(INITIAL); coluna = 0; linha++;}

<CHRLIT>([^'\n\\]|\\([nt\\\'\"]|[0-7]{1,3}))\'      { printf("CHRLIT('%s)\n", yytext);
                                                    coluna += yyleng;
                                                    BEGIN(INITIAL); }

<CHRLIT>.*\'                {printf("Line %d, column %d: invalid char constant ('%s)\n", linha ,coluna, yytext);
                            coluna+=yyleng;
                            BEGIN(INITIAL); }

<CHRLIT>\n                  {printf("Line %d, column %d: unterminated char constant\n", linha, coluna);
                            coluna += yyleng; 
                            linha++;
                            BEGIN(INITIAL); }

<CHRLIT>.                   {printf("Line %d, column %d: unterminated char constant ('%s)\n", linha, coluna, yytext);
                            coluna += yyleng; 
                            BEGIN(INITIAL); }

{reserved}              {   if(strcmp(yytext,"char") == 0)          {printf("CHAR\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"else") == 0)  {printf("ELSE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"while") == 0) {printf("WHILE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"if") == 0)    {printf("IF\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"int") == 0)   {printf("INT\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"short") == 0) {printf("SHORT\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"double") == 0){printf("DOUBLE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"return") == 0){printf("RETURN\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"void") == 0)  {printf("VOID\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"&") == 0)     {printf("BITWISEAND\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"|") == 0)     {printf("BITWISEOR\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"^") == 0)     {printf("BITWISEXOR\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"&&") == 0)    {printf("AND\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"=") == 0)     {printf("ASSIGN\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"*") == 0)     {printf("MUL\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,",") == 0)     {printf("COMMA\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"/") == 0)     {printf("DIV\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"==") == 0)    {printf("EQ\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,">=") == 0)    {printf("GE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,">") == 0)     {printf("GT\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"{") == 0)     {printf("LBRACE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"<=") == 0)    {printf("LE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"(") == 0)     {printf("LPAR\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"<") == 0)     {printf("LT\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"-") == 0)     {printf("MINUS\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"%") == 0)     {printf("MOD\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"!=") == 0)    {printf("NE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"!") == 0)     {printf("NOT\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"||") == 0)    {printf("OR\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"+") == 0)     {printf("PLUS\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"}") == 0)     {printf("RBRACE\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,")") == 0)     {printf("RPAR\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,";") == 0)     {printf("SEMI\n");coluna+=yyleng;;
                            }  else if (strcmp(yytext,"[") == 0)    {printf("RESERVED\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"]") == 0)     {printf("RESERVED\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"--") == 0)    {printf("RESERVED\n");coluna+=yyleng;;
                            } else if (strcmp(yytext,"++") == 0)    {printf("RESERVED\n");coluna+=yyleng;;
                            } 
                        }

{notdigit}+{alltypes}*                          {   printf("IDENTIFIER(%s)\n",yytext); coluna+=yyleng;}

{digit}+                                        {   printf("NATURAL(%s)\n",yytext);coluna+=yyleng;}

{digit}+"."{digit}*{expoente}{signal}*{digit}+    {   printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;}

"."{digit}+{expoente}{signal}*{digit}+          {   printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;}

{digit}+{expoente}{signal}*{digit}+             {   printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;}

{digit}*"."{digit}+                             {   printf("DECIMAL(%s)\n", yytext);coluna+=yyleng; }

{enter}*                {   linha++;coluna = 0;}

[ \t\n]                 { coluna++;}

.                       { 
                            coluna++;
                            printf("Line %d, column %d: unrecognized character (%s)\n",linha,coluna,yytext); 
                        }

%%



extern int yylex();
int main() {
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}
