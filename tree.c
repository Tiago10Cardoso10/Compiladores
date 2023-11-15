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

struct node_list *append_node(struct node_list *list, struct node *criar_no) {
    struct node_list *new_list_node = malloc(sizeof(struct node_list));
    new_list_node->no = criar_no;
    new_list_node->next = NULL;

    if (list == NULL) {
        // If the list is empty, start a new list with the new node
        return new_list_node;
    } else {
        // Find the last node in the list
        struct node_list *current = list;
        while (current->next != NULL) {
            current = current->next;
        }
        // Append the new node
        current->next = new_list_node;
        return list;  // Return the head of the list
    }
}

struct node_list *node_to_nodelist(struct node *node) {
    struct node_list *list_item = malloc(sizeof(struct node_list));
    list_item->no = node;
    list_item->next = NULL;
    return list_item;
}

struct node *nodelist_to_node(struct node_list *node_list) {
    struct node *node = malloc(sizeof(struct node));
    node = node_list->no;
    return node;
}

struct node_list* reverse_list(struct node_list* head) {
    struct node_list *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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