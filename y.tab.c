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
#line 2 "uccompiler.y"

/*
Henrique José Correia Brás - 2021229812
Tiago Rafael Cardoso Santos - 2021229679
*/
    
    

    int yylex(void);
    extern void yyerror(const char *s);

    #include "tree.h"
    int nr_erro = 0;
    int teste = 1;
    struct node *raiz;
    struct node *novo;

#line 89 "y.tab.c"

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
    IDENTIFIER = 292,              /* IDENTIFIER  */
    NATURAL = 293,                 /* NATURAL  */
    DECIMAL = 294,                 /* DECIMAL  */
    CHRLIT = 295,                  /* CHRLIT  */
    UNARY = 296                    /* UNARY  */
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
#define IDENTIFIER 292
#define NATURAL 293
#define DECIMAL 294
#define CHRLIT 295
#define UNARY 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "uccompiler.y"

    char *v;
    struct node *no;

#line 229 "y.tab.c"

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
  YYSYMBOL_IDENTIFIER = 37,                /* IDENTIFIER  */
  YYSYMBOL_NATURAL = 38,                   /* NATURAL  */
  YYSYMBOL_DECIMAL = 39,                   /* DECIMAL  */
  YYSYMBOL_CHRLIT = 40,                    /* CHRLIT  */
  YYSYMBOL_UNARY = 41,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_FunctionsAndDeclarations = 43,  /* FunctionsAndDeclarations  */
  YYSYMBOL_FunctionsAndDeclarations2 = 44, /* FunctionsAndDeclarations2  */
  YYSYMBOL_FunctionDefinition = 45,        /* FunctionDefinition  */
  YYSYMBOL_FunctionBody = 46,              /* FunctionBody  */
  YYSYMBOL_DeclarationsAndStatements = 47, /* DeclarationsAndStatements  */
  YYSYMBOL_FunctionDeclaration = 48,       /* FunctionDeclaration  */
  YYSYMBOL_FunctionDeclarator = 49,        /* FunctionDeclarator  */
  YYSYMBOL_ParameterList = 50,             /* ParameterList  */
  YYSYMBOL_ParameterList2 = 51,            /* ParameterList2  */
  YYSYMBOL_ParameterDeclaration = 52,      /* ParameterDeclaration  */
  YYSYMBOL_Declaration = 53,               /* Declaration  */
  YYSYMBOL_Declaration2 = 54,              /* Declaration2  */
  YYSYMBOL_TypeSpec = 55,                  /* TypeSpec  */
  YYSYMBOL_Declarator = 56,                /* Declarator  */
  YYSYMBOL_StatementsERROR = 57,           /* StatementsERROR  */
  YYSYMBOL_StatementERROR = 58,            /* StatementERROR  */
  YYSYMBOL_Statement2 = 59,                /* Statement2  */
  YYSYMBOL_Expr = 60                       /* Expr  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   712

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    95,   101,   110,   111,   114,   117,   123,
     132,   135,   141,   144,   147,   150,   156,   164,   171,   179,
     180,   186,   190,   198,   213,   216,   217,   225,   228,   231,
     234,   237,   243,   246,   253,   256,   260,   264,   267,   271,
     275,   278,   282,   286,   289,   292,   295,   298,   302,   305,
     308,   313,   314,   317,   318,   324,   327,   330,   333,   336,
     339,   342,   346,   349,   352,   355,   358,   362,   365,   368,
     371,   374,   377,   381,   384,   387,   391,   394,   398,   401,
     404,   407,   410,   414,   415
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
  "OR", "PLUS", "RBRACE", "RPAR", "SEMI", "RESERVED", "IDENTIFIER",
  "NATURAL", "DECIMAL", "CHRLIT", "UNARY", "$accept",
  "FunctionsAndDeclarations", "FunctionsAndDeclarations2",
  "FunctionDefinition", "FunctionBody", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterList2", "ParameterDeclaration", "Declaration", "Declaration2",
  "TypeSpec", "Declarator", "StatementsERROR", "StatementERROR",
  "Statement2", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     180,   -34,  -145,  -145,  -145,  -145,  -145,    11,   140,   140,
     140,   -22,  -145,  -145,  -145,   140,   140,   140,  -145,  -145,
      62,   -18,    -2,  -145,  -145,  -145,   663,   701,    87,  -145,
    -145,   -14,     1,   224,   663,   663,   663,    12,  -145,  -145,
    -145,   590,    29,    46,    34,    58,    66,   643,   207,  -145,
    -145,    43,   127,   -14,   167,   356,    97,    -2,  -145,    81,
     452,    83,   100,    83,   184,   663,   663,   663,   663,   663,
     663,   663,   663,   663,   663,   663,   663,   663,   663,   663,
     663,   663,   663,  -145,   701,  -145,  -145,   663,   663,  -145,
     380,    51,    93,    96,   659,   247,  -145,   287,    90,   404,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,    95,  -145,   475,
     319,   630,   279,    53,   100,   100,   590,   100,     3,   644,
     644,   644,   644,    83,   100,     3,   611,    83,    46,   498,
     521,  -145,  -145,  -145,   663,   663,  -145,   428,    68,    98,
     104,  -145,  -145,  -145,  -145,  -145,  -145,   327,   327,   544,
     567,  -145,  -145,  -145,  -145,   138,   327,   327,   327,  -145,
     141,  -145,   327,  -145
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    27,    28,    30,    31,    29,     0,     0,     0,
       0,     0,    24,     1,     2,     0,     0,     0,     3,     4,
      32,     0,    25,     6,     7,     8,     0,     0,     0,    16,
       9,     0,     0,     0,     0,     0,     0,    78,    79,    81,
      80,    33,     0,    19,    21,     0,     0,     0,     0,    10,
      34,     0,     0,     0,     0,     0,    32,    25,    23,     0,
       0,    74,    75,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    18,    22,     0,     0,    41,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
      11,    13,    12,    35,    26,    84,    82,     0,    77,     0,
      64,    65,    66,    63,    55,    59,    56,    60,    67,    70,
      72,    69,    71,    58,    61,    68,    62,    57,    19,     0,
       0,    40,    42,    52,     0,     0,    50,     0,     0,     0,
       0,    54,    36,    44,    83,    76,    20,     0,     0,     0,
       0,    49,    51,    45,    39,    38,     0,     0,     0,    48,
      47,    37,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,   250,   144,  -145,    52,   146,  -145,  -145,    25,
      71,     6,    99,     5,   130,  -145,  -144,    10,   -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,    14,    15,    30,    51,    16,    21,    42,    85,
      43,    17,    32,    11,    22,    54,    97,    98,    99
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    12,    55,   154,   155,    28,    10,    60,    61,    62,
      63,    13,   159,   160,   161,    20,    31,    29,   163,    69,
      70,    90,    72,    56,    74,    75,    55,    76,    55,    77,
      78,    79,    44,    53,    52,    82,    58,    64,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,    53,    52,    53,
      52,   129,   130,    83,    84,    65,    66,    67,   137,    69,
      70,    86,    72,    73,    74,    75,   100,    76,    26,    77,
      78,    79,    80,    87,   132,    82,   133,    27,     1,    44,
       2,    88,    45,    46,     3,     4,     5,    47,     6,    69,
      70,   152,    72,   133,   101,   139,   102,   141,   149,   150,
      48,    79,    33,    26,    34,   105,    69,    35,   134,    36,
      49,   135,    50,   142,    37,    38,    39,    40,     1,   144,
       2,   153,    45,    46,     3,     4,     5,    47,     6,   133,
      -5,     1,   158,     2,     8,   162,     9,     3,     4,     5,
      48,     6,    33,   146,    34,   128,   104,    35,     0,    36,
     -15,    57,    50,     0,    37,    38,    39,    40,     1,     0,
       2,     0,    45,    46,     3,     4,     5,    47,     6,     0,
       0,     1,     0,     2,     0,   107,     0,     3,     4,     5,
      48,     6,    33,     0,    34,     0,     0,    35,     0,    36,
     -14,     0,    50,     0,    37,    38,    39,    40,    91,    33,
       0,    34,    92,    93,    35,     0,    36,    94,   108,     0,
       0,    37,    38,    39,    40,    59,     0,     0,     0,     0,
      95,     0,    33,     0,    34,     0,     0,    35,     0,    36,
     -53,     0,    96,     0,    37,    38,    39,    40,   138,    33,
       0,    34,    92,    93,    35,     0,    36,    94,     0,    18,
      19,    37,    38,    39,    40,    23,    24,    25,     0,     0,
      95,     0,    33,     0,    34,     0,     0,    35,     0,    36,
     -53,     0,    96,     0,    37,    38,    39,    40,   140,     0,
       0,    65,    92,    93,     0,    69,    70,    94,    72,    73,
      74,    75,     0,    76,     0,    77,    78,    79,    80,     0,
      95,    82,    33,     0,    34,     0,     0,    35,     0,    36,
     -53,     0,    96,     0,    37,    38,    39,    40,   140,     0,
       0,     0,    92,    93,     0,    69,    70,    94,    72,    73,
      74,    75,     0,    76,     0,    77,    78,    79,    80,     0,
      95,    82,    33,     0,    34,     0,     0,    35,     0,    36,
       0,     0,    96,     0,    37,    38,    39,    40,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,    77,    78,    79,    80,     0,    81,    82,     0,
       0,   103,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
       0,    81,    82,     0,     0,   131,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,     0,    81,    82,     0,     0,   143,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,    77,    78,    79,    80,     0,    81,
      82,     0,     0,   151,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,    77,    78,
      79,    80,     0,    81,    82,     0,   106,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,     0,    76,
       0,    77,    78,    79,    80,     0,    81,    82,     0,   145,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,    77,    78,    79,    80,     0,    81,
      82,     0,   147,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,     0,    77,    78,    79,
      80,     0,    81,    82,     0,   148,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,     0,    81,    82,     0,   156,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,    76,     0,    77,    78,    79,    80,     0,    81,    82,
       0,   157,    65,    66,    67,    68,    69,    70,     0,    72,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
       0,    81,    82,    65,    66,    67,    68,    69,    70,     0,
      72,    73,    74,    75,     0,    76,     0,    77,    78,    79,
      80,     0,    65,    82,    67,     0,    69,    70,     0,    72,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
      69,    70,    82,    72,     0,     0,     0,     0,    33,     0,
      34,    78,    79,    35,     0,    36,    82,     0,    89,     0,
      37,    38,    39,    40,    33,     0,    34,     0,    33,    35,
      34,    36,     0,    35,   136,    36,    37,    38,    39,    40,
      37,    38,    39,    40,     2,     0,     0,     0,     3,     4,
       5,     0,     6
};

static const yytype_int16 yycheck[] =
{
      26,    35,    28,   147,   148,    23,     0,    33,    34,    35,
      36,     0,   156,   157,   158,    37,    18,    35,   162,    16,
      17,    47,    19,    37,    21,    22,    52,    24,    54,    26,
      27,    28,    27,    28,    28,    32,    35,    25,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    52,    52,    54,
      54,    87,    88,    34,    18,    12,    13,    14,    94,    16,
      17,    37,    19,    20,    21,    22,    33,    24,    16,    26,
      27,    28,    29,    25,    33,    32,    35,    25,     1,    84,
       3,    25,     5,     6,     7,     8,     9,    10,    11,    16,
      17,    33,    19,    35,    52,    95,    54,    97,   134,   135,
      23,    28,    25,    16,    27,    34,    16,    30,    25,    32,
      33,    25,    35,    33,    37,    38,    39,    40,     1,    34,
       3,    33,     5,     6,     7,     8,     9,    10,    11,    35,
       0,     1,     4,     3,     0,     4,     0,     7,     8,     9,
      23,    11,    25,   128,    27,    84,    57,    30,    -1,    32,
      33,    31,    35,    -1,    37,    38,    39,    40,     1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,     1,    -1,     3,    -1,     1,    -1,     7,     8,     9,
      23,    11,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      33,    -1,    35,    -1,    37,    38,    39,    40,     1,    25,
      -1,    27,     5,     6,    30,    -1,    32,    10,    34,    -1,
      -1,    37,    38,    39,    40,     1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      33,    -1,    35,    -1,    37,    38,    39,    40,     1,    25,
      -1,    27,     5,     6,    30,    -1,    32,    10,    -1,     9,
      10,    37,    38,    39,    40,    15,    16,    17,    -1,    -1,
      23,    -1,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      33,    -1,    35,    -1,    37,    38,    39,    40,     1,    -1,
      -1,    12,     5,     6,    -1,    16,    17,    10,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    -1,
      23,    32,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      33,    -1,    35,    -1,    37,    38,    39,    40,     1,    -1,
      -1,    -1,     5,     6,    -1,    16,    17,    10,    19,    20,
      21,    22,    -1,    24,    -1,    26,    27,    28,    29,    -1,
      23,    32,    25,    -1,    27,    -1,    -1,    30,    -1,    32,
      -1,    -1,    35,    -1,    37,    38,    39,    40,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    35,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    -1,    35,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    31,    32,    -1,    34,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    31,    32,    -1,    34,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    34,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    31,    32,    -1,    34,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    12,    13,    14,    15,    16,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    12,    13,    14,    15,    16,    17,    -1,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    12,    32,    14,    -1,    16,    17,    -1,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      16,    17,    32,    19,    -1,    -1,    -1,    -1,    25,    -1,
      27,    27,    28,    30,    -1,    32,    32,    -1,    35,    -1,
      37,    38,    39,    40,    25,    -1,    27,    -1,    25,    30,
      27,    32,    -1,    30,    35,    32,    37,    38,    39,    40,
      37,    38,    39,    40,     3,    -1,    -1,    -1,     7,     8,
       9,    -1,    11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    43,    45,    48,
      53,    55,    35,     0,    44,    45,    48,    53,    44,    44,
      37,    49,    56,    44,    44,    44,    16,    25,    23,    35,
      46,    18,    54,    25,    27,    30,    32,    37,    38,    39,
      40,    60,    50,    52,    55,     5,     6,    10,    23,    33,
      35,    47,    53,    55,    57,    60,    37,    56,    35,     1,
      60,    60,    60,    60,    25,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    24,    26,    27,    28,
      29,    31,    32,    34,    18,    51,    37,    25,    25,    35,
      60,     1,     5,     6,    10,    23,    35,    58,    59,    60,
      33,    47,    47,    35,    54,    34,    34,     1,    34,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    52,    60,
      60,    35,    33,    35,    25,    25,    35,    60,     1,    59,
       1,    59,    33,    35,    34,    34,    51,    34,    34,    60,
      60,    35,    33,    33,    58,    58,    34,    34,     4,    58,
      58,    58,     4,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    44,    44,    45,
      46,    46,    47,    47,    47,    47,    48,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     2,     2,     3,
       2,     3,     2,     2,     1,     1,     3,     4,     2,     0,
       3,     1,     2,     4,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     7,     5,     5,
       3,     2,     3,     1,     2,     3,     7,     5,     5,     3,
       2,     3,     2,     0,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     4,     3,     1,     1,
       1,     1,     3,     4,     3
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
  case 2: /* FunctionsAndDeclarations: FunctionDefinition FunctionsAndDeclarations2  */
