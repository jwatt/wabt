/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         WASM_PARSER_STYPE
#define YYLTYPE         WASM_PARSER_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         wasm_parser_parse
#define yylex           wasm_parser_lex
#define yyerror         wasm_parser_error
#define yydebug         wasm_parser_debug
#define yynerrs         wasm_parser_nerrs


/* Copy the first part of user declarations.  */
#line 17 "src/wasm-bison-parser.y" /* yacc.c:339  */

#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "wasm-allocator.h"
#include "wasm-internal.h"
#include "wasm-parser.h"

#define DUPTEXT(dst, src)                                                   \
  (dst).start = wasm_strndup(parser->allocator, (src).start, (src).length); \
  (dst).length = (src).length

#define DUPQUOTEDTEXT(dst, src)                                           \
  (dst).start =                                                           \
      wasm_strndup(parser->allocator, (src).start + 1, (src).length - 2); \
  (dst).length = (src).length - 2

#define CHECK_ALLOC_(cond)                                       \
  if ((cond)) {                                                  \
    WasmLocation loc;                                            \
    loc.filename = __FILE__;                                     \
    loc.line = __LINE__;                                         \
    loc.first_column = loc.last_column = 0;                      \
    wasm_parser_error(&loc, lexer, parser, "allocation failed"); \
    YYERROR;                                                     \
  }

#define CHECK_ALLOC(e) CHECK_ALLOC_((e) != WASM_OK)
#define CHECK_ALLOC_NULL(v) CHECK_ALLOC_(!(v))
#define CHECK_ALLOC_STR(s) CHECK_ALLOC_(!(s).start)

#define YYLLOC_DEFAULT(Current, Rhs, N)                       \
  do                                                          \
    if (N) {                                                  \
      (Current).filename = YYRHSLOC(Rhs, 1).filename;         \
      (Current).line = YYRHSLOC(Rhs, 1).line;                 \
      (Current).first_column = YYRHSLOC(Rhs, 1).first_column; \
      (Current).last_column = YYRHSLOC(Rhs, N).last_column;   \
    } else {                                                  \
      (Current).filename = NULL;                              \
      (Current).line = YYRHSLOC(Rhs, 0).line;                 \
      (Current).first_column = (Current).last_column =        \
          YYRHSLOC(Rhs, 0).last_column;                       \
    }                                                         \
  while (0)

#define YYMALLOC(size) wasm_alloc(parser->allocator, size, WASM_DEFAULT_ALIGN)
#define YYFREE(p) wasm_free(parser->allocator, p)

static WasmFunc* new_func(WasmAllocator* allocator) {
  return wasm_alloc_zero(allocator, sizeof(WasmFunc), WASM_DEFAULT_ALIGN);
}

static WasmCommand* new_command(WasmAllocator* allocator) {
  return wasm_alloc_zero(allocator, sizeof(WasmCommand), WASM_DEFAULT_ALIGN);
}

static WasmModule* new_module(WasmAllocator* allocator) {
  return wasm_alloc_zero(allocator, sizeof(WasmModule), WASM_DEFAULT_ALIGN);
}

static WasmImport* new_import(WasmAllocator* allocator) {
  return wasm_alloc_zero(allocator, sizeof(WasmImport), WASM_DEFAULT_ALIGN);
}

static int read_int32(const char* s, const char* end, uint32_t* out,
                      int allow_signed);
static int read_int64(const char* s, const char* end, uint64_t* out);
static int read_uint64(const char* s, const char* end, uint64_t* out);
static int read_float(const char* s, const char* end, float* out);
static int read_double(const char* s, const char* end, double* out);
static int read_const(WasmType type, const char* s, const char* end,
                      WasmConst* out);
static WasmResult dup_string_contents(WasmAllocator*, WasmStringSlice* text,
                                      void** out_data, size_t* out_size);

#define wasm_parser_lex wasm_lexer_lex


#line 158 "src/wasm-bison-parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "wasm-bison-parser.h".  */
#ifndef YY_WASM_PARSER_SRC_WASM_BISON_PARSER_H_INCLUDED
# define YY_WASM_PARSER_SRC_WASM_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef WASM_PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define WASM_PARSER_DEBUG 1
#  else
#   define WASM_PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define WASM_PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined WASM_PARSER_DEBUG */
#if WASM_PARSER_DEBUG
extern int wasm_parser_debug;
#endif

/* Token type.  */
#ifndef WASM_PARSER_TOKENTYPE
# define WASM_PARSER_TOKENTYPE
  enum wasm_parser_tokentype
  {
    WASM_TOKEN_TYPE_EOF = 0,
    WASM_TOKEN_TYPE_LPAR = 258,
    WASM_TOKEN_TYPE_RPAR = 259,
    WASM_TOKEN_TYPE_INT = 260,
    WASM_TOKEN_TYPE_FLOAT = 261,
    WASM_TOKEN_TYPE_TEXT = 262,
    WASM_TOKEN_TYPE_VAR = 263,
    WASM_TOKEN_TYPE_VALUE_TYPE = 264,
    WASM_TOKEN_TYPE_NOP = 265,
    WASM_TOKEN_TYPE_BLOCK = 266,
    WASM_TOKEN_TYPE_IF = 267,
    WASM_TOKEN_TYPE_THEN = 268,
    WASM_TOKEN_TYPE_ELSE = 269,
    WASM_TOKEN_TYPE_LOOP = 270,
    WASM_TOKEN_TYPE_BR = 271,
    WASM_TOKEN_TYPE_BR_IF = 272,
    WASM_TOKEN_TYPE_TABLESWITCH = 273,
    WASM_TOKEN_TYPE_CASE = 274,
    WASM_TOKEN_TYPE_CALL = 275,
    WASM_TOKEN_TYPE_CALL_IMPORT = 276,
    WASM_TOKEN_TYPE_CALL_INDIRECT = 277,
    WASM_TOKEN_TYPE_RETURN = 278,
    WASM_TOKEN_TYPE_GET_LOCAL = 279,
    WASM_TOKEN_TYPE_SET_LOCAL = 280,
    WASM_TOKEN_TYPE_LOAD = 281,
    WASM_TOKEN_TYPE_STORE = 282,
    WASM_TOKEN_TYPE_OFFSET = 283,
    WASM_TOKEN_TYPE_ALIGN = 284,
    WASM_TOKEN_TYPE_CONST = 285,
    WASM_TOKEN_TYPE_UNARY = 286,
    WASM_TOKEN_TYPE_BINARY = 287,
    WASM_TOKEN_TYPE_COMPARE = 288,
    WASM_TOKEN_TYPE_CONVERT = 289,
    WASM_TOKEN_TYPE_SELECT = 290,
    WASM_TOKEN_TYPE_FUNC = 291,
    WASM_TOKEN_TYPE_START = 292,
    WASM_TOKEN_TYPE_TYPE = 293,
    WASM_TOKEN_TYPE_PARAM = 294,
    WASM_TOKEN_TYPE_RESULT = 295,
    WASM_TOKEN_TYPE_LOCAL = 296,
    WASM_TOKEN_TYPE_MODULE = 297,
    WASM_TOKEN_TYPE_MEMORY = 298,
    WASM_TOKEN_TYPE_SEGMENT = 299,
    WASM_TOKEN_TYPE_IMPORT = 300,
    WASM_TOKEN_TYPE_EXPORT = 301,
    WASM_TOKEN_TYPE_TABLE = 302,
    WASM_TOKEN_TYPE_UNREACHABLE = 303,
    WASM_TOKEN_TYPE_MEMORY_SIZE = 304,
    WASM_TOKEN_TYPE_GROW_MEMORY = 305,
    WASM_TOKEN_TYPE_ASSERT_INVALID = 306,
    WASM_TOKEN_TYPE_ASSERT_RETURN = 307,
    WASM_TOKEN_TYPE_ASSERT_RETURN_NAN = 308,
    WASM_TOKEN_TYPE_ASSERT_TRAP = 309,
    WASM_TOKEN_TYPE_INVOKE = 310,
    WASM_TOKEN_TYPE_LOW = 311
  };
#endif

/* Value type.  */
#if ! defined WASM_PARSER_STYPE && ! defined WASM_PARSER_STYPE_IS_DECLARED
typedef WasmToken WASM_PARSER_STYPE;
# define WASM_PARSER_STYPE_IS_TRIVIAL 1
# define WASM_PARSER_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined WASM_PARSER_LTYPE && ! defined WASM_PARSER_LTYPE_IS_DECLARED
typedef struct WASM_PARSER_LTYPE WASM_PARSER_LTYPE;
struct WASM_PARSER_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define WASM_PARSER_LTYPE_IS_DECLARED 1
# define WASM_PARSER_LTYPE_IS_TRIVIAL 1
#endif



int wasm_parser_parse (WasmLexer lexer, WasmParser* parser);

