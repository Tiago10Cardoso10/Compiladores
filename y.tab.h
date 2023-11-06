/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    ASSIGN = 262,                  /* ASSIGN  */
    COMMA = 263,                   /* COMMA  */
    SEMI = 264,                    /* SEMI  */
    LPAR = 265,                    /* LPAR  */
    RPAR = 266,                    /* RPAR  */
    LBRACE = 267,                  /* LBRACE  */
    RBRACE = 268,                  /* RBRACE  */
    CHAR = 269,                    /* CHAR  */
    INT = 270,                     /* INT  */
    VOID = 271,                    /* VOID  */
    SHORT = 272,                   /* SHORT  */
    DOUBLE = 273,                  /* DOUBLE  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    RETURN = 277,                  /* RETURN  */
    RESERVED = 278,                /* RESERVED  */
    IDENTIFIER = 279,              /* IDENTIFIER  */
    NATURAL = 280,                 /* NATURAL  */
    DECIMAL = 281,                 /* DECIMAL  */
    CHRLIT = 282,                  /* CHRLIT  */
    OR = 283,                      /* OR  */
    AND = 284,                     /* AND  */
    BITWISEOR = 285,               /* BITWISEOR  */
    BITWISEXOR = 286,              /* BITWISEXOR  */
    BITWISEAND = 287,              /* BITWISEAND  */
    EQ = 288,                      /* EQ  */
    NE = 289,                      /* NE  */
    LT = 290,                      /* LT  */
    GT = 291,                      /* GT  */
    LE = 292,                      /* LE  */
    GE = 293,                      /* GE  */
    MOD = 294,                     /* MOD  */
    NOT = 295                      /* NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define PLUS 258
#define MINUS 259
#define MUL 260
#define DIV 261
#define ASSIGN 262
#define COMMA 263
#define SEMI 264
#define LPAR 265
#define RPAR 266
#define LBRACE 267
#define RBRACE 268
#define CHAR 269
#define INT 270
#define VOID 271
#define SHORT 272
#define DOUBLE 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define RETURN 277
#define RESERVED 278
#define IDENTIFIER 279
#define NATURAL 280
#define DECIMAL 281
#define CHRLIT 282
#define OR 283
#define AND 284
#define BITWISEOR 285
#define BITWISEXOR 286
#define BITWISEAND 287
#define EQ 288
#define NE 289
#define LT 290
#define GT 291
#define LE 292
#define GE 293
#define MOD 294
#define NOT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "uccompiler.y"

    char *v;
    struct no *no;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