#line 89 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = raiz = criar_no(no_raiz,"Program",NULL);
                                                                
                                                                adicionar_filho(raiz,(yyvsp[-1].no));
                                                                adicionar_filho(raiz,(yyvsp[0].no));
                                                            }
#line 1489 "y.tab.c"
    break;

  case 3: /* FunctionsAndDeclarations: FunctionDeclaration FunctionsAndDeclarations2  */
#line 95 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = raiz = criar_no(no_raiz,"Program",NULL);
                                                                
                                                                adicionar_filho(raiz,(yyvsp[-1].no));
                                                                adicionar_filho(raiz,(yyvsp[0].no));
                                                            }
#line 1500 "y.tab.c"
    break;

  case 4: /* FunctionsAndDeclarations: Declaration FunctionsAndDeclarations2  */
#line 101 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = raiz = criar_no(no_raiz,"Program",NULL);
                                                                
                                                                adicionar_filho(raiz,(yyvsp[-1].no));
                                                                adicionar_filho(raiz,(yyvsp[0].no));
                                                                
                                                            }
#line 1512 "y.tab.c"
    break;

  case 5: /* FunctionsAndDeclarations2: %empty  */
#line 110 "uccompiler.y"
                                                            {   (yyval.no) = NULL;}
#line 1518 "y.tab.c"
    break;

  case 6: /* FunctionsAndDeclarations2: FunctionDefinition FunctionsAndDeclarations2  */
