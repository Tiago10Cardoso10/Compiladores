#include "tree.h"

//----------------Criar arvore ------------------

struct node *criar_no(enum tipo_no tipo_no,char *tipo, char *token){
    struct node *novo = malloc(sizeof(struct node));
    novo->tipo_no = tipo_no;
    novo->tipo = tipo;
    novo->token = token;
    novo->filhos = NULL;
    novo->irmaos = NULL;
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

void adicionar_irmao(struct node *irmao, struct node *novo){
    if (irmao == NULL || novo == NULL) {
        return;
    }
    struct node_list *novo_irmao = malloc(sizeof(struct node_list));

    novo_irmao->no = novo;
    novo_irmao->next = NULL;

    struct node_list *ultimo_irmao = irmao->irmaos;
    if (ultimo_irmao == NULL) {
        irmao->irmaos = novo_irmao;
    } else {
        while (ultimo_irmao->next != NULL) {
            ultimo_irmao = ultimo_irmao->next;
        }
        ultimo_irmao->next = novo_irmao;
    }
    
}

int conta_irmaos(struct node *raiz) {
    int conta = 0;
    struct node_list *aux = raiz->irmaos;

    while (aux != NULL) {
        aux = aux->next;
        conta++;
    }
    return conta;
}

void imprime_arvore(struct node *no, int num){ 
    for (int i = 0; i < num; i++) {
        printf(".."); 
    }
    
    
    if(no->token){
        printf("%s(%s)\n", no->tipo, no->token);
    } else {
        printf("%s\n", no->tipo);
    }
    
    struct node_list *atual = no->filhos;
    while (atual && atual->no) {
        imprime_arvore(atual->no, num + 1);
        atual = atual->next;
    }
    struct node_list *atual2 = no->irmaos;
    while (atual2 && atual2->no) {
        imprime_arvore(atual2->no, num);
        atual2 = atual2->next;
    }
}