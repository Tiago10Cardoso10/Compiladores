#include "tree.h"

node criar_no(tipo_no no_tipo, char *valor, char *tipo){
    node novo = malloc(sizeof(no));
    novo->tipo = (char*)malloc((strlen(tipo) + 1)*sizeof(char));  
    strcpy(novo->tipo, tipo);
    novo->valor = (char*)malloc((strlen(valor) + 1)*sizeof(char));  
    strcpy(novo->valor, valor);
    novo->pai = NULL;
    novo->filho = NULL;
    novo->irmao = NULL;
    novo->no_tipo = no_tipo;
    return novo;
}

void adicionar_irmao(node novo, node irmao){
    if(novo == NULL || irmao == NULL)
        return ;
    node aux;
    aux = irmao;
    while(aux->irmao != NULL){
        aux = aux->irmao;
    }
    aux->irmao = novo;
    if(irmao->pai != NULL){
        novo->pai = irmao->pai;
    }
}

void adicionar_filho(node pai, node novo){
    if(novo == NULL)
        return ;
    pai->filho = novo;
    novo->pai = pai;
}

int conta_irmaos(node raiz) {
    int conta = 0;
    node aux = raiz;
    while (aux != NULL) {
        aux = aux->irmao;
        conta++;
    }
    
    return conta;
}

void imprime_arvore(node raiz, int num){

    if(raiz == NULL)
        return ;
    
    int i = 0;

    while(i < num){
        printf("..");
        i++;
    }
    if(strcmp(raiz->valor, "") == 0)
        printf("%s\n", raiz->tipo);
    else
        printf("%s(%s)\n", raiz->tipo, raiz->valor);
    
    

    if(raiz->filho != NULL){
        imprime_arvore(raiz->filho, num + 1);
    }

    if(raiz->irmao != NULL){             
        imprime_arvore(raiz->irmao, num);
    }
}

//---------------- Criar e imprimir a tabela ------------------------

void imprime_tabela(lista *l){
    metodo *tabela = malloc(sizeof(metodo));
    tabela = l->inicio;
    
    printf("===== Class %s Symbol Table =====\n", tabela->nome_class);
    
    while(tabela != NULL){
        if(strcmp(tabela->tipo, "MethodDecl") == 0){
            printf("%s\t(", tabela->nome_funcao);
            imprime_parametros(tabela->tipo_param, tabela->num_param);
            printf(")\t%s\n", tabela->tipo_retorna);
            
        }
        else{
            printf("%s\t\t%s\n", tabela->nome_funcao, tabela->tipo_retorna);             
        }
        tabela = tabela->proximo_metodo;
    }
    printf("\n");
    metodo *m = malloc(sizeof(metodo));
    m = l->inicio;
    
    while(m != NULL){
        if(strcmp(m->tipo, "MethodDecl") == 0){
            printf("===== Method %s(",m->nome_funcao);
            imprime_parametros(m->tipo_param, m->num_param);
            printf(") Symbol Table =====\n");
            printf("return\t\t%s\n", m->tipo_retorna);

            for(int i = 0; i < m->num_param; i++){
                printf("%s\t\t%s\tparam\n", m->nome_param[i], m->tipo_param[i]);
            }
            printf("%s", m->variavel);
            printf("\n");
        }
        m = m->proximo_metodo;

    }
}

void imprime_parametros(char **p, int num){
    for(int i = 0; i < num; i++){
        printf("%s", p[i]);
        if(num > 1 && i != num - 1){
            printf(",");
        }
    }
}

lista criar_tabela(node r){
    lista tab;
    tab.inicio = NULL; 
    node raiz_aux = r->filho->irmao;
    
    while(raiz_aux != NULL){
        
        if(strcmp(raiz_aux->tipo, "MethodDecl") == 0){
            metodo_decl(raiz_aux, &tab, r->filho->valor);
        }
        else if(strcmp(raiz_aux->tipo, "FieldDecl") == 0){
            field_decl(raiz_aux, &tab, r->filho->valor);
        }
        raiz_aux = raiz_aux->irmao;
    }
    
    return tab;
}

void field_decl(node cr7, lista *l, char *nome_class){
    metodo *aux = malloc(sizeof(metodo));
    aux = l->inicio;
    if(verifica_repetido(aux, "FieldDecl", strdup(cr7->filho->irmao->valor), 0)){
        metodo *no, *tabela = malloc(sizeof(metodo));

        tabela->tipo = (char*)malloc((strlen("FieldDecl") + 1)*sizeof(char));
        strcpy(tabela->tipo, "FieldDecl");

        tabela->nome_class = (char*)malloc((strlen(nome_class) + 1)*sizeof(char));
        strcpy(tabela->nome_class, nome_class);
        
        char *c = type(strdup(cr7->filho->tipo));
        tabela->tipo_retorna = (char*)malloc((strlen(c) + 1)*sizeof(char));
        strcpy(tabela->tipo_retorna, c);

        tabela->nome_funcao = (char*)malloc((strlen(cr7->filho->irmao->valor) + 1)*sizeof(char));
        strcpy(tabela->nome_funcao, strdup(cr7->filho->irmao->valor));
        

        if(l->inicio == NULL){
            l->inicio = tabela;
        }
        else{
            no = l->inicio;
            while(no->proximo_metodo != NULL){
                no = no->proximo_metodo;
            }
            no->proximo_metodo = tabela;
        }
    }
}