#endif /* !YY_WASM_PARSER_SRC_WASM_BISON_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 288 "src/wasm-bison-parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined WASM_PARSER_LTYPE_IS_TRIVIAL && WASM_PARSER_LTYPE_IS_TRIVIAL \
             && defined WASM_PARSER_STYPE_IS_TRIVIAL && WASM_PARSER_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  347

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if WASM_PARSER_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   199,   199,   200,   206,   207,   211,   215,   222,   223,
     227,   236,   244,   245,   251,   255,   259,   266,   267,   271,
     272,   279,   280,   288,   291,   295,   300,   306,   313,   320,
     329,   338,   344,   351,   358,   365,   373,   379,   384,   405,
     411,   417,   424,   429,   435,   443,   452,   461,   467,   474,
     481,   488,   494,   498,   502,   509,   510,   513,   517,   523,
     524,   528,   532,   538,   539,   545,   546,   549,   550,   560,
     565,   574,   579,   590,   593,   598,   607,   612,   623,   626,
     630,   635,   641,   648,   656,   665,   675,   684,   692,   701,
     709,   716,   724,   733,   741,   748,   756,   763,   769,   776,
     782,   789,   797,   806,   814,   821,   829,   836,   842,   849,
     857,   864,   870,   875,   881,   888,   896,   905,   913,   920,
     928,   935,   941,   948,   956,   963,   969,   976,   982,   987,
     993,  1000,  1008,  1015,  1021,  1028,  1034,  1039,  1045,  1052,
    1058,  1063,  1069,  1076,  1082,  1086,  1095,  1103,  1104,  1111,
    1120,  1129,  1135,  1144,  1148,  1155,  1159,  1166,  1174,  1181,
    1192,  1199,  1205,  1206,  1215,  1224,  1232,  1240,  1248,  1256,
    1264,  1274,  1362,  1368,  1375,  1382,  1390,  1397,  1407,  1408,
    1416,  1425,  1426,  1429,  1430,  1437,  1446
};
#endif

#if WASM_PARSER_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"EOF\"", "error", "$undefined", "\"(\"", "\")\"", "INT", "FLOAT",
  "TEXT", "VAR", "VALUE_TYPE", "NOP", "BLOCK", "IF", "THEN", "ELSE",
  "LOOP", "BR", "BR_IF", "TABLESWITCH", "CASE", "CALL", "CALL_IMPORT",
  "CALL_INDIRECT", "RETURN", "GET_LOCAL", "SET_LOCAL", "LOAD", "STORE",
  "OFFSET", "ALIGN", "CONST", "UNARY", "BINARY", "COMPARE", "CONVERT",
  "SELECT", "FUNC", "START", "TYPE", "PARAM", "RESULT", "LOCAL", "MODULE",
  "MEMORY", "SEGMENT", "IMPORT", "EXPORT", "TABLE", "UNREACHABLE",
  "MEMORY_SIZE", "GROW_MEMORY", "ASSERT_INVALID", "ASSERT_RETURN",
  "ASSERT_RETURN_NAN", "ASSERT_TRAP", "INVOKE", "LOW", "$accept",
  "value_type_list", "func_type", "literal", "var", "var_list", "bind_var",
  "quoted_text", "string_contents", "labeling", "offset", "align", "expr",
  "expr1", "expr_opt", "non_empty_expr_list", "expr_list", "target",
  "target_list", "case", "case_list", "param_list", "result", "local_list",
  "type_use", "func_info", "func", "start", "segment_address", "segment",
  "segment_list", "initial_size", "max_size", "memory", "type_def",
  "table", "import", "export", "export_memory", "module_fields", "module",
  "cmd", "cmd_list", "const", "const_opt", "const_list", "script",
  "script_start", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

#define YYPACT_NINF -143

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -143,    25,  -143,    38,     2,  -143,  -143,  -143,  -143,    49,
      59,    63,    71,    75,    42,    50,    75,    43,    46,    51,
    -143,  -143,   241,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,   119,    75,    75,    75,   100,    23,    31,    26,
     105,   106,    75,  -143,  -143,  -143,  -143,  -143,   102,  -143,
    -143,   284,  -143,   127,  -143,   134,   140,   142,   145,   147,
     149,  -143,  -143,   151,   138,   160,  -143,   165,    75,    75,
      16,    91,   116,   123,   131,   153,  -143,   174,   134,   174,
      22,    31,   174,    31,    31,    31,   134,    31,    31,   148,
     148,   153,   134,   134,   134,   134,   134,    31,   174,   175,
     174,  -143,  -143,   134,   179,   134,   140,   142,   145,   147,
     577,  -143,   356,   134,   142,   145,   454,   134,   145,   495,
     134,   413,   134,   140,   142,   145,  -143,  -143,   182,   154,
    -143,   157,  -143,    75,   186,   189,   190,  -143,  -143,   194,
     203,    75,  -143,  -143,   205,  -143,   134,   207,   174,   134,
     134,  -143,  -143,   134,   134,   134,   134,   134,  -143,  -143,
     134,  -143,   183,   183,  -143,  -143,   134,   134,  -143,   134,
     211,    60,   209,   215,    61,   212,  -143,  -143,   134,   142,
     145,   134,   145,   134,   134,   140,   142,   145,   174,   134,
     145,   134,   134,   174,   134,   142,   145,   134,   145,   134,
     126,   218,   182,   184,  -143,  -143,   164,   186,    78,   223,
     225,  -143,  -143,  -143,   229,  -143,   230,  -143,   134,   536,
     134,   134,   134,  -143,  -143,   134,   232,  -143,  -143,   134,
    -143,  -143,   134,   134,  -143,  -143,   134,  -143,  -143,  -143,
     236,  -143,  -143,   239,   134,   145,   134,   134,   134,   142,
     145,   134,   145,   134,    69,   227,   134,    76,   237,   134,
     145,   134,   134,  -143,   238,   244,   245,   247,  -143,   249,
     250,  -143,  -143,  -143,  -143,   174,  -143,  -143,  -143,   208,
    -143,  -143,   134,  -143,  -143,  -143,   134,   134,   145,   134,
     134,  -143,   252,  -143,   259,   134,    79,   260,  -143,   264,
    -143,   262,  -143,  -143,   134,  -143,  -143,   134,  -143,  -143,
     267,  -143,  -143,  -143,   268,   276,   168,   231,  -143,   280,
      81,   286,  -143,   288,   279,    31,    31,  -143,   294,   174,
     308,   316,   323,  -143,   134,  -143,  -143,   309,  -143,   325,
      83,  -143,   134,   327,   331,  -143,  -143
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     178,   185,   186,     0,     0,   172,   179,     1,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,   183,     0,   171,   163,   170,   169,   168,   167,   164,
     165,   166,     0,     0,     0,     0,     0,    79,     0,     0,
       0,     0,     0,    12,   174,   183,   183,   183,     0,   173,
     184,     0,    14,    80,    57,   142,   128,   136,   140,   112,
       0,    10,    11,     0,     0,     0,   149,   147,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    17,     0,    17,
      55,     0,    17,     0,     0,     0,    55,     0,     0,    19,
      19,     0,     0,     0,     0,     0,     0,     0,     2,     0,
       2,    52,    53,     0,     0,   111,    99,   107,    97,    81,
       0,    58,     0,   135,   129,   133,     0,   139,   137,     0,
     141,     0,   127,   113,   121,   125,   143,   144,     4,     0,
     150,     0,   147,     0,     4,     0,     0,   155,    13,   181,
       0,     0,     8,     9,     0,    18,    25,     0,    18,    59,
      55,    56,    35,     0,     0,    59,    59,     0,    37,    42,
       0,    20,    21,    21,    46,    47,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,    54,    23,   106,   100,
     104,   110,   108,    98,    96,    82,    90,    94,     2,   132,
     130,   134,   138,     2,   120,   114,   118,   124,   122,   126,
       0,     0,     4,     0,   152,   148,     0,     4,     0,     0,
       0,   161,   160,   182,     0,   176,     0,   180,    26,     0,
      27,    59,    60,    33,    36,    31,     0,    39,    40,    59,
      43,    22,     0,     0,    48,    50,     0,    78,    69,     3,
       0,    73,    74,     0,   103,   101,   105,   109,    89,    83,
      87,    93,    91,    95,     0,     0,   131,     0,     0,   117,
     115,   119,   123,     2,     0,     0,     0,     0,   151,     0,
       0,   158,   156,   175,   177,    17,    29,    34,    32,     0,
      41,    44,     0,    49,    70,    75,   102,    86,    84,    88,
      92,    71,     0,    76,     0,   116,     0,     0,   153,     0,
     145,     0,   159,   157,    59,    63,    45,    85,    72,    77,
       5,     7,   154,    16,     0,     0,     0,     0,   146,    28,
       0,     0,    64,     0,     0,     0,     0,    67,     0,    17,
       0,     0,    38,     6,    59,    62,    61,     0,    68,     0,
      59,    30,    59,     0,     0,    65,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,   -99,  -126,   246,   -65,  -143,   -37,   197,  -143,   -70,
     251,   173,   -45,  -143,   -79,   167,  -142,     6,  -143,  -143,
    -143,   -42,   -16,    72,   -50,  -143,  -143,  -143,  -143,  -143,
     210,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
     330,  -143,  -143,   201,  -143,    95,  -143,  -143
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   171,   201,   144,    63,    71,   145,    21,   314,   146,
     162,   232,    54,   104,   152,   222,   223,   322,   316,   338,
     332,    56,    57,    58,    59,    60,    24,    25,   301,   205,
     131,    67,   132,    26,    27,    28,    29,    30,    31,    14,
       5,     6,     1,    50,   214,    36,     2,     3
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      53,   174,    65,   109,    68,   136,   138,   158,   209,   149,
     111,   106,   154,   227,   228,   150,   153,   123,   155,   156,
     157,    61,   159,   160,    62,   110,    51,    61,     4,    64,
      62,    52,   170,   147,    52,   151,    61,   107,     7,    62,
     114,   151,   148,   124,     8,    22,    23,   165,   166,   167,
     168,   169,    15,     9,    10,    11,    12,    13,   176,   135,
     111,   172,    17,   175,   238,   242,    18,   185,   111,   239,
     239,   224,   111,   291,    19,   111,   266,   111,   239,   277,
     293,   269,    20,   310,   210,   239,   110,   280,   239,   254,
     179,    52,     8,   186,   257,   137,    61,   325,    33,    62,
     326,    34,   220,    48,    49,   151,    35,   195,   225,   226,
      66,   221,   229,    20,    52,   230,    97,   263,   264,    48,
     139,   234,   235,    44,   236,   108,    48,   140,   115,   118,
      51,   125,    75,   111,    48,   141,   111,   110,   111,   111,
      72,    73,    74,   112,   111,   116,   111,   111,   119,   111,
     121,   255,   111,   126,   111,   127,   258,   270,   142,   143,
     203,   204,   315,   129,   296,   263,   264,   203,   268,   249,
     130,   320,   321,   111,   128,   276,   161,   111,   180,   182,
     278,   187,    52,   177,   173,   200,   190,   281,   282,   208,
     202,   283,   339,   211,   212,   196,   198,    48,   343,   111,
     344,   111,   111,   111,    55,   304,   111,   215,   111,   217,
     219,   111,   231,    32,   111,   237,   111,   111,   240,   241,
     105,   243,   265,   113,   117,   120,   122,   271,   267,   272,
      45,    46,    47,   273,   274,   279,   292,   306,    69,    70,
     284,   111,   111,   285,   111,   111,   294,   297,   298,   299,
     111,   245,   300,   302,   303,   305,   308,   250,   252,   334,
     330,   331,   111,   309,   311,   133,   134,   260,   312,   313,
     317,   323,   318,   178,   181,   183,   184,    37,    38,    39,
     319,   189,   191,   324,    40,   192,    41,    42,    43,   320,
     194,   197,   199,   329,    76,    77,    78,   328,   333,    79,
      80,    81,    82,   342,    83,    84,    85,    86,    87,    88,
      89,    90,   335,   218,    91,    92,    93,    94,    95,    96,
     336,   288,    97,    98,    99,   100,   337,   327,   340,   341,
     207,   345,   101,   102,   103,   346,   233,   164,   216,    16,
     213,   163,   206,     0,     0,     0,   244,   246,     0,   247,
       0,     0,   248,   251,   253,     0,     0,   256,     0,     0,
       0,     0,   259,   261,     0,   262,    76,    77,    78,     0,
       0,    79,    80,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,    91,    92,    93,    94,
      95,    96,     0,     0,     0,   188,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,     0,     0,
       0,     0,   286,     0,     0,     0,   287,   289,     0,   290,
       0,     0,     0,    76,    77,    78,     0,   295,    79,    80,
      81,    82,     0,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,    91,    92,    93,    94,    95,    96,     0,
       0,     0,    98,    99,   100,   307,     0,     0,     0,     0,
       0,   101,   102,   103,    76,    77,    78,     0,     0,    79,
      80,    81,    82,     0,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,    76,    77,    78,     0,     0,
      79,    80,    81,    82,     0,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,    91,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,   193,     0,     0,     0,
       0,     0,     0,   101,   102,   103,    76,    77,    78,   275,
       0,    79,    80,    81,    82,     0,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,    91,    92,    93,    94,
      95,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   101,   102,   103,    76,    77,    78,
       0,     0,    79,    80,    81,    82,     0,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   102,   103
};