#line 111 "uccompiler.y"
                                                            {   
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                            }
#line 1526 "y.tab.c"
    break;

  case 7: /* FunctionsAndDeclarations2: FunctionDeclaration FunctionsAndDeclarations2  */
#line 114 "uccompiler.y"
                                                            {
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                            }
#line 1534 "y.tab.c"
    break;

  case 8: /* FunctionsAndDeclarations2: Declaration FunctionsAndDeclarations2  */
#line 117 "uccompiler.y"
                                                            {
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                            }
#line 1542 "y.tab.c"
    break;

  case 9: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 123 "uccompiler.y"
                                                            {   
                                                                (yyval.no) = novo = criar_no(no_funcoes,"FuncDefinition",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                            }
#line 1553 "y.tab.c"
    break;

  case 10: /* FunctionBody: LBRACE RBRACE  */
#line 132 "uccompiler.y"
                                                            {
                                                                (yyval.no) = NULL;
                                                            }
#line 1561 "y.tab.c"
    break;

  case 11: /* FunctionBody: LBRACE DeclarationsAndStatements RBRACE  */
#line 135 "uccompiler.y"
                                                            {
                                                                (yyval.no) = (yyvsp[-1].no);
                                                            }
#line 1569 "y.tab.c"
    break;

  case 12: /* DeclarationsAndStatements: StatementsERROR DeclarationsAndStatements  */
#line 141 "uccompiler.y"
                                                            { 
                                                                ;
                                                            }
#line 1577 "y.tab.c"
    break;

  case 13: /* DeclarationsAndStatements: Declaration DeclarationsAndStatements  */
#line 144 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1585 "y.tab.c"
    break;

  case 14: /* DeclarationsAndStatements: StatementsERROR  */
#line 147 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1593 "y.tab.c"
    break;

  case 15: /* DeclarationsAndStatements: Declaration  */
#line 150 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1601 "y.tab.c"
    break;

  case 16: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 156 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_funcoes,"FuncDeclaration",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-2].no));
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                            }
#line 1611 "y.tab.c"
    break;

  case 17: /* FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR  */
