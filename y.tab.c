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
    int yylex(void);
    extern void yyerror(const char *s);

    #include "tree.h"
    int nr_erro = 0;
    int vazio = 0;
    int conta = 0;
    struct node *raiz;
    struct node *novo;

#line 87 "y.tab.c"

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
    CHAR = 258,                    /* CHAR  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    IF = 261,                      /* IF  */
    INT = 262,                     /* INT  */
    SHORT = 263,                   /* SHORT  */
    DOUBLE = 264,                  /* DOUBLE  */
    RETURN = 265,                  /* RETURN  */
    VOID = 266,                    /* VOID  */
    BITWISEAND = 267,              /* BITWISEAND  */
    BITWISEOR = 268,               /* BITWISEOR  */
    BITWISEXOR = 269,              /* BITWISEXOR  */
    AND = 270,                     /* AND  */
    ASSIGN = 271,                  /* ASSIGN  */
    MUL = 272,                     /* MUL  */
    COMMA = 273,                   /* COMMA  */
    DIV = 274,                     /* DIV  */
    EQ = 275,                      /* EQ  */
    GE = 276,                      /* GE  */
    GT = 277,                      /* GT  */
    LBRACE = 278,                  /* LBRACE  */
    LE = 279,                      /* LE  */
    LPAR = 280,                    /* LPAR  */
    LT = 281,                      /* LT  */
    MINUS = 282,                   /* MINUS  */
    MOD = 283,                     /* MOD  */
    NE = 284,                      /* NE  */
    NOT = 285,                     /* NOT  */
    OR = 286,                      /* OR  */
    PLUS = 287,                    /* PLUS  */
    RBRACE = 288,                  /* RBRACE  */
    RPAR = 289,                    /* RPAR  */
    SEMI = 290,                    /* SEMI  */
    RESERVED = 291,                /* RESERVED  */
    SUB = 292,                     /* SUB  */
    ADD = 293,                     /* ADD  */
    IDENTIFIER = 294,              /* IDENTIFIER  */
    NATURAL = 295,                 /* NATURAL  */
    DECIMAL = 296,                 /* DECIMAL  */
    CHRLIT = 297,                  /* CHRLIT  */
    UNARY = 298                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define DIV 274
#define EQ 275
#define GE 276
#define GT 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define RESERVED 291
#define SUB 292
#define ADD 293
#define IDENTIFIER 294
#define NATURAL 295
#define DECIMAL 296
#define CHRLIT 297
#define UNARY 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "uccompiler.y"

    char *v;
    struct node *no;

