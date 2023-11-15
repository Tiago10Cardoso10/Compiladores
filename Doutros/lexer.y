%{

#include "ast.h"

int yylex(void);
void yyerror(const char *);

struct node *program;

//int yydebug = 1;

%}

%token COMMA
%token CHAR INT VOID SHORT DOUBLE
%token IF ELSE WHILE RETURN 
%token ASSIGN
%token PLUS MINUS MUL DIV MOD 
%token OR AND BITWISEAND BITWISEOR BITWISEXOR
%token EQ NE LE GE LT GT 
%token NOT
%token LPAR RPAR LBRACE RBRACE SEMI

%token<token> IDENTIFIER NATURAL CHRLIT DECIMAL RESERVED

%nonassoc THEN
%nonassoc ELSE
%left LPAR RPAR
%left COMMA
%left ASSIGN
%left OR
%left AND 
%left BITWISEOR
%left BITWISEXOR
%left BITWISEAND
%left EQ NE 
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT \

%union{
     char *token;
     struct node* node;
     struct node_list* node_list;
}

%type <node> program functions_and_declarations func_definition func_body func_declaration param_list param_declaration declaration declarator_list declarator statement statements expr expr_no_comma TypeSpec args
%type <node_list> decl_and_statements

%%

program: functions_and_declarations { $$ = program = newnode(Program, NULL);
                                addchild($$, $1);
                              }
       ;

functions_and_declarations:
         func_definition functions_and_declarations { $$ = $1;}
       | func_declaration functions_and_declarations {$$ = $1; }
       | declaration functions_and_declarations { $$ = $1; }
       | {  }
       ;

func_definition: TypeSpec IDENTIFIER LPAR param_list RPAR func_body { $$ = newnode(FuncDefinition, NULL);
                                                                      addchild($$, $1);
                                                                      addchild($$, newnode(Identifier, $2));
                                                                      addchild($$, $4);
                                                                      addchild($$, $6);
                                                                    }
               ;
func_body: LBRACE decl_and_statements RBRACE { 
              $$ = newnode(FuncBody, NULL);
              struct node_list* stmts_and_decls = reverse_list($2);
              while(stmts_and_decls != NULL){
                  addchild($$, stmts_and_decls->node);
                  stmts_and_decls = stmts_and_decls->next;
              }
          }
          ;

decl_and_statements: 
    statement decl_and_statements { 
        $$ = append_node($2, $1);
    }
  | declaration decl_and_statements { 
        $$ = append_node($2, $1);
    }  
  | statement { 
        $$ = node_to_nodelist($1);
    }
  | declaration { 
        $$ = node_to_nodelist($1);
    }
  ;


func_declaration: TypeSpec IDENTIFIER LPAR param_list RPAR SEMI { $$ = newnode(FuncDeclaration, NULL);
                                                                  addchild($$, $1);
                                                                  addchild($$, newnode(Identifier, $2));
                                                                  addchild($$, $4);
                                                                }
                ;

param_list:
         param_declaration COMMA param_list { $$ = newnode(ParamList, NULL); 
                                              addchild($$, $1);
                                              addchild($$, $3);
                                             }
       | param_declaration { $$ = newnode(ParamList, NULL); 
                            addchild($$, $1);
                           }
       | {   }
       ;

param_declaration:
         TypeSpec IDENTIFIER { $$ = newnode(ParamDeclaration, NULL); 
                               addchild($$, $1);
                               addchild($$, newnode(Identifier, $2));
                             }
       | TypeSpec { $$ = newnode(ParamDeclaration, NULL); 
                    addchild($$, $1);
                  }
       ;

declaration: TypeSpec declarator_list SEMI { $$ = newnode(Declaration, NULL);
                                             addchild($$, $1);
                                             addchild($$, $2);
                                           }
           ;

declarator_list:
         declarator COMMA declarator_list { 

           }
       | declarator { $$ = $1;
        }
       ;

TypeSpec:
         CHAR { $$ = newnode(Char, NULL); }
       | INT { $$ = newnode(Int, NULL); }
       | VOID { $$ = newnode(Void, NULL); }
       | SHORT { $$ = newnode(Short, NULL); }
       | DOUBLE { $$ = newnode(Double, NULL); }
       ;

declarator:
         IDENTIFIER ASSIGN expr { 
             $$ = newnode(Identifier, $1);
             addchild($$, $3);
         }
       | IDENTIFIER { $$ = newnode(Identifier, $1); }
       ;

statement:
         expr SEMI { $$ = $1; }
       | LBRACE statements RBRACE { $$ = newnode(StatList, NULL);
                                    addchild($$, $2);
                                  }
       | LBRACE error RBRACE {  }
       | IF LPAR expr RPAR statement %prec THEN { $$ = newnode(If, NULL);
                                                  addchild($$, $3);
                                                  addchild($$, $5);
                                                  addchild($$, newnode(Null, NULL));
                                                }  
       | IF LPAR expr RPAR statement ELSE statement { $$ = newnode(If, NULL);
                                                      addchild($$, $3);
                                                      addchild($$, $5);
                                                      addchild($$, $7);
                                                    }  
       | WHILE LPAR expr RPAR statement { $$ = newnode(While, NULL);
                                          addchild($$, $3);
                                          addchild($$, $5);
                                        }
       | RETURN expr SEMI { $$ = newnode(Return, NULL); 
                            addchild($$, $2);
                          }
       | RETURN SEMI { $$ = newnode(Return, NULL); 
                       addchild($$, newnode(Null, NULL));
                     }
       | error SEMI { }
       ;

