/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "uccompiler.y"

/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/

<<<<<<< HEAD
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

 typedef enum{
        no_raiz,
        no_declaracao,
        no_metodos,
        no_statements,
=======
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdarg.h>


int yylex(void);
void yyerror(const char* s);

typedef enum{
        no_raiz,
        no_declaracao,
        no_metodos,
        no_Statement2,
>>>>>>> TiagoCardoso
        no_operadores,
        no_terminais,
        no_id
    } tipo_no;

<<<<<<< HEAD
    typedef struct no * node;
=======
typedef struct no * node;
>>>>>>> TiagoCardoso
    typedef struct no{
        node pai;
        node filho;
        node irmao;
        tipo_no no_tipo;
        char *valor;           
        char *tipo;            
        int num_filhos;
    } no;

<<<<<<< HEAD
    int yylex(void);
    void yyerror(const char *s);


#line 108 "y.tab.c"
=======


#line 110 "y.tab.c"
>>>>>>> TiagoCardoso

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
<<<<<<< HEAD
#line 38 "uccompiler.y"
=======
#line 40 "uccompiler.y"
>>>>>>> TiagoCardoso

    char *v;
    struct no *no;

<<<<<<< HEAD
#line 246 "y.tab.c"
=======
#line 248 "y.tab.c"
>>>>>>> TiagoCardoso

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_ASSIGN = 7,                     /* ASSIGN  */
  YYSYMBOL_COMMA = 8,                      /* COMMA  */
  YYSYMBOL_SEMI = 9,                       /* SEMI  */
  YYSYMBOL_LPAR = 10,                      /* LPAR  */
  YYSYMBOL_RPAR = 11,                      /* RPAR  */
  YYSYMBOL_LBRACE = 12,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 13,                    /* RBRACE  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_SHORT = 17,                     /* SHORT  */
  YYSYMBOL_DOUBLE = 18,                    /* DOUBLE  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_RESERVED = 23,                  /* RESERVED  */
  YYSYMBOL_IDENTIFIER = 24,                /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 25,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 26,                   /* DECIMAL  */
  YYSYMBOL_CHRLIT = 27,                    /* CHRLIT  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_BITWISEOR = 30,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEXOR = 31,                /* BITWISEXOR  */
  YYSYMBOL_BITWISEAND = 32,                /* BITWISEAND  */
  YYSYMBOL_EQ = 33,                        /* EQ  */
  YYSYMBOL_NE = 34,                        /* NE  */
  YYSYMBOL_LT = 35,                        /* LT  */
  YYSYMBOL_GT = 36,                        /* GT  */
  YYSYMBOL_LE = 37,                        /* LE  */
  YYSYMBOL_GE = 38,                        /* GE  */
  YYSYMBOL_MOD = 39,                       /* MOD  */
  YYSYMBOL_NOT = 40,                       /* NOT  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_FunctionsAndDeclarations = 42,  /* FunctionsAndDeclarations  */
<<<<<<< HEAD
  YYSYMBOL_FunctionOrDeclaration = 43,     /* FunctionOrDeclaration  */
  YYSYMBOL_FunctionDefinition = 44,        /* FunctionDefinition  */
  YYSYMBOL_FunctionBody = 45,              /* FunctionBody  */
  YYSYMBOL_OpcionalDeclarationAndStatements = 46, /* OpcionalDeclarationAndStatements  */
  YYSYMBOL_DeclarationsAndStatements = 47, /* DeclarationsAndStatements  */
=======
  YYSYMBOL_FunctionAndDeclarations2 = 43,  /* FunctionAndDeclarations2  */
  YYSYMBOL_FunctionDefinition = 44,        /* FunctionDefinition  */
  YYSYMBOL_FunctionBody = 45,              /* FunctionBody  */
  YYSYMBOL_DeclarationAndStatement2 = 46,  /* DeclarationAndStatement2  */
  YYSYMBOL_DeclarationsAndStatement = 47,  /* DeclarationsAndStatement  */
>>>>>>> TiagoCardoso
  YYSYMBOL_FunctionDeclaration = 48,       /* FunctionDeclaration  */
  YYSYMBOL_FunctionDeclarator = 49,        /* FunctionDeclarator  */
  YYSYMBOL_ParameterList = 50,             /* ParameterList  */
  YYSYMBOL_ParameterDeclaration = 51,      /* ParameterDeclaration  */
  YYSYMBOL_Declaration = 52,               /* Declaration  */
<<<<<<< HEAD
  YYSYMBOL_DeclaratorList = 53,            /* DeclaratorList  */
  YYSYMBOL_TypeSpec = 54,                  /* TypeSpec  */
  YYSYMBOL_Declarator = 55,                /* Declarator  */
  YYSYMBOL_Statement = 56,                 /* Statement  */
  YYSYMBOL_Statements = 57,                /* Statements  */
  YYSYMBOL_Expr = 58,                      /* Expr  */
  YYSYMBOL_ArgumentExpr = 59               /* ArgumentExpr  */
=======
  YYSYMBOL_Declaration2 = 53,              /* Declaration2  */
  YYSYMBOL_TypeSpec = 54,                  /* TypeSpec  */
  YYSYMBOL_Declarator = 55,                /* Declarator  */
  YYSYMBOL_Statement = 56,                 /* Statement  */
  YYSYMBOL_Statement2 = 57,                /* Statement2  */
  YYSYMBOL_Expr = 58,                      /* Expr  */
  YYSYMBOL_Expr2 = 59                      /* Expr2  */
>>>>>>> TiagoCardoso
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
<<<<<<< HEAD
#define YYLAST   465
=======
#define YYLAST   443
>>>>>>> TiagoCardoso

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122
=======
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123
>>>>>>> TiagoCardoso

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
<<<<<<< HEAD
       0,    66,    66,    67,    71,    72,    73,    77,    81,    84,
      85,    89,    90,    91,    92,    96,   100,   104,   105,   109,
     110,   114,   118,   119,   123,   124,   125,   126,   127,   131,
     132,   136,   137,   138,   139,   140,   141,   142,   143,   146,
     147,   151,   152,   154,   155,   156,   157,   158,   160,   161,
     162,   163,   164,   166,   167,   168,   169,   170,   171,   173,
     174,   175,   177,   178,   180,   181,   182,   183,   184,   188,
     189
=======
       0,    68,    68,    69,    73,    74,    75,    79,    83,    87,
      91,    92,    93,    94,    98,   102,   106,   107,   111,   112,
     116,   120,   121,   125,   126,   127,   128,   129,   133,   134,
     138,   139,   140,   141,   142,   143,   144,   145,   149,   150,
     154,   155,   157,   158,   159,   160,   161,   163,   164,   165,
     166,   167,   169,   170,   171,   172,   173,   174,   176,   177,
     178,   180,   181,   183,   184,   185,   186,   187,   191,   192
>>>>>>> TiagoCardoso
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS", "MUL",
  "DIV", "ASSIGN", "COMMA", "SEMI", "LPAR", "RPAR", "LBRACE", "RBRACE",
  "CHAR", "INT", "VOID", "SHORT", "DOUBLE", "IF", "ELSE", "WHILE",
  "RETURN", "RESERVED", "IDENTIFIER", "NATURAL", "DECIMAL", "CHRLIT", "OR",
  "AND", "BITWISEOR", "BITWISEXOR", "BITWISEAND", "EQ", "NE", "LT", "GT",
  "LE", "GE", "MOD", "NOT", "$accept", "FunctionsAndDeclarations",
<<<<<<< HEAD
  "FunctionOrDeclaration", "FunctionDefinition", "FunctionBody",
  "OpcionalDeclarationAndStatements", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterDeclaration", "Declaration", "DeclaratorList", "TypeSpec",
  "Declarator", "Statement", "Statements", "Expr", "ArgumentExpr", YY_NULLPTR
=======
  "FunctionAndDeclarations2", "FunctionDefinition", "FunctionBody",
  "DeclarationAndStatement2", "DeclarationsAndStatement",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterDeclaration", "Declaration", "Declaration2", "TypeSpec",
  "Declarator", "Statement", "Statement2", "Expr", "Expr2", YY_NULLPTR
>>>>>>> TiagoCardoso
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
     143,   -58,   -58,   -58,   -58,   -58,    11,   -58,   -58,   -58,
     -58,   -19,   -58,   -58,    28,     5,    14,   -58,   146,   143,
     -58,    61,   -58,   -12,   -58,   146,   146,   146,     6,   -58,
     -58,   -58,   146,   319,    10,   -58,    33,   -58,   -58,    48,
      57,   115,    55,   -58,    61,   -12,    61,   171,    65,   -58,
      -3,   282,   -58,   184,   142,    85,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   143,   -58,   -58,    86,   146,   146,
     -58,   221,   -58,   -58,   -58,   -58,   146,   -58,   -58,    73,
      -3,    -3,    85,    85,    85,   319,   330,   367,   376,   384,
     421,   426,   426,    27,    27,    27,    27,    85,   -58,   -58,
     -58,   233,   270,   -58,   319,   -58,   111,   111,    74,   -58,
     111,   -58
=======
     195,   -58,   -58,   -58,   -58,   -58,   121,   -58,   -58,   -58,
     -58,    -6,   -58,   -58,     6,     8,    19,   -58,   124,   195,
     -58,    64,   -58,    10,   -58,   124,   124,   124,    25,   -58,
     -58,   -58,   124,   297,    14,   -58,    13,   -58,    -5,    29,
      48,    93,    46,   -58,    64,    10,    64,    53,   149,    62,
     -58,    -3,   260,   -58,   162,   120,    63,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   195,   -58,   -58,    89,   124,
     124,   -58,   199,   -58,   -58,   -58,   -58,   -58,   124,   -58,
     -58,    15,    -3,    -3,    63,    63,    63,   297,   308,   345,
     354,   362,   399,   404,   404,    26,    26,    26,    26,    63,
     -58,   -58,   211,   248,   -58,   297,   -58,    89,    89,    52,
     -58,    89,   -58
>>>>>>> TiagoCardoso
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
<<<<<<< HEAD
       0,    24,    25,    26,    27,    28,     0,     2,     4,     5,
       6,     0,     1,     3,    29,     0,     0,    22,     0,     0,
      15,     9,     7,     0,    21,     0,     0,     0,    64,    65,
      67,    66,     0,    30,     0,    17,    20,    31,    39,     0,
       0,     0,     0,    10,    14,     0,    13,     0,    29,    23,
      59,    69,    60,     0,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    19,     0,     0,     0,
      37,     0,     8,    12,    11,    32,     0,    68,    62,     0,
      43,    44,    45,    46,    41,    42,    48,    49,    51,    52,
      50,    53,    54,    57,    58,    55,    56,    47,    18,    33,
      40,     0,     0,    38,    70,    63,     0,     0,    34,    36,
       0,    35
=======
       0,    23,    24,    25,    26,    27,     0,     2,     4,     5,
       6,     0,     1,     3,    28,     0,     0,    21,     0,     0,
      14,     0,     7,     0,    20,     0,     0,     0,    63,    64,
      66,    65,     0,    29,     0,    16,    19,    30,    38,     0,
       0,     0,     0,     9,    13,     0,    12,     0,     0,    28,
      22,    58,    68,    59,     0,     0,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    18,     0,     0,
       0,    36,     0,     8,    11,    10,    32,    31,     0,    67,
      61,     0,    42,    43,    44,    45,    40,    41,    47,    48,
      50,    51,    49,    52,    53,    56,    57,    54,    55,    46,
      17,    39,     0,     0,    37,    69,    62,     0,     0,    33,
      35,     0,    34
>>>>>>> TiagoCardoso
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -58,   -58,    91,   -58,   -58,   -58,    47,   -58,   -58,   -58,
      26,     7,   -58,     0,    79,   -57,   -58,   -17,    49
=======
     -58,   -58,    71,   -58,   -58,   -58,   -32,   -58,   -58,   -58,
       9,     5,   -58,     0,    72,   -57,    49,   -17,    39
>>>>>>> TiagoCardoso
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,    22,    42,    43,     9,    15,    34,
<<<<<<< HEAD
      35,    44,    16,    45,    17,    46,    77,    47,    52
=======
      35,    44,    16,    45,    17,    46,    47,    48,    53
>>>>>>> TiagoCardoso
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
<<<<<<< HEAD
      11,    33,    58,    59,    60,    14,    11,    10,    50,    51,
      53,    12,    48,    10,    20,    55,    54,    21,    74,    36,
     110,    75,    23,    24,    81,     1,     2,     3,     4,     5,
      56,    57,    58,    59,    60,    18,    73,    51,    19,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,    76,    78,   118,
     119,   111,   112,   121,    25,    26,    73,    79,    82,   114,
      37,    27,    18,    38,    36,     1,     2,     3,     4,     5,
      39,    86,    40,    41,   115,    28,    29,    30,    31,    25,
      26,    83,    60,    84,   120,    37,    27,    13,    38,   109,
     108,    32,    49,    89,     0,    39,     0,    40,    41,     0,
      28,    29,    30,    31,    25,    26,     0,     0,    25,    26,
      37,    27,     0,    38,    80,    27,    32,     0,     0,     0,
      39,     0,    40,    41,     0,    28,    29,    30,    31,    28,
      29,    30,    31,     0,     0,    25,    26,     0,     0,    25,
      26,    32,    27,    88,     0,    32,    27,     1,     2,     3,
       4,     5,     0,     0,     0,     0,    28,    29,    30,    31,
      28,    29,    30,    31,    56,    57,    58,    59,    60,    61,
      85,     0,    32,     0,     0,     0,    32,    56,    57,    58,
      59,    60,    61,     0,     0,    87,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    56,    57,    58,    59,    60,    61,
     113,     0,     0,     0,     0,     0,    56,    57,    58,    59,
      60,    61,     0,     0,   116,     0,     0,     0,     0,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    56,    57,    58,    59,    60,    61,     0,
       0,   117,     0,     0,     0,    56,    57,    58,    59,    60,
      61,     0,     0,     0,     0,     0,     0,     0,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      56,    57,    58,    59,    60,     0,     0,     0,     0,    56,
      57,    58,    59,    60,     0,     0,     0,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    66,    67,    68,    69,
      70,    71,    72,    73,    56,    57,    58,    59,    60,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    68,    69,    70,    71,    72,
      73,    69,    70,    71,    72,    73
=======
      11,    33,    59,    60,    61,    10,    11,    38,    51,    52,
      54,    10,    84,    18,    85,    56,    19,    20,    14,    36,
      21,   111,    75,    88,    82,    76,   116,    23,    24,    57,
      58,    59,    60,    61,    49,    55,    74,    77,    52,    79,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,    80,    83,
     119,   120,   112,   113,   122,    74,    86,    25,    26,    18,
      61,   115,   121,    37,    27,    36,    38,    13,     1,     2,
       3,     4,     5,    39,   110,    40,    41,    78,    28,    29,
      30,    31,    25,    26,    91,    50,    25,    26,    37,    27,
       0,    38,    81,    27,    32,     0,     0,     0,    39,     0,
      40,    41,     0,    28,    29,    30,    31,    28,    29,    30,
      31,    12,     0,    25,    26,     0,     0,    25,    26,    32,
      27,    90,     0,    32,    27,     1,     2,     3,     4,     5,
       0,     0,     0,     0,    28,    29,    30,    31,    28,    29,
      30,    31,    57,    58,    59,    60,    61,    62,    87,     0,
      32,     0,     0,     0,    32,    57,    58,    59,    60,    61,
      62,     0,     0,    89,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    57,    58,    59,    60,    61,    62,   114,     1,
       2,     3,     4,     5,    57,    58,    59,    60,    61,    62,
       0,     0,   117,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    57,    58,    59,    60,    61,    62,     0,     0,   118,
       0,     0,     0,    57,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      57,    58,    59,    60,    61,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    57,    58,
      59,    60,    61,     0,     0,     0,     0,    57,    58,    59,
      60,    61,     0,     0,     0,    57,    58,    59,    60,    61,
       0,     0,     0,     0,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    67,    68,    69,    70,    71,    72,
      73,    74,    57,    58,    59,    60,    61,    57,    58,    59,
      60,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    69,    70,    71,    72,    73,    74,    70,
      71,    72,    73,    74
>>>>>>> TiagoCardoso
};