static const yytype_int16 yycheck[] =
{
      37,   100,    39,    53,    41,    70,    71,    86,   134,    79,
      55,    53,    82,   155,   156,    80,    81,    59,    83,    84,
      85,     5,    87,    88,     8,     3,     3,     5,     3,     3,
       8,     8,    97,    78,     8,    80,     5,    53,     0,     8,
      56,    86,    79,    59,    42,     3,     4,    92,    93,    94,
      95,    96,     3,    51,    52,    53,    54,    55,   103,    43,
     105,    98,     3,   100,     4,     4,     3,   109,   113,     9,
       9,   150,   117,     4,     3,   120,   202,   122,     9,   221,
       4,   207,     7,     4,   134,     9,     3,   229,     9,   188,
     106,     8,    42,   109,   193,     4,     5,    16,    55,     8,
      19,    55,   147,     3,     4,   150,    55,   123,   153,   154,
       5,   148,   157,     7,     8,   160,    38,    39,    40,     3,
       4,   166,   167,     4,   169,    53,     3,     4,    56,    57,
       3,    59,    30,   178,     3,     4,   181,     3,   183,   184,
      45,    46,    47,     3,   189,     3,   191,   192,     3,   194,
       3,   188,   197,     4,   199,     4,   193,   207,     5,     6,
       3,     4,   304,     3,   263,    39,    40,     3,     4,   185,
       5,     3,     4,   218,    36,   220,    28,   222,   106,   107,
     225,   109,     8,     4,     9,     3,   114,   232,   233,     3,
      36,   236,   334,     4,     4,   123,   124,     3,   340,   244,
     342,   246,   247,   248,    37,   275,   251,     4,   253,     4,
       3,   256,    29,    16,   259,     4,   261,   262,     9,     4,
      53,     9,     4,    56,    57,    58,    59,     4,    44,     4,
      33,    34,    35,     4,     4,     3,     9,   282,    41,    42,
       4,   286,   287,     4,   289,   290,     9,     9,     4,     4,
     295,   179,     5,     4,     4,    47,     4,   185,   186,   329,
     325,   326,   307,     4,     4,    68,    69,   195,     4,     7,
       3,    40,     4,   106,   107,   108,   109,    36,    37,    38,
       4,   114,   115,     3,    43,   118,    45,    46,    47,     3,
     123,   124,   125,    14,    10,    11,    12,     9,     4,    15,
      16,    17,    18,   340,    20,    21,    22,    23,    24,    25,
      26,    27,     4,   146,    30,    31,    32,    33,    34,    35,
       4,   249,    38,    39,    40,    41,     3,   321,    19,     4,
     133,     4,    48,    49,    50,     4,   163,    91,   141,     9,
     139,    90,   132,    -1,    -1,    -1,   179,   180,    -1,   182,
      -1,    -1,   185,   186,   187,    -1,    -1,   190,    -1,    -1,
      -1,    -1,   195,   196,    -1,   198,    10,    11,    12,    -1,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,   245,    -1,    -1,    -1,   249,   250,    -1,   252,
      -1,    -1,    -1,    10,    11,    12,    -1,   260,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    39,    40,    41,   288,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    10,    11,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    30,    31,    32,    33,    34,    35,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    10,    11,    12,    -1,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    30,    31,    32,    33,    34,
      35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    10,    11,    12,
      -1,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    99,   103,   104,     3,    97,    98,     0,    42,    51,
      52,    53,    54,    55,    96,     3,    97,     3,     3,     3,
       7,    64,     3,     4,    83,    84,    90,    91,    92,    93,
      94,    95,    64,    55,    55,    55,   102,    36,    37,    38,
      43,    45,    46,    47,     4,    64,    64,    64,     3,     4,
     100,     3,     8,    63,    69,    72,    78,    79,    80,    81,
      82,     5,     8,    61,     3,    63,     5,    88,    63,    64,
      64,    62,   102,   102,   102,    30,    10,    11,    12,    15,
      16,    17,    18,    20,    21,    22,    23,    24,    25,    26,
      27,    30,    31,    32,    33,    34,    35,    38,    39,    40,
      41,    48,    49,    50,    70,    72,    78,    79,    80,    81,
       3,    69,     3,    72,    79,    80,     3,    72,    80,     3,
      72,     3,    72,    78,    79,    80,     4,     4,    36,     3,
       5,    87,    89,    64,    64,    43,    61,     4,    61,     4,
       4,     4,     5,     6,    60,    63,    66,    69,    63,    66,
      61,    69,    71,    61,    66,    61,    61,    61,    71,    61,
      61,    28,    67,    67,    60,    69,    69,    69,    69,    69,
      61,    58,    63,     9,    58,    63,    69,     4,    72,    79,
      80,    72,    80,    72,    72,    78,    79,    80,    39,    72,
      80,    72,    72,    41,    72,    79,    80,    72,    80,    72,
       3,    59,    36,     3,     4,    86,    87,    64,     3,    59,
      81,     4,     4,   100,   101,     4,    64,     4,    72,     3,
      69,    63,    72,    73,    71,    69,    69,    73,    73,    69,
      69,    29,    68,    68,    69,    69,    69,     4,     4,     9,
       9,     4,     4,     9,    72,    80,    72,    72,    72,    79,
      80,    72,    80,    72,    58,    63,    72,    58,    63,    72,
      80,    72,    72,    39,    40,     4,    59,    44,     4,    59,
      81,     4,     4,     4,     4,    13,    69,    73,    69,     3,
      73,    69,    69,    69,     4,     4,    72,    72,    80,    72,
      72,     4,     9,     4,     9,    72,    58,     9,     4,     4,
       5,    85,     4,     4,    66,    47,    69,    72,     4,     4,
       4,     4,     4,     7,    65,    73,    75,     3,     4,     4,
       3,     4,    74,    40,     3,    16,    19,    74,     9,    14,
      61,    61,    77,     4,    66,     4,     4,     3,    76,    73,
      19,     4,    63,    73,    73,     4,     4
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    64,    65,    66,    66,    67,
      67,    68,    68,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    78,    78,    79,    80,    80,    80,    80,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    84,    85,    86,    87,    87,    88,
      89,    90,    90,    91,    91,    92,    93,    93,    93,    93,
      94,    95,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    97,    98,    98,    98,    98,    98,    98,    99,    99,
     100,   101,   101,   102,   102,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     4,     8,     4,     1,     1,
       1,     1,     0,     2,     1,     1,     1,     0,     1,     0,
       1,     0,     1,     3,     1,     2,     3,     3,     7,     4,
      12,     3,     4,     3,     4,     2,     3,     2,     9,     3,
       3,     4,     2,     3,     4,     5,     2,     2,     3,     4,
       3,     2,     1,     1,     2,     0,     1,     1,     2,     0,
       1,     4,     4,     0,     2,     4,     5,     0,     2,     4,
       5,     5,     6,     4,     4,     5,     5,     6,     4,     0,
       1,     2,     3,     4,     5,     6,     5,     4,     5,     4,
       3,     4,     5,     4,     3,     4,     3,     2,     3,     2,
       3,     4,     5,     4,     3,     4,     3,     2,     3,     4,
       3,     2,     1,     2,     3,     4,     5,     4,     3,     4,
       3,     2,     3,     4,     3,     2,     3,     2,     1,     2,
       3,     4,     3,     2,     3,     2,     1,     2,     3,     2,
       1,     2,     1,     4,     4,     1,     5,     0,     2,     1,
       1,     6,     5,     7,     8,     4,     6,     7,     6,     7,
       5,     5,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     1,     5,     5,     9,     8,     9,     0,     2,
       4,     0,     1,     0,     2,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (&yylloc, lexer, parser, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if WASM_PARSER_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined WASM_PARSER_LTYPE_IS_TRIVIAL && WASM_PARSER_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, lexer, parser); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, WasmLexer lexer, WasmParser* parser)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (lexer);
  YYUSE (parser);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, WasmLexer lexer, WasmParser* parser)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, lexer, parser);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, WasmLexer lexer, WasmParser* parser)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , lexer, parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, lexer, parser); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !WASM_PARSER_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !WASM_PARSER_DEBUG */


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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, WasmLexer lexer, WasmParser* parser)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (lexer);
  YYUSE (parser);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 58: /* value_type_list  */
