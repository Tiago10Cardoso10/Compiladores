%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int linha = 1;
int coluna = 0;

char agrupar[100];

%}

digit       [0-9]
notdigit    [a-zA-Z_]
alltypes    [a-zA-Z_0-9] 
signal      ("+"|"-")
expoente    ("e"|"E")


reserved    ("char"|"else"|"while"|"if"|"int"|"short"|"double"|"return"|"void"|"&"|"|"|"^"|"&&"|"="|"*"|","|"/"|"=="|">="|">"|"{"|"<="|"("|")"|"<"|"-"|"%"|"!="|"!"|"||"|"+"|"}"|";"|"["|"]"|"++"|"--")

%X COMMENT
%X LETTER


enter ("\n"|"\r")

%%

"/*"                    { 
                            BEGIN(COMMENT); 
                            coluna+=2;
                        }

<COMMENT>.              {
                            coluna++;
                        }

<COMMENT>\n             {
                            coluna = 0;
                            linha++;
                        }

<COMMENT>"*/"           { 
                            BEGIN(INITIAL);
                            coluna+=2;
                        }

{reserved}             {
                            if(strcmp(yytext,"char") == 0){
                                printf("CHAR\n");
                                coluna += 4;
                            } else if (strcmp(yytext,"else") == 0){
                                printf("ELSE\n");
                                coluna += 4;
                            } else if (strcmp(yytext,"while") == 0){
                                printf("WHILE\n");
                                coluna += 5;
                            } else if (strcmp(yytext,"if") == 0){
                                printf("IF\n");
                                coluna += 2;
                            } else if (strcmp(yytext,"int") == 0){
                                printf("INT\n");
                                coluna += 3;
                            } else if (strcmp(yytext,"short") == 0){
                                printf("SHORT\n");
                                coluna += 5;
                            } else if (strcmp(yytext,"double") == 0){
                                printf("DOUBLE\n");
                                coluna += 6;
                            } else if (strcmp(yytext,"return") == 0){
                                printf("RETURN\n");
                                coluna += 6;
                            } else if (strcmp(yytext,"void") == 0){
                                printf("VOID\n");   
                                coluna += 4;
                            } else if (strcmp(yytext,"&") == 0){
                                printf("BITWISEAND\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"|") == 0){
                                printf("BITWISEOR\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"^") == 0){
                                printf("BITWISEXOR\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"&&") == 0){
                                printf("AND\n");
                                coluna += 2;
                            } else if (strcmp(yytext,"=") == 0){
                                printf("ASSIGN\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"*") == 0){
                                printf("MUL\n");
                                coluna += 1;
                            } else if (strcmp(yytext,",") == 0){
                                printf("COMMA\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"/") == 0){
                                printf("DIV\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"==") == 0){
                                printf("EQ\n");
                                coluna += 2;
                            } else if (strcmp(yytext,">=") == 0){
                                printf("GE\n");
                                coluna += 2;
                            } else if (strcmp(yytext,">") == 0){
                                printf("GT\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"{") == 0){
                                printf("LBRACE\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"<=") == 0){
                                printf("LE\n");
                                coluna += 2;
                            } else if (strcmp(yytext,"(") == 0){
                                printf("LPAR\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"<") == 0){
                                printf("LT\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"-") == 0){
                                printf("MINUS\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"%") == 0){
                                printf("MOD\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"!=") == 0){
                                printf("NE\n");
                                coluna += 2;
                            } else if (strcmp(yytext,"!") == 0){
                                printf("NOT\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"||") == 0){
                                printf("OR\n");
                                coluna += 2;
                            } else if (strcmp(yytext,"+") == 0){
                                printf("PLUS\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"}") == 0){
                                printf("RBRACE\n");
                                coluna += 1;
                            } else if (strcmp(yytext,")") == 0){
                                printf("RPAR\n");
                                coluna += 1;
                            } else if (strcmp(yytext,";") == 0){
                                printf("SEMI\n");
                                coluna += 1;
                            }  else if (strcmp(yytext,"[") == 0){
                                printf("RESERVED\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"]") == 0){
                                printf("RESERVED\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"--") == 0){
                                printf("RESERVED\n");
                                coluna += 1;
                            } else if (strcmp(yytext,"++") == 0){
                                printf("RESERVED\n");
                                coluna += 1;
                            } 
                        }

{notdigit}+{alltypes}*                          {
                                                    printf("IDENTIFIER(%s)\n",yytext);
                                                    coluna++;
                                                }

{digit}+                                        {
                                                    printf("NATURAL(%s)\n",yytext);
                                                    coluna++;
                                                }

{digit}*"."{digit}+                             {   
                                                    printf("DECIMAL(%s)\n", yytext);
                                                    coluna++; 
                                                }

{digit}+"."{digit}{expoente}{signal}{digit}+    {
                                                    printf("DECIMAL(%s)\n", yytext);
                                                    coluna++;
                                                }

"."{digit}+{expoente}{signal}*{digit}+          {
                                                    printf("DECIMAL(%s)\n", yytext);
                                                    coluna++;
                                                }

{digit}+{expoente}{signal}*{digit}+             {
                                                    printf("DECIMAL(%s)\n", yytext);
                                                    coluna++;
                                                }

{enter}*                {   
                            linha++;
                            coluna = 0;
                        }

[ \t\n]                 { 
                            coluna++;
                        }

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
