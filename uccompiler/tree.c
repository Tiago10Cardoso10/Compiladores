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
    if (strcmp(no->tipo," ") != 0){ 
        for (int i = 0; i < num; i++) {
            printf(".."); 
        }
    
    
        if(no->token){
            printf("%s(%s)\n", no->tipo, no->token);
        } else {
            printf("%s\n", no->tipo);
        }
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

    tab.elem = NULL;

    cria_especiasP(&tab);
    cria_especiasG(&tab);

    struct node_list *raiz_aux = raiz->filhos;
    if (strcmp(raiz_aux->no->tipo, "FuncDefinition") == 0) {
    } else if (strcmp(raiz_aux->no->tipo, "FuncDeclaration") == 0) {
    } else if (strcmp(raiz_aux->no->tipo, "Declaration") == 0) {
        declaration(raiz_aux,&tab);
    }
    
    struct node_list *raiz_aux2 = raiz_aux->no->irmaos;
    
    struct node_list *save;

    while (raiz_aux2 != NULL || save != NULL) {
        if (strcmp(raiz_aux2->no->tipo, "FuncDefinition") == 0) {
        } else if (strcmp(raiz_aux2->no->tipo, "FuncDeclaration") == 0) {
        } else if (strcmp(raiz_aux2->no->tipo, "Declaration") == 0){
            declaration(raiz_aux2,&tab);
        }

        save = raiz_aux2;
        if (raiz_aux2->next == NULL){
            save = raiz_aux2->no->irmaos;
            while (save != NULL) {
                if (strcmp(save->no->tipo, "FuncDefinition") == 0) {
                } else if (strcmp(save->no->tipo, "FuncDeclaration") == 0) {
                } else if (strcmp(save->no->tipo, "Declaration") == 0){
                    declaration(save,&tab);
                }
                save = save->no->irmaos;
            }
            raiz_aux2 = raiz_aux2->no->irmaos;
        }
        else{
            raiz_aux2 = raiz_aux2->next;
        }
        
        
    }
    return tab;
}

void cria_especiasP(struct tabela *tab){
    struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));

    char *guarda1 = "FunctionDeclaration";
    aux_elem->tipo = (char*) malloc(strlen(guarda1) + 1);
    strcpy(aux_elem->tipo, guarda1);
        
    char *guarda2 = "int";
    aux_elem->tipo_func = (char*) malloc(strlen(guarda2) + 1);
    strcpy(aux_elem->tipo_func, guarda2);

    char *guarda3 = "putchar";
    aux_elem->identifier = (char*) malloc(strlen(guarda3) + 1);
    strcpy(aux_elem->identifier,guarda3);

    aux_elem->nr_param = 1;

    char *guarda4 = "int";

    aux_elem->param = (char**) malloc(aux_elem->nr_param * sizeof(char*));
    aux_elem->param[0] = (char*) malloc(strlen(guarda4) + 1);
    strcpy(aux_elem->param[0], guarda4);

    aux_elem->next = NULL;

    tab->elem = aux_elem;
}

void cria_especiasG(struct tabela *tab){
    struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));

    char *guarda1 = "FunctionDeclaration";
    aux_elem->tipo = (char*) malloc(strlen(guarda1) + 1);
    strcpy(aux_elem->tipo, guarda1);
        
    char *guarda2 = "int";
    aux_elem->tipo_func = (char*) malloc(strlen(guarda2) + 1);
    strcpy(aux_elem->tipo_func, guarda2);

    char *guarda3 = "getchar";
    aux_elem->identifier = (char*) malloc(strlen(guarda3) + 1);
    strcpy(aux_elem->identifier,guarda3);

    aux_elem->nr_param = 1;

    char *guarda4 = "void";

    aux_elem->param = (char**) malloc(aux_elem->nr_param * sizeof(char*));
    aux_elem->param[0] = (char*) malloc(strlen(guarda4) + 1);

    strcpy(aux_elem->param[0], guarda4);

    aux_elem->next = NULL;

    struct elementos *aux = tab->elem;
    aux = tab->elem;
    while (aux->next != NULL) {
        aux = aux->next;
    }
    aux->next = aux_elem;
}


void declaration(struct node_list *ast,struct tabela *tab){
    struct elementos *aux_tab = tab->elem;

    if(repeticao(aux_tab,ast->no->filhos->next->no->token) == 0){
        struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));

        char *guarda1 = ast->no->tipo;
        aux_elem->tipo = (char*) malloc(strlen(guarda1) + 1);
        strcpy(aux_elem->tipo, guarda1);
        
        char *guarda2 = tipo_func(ast->no->filhos->no->tipo);
        aux_elem->tipo_func = (char*) malloc(strlen(guarda2) + 1);
        strcpy(aux_elem->tipo_func, guarda2);

        char *guarda3 = ast->no->filhos->next->no->token;
        aux_elem->identifier = (char*) malloc(strlen(guarda3) + 1);
        strcpy(aux_elem->identifier,guarda3);

        aux_elem->next = NULL;

        struct elementos *aux = tab->elem;
        if (tab->elem == NULL) {
            tab->elem = aux_elem;
        } else {
            aux = tab->elem;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            
            aux->next = aux_elem;
        }
    }
}

void functiondeclaration(){
    
}

int repeticao(struct elementos *aux, char *identifier){
    int val = 0;
    while(aux != NULL){
        if(strcmp(aux->identifier,identifier) == 0){
            val = 1;
        }
        aux = aux->next;
    }
    return val;
}

void imprime_tabela(struct tabela *tab){
    printf("===== Global Symbol Table =====\n");
    
    struct elementos *current_elem = tab->elem;
    while (current_elem != NULL) {
        if (strcmp(current_elem->tipo, "Declaration") == 0) {
            printf("%s\t%s\n",current_elem->identifier,current_elem->tipo_func);
        } else {
                printf("%s\t%s(",current_elem->identifier,current_elem->tipo_func);
                param(current_elem->param,current_elem->nr_param);
                printf(")\n");
        }
        current_elem = current_elem->next;
    }
    printf("\n");
}

void param(char **parametros,int num){
    for(int i = 0; i < num; i++){
        printf("%d",i);
        printf("%s", parametros[i]);
        if(num > 1 && i != num - 1){
            printf(",");
        } 
    }
}

char *tipo_func(char *tipo_func){
    if (strcmp(tipo_func, "Int") == 0){
        tipo_func = "int";
        return tipo_func;
    }
    else if (strcmp(tipo_func, "Double") == 0){
        tipo_func = "double";
        return tipo_func;
    }
    else if (strcmp(tipo_func, "Void") == 0){
        tipo_func = "void";
        return tipo_func;
    }
    else if (strcmp(tipo_func, "Short") == 0){
        tipo_func = "short";
        return tipo_func;
    }
    else if (strcmp(tipo_func, "Char") == 0){
        tipo_func = "char";
        return tipo_func;
    }
    return tipo_func;
}