#line 164 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_type_vector(parser->allocator, &((*yyvaluep).types)); }
#line 1490 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 59: /* func_type  */
#line 178 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_func_signature(parser->allocator, &((*yyvaluep).func_sig)); }
#line 1496 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 60: /* literal  */
#line 163 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_string_slice(parser->allocator, &((*yyvaluep).text)); }
#line 1502 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 61: /* var  */
#line 165 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_var(parser->allocator, &((*yyvaluep).var)); }
#line 1508 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 62: /* var_list  */
#line 166 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_var_vector_and_elements(parser->allocator, &((*yyvaluep).vars)); }
#line 1514 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 63: /* bind_var  */
#line 163 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_string_slice(parser->allocator, &((*yyvaluep).text)); }
#line 1520 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 64: /* quoted_text  */
#line 163 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_string_slice(parser->allocator, &((*yyvaluep).text)); }
#line 1526 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 65: /* string_contents  */
#line 175 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_segment(parser->allocator, &((*yyvaluep).segment)); }
#line 1532 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 66: /* labeling  */
#line 163 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_string_slice(parser->allocator, &((*yyvaluep).text)); }
#line 1538 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 69: /* expr  */
#line 167 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_expr_ptr(parser->allocator, &((*yyvaluep).expr)); }
#line 1544 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 70: /* expr1  */
#line 167 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_expr_ptr(parser->allocator, &((*yyvaluep).expr)); }
#line 1550 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 71: /* expr_opt  */
#line 167 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_expr_ptr(parser->allocator, &((*yyvaluep).expr)); }
#line 1556 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 72: /* non_empty_expr_list  */
#line 168 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_expr_ptr_vector_and_elements(parser->allocator, &((*yyvaluep).exprs)); }
#line 1562 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 73: /* expr_list  */
#line 168 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_expr_ptr_vector_and_elements(parser->allocator, &((*yyvaluep).exprs)); }
#line 1568 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 74: /* target  */
#line 169 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_target(parser->allocator, &((*yyvaluep).target)); }
#line 1574 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 75: /* target_list  */
#line 170 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_target_vector_and_elements(parser->allocator, &((*yyvaluep).targets)); }
#line 1580 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 76: /* case  */
#line 171 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_case(parser->allocator, &((*yyvaluep).case_)); }
#line 1586 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 77: /* case_list  */
#line 172 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_case_vector_and_elements(parser->allocator, &((*yyvaluep).cases)); }
#line 1592 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 78: /* param_list  */
#line 173 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_type_bindings(parser->allocator, &((*yyvaluep).type_bindings)); }
#line 1598 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 80: /* local_list  */
#line 173 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_type_bindings(parser->allocator, &((*yyvaluep).type_bindings)); }
#line 1604 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 82: /* func_info  */
#line 174 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_func(parser->allocator, ((*yyvaluep).func)); wasm_free(parser->allocator, ((*yyvaluep).func)); }
#line 1610 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 83: /* func  */
#line 174 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_func(parser->allocator, ((*yyvaluep).func)); wasm_free(parser->allocator, ((*yyvaluep).func)); }
#line 1616 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 86: /* segment  */
#line 175 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_segment(parser->allocator, &((*yyvaluep).segment)); }
#line 1622 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 87: /* segment_list  */
#line 176 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_segment_vector_and_elements(parser->allocator, &((*yyvaluep).segments)); }
#line 1628 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 90: /* memory  */
#line 177 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_memory(parser->allocator, &((*yyvaluep).memory)); }
#line 1634 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 91: /* type_def  */
#line 179 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_func_type(parser->allocator, &((*yyvaluep).func_type)); }
#line 1640 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 92: /* table  */
#line 166 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_var_vector_and_elements(parser->allocator, &((*yyvaluep).vars)); }
#line 1646 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 93: /* import  */
#line 180 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_import(parser->allocator, ((*yyvaluep).import)); wasm_free(parser->allocator, ((*yyvaluep).import)); }
#line 1652 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 94: /* export  */
#line 181 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_export(parser->allocator, &((*yyvaluep).export_)); }
#line 1658 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 96: /* module_fields  */
#line 182 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_module_field_vector_and_elements(parser->allocator, &((*yyvaluep).module_fields)); }
#line 1664 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 97: /* module  */
#line 183 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_module(parser->allocator, ((*yyvaluep).module)); wasm_free(parser->allocator, ((*yyvaluep).module)); }
#line 1670 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 98: /* cmd  */
#line 185 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_command(parser->allocator, ((*yyvaluep).command)); wasm_free(parser->allocator, ((*yyvaluep).command)); }
#line 1676 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 99: /* cmd_list  */
#line 186 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_command_vector_and_elements(parser->allocator, &((*yyvaluep).commands)); }
#line 1682 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 102: /* const_list  */
#line 184 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_const_vector(parser->allocator, &((*yyvaluep).consts)); }
#line 1688 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;

    case 103: /* script  */
#line 187 "src/wasm-bison-parser.y" /* yacc.c:1257  */
      { wasm_destroy_script(&((*yyvaluep).script)); }
#line 1694 "src/wasm-bison-parser.c" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (WasmLexer lexer, WasmParser* parser)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined WASM_PARSER_LTYPE_IS_TRIVIAL && WASM_PARSER_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, lexer, parser);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 199 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.types)); }
#line 1988 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 200 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.types) = (yyvsp[-1].types);
      CHECK_ALLOC(wasm_append_type_value(parser->allocator, &(yyval.types), &(yyvsp[0].type)));
    }
#line 1997 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 4:
#line 206 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.func_sig)); }
#line 2003 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 207 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func_sig).result_type = WASM_TYPE_VOID;
      (yyval.func_sig).param_types = (yyvsp[-1].types);
    }
#line 2012 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 211 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func_sig).result_type = (yyvsp[-1].type);
      (yyval.func_sig).param_types = (yyvsp[-5].types);
    }
#line 2021 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 215 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.func_sig)); (yyval.func_sig).result_type = (yyvsp[-1].type); }
#line 2027 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 222 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { DUPTEXT((yyval.text), (yyvsp[0].text)); CHECK_ALLOC_STR((yyval.text)); }
#line 2033 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 223 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { DUPTEXT((yyval.text), (yyvsp[0].text)); CHECK_ALLOC_STR((yyval.text)); }
#line 2039 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 227 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.var).loc = (yylsp[0]);
      (yyval.var).type = WASM_VAR_TYPE_INDEX;
      uint32_t index;
      if (!read_int32((yyvsp[0].text).start, (yyvsp[0].text).start + (yyvsp[0].text).length, &index, 0))
        wasm_parser_error(&(yylsp[0]), lexer, parser, "invalid int %.*s", (yyvsp[0].text).length,
                          (yyvsp[0].text).start);
      (yyval.var).index = index;
    }
#line 2053 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 236 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.var).loc = (yylsp[0]);
      (yyval.var).type = WASM_VAR_TYPE_NAME;
      DUPTEXT((yyval.var).name, (yyvsp[0].text));
      CHECK_ALLOC_STR((yyval.var).name);
    }
#line 2064 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 244 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.vars)); }
#line 2070 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 245 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.vars) = (yyvsp[-1].vars);
      CHECK_ALLOC(wasm_append_var_value(parser->allocator, &(yyval.vars), &(yyvsp[0].var)));
    }
#line 2079 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 251 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { DUPTEXT((yyval.text), (yyvsp[0].text)); CHECK_ALLOC_STR((yyval.text)); }
#line 2085 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 255 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { DUPQUOTEDTEXT((yyval.text), (yyvsp[0].text)); CHECK_ALLOC_STR((yyval.text)); }
#line 2091 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 259 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      CHECK_ALLOC(dup_string_contents(parser->allocator, &(yyvsp[0].text), &(yyval.segment).data,
                                      &(yyval.segment).size));
    }
#line 2100 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 266 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.text)); }
#line 2106 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 267 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.text) = (yyvsp[0].text); }
#line 2112 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 271 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.u64) = 0; }
#line 2118 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 272 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      if (!read_int64((yyvsp[0].text).start, (yyvsp[0].text).start + (yyvsp[0].text).length, &(yyval.u64)))
        wasm_parser_error(&(yylsp[0]), lexer, parser, "invalid offset \"%.*s\"",
                          (yyvsp[0].text).length, (yyvsp[0].text).start);
    }
