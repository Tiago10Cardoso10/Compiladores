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
#include "y.tab.h"

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
especial    ("char"|"else"|"while"|"if"|"int"|"short"|"double"|"return"|"void"|"&"|"|"|"^"|"&&"|"="|"*"|","|"/"|"=="|">="|">"|"{"|"<="|"("|")"|"<"|"-"|"%"|"!="|"!"|"||"|"+"|"}"|";")
reserved    ("["|"]"|"++"|"--"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"restrict"|"_Bool"|"_Complex"|"_Imaginary")
enter       (\n|\r|\n\r)

identifier  {notdigit}+{alltypes}*
natural     {digit}+
decimal     {digit}+"."{digit}*{expoente}{signal}?{digit}+|"."{digit}+{expoente}{signal}?{digit}+|{digit}+{expoente}{signal}?{digit}+|{digit}*"."{digit}+|{digit}+"."{digit}*
achrlit     \'{chrlit}\'

%X COMMENT
%X COMMENT2

%%

{especial}              {   coluna+=yyleng;
                                if(strcmp(yytext,"char") == 0 && flag == 1)          {printf("CHAR\n");if(flag == 2){return CHAR;}
                            } else if (strcmp(yytext,"else") == 0 && flag == 1)      {printf("ELSE\n");if(flag == 2){return ELSE;}
                            } else if (strcmp(yytext,"while") == 0 && flag == 1)     {printf("WHILE\n");if(flag == 2){return WHILE;}
                            } else if (strcmp(yytext,"if") == 0 && flag == 1)        {printf("IF\n");if(flag == 2) {return IF;}
                            } else if (strcmp(yytext,"int") == 0 && flag == 1)       {printf("INT\n");if(flag == 2){return INT;}
                            } else if (strcmp(yytext,"short") == 0 && flag == 1)     {printf("SHORT\n");if(flag == 2){return SHORT;}
                            } else if (strcmp(yytext,"double") == 0 && flag == 1)    {printf("DOUBLE\n");if(flag == 2){return DOUBLE;}
                            } else if (strcmp(yytext,"return") == 0 && flag == 1)    {printf("RETURN\n");if(flag == 2){return RETURN;}
                            } else if (strcmp(yytext,"void") == 0 && flag == 1)      {printf("VOID\n");if(flag == 2){return VOID;}
                            } else if (strcmp(yytext,"&") == 0 && flag == 1)         {printf("BITWISEAND\n");if(flag == 2){return BITWISEAND;}
                            } else if (strcmp(yytext,"|") == 0 && flag == 1)         {printf("BITWISEOR\n");if(flag == 2){return BITWISEOR;}
                            } else if (strcmp(yytext,"^") == 0 && flag == 1)         {printf("BITWISEXOR\n");if(flag == 2){return BITWISEXOR;}
                            } else if (strcmp(yytext,"&&") == 0 && flag == 1)        {printf("AND\n");if(flag == 2){return AND;}
                            } else if (strcmp(yytext,"=") == 0 && flag == 1)         {printf("ASSIGN\n");if(flag == 2){return ASSIGN;}
                            } else if (strcmp(yytext,"*") == 0 && flag == 1)         {printf("MUL\n");if(flag == 2){return MUL;}
                            } else if (strcmp(yytext,",") == 0 && flag == 1)         {printf("COMMA\n");if(flag == 2){return COMMA;}
                            } else if (strcmp(yytext,"/") == 0 && flag == 1)         {printf("DIV\n");if(flag == 2){return DIV;}
                            } else if (strcmp(yytext,"==") == 0 && flag == 1)        {printf("EQ\n");if(flag == 2){return EQ;}
                            } else if (strcmp(yytext,">=") == 0 && flag == 1)        {printf("GE\n");if(flag == 2){return GE;}
                            } else if (strcmp(yytext,">") == 0 && flag == 1)         {printf("GT\n");if(flag == 2){return GT;}
                            } else if (strcmp(yytext,"{") == 0 && flag == 1)         {printf("LBRACE\n");if(flag == 2){return LBRACE;}
                            } else if (strcmp(yytext,"<=") == 0 && flag == 1)        {printf("LE\n");if(flag == 2){return LE;}
                            } else if (strcmp(yytext,"(") == 0 && flag == 1)         {printf("LPAR\n");if(flag == 2){return LPAR;}
                            } else if (strcmp(yytext,"<") == 0 && flag == 1)         {printf("LT\n");if(flag == 2){return LT;}
                            } else if (strcmp(yytext,"-") == 0 && flag == 1)         {printf("MINUS\n");if(flag == 2){return MINUS;}
                            } else if (strcmp(yytext,"%") == 0 && flag == 1)         {printf("MOD\n");if(flag == 2){return MOD;}
                            } else if (strcmp(yytext,"!=") == 0 && flag == 1)        {printf("NE\n");if(flag == 2){return NE;}
                            } else if (strcmp(yytext,"!") == 0 && flag == 1)         {printf("NOT\n");if(flag == 2){return NOT;}
                            } else if (strcmp(yytext,"||") == 0 && flag == 1)        {printf("OR\n");if(flag == 2){return OR;}
                            } else if (strcmp(yytext,"+") == 0 && flag == 1)         {printf("PLUS\n");if(flag == 2){return PLUS;}
                            } else if (strcmp(yytext,"}") == 0 && flag == 1)         {printf("RBRACE\n");if(flag == 2){return RBRACE;}
                            } else if (strcmp(yytext,")") == 0 && flag == 1)         {printf("RPAR\n");if(flag == 2){return RPAR;}
                            } else if (strcmp(yytext,";") == 0 && flag == 1)         {printf("SEMI\n");if(flag == 2){return SEMI;}}
                            }

