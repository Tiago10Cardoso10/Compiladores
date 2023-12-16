#include "uccompiler.h"

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
    
    /*
        int v;
        int a;
        void as;
        double p,bs, test;
        void x, b;

        printf("1-%s-%s\n",raiz_aux->no->tipo,raiz_aux->no->filhos->next->no->token);
        raiz_aux = raiz_aux->no->irmaos;
        printf("2-%s-%s\n",raiz_aux->no->tipo,raiz_aux->no->filhos->next->no->token);
        raiz_aux = raiz_aux->no->irmaos;
        printf("3-%s-%s\n",raiz_aux->no->tipo,raiz_aux->no->filhos->next->no->token);
        raiz_aux = raiz_aux->no->irmaos;
        struct node_list *raiz_aux2 = raiz_aux;
        printf("4-%s-%s\n",raiz_aux->no->tipo,raiz_aux->no->filhos->next->no->token);
        raiz_aux = raiz_aux->no->irmaos;
        printf("5-%s-%s\n",raiz_aux->no->tipo,raiz_aux->no->filhos->next->no->token);

        raiz_aux2 = raiz_aux2->no->irmaos->next;
        printf("6-%s-%s\n",raiz_aux2->no->tipo,raiz_aux2->no->filhos->next->no->token);
        raiz_aux2 = raiz_aux2->next;
        printf("7-%s-%s\n",raiz_aux2->no->tipo,raiz_aux2->no->filhos->next->no->token);

        raiz_aux2 = raiz_aux2->no->irmaos;
        printf("8-%s-%s\n",raiz_aux2->no->tipo,raiz_aux2->no->filhos->next->no->token);
    */


    struct tabela tab;

    tab.elem = NULL;

    cria_especiasP(&tab);
    cria_especiasG(&tab);

    
    struct node_list *raiz_aux;
    struct node_list *raiz_aux2;

    int conta_first = 0;
    while(raiz_aux2){

        if (conta_first == 0){
            raiz_aux2 = raiz->filhos;
        } 
        conta_first++;

        if (strcmp(raiz_aux2->no->tipo, "FuncDefinition") == 0) {
                functiondefinition(raiz_aux2,&tab);
            } else if (strcmp(raiz_aux2->no->tipo, "FuncDeclaration") == 0) {
                functiondeclaration(raiz_aux2,&tab);
            } else if (strcmp(raiz_aux2->no->tipo, "Declaration") == 0) {
                declaration(raiz_aux2,&tab);
            }
        
        
        
        int conta = 0;
        struct node_list *raiz_aux3 = raiz_aux2->no->irmaos;
        struct node_list *raiz_aux4;
        struct node_list *lista[300];
        while(raiz_aux3){
            lista[conta] = raiz_aux3;
            conta++;
            if(raiz_aux3->next == NULL){
                raiz_aux4 = raiz_aux3;
            }
            raiz_aux3 = raiz_aux3->next;
        }
        
        for(int i=0;i<conta-1;i++){
            if (strcmp(lista[i]->no->tipo,"FuncDefinition") == 0) {
                functiondefinition(lista[i],&tab);
            } else if (strcmp(lista[i]->no->tipo, "FuncDeclaration") == 0) {
                functiondeclaration(lista[i],&tab);
            } else if (strcmp(lista[i]->no->tipo, "Declaration") == 0) {
                declaration(lista[i],&tab);
            }
        }

        if (conta != 0){
            raiz_aux2 = raiz_aux4;
        } else {
            raiz_aux2 = NULL;
        }
    }
    return tab;
}