#line 164 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Identifier",(yyvsp[-3].v));
                                                                adicionar_irmao((yyval.no),(yyvsp[-1].no));
                                                            }
#line 1620 "y.tab.c"
    break;

  case 18: /* ParameterList: ParameterDeclaration ParameterList2  */
#line 171 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_funcoes,"ParamList",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));

                                                                /* Parecido com Declaration */
                                                            }
#line 1631 "y.tab.c"
    break;

  case 19: /* ParameterList2: %empty  */
#line 179 "uccompiler.y"
                                                            {   (yyval.no) = NULL; }
#line 1637 "y.tab.c"
    break;

  case 20: /* ParameterList2: COMMA ParameterDeclaration ParameterList2  */
#line 180 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1645 "y.tab.c"
    break;

  case 21: /* ParameterDeclaration: TypeSpec  */
#line 186 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_funcoes,"ParamDeclaration",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[0].no));
                                                            }
#line 1654 "y.tab.c"
    break;

  case 22: /* ParameterDeclaration: TypeSpec IDENTIFIER  */
#line 190 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_funcoes,"ParamDeclaration",NULL);
                                                                adicionar_filho((yyval.no),(yyvsp[-1].no));
                                                                adicionar_filho((yyval.no),criar_no(no_terminais,"Identifier",(yyvsp[0].v)));
                                                            }