#line 231 "y.tab.c"

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
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_SHORT = 8,                      /* SHORT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_BITWISEAND = 12,                /* BITWISEAND  */
  YYSYMBOL_BITWISEOR = 13,                 /* BITWISEOR  */
  YYSYMBOL_BITWISEXOR = 14,                /* BITWISEXOR  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_MUL = 17,                       /* MUL  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_DIV = 19,                       /* DIV  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_GE = 21,                        /* GE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LBRACE = 23,                    /* LBRACE  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_LPAR = 25,                      /* LPAR  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MOD = 28,                       /* MOD  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_RBRACE = 33,                    /* RBRACE  */
  YYSYMBOL_RPAR = 34,                      /* RPAR  */
  YYSYMBOL_SEMI = 35,                      /* SEMI  */
  YYSYMBOL_RESERVED = 36,                  /* RESERVED  */
  YYSYMBOL_SUB = 37,                       /* SUB  */
  YYSYMBOL_ADD = 38,                       /* ADD  */
  YYSYMBOL_IDENTIFIER = 39,                /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 40,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 41,                   /* DECIMAL  */
  YYSYMBOL_CHRLIT = 42,                    /* CHRLIT  */
  YYSYMBOL_UNARY = 43,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_Program = 45,                   /* Program  */
  YYSYMBOL_FunctionsAndDeclarations = 46,  /* FunctionsAndDeclarations  */
  YYSYMBOL_FunctionsAndDeclarations2 = 47, /* FunctionsAndDeclarations2  */
  YYSYMBOL_FunctionDefinition = 48,        /* FunctionDefinition  */
  YYSYMBOL_FunctionBody = 49,              /* FunctionBody  */
  YYSYMBOL_DeclarationsAndStatements = 50, /* DeclarationsAndStatements  */
  YYSYMBOL_FunctionDeclaration = 51,       /* FunctionDeclaration  */
  YYSYMBOL_FunctionDeclarator = 52,        /* FunctionDeclarator  */
  YYSYMBOL_ParameterList = 53,             /* ParameterList  */
  YYSYMBOL_ParameterList2 = 54,            /* ParameterList2  */
  YYSYMBOL_ParameterDeclaration = 55,      /* ParameterDeclaration  */
  YYSYMBOL_Declaration = 56,               /* Declaration  */
  YYSYMBOL_Declaration2 = 57,              /* Declaration2  */
  YYSYMBOL_TypeSpec = 58,                  /* TypeSpec  */
  YYSYMBOL_Declarator = 59,                /* Declarator  */
  YYSYMBOL_StatementsERROR = 60,           /* StatementsERROR  */
  YYSYMBOL_StatementERROR = 61,            /* StatementERROR  */
  YYSYMBOL_Statement2 = 62,                /* Statement2  */
  YYSYMBOL_Statement3 = 63,                /* Statement3  */
  YYSYMBOL_Expr = 64,                      /* Expr  */
  YYSYMBOL_Expr2 = 65,                     /* Expr2  */
  YYSYMBOL_Expr3 = 66                      /* Expr3  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   103,   110,   114,   118,   124,   127,   131,
     135,   142,   152,   155,   165,   175,   179,   182,   188,   199,
     208,   221,   224,   233,   239,   249,   253,   257,   258,   275,
     278,   281,   284,   287,   293,   297,   305,   308,   312,   316,
     330,   347,   359,   367,   373,   377,   382,   386,   389,   402,
     417,   430,   437,   444,   445,   448,   451,   465,   469,   476,
     484,   491,   498,   505,   512,   520,   527,   534,   541,   548,
     556,   563,   570,   577,   584,   592,   600,   606,   611,   618,
     627,   633,   638,   643,   648,   653,   659,   660,   665,   666,
     679,   680
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
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "ELSE",
  "WHILE", "IF", "INT", "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND",
  "BITWISEOR", "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "DIV", "EQ",
  "GE", "GT", "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT",
  "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "RESERVED", "SUB", "ADD",
  "IDENTIFIER", "NATURAL", "DECIMAL", "CHRLIT", "UNARY", "$accept",
  "Program", "FunctionsAndDeclarations", "FunctionsAndDeclarations2",
  "FunctionDefinition", "FunctionBody", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterList2", "ParameterDeclaration", "Declaration", "Declaration2",
  "TypeSpec", "Declarator", "StatementsERROR", "StatementERROR",
  "Statement2", "Statement3", "Expr", "Expr2", "Expr3", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-47)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-56)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     277,   -21,   -47,   -47,   -47,   -47,   -47,    16,   -47,   151,
     151,   151,   -19,   -47,   -47,   -21,   -47,   151,   151,   151,
     -47,   -47,    -1,   -18,   -14,   -47,   -47,   -47,   -47,   449,
     511,    85,   -47,   -47,    18,   -47,    28,   449,   449,   449,
      34,   -47,   -47,   -47,   360,   -47,   -16,    54,    35,    51,
      59,   427,   222,   -47,   -47,    56,   138,    18,   180,   -12,
      62,   -47,    65,    -9,   -47,   -47,   147,   199,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   -47,   511,   -47,   -47,
     449,   449,   -47,    -7,    68,   329,    71,   -47,   -47,   -47,
     -47,   -47,   -47,    69,   -47,   360,   475,   421,   298,   402,
     360,    70,   104,   489,   165,   165,   165,   165,   -47,    78,
     489,   381,   147,   360,    54,    45,    46,   -47,   -47,   329,
     -47,   -47,   -47,    47,   -47,   306,   306,   -47,   449,   -47,
      74,    86,    88,   445,   264,   -47,   -47,    -5,   112,   360,
     -47,   449,   449,   -47,    38,    95,    97,   -47,   306,    48,
      53,   -47,   -47,   -47,   -47,   306,   306,   -47,   115,   306,
     -47
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     2,    29,    30,    32,    33,    31,     0,     3,     0,
       0,     0,     0,    26,     1,     0,     4,     0,     0,     0,
       5,     6,    34,     0,     0,    27,     8,     9,    10,     0,
       0,     0,    18,    11,     0,    25,     0,     0,     0,     0,
      81,    82,    84,    83,    88,    35,     0,    21,    23,     0,
       0,     0,     0,    12,    36,     0,     0,     0,     0,     0,
      34,    28,     0,     0,    77,    78,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,    20,    24,
       0,     0,    43,     0,     0,    57,     0,    13,    15,    14,
      37,    87,    85,     0,    80,    90,    67,    68,    69,    66,
      59,    62,    63,    70,    73,    75,    72,    74,    61,    64,
      71,    65,    60,    89,    21,     0,     0,    42,    44,    57,
      56,    38,    86,     0,    22,     0,     0,    58,     0,    79,
       0,     0,     0,     0,     0,    45,    41,     0,    40,    91,
      54,     0,     0,    52,     0,     0,     0,    46,     0,     0,
       0,    51,    53,    47,    39,     0,     0,    50,    49,     0,
      48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -47,   -47,   -47,   225,   133,   -47,   -46,   134,   -47,   -47,
      11,    55,    19,   -47,    -4,   116,   -44,   110,    -6,    24,
     -36,   -29,   -47
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,    16,    17,    33,    55,    18,    23,    46,
      88,    47,    19,    24,    12,    25,    58,   146,    96,   130,
      44,    59,   133
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    64,    65,    66,    34,    31,    85,    63,    95,    85,
      98,    85,    99,    85,    13,    29,    14,    32,    86,    11,
      22,    35,    93,   100,    30,   102,    48,    57,   127,    62,
     157,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      56,   129,    57,    36,    57,    37,    85,    60,    38,    67,
      39,   125,   126,    85,    85,   138,    85,    40,    41,    42,
      43,    85,    87,   161,    89,    56,    90,    56,    29,   135,
     136,   139,   165,    48,    91,   129,    15,   166,     2,    97,
      49,    50,     3,     4,     5,    51,     6,    80,    81,   101,
      95,   128,   149,   132,   131,    80,   147,   147,    52,   150,
      36,   151,    37,   152,   154,    38,   158,    39,    53,   169,
      54,    73,   159,   160,    40,    41,    42,    43,   162,   147,
     163,    80,    81,     9,    10,   134,   147,   147,   156,    15,
     147,     2,   124,    49,    50,     3,     4,     5,    51,     6,
      61,    -7,    15,   137,     2,     0,     0,     0,     3,     4,
       5,    52,     6,    36,    73,    37,    74,     0,    38,     0,
      39,   -17,     0,    54,    80,    81,     0,    40,    41,    42,
      43,    15,    73,     2,    74,    49,    50,     3,     4,     5,
      51,     6,    80,    81,     0,     0,     0,    84,     0,     0,
     103,     0,     0,    52,     0,    36,     0,    37,     0,     0,
      38,     0,    39,   -16,     0,    54,     0,     0,     0,    40,
      41,    42,    43,    94,    36,     0,    37,    49,    50,    38,
       0,    39,    51,   104,     0,    20,    21,     0,    40,    41,
      42,    43,    26,    27,    28,    52,   148,    36,     0,    37,
       0,     0,    38,     0,    39,   -55,     0,    54,     0,     0,
       0,    40,    41,    42,    43,   155,     0,     0,   164,    49,
      50,     0,     0,     0,    51,   167,   168,     0,     1,   170,
       2,     0,     0,     0,     3,     4,     5,    52,     6,    36,
       0,    37,     0,     0,    38,     0,    39,   -55,     0,    54,
       0,     0,     0,    40,    41,    42,    43,   140,     0,     0,
      68,   141,   142,     0,     0,    73,   143,    74,    75,    76,
      77,     0,    78,     0,    79,    80,    81,    82,     0,   144,
      84,    36,     0,    37,    49,    50,    38,     0,    39,    51,
       0,   145,     0,     0,     0,    40,    41,    42,    43,     0,
       0,     0,    52,     0,    36,     0,    37,     0,     0,    38,
       0,    39,     0,     0,    54,     0,     0,     0,    40,    41,
      42,    43,    68,    69,    70,    71,    72,    73,     0,    74,
      75,    76,    77,     0,    78,     0,    79,    80,    81,    82,
       0,    83,    84,    68,    69,    70,    71,     0,    73,     0,
      74,    75,    76,    77,     0,    78,     0,    79,    80,    81,
      82,     0,     0,    84,    68,    69,    70,     0,     0,    73,
       0,    74,    75,    76,    77,     0,    78,     0,    79,    80,
      81,    82,     0,    68,    84,    70,     0,     0,    73,     0,
      74,    75,    76,    77,     0,    78,     0,    79,    80,    81,
      82,     0,    36,    84,    37,     0,     0,    38,     0,    39,
       0,     0,    92,     0,     0,     0,    40,    41,    42,    43,
      36,     0,    37,     0,    36,    38,    37,    39,     0,    38,
     153,    39,     0,     0,    40,    41,    42,    43,    40,    41,
      42,    43,    73,     0,    74,    75,    76,    77,     0,    78,
       0,    79,    80,    81,    82,     0,    73,    84,    74,     0,
      76,    77,     0,    78,     2,    79,    80,    81,     3,     4,
       5,    84,     6
};

static const yytype_int16 yycheck[] =
{
      29,    37,    38,    39,    18,    23,    18,    36,    52,    18,
      56,    18,    58,    18,    35,    16,     0,    35,    34,     0,
      39,    35,    51,    35,    25,    34,    30,    31,    35,     1,
      35,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      31,    95,    56,    25,    58,    27,    18,    39,    30,    25,
      32,    90,    91,    18,    18,    18,    18,    39,    40,    41,
      42,    18,    18,    35,    39,    56,    25,    58,    16,    34,
      34,    34,    34,    87,    25,   129,     1,    34,     3,    33,
       5,     6,     7,     8,     9,    10,    11,    27,    28,    34,
     144,    33,   138,    34,    33,    27,   135,   136,    23,    35,
      25,    25,    27,    25,   143,    30,     4,    32,    33,     4,
      35,    17,   151,   152,    39,    40,    41,    42,    33,   158,
      33,    27,    28,     0,     0,   124,   165,   166,   144,     1,
     169,     3,    87,     5,     6,     7,     8,     9,    10,    11,
      34,     0,     1,   129,     3,    -1,    -1,    -1,     7,     8,
       9,    23,    11,    25,    17,    27,    19,    -1,    30,    -1,
      32,    33,    -1,    35,    27,    28,    -1,    39,    40,    41,
      42,     1,    17,     3,    19,     5,     6,     7,     8,     9,
      10,    11,    27,    28,    -1,    -1,    -1,    32,    -1,    -1,
       1,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,
      30,    -1,    32,    33,    -1,    35,    -1,    -1,    -1,    39,
      40,    41,    42,     1,    25,    -1,    27,     5,     6,    30,
      -1,    32,    10,    34,    -1,    10,    11,    -1,    39,    40,
      41,    42,    17,    18,    19,    23,   136,    25,    -1,    27,
      -1,    -1,    30,    -1,    32,    33,    -1,    35,    -1,    -1,
      -1,    39,    40,    41,    42,     1,    -1,    -1,   158,     5,
       6,    -1,    -1,    -1,    10,   165,   166,    -1,     1,   169,
       3,    -1,    -1,    -1,     7,     8,     9,    23,    11,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,
      -1,    -1,    -1,    39,    40,    41,    42,     1,    -1,    -1,
      12,     5,     6,    -1,    -1,    17,    10,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    23,
      32,    25,    -1,    27,     5,     6,    30,    -1,    32,    10,
      -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    23,    -1,    25,    -1,    27,    -1,    -1,    30,
      -1,    32,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,
      41,    42,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    12,    13,    14,    15,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    -1,    32,    12,    13,    14,    -1,    -1,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    12,    32,    14,    -1,    -1,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    25,    32,    27,    -1,    -1,    30,    -1,    32,
      -1,    -1,    35,    -1,    -1,    -1,    39,    40,    41,    42,
      25,    -1,    27,    -1,    25,    30,    27,    32,    -1,    30,
      35,    32,    -1,    -1,    39,    40,    41,    42,    39,    40,
      41,    42,    17,    -1,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    17,    32,    19,    -1,
      21,    22,    -1,    24,     3,    26,    27,    28,     7,     8,
       9,    32,    11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    45,    46,    48,
      51,    56,    58,    35,     0,     1,    47,    48,    51,    56,
      47,    47,    39,    52,    57,    59,    47,    47,    47,    16,
      25,    23,    35,    49,    18,    35,    25,    27,    30,    32,
      39,    40,    41,    42,    64,    65,    53,    55,    58,     5,
       6,    10,    23,    33,    35,    50,    56,    58,    60,    65,
      39,    59,     1,    65,    64,    64,    64,    25,    12,    13,
      14,    15,    16,    17,    19,    20,    21,    22,    24,    26,
      27,    28,    29,    31,    32,    18,    34,    18,    54,    39,
      25,    25,    35,    65,     1,    60,    62,    33,    50,    50,
      35,    34,    34,     1,    34,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    55,    65,    65,    35,    33,    60,
      63,    33,    34,    66,    54,    34,    34,    63,    18,    34,
       1,     5,     6,    10,    23,    35,    61,    65,    61,    64,
      35,    25,    25,    35,    65,     1,    62,    35,     4,    65,
      65,    35,    33,    33,    61,    34,    34,    61,    61,     4,
      61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    47,    47,    47,
      47,    48,    49,    49,    50,    50,    50,    50,    51,    52,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     0,     2,     2,
       2,     3,     2,     3,     2,     2,     1,     1,     3,     4,
       2,     0,     3,     1,     2,     3,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     2,     3,     7,
       5,     5,     3,     2,     3,     1,     2,     3,     7,     5,
       5,     3,     2,     3,     2,     0,     2,     0,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     5,
       3,     1,     1,     1,     1,     3,     4,     3,     1,     3,
       0,     3
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
  case 2: /* Program: error  */
