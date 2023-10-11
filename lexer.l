%{
#include <stdio.h>
#include <ctype.h>

int linha = 1;
int coluna = 0;

%}


digit   [0-9]
notdigit [a-zA-Z]           
alltypes [a-zA-Z0-9]
tokens ("integer"|"double"|"if"|"else"|"then")
puct ("("|")"|"="|","|"*"|"/"|"+"|"-")
escape ("\\f"|"\\n"|"\\r"|"\\t"|"\\\\"|"\\")
enter ("\n"|\r\n|\r)
signal ("+"|"-")
expoente ("e"|"E")


%X COMMENT

%%


"/*" { BEGIN(COMMENT);coluna+=2; }
<COMMENT>. { coluna++; }
<COMMENT>\n { coluna=0;linha++; }
<COMMENT>"*/" { BEGIN(INITIAL);coluna+=2; }

{puct}+                     {   
                                printf("%s\n", yytext);
                                coluna++;
                            }

{tokens}+                   {
                                int i;
                                for (i = 0; yytext[i]; i++) {
                                    yytext[i] = toupper(yytext[i]);
                                }
                                printf("%s\n", yytext);
                                coluna++;
                            }

{digit}+"."{digit}*{expoente}{signal}*{digit}+ {
                                printf("DECIMAL(%s)\n", yytext);
                                coluna++;
                            }

"."{digit}+{expoente}{signal}*{digit}+         {
                                printf("DECIMAL(%s)\n", yytext);
                                coluna++;
                            }

{digit}+{expoente}{signal}*{digit}+            {
                                printf("DECIMAL(%s)\n", yytext);
                                coluna++;
                            }

{digit}+                    {
                                printf("NATURAL(%s)\n", yytext);
                                coluna++;
                            }  

{digit}*"."{digit}+         {   printf("DECIMAL(%s)\n", yytext);
                                coluna++; 
                            }

{notdigit}+{alltypes}*      {
                                printf("IDENTIFIER(%s)\n", yytext);
                                coluna++; 
                            }

{notdigit}+{escape}      {
                                printf("%s\n", yytext);
                                coluna++; 
                            }

{enter}*                    {   
                                linha++;
                                coluna = 0;
                            }

[ \t\n]                     { 
                                coluna++;
                            }
.                           { 
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