statements:
         statement statements { 
               addchild($$, $2);
               $$ = $1;
          }
       | {  }
       ;

expr:
         expr ASSIGN expr { $$ = newnode(Store, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr COMMA expr { $$ = newnode(Comma, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr PLUS expr { $$ = newnode(Add, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr MINUS expr { $$ = newnode(Sub, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr MUL expr { $$ = newnode(Mul, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr DIV expr { $$ = newnode(Div, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr MOD expr { $$ = newnode(Mod, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr OR expr { $$ = newnode(Or, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr AND expr { $$ = newnode(And, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr BITWISEOR expr { $$ = newnode(BitWiseOr, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr BITWISEXOR expr { $$ = newnode(BitWiseXor, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr BITWISEAND expr { $$ = newnode(BitWiseAnd, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr EQ expr { $$ = newnode(Eq, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr NE expr { $$ = newnode(Ne, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr LT expr { $$ = newnode(Lt, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr LE expr { $$ = newnode(Le, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr GT expr { $$ = newnode(Gt, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | expr GE expr { $$ = newnode(Ge, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                          }
       | PLUS expr { $$ = newnode(Plus, NULL);
                            addchild($$, $2);
                          }
       | MINUS expr { $$ = newnode(Minus, NULL);
                            addchild($$, $2);
                          }
       | NOT expr { $$ = newnode(Not, NULL);
                            addchild($$, $2);
                          }
       | IDENTIFIER LPAR RPAR { $$ = newnode(Call, NULL);
                            addchild($$, newnode(Identifier, $1));
                          }
       | IDENTIFIER LPAR args RPAR { $$ = newnode(Call, NULL);
                            addchild($$, newnode(Identifier, $1));
                            addchild($$, $3);
                          }
       | IDENTIFIER LPAR error RPAR { }
       | IDENTIFIER { $$ = newnode(Identifier, $1); }
       | NATURAL { $$ = newnode(Natural, $1); }
       | CHRLIT { $$ = newnode(ChrLit, $1);}
       | DECIMAL { $$ = newnode(Decimal, $1); }
       | LPAR expr RPAR {  }
       | LPAR error RPAR { }
       ;

expr_no_comma:
         expr_no_comma ASSIGN expr_no_comma { $$ = newnode(Store, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma PLUS expr_no_comma { $$ = newnode(Plus, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma MINUS expr_no_comma { $$ = newnode(Minus, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma MUL expr_no_comma { $$ = newnode(Mul, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma DIV expr_no_comma { $$ = newnode(Div, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma MOD expr_no_comma { $$ = newnode(Mod, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma OR expr_no_comma { $$ = newnode(Or, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma AND expr_no_comma { $$ = newnode(And, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma BITWISEOR expr_no_comma { $$ = newnode(BitWiseOr, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma BITWISEXOR expr_no_comma { $$ = newnode(BitWiseXor, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma BITWISEAND expr_no_comma { $$ = newnode(BitWiseAnd, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma EQ expr_no_comma { $$ = newnode(Eq, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma NE expr_no_comma { $$ = newnode(Ne, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma LT expr_no_comma { $$ = newnode(Lt, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma LE expr_no_comma { $$ = newnode(Le, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma GT expr_no_comma { $$ = newnode(Gt, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | expr_no_comma GE expr_no_comma { $$ = newnode(Ge, NULL);
                            addchild($$, $1);
                            addchild($$, $3);
                           }
       | PLUS expr_no_comma  { $$ = newnode(Plus, NULL);
                            addchild($$, $2);
                           }
       | MINUS expr_no_comma { $$ = newnode(Minus, NULL);
                            addchild($$, $2);
                           } 
       | NOT expr_no_comma { $$ = newnode(Not, NULL);
                            addchild($$, $2);
                           }
       | IDENTIFIER LPAR RPAR { $$ = newnode(Call, NULL);
                            addchild($$, newnode(Identifier, $1));
                           }
       | IDENTIFIER LPAR args RPAR { $$ = newnode(Call, NULL);
                            addchild($$, newnode(Identifier, $1));
                            addchild($$, $3);
                           }
       | IDENTIFIER LPAR error RPAR { }
       | IDENTIFIER { $$ = newnode(Identifier, $1); }
       | NATURAL { $$ = newnode(Natural, $1); }
       | CHRLIT { $$ = newnode(ChrLit, $1);}
       | DECIMAL { $$ = newnode(Decimal, $1); }
       | LPAR expr_no_comma RPAR {  }
       | LPAR error RPAR { }

args:
     expr_no_comma { $$ = $1; }
     | expr_no_comma COMMA args { addchild($$, $3);
                                  $$ = $1;
                                }
     ;


%%

