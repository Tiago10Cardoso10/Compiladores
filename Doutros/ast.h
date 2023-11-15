#ifndef _AST_H
#define _AST_H

enum category { Program, Declaration, FuncDeclaration, FuncDefinition, ParamList, FuncBody, ParamDeclaration, StatList, If, While, Return, Or, And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Store, Comma, Call, BitWiseAnd, BitWiseXor, BitWiseOr, Char, ChrLit, Identifier, Int, Short, Natural, Double, Decimal, Void, Null};

struct node {
    enum category category;
    char *token;
    struct node_list *children;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

const char* categoryToString(enum category cat);
struct node *newnode(enum category category, char *token);
void addchild(struct node *parent, struct node *child);
struct node_list *append_node(struct node_list *list, struct node *new_node);
struct node_list *node_to_nodelist(struct node *node);
struct node *nodelist_to_node(struct node_list *node_list);
struct node_list* reverse_list(struct node_list* head);
void ast_print(struct node *node, int depth);

#endif