#line 102 "uccompiler.y"
                                                            {   nr_erro = 1;}
#line 1462 "y.tab.c"
    break;

  case 3: /* Program: FunctionsAndDeclarations  */
#line 103 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = raiz = criar_no(no_raiz,"Program",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                            }
#line 1471 "y.tab.c"
    break;

  case 4: /* FunctionsAndDeclarations: FunctionDefinition FunctionsAndDeclarations2  */
#line 110 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                adicionar_irmao((yyvsp[-1].no),(yyvsp[0].no));
                                                            }
#line 1480 "y.tab.c"
    break;

  case 5: /* FunctionsAndDeclarations: FunctionDeclaration FunctionsAndDeclarations2  */
#line 114 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                adicionar_irmao((yyvsp[-1].no),(yyvsp[0].no));
                                                            }
#line 1489 "y.tab.c"
    break;

  case 6: /* FunctionsAndDeclarations: Declaration FunctionsAndDeclarations2  */
#line 118 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                adicionar_irmao((yyvsp[-1].no),(yyvsp[0].no));
                                                            }
#line 1498 "y.tab.c"
    break;

  case 7: /* FunctionsAndDeclarations2: %empty  */
#line 124 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = NULL;
                                                            }
#line 1506 "y.tab.c"
    break;

  case 8: /* FunctionsAndDeclarations2: FunctionDefinition FunctionsAndDeclarations2  */