#line 1664 "y.tab.c"
    break;

  case 23: /* Declaration: TypeSpec Declarator Declaration2 SEMI  */
#line 198 "uccompiler.y"
                                                            {
                                                                (yyval.no) = novo = criar_no(no_declaracao,"Declaration",NULL);
                                                                adicionar_filho(novo,(yyvsp[-3].no));
                                                                adicionar_filho(novo,(yyvsp[-2].no));

                                                                if ((yyvsp[-1].no) != NULL) {
                                                                    struct node *novo2;
                                                                    novo2 = criar_no(no_declaracao,"Declaration",NULL);
                                                                    adicionar_irmao(novo,novo2);
                                                                    adicionar_filho(novo2,(yyvsp[-3].no));
                                                                    adicionar_filho(novo2,(yyvsp[-1].no));
                                                                }
                                                                
                                                            }
#line 1683 "y.tab.c"
    break;

  case 24: /* Declaration: error SEMI  */
#line 213 "uccompiler.y"
                                                            {  (yyval.no) = NULL; nr_erro = 1;}
#line 1689 "y.tab.c"
    break;

  case 25: /* Declaration2: %empty  */
#line 216 "uccompiler.y"
                                                            {  (yyval.no) = NULL;}
#line 1695 "y.tab.c"
    break;

  case 26: /* Declaration2: COMMA Declarator Declaration2  */
