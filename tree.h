#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "y.tab.h"

typedef enum{
    no_raiz,
    no_declaracao,
    no_metodos,
    no_Statement2,
    no_operadores,
    no_terminais,
    no_id
} tipo_no;

typedef struct no *node;

typedef struct no{
    node pai;
    node filho;
    node irmao;
    tipo_no no_tipo;
    char *valor;           
    char *tipo;            
    char *tipo_anotada;
} no;

typedef struct metodo{
    char *tipo;
    char *nome_class;
    char *nome_funcao;
    char *tipo_retorna;
    char **tipo_param;
    char **nome_param;
    int num_param;
    char *variavel;
    struct metodo *proximo_metodo;
}metodo;

typedef struct lista{
    metodo *inicio;
}lista;

node criar_no(tipo_no no_tipo, char *valor, char *tipo);
void adicionar_irmao(node novo, node irmao);
void adicionar_filho(node pai, node novo);
int conta_irmaos(node raiz);
void imprime_arvore(node raiz, int num);

void imprime_tabela(lista *l);
lista criar_tabela(node raiz);
void metodo_decl(node r2, lista *l, char *nome_class);
void metodo_header(metodo *tabela, node r2);
void metodo_body(metodo *tabela, node r2);
char *type(char *type);
void imprime_parametros(char **p, int num);
void field_decl(node cr7, lista *l, char *nome_class);
bool verifica_repetido(metodo *aux, char *tipo, char *valor);