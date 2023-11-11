#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "y.tab.h"

typedef enum{
        // Falta descobrir para que é isto
        no_raiz,
        no_declaracao,
        no_metodos,
        no_Statement2,
        no_operadores,
        no_terminais,
        no_id
    } tipo_no;

typedef struct no * node;
    typedef struct no{
        node pai;
        node filho;
        node irmao;
        tipo_no no_tipo;
        char *valor;           
        char *tipo;            
        int num_filhos;
    } no;