/*
struct tabela criar_tabela(struct node *raiz) {
    
    /*
        struct node_list *atual = raiz->filhos;
        while (atual && atual->no) {
        criar_tabela(atual->no, conta + 1,0);
        atual = atual->next;
        } 
        struct node_list *atual2 = raiz->irmaos;
        while (atual2 && atual2->no) {
        criar_tabela(atual->no, conta + 2,0);
        atual2 = atual2->next;
        }
    */

    


    /*
    struct tabela tab;

    tab.elem = NULL;

    cria_especiasP(&tab);
    cria_especiasG(&tab);

    struct node_list *raiz_aux = raiz->filhos;
    if (strcmp(raiz_aux->no->tipo, "FuncDefinition") == 0) {
        functiondefinition(raiz_aux,&tab);
    } else if (strcmp(raiz_aux->no->tipo, "FuncDeclaration") == 0) {
        functiondeclaration(raiz_aux,&tab);
    } else if (strcmp(raiz_aux->no->tipo, "Declaration") == 0) {
        declaration(raiz_aux,&tab);
    }
    
    struct node_list *raiz_aux2 = raiz_aux->no->irmaos;
    
    struct node_list *save = raiz_aux2;

    int j = 0;
    const int MAX_SIZE = 300;

    char *repetI[MAX_SIZE];
    char *repetT[MAX_SIZE];

    while (raiz_aux2 != NULL || save != NULL) {
        int i = 0;
        bool res = true;
        if (strcmp(raiz_aux2->no->tipo, "FuncDefinition") == 0) {
            while (res && i < j){
                if (strcmp(repetT[i], raiz_aux2->no->tipo) == 0){
                    if (strcmp(repetI[i], raiz_aux2->no->filhos->next->no->token) == 0){
                        res = false;
                    }
                }
                i++;
            }
            if (res){
                if(functiondefinition(raiz_aux2,&tab) != 1){
                    repetI[j] = raiz_aux2->no->filhos->next->no->token;
                    repetT[j] = raiz_aux2->no->tipo;
                    j++;
                }
            }
        } else if (strcmp(raiz_aux2->no->tipo, "FuncDeclaration") == 0) {
            while (res && i < j){
                if (strcmp(repetT[i], raiz_aux2->no->tipo) == 0){
                    if (strcmp(repetI[i], raiz_aux2->no->filhos->next->no->token) == 0){
                        res = false;
                    }
                }
                i++;
            }
            if (res){
                if(functiondeclaration(raiz_aux2,&tab) != 1){

                    repetI[j] = raiz_aux2->no->filhos->next->no->token;
                    repetT[j] = raiz_aux2->no->tipo;
                    j++;
                }
            }
        } else if (strcmp(raiz_aux2->no->tipo, "Declaration") == 0){
            while (res && i < j){
                if (strcmp(repetT[i], raiz_aux2->no->tipo) == 0){
                    if (strcmp(repetI[i], raiz_aux2->no->filhos->next->no->token) == 0){
                        res = false;
                    }
                }
                i++;
            }
            if (res){
                if(declaration(raiz_aux2,&tab) != 1){
                    repetI[j] = raiz_aux2->no->filhos->next->no->token;
                    repetT[j] = raiz_aux2->no->tipo;
                    j++;
                }
            }
        }

        save = raiz_aux2;
        if (raiz_aux2->next == NULL){
            
            save = raiz_aux2->no->irmaos;
            while (save != NULL) {
                i = 0;
                bool res = true;
                if (strcmp(save->no->tipo, "FuncDefinition") == 0) {
                    while (res && i < j){
                        if (strcmp(repetT[i], save->no->tipo) == 0){
                            if (strcmp(repetI[i], save->no->filhos->next->no->token) == 0){
                                res = false;
                            }
                        }
                        i++;
                    }
                    if (res){
                        if(functiondefinition(save,&tab) != 1){
                            repetI[j] = save->no->filhos->next->no->token;
                            repetT[j] = save->no->tipo;
                            j++;
                        } 
                    }
                    
                } else if (strcmp(save->no->tipo, "FuncDeclaration") == 0) {
                    while (res && i < j){
                        if (strcmp(repetT[i], save->no->tipo) == 0){
                            if (strcmp(repetI[i], save->no->filhos->next->no->token) == 0){
                                res = false;
                            }
                        }
                        i++;
                    }
                    if (res){
                        if(functiondeclaration(save,&tab) != 1){
                            repetI[j] = save->no->filhos->next->no->token;
                            repetT[j] = save->no->tipo;
                            j++;
                        } 
                    }
                    
                } else if (strcmp(save->no->tipo, "Declaration") == 0){
                    while (res && i < j){
                        if (strcmp(repetT[i], save->no->tipo) == 0){
                            if (strcmp(repetI[i], save->no->filhos->next->no->token) == 0){
                                res = false;
                            }
                        }
                        i++;
                    }
                    if (res){
                        if(declaration(save,&tab) != 1){
                            repetI[j] = save->no->filhos->next->no->token;
                            repetT[j] = save->no->tipo;
                            j++;
                        } 
                    }
                    
                    
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
*/
void cria_especiasP(struct tabela *tab){
    struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));

    char *guarda1 = "FuncDeclaration";
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

    aux_elem->param_t = (char**) malloc(aux_elem->nr_param * sizeof(char*));
    aux_elem->param_t[0] = (char*) malloc(strlen(guarda4) + 1);
    strcpy(aux_elem->param_t[0], guarda4);

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