static const yytype_int8 yycheck[] =
{
<<<<<<< HEAD
       0,    18,     5,     6,     7,    24,     6,     0,    25,    26,
      27,     0,    24,     6,     9,    32,    10,    12,     8,    19,
      77,    11,     8,     9,    41,    14,    15,    16,    17,    18,
       3,     4,     5,     6,     7,     7,    39,    54,    10,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    24,    10,   116,
     117,    78,    79,   120,     3,     4,    39,    10,    13,    86,
       9,    10,     7,    12,    74,    14,    15,    16,    17,    18,
      19,     8,    21,    22,    11,    24,    25,    26,    27,     3,
       4,    44,     7,    46,    20,     9,    10,     6,    12,    13,
      74,    40,    23,    54,    -1,    19,    -1,    21,    22,    -1,
      24,    25,    26,    27,     3,     4,    -1,    -1,     3,     4,
       9,    10,    -1,    12,     9,    10,    40,    -1,    -1,    -1,
      19,    -1,    21,    22,    -1,    24,    25,    26,    27,    24,
      25,    26,    27,    -1,    -1,     3,     4,    -1,    -1,     3,
       4,    40,    10,    11,    -1,    40,    10,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      24,    25,    26,    27,     3,     4,     5,     6,     7,     8,
       9,    -1,    40,    -1,    -1,    -1,    40,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    -1,    -1,    -1,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    32,    33,    34,    35,
      36,    37,    38,    39,     3,     4,     5,     6,     7,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    35,    36,    37,    38,    39
=======
       0,    18,     5,     6,     7,     0,     6,    12,    25,    26,
      27,     6,    44,     7,    46,    32,    10,     9,    24,    19,
      12,    78,     8,     8,    41,    11,    11,     8,     9,     3,
       4,     5,     6,     7,    24,    10,    39,    24,    55,    10,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    10,    13,
     117,   118,    79,    80,   121,    39,    13,     3,     4,     7,
       7,    88,    20,     9,    10,    75,    12,     6,    14,    15,
      16,    17,    18,    19,    75,    21,    22,    38,    24,    25,
      26,    27,     3,     4,    55,    23,     3,     4,     9,    10,
      -1,    12,     9,    10,    40,    -1,    -1,    -1,    19,    -1,
      21,    22,    -1,    24,    25,    26,    27,    24,    25,    26,
      27,     0,    -1,     3,     4,    -1,    -1,     3,     4,    40,
      10,    11,    -1,    40,    10,    14,    15,    16,    17,    18,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    24,    25,
      26,    27,     3,     4,     5,     6,     7,     8,     9,    -1,
      40,    -1,    -1,    -1,    40,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     3,     4,     5,     6,     7,     8,     9,    14,
      15,    16,    17,    18,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     3,     4,     5,     6,     7,     8,    -1,    -1,    11,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    32,    33,    34,    35,    36,    37,
      38,    39,     3,     4,     5,     6,     7,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    35,
      36,    37,    38,    39
>>>>>>> TiagoCardoso
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    15,    16,    17,    18,    42,    43,    44,    48,
      52,    54,     0,    43,    24,    49,    53,    55,     7,    10,
       9,    12,    45,     8,     9,     3,     4,    10,    24,    25,
      26,    27,    40,    58,    50,    51,    54,     9,    12,    19,
<<<<<<< HEAD
      21,    22,    46,    47,    52,    54,    56,    58,    24,    55,
      58,    58,    59,    58,    10,    58,     3,     4,     5,     6,
       7,     8,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     8,    11,    24,    57,    10,    10,
       9,    58,    13,    47,    47,     9,     8,    11,    11,    59,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    51,    13,
      56,    58,    58,     9,    58,    11,    11,    11,    56,    56,
      20,    56
=======
      21,    22,    46,    47,    52,    54,    56,    57,    58,    24,
      55,    58,    58,    59,    58,    10,    58,     3,     4,     5,
       6,     7,     8,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     8,    11,    24,    57,    10,
      10,     9,    58,    13,    47,    47,    13,     9,     8,    11,
      11,    59,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      51,    56,    58,    58,     9,    58,    11,    11,    11,    56,
      56,    20,    56
>>>>>>> TiagoCardoso
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    43,    44,    45,    46,
<<<<<<< HEAD
      46,    47,    47,    47,    47,    48,    49,    50,    50,    51,
      51,    52,    53,    53,    54,    54,    54,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59
=======
      47,    47,    47,    47,    48,    49,    50,    50,    51,    51,
      52,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59
>>>>>>> TiagoCardoso
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
<<<<<<< HEAD
       0,     2,     1,     2,     1,     1,     1,     3,     3,     0,
       1,     2,     2,     1,     1,     3,     4,     1,     3,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     5,     7,     5,     2,     3,     0,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     4,     1,     1,     1,     1,     3,     1,
       3
=======
       0,     2,     1,     2,     1,     1,     1,     3,     3,     1,
       2,     2,     1,     1,     3,     4,     1,     3,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     2,     5,     7,     5,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     4,     1,     1,     1,     1,     3,     1,     3
>>>>>>> TiagoCardoso
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
<<<<<<< HEAD
  case 2: /* FunctionsAndDeclarations: FunctionOrDeclaration  */
#line 66 "uccompiler.y"
                                                            {}
#line 1434 "y.tab.c"
    break;

  case 3: /* FunctionsAndDeclarations: FunctionsAndDeclarations FunctionOrDeclaration  */
#line 67 "uccompiler.y"
                                                            {}
#line 1440 "y.tab.c"
    break;

  case 4: /* FunctionOrDeclaration: FunctionDefinition  */
#line 71 "uccompiler.y"
                                                            {}
#line 1446 "y.tab.c"
    break;

  case 5: /* FunctionOrDeclaration: FunctionDeclaration  */
#line 72 "uccompiler.y"
                                                            {}
#line 1452 "y.tab.c"
    break;

  case 6: /* FunctionOrDeclaration: Declaration  */
#line 73 "uccompiler.y"
                                                            {}
#line 1458 "y.tab.c"
    break;

  case 7: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 77 "uccompiler.y"
                                                            {}
#line 1464 "y.tab.c"
    break;

  case 8: /* FunctionBody: LBRACE OpcionalDeclarationAndStatements RBRACE  */
#line 81 "uccompiler.y"
                                                            {}
#line 1470 "y.tab.c"
    break;

  case 10: /* OpcionalDeclarationAndStatements: DeclarationsAndStatements  */
#line 85 "uccompiler.y"
                                                            {}
#line 1476 "y.tab.c"
    break;

  case 11: /* DeclarationsAndStatements: Statement DeclarationsAndStatements  */
#line 89 "uccompiler.y"
                                                            {}
#line 1482 "y.tab.c"
    break;

  case 12: /* DeclarationsAndStatements: Declaration DeclarationsAndStatements  */
#line 90 "uccompiler.y"
                                                            {}
#line 1488 "y.tab.c"
    break;

  case 13: /* DeclarationsAndStatements: Statement  */
#line 91 "uccompiler.y"
                                                            {}
#line 1494 "y.tab.c"
    break;

  case 14: /* DeclarationsAndStatements: Declaration  */
#line 92 "uccompiler.y"
                                                            {}
#line 1500 "y.tab.c"
    break;

  case 15: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 96 "uccompiler.y"
                                                           {}
#line 1506 "y.tab.c"
    break;

  case 16: /* FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR  */
#line 100 "uccompiler.y"
                                                            {}
#line 1512 "y.tab.c"
    break;

  case 17: /* ParameterList: ParameterDeclaration  */
#line 104 "uccompiler.y"
                                                            {}
#line 1518 "y.tab.c"
    break;

  case 18: /* ParameterList: ParameterList COMMA ParameterDeclaration  */
#line 105 "uccompiler.y"
                                                            {}
#line 1524 "y.tab.c"
    break;

  case 19: /* ParameterDeclaration: TypeSpec IDENTIFIER  */
#line 109 "uccompiler.y"
                                                            {}
#line 1530 "y.tab.c"
    break;

  case 20: /* ParameterDeclaration: TypeSpec  */
#line 110 "uccompiler.y"
                                                            {}
#line 1536 "y.tab.c"
    break;

  case 21: /* Declaration: TypeSpec DeclaratorList SEMI  */
#line 114 "uccompiler.y"
                                                            {}
#line 1542 "y.tab.c"
    break;

  case 22: /* DeclaratorList: Declarator  */
#line 118 "uccompiler.y"
                                                            {}
#line 1548 "y.tab.c"
    break;

  case 23: /* DeclaratorList: DeclaratorList COMMA Declarator  */
#line 119 "uccompiler.y"
                                                            {}
#line 1554 "y.tab.c"
    break;

  case 24: /* TypeSpec: CHAR  */
#line 123 "uccompiler.y"
                                                            {}
#line 1560 "y.tab.c"
    break;

  case 25: /* TypeSpec: INT  */
#line 124 "uccompiler.y"
                                                            {}
#line 1566 "y.tab.c"
    break;

  case 26: /* TypeSpec: VOID  */
#line 125 "uccompiler.y"
                                                            {}
#line 1572 "y.tab.c"
    break;

  case 27: /* TypeSpec: SHORT  */
#line 126 "uccompiler.y"
                                                            {}
#line 1578 "y.tab.c"
    break;

  case 28: /* TypeSpec: DOUBLE  */
#line 127 "uccompiler.y"
                                                            {}
#line 1584 "y.tab.c"
    break;

  case 29: /* Declarator: IDENTIFIER  */
#line 131 "uccompiler.y"
                                                            {}
#line 1590 "y.tab.c"
    break;

  case 30: /* Declarator: IDENTIFIER ASSIGN Expr  */
#line 132 "uccompiler.y"
                                                            {}
#line 1596 "y.tab.c"
    break;

  case 31: /* Statement: SEMI  */
#line 136 "uccompiler.y"
                                                            {}
#line 1602 "y.tab.c"
    break;

  case 32: /* Statement: Expr SEMI  */
#line 137 "uccompiler.y"
                                                            {}
#line 1608 "y.tab.c"
    break;

  case 33: /* Statement: LBRACE Statements RBRACE  */
#line 138 "uccompiler.y"
                                                            {}
#line 1614 "y.tab.c"
    break;

  case 34: /* Statement: IF LPAR Expr RPAR Statement  */
#line 139 "uccompiler.y"
                                                            {}
#line 1620 "y.tab.c"
    break;

  case 35: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 140 "uccompiler.y"
                                                            {}
#line 1626 "y.tab.c"
    break;

  case 36: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 141 "uccompiler.y"
                                                            {}
#line 1632 "y.tab.c"
    break;

  case 37: /* Statement: RETURN SEMI  */
#line 142 "uccompiler.y"
                                                            {}
#line 1638 "y.tab.c"
    break;

  case 38: /* Statement: RETURN Expr SEMI  */
#line 143 "uccompiler.y"
                                                            {}
#line 1644 "y.tab.c"
    break;

  case 40: /* Statements: Statements Statement  */
#line 147 "uccompiler.y"
                                                            {}
#line 1650 "y.tab.c"
    break;

  case 41: /* Expr: Expr ASSIGN Expr  */
#line 151 "uccompiler.y"
                                                            {}
#line 1656 "y.tab.c"
    break;

  case 42: /* Expr: Expr COMMA Expr  */
#line 152 "uccompiler.y"
                                                            {}
#line 1662 "y.tab.c"
    break;

  case 43: /* Expr: Expr PLUS Expr  */
#line 154 "uccompiler.y"
                                                            {}
#line 1668 "y.tab.c"
    break;

  case 44: /* Expr: Expr MINUS Expr  */
#line 155 "uccompiler.y"
                                                            {}
#line 1674 "y.tab.c"
    break;

  case 45: /* Expr: Expr MUL Expr  */
#line 156 "uccompiler.y"
                                                            {}
#line 1680 "y.tab.c"
    break;

  case 46: /* Expr: Expr DIV Expr  */
#line 157 "uccompiler.y"
                                                            {}
#line 1686 "y.tab.c"
    break;

  case 47: /* Expr: Expr MOD Expr  */
#line 158 "uccompiler.y"
                                                            {}
#line 1692 "y.tab.c"
    break;

  case 48: /* Expr: Expr OR Expr  */
#line 160 "uccompiler.y"
                                                            {}
#line 1698 "y.tab.c"
    break;

  case 49: /* Expr: Expr AND Expr  */
#line 161 "uccompiler.y"
                                                            {}
#line 1704 "y.tab.c"
    break;

  case 50: /* Expr: Expr BITWISEAND Expr  */
#line 162 "uccompiler.y"
                                                            {}
#line 1710 "y.tab.c"
    break;

  case 51: /* Expr: Expr BITWISEOR Expr  */
#line 163 "uccompiler.y"
                                                            {}
#line 1716 "y.tab.c"
    break;

  case 52: /* Expr: Expr BITWISEXOR Expr  */
#line 164 "uccompiler.y"
                                                            {}
#line 1722 "y.tab.c"
    break;

  case 53: /* Expr: Expr EQ Expr  */
#line 166 "uccompiler.y"
                                                            {}
#line 1728 "y.tab.c"
    break;

  case 54: /* Expr: Expr NE Expr  */
#line 167 "uccompiler.y"
                                                            {}
#line 1734 "y.tab.c"
    break;

  case 55: /* Expr: Expr LE Expr  */
#line 168 "uccompiler.y"
                                                            {}
#line 1740 "y.tab.c"
    break;

  case 56: /* Expr: Expr GE Expr  */
#line 169 "uccompiler.y"
                                                            {}
#line 1746 "y.tab.c"
    break;

  case 57: /* Expr: Expr LT Expr  */
#line 170 "uccompiler.y"
                                                            {}
#line 1752 "y.tab.c"
    break;

  case 58: /* Expr: Expr GT Expr  */
#line 171 "uccompiler.y"
                                                            {}
#line 1758 "y.tab.c"
    break;

  case 59: /* Expr: PLUS Expr  */
#line 173 "uccompiler.y"
                                                            {}
#line 1764 "y.tab.c"
    break;

  case 60: /* Expr: MINUS ArgumentExpr  */
#line 174 "uccompiler.y"
                                                            {}
#line 1770 "y.tab.c"
    break;

  case 61: /* Expr: NOT Expr  */
#line 175 "uccompiler.y"
                                                            {}
#line 1776 "y.tab.c"
    break;

  case 62: /* Expr: IDENTIFIER LPAR RPAR  */
#line 177 "uccompiler.y"
                                                            {}
#line 1782 "y.tab.c"
    break;

  case 63: /* Expr: IDENTIFIER LPAR ArgumentExpr RPAR  */
#line 178 "uccompiler.y"
                                                            {}
#line 1788 "y.tab.c"
    break;

  case 64: /* Expr: IDENTIFIER  */
#line 180 "uccompiler.y"
                                                            {}
#line 1794 "y.tab.c"
    break;

  case 65: /* Expr: NATURAL  */
#line 181 "uccompiler.y"
                                                            {}
#line 1800 "y.tab.c"
    break;

  case 66: /* Expr: CHRLIT  */
#line 182 "uccompiler.y"
                                                            {}
#line 1806 "y.tab.c"
    break;

  case 67: /* Expr: DECIMAL  */
#line 183 "uccompiler.y"
                                                            {}
#line 1812 "y.tab.c"
    break;

  case 68: /* Expr: LPAR Expr RPAR  */
#line 184 "uccompiler.y"
                                                            {}
#line 1818 "y.tab.c"
    break;

  case 69: /* ArgumentExpr: Expr  */
#line 188 "uccompiler.y"
                                                            {}
#line 1824 "y.tab.c"
    break;

  case 70: /* ArgumentExpr: ArgumentExpr COMMA Expr  */
#line 189 "uccompiler.y"
                                                            {}
#line 1830 "y.tab.c"
    break;


#line 1834 "y.tab.c"
=======
  case 2: /* FunctionsAndDeclarations: FunctionAndDeclarations2  */
#line 68 "uccompiler.y"
                                                            {}
#line 1429 "y.tab.c"
    break;

  case 3: /* FunctionsAndDeclarations: FunctionsAndDeclarations FunctionAndDeclarations2  */
#line 69 "uccompiler.y"
                                                            {}
#line 1435 "y.tab.c"
    break;

  case 4: /* FunctionAndDeclarations2: FunctionDefinition  */
#line 73 "uccompiler.y"
                                                            {}
#line 1441 "y.tab.c"
    break;

  case 5: /* FunctionAndDeclarations2: FunctionDeclaration  */
#line 74 "uccompiler.y"
                                                            {}
#line 1447 "y.tab.c"
    break;

  case 6: /* FunctionAndDeclarations2: Declaration  */
#line 75 "uccompiler.y"
                                                            {}
#line 1453 "y.tab.c"
    break;

  case 7: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 79 "uccompiler.y"
                                                            {}
#line 1459 "y.tab.c"
    break;

  case 8: /* FunctionBody: LBRACE DeclarationAndStatement2 RBRACE  */
#line 83 "uccompiler.y"
                                                            {}
#line 1465 "y.tab.c"
    break;

  case 9: /* DeclarationAndStatement2: DeclarationsAndStatement  */
#line 87 "uccompiler.y"
                                                            {}
#line 1471 "y.tab.c"
    break;

  case 10: /* DeclarationsAndStatement: Statement DeclarationsAndStatement  */
#line 91 "uccompiler.y"
                                                            {}
#line 1477 "y.tab.c"
    break;

  case 11: /* DeclarationsAndStatement: Declaration DeclarationsAndStatement  */
#line 92 "uccompiler.y"
                                                            {}
#line 1483 "y.tab.c"
    break;

  case 12: /* DeclarationsAndStatement: Statement  */
#line 93 "uccompiler.y"
                                                            {}
#line 1489 "y.tab.c"
    break;

  case 13: /* DeclarationsAndStatement: Declaration  */
#line 94 "uccompiler.y"
                                                            {}
#line 1495 "y.tab.c"
    break;

  case 14: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 98 "uccompiler.y"
                                                            {}
#line 1501 "y.tab.c"
    break;

  case 15: /* FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR  */
#line 102 "uccompiler.y"
                                                            {}
#line 1507 "y.tab.c"
    break;

  case 16: /* ParameterList: ParameterDeclaration  */
#line 106 "uccompiler.y"
                                                            {}
#line 1513 "y.tab.c"
    break;

  case 17: /* ParameterList: ParameterList COMMA ParameterDeclaration  */
#line 107 "uccompiler.y"
                                                            {}
#line 1519 "y.tab.c"
    break;

  case 18: /* ParameterDeclaration: TypeSpec IDENTIFIER  */
#line 111 "uccompiler.y"
                                                            {}
#line 1525 "y.tab.c"
    break;

  case 19: /* ParameterDeclaration: TypeSpec  */
#line 112 "uccompiler.y"
                                                            {}
#line 1531 "y.tab.c"
    break;

  case 20: /* Declaration: TypeSpec Declaration2 SEMI  */
#line 116 "uccompiler.y"
                                                            {}
#line 1537 "y.tab.c"
    break;

  case 21: /* Declaration2: Declarator  */
#line 120 "uccompiler.y"
                                                            {}
#line 1543 "y.tab.c"
    break;

  case 22: /* Declaration2: Declaration2 COMMA Declarator  */
#line 121 "uccompiler.y"
                                                            {}
#line 1549 "y.tab.c"
    break;

  case 23: /* TypeSpec: CHAR  */
#line 125 "uccompiler.y"
                                                            {}
#line 1555 "y.tab.c"
    break;

  case 24: /* TypeSpec: INT  */
#line 126 "uccompiler.y"
                                                            {}
#line 1561 "y.tab.c"
    break;

  case 25: /* TypeSpec: VOID  */
#line 127 "uccompiler.y"
                                                            {}
#line 1567 "y.tab.c"
    break;

  case 26: /* TypeSpec: SHORT  */
#line 128 "uccompiler.y"
                                                            {}
#line 1573 "y.tab.c"
    break;

  case 27: /* TypeSpec: DOUBLE  */
#line 129 "uccompiler.y"
                                                            {}
#line 1579 "y.tab.c"
    break;

  case 28: /* Declarator: IDENTIFIER  */
#line 133 "uccompiler.y"
                                                            {}
#line 1585 "y.tab.c"
    break;

  case 29: /* Declarator: IDENTIFIER ASSIGN Expr  */
#line 134 "uccompiler.y"
                                                            {}
#line 1591 "y.tab.c"
    break;

  case 30: /* Statement: SEMI  */
#line 138 "uccompiler.y"
                                                            {}
#line 1597 "y.tab.c"
    break;

  case 31: /* Statement: Expr SEMI  */
#line 139 "uccompiler.y"
                                                            {}
#line 1603 "y.tab.c"
    break;

  case 32: /* Statement: Statement2 RBRACE  */
#line 140 "uccompiler.y"
                                                            {}
#line 1609 "y.tab.c"
    break;

  case 33: /* Statement: IF LPAR Expr RPAR Statement  */
#line 141 "uccompiler.y"
                                                            {}
#line 1615 "y.tab.c"
    break;

  case 34: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 142 "uccompiler.y"
                                                            {}
#line 1621 "y.tab.c"
    break;

  case 35: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 143 "uccompiler.y"
                                                            {}
#line 1627 "y.tab.c"
    break;

  case 36: /* Statement: RETURN SEMI  */
#line 144 "uccompiler.y"
                                                            {}
#line 1633 "y.tab.c"
    break;

  case 37: /* Statement: RETURN Expr SEMI  */
#line 145 "uccompiler.y"
                                                            {}
#line 1639 "y.tab.c"
    break;

  case 39: /* Statement2: LBRACE Statement2 Statement  */
#line 150 "uccompiler.y"
                                                            {}
#line 1645 "y.tab.c"
    break;

  case 40: /* Expr: Expr ASSIGN Expr  */
#line 154 "uccompiler.y"
                                                            {}
#line 1651 "y.tab.c"
    break;

  case 41: /* Expr: Expr COMMA Expr  */
#line 155 "uccompiler.y"
                                                            {}
#line 1657 "y.tab.c"
    break;

  case 42: /* Expr: Expr PLUS Expr  */
#line 157 "uccompiler.y"
                                                            {}
#line 1663 "y.tab.c"
    break;

  case 43: /* Expr: Expr MINUS Expr  */
#line 158 "uccompiler.y"
                                                            {}
#line 1669 "y.tab.c"
    break;

  case 44: /* Expr: Expr MUL Expr  */
#line 159 "uccompiler.y"
                                                            {}
#line 1675 "y.tab.c"
    break;

  case 45: /* Expr: Expr DIV Expr  */
#line 160 "uccompiler.y"
                                                            {}
#line 1681 "y.tab.c"
    break;

  case 46: /* Expr: Expr MOD Expr  */
#line 161 "uccompiler.y"
                                                            {}
#line 1687 "y.tab.c"
    break;

  case 47: /* Expr: Expr OR Expr  */
#line 163 "uccompiler.y"
                                                            {}
#line 1693 "y.tab.c"
    break;

  case 48: /* Expr: Expr AND Expr  */
#line 164 "uccompiler.y"
                                                            {}
#line 1699 "y.tab.c"
    break;

  case 49: /* Expr: Expr BITWISEAND Expr  */
#line 165 "uccompiler.y"
                                                            {}
#line 1705 "y.tab.c"
    break;

  case 50: /* Expr: Expr BITWISEOR Expr  */
#line 166 "uccompiler.y"
                                                            {}
#line 1711 "y.tab.c"
    break;

  case 51: /* Expr: Expr BITWISEXOR Expr  */
#line 167 "uccompiler.y"
                                                            {}
#line 1717 "y.tab.c"
    break;

  case 52: /* Expr: Expr EQ Expr  */
#line 169 "uccompiler.y"
                                                            {}
#line 1723 "y.tab.c"
    break;

  case 53: /* Expr: Expr NE Expr  */
#line 170 "uccompiler.y"
                                                            {}
#line 1729 "y.tab.c"
    break;

  case 54: /* Expr: Expr LE Expr  */
#line 171 "uccompiler.y"
                                                            {}
#line 1735 "y.tab.c"
    break;

  case 55: /* Expr: Expr GE Expr  */
#line 172 "uccompiler.y"
                                                            {}
#line 1741 "y.tab.c"
    break;

  case 56: /* Expr: Expr LT Expr  */
#line 173 "uccompiler.y"
                                                            {}
#line 1747 "y.tab.c"
    break;

  case 57: /* Expr: Expr GT Expr  */
#line 174 "uccompiler.y"
                                                            {}
#line 1753 "y.tab.c"
    break;

  case 58: /* Expr: PLUS Expr  */
#line 176 "uccompiler.y"
                                                            {}
#line 1759 "y.tab.c"
    break;

  case 59: /* Expr: MINUS Expr2  */
#line 177 "uccompiler.y"
                                                            {}
#line 1765 "y.tab.c"
    break;

  case 60: /* Expr: NOT Expr  */
#line 178 "uccompiler.y"
                                                            {}
#line 1771 "y.tab.c"
    break;

  case 61: /* Expr: IDENTIFIER LPAR RPAR  */
#line 180 "uccompiler.y"
                                                            {}
#line 1777 "y.tab.c"
    break;

  case 62: /* Expr: IDENTIFIER LPAR Expr2 RPAR  */
#line 181 "uccompiler.y"
                                                            {}
#line 1783 "y.tab.c"
    break;

  case 63: /* Expr: IDENTIFIER  */
#line 183 "uccompiler.y"
                                                            {}
#line 1789 "y.tab.c"
    break;

  case 64: /* Expr: NATURAL  */
#line 184 "uccompiler.y"
                                                            {}
#line 1795 "y.tab.c"
    break;

  case 65: /* Expr: CHRLIT  */
#line 185 "uccompiler.y"
                                                            {}
#line 1801 "y.tab.c"
    break;

  case 66: /* Expr: DECIMAL  */
#line 186 "uccompiler.y"
                                                            {}
#line 1807 "y.tab.c"
    break;

  case 67: /* Expr: LPAR Expr RPAR  */
#line 187 "uccompiler.y"
                                                            {}
#line 1813 "y.tab.c"
    break;

  case 68: /* Expr2: Expr  */
#line 191 "uccompiler.y"
                                                            {}
#line 1819 "y.tab.c"
    break;

  case 69: /* Expr2: Expr2 COMMA Expr  */
#line 192 "uccompiler.y"
                                                            {}
#line 1825 "y.tab.c"
    break;


#line 1829 "y.tab.c"
>>>>>>> TiagoCardoso

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

<<<<<<< HEAD
#line 193 "uccompiler.y"


void yyerror(const char* message) {
    fprintf(stderr, "Syntax Error: %s\n", message);
}
=======
#line 195 "uccompiler.y"
>>>>>>> TiagoCardoso
