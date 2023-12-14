%{
/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include "y.tab.h"

#include "uccompiler.h"

int linha = 1;
int coluna = 1;
int linhareserved = 0;
int colunareserved = 0;
int flag = 0;

extern int nr_erro;
extern struct node *raiz;


%}

digit       [0-9]
notdigit    [a-zA-Z_]
alltypes    [a-zA-Z_0-9] 
signal      ("+"|"-")
expoente    ("e"|"E")
notaccepted [^\'\\\n]

chrlit      {notaccepted}|"\\n"|"\\t"|"\\\\"|"\\\'"|"\\\""|"\\"[0-7]{1,3}|\t
reserved    "["|"]"|"++"|"--"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"restrict"|"_Bool"|"_Complex"|"_Imaginary"
enter       (\n|\r|\n\r)

identifier  {notdigit}+{alltypes}*
natural     {digit}+
decimal     {digit}+"."{digit}*{expoente}{signal}?{digit}+|"."{digit}+{expoente}{signal}?{digit}+|{digit}+{expoente}{signal}?{digit}+|{digit}*"."{digit}+|{digit}+"."{digit}*
achrlit     \'{chrlit}\'

char "char"
else "else"
while "while"
if "if"
int "int"
short "short"
double "double"
return "return"
void "void"
bitwiseand "&"
bitwiseor "|"
bitwisexor "^"
and "&&"
assign "="
mul "*"
comma ","
div "/"
eq "=="
ge ">="
gt ">"
lbrace "{"
le "<="
lpar "("
lt "<"
minus "-"
mod "%"
ne "!="
not "!"
or "||"
plus "+"
rbrace "}"
rpar ")"
semi ";"

%X COMMENT
%X COMMENT2

%%

{char}          {if(flag == 1){printf("CHAR\n");}coluna+=yyleng; yylloc.first_column = coluna;if(flag != 1)return CHAR;}
{else}          {if (flag == 1){printf("ELSE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return ELSE;}
{while}         {if (flag == 1){printf("WHILE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return WHILE;}
{if}            {if (flag == 1){printf("IF\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return IF;}
{int}           {if (flag == 1){printf("INT\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return INT;}
{short}         {if (flag == 1){printf("SHORT\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return SHORT;}
{double}        {if (flag == 1){printf("DOUBLE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return DOUBLE;}
{return}        {if (flag == 1){printf("RETURN\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return RETURN;}
{void}          {if (flag == 1){printf("VOID\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return VOID;}
{bitwiseand}    {if (flag == 1){printf("BITWISEAND\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return BITWISEAND;}
{bitwiseor}     {if (flag == 1){printf("BITWISEOR\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return BITWISEOR;}
{bitwisexor}    {if (flag == 1){printf("BITWISEXOR\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return BITWISEXOR;}
{and}           {if (flag == 1){printf("AND\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return AND;}
{assign}        {if (flag == 1){printf("ASSIGN\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return ASSIGN;}
{mul}           {if (flag == 1){printf("MUL\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return MUL;}
{comma}         {if (flag == 1){printf("COMMA\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return COMMA;}
{div}           {if (flag == 1){printf("DIV\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return DIV;}
{eq}            {if (flag == 1){printf("EQ\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return EQ;}
{ge}            {if (flag == 1){printf("GE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return GE;}
{gt}            {if (flag == 1){printf("GT\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return GT;}
{lbrace}        {if (flag == 1){printf("LBRACE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return LBRACE;}
{le}            {if (flag == 1){printf("LE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return LE;}
{lpar}          {if (flag == 1){printf("LPAR\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return LPAR;}
{lt}            {if (flag == 1){printf("LT\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return LT;}
{minus}         {if (flag == 1){printf("MINUS\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return MINUS;}
{mod}           {if (flag == 1){printf("MOD\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return MOD;}
{ne}            {if (flag == 1){printf("NE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return NE;}
{not}           {if (flag == 1){printf("NOT\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return NOT;}
{or}            {if (flag == 1){printf("OR\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return OR;}
{plus}          {if (flag == 1){printf("PLUS\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return PLUS;}
{rbrace}        {if (flag == 1){printf("RBRACE\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return RBRACE;}
{rpar}          {if (flag == 1){printf("RPAR\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return RPAR;}
{semi}          {if (flag == 1){printf("SEMI\n");}coluna+=yyleng;yylloc.first_column = coluna;if(flag != 1)return SEMI;}



{reserved}                                      {   if (flag == 1){
                                                        printf("RESERVED(%s)\n",yytext);
                                                    }
                                                    coluna+=yyleng;
                                                    yylloc.first_column = coluna;
                                                    if(flag != 1){
                                                        yylval.v = strdup(yytext);
                                                        return RESERVED;
                                                    }
                                                }

{identifier}                                    {   if(flag == 1){
                                                        printf("IDENTIFIER(%s)\n",yytext);
                                                    } 
                                                    coluna+=yyleng;
                                                    yylloc.first_column = coluna;
                                                    if(flag != 1){
                                                        yylval.v = strdup(yytext);
                                                        return IDENTIFIER;
                                                    }
                                                } 

{natural}                                       {   if(flag == 1){
                                                        printf("NATURAL(%s)\n",yytext);
                                                    }
                                                    coluna+=yyleng;
                                                    yylloc.first_column = coluna;
                                                    if(flag != 1){ 
                                                        yylval.v = strdup(yytext);
                                                        return NATURAL;
                                                    }
                                                } 

{decimal}                                       {   if(flag == 1){
                                                        printf("DECIMAL(%s)\n", yytext);
                                                    }
                                                    coluna+=yyleng;
                                                    yylloc.first_column = coluna;
                                                    if(flag != 1){ 
                                                        yylval.v = strdup(yytext);
                                                        return DECIMAL;
                                                    }
                                                }

{enter}                 {   linha++;coluna = 1;yylloc.first_line =  linha;yylloc.first_column = coluna;}

[ \t\n]                 {   coluna+=yyleng;yylloc.first_column = coluna;}

"/*"                    {   BEGIN(COMMENT); colunareserved = coluna; linhareserved = linha; coluna+=yyleng;yylloc.first_column = coluna;}
"//"                    {   BEGIN(COMMENT2); colunareserved = coluna; linhareserved = linha; coluna+=yyleng;yylloc.first_column = coluna;}

<COMMENT>\n|\r|(\n\r)   {   coluna = 1; linha++;yylloc.first_line =  linha;yylloc.first_column = coluna;}

<COMMENT>"*/"           {   BEGIN(INITIAL); coluna+=yyleng;yylloc.first_column = coluna;}

<COMMENT>.              {   coluna+= yyleng; yylloc.first_column = coluna;}

<COMMENT><<EOF>>        {   
                            printf("Line %d, column %d: unterminated comment\n",linhareserved,colunareserved);
                            return 0;
                        }

<COMMENT2>.             {   coluna+=yyleng;yylloc.first_column = coluna;}
<COMMENT2>\n|\r|(\n\r)  {   BEGIN(INITIAL); coluna = 1; linha++;yylloc.first_column = coluna;yylloc.first_line =  linha;}

{achrlit}                           {if(flag == 1){printf("CHRLIT(%s)\n", yytext);} coluna += yyleng;yylloc.first_column = coluna;if(flag != 1){yylval.v = strdup(yytext);return CHRLIT;}}
'(({chrlit})*|([^\n\r'])*)          {printf("Line %d, column %d: unterminated char constant\n", linha, coluna); coluna += yyleng; yylloc.first_column = coluna;}
'({chrlit}|\\[^\n'])*'              {printf("Line %d, column %d: invalid char constant (%s)\n", linha, coluna, yytext); coluna += yyleng; yylloc.first_column = coluna;}

.                                   { 
                                        printf("Line %d, column %d: unrecognized character (%s)\n",linha,coluna,yytext);
                                        coluna+=yyleng; 
                                        yylloc.first_column = coluna; 
                                    }

%%
extern int yylex();

void yyerror(const char *s) {
    printf("Line %d, column %d: %s: %s\n" ,linha,(int)(coluna-strlen(yytext)), s , yytext); 
}

int yywrap() {  /* called on EOF, return 1 to terminate */
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            flag = 1;
            yylex();
        }   
        else if(strcmp(argv[1], "-t") == 0){
            flag = 2;
            yyparse();
            if(nr_erro == 0){
                imprime_arvore(raiz,0);
            }
        } else if (strcmp(argv[1], "-s") == 0){
            flag = 2;
            yyparse();
            if(nr_erro == 0){
                struct tabela t = criar_tabela(raiz);
                imprime_tabela(&t);
                imprime_arvore(raiz,0);
            }
        }
    }
    if (argc == 1){
        flag = 0;
        yyparse();
        yylex();
    }
    
    return 0;
}