void cria_especiasG(struct tabela *tab){
    struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));

    char *guarda1 = "FuncDeclaration";
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

    aux_elem->param_t = (char**) malloc(aux_elem->nr_param * sizeof(char*));
    aux_elem->param_t[0] = (char*) malloc(strlen(guarda4) + 1);

    strcpy(aux_elem->param_t[0], guarda4);

    aux_elem->next = NULL;

    struct elementos *aux = tab->elem;
    
    aux->next = aux_elem;
}


int declaration(struct node_list *ast,struct tabela *tab){
    struct elementos *aux_tab = tab->elem;

    if(repeticao(aux_tab,ast->no->tipo,ast->no->filhos->next->no->token,ast->no->filhos->next->no->linha,ast->no->filhos->next->no->coluna) == 0){
        struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));
        
        
        if(strcmp(ast->no->filhos->no->tipo,"Void")== 0){
            printf("Line %d, column %ld: Invalid use of void type in declaration\n",ast->no->filhos->no->linha,ast->no->filhos->no->coluna-strlen(ast->no->filhos->next->no->token));
            return 1;
        }
        
        
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
        
        if (tab->elem == NULL) {
            tab->elem = aux_elem;
            
        } else {
            struct elementos *aux = tab->elem;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = aux_elem;
        }
        
    }
}