#line 217 "uccompiler.y"
                                                            {
                                                                if ((yyvsp[0].no) != NULL){
                                                                    (yyval.no) = (yyvsp[-1].no);
                                                                }
                                                            }
#line 1705 "y.tab.c"
    break;

  case 27: /* TypeSpec: CHAR  */
#line 225 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_nterminais,"Char",NULL);
                                                            }
#line 1713 "y.tab.c"
    break;

  case 28: /* TypeSpec: INT  */
#line 228 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_nterminais,"Int",NULL);
                                                            }
#line 1721 "y.tab.c"
    break;

  case 29: /* TypeSpec: VOID  */
#line 231 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_nterminais,"Void",NULL);
                                                            }
#line 1729 "y.tab.c"
    break;

  case 30: /* TypeSpec: SHORT  */
#line 234 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_nterminais,"Short",NULL);
                                                            }
#line 1737 "y.tab.c"
    break;

  case 31: /* TypeSpec: DOUBLE  */
#line 237 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_nterminais,"Double",NULL);
                                                            }
#line 1745 "y.tab.c"
    break;

  case 32: /* Declarator: IDENTIFIER  */
#line 243 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Identifier",(yyvsp[0].v));
                                                            }
#line 1753 "y.tab.c"
    break;

  case 33: /* Declarator: IDENTIFIER ASSIGN Expr  */
#line 246 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Identifier",(yyvsp[-2].v));
                                                                adicionar_irmao((yyval.no),(yyvsp[0].no));
                                                            }