#line 127 "uccompiler.y"
                                                            {   
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                                
                                                            }
#line 1515 "y.tab.c"
    break;

  case 9: /* FunctionsAndDeclarations2: FunctionDeclaration FunctionsAndDeclarations2  */
#line 131 "uccompiler.y"
                                                            {
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                                
                                                            }
#line 1524 "y.tab.c"
    break;

  case 10: /* FunctionsAndDeclarations2: Declaration FunctionsAndDeclarations2  */
#line 135 "uccompiler.y"
                                                            {
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                                
                                                            }
#line 1533 "y.tab.c"
    break;

  case 11: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 142 "uccompiler.y"
                                                            {   
                                                                
                                                                (yyval.no) = criar_no(no_funcoes,"FuncDefinition",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                            }
#line 1545 "y.tab.c"
    break;

  case 12: /* FunctionBody: LBRACE RBRACE  */
#line 152 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_funcoes,"FuncBody",NULL);
                                                            }
#line 1553 "y.tab.c"
    break;

  case 13: /* FunctionBody: LBRACE DeclarationsAndStatements RBRACE  */
#line 155 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_funcoes,"FuncBody",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                
                                                                
                                                            }
#line 1565 "y.tab.c"
    break;

  case 14: /* DeclarationsAndStatements: StatementsERROR DeclarationsAndStatements  */