int functiondeclaration(struct node_list *ast,struct tabela *tab){
    struct elementos *aux_tab = tab->elem;

            
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

        
        aux_elem->param_t = NULL;
        struct node_list *aux_irmaos = ast->no->filhos->next->no->irmaos->no->filhos;
        
        int contador = 0;
        int linha_r = 0;
        int coluna_r = 0;
        int contador_void = 0;
        while (aux_irmaos) {
            char *tipo = tipo_func(aux_irmaos->no->filhos->no->tipo);
            
            aux_elem->param_t = (char**) realloc(aux_elem->param_t, (contador + 1) * sizeof(char*));
            aux_elem->param_t[contador] = (char*) malloc((strlen(tipo) + 1) * sizeof(char));
            strcpy(aux_elem->param_t[contador], tipo);
            
            if(aux_irmaos->no->filhos->next != NULL){
                char *identifier = aux_irmaos->no->filhos->next->no->token;

                
                for(int i=0; i < contador; i++){
                    if(strcmp(tipo,aux_elem->param_t[i])== 0){
                        if(strcmp(identifier, aux_elem->param_i[i]) == 0){
                            printf("Line %d, column %ld: Symbol %s already defined\n",aux_irmaos->no->filhos->next->no->linha,aux_irmaos->no->filhos->next->no->coluna-strlen(identifier),identifier);
                        }
                    }    
                }
                
                
                
                if (strcmp(tipo,"void") == 0){
                    printf("Line %d, column %ld: Invalid use of void type in declaration\n",aux_irmaos->no->filhos->no->linha,aux_irmaos->no->filhos->no->coluna-strlen(tipo));
                    return 1;
                }
                
                aux_elem->param_i = (char**) realloc(aux_elem->param_i, (contador + 1) * sizeof(char*));
                aux_elem->param_i[contador] = (char*) malloc((strlen(identifier) + 1) * sizeof(char));
                strcpy(aux_elem->param_i[contador], identifier);
            } else {
                char *identifier = "NULL";
                
                if (strcmp(tipo,"void") == 0){
                    contador_void++;
                }
                if(contador_void >= 1 && contador > 0){
                    printf("Line %d, column %ld: Invalid use of void type in declaration\n",aux_irmaos->no->filhos->no->linha,aux_irmaos->no->filhos->no->coluna-strlen(tipo));
                    return 1;
                } else{
                    aux_elem->param_i = (char**) realloc(aux_elem->param_i, (contador + 1) * sizeof(char*));
                    aux_elem->param_i[contador] = (char*) malloc((strlen(identifier) + 1) * sizeof(char));
                    strcpy(aux_elem->param_i[contador], identifier);
                }
            }

            contador++;
            if (aux_irmaos->next != NULL) {
                aux_irmaos = aux_irmaos->next;
            } else {
                aux_irmaos = aux_irmaos->no->irmaos;
            }
        }
        aux_elem->nr_param = contador;


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

int functiondefinition(struct node_list *ast,struct tabela *tab){
    struct elementos *aux_tab = tab->elem;

    if(repeticao(aux_tab,ast->no->tipo,ast->no->filhos->next->no->token,ast->no->filhos->next->no->linha,ast->no->filhos->next->no->coluna) == 0){        
        struct elementos *aux_elem = (struct elementos*) malloc(sizeof(struct elementos));
        struct elementos *aux_tab2 = tab->elem;


        char *guarda1 = ast->no->tipo;
        aux_elem->tipo = (char*) malloc(strlen(guarda1) + 1);
        strcpy(aux_elem->tipo, guarda1);
        
        char *guarda2 = tipo_func(ast->no->filhos->no->tipo);
        aux_elem->tipo_func = (char*) malloc(strlen(guarda2) + 1);
        aux_elem->tipo_devolve = (char*) malloc(strlen(guarda2) + 1);
        strcpy(aux_elem->tipo_func, guarda2);
        strcpy(aux_elem->tipo_devolve,guarda2);

        char *guarda3 = ast->no->filhos->next->no->token;
        aux_elem->identifier = (char*) malloc(strlen(guarda3) + 1);
        strcpy(aux_elem->identifier,guarda3);

        while (aux_tab2 != NULL) {
            if(strcmp(aux_tab2->tipo,aux_elem->identifier) != 0){
                if (strcmp(aux_tab2->tipo,"FuncDeclaration") == 0){
                    if(strcmp(aux_tab2->identifier,aux_elem->identifier)==0){
                        if(strcmp(aux_tab2->tipo_func,aux_elem->tipo_func) !=0){
                            return 4;
                        }   
                    }
                }
            }
            aux_tab2 = aux_tab2->next;
        }
            
        

        
        aux_elem->param_t = NULL;

        struct node_list *aux_irmaos = ast->no->filhos->next->no->irmaos->no->filhos;
        int contador = 0;
        int linha_r1 = 0;
        int coluna_r1 = 0;
        int contador_void = 0;
        while (aux_irmaos) {
            char *tipo = tipo_func(aux_irmaos->no->filhos->no->tipo);

            aux_elem->param_t = (char**) realloc(aux_elem->param_t, (contador + 1) * sizeof(char*));
            aux_elem->param_t[contador] = (char*) malloc((strlen(tipo) + 1) * sizeof(char));
            strcpy(aux_elem->param_t[contador], tipo);

            if(aux_irmaos->no->filhos->next != NULL){
                char *identifier = aux_irmaos->no->filhos->next->no->token;
                
                for(int i=0; i < contador; i++){
                    if(strcmp(tipo,aux_elem->param_t[i])== 0){
                        if(strcmp(identifier, aux_elem->param_i[i]) == 0){
                            printf("Line %d, column %ld: Symbol %s already defined\n",aux_irmaos->no->filhos->next->no->linha,aux_irmaos->no->filhos->next->no->coluna-strlen(identifier),identifier);
                        }
                    }    
                }
                
                
                if (strcmp(tipo,"void") == 0){
                    printf("Line %d, column %ld: Invalid use of void type in declaration\n",aux_irmaos->no->filhos->no->linha,aux_irmaos->no->filhos->no->coluna-strlen(tipo));
                    return 1;
                }
                
                aux_elem->param_i = (char**) realloc(aux_elem->param_i, (contador + 1) * sizeof(char*));
                aux_elem->param_i[contador] = (char*) malloc((strlen(identifier) + 1) * sizeof(char));
                strcpy(aux_elem->param_i[contador], identifier);
            } else {
                char *identifier = "NULL";
                
                if (strcmp(tipo,"void") == 0){
                    contador_void++;
                }
                if(contador_void >= 1 && contador > 0){
                    printf("Line %d, column %ld: Invalid use of void type in declaration\n",aux_irmaos->no->filhos->no->linha,aux_irmaos->no->filhos->no->coluna-strlen(tipo));
                    return 1;
                } else{
                    aux_elem->param_i = (char**) realloc(aux_elem->param_i, (contador + 1) * sizeof(char*));
                    aux_elem->param_i[contador] = (char*) malloc((strlen(identifier) + 1) * sizeof(char));
                    strcpy(aux_elem->param_i[contador], identifier);
                }
            }

            contador++;
            if (aux_irmaos->next != NULL) {
                aux_irmaos = aux_irmaos->next;
            } else {
                aux_irmaos = aux_irmaos->no->irmaos;
            }
        }
        aux_elem->nr_param = contador;

        aux_elem->next = NULL;

        
        // Body
        aux_elem->nova = body();
        struct node_list *aux_body = ast->no->filhos->next->next->no->filhos;
        while (aux_body)
        {
            if(strcmp(aux_body->no->tipo,"Declaration") == 0){
                declaration(aux_body,aux_elem->nova);
            } 
            
            else if (strcmp(aux_body->no->tipo,"Return") == 0){
                if (strcmp(aux_body->no->filhos->no->tipo,"Identifier") == 0){
                    struct elementos *aux2 = search_symbol(tab,aux_body->no->filhos->no->token);
                    if(aux2 != NULL){
                        if (strcmp(aux2->tipo_func,aux_elem->tipo_devolve) != 0 ){
                            printf("Line %d, column %d: Conflicting types (got %s, expected %s)\n",aux_body->no->linha,aux_body->no->coluna,aux2->tipo_func,aux_elem->tipo_devolve);
                        }   
                    }
                }
            }
            
            
            // Necessário ver os CALLS IF WHILE SOMAS ETC...
            
            if (aux_body->next == NULL){
                aux_body = aux_body->no->irmaos;
            } else {
                aux_body = aux_body->next;
            }
        }
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

struct tabela* body(){
    struct tabela *nova_tabela = malloc(sizeof(struct tabela));
    if (nova_tabela != NULL) {
        nova_tabela->elem = NULL;
    }
    return nova_tabela;
}

struct elementos *search_symbol(struct tabela *tab,char *identifier){
    struct elementos *aux = tab->elem;
    while(aux != NULL){
        if(strcmp(aux->identifier,identifier)==0){
            return aux;
        }
        aux = aux->next;
    }
    
    return NULL;
}

int repeticao(struct elementos *aux,char *tipo ,char *identifier,int linha,int coluna){
    int val = 0;
    while(aux != NULL){
        if(strcmp(aux->tipo,tipo) == 0){
            if(strcmp(aux->identifier,identifier) == 0){
                val = 1;
                printf("Line %d, column %ld: Symbol %s already defined\n",linha,coluna-strlen(identifier),identifier);
            } 
        } 
        aux = aux->next;
    }
    return val;
}

void imprime_tabela(struct tabela *tab){
    printf("===== Global Symbol Table =====\n");
    
    int j = 0;
    const int MAX_SIZE = 300;
    char *repet[MAX_SIZE];
    
    struct elementos *current_elem = tab->elem;

    while (current_elem != NULL) {
        int i = 0;
        bool res = true;
        if (strcmp(current_elem->tipo, "Declaration") == 0) {
            while (res && i < j){
                if (strcmp(repet[i], current_elem->identifier) == 0){
                    res = false;
                }
                i++;
            }
            if (res){
                printf("%s\t%s\n",current_elem->identifier,current_elem->tipo_func);
            }
            repet[j] = current_elem->identifier;
            j++;
        } else {
            while (res && i < j){
                if (strcmp(repet[i], current_elem->identifier) == 0){
                    res = false;
                }
                i++;
            }
            if (res){
                printf("%s\t%s(",current_elem->identifier,current_elem->tipo_func);
                param(current_elem->param_t,current_elem->nr_param);
                printf(")\n");
                
            }
            repet[j] = current_elem->identifier;
            j++;
        }
        current_elem = current_elem->next;
        
    }
    
    printf("\n");
    int l = 0;
    const int MAX_SIZEE = 50;
    char *repet_fd[MAX_SIZEE];

    struct elementos *aux = tab->elem;
    while (aux != NULL) {
        int i = 0;
        bool res = true;
        struct elementos *veri = verifica(aux,aux);
        if (veri == NULL){
            if (strcmp(aux->tipo, "FuncDefinition") == 0) {
                while (res && i < l){
                    if (strcmp(repet_fd[i], aux->identifier) == 0){
                        res = false;
                    }
                    i++;
                }
                if(res){
                    printf("===== Function %s Symbol Table =====\n",aux->identifier);
                    printf("return\t%s\n",aux->tipo_devolve);

                    const int MAX_SIZE = 50;
                    char **no_repet = (char **)malloc(MAX_SIZE * sizeof(char *));

                    if (no_repet != NULL) {
                        int j = 0;
                        bool res = true;
                        int k = 0;

                        for (int i = 0; i < aux->nr_param; i++) {
                            if (strcmp(aux->param_i[i], "NULL") != 0) {
                                while (k < j && res) {
                                    if (strcmp(no_repet[k], aux->param_i[i]) != 0) {
                                        printf("%s\t%s\tparam\n", aux->param_i[i], aux->param_t[i]);
                                        no_repet[j] = aux->param_i[i];
                                        j++;
                                    }
                                    res = false;
                                    k++;
                                }
                                if (j == 0) {
                                    printf("%s\t%s\tparam\n", aux->param_i[i], aux->param_t[i]);
                                    no_repet[j] = aux->param_i[i];
                                    j++;
                                }
                            }
                            k = 0;
                            res = true;
                        }
                    }

                    while(aux->nova->elem){
                        for(int i = 0; i < aux->nr_param; i++){
                            if(strcmp(no_repet[i], aux->nova->elem->identifier)== 0){
                                printf("%s\t%s\n",aux->nova->elem->identifier,aux->nova->elem->tipo_func);
                            }
                        }
                        aux->nova->elem = aux->nova->elem->next;
                    }
                    printf("\n");
                }
                repet_fd[l] = aux->identifier;
                l++;
            } 
        } else {
            if (strcmp(veri->tipo, "FuncDefinition") == 0) {
                while (res && i < l){
                    if (strcmp(repet_fd[i], veri->identifier) == 0){
                        res = false;
                    }
                    i++;
                }
                if(res){
                    printf("===== Function %s Symbol Table =====\n",veri->identifier);
                    printf("return\t%s\n",veri->tipo_devolve);

                    const int MAX_SIZEE = 50;
                    char **no_repet2 = (char **)malloc(MAX_SIZEE * sizeof(char *));

                    if (no_repet2 != NULL) {
                        int j = 0;
                        bool res = true;
                        int k = 0;

                        for (int i = 0; i < veri->nr_param; i++) {
                            if (strcmp(veri->param_i[i], "NULL") != 0) {
                                while (k < j && res) {
                                    if (strcmp(no_repet2[k], veri->param_i[i]) != 0) {
                                        printf("%s\t%s\tparam\n", veri->param_i[i], veri->param_t[i]);
                                        no_repet2[j] = veri->param_i[i];
                                        j++;
                                    }
                                    res = false;
                                    k++;
                                }
                                if (j == 0) {
                                    printf("%s\t%s\tparam\n", veri->param_i[i], veri->param_t[i]);
                                    no_repet2[j] = veri->param_i[i];
                                    j++;
                                }
                            }
                            k = 0;
                            res = true;
                        }
                    }

                    while(veri->nova->elem){
                        for(int i = 0; i < veri->nr_param; i++){
                            if(strcmp(no_repet2[i], veri->nova->elem->identifier)== 0){
                                printf("%s\t%s\n",veri->nova->elem->identifier,veri->nova->elem->tipo_func);
                            }
                        }
                        veri->nova->elem = veri->nova->elem->next;
                    }
                    printf("\n");
                }
                repet_fd[l] = veri->identifier;
                l++;
            } 
        }
        aux = aux->next;
    }
}

struct elementos *verifica(struct elementos *elem,struct elementos *atual){
    
    while(elem != NULL){
        if(strcmp(elem->tipo,atual->tipo) !=0 ){
            if (strcmp(elem->tipo,"FuncDefinition")==0){
                if(strcmp(elem->identifier,atual->identifier)==0){
                    if(strcmp(elem->tipo_func,atual->tipo_func)==0){
                        return elem;
                    }   
                }
            }
            
        }
        elem = elem->next;
    }
    return NULL;
}

void param(char **parametros,int num){
    for(int i = 0; i < num; i++){
        printf("%s", parametros[i]);
        if(num > 1 && i != num - 1){
            printf(",");
        } 
    }
}

void paramlist(char **parametros, char **identifiers, int num) {
    const int MAX_SIZE = 50;
    char **no_repet = (char **)malloc(MAX_SIZE * sizeof(char *));

    if (no_repet != NULL) {
        int j = 0;
        bool res = true;
        int k = 0;

        for (int i = 0; i < num; i++) {
            if (strcmp(identifiers[i], "NULL") != 0) {
                while (k < j && res) {
                    if (strcmp(no_repet[k], identifiers[i]) != 0) {
                        printf("%s\t%s\tparam\n", identifiers[i], parametros[i]);
                        no_repet[j] = identifiers[i];
                        j++;
                    }
                    res = false;
                    k++;
                }
                if (j == 0) {
                    printf("%s\t%s\tparam\n", identifiers[i], parametros[i]);
                    no_repet[j] = identifiers[i];
                    j++;
                }
            }
            k = 0;
            res = true;
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