#line 2128 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 279 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.u32) = WASM_USE_NATURAL_ALIGNMENT; }
#line 2134 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 280 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      if (!read_int32((yyvsp[0].text).start, (yyvsp[0].text).start + (yyvsp[0].text).length, &(yyval.u32), 0))
        wasm_parser_error(&(yylsp[0]), lexer, parser, "invalid alignment \"%.*s\"",
                          (yyvsp[0].text).length, (yyvsp[0].text).start);
    }
#line 2144 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 288 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); (yyval.expr)->loc = (yylsp[-2]); }
#line 2150 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 291 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_empty_expr(parser->allocator, WASM_EXPR_TYPE_NOP);
      CHECK_ALLOC_NULL((yyval.expr));
    }
#line 2159 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 295 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_block_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->block.label = (yyvsp[0].text);
    }
#line 2169 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 300 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_block_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->block.label = (yyvsp[-1].text);
      (yyval.expr)->block.exprs = (yyvsp[0].exprs);
    }
#line 2180 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 306 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_if_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->if_.cond = (yyvsp[-1].expr);
      CHECK_ALLOC(wasm_append_expr_ptr_value(parser->allocator,
                                             &(yyval.expr)->if_.true_.exprs, &(yyvsp[0].expr)));
    }
#line 2192 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 313 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_if_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->if_.cond = (yyvsp[-5].expr);
      (yyval.expr)->if_.true_.label = (yyvsp[-2].text);
      (yyval.expr)->if_.true_.exprs = (yyvsp[-1].exprs);
    }
#line 2204 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 320 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_if_else_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->if_else.cond = (yyvsp[-2].expr);
      CHECK_ALLOC(wasm_append_expr_ptr_value(parser->allocator,
                                             &(yyval.expr)->if_else.true_.exprs, &(yyvsp[-1].expr)));
      CHECK_ALLOC(wasm_append_expr_ptr_value(parser->allocator,
                                             &(yyval.expr)->if_else.false_.exprs, &(yyvsp[0].expr)));
    }
#line 2218 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 329 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_if_else_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->if_else.cond = (yyvsp[-10].expr);
      (yyval.expr)->if_else.true_.label = (yyvsp[-7].text);
      (yyval.expr)->if_else.true_.exprs = (yyvsp[-6].exprs);
      (yyval.expr)->if_else.false_.label = (yyvsp[-2].text);
      (yyval.expr)->if_else.false_.exprs = (yyvsp[-1].exprs);
    }
#line 2232 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 338 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_br_if_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->br_if.var = (yyvsp[-1].var);
      (yyval.expr)->br_if.cond = (yyvsp[0].expr);
    }
#line 2243 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 344 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_br_if_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->br_if.var = (yyvsp[-2].var);
      (yyval.expr)->br_if.expr = (yyvsp[-1].expr);
      (yyval.expr)->br_if.cond = (yyvsp[0].expr);
    }
#line 2255 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 351 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_loop_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      ZERO_MEMORY((yyval.expr)->loop.outer);
      (yyval.expr)->loop.inner = (yyvsp[-1].text);
      (yyval.expr)->loop.exprs = (yyvsp[0].exprs);
    }
#line 2267 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 358 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_loop_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->loop.outer = (yyvsp[-2].text);
      (yyval.expr)->loop.inner = (yyvsp[-1].text);
      (yyval.expr)->loop.exprs = (yyvsp[0].exprs);
    }
#line 2279 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 365 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_br_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->br.var.loc = (yylsp[-1]);
      (yyval.expr)->br.var.type = WASM_VAR_TYPE_INDEX;
      (yyval.expr)->br.var.index = 0;
      (yyval.expr)->br.expr = (yyvsp[0].expr);
    }
#line 2292 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 373 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_br_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->br.var = (yyvsp[-1].var);
      (yyval.expr)->br.expr = (yyvsp[0].expr);
    }
#line 2303 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 379 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_return_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->return_.expr = (yyvsp[0].expr);
    }
#line 2313 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 384 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_tableswitch_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->tableswitch.label = (yyvsp[-7].text);
      (yyval.expr)->tableswitch.expr = (yyvsp[-6].expr);
      (yyval.expr)->tableswitch.targets = (yyvsp[-3].targets);
      (yyval.expr)->tableswitch.default_target = (yyvsp[-1].target);
      (yyval.expr)->tableswitch.cases = (yyvsp[0].cases);

      int i;
      for (i = 0; i < (yyval.expr)->tableswitch.cases.size; ++i) {
        WasmCase* case_ = &(yyval.expr)->tableswitch.cases.data[i];
        if (case_->label.start) {
          WasmBinding* binding = wasm_insert_binding(
              parser->allocator, &(yyval.expr)->tableswitch.case_bindings, &case_->label);
          CHECK_ALLOC_NULL(binding);
          binding->loc = case_->loc;
          binding->index = i;
        }
      }
    }
#line 2339 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 405 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_call_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->call.var = (yyvsp[-1].var);
      (yyval.expr)->call.args = (yyvsp[0].exprs);
    }
#line 2350 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 411 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_call_import_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->call.var = (yyvsp[-1].var);
      (yyval.expr)->call.args = (yyvsp[0].exprs);
    }
#line 2361 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 417 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_call_indirect_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->call_indirect.var = (yyvsp[-2].var);
      (yyval.expr)->call_indirect.expr = (yyvsp[-1].expr);
      (yyval.expr)->call_indirect.args = (yyvsp[0].exprs);
    }
#line 2373 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 424 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_get_local_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->get_local.var = (yyvsp[0].var);
    }
#line 2383 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 429 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_set_local_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->set_local.var = (yyvsp[-1].var);
      (yyval.expr)->set_local.expr = (yyvsp[0].expr);
    }
#line 2394 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 435 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_load_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->load.op = (yyvsp[-3].mem);
      (yyval.expr)->load.offset = (yyvsp[-2].u64);
      (yyval.expr)->load.align = (yyvsp[-1].u32);
      (yyval.expr)->load.addr = (yyvsp[0].expr);
    }
#line 2407 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 443 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_store_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->store.op = (yyvsp[-4].mem);
      (yyval.expr)->store.offset = (yyvsp[-3].u64);
      (yyval.expr)->store.align = (yyvsp[-2].u32);
      (yyval.expr)->store.addr = (yyvsp[-1].expr);
      (yyval.expr)->store.value = (yyvsp[0].expr);
    }
#line 2421 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 452 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_const_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->const_.loc = (yylsp[-1]);
      if (!read_const((yyvsp[-1].type), (yyvsp[0].text).start, (yyvsp[0].text).start + (yyvsp[0].text).length, &(yyval.expr)->const_))
        wasm_parser_error(&(yylsp[0]), lexer, parser, "invalid literal \"%.*s\"",
                          (yyvsp[0].text).length, (yyvsp[0].text).start);
      wasm_free(parser->allocator, (char*)(yyvsp[0].text).start);
    }
#line 2435 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 461 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_unary_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->unary.op = (yyvsp[-1].unary);
      (yyval.expr)->unary.expr = (yyvsp[0].expr);
    }
#line 2446 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 467 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_binary_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->binary.op = (yyvsp[-2].binary);
      (yyval.expr)->binary.left = (yyvsp[-1].expr);
      (yyval.expr)->binary.right = (yyvsp[0].expr);
    }
#line 2458 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 474 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_select_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->select.true_ = (yyvsp[-2].expr);
      (yyval.expr)->select.false_ = (yyvsp[-1].expr);
      (yyval.expr)->select.cond = (yyvsp[0].expr);
    }
#line 2470 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 481 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_compare_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->compare.op = (yyvsp[-2].compare);
      (yyval.expr)->compare.left = (yyvsp[-1].expr);
      (yyval.expr)->compare.right = (yyvsp[0].expr);
    }
#line 2482 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 488 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_convert_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->convert.op = (yyvsp[-1].convert);
      (yyval.expr)->convert.expr = (yyvsp[0].expr);
    }
#line 2493 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 494 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_empty_expr(parser->allocator, WASM_EXPR_TYPE_UNREACHABLE);
      CHECK_ALLOC_NULL((yyval.expr));
    }
#line 2502 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 498 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_empty_expr(parser->allocator, WASM_EXPR_TYPE_MEMORY_SIZE);
      CHECK_ALLOC_NULL((yyval.expr));
    }
#line 2511 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 502 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.expr) = wasm_new_grow_memory_expr(parser->allocator);
      CHECK_ALLOC_NULL((yyval.expr));
      (yyval.expr)->grow_memory.expr = (yyvsp[0].expr);
    }
#line 2521 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 509 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.expr) = NULL; }
#line 2527 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 513 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      ZERO_MEMORY((yyval.exprs));
      CHECK_ALLOC(wasm_append_expr_ptr_value(parser->allocator, &(yyval.exprs), &(yyvsp[0].expr)));
    }
#line 2536 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 517 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.exprs) = (yyvsp[-1].exprs);
      CHECK_ALLOC(wasm_append_expr_ptr_value(parser->allocator, &(yyval.exprs), &(yyvsp[0].expr)));
    }
#line 2545 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 523 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.exprs)); }
#line 2551 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 528 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.target).type = WASM_TARGET_TYPE_CASE;
      (yyval.target).var = (yyvsp[-1].var);
    }
#line 2560 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 532 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.target).type = WASM_TARGET_TYPE_BR;
      (yyval.target).var = (yyvsp[-1].var);
    }
#line 2569 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 538 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.targets)); }
#line 2575 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 539 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.targets) = (yyvsp[-1].targets);
      CHECK_ALLOC(wasm_append_target_value(parser->allocator, &(yyval.targets), &(yyvsp[0].target)));
    }