#line 165 "uccompiler.y"
                                                            { 
                                                                
                                                                if((yyvsp[-1].no) == NULL){
                                                                    (yyval.no) = (yyvsp[0].no);
                                                                } else {
                                                                    (yyval.no) = (yyvsp[-1].no);
                                                                    adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                                }
                                                                
                                                            }
#line 1580 "y.tab.c"
    break;

  case 15: /* DeclarationsAndStatements: Declaration DeclarationsAndStatements  */
#line 175 "uccompiler.y"
                                                            {
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                            }
#line 1589 "y.tab.c"
    break;

  case 16: /* DeclarationsAndStatements: StatementsERROR  */
#line 179 "uccompiler.y"
                                                            {
                                                                (yyval.no) = (yyvsp[0].no);
                                                            }
#line 1597 "y.tab.c"
    break;

  case 17: /* DeclarationsAndStatements: Declaration  */
#line 182 "uccompiler.y"
                                                            {
                                                                (yyval.no) = (yyvsp[0].no);
                                                            }
#line 1605 "y.tab.c"
    break;

  case 18: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 188 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_funcoes,"FuncDeclaration",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                

                                                            }
#line 1618 "y.tab.c"
    break;

  case 19: /* FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR  */
#line 199 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_terminais,"Identifier",(yyvsp[-3].v));
                                                                adicionar_irmao((yyval.no),(yyvsp[-1].no));
                                                                
                                                            }
#line 1629 "y.tab.c"
    break;

  case 20: /* ParameterList: ParameterDeclaration ParameterList2  */
#line 208 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_funcoes,"ParamList",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                
                                                                if ((yyvsp[0].no) != NULL){
                                                                    adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                }
                                                                
                                                                
                                                            }
#line 1645 "y.tab.c"
    break;

  case 21: /* ParameterList2: %empty  */
#line 221 "uccompiler.y"
                                                            {   (yyval.no) = NULL;
                                                                
                                                            }
#line 1653 "y.tab.c"
    break;

  case 22: /* ParameterList2: COMMA ParameterDeclaration ParameterList2  */
#line 224 "uccompiler.y"
                                                            {
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                if((yyvsp[0].no) != NULL){
                                                                    adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                                }
                                                            }
#line 1664 "y.tab.c"
    break;

  case 23: /* ParameterDeclaration: TypeSpec  */
#line 233 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_funcoes,"ParamDeclaration",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                
                                                            }
#line 1675 "y.tab.c"
    break;

  case 24: /* ParameterDeclaration: TypeSpec IDENTIFIER  */
#line 239 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_funcoes,"ParamDeclaration",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                adicionar_filho((yyval.no),criar_no(no_terminais,"Identifier",(yyvsp[0].v)));
                                                                
                                                            }
#line 1687 "y.tab.c"
    break;

  case 25: /* Declaration: TypeSpec Declaration2 SEMI  */
#line 249 "uccompiler.y"
                                                            {  
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                adiciona_primeiro((yyval.no),(yyvsp[-2].no));
                                                            }
#line 1696 "y.tab.c"
    break;

  case 26: /* Declaration: error SEMI  */
#line 253 "uccompiler.y"
                                                            {  (yyval.no) = NULL; nr_erro = 1;}
#line 1702 "y.tab.c"
    break;

  case 27: /* Declaration2: Declarator  */
#line 257 "uccompiler.y"
                                                            {  (yyval.no) = (yyvsp[0].no);}
#line 1708 "y.tab.c"
    break;

  case 28: /* Declaration2: Declaration2 COMMA Declarator  */
#line 258 "uccompiler.y"
                                                            {
                                                                
                                                                if ((yyvsp[-2].no) != NULL){
                                                                    (yyval.no) = (yyvsp[-2].no);
                                                                    adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                                } else {
                                                                    (yyval.no) = (yyvsp[0].no);
                                                                }
                                                                
                                                                
                                                            
                                                                
                                                                
                                                            }
#line 1727 "y.tab.c"
    break;

  case 29: /* TypeSpec: CHAR  */
#line 275 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Char",NULL);
                                                            }
#line 1735 "y.tab.c"
    break;

  case 30: /* TypeSpec: INT  */
#line 278 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Int",NULL);
                                                            }
#line 1743 "y.tab.c"
    break;

  case 31: /* TypeSpec: VOID  */
