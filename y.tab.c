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
    #include <stdio.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdarg.h>
    

    int yylex(void);
    void yyerror(const char *s);
    

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
    struct no *no;

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
  YYSYMBOL_Expr = 60,                      /* Expr  */
  YYSYMBOL_Expr2 = 61                      /* Expr2  */
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
#define YYLAST   713

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

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
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    90,    91,    94,    95,    96,    97,   101,
     105,   106,   110,   111,   112,   113,   117,   121,   125,   128,
     129,   133,   134,   138,   140,   143,   144,   148,   149,   150,
     151,   152,   156,   157,   161,   162,   163,   164,   165,   167,
     168,   170,   174,   175,   176,   177,   178,   180,   181,   183,
     184,   187,   188,   192,   193,   194,   195,   196,   197,   198,
     200,   201,   202,   203,   204,   206,   207,   208,   209,   210,
     211,   213,   214,   215,   217,   218,   219,   221,   222,   223,
     224,   226,   227,   231,   232
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
  "Statement2", "Expr", "Expr2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-143)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     124,   -32,  -143,  -143,  -143,  -143,  -143,    19,    76,    76,
      76,   -17,  -143,  -143,  -143,    76,    76,    76,  -143,  -143,
      -1,   -22,    13,  -143,  -143,  -143,   538,   102,    63,  -143,
    -143,    38,    46,   210,   538,   538,   538,    57,  -143,  -143,
    -143,   592,    65,    73,    60,    79,    81,   538,   193,  -143,
    -143,    82,   113,    38,   153,   342,    96,    13,  -143,    92,
     438,    -5,   112,    -5,   170,   538,   538,   538,   538,   538,
     538,   538,   538,   538,   538,   538,   538,   538,   538,   538,
     538,   538,   538,  -143,   102,  -143,  -143,   538,   538,   366,
      -8,   104,   105,   538,   233,  -143,   273,   101,   390,  -143,
    -143,  -143,  -143,  -143,  -143,  -143,   103,  -143,   571,   305,
     653,   265,   634,   112,   112,   592,   112,   667,   681,   681,
     681,   681,    -5,   112,   667,   613,    -5,    73,   461,   484,
    -143,  -143,  -143,   538,   538,   414,    30,   106,   107,  -143,
    -143,  -143,  -143,   542,   110,  -143,   313,   313,   507,   530,
    -143,  -143,  -143,   123,  -143,  -143,  -143,   143,   313,   313,
     313,  -143,   145,  -143,   313,  -143
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    27,    28,    30,    31,    29,     0,     0,     0,
       0,     0,    24,     1,     2,     0,     0,     0,     3,     4,
      32,     0,    25,     6,     7,     8,     0,     0,     0,    16,
       9,     0,     0,     0,     0,     0,     0,    76,    77,    79,
      78,    33,     0,    19,    21,     0,     0,     0,     0,    10,
      34,     0,     0,     0,     0,     0,    32,    25,    23,     0,
       0,    72,    73,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,    18,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,    11,
      13,    12,    35,    26,    82,    80,     0,    74,    83,    62,
      63,    64,    61,    53,    57,    54,    58,    65,    68,    70,
      67,    69,    56,    59,    66,    60,    55,    19,     0,     0,
      40,    41,    50,     0,     0,     0,     0,     0,     0,    52,
      36,    43,    81,    83,     0,    20,     0,     0,     0,     0,
      48,    49,    44,    83,    84,    75,    39,    38,     0,     0,
       0,    47,    46,    37,     0,    45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,    20,   155,  -143,    26,   157,  -143,  -143,    39,
      83,     6,   108,     5,   137,  -143,  -142,    -2,   -26,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,    14,    15,    30,    51,    16,    21,    42,    85,
      43,    17,    32,    11,    22,    54,    96,    97,    98,   154
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    28,    55,    12,   156,   157,    10,    60,    61,    62,
      63,    69,    70,    29,    72,    26,   161,   162,   163,    13,
      20,    89,   165,    79,    27,   131,    55,   132,    55,    18,
      19,    31,    44,    53,    52,    23,    24,    25,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,    53,    52,    53,
      52,   128,   129,   151,     1,   132,     2,   135,    45,    46,
       3,     4,     5,    47,     6,    56,    -5,     1,   100,     2,
     101,    58,    64,     3,     4,     5,    48,     6,    33,    44,
      34,    84,   137,    35,   139,    36,    49,    86,    50,    83,
      37,    38,    39,    40,    87,     2,    88,   148,   149,     3,
       4,     5,    26,     6,     1,    99,     2,   115,    45,    46,
       3,     4,     5,    47,     6,     1,   104,     2,    69,   133,
     134,     3,     4,     5,   140,     6,    48,   142,    33,   152,
      34,   153,   132,    35,   155,    36,   -15,   160,    50,   164,
      37,    38,    39,    40,     1,     8,     2,     9,    45,    46,
       3,     4,     5,    47,     6,   103,   145,   127,    57,   144,
       0,   106,     0,     0,     0,     0,    48,     0,    33,     0,
      34,     0,     0,    35,     0,    36,   -14,     0,    50,     0,
      37,    38,    39,    40,    90,    33,     0,    34,    91,    92,
      35,     0,    36,    93,   107,     0,     0,    37,    38,    39,
      40,    59,     0,     0,     0,     0,    94,     0,    33,     0,
      34,     0,     0,    35,     0,    36,   -51,     0,    95,     0,
      37,    38,    39,    40,   136,    33,     0,    34,    91,    92,
      35,     0,    36,    93,     0,     0,     0,    37,    38,    39,
      40,     0,     0,     0,     0,     0,    94,     0,    33,     0,
      34,     0,     0,    35,     0,    36,   -51,     0,    95,     0,
      37,    38,    39,    40,   138,     0,     0,    65,    91,    92,
       0,    69,    70,    93,    72,    73,    74,    75,     0,    76,
       0,    77,    78,    79,    80,     0,    94,    82,    33,     0,
      34,     0,     0,    35,     0,    36,   -51,     0,    95,     0,
      37,    38,    39,    40,   138,     0,     0,     0,    91,    92,
       0,    69,    70,    93,    72,    73,    74,    75,     0,    76,
       0,    77,    78,    79,    80,     0,    94,    82,    33,     0,
      34,     0,     0,    35,     0,    36,     0,     0,    95,     0,
      37,    38,    39,    40,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,    76,     0,    77,    78,
      79,    80,     0,    81,    82,     0,     0,   102,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     0,
      76,     0,    77,    78,    79,    80,     0,    81,    82,     0,
       0,   130,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
       0,    81,    82,     0,     0,   141,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,     0,    81,    82,     0,     0,   150,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,     0,    76,     0,    77,    78,    79,    80,     0,    81,
      82,     0,   105,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,     0,    77,    78,    79,
      80,     0,    81,    82,     0,   146,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,     0,    81,    82,     0,   147,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
       0,    76,     0,    77,    78,    79,    80,     0,    81,    82,
       0,   158,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,     0,    77,    78,    79,    80,
     153,    81,    82,    33,   159,    34,     0,    33,    35,    34,
      36,     0,    35,     0,    36,    37,    38,    39,    40,    37,
      38,    39,    40,    65,    66,    67,    68,    69,    70,   143,
      72,    73,    74,    75,     0,    76,     0,    77,    78,    79,
      80,     0,    81,    82,    65,    66,    67,    68,    69,    70,
       0,    72,    73,    74,    75,     0,    76,     0,    77,    78,
      79,    80,     0,    81,    82,    65,    66,    67,    68,    69,
      70,     0,    72,    73,    74,    75,     0,    76,     0,    77,
      78,    79,    80,     0,     0,    82,    65,    66,    67,     0,
      69,    70,     0,    72,    73,    74,    75,     0,    76,     0,
      77,    78,    79,    80,     0,    65,    82,    67,     0,    69,
      70,     0,    72,    73,    74,    75,     0,    76,     0,    77,
      78,    79,    80,    69,    70,    82,    72,     0,    74,    75,
       0,    76,     0,    77,    78,    79,     0,    69,    70,    82,
      72,     0,     0,     0,     0,     0,     0,     0,    78,    79,
       0,     0,     0,    82
};