#line 2584 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 545 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.case_).label); (yyval.case_).exprs = (yyvsp[-1].exprs); }
#line 2590 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 546 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.case_).label = (yyvsp[-2].text); (yyval.case_).exprs = (yyvsp[-1].exprs); }
#line 2596 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 549 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.cases)); }
#line 2602 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 550 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.cases) = (yyvsp[-1].cases);
      CHECK_ALLOC(wasm_append_case_value(parser->allocator, &(yyval.cases), &(yyvsp[0].case_)));
    }
#line 2611 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 560 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      ZERO_MEMORY((yyval.type_bindings));
      CHECK_ALLOC(wasm_extend_types(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].types)));
      wasm_destroy_type_vector(parser->allocator, &(yyvsp[-1].types));
    }
#line 2621 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 70:
#line 565 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      ZERO_MEMORY((yyval.type_bindings));
      WasmBinding* binding =
          wasm_insert_binding(parser->allocator, &(yyval.type_bindings).bindings, &(yyvsp[-2].text));
      CHECK_ALLOC_NULL(binding);
      binding->loc = (yylsp[-3]);
      binding->index = (yyval.type_bindings).types.size;
      CHECK_ALLOC(wasm_append_type_value(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].type)));
    }
#line 2635 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 574 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.type_bindings) = (yyvsp[-4].type_bindings);
      CHECK_ALLOC(wasm_extend_types(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].types)));
      wasm_destroy_type_vector(parser->allocator, &(yyvsp[-1].types));
    }
#line 2645 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 579 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.type_bindings) = (yyvsp[-5].type_bindings);
      WasmBinding* binding =
          wasm_insert_binding(parser->allocator, &(yyval.type_bindings).bindings, &(yyvsp[-2].text));
      CHECK_ALLOC_NULL(binding);
      binding->loc = (yylsp[-3]);
      binding->index = (yyval.type_bindings).types.size;
      CHECK_ALLOC(wasm_append_type_value(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].type)));
    }
#line 2659 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 590 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 2665 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 593 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      ZERO_MEMORY((yyval.type_bindings));
      CHECK_ALLOC(wasm_extend_types(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].types)));
      wasm_destroy_type_vector(parser->allocator, &(yyvsp[-1].types));
    }
#line 2675 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 598 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      ZERO_MEMORY((yyval.type_bindings));
      WasmBinding* binding =
          wasm_insert_binding(parser->allocator, &(yyval.type_bindings).bindings, &(yyvsp[-2].text));
      CHECK_ALLOC_NULL(binding);
      binding->loc = (yylsp[-3]);
      binding->index = (yyval.type_bindings).types.size;
      CHECK_ALLOC(wasm_append_type_value(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].type)));
    }
#line 2689 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 607 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.type_bindings) = (yyvsp[-4].type_bindings);
      CHECK_ALLOC(wasm_extend_types(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].types)));
      wasm_destroy_type_vector(parser->allocator, &(yyvsp[-1].types));
    }
#line 2699 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 612 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.type_bindings) = (yyvsp[-5].type_bindings);
      WasmBinding* binding =
          wasm_insert_binding(parser->allocator, &(yyval.type_bindings).bindings, &(yyvsp[-2].text));
      CHECK_ALLOC_NULL(binding);
      binding->loc = (yylsp[-3]);
      binding->index = (yyval.type_bindings).types.size;
      CHECK_ALLOC(wasm_append_type_value(parser->allocator, &(yyval.type_bindings).types, &(yyvsp[-1].type)));
    }
#line 2713 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 623 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 2719 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 626 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
    }
#line 2728 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 630 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[0].text);
    }
#line 2738 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 635 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->name = (yyvsp[-1].text);
      (yyval.func)->type_var = (yyvsp[0].var);
    }
#line 2749 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 641 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->params = (yyvsp[0].type_bindings);
    }
#line 2761 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 648 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 2774 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 656 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-4].text);
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 2788 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 665 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-5].text);
      (yyval.func)->type_var = (yyvsp[-4].var);
      (yyval.func)->params = (yyvsp[-3].type_bindings);
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2803 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 675 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-4].text);
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2817 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 684 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 2830 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 692 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-4].text);
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2844 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 701 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2857 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 709 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 2869 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 716 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 2882 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 724 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-4].text);
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2896 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 733 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2909 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 741 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 2921 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 748 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2934 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 756 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2946 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 763 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-1].text);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 2957 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 769 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 2969 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 776 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-1].text);
      (yyval.func)->params = (yyvsp[0].type_bindings);
    }
#line 2980 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 782 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 2992 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 789 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3005 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 797 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-4].text);
      (yyval.func)->params = (yyvsp[-3].type_bindings);
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3019 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 103:
#line 806 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3032 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 814 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3044 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 821 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3057 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 829 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3069 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 836 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-1].text);
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 3080 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 842 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3092 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 849 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-3].text);
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3105 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 857 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-2].text);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3117 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 864 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->name = (yyvsp[-1].text);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3128 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 870 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->type_var = (yyvsp[0].var);
    }
#line 3138 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 875 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->params = (yyvsp[0].type_bindings);
    }
#line 3149 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 881 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 3161 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 888 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3174 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 896 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-4].var);
      (yyval.func)->params = (yyvsp[-3].type_bindings);
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3188 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 905 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3201 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 913 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3213 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 920 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3226 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 928 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3238 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 935 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 3249 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 941 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3261 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 948 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-3].var);
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3274 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 956 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE | WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3286 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 963 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3297 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 969 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->type_var = (yyvsp[-2].var);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3309 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 127:
#line 976 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_FUNC_TYPE;
      (yyval.func)->type_var = (yyvsp[-1].var);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3320 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 982 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[0].type_bindings);
    }
#line 3330 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 987 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 3341 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 993 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3353 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1000 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[-3].type_bindings);
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3366 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1008 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3378 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1015 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3389 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1021 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[-2].type_bindings);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3401 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1028 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->params = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3412 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1034 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->result_type = (yyvsp[0].type);
    }
#line 3422 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1039 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3433 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1045 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->result_type = (yyvsp[-2].type);
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3445 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1052 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->result_type = (yyvsp[-1].type);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3456 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1058 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->locals = (yyvsp[0].type_bindings);
    }
#line 3466 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1063 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->locals = (yyvsp[-1].type_bindings);
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3477 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1069 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func) = new_func(parser->allocator);
      (yyval.func)->flags = WASM_FUNC_FLAG_HAS_SIGNATURE;
      (yyval.func)->exprs = (yyvsp[0].exprs);
    }
#line 3487 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1076 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.func) = (yyvsp[-1].func); (yyval.func)->loc = (yylsp[-2]); }
#line 3493 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1082 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 3499 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1086 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      if (!read_int32((yyvsp[0].text).start, (yyvsp[0].text).start + (yyvsp[0].text).length, &(yyval.u32), 0))
        wasm_parser_error(&(yylsp[0]), lexer, parser,
                          "invalid memory segment address \"%.*s\"", (yyvsp[0].text).length,
                          (yyvsp[0].text).start);
    }
#line 3510 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1095 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.segment).loc = (yylsp[-3]);
      (yyval.segment).data = (yyvsp[-1].segment).data;
      (yyval.segment).size = (yyvsp[-1].segment).size;
      (yyval.segment).addr = (yyvsp[-2].u32);
    }
#line 3521 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1103 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.segments)); }
#line 3527 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1104 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.segments) = (yyvsp[-1].segments);
      CHECK_ALLOC(wasm_append_segment_value(parser->allocator, &(yyval.segments), &(yyvsp[0].segment)));
    }
#line 3536 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1111 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      if (!read_int32((yyvsp[0].text).start, (yyvsp[0].text).start + (yyvsp[0].text).length, &(yyval.u32), 0))
        wasm_parser_error(&(yylsp[0]), lexer, parser,
                          "invalid initial memory size \"%.*s\"", (yyvsp[0].text).length,
                          (yyvsp[0].text).start);
    }
#line 3547 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1120 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      if (!read_int32((yyvsp[0].text).start, (yyvsp[0].text).start + (yyvsp[0].text).length, &(yyval.u32), 0))
        wasm_parser_error(&(yylsp[0]), lexer, parser,
                          "invalid max memory size \"%.*s\"", (yyvsp[0].text).length,
                          (yyvsp[0].text).start);
    }
#line 3558 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1129 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.memory).loc = (yylsp[-4]);
      (yyval.memory).initial_size = (yyvsp[-3].u32);
      (yyval.memory).max_size = (yyvsp[-2].u32);
      (yyval.memory).segments = (yyvsp[-1].segments);
    }
#line 3569 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1135 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.memory).loc = (yylsp[-3]);
      (yyval.memory).initial_size = (yyvsp[-2].u32);
      (yyval.memory).max_size = (yyval.memory).initial_size;
      (yyval.memory).segments = (yyvsp[-1].segments);
    }
#line 3580 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1144 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      ZERO_MEMORY((yyval.func_type));
      (yyval.func_type).sig = (yyvsp[-2].func_sig);
    }
#line 3589 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1148 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.func_type).name = (yyvsp[-5].text);
      (yyval.func_type).sig = (yyvsp[-2].func_sig);
    }
#line 3598 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1155 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.vars) = (yyvsp[-1].vars); }
#line 3604 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1159 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.import) = new_import(parser->allocator);
      (yyval.import)->import_type = WASM_IMPORT_HAS_TYPE;
      (yyval.import)->module_name = (yyvsp[-3].text);
      (yyval.import)->func_name = (yyvsp[-2].text);
      (yyval.import)->type_var = (yyvsp[-1].var);
    }