#line 281 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Void",NULL);
                                                            }
#line 1751 "y.tab.c"
    break;

  case 32: /* TypeSpec: SHORT  */
#line 284 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Short",NULL);
                                                            }
#line 1759 "y.tab.c"
    break;

  case 33: /* TypeSpec: DOUBLE  */
#line 287 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Double",NULL);
                                                            }
#line 1767 "y.tab.c"
    break;

  case 34: /* Declarator: IDENTIFIER  */
#line 293 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_declaracao,"Declaration",NULL);
                                                                adicionar_filho((yyval.no),criar_no(no_terminais,"Identifier",(yyvsp[0].v)));
                                                            }
#line 1776 "y.tab.c"
    break;

  case 35: /* Declarator: IDENTIFIER ASSIGN Expr2  */
#line 297 "uccompiler.y"
                                                             {
                                                                (yyval.no) = criar_no(no_declaracao,"Declaration",NULL);
                                                                adicionar_filho((yyval.no),criar_no(no_terminais,"Identifier",(yyvsp[-2].v)));
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                            }
#line 1786 "y.tab.c"
    break;

  case 36: /* StatementsERROR: SEMI  */
#line 305 "uccompiler.y"
                                                            {
                                                                (yyval.no) = NULL;
                                                            }
#line 1794 "y.tab.c"
    break;

  case 37: /* StatementsERROR: Expr2 SEMI  */
#line 308 "uccompiler.y"
                                                             {
                                                                (yyval.no) = (yyvsp[-1].no);
                                                            }
#line 1802 "y.tab.c"
    break;

  case 38: /* StatementsERROR: LBRACE Statement2 RBRACE  */
#line 312 "uccompiler.y"
                                                            {
                                                                (yyval.no) = (yyvsp[-1].no);
                                                            }
#line 1810 "y.tab.c"
    break;

  case 39: /* StatementsERROR: IF LPAR Expr2 RPAR StatementERROR ELSE StatementERROR  */
#line 316 "uccompiler.y"
                                                             {
                                                                (yyval.no) = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-4].no));
                                                                
                                                                
                                                                if ((yyvsp[-2].no) != NULL && (yyvsp[0].no) != NULL){
                                                                    adicionar_filho((yyval.no), (yyvsp[-2].no));
                                                                    adicionar_filho((yyval.no), (yyvsp[0].no));
                                                                } else if ((yyvsp[-2].no) == NULL) {
                                                                        adicionar_filho((yyval.no), criar_no(no_especial, "Null", NULL));
                                                                        adicionar_filho((yyval.no), (yyvsp[0].no));
                                                                }
                                                                
                                                            }
#line 1829 "y.tab.c"
    break;

  case 40: /* StatementsERROR: IF LPAR Expr2 RPAR StatementERROR  */
#line 330 "uccompiler.y"
                                                             {
                                                                
                                                                (yyval.no) = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                
                                                                if((yyvsp[0].no)==NULL){
                                                                        adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                        adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                    adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                }
                                                                
                                                                
                                                                
                                                            }
#line 1850 "y.tab.c"
    break;

  case 41: /* StatementsERROR: WHILE LPAR Expr2 RPAR StatementERROR  */
#line 347 "uccompiler.y"
                                                             {
                                                                
                                                                (yyval.no) = criar_no(no_statments,"While",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                
                                                                if ((yyvsp[0].no) == NULL){
                                                                    adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                }
                                                            }
#line 1866 "y.tab.c"
    break;

  case 42: /* StatementsERROR: RETURN Expr2 SEMI  */
#line 359 "uccompiler.y"
                                                             {
                                                                
                                                                
                                                                (yyval.no) = criar_no(no_statments,"Return",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                
                                                                vazio = 1;
                                                            }
#line 1879 "y.tab.c"
    break;

  case 43: /* StatementsERROR: RETURN SEMI  */
#line 367 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_statments,"Return",NULL);
                                                                novo = criar_no(no_especial, "Null",NULL);
                                                                adicionar_filho((yyval.no),novo); 
                                                            }
#line 1889 "y.tab.c"
    break;

  case 44: /* StatementsERROR: LBRACE error RBRACE  */
#line 373 "uccompiler.y"
                                                            {   (yyval.no) = NULL; nr_erro = 1;}
#line 1895 "y.tab.c"
    break;

  case 45: /* StatementERROR: SEMI  */
#line 377 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_especial,"Null",NULL);
                                                                
                                                            }
#line 1905 "y.tab.c"
    break;

  case 46: /* StatementERROR: Expr2 SEMI  */
#line 382 "uccompiler.y"
                                                             {
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                vazio = 1;
                                                            }
#line 1914 "y.tab.c"
    break;

  case 47: /* StatementERROR: LBRACE Statement2 RBRACE  */
#line 386 "uccompiler.y"
                                                            {
                                                                (yyval.no) = (yyvsp[-1].no);
                                                            }
#line 1922 "y.tab.c"
    break;

  case 48: /* StatementERROR: IF LPAR Expr2 RPAR StatementERROR ELSE StatementERROR  */