{reserved}                                      {if (flag == 1){printf("RESERVED(%s)\n",yytext);if(flag == 2){yylval.v = strdup(yytext);return RESERVED;}}}

{identifier}                                    {   if(flag == 1)printf("IDENTIFIER(%s)\n",yytext); coluna+=yyleng;if(flag == 2){yylval.v = strdup(yytext);return IDENTIFIER;}} 

{natural}                                       {   if(flag == 1)printf("NATURAL(%s)\n",yytext);coluna+=yyleng;if(flag == 2){yylval.v = strdup(yytext);return NATURAL;}} 

{decimal}                                       {   if(flag == 1)printf("DECIMAL(%s)\n", yytext);coluna+=yyleng;if(flag == 2){yylval.v = strdup(yytext);return DECIMAL;}}

{enter}                 {   linha++;coluna = 1;}

[ \t\n]                 {   coluna+=yyleng;}

"/*"                    {   BEGIN(COMMENT); colunareserved = coluna; linhareserved = linha; coluna+=yyleng;}
"//"                    {   BEGIN(COMMENT2); colunareserved = coluna; linhareserved = linha; coluna+=yyleng;}

<COMMENT>\n|\r|(\n\r)   {   coluna = 1; linha++;}

<COMMENT>"*/"           {   BEGIN(INITIAL); coluna+=yyleng;}

<COMMENT>.              {   coluna+= yyleng; }

<COMMENT><<EOF>>        {   
                            printf("Line %d, column %d: unterminated comment\n",linhareserved,colunareserved);
                            yyterminate();
                        }

<COMMENT2>.             {   coluna+=yyleng;}
<COMMENT2>\n|\r|(\n\r)  {   BEGIN(INITIAL); coluna = 1; linha++;}

{achrlit}                           {if(flag == 1) printf("CHRLIT(%s)\n", yytext); coluna += yyleng;if(flag == 2){yylval.v = strdup(yytext);return CHRLIT;}}
'(({chrlit})*|([^\n\r'])*)          {printf("Line %d, column %d: unterminated char constant\n", linha, coluna); coluna += yyleng; }
'({chrlit}|\\[^\n'])*'              {printf("Line %d, column %d: invalid char constant (%s)\n", linha, coluna, yytext); coluna += yyleng; }
.                                   { 
                                        printf("Line %d, column %d: unrecognized character (%s)\n",linha,coluna,yytext);
                                        coluna+=yyleng;  
                                    }

%%

void yyerror(const char *s) { 
    printf ( "Line %d ,column %d: %s: %s\n " ,linha,(int)(coluna-strlen(yytext)), s , yytext );

}

int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}

extern int yylex();
int main(int argc, char* argv[]) {
    for(int i=1; i<argc; i++){
        if(strcmp(argv[i], "-l") == 0){
            flag = 1;
            yylex();  /* run the lexical analysis automaton */
        }else if (strcmp(argv[i], "-t") == 0){
            flag = 2;
            yyparse();   
        } 
    }
    if(argc == 1){
            yyparse();
            yylex();
    }
    
    return 0;
}