#line 3616 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1166 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.import) = new_import(parser->allocator);
      (yyval.import)->import_type = WASM_IMPORT_HAS_TYPE;
      (yyval.import)->name = (yyvsp[-4].text);
      (yyval.import)->module_name = (yyvsp[-3].text);
      (yyval.import)->func_name = (yyvsp[-2].text);
      (yyval.import)->type_var = (yyvsp[-1].var);
    }
#line 3629 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1174 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.import) = new_import(parser->allocator);
      (yyval.import)->import_type = WASM_IMPORT_HAS_FUNC_SIGNATURE;
      (yyval.import)->module_name = (yyvsp[-3].text);
      (yyval.import)->func_name = (yyvsp[-2].text);
      (yyval.import)->func_sig = (yyvsp[-1].func_sig);
    }
#line 3641 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1181 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.import) = new_import(parser->allocator);
      (yyval.import)->import_type = WASM_IMPORT_HAS_FUNC_SIGNATURE;
      (yyval.import)->name = (yyvsp[-4].text);
      (yyval.import)->module_name = (yyvsp[-3].text);
      (yyval.import)->func_name = (yyvsp[-2].text);
      (yyval.import)->func_sig = (yyvsp[-1].func_sig);
    }
#line 3654 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1192 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.export_).name = (yyvsp[-2].text);
      (yyval.export_).var = (yyvsp[-1].var);
    }
#line 3663 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1199 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.export_memory).name = (yyvsp[-2].text);
    }
#line 3671 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1205 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.module_fields)); }
#line 3677 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1206 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_FUNC;
      field->func = *(yyvsp[0].func);
      wasm_free(parser->allocator, (yyvsp[0].func));
    }
#line 3691 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1215 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_IMPORT;
      field->import = *(yyvsp[0].import);
      wasm_free(parser->allocator, (yyvsp[0].import));
    }
#line 3705 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1224 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_EXPORT;
      field->export_ = (yyvsp[0].export_);
    }
#line 3718 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1232 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_EXPORT_MEMORY;
      field->export_memory = (yyvsp[0].export_memory);
    }
#line 3731 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1240 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_TABLE;
      field->table = (yyvsp[0].vars);
    }
#line 3744 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1248 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_FUNC_TYPE;
      field->func_type = (yyvsp[0].func_type);
    }
#line 3757 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1256 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_MEMORY;
      field->memory = (yyvsp[0].memory);
    }
#line 3770 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1264 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module_fields) = (yyvsp[-1].module_fields);
      WasmModuleField* field = wasm_append_module_field(parser->allocator, &(yyval.module_fields));
      CHECK_ALLOC_NULL(field);
      field->loc = (yylsp[0]);
      field->type = WASM_MODULE_FIELD_TYPE_START;
      field->start = (yyvsp[0].var);
    }
#line 3783 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1274 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.module) = new_module(parser->allocator);
      (yyval.module)->loc = (yylsp[-2]);
      (yyval.module)->fields = (yyvsp[-1].module_fields);
      /* clear the start function */
      (yyval.module)->start.type = WASM_VAR_TYPE_INDEX;
      (yyval.module)->start.index = -1;

      /* cache values */
      int i;
      for (i = 0; i < (yyval.module)->fields.size; ++i) {
        WasmModuleField* field = &(yyval.module)->fields.data[i];
        switch (field->type) {
          case WASM_MODULE_FIELD_TYPE_FUNC: {
            WasmFuncPtr func_ptr = &field->func;
            CHECK_ALLOC(wasm_append_func_ptr_value(parser->allocator,
                                                   &(yyval.module)->funcs, &func_ptr));
            if (field->func.name.start) {
              WasmBinding* binding = wasm_insert_binding(
                  parser->allocator, &(yyval.module)->func_bindings, &field->func.name);
              CHECK_ALLOC_NULL(binding);
              binding->loc = field->loc;
              binding->index = (yyval.module)->funcs.size - 1;
            }
            break;
          }
          case WASM_MODULE_FIELD_TYPE_IMPORT: {
            WasmImportPtr import_ptr = &field->import;
            CHECK_ALLOC(wasm_append_import_ptr_value(
                parser->allocator, &(yyval.module)->imports, &import_ptr));
            if (field->import.name.start) {
              WasmBinding* binding = wasm_insert_binding(
                  parser->allocator, &(yyval.module)->import_bindings, &field->import.name);
              CHECK_ALLOC_NULL(binding);
              binding->loc = field->loc;
              binding->index = (yyval.module)->imports.size - 1;
            }
            break;
          }
          case WASM_MODULE_FIELD_TYPE_EXPORT: {
            WasmExportPtr export_ptr = &field->export_;
            CHECK_ALLOC(wasm_append_export_ptr_value(
                parser->allocator, &(yyval.module)->exports, &export_ptr));
            if (field->export_.name.start) {
              WasmBinding* binding =
                  wasm_insert_binding(parser->allocator, &(yyval.module)->export_bindings,
                                      &field->export_.name);
              CHECK_ALLOC_NULL(binding);
              binding->loc = field->loc;
              binding->index = (yyval.module)->exports.size - 1;
            }
            break;
          }
          case WASM_MODULE_FIELD_TYPE_EXPORT_MEMORY:
            (yyval.module)->export_memory = &field->export_memory;
            break;
          case WASM_MODULE_FIELD_TYPE_TABLE:
            (yyval.module)->table = &field->table;
            break;
          case WASM_MODULE_FIELD_TYPE_FUNC_TYPE: {
            WasmFuncTypePtr func_type_ptr = &field->func_type;
            CHECK_ALLOC(wasm_append_func_type_ptr_value(
                parser->allocator, &(yyval.module)->func_types, &func_type_ptr));
            if (field->func_type.name.start) {
              WasmBinding* binding = wasm_insert_binding(
                  parser->allocator, &(yyval.module)->func_type_bindings,
                  &field->func_type.name);
              CHECK_ALLOC_NULL(binding);
              binding->loc = field->loc;
              binding->index = (yyval.module)->func_types.size - 1;
            }
            break;
          }
          case WASM_MODULE_FIELD_TYPE_MEMORY:
            (yyval.module)->memory = &field->memory;
            break;
          case WASM_MODULE_FIELD_TYPE_START:
            (yyval.module)->start = field->start;
            break;
        }
      }
    }
#line 3870 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1362 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.command) = new_command(parser->allocator);
      (yyval.command)->type = WASM_COMMAND_TYPE_MODULE;
      (yyval.command)->module = *(yyvsp[0].module);
      wasm_free(parser->allocator, (yyvsp[0].module));
    }
#line 3881 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1368 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.command) = new_command(parser->allocator);
      (yyval.command)->type = WASM_COMMAND_TYPE_INVOKE;
      (yyval.command)->invoke.loc = (yylsp[-3]);
      (yyval.command)->invoke.name = (yyvsp[-2].text);
      (yyval.command)->invoke.args = (yyvsp[-1].consts);
    }
#line 3893 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1375 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.command) = new_command(parser->allocator);
      (yyval.command)->type = WASM_COMMAND_TYPE_ASSERT_INVALID;
      (yyval.command)->assert_invalid.module = *(yyvsp[-2].module);
      (yyval.command)->assert_invalid.text = (yyvsp[-1].text);
      wasm_free(parser->allocator, (yyvsp[-2].module));
    }
#line 3905 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1382 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.command) = new_command(parser->allocator);
      (yyval.command)->type = WASM_COMMAND_TYPE_ASSERT_RETURN;
      (yyval.command)->assert_return.invoke.loc = (yylsp[-5]);
      (yyval.command)->assert_return.invoke.name = (yyvsp[-4].text);
      (yyval.command)->assert_return.invoke.args = (yyvsp[-3].consts);
      (yyval.command)->assert_return.expected = (yyvsp[-1].const_);
    }
#line 3918 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1390 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.command) = new_command(parser->allocator);
      (yyval.command)->type = WASM_COMMAND_TYPE_ASSERT_RETURN_NAN;
      (yyval.command)->assert_return_nan.invoke.loc = (yylsp[-4]);
      (yyval.command)->assert_return_nan.invoke.name = (yyvsp[-3].text);
      (yyval.command)->assert_return_nan.invoke.args = (yyvsp[-2].consts);
    }
#line 3930 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1397 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.command) = new_command(parser->allocator);
      (yyval.command)->type = WASM_COMMAND_TYPE_ASSERT_TRAP;
      (yyval.command)->assert_trap.invoke.loc = (yylsp[-5]);
      (yyval.command)->assert_trap.invoke.name = (yyvsp[-4].text);
      (yyval.command)->assert_trap.invoke.args = (yyvsp[-3].consts);
      (yyval.command)->assert_trap.text = (yyvsp[-1].text);
    }
#line 3943 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1407 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.commands)); }
#line 3949 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1408 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.commands) = (yyvsp[-1].commands);
      CHECK_ALLOC(wasm_append_command_value(parser->allocator, &(yyval.commands), (yyvsp[0].command)));
      wasm_free(parser->allocator, (yyvsp[0].command));
    }
#line 3959 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1416 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.const_).loc = (yylsp[-2]);
      if (!read_const((yyvsp[-2].type), (yyvsp[-1].text).start, (yyvsp[-1].text).start + (yyvsp[-1].text).length, &(yyval.const_)))
        wasm_parser_error(&(yylsp[-1]), lexer, parser, "invalid literal \"%.*s\"",
                          (yyvsp[-1].text).length, (yyvsp[-1].text).start);
      wasm_free(parser->allocator, (char*)(yyvsp[-1].text).start);
    }