#line 389 "uccompiler.y"
                                                             {
                                                                (yyval.no) = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-4].no));
                                                                
                                                                
                                                                if ((yyvsp[-2].no) != NULL && (yyvsp[0].no) != NULL){
                                                                    adicionar_filho((yyval.no), (yyvsp[-2].no));
                                                                    adicionar_filho((yyval.no), (yyvsp[0].no));
                                                                } else if ((yyvsp[-2].no) == NULL) {
                                                                        adicionar_filho((yyval.no), criar_no(no_especial, "Null", NULL));
                                                                        adicionar_filho((yyval.no), (yyvsp[0].no));
                                                                }
                                                            }
#line 1940 "y.tab.c"
    break;

  case 49: /* StatementERROR: IF LPAR Expr2 RPAR StatementERROR  */
#line 402 "uccompiler.y"
                                                             {
                                                                
                                                                (yyval.no) = criar_no(no_statments,"If",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                
                                                                if((yyvsp[0].no)==NULL){
                                                                        adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                        adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                    adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                }
                                                                
                                                            }
#line 1959 "y.tab.c"
    break;

  case 50: /* StatementERROR: WHILE LPAR Expr2 RPAR StatementERROR  */
#line 417 "uccompiler.y"
                                                             {
                                                                
                                                                (yyval.no) = criar_no(no_statments,"While",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                
                                                                if ((yyvsp[0].no) == NULL){
                                                                    adicionar_filho((yyval.no),criar_no(no_especial,"Null",NULL));
                                                                } else {
                                                                    adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                }
                                                                

                                                            }
#line 1977 "y.tab.c"
    break;

  case 51: /* StatementERROR: RETURN Expr2 SEMI  */
#line 430 "uccompiler.y"
                                                             {
                                                                
                                                                (yyval.no) = criar_no(no_statments,"Return",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                vazio = 1;
                                                                
                                                            }
#line 1989 "y.tab.c"
    break;

  case 52: /* StatementERROR: RETURN SEMI  */
#line 437 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_statments,"Return",NULL);
                                                                novo = criar_no(no_especial, "Null",NULL);
                                                                adicionar_filho((yyval.no),novo);
                                                            }
#line 1999 "y.tab.c"
    break;

  case 53: /* StatementERROR: LBRACE error RBRACE  */
#line 444 "uccompiler.y"
                                                            {  (yyval.no) = NULL;nr_erro = 1;}
#line 2005 "y.tab.c"
    break;

  case 54: /* StatementERROR: error SEMI  */
#line 445 "uccompiler.y"
                                                            {  (yyval.no) = NULL;nr_erro = 1;}
#line 2011 "y.tab.c"
    break;

  case 55: /* Statement2: %empty  */
#line 448 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = NULL;
                                                            }
#line 2019 "y.tab.c"
    break;

  case 56: /* Statement2: StatementsERROR Statement3  */
#line 451 "uccompiler.y"
                                                             {
                                                                
                                                                if ((yyvsp[0].no) != NULL){
                                                                    (yyval.no) = criar_no(no_statments,"StatList",NULL);
                                                                    adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                    adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                
                                                                } else {
                                                                    (yyval.no) = (yyvsp[-1].no);
                                                                }
                                                                
                                                            }
#line 2036 "y.tab.c"
    break;

  case 57: /* Statement3: %empty  */
#line 465 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = NULL;
                                                            }
#line 2044 "y.tab.c"
    break;

  case 58: /* Statement3: StatementsERROR Statement3  */
#line 469 "uccompiler.y"
                                                              {
                                                                    (yyval.no) = (yyvsp[-1].no);
                                                                    adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                                
                                                            }
#line 2054 "y.tab.c"
    break;

  case 59: /* Expr: Expr ASSIGN Expr  */
#line 476 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Store",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2066 "y.tab.c"
    break;

  case 60: /* Expr: Expr PLUS Expr  */
#line 484 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Add",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2078 "y.tab.c"
    break;

  case 61: /* Expr: Expr MINUS Expr  */
