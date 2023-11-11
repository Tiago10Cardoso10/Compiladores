int main(void){
	
	double x=1.5;
	
	int a=1,b=2,c=3;
	
	short d=4;
	
	char c = 'a';
	
	a=(-1*3+2/4);
		
}

Expr:    
    Expr Expr2 Expr                                         {}
    | Expr Expr3 Expr                                       {}
    | Expr Expr4 Expr                                       {}
    | Expr Expr5 Expr                                       {}
    | Expr6 Expr                                            {}
    | IDENTIFIER LPAR RPAR                                  {}    
    | IDENTIFIER LPAR Expr7 RPAR                            {}
    | IDENTIFIER                                            {}
    | NATURAL                                               {}
    | CHRLIT                                                {}
    | DECIMAL                                               {}
    | LPAR Expr RPAR                                        {}
    ;

Expr2:
    ASSIGN                                                  {}
    | COMMA                                                 {}
    ;

Expr3:
    PLUS                                                    {}
    | MINUS                                                 {}
    | MUL                                                   {}
    | DIV                                                   {}
    | MOD                                                   {}
    ;

Expr4:
    OR                                                      {}
    | AND                                                   {}
    | BITWISEAND                                            {}
    | BITWISEOR                                             {}
    | BITWISEXOR                                            {}
    ;

Expr5:
    EQ                                                      {}
    | NE                                                    {}
    | LE                                                    {}
    | GE                                                    {}
    | LT                                                    {}
    | GT                                                    {}
    ;

Expr6:
    PLUS                                                    {}
    | MINUS                                                 {}
    | NOT                                                   {}
    ;

Expr7:
    Expr Expr8                                              {}
    ;

Expr8:/* empty */                                           {}
    | COMMA Expr                                            {}
    ;