#line 1762 "y.tab.c"
    break;

  case 34: /* StatementsERROR: SEMI  */
#line 253 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1770 "y.tab.c"
    break;

  case 35: /* StatementsERROR: Expr SEMI  */
#line 256 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1778 "y.tab.c"
    break;

  case 36: /* StatementsERROR: LBRACE Statement2 RBRACE  */
#line 260 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1786 "y.tab.c"
    break;

  case 37: /* StatementsERROR: IF LPAR Expr RPAR StatementERROR ELSE StatementERROR  */
#line 264 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1794 "y.tab.c"
    break;

  case 38: /* StatementsERROR: IF LPAR Expr RPAR StatementERROR  */
#line 267 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1802 "y.tab.c"
    break;

  case 39: /* StatementsERROR: WHILE LPAR Expr RPAR StatementERROR  */
#line 271 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1810 "y.tab.c"
    break;

  case 40: /* StatementsERROR: RETURN Expr SEMI  */
#line 275 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1818 "y.tab.c"
    break;

  case 41: /* StatementsERROR: RETURN SEMI  */
#line 278 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1826 "y.tab.c"
    break;

  case 42: /* StatementsERROR: LBRACE error RBRACE  */
#line 282 "uccompiler.y"
                                                            {   (yyval.no) = NULL; nr_erro = 1;}
#line 1832 "y.tab.c"
    break;

  case 43: /* StatementERROR: SEMI  */
#line 286 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1840 "y.tab.c"
    break;

  case 44: /* StatementERROR: Expr SEMI  */
#line 289 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1848 "y.tab.c"
    break;

  case 45: /* StatementERROR: LBRACE Statement2 RBRACE  */
#line 292 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1856 "y.tab.c"
    break;

  case 46: /* StatementERROR: IF LPAR Expr RPAR StatementERROR ELSE StatementERROR  */
#line 295 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1864 "y.tab.c"
    break;

  case 47: /* StatementERROR: IF LPAR Expr RPAR StatementERROR  */
#line 298 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1872 "y.tab.c"
    break;

  case 48: /* StatementERROR: WHILE LPAR Expr RPAR StatementERROR  */
#line 302 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1880 "y.tab.c"
    break;

  case 49: /* StatementERROR: RETURN Expr SEMI  */
#line 305 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1888 "y.tab.c"
    break;

  case 50: /* StatementERROR: RETURN SEMI  */
#line 308 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1896 "y.tab.c"
    break;

  case 51: /* StatementERROR: LBRACE error RBRACE  */
#line 313 "uccompiler.y"
                                                            {  (yyval.no) = NULL; nr_erro = 1;}
#line 1902 "y.tab.c"
    break;

  case 52: /* StatementERROR: error SEMI  */
#line 314 "uccompiler.y"
                                                            {  (yyval.no) = NULL; nr_erro = 1;}
#line 1908 "y.tab.c"
    break;

  case 53: /* Statement2: %empty  */
#line 317 "uccompiler.y"
                                                            {   (yyval.no) = NULL; }
#line 1914 "y.tab.c"
    break;

  case 54: /* Statement2: StatementERROR Statement2  */
#line 318 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1922 "y.tab.c"
    break;

  case 55: /* Expr: Expr ASSIGN Expr  */
#line 324 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1930 "y.tab.c"
    break;

  case 56: /* Expr: Expr COMMA Expr  */
#line 327 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1938 "y.tab.c"
    break;

  case 57: /* Expr: Expr PLUS Expr  */
#line 330 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1946 "y.tab.c"
    break;

  case 58: /* Expr: Expr MINUS Expr  */
#line 333 "uccompiler.y"
                                                            {   
                                                                ;
                                                            }
#line 1954 "y.tab.c"
    break;

  case 59: /* Expr: Expr MUL Expr  */
#line 336 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1962 "y.tab.c"
    break;

  case 60: /* Expr: Expr DIV Expr  */
