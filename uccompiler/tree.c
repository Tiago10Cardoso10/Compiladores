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
        pai->irmaos = NULL;
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


void adiciona_primeiro(struct node* pai, struct node* filho) {
    if (pai == NULL || filho == NULL) {
        return;
    }

    
    if (pai->filhos == NULL) {
        struct node_list *lista_filhos = (struct node_list*)malloc(sizeof(struct node_list));
        if (lista_filhos == NULL) {
            return;
        }
        lista_filhos->no = filho;
        lista_filhos->next = NULL;
        pai->filhos = lista_filhos;
    } else {
        
        struct node_list *lista_irmaos = (struct node_list*)malloc(sizeof(struct node_list));
        if (lista_irmaos == NULL) {
            return;
        }
        lista_irmaos->no = filho;
        lista_irmaos->next = pai->filhos;
        pai->filhos = lista_irmaos;
    }

    
    struct node_list *atual_irmao = pai->irmaos;
    while (atual_irmao != NULL) {
        struct node_list *nova_lista = (struct node_list*)malloc(sizeof(struct node_list));
        nova_lista->no = filho;
        nova_lista->next = atual_irmao->no->filhos;
        atual_irmao->no->filhos = nova_lista;

        atual_irmao = atual_irmao->next;
    }
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

//----------------Criar Tabelas ------------------

struct tabela criar_tabela(struct node *raiz) {
    struct tabela tab;

    tab.elem = NULL; // Inicialize elem como NULL ou conforme necessário

    // Processa o primeiro filho do nó raiz
    struct node_list *raiz_aux = raiz->filhos;
    if (strcmp(raiz_aux->no->tipo, "FuncDefinition") == 0) {
    } else if (strcmp(raiz_aux->no->tipo, "FuncDeclaration") == 0) {
    } else if (strcmp(raiz_aux->no->tipo, "Declaration") == 0) {
        declaration(raiz_aux,&tab);
    }

    struct node_list *raiz_aux2 = raiz_aux->no->irmaos;
    while (raiz_aux2 != NULL) {
        if (strcmp(raiz_aux2->no->tipo, "FuncDefinition") == 0) {
        } else if (strcmp(raiz_aux2->no->tipo, "FuncDeclaration") == 0) {
        } else if (strcmp(raiz_aux2->no->tipo, "Declaration") == 0){
            declaration(raiz_aux2,&tab);
        }
        raiz_aux2 = raiz_aux2->next;
    }

    return tab;
}

void declaration(struct node_list *ast,struct tabela *tab){
    struct tabela *aux_tab = (struct tabela*) malloc(sizeof(struct tabela));

    aux_tab = tab; // Para verificar se há igual

    // Verificar se já existe

    struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));

    char *guarda1 = ast->no->tipo;
    aux_elem->tipo = (char*) malloc(strlen(guarda1) + 1);
    strcpy(aux_elem->tipo, guarda1);
    
    
    char *guarda = ast->no->filhos->no->tipo;
    aux_elem->tipo_func = (char*) malloc(strlen(guarda) + 1);
    strcpy(aux_elem->tipo_func, guarda);

    char *teste = ast->no->filhos->next->no->token;
    aux_elem->identifier = (char*) malloc(strlen(teste) + 1);
    strcpy(aux_elem->identifier, teste);

    if (tab->elem == NULL) {
        tab->elem = aux_elem;
    } else {
        
        while(tab->elem != NULL){
            tab->elem = tab->elem->next;
        }
        tab->elem = aux_elem;
        tab->elem->next = NULL;
    }
    
}





void imprime_tabela(struct tabela *tab){
    printf("===== Global Symbol Table =====\n");
    printf("putchar\tint(int)\n");
    printf("getchar\tint(void)\n");
    
        while(tab->elem != NULL){
            if (strcmp(tab->elem->tipo, "Declaration") == 0){
                printf("%s\t%s\n",tab->elem->identifier,tab->elem->tipo_func);
            } else {
                printf("%s\t%s(",tab->elem->identifier,tab->elem->tipo_func);
                param(tab->elem->param,tab->elem->nr_param);
                printf(")\n");
            }
            tab->elem = tab->elem->next;
        }
        printf("\n");
    

    /* Quando é funcDeclaration */
}

void param(char **parametros,int num){
    for(int i = 0; i < num; i++){
        printf("%s", parametros[i]);
        if(num > 1 && i != num - 1){
            printf(",");
        }
    }
}



int repeticao(){
    return 0;
}