#line 3971 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1425 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { (yyval.const_).type = WASM_TYPE_VOID; }
#line 3977 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1429 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    { ZERO_MEMORY((yyval.consts)); }
#line 3983 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1430 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.consts) = (yyvsp[-1].consts);
      CHECK_ALLOC(wasm_append_const_value(parser->allocator, &(yyval.consts), &(yyvsp[0].const_)));
    }
#line 3992 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1437 "src/wasm-bison-parser.y" /* yacc.c:1646  */
    {
      (yyval.script).commands = (yyvsp[0].commands);
      parser->script = (yyval.script);
    }
#line 4001 "src/wasm-bison-parser.c" /* yacc.c:1646  */
    break;


#line 4005 "src/wasm-bison-parser.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, lexer, parser, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, lexer, parser, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, lexer, parser);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, lexer, parser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, lexer, parser, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, lexer, parser);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, lexer, parser);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1449 "src/wasm-bison-parser.y" /* yacc.c:1906  */


void wasm_parser_error(WasmLocation* loc,
                       WasmLexer lexer,
                       WasmParser* parser,
                       const char* fmt,
                       ...) {
  parser->errors++;
  va_list args;
  va_start(args, fmt);
  wasm_vfprint_error(stderr, loc, lexer, fmt, args);
  va_end(args);
}

static int hexdigit(char c, uint32_t* out) {
  if ((unsigned int)(c - '0') <= 9) {
    *out = c - '0';
    return 1;
  } else if ((unsigned int)(c - 'a') <= 6) {
    *out = 10 + (c - 'a');
    return 1;
  } else if ((unsigned int)(c - 'A') <= 6) {
    *out = 10 + (c - 'A');
    return 1;
  }
  return 0;
}

/* return 1 if the non-NULL-terminated string starting with |start| and ending
 with |end| starts with the NULL-terminated string |prefix|. */
static int string_starts_with(const char* start,
                              const char* end,
                              const char* prefix) {
  while (start < end && *prefix) {
    if (*start != *prefix)
      return 0;
    start++;
    prefix++;
  }
  return *prefix == 0;
}

static int read_uint64(const char* s, const char* end, uint64_t* out) {
  if (s == end)
    return 0;
  uint64_t value = 0;
  if (*s == '0' && s + 1 < end && s[1] == 'x') {
    s += 2;
    if (s == end)
      return 0;
    for (; s < end; ++s) {
      uint32_t digit;
      if (!hexdigit(*s, &digit))
        return 0;
      uint64_t old_value = value;
      value = value * 16 + digit;
      /* check for overflow */
      if (old_value > value)
        return 0;
    }
  } else {
    for (; s < end; ++s) {
      uint32_t digit = (*s - '0');
      if (digit > 9)
        return 0;
      uint64_t old_value = value;
      value = value * 10 + digit;
      /* check for overflow */
      if (old_value > value)
        return 0;
    }
  }
  if (s != end)
    return 0;
  *out = value;
  return 1;
}

static int read_int64(const char* s, const char* end, uint64_t* out) {
  int has_sign = 0;
  if (*s == '-') {
    has_sign = 1;
    s++;
  }
  uint64_t value = 0;
  int result = read_uint64(s, end, &value);
  if (has_sign) {
    if (value > (uint64_t)INT64_MAX + 1) /* abs(INT64_MIN) == INT64_MAX + 1 */
      return 0;
    value = UINT64_MAX - value + 1;
  }
  *out = value;
  return result;
}

static int read_int32(const char* s,
                      const char* end,
                      uint32_t* out,
                      int allow_signed) {
  uint64_t value;
  int has_sign = 0;
  if (*s == '-') {
    if (!allow_signed)
      return 0;
    has_sign = 1;
    s++;
  }
  if (!read_uint64(s, end, &value))
    return 0;

  if (has_sign) {
    if (value > (uint64_t)INT32_MAX + 1) /* abs(INT32_MIN) == INT32_MAX + 1 */
      return 0;
    value = UINT32_MAX - value + 1;
  } else {
    if (value > (uint64_t)UINT32_MAX)
      return 0;
  }
  *out = (uint32_t)value;
  return 1;
}

static int read_float_nan(const char* s, const char* end, float* out) {
  int is_neg = 0;
  if (*s == '-') {
    is_neg = 1;
    s++;
  } else if (*s == '+') {
    s++;
  }
  if (!string_starts_with(s, end, "nan"))
    return 0;
  s += 3;

  uint32_t tag;
  if (s != end) {
    tag = 0;
    if (!string_starts_with(s, end, ":0x"))
      return 0;
    s += 3;

    for (; s < end; ++s) {
      uint32_t digit;
      if (!hexdigit(*s, &digit))
        return 0;
      tag = tag * 16 + digit;
      /* check for overflow */
      const uint32_t max_tag = 0x7fffff;
      if (tag > max_tag)
        return 0;
    }

    /* NaN cannot have a zero tag, that is reserved for infinity */
    if (tag == 0)
      return 0;
  } else {
    /* normal quiet NaN */
    tag = 0x400000;
  }

  uint32_t bits = 0x7f800000 | tag;
  if (is_neg)
    bits |= 0x80000000U;
  memcpy(out, &bits, sizeof(*out));
  return 1;
}

static int read_float(const char* s, const char* end, float* out) {
  if (read_float_nan(s, end, out))
    return 1;

  errno = 0;
  char* endptr;
  float value;
  value = strtof(s, &endptr);
  if (endptr != end ||
      ((value == 0 || value == HUGE_VALF || value == -HUGE_VALF) && errno != 0))
    return 0;

  *out = value;
  return 1;
}

static int read_double_nan(const char* s, const char* end, double* out) {
  int is_neg = 0;
  if (*s == '-') {
    is_neg = 1;
    s++;
  } else if (*s == '+') {
    s++;
  }
  if (!string_starts_with(s, end, "nan"))
    return 0;
  s += 3;

  uint64_t tag;
  if (s != end) {
    tag = 0;
    if (!string_starts_with(s, end, ":0x"))
      return 0;
    s += 3;

    for (; s < end; ++s) {
      uint32_t digit;
      if (!hexdigit(*s, &digit))
        return 0;
      tag = tag * 16 + digit;
      /* check for overflow */
      const uint64_t max_tag = 0xfffffffffffffULL;
      if (tag > max_tag)
        return 0;
    }

    /* NaN cannot have a zero tag, that is reserved for infinity */
    if (tag == 0)
      return 0;
  } else {
    /* normal quiet NaN */
    tag = 0x8000000000000ULL;
  }

  uint64_t bits = 0x7ff0000000000000ULL | tag;
  if (is_neg)
    bits |= 0x8000000000000000ULL;
  memcpy(out, &bits, sizeof(*out));
  return 1;
}

static int read_double(const char* s, const char* end, double* out) {
  if (read_double_nan(s, end, out))
    return 1;

  errno = 0;
  char* endptr;
  double value;
  value = strtod(s, &endptr);
  if (endptr != end ||
      ((value == 0 || value == HUGE_VAL || value == -HUGE_VAL) && errno != 0))
    return 0;

  *out = value;
  return 1;
}

static int read_const(WasmType type,
                      const char* s,
                      const char* end,
                      WasmConst* out) {
  out->type = type;
  switch (type) {
    case WASM_TYPE_I32:
      return read_int32(s, end, &out->u32, 1);
    case WASM_TYPE_I64:
      return read_int64(s, end, &out->u64);
    case WASM_TYPE_F32:
      return read_float(s, end, &out->f32);
    case WASM_TYPE_F64:
      return read_double(s, end, &out->f64);
    default:
      assert(0);
      break;
  }
  return 0;
}

static size_t copy_string_contents(WasmStringSlice* text,
                                   char* dest,
                                   size_t size) {
  const char* src = text->start + 1;
  const char* end = text->start + text->length - 1;

  char* dest_start = dest;

  while (src < end) {
    if (*src == '\\') {
      src++;
      switch (*src) {
        case 'n':
          *dest++ = '\n';
          break;
        case 't':
          *dest++ = '\t';
          break;
        case '\\':
          *dest++ = '\\';
          break;
        case '\'':
          *dest++ = '\'';
          break;
        case '\"':
          *dest++ = '\"';
          break;
        default: {
          /* The string should be validated already, so we know this is a hex
           * sequence */
          uint32_t hi;
          uint32_t lo;
          if (!hexdigit(src[0], &hi) || !hexdigit(src[1], &lo))
            assert(0);
          *dest++ = (hi << 4) | lo;
          src++;
          break;
        }
      }
      src++;
    } else {
      *dest++ = *src++;
    }
  }
  /* return the data length */
  return dest - dest_start;
}

static WasmResult dup_string_contents(WasmAllocator* allocator,
                                      WasmStringSlice* text,
                                      void** out_data,
                                      size_t* out_size) {
  const char* src = text->start + 1;
  const char* end = text->start + text->length - 1;
  /* Always allocate enough space for the entire string including the escape
   * characters. It will only get shorter, and this way we only have to iterate
   * through the string once. */
  size_t size = end - src;
  char* result = wasm_alloc(allocator, size, 1);
  if (!result)
    return WASM_ERROR;
  size_t actual_size = copy_string_contents(text, result, size);
  *out_data = result;
  *out_size = actual_size;
  return WASM_OK;
}

WasmResult wasm_parse(WasmLexer lexer, struct WasmScript* out_script) {
  WasmParser parser;
  ZERO_MEMORY(parser);
  WasmAllocator* allocator = wasm_lexer_get_allocator(lexer);
  parser.allocator = allocator;
  out_script->allocator = allocator;
  int result = wasm_parser_parse(lexer, &parser);
  out_script->commands = parser.script.commands;
  return result == 0 && parser.errors == 0 ? WASM_OK : WASM_ERROR;
}