#line 491 "uccompiler.y"
                                                            {   
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Sub",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2090 "y.tab.c"
    break;

  case 62: /* Expr: Expr MUL Expr  */
#line 498 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Mul",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2102 "y.tab.c"
    break;

  case 63: /* Expr: Expr DIV Expr  */
#line 505 "uccompiler.y"
                                                            {   
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Div",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2114 "y.tab.c"
    break;

  case 64: /* Expr: Expr MOD Expr  */
#line 512 "uccompiler.y"
                                                            {   
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Mod",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2126 "y.tab.c"
    break;

  case 65: /* Expr: Expr OR Expr  */
#line 520 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Or",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2138 "y.tab.c"
    break;

  case 66: /* Expr: Expr AND Expr  */
#line 527 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"And",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2150 "y.tab.c"
    break;

  case 67: /* Expr: Expr BITWISEAND Expr  */
#line 534 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"BitWiseAnd",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2162 "y.tab.c"
    break;

  case 68: /* Expr: Expr BITWISEOR Expr  */
#line 541 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"BitWiseOr",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2174 "y.tab.c"
    break;

  case 69: /* Expr: Expr BITWISEXOR Expr  */
#line 548 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"BitWiseXor",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2186 "y.tab.c"
    break;

  case 70: /* Expr: Expr EQ Expr  */
#line 556 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Eq",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2198 "y.tab.c"
    break;

  case 71: /* Expr: Expr NE Expr  */
#line 563 "uccompiler.y"
                                                            {   
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Ne",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2210 "y.tab.c"
    break;

  case 72: /* Expr: Expr LE Expr  */
#line 570 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Le",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2222 "y.tab.c"
    break;

  case 73: /* Expr: Expr GE Expr  */
#line 577 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Ge",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2234 "y.tab.c"
    break;

  case 74: /* Expr: Expr LT Expr  */
#line 584 "uccompiler.y"
                                                            {
                                                                
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Lt",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2247 "y.tab.c"
    break;

  case 75: /* Expr: Expr GT Expr  */
#line 592 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Gt",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                                                                
                                                            }
#line 2259 "y.tab.c"
    break;

  case 76: /* Expr: PLUS Expr  */
#line 600 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Plus",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                
                                                            }
#line 2270 "y.tab.c"
    break;

  case 77: /* Expr: MINUS Expr  */
#line 606 "uccompiler.y"
                                                            {   
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Minus",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                            }
#line 2280 "y.tab.c"
    break;

  case 78: /* Expr: NOT Expr  */
#line 611 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Not",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                                
                                                            }
#line 2291 "y.tab.c"
    break;

  case 79: /* Expr: IDENTIFIER LPAR Expr Expr3 RPAR  */
#line 618 "uccompiler.y"
                                                                  {
                                                                
                                                                (yyval.no) = criar_no(no_operadores,"Call",NULL);
                                                                novo = criar_no(no_terminais,"Identifier",(yyvsp[-4].v));
                                                                adicionar_filho((yyval.no),novo);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                
                                                            }
#line 2305 "y.tab.c"
    break;

  case 80: /* Expr: IDENTIFIER LPAR RPAR  */
#line 627 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_operadores,"Call",NULL);
                                                                novo = criar_no(no_terminais,"Identifier",(yyvsp[-2].v));
                                                                adicionar_filho((yyval.no),novo);
                                                            }
#line 2315 "y.tab.c"
    break;

  case 81: /* Expr: IDENTIFIER  */
#line 633 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_terminais,"Identifier",(yyvsp[0].v));
                                                                
                                                            }
#line 2325 "y.tab.c"
    break;

  case 82: /* Expr: NATURAL  */
#line 638 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_terminais,"Natural",(yyvsp[0].v));
                                                                
                                                            }
#line 2335 "y.tab.c"
    break;

  case 83: /* Expr: CHRLIT  */
#line 643 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_terminais,"ChrLit",(yyvsp[0].v));
                                                                
                                                            }
#line 2345 "y.tab.c"
    break;

  case 84: /* Expr: DECIMAL  */
#line 648 "uccompiler.y"
                                                            {
                                                                
                                                                (yyval.no) = criar_no(no_terminais,"Decimal",(yyvsp[0].v));
                                                                
                                                            }
#line 2355 "y.tab.c"
    break;

  case 85: /* Expr: LPAR Expr2 RPAR  */
#line 653 "uccompiler.y"
                                                             {
                                                                
                                                                (yyval.no) = (yyvsp[-1].no);
                                                                
                                                            }
#line 2365 "y.tab.c"
    break;

  case 86: /* Expr: IDENTIFIER LPAR error RPAR  */
#line 659 "uccompiler.y"
                                                            {   (yyval.no) = NULL; nr_erro = 1;}
#line 2371 "y.tab.c"
    break;

  case 87: /* Expr: LPAR error RPAR  */
#line 660 "uccompiler.y"
                                                            {   (yyval.no) = NULL; nr_erro = 1;}
#line 2377 "y.tab.c"
    break;

  case 88: /* Expr2: Expr  */
#line 665 "uccompiler.y"
         {(yyval.no) = (yyvsp[0].no);}
#line 2383 "y.tab.c"
    break;

  case 89: /* Expr2: Expr2 COMMA Expr  */
#line 666 "uccompiler.y"
                       {    if((yyvsp[-2].no) != NULL){
                                (yyval.no) = criar_no(no_operadores,"Comma",NULL);
                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                adicionar_irmao((yyvsp[-2].no),(yyvsp[0].no));
                            } else {
                                (yyval.no) = (yyvsp[0].no);
                                
                                
                            }
                        }
#line 2398 "y.tab.c"
    break;

  case 90: /* Expr3: %empty  */
#line 679 "uccompiler.y"
    {(yyval.no) = NULL;}
#line 2404 "y.tab.c"
    break;

  case 91: /* Expr3: Expr3 COMMA Expr  */
#line 680 "uccompiler.y"
                        {
                            if((yyvsp[-2].no) != NULL){
                                (yyval.no) = (yyvsp[-2].no);
                                
                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                        }else {
                                (yyval.no) = (yyvsp[0].no);
                                
                                
                            }
                    
    }
#line 2421 "y.tab.c"
    break;


#line 2425 "y.tab.c"

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

#line 692 "uccompiler.y"