void metodo_decl(node r2, lista *l, char *nome_class){
    metodo *no, *tabela = malloc(sizeof(metodo));

    tabela->tipo = (char*)malloc((strlen("MethodDecl") + 1)*sizeof(char));
    strcpy(tabela->tipo, "MethodDecl");

    tabela->nome_class = (char*)malloc((strlen(nome_class) + 1)*sizeof(char));
    strcpy(tabela->nome_class, nome_class);

    char *m = type(strdup(r2->filho->filho->tipo));
    tabela->tipo_retorna = (char*)malloc((strlen(m) + 1)*sizeof(char));
    strcpy(tabela->tipo_retorna, m);

    tabela->nome_funcao = (char*)malloc((strlen(r2->filho->filho->irmao->valor) + 1)*sizeof(char));
    strcpy(tabela->nome_funcao, strdup(r2->filho->filho->irmao->valor));

    if(r2->filho->filho->irmao->irmao->filho != NULL){
        metodo_header(tabela, r2->filho);
    }
    metodo_body(tabela, r2->filho->irmao);

    if(l->inicio == NULL){
        l->inicio = tabela;
    }
    else{
        no = l->inicio;
        while(no->proximo_metodo != NULL){
            no = no->proximo_metodo;
        }
        no->proximo_metodo = tabela;
    }
    
}

void metodo_header(metodo *tabela, node r2){    
    node r = r2->filho->irmao->irmao->filho->filho;
    char *c = type(r->tipo);
    int count = 0;
    tabela->tipo_param = (char**)malloc(50*sizeof(char*));
    tabela->nome_param = (char**)malloc(50*sizeof(char*));
    
    tabela->tipo_param[count] = (char*)malloc((strlen(c) + 1)*sizeof(char));
    strcpy(tabela->tipo_param[count], c);
    
    tabela->nome_param[count] = (char*)malloc((strlen(r->irmao->valor) + 1)*sizeof(char));
    strcpy(tabela->nome_param[count], r->irmao->valor);
    count++;
    node r1 = r2->filho->irmao->irmao->filho->irmao;
    
    while(r1 != NULL){

        char *f = type(r1->filho->tipo);
        
        tabela->tipo_param[count] = (char*)malloc((strlen(f) + 1)*sizeof(char));
        strcpy(tabela->tipo_param[count], f);
        tabela->nome_param[count] = (char*)malloc((strlen(r1->filho->irmao->valor) + 1)*sizeof(char));
        strcpy(tabela->nome_param[count], r1->filho->irmao->valor);
        count++;
        r1 = r1->irmao;  
    }
    tabela->num_param = count;
}

void metodo_body(metodo *tabela, node r3){
    node r4 = r3->filho;
    char *aux = (char*)malloc(sizeof(char));
    while(r4 != NULL){
        if(strcmp(r4->tipo, "VarDecl") == 0){
            char *m = type(r4->filho->tipo);          
            strcat(aux, strdup(r4->filho->irmao->valor));
            strcat(aux, "\t\t");
            strcat(aux, m);
            strcat(aux, "\n");
        }
        r4 = r4->irmao;
    }
    tabela->variavel = (char*)malloc((strlen(aux) + 1)*sizeof(char));
    strcpy(tabela->variavel, aux);
}

char *type(char *type){
    if (strcmp(type, "Int") == 0){
        type = "int";
        return type;
    }
    else if (strcmp(type, "Double") == 0){
        type = "double";
        return type;
    }
    else if (strcmp(type, "Bool") == 0){
        type = "boolean";
        return type;
    }
    else if (strcmp(type, "Void") == 0){
        type = "void";
        return type;
    }
    else if (strcmp(type, "StringArray") == 0){
        type = "String[]";
        return type;
    }
    return type;
}

bool verifica_repetido(metodo *aux, char *tipo, char *valor){
    
    bool verifica = true;
    while(aux != NULL){
        if(strcmp(aux->tipo, tipo) == 0){
            if(strcmp(aux->nome_funcao, valor) == 0){
                verifica = false;
            }
        }
        aux = aux->proximo_metodo;
    }
    return verifica;
}