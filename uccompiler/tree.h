#ifndef _TREE_H
#define _TREE_H

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
    char **param;
    int  nr_param;
    char *tipo_devolve;
    struct elementos *next;
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
void imprime_tabela(struct tabela *tab);
void param(char **parametros,int num);
void declaration(struct node_list *ast,struct tabela *tab);
int repeticao();


#endif