static const yytype_int16 yycheck[] =
{
      26,    23,    28,    35,   146,   147,     0,    33,    34,    35,
      36,    16,    17,    35,    19,    16,   158,   159,   160,     0,
      37,    47,   164,    28,    25,    33,    52,    35,    54,     9,
      10,    18,    27,    28,    28,    15,    16,    17,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    52,    52,    54,
      54,    87,    88,    33,     1,    35,     3,    93,     5,     6,
       7,     8,     9,    10,    11,    37,     0,     1,    52,     3,
      54,    35,    25,     7,     8,     9,    23,    11,    25,    84,
      27,    18,    94,    30,    96,    32,    33,    37,    35,    34,
      37,    38,    39,    40,    25,     3,    25,   133,   134,     7,
       8,     9,    16,    11,     1,    33,     3,   143,     5,     6,
       7,     8,     9,    10,    11,     1,    34,     3,    16,    25,
      25,     7,     8,     9,    33,    11,    23,    34,    25,    33,
      27,    18,    35,    30,    34,    32,    33,     4,    35,     4,
      37,    38,    39,    40,     1,     0,     3,     0,     5,     6,
       7,     8,     9,    10,    11,    57,   127,    84,    31,   108,
      -1,     1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,    -1,
      37,    38,    39,    40,     1,    25,    -1,    27,     5,     6,
      30,    -1,    32,    10,    34,    -1,    -1,    37,    38,    39,
      40,     1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,    -1,
      37,    38,    39,    40,     1,    25,    -1,    27,     5,     6,
      30,    -1,    32,    10,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,    -1,
      37,    38,    39,    40,     1,    -1,    -1,    12,     5,     6,
      -1,    16,    17,    10,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    23,    32,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,    -1,
      37,    38,    39,    40,     1,    -1,    -1,    -1,     5,     6,
      -1,    16,    17,    10,    19,    20,    21,    22,    -1,    24,
      -1,    26,    27,    28,    29,    -1,    23,    32,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    -1,    -1,    35,    -1,
      37,    38,    39,    40,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    31,    32,    -1,    -1,    35,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    -1,    26,    27,    28,    29,    -1,    31,    32,    -1,
      -1,    35,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    -1,    -1,    35,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    35,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    27,    28,    29,    -1,    31,
      32,    -1,    34,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    31,    32,    -1,    34,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      18,    31,    32,    25,    34,    27,    -1,    25,    30,    27,
      32,    -1,    30,    -1,    32,    37,    38,    39,    40,    37,
      38,    39,    40,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    31,    32,    12,    13,    14,    15,    16,    17,
      -1,    19,    20,    21,    22,    -1,    24,    -1,    26,    27,
      28,    29,    -1,    31,    32,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    -1,    -1,    32,    12,    13,    14,    -1,
      16,    17,    -1,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    12,    32,    14,    -1,    16,
      17,    -1,    19,    20,    21,    22,    -1,    24,    -1,    26,
      27,    28,    29,    16,    17,    32,    19,    -1,    21,    22,
      -1,    24,    -1,    26,    27,    28,    -1,    16,    17,    32,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      -1,    -1,    -1,    32
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
      29,    31,    32,    34,    18,    51,    37,    25,    25,    60,
       1,     5,     6,    10,    23,    35,    58,    59,    60,    33,
      47,    47,    35,    54,    34,    34,     1,    34,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    52,    60,    60,
      35,    33,    35,    25,    25,    60,     1,    59,     1,    59,
      33,    35,    34,    18,    61,    51,    34,    34,    60,    60,
      35,    33,    33,    18,    61,    34,    58,    58,    34,    34,
       4,    58,    58,    58,     4,    58
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    44,    44,    45,
      46,    46,    47,    47,    47,    47,    48,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     2,     2,     2,     3,
       2,     3,     2,     2,     1,     1,     3,     4,     2,     0,
       3,     1,     2,     4,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     7,     5,     5,
       3,     3,     1,     2,     3,     7,     5,     5,     3,     3,
       2,     0,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     5,     1,     1,     1,     1,
       3,     4,     3,     0,     2
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
                                                            {}
#line 1485 "y.tab.c"
    break;

  case 3: /* FunctionsAndDeclarations: FunctionDeclaration FunctionsAndDeclarations2  */
#line 90 "uccompiler.y"
                                                            {}
#line 1491 "y.tab.c"
    break;

  case 4: /* FunctionsAndDeclarations: Declaration FunctionsAndDeclarations2  */
#line 91 "uccompiler.y"
                                                            {}
#line 1497 "y.tab.c"
    break;

  case 5: /* FunctionsAndDeclarations2: %empty  */
#line 94 "uccompiler.y"
                                                 {}
#line 1503 "y.tab.c"
    break;

  case 6: /* FunctionsAndDeclarations2: FunctionDefinition FunctionsAndDeclarations2  */
#line 95 "uccompiler.y"
                                                            {}
#line 1509 "y.tab.c"
    break;

  case 7: /* FunctionsAndDeclarations2: FunctionDeclaration FunctionsAndDeclarations2  */
#line 96 "uccompiler.y"
                                                            {}
#line 1515 "y.tab.c"
    break;

  case 8: /* FunctionsAndDeclarations2: Declaration FunctionsAndDeclarations2  */
#line 97 "uccompiler.y"
                                                            {}
#line 1521 "y.tab.c"
    break;

  case 9: /* FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody  */
#line 101 "uccompiler.y"
                                                            {}
#line 1527 "y.tab.c"
    break;

  case 10: /* FunctionBody: LBRACE RBRACE  */
#line 105 "uccompiler.y"
                                                            {}
#line 1533 "y.tab.c"
    break;

  case 11: /* FunctionBody: LBRACE DeclarationsAndStatements RBRACE  */
#line 106 "uccompiler.y"
                                                            {}
#line 1539 "y.tab.c"
    break;

  case 12: /* DeclarationsAndStatements: StatementsERROR DeclarationsAndStatements  */
#line 110 "uccompiler.y"
                                                                  {}
#line 1545 "y.tab.c"
    break;

  case 13: /* DeclarationsAndStatements: Declaration DeclarationsAndStatements  */
#line 111 "uccompiler.y"
                                                            {}
#line 1551 "y.tab.c"
    break;

  case 14: /* DeclarationsAndStatements: StatementsERROR  */
#line 112 "uccompiler.y"
                                                                  {}
#line 1557 "y.tab.c"
    break;

  case 15: /* DeclarationsAndStatements: Declaration  */
#line 113 "uccompiler.y"
                                                            {}
#line 1563 "y.tab.c"
    break;

  case 16: /* FunctionDeclaration: TypeSpec FunctionDeclarator SEMI  */
#line 117 "uccompiler.y"
                                                            {}
#line 1569 "y.tab.c"
    break;

  case 17: /* FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR  */
#line 121 "uccompiler.y"
                                                            {}
#line 1575 "y.tab.c"
    break;

  case 18: /* ParameterList: ParameterDeclaration ParameterList2  */
#line 125 "uccompiler.y"
                                                            {}
#line 1581 "y.tab.c"
    break;

  case 19: /* ParameterList2: %empty  */
#line 128 "uccompiler.y"
                                                 {  }
#line 1587 "y.tab.c"
    break;

  case 20: /* ParameterList2: COMMA ParameterDeclaration ParameterList2  */
#line 129 "uccompiler.y"
                                                            {  }
#line 1593 "y.tab.c"
    break;

  case 21: /* ParameterDeclaration: TypeSpec  */
#line 133 "uccompiler.y"
                                                            {  }
#line 1599 "y.tab.c"
    break;

  case 22: /* ParameterDeclaration: TypeSpec IDENTIFIER  */
#line 134 "uccompiler.y"
                                                            {  }
#line 1605 "y.tab.c"
    break;

  case 23: /* Declaration: TypeSpec Declarator Declaration2 SEMI  */
#line 138 "uccompiler.y"
                                                            {  }
#line 1611 "y.tab.c"
    break;

  case 24: /* Declaration: error SEMI  */
#line 140 "uccompiler.y"
                                                            {  }
#line 1617 "y.tab.c"
    break;

  case 25: /* Declaration2: %empty  */
#line 143 "uccompiler.y"
                                                 {  }
#line 1623 "y.tab.c"
    break;

  case 26: /* Declaration2: COMMA Declarator Declaration2  */
#line 144 "uccompiler.y"
                                                            {  }
#line 1629 "y.tab.c"
    break;

  case 27: /* TypeSpec: CHAR  */
#line 148 "uccompiler.y"
                                                            {  }
#line 1635 "y.tab.c"
    break;

  case 28: /* TypeSpec: INT  */
#line 149 "uccompiler.y"
                                                            {  }
#line 1641 "y.tab.c"
    break;

  case 29: /* TypeSpec: VOID  */
#line 150 "uccompiler.y"
                                                            {  }
#line 1647 "y.tab.c"
    break;

  case 30: /* TypeSpec: SHORT  */
#line 151 "uccompiler.y"
                                                            {  }
#line 1653 "y.tab.c"
    break;

  case 31: /* TypeSpec: DOUBLE  */
#line 152 "uccompiler.y"
                                                            {  }
#line 1659 "y.tab.c"
    break;

  case 32: /* Declarator: IDENTIFIER  */
#line 156 "uccompiler.y"
                                                            {  }
#line 1665 "y.tab.c"
    break;

  case 33: /* Declarator: IDENTIFIER ASSIGN Expr  */
#line 157 "uccompiler.y"
                                                            {  }
#line 1671 "y.tab.c"
    break;

  case 34: /* StatementsERROR: SEMI  */
#line 161 "uccompiler.y"
                                                            {  }
#line 1677 "y.tab.c"
    break;

  case 35: /* StatementsERROR: Expr SEMI  */
#line 162 "uccompiler.y"
                                                            {  }
#line 1683 "y.tab.c"
    break;

  case 36: /* StatementsERROR: LBRACE Statement2 RBRACE  */
#line 163 "uccompiler.y"
                                                            {  }
#line 1689 "y.tab.c"
    break;

  case 37: /* StatementsERROR: IF LPAR Expr RPAR StatementERROR ELSE StatementERROR  */
#line 164 "uccompiler.y"
                                                                      {  }
#line 1695 "y.tab.c"
    break;

  case 38: /* StatementsERROR: IF LPAR Expr RPAR StatementERROR  */
#line 165 "uccompiler.y"
                                                      {  }
#line 1701 "y.tab.c"
    break;

  case 39: /* StatementsERROR: WHILE LPAR Expr RPAR StatementERROR  */
#line 167 "uccompiler.y"
                                                                 {  }
#line 1707 "y.tab.c"
    break;

  case 40: /* StatementsERROR: RETURN Expr SEMI  */
#line 168 "uccompiler.y"
                                                            {  }
#line 1713 "y.tab.c"
    break;

  case 41: /* StatementsERROR: LBRACE error RBRACE  */
#line 170 "uccompiler.y"
                                                            {  }
#line 1719 "y.tab.c"
    break;

  case 42: /* StatementERROR: SEMI  */
#line 174 "uccompiler.y"
                                                            {  }
#line 1725 "y.tab.c"
    break;

  case 43: /* StatementERROR: Expr SEMI  */
#line 175 "uccompiler.y"
                                                            {  }
#line 1731 "y.tab.c"
    break;

  case 44: /* StatementERROR: LBRACE Statement2 RBRACE  */
#line 176 "uccompiler.y"
                                                            {  }
#line 1737 "y.tab.c"
    break;

  case 45: /* StatementERROR: IF LPAR Expr RPAR StatementERROR ELSE StatementERROR  */
#line 177 "uccompiler.y"
                                                                      {  }
#line 1743 "y.tab.c"
    break;

  case 46: /* StatementERROR: IF LPAR Expr RPAR StatementERROR  */
#line 178 "uccompiler.y"
                                                      {  }
#line 1749 "y.tab.c"
    break;

  case 47: /* StatementERROR: WHILE LPAR Expr RPAR StatementERROR  */
#line 180 "uccompiler.y"
                                                                 {  }
#line 1755 "y.tab.c"
    break;

  case 48: /* StatementERROR: RETURN Expr SEMI  */
#line 181 "uccompiler.y"
                                                            {  }
#line 1761 "y.tab.c"
    break;

  case 49: /* StatementERROR: LBRACE error RBRACE  */
#line 183 "uccompiler.y"
                                                            {  }
#line 1767 "y.tab.c"
    break;

  case 50: /* StatementERROR: error SEMI  */
#line 184 "uccompiler.y"
                 {}
#line 1773 "y.tab.c"
    break;

  case 51: /* Statement2: %empty  */
#line 187 "uccompiler.y"
                   {  }
#line 1779 "y.tab.c"
    break;

  case 52: /* Statement2: StatementERROR Statement2  */
#line 188 "uccompiler.y"
                                                                 {  }
#line 1785 "y.tab.c"
    break;

  case 53: /* Expr: Expr ASSIGN Expr  */
#line 192 "uccompiler.y"
                                                            { }
#line 1791 "y.tab.c"
    break;

  case 54: /* Expr: Expr COMMA Expr  */
#line 193 "uccompiler.y"
                                                             { }
#line 1797 "y.tab.c"
    break;

  case 55: /* Expr: Expr PLUS Expr  */
#line 194 "uccompiler.y"
                     { }
#line 1803 "y.tab.c"
    break;

  case 56: /* Expr: Expr MINUS Expr  */
#line 195 "uccompiler.y"
                      { }
#line 1809 "y.tab.c"
    break;

  case 57: /* Expr: Expr MUL Expr  */
#line 196 "uccompiler.y"
                    { }
#line 1815 "y.tab.c"
    break;

  case 58: /* Expr: Expr DIV Expr  */
#line 197 "uccompiler.y"
                    { }
#line 1821 "y.tab.c"
    break;

  case 59: /* Expr: Expr MOD Expr  */
#line 198 "uccompiler.y"
                    { }
#line 1827 "y.tab.c"
    break;

  case 60: /* Expr: Expr OR Expr  */
#line 200 "uccompiler.y"
                   { }
#line 1833 "y.tab.c"
    break;

  case 61: /* Expr: Expr AND Expr  */
#line 201 "uccompiler.y"
                    { }
#line 1839 "y.tab.c"
    break;

  case 62: /* Expr: Expr BITWISEAND Expr  */
#line 202 "uccompiler.y"
                           { }
#line 1845 "y.tab.c"
    break;

  case 63: /* Expr: Expr BITWISEOR Expr  */
#line 203 "uccompiler.y"
                          { }
#line 1851 "y.tab.c"
    break;

  case 64: /* Expr: Expr BITWISEXOR Expr  */
#line 204 "uccompiler.y"
                           { }
#line 1857 "y.tab.c"
    break;

  case 65: /* Expr: Expr EQ Expr  */
#line 206 "uccompiler.y"
                   { }
#line 1863 "y.tab.c"
    break;

  case 66: /* Expr: Expr NE Expr  */
#line 207 "uccompiler.y"
                   { }
#line 1869 "y.tab.c"
    break;

  case 67: /* Expr: Expr LE Expr  */
#line 208 "uccompiler.y"
                   { }
#line 1875 "y.tab.c"
    break;

  case 68: /* Expr: Expr GE Expr  */
#line 209 "uccompiler.y"
                   { }
#line 1881 "y.tab.c"
    break;

  case 69: /* Expr: Expr LT Expr  */
#line 210 "uccompiler.y"
                   { }
#line 1887 "y.tab.c"
    break;

  case 70: /* Expr: Expr GT Expr  */
#line 211 "uccompiler.y"
                   {}
#line 1893 "y.tab.c"
    break;

  case 71: /* Expr: PLUS Expr  */
#line 213 "uccompiler.y"
                {}
#line 1899 "y.tab.c"
    break;

  case 72: /* Expr: MINUS Expr  */
#line 214 "uccompiler.y"
                 {}
#line 1905 "y.tab.c"
    break;

  case 73: /* Expr: NOT Expr  */
#line 215 "uccompiler.y"
                {}
#line 1911 "y.tab.c"
    break;

  case 74: /* Expr: IDENTIFIER LPAR RPAR  */
#line 217 "uccompiler.y"
                           {}
#line 1917 "y.tab.c"
    break;

  case 75: /* Expr: IDENTIFIER LPAR Expr Expr2 RPAR  */
#line 218 "uccompiler.y"
                                      {}
#line 1923 "y.tab.c"
    break;

  case 76: /* Expr: IDENTIFIER  */
#line 219 "uccompiler.y"
                             {}
#line 1929 "y.tab.c"
    break;

  case 77: /* Expr: NATURAL  */
#line 221 "uccompiler.y"
              {}
#line 1935 "y.tab.c"
    break;

  case 78: /* Expr: CHRLIT  */
#line 222 "uccompiler.y"
             {}
#line 1941 "y.tab.c"
    break;

  case 79: /* Expr: DECIMAL  */
#line 223 "uccompiler.y"
              {}
#line 1947 "y.tab.c"
    break;

  case 80: /* Expr: LPAR Expr RPAR  */
#line 224 "uccompiler.y"
                     {}
#line 1953 "y.tab.c"
    break;

  case 81: /* Expr: IDENTIFIER LPAR error RPAR  */
#line 226 "uccompiler.y"
                                 {}
#line 1959 "y.tab.c"
    break;

  case 82: /* Expr: LPAR error RPAR  */
#line 227 "uccompiler.y"
                      {}
#line 1965 "y.tab.c"
    break;

  case 83: /* Expr2: %empty  */
#line 231 "uccompiler.y"
    {}
#line 1971 "y.tab.c"
    break;

  case 84: /* Expr2: COMMA Expr2  */
#line 232 "uccompiler.y"
                  {}
#line 1977 "y.tab.c"
    break;


#line 1981 "y.tab.c"

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

#line 235 "uccompiler.y"

