#ifndef _UCCOMPILER_H
#define _UCCOMPILER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

typedef enum tipo_no{
    no_raiz,
    no_declaracao,
    no_funcoes,
    no_statments,
    no_operadores,
    no_terminais,
    no_especial,
}tipo_no;


/* Arvore AST */

struct node {
    enum tipo_no tipo_no;
    char *tipo;
    char *token;
    int linha;
    int coluna;
    struct node_list *filhos;
    struct node_list *irmaos;
};

struct node_list {
    struct node *no;
    struct node_list *next;
};

/* Tabela de Simbolos */

struct elementos{
    char *tipo;
    char *tipo_func;
    char *identifier;
    char **param_t;
    char **param_i;
    int  nr_param;
    char *tipo_devolve;
    struct elementos *next;
    struct tabela *nova;
};

struct tabela {
    struct elementos *elem;
    
};



struct node *criar_no(enum tipo_no tipo_no,char *tipo, char *token);
void adicionar_filho(struct node *pai, struct node *filho);
void adicionar_irmao(struct node *irmao, struct node *novo);
void adiciona_primeiro(struct node* pai, struct node* filho);
void imprime_arvore(struct node *no, int num);

struct tabela criar_tabela(struct node *raiz);
void cria_especiasP(struct tabela *tab);
void cria_especiasG(struct tabela *tab);
void declaration(struct node_list *ast,struct tabela *tab);
void functiondeclaration(struct node_list *ast,struct tabela *tab);
void functiondefinition(struct node_list *ast,struct tabela *tab);
struct tabela* body();
int repeticao(struct elementos *aux,char *tipo ,char *identifier,int linha,int coluna);
void imprime_tabela(struct tabela *tab);
void param(char **parametros,int num);
void paramlist(char **parametros,char **identifiers,int num);
char *tipo_func(char *tipo_func);

#endif