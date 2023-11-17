#ifndef _TREE_H
#define _TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>


/*
enum tipo_no{
    Program,
    Declaration,
    FuncDeclaration,
    FuncDefinition,
    ParamList,
    FuncBody,
    ParamDeclaration,
    StatList,
    If,
    While,
    Return,
    Or,
    And,
    Eq,
    Ne,
    Lt,
    Gt,
    Le,
    Ge,
    Add, 
    Sub, 
    Mul, 
    Div, 
    Mod, 
    Not, 
    Minus, 
    Plus, 
    Store, 
    Comma, 
    Call, 
    BitWiseAnd,
    BitWiseXor, 
    BitWiseOr, 
    Char, 
    Chrlit, 
    Identifier, 
    Int, 
    Short, 
    Natural, 
    Double, 
    Decimal, 
    Void,
    Null
};
*/

typedef enum tipo_no{
    no_raiz,
    no_declaracao,
    no_funcoes,
    no_statments,
    no_operadores,
    no_terminais,
    no_especial,
}tipo_no;

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

struct node *criar_no(enum tipo_no tipo_no,char *tipo, char *token);
void adicionar_filho(struct node *pai, struct node *filho);
void adicionar_irmao(struct node *irmao, struct node *novo);
void imprime_arvore(struct node *no, int num);
struct node_list *node_to_nodelist(struct node *node);
int conta_irmaos(struct node *raiz);
int conta_filhos(struct node *raiz);

#endif