#line 339 "uccompiler.y"
                                                            {   
                                                                ;
                                                            }
#line 1970 "y.tab.c"
    break;

  case 61: /* Expr: Expr MOD Expr  */
#line 342 "uccompiler.y"
                                                            {   
                                                                ;
                                                            }
#line 1978 "y.tab.c"
    break;

  case 62: /* Expr: Expr OR Expr  */
#line 346 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1986 "y.tab.c"
    break;

  case 63: /* Expr: Expr AND Expr  */
#line 349 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 1994 "y.tab.c"
    break;

  case 64: /* Expr: Expr BITWISEAND Expr  */
#line 352 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2002 "y.tab.c"
    break;

  case 65: /* Expr: Expr BITWISEOR Expr  */
#line 355 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2010 "y.tab.c"
    break;

  case 66: /* Expr: Expr BITWISEXOR Expr  */
#line 358 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2018 "y.tab.c"
    break;

  case 67: /* Expr: Expr EQ Expr  */
#line 362 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2026 "y.tab.c"
    break;

  case 68: /* Expr: Expr NE Expr  */
#line 365 "uccompiler.y"
                                                            {   
                                                                ;
                                                            }
#line 2034 "y.tab.c"
    break;

  case 69: /* Expr: Expr LE Expr  */
#line 368 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2042 "y.tab.c"
    break;

  case 70: /* Expr: Expr GE Expr  */
#line 371 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2050 "y.tab.c"
    break;

  case 71: /* Expr: Expr LT Expr  */
#line 374 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2058 "y.tab.c"
    break;

  case 72: /* Expr: Expr GT Expr  */
#line 377 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2066 "y.tab.c"
    break;

  case 73: /* Expr: PLUS Expr  */
#line 381 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2074 "y.tab.c"
    break;

  case 74: /* Expr: MINUS Expr  */
#line 384 "uccompiler.y"
                                                            {   
                                                                ;
                                                            }
#line 2082 "y.tab.c"
    break;

  case 75: /* Expr: NOT Expr  */
#line 387 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2090 "y.tab.c"
    break;

  case 76: /* Expr: IDENTIFIER LPAR Expr RPAR  */
#line 391 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2098 "y.tab.c"
    break;

  case 77: /* Expr: IDENTIFIER LPAR RPAR  */
#line 394 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2106 "y.tab.c"
    break;

  case 78: /* Expr: IDENTIFIER  */
#line 398 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Identifier",(yyvsp[0].v));
                                                            }
#line 2114 "y.tab.c"
    break;

  case 79: /* Expr: NATURAL  */
#line 401 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Natural",(yyvsp[0].v));
                                                            }
#line 2122 "y.tab.c"
    break;

  case 80: /* Expr: CHRLIT  */
#line 404 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Chrlit",(yyvsp[0].v));
                                                            }
#line 2130 "y.tab.c"
    break;

  case 81: /* Expr: DECIMAL  */
#line 407 "uccompiler.y"
                                                            {
                                                                (yyval.no) = criar_no(no_terminais,"Decimal",(yyvsp[0].v));
                                                            }
#line 2138 "y.tab.c"
    break;

  case 82: /* Expr: LPAR Expr RPAR  */
#line 410 "uccompiler.y"
                                                            {
                                                                ;
                                                            }
#line 2146 "y.tab.c"
    break;

  case 83: /* Expr: IDENTIFIER LPAR error RPAR  */
#line 414 "uccompiler.y"
                                                            {   (yyval.no) = NULL; nr_erro = 1;}
#line 2152 "y.tab.c"
    break;

  case 84: /* Expr: LPAR error RPAR  */
#line 415 "uccompiler.y"
                                                            {   (yyval.no) = NULL; nr_erro = 1;}
#line 2158 "y.tab.c"
    break;


#line 2162 "y.tab.c"

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

#line 419 "uccompiler.y"

