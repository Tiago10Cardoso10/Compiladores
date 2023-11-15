#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// Helper function to convert the category enum to a string
const char* categoryToString(enum category cat) {
    switch(cat) {
        case Program: return "Program";
        case Declaration: return "Declaration";
        case FuncDeclaration: return "FuncDeclaration";
        case FuncDefinition: return "FuncDefinition";
        case ParamList: return "ParamList";
        case FuncBody: return "FuncBody";
        case ParamDeclaration: return "ParamDeclaration";
        case StatList: return "StatList";
        case If: return "If";
        case While: return "While";
        case Return: return "Return";
        case Or: return "Or";
        case And: return "And";
        case Eq: return "Eq";
        case Ne: return "Ne";
        case Lt: return "Lt";
        case Gt: return "Gt";
        case Le: return "Le";
        case Ge: return "Ge";
        case Add: return "Add";
        case Sub: return "Sub";
        case Mul: return "Mul";
        case Div: return "Div";
        case Mod: return "Mod";
        case Not: return "Not";
        case Minus: return "Minus";
        case Plus: return "Plus";
        case Store: return "Store";
        case Comma: return "Comma";
        case Call: return "Call";
        case BitWiseAnd: return "BitWiseAnd";
        case BitWiseXor: return "BitWiseXor";
        case BitWiseOr: return "BitWiseOr";
        case Char: return "Char";
        case ChrLit: return "ChrLit";
        case Identifier: return "Identifier";
        case Int: return "Int";
        case Short: return "Short";
        case Natural: return "Natural";
        case Double: return "Double";
        case Decimal: return "Decimal";
        case Void: return "Void";
        case Null: return "Null";
        default: return "Unknown";
    }
}



/*
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    return new;
}
*/

// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    //printf("%s\n", categoryToString(category));
    new->category = category;
    new->token = token;
    new->children = NULL;
    return new;
}

// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) {
    //printf("parent name: %s\n", categoryToString(parent->category));
    if(!parent->children){
        parent->children = malloc(sizeof(struct node_list));
        parent->children->node = child;
        parent->children->next = NULL;
    } else {
        struct node_list *new = malloc(sizeof(struct node_list));
        new->node = child;
        new->next = NULL;
        struct node_list *children = parent->children;
        while(children->next != NULL)
            children = children->next;
        children->next = new;
    }
    //printf("parent: %s\t\tchild: %s\n", categoryToString(parent->category), categoryToString(child->category));
}

struct node_list *append_node(struct node_list *list, struct node *new_node) {
    struct node_list *new_list_node = malloc(sizeof(struct node_list));
    new_list_node->node = new_node;
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
    list_item->node = node;
    list_item->next = NULL;
    return list_item;
}

struct node *nodelist_to_node(struct node_list *node_list) {
    struct node *node = malloc(sizeof(struct node));
    node = node_list->node;
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

void ast_print(struct node *node, int depth) {
    // Indentation based on depth
    for (int i = 0; i < depth; i++) {
        printf(".."); // Using two spaces for indentation
    }
    
    // Print the node's category and token. 
    if(node->token)
        printf("%s(%s)\n", categoryToString(node->category), node->token);
    else
        printf("%s\n", categoryToString(node->category));
    // Recursively print the children
    struct node_list *current = node->children;
    while (current && current->node) {
        ast_print(current->node, depth + 1);
        current = current->next;
    }
}
