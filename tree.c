#include "tree.h"

//----------------Criar arvore ------------------

struct node *criar_no(enum tipo_no tipo_no,char *tipo, char *token){
    struct node *novo = malloc(sizeof(struct node));
    novo->tipo_no = tipo_no;
    novo->tipo = tipo;
    novo->token = token;
    novo->filhos = NULL;
    return novo;
}

void adicionar_filho(struct node *pai, struct node *filho){ 
    if(!pai->filhos){
        pai->filhos = malloc(sizeof(struct node_list));
        pai->filhos->no = filho;
        pai->filhos->next = NULL;
    } else {
        struct node_list *novo = malloc(sizeof(struct node_list));
        novo->no = filho;
        novo->next = NULL;
        struct node_list *filhos = pai->filhos;
        while(filhos->next != NULL)
            filhos = filhos->next;
        filhos->next = novo;
    }
}

void imprime_arvore(struct node *no, int num){ 
    for (int i = 0; i < num; i++) {
        printf(".."); 
    }
    
    
    if(no->token)
        printf("%s(%s)\n", no->tipo, no->token);
    else
        printf("%s\n", no->tipo);
    struct node_list *atual = no->filhos;
    while (atual && atual->no) {
        imprime_arvore(atual->no, num + 1);
        atual = atual->next;
    }
}