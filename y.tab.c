/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
#include <stdlib.h>
#include <string.h>
#include <tuple>

using std::string;
using std::getline;
//colocar na tabela uma variavel pra verificar se a mesma foi inicializada ou nao

#define YYSTYPE atributos
using namespace std;

typedef struct Vector{
	//vector<string> variaveis;
	string tmVetor;
	string isVector;
	string tmp;
} Vector;

typedef struct Variable{
	Vector vetor;
	string tipo;
	string nome;
	string valor;
	string tmp;
} variable;

typedef struct Temps{
	string valor;
	string tmp;
} temps;

typedef struct Execucao {
	string Inicio;
	string Fim;
} Execucao;

typedef struct Atributos{
	string tipo;
	string label;
	string traducao_dec;
	string traducao;
	string tmp;
	string operacao;
} atributos;

typedef struct Function{
	//atributos bloco;
	string argumentos;
	string nome;
	string retorno;
} Function;

typedef struct{
	string implicita; //tradução após conversão
	string nomeVar; //nome da variável
	string varConvertida; //nome da variável que foi convertida
} structAux; //struct auxiliar utilizada para conversões

//variaveis
int valorVar = 1;//Gerador de tmp
int valorBlock = 0;//Gerador de blocos
int mapAtual = 0;//Contador de mapas
int entryMain = 0;//variável para indicar quando entrar na main
int entryFunc = 0;//variável para indicar quando entrar em função
variable auxiliar;//Auxiliar que retorna uma struct vazia de variable
vector<vector<variable>>globalTabSym;//Tabela de variáveis global
vector<string> auxArray;//Vetor que retorna o nome/valor dos itens adicionados no vetor
vector<string> auxArrayTmp;//Vetor que irá retornar todas as tmps de quando um vetor for criado
stack<Execucao> loops;//Pilha de contador de contextos
vector<Function> funcoes;//Vetor que armazena uma struct que possui tipo de retorno,nome e os argumentos passados de uma função
Function funcaoAux;//Auxiliar que retorna uma struct de funcao vazia caso não ache uma determinada função no vetor de funções
string tipoRetorno;//string que irá retornar o tipo do comando return de uma função, para depois ser verificado se o tipo bate com o tipo da função


//funções yacc
int yylex(void);
void yyerror(string);
void criaOperacao(atributos *dolardolar, atributos dolar1, atributos dolar3, string operacao);
bool verifyVariableLocal(string nome);
bool verifyVariableGlobal(string nome);
bool verifyFunction(string nome);
variable *returnVariable(string nome);
Function *returnFunction(string nome);
Execucao criaBloco(string inicio, string fim);

//função geradora de tmps
string genLabel();
Execucao genBlock(string);


#line 169 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_MAIN = 258,
    TK_INPUT = 259,
    TK_SAIDA = 260,
    TK_WHILE = 261,
    TK_DO = 262,
    TK_FOR = 263,
    TK_IF = 264,
    TK_ELSE = 265,
    TK_END_LOOP = 266,
    TK_ID = 267,
    TK_DEC_VAR = 268,
    TK_GLOBAL_VAR = 269,
    TK_TIPO_VOID = 270,
    TK_TIPO_CHAR = 271,
    TK_TIPO_INT = 272,
    TK_TIPO_FLOAT = 273,
    TK_COMENTARIO = 274,
    TK_UN_SUM = 275,
    TK_UN_SUB = 276,
    TK_LESS = 277,
    TK_GREATER = 278,
    TK_LE = 279,
    TK_HE = 280,
    TK_EQ = 281,
    TK_DIFF = 282,
    TK_NOT = 283,
    TK_AND = 284,
    TK_OR = 285,
    TK_CHAR = 286,
    TK_FLOAT = 287,
    TK_BOOL = 288,
    TK_NUM = 289,
    TK_STRING = 290,
    TK_INT = 291,
    TK_FIM = 292,
    TK_ERROR = 293,
    TK_BREAK = 294,
    TK_CONTINUE = 295,
    TK_RETURN = 296,
    TK_ADD_VETOR = 297,
    TK_SWITCH = 298,
    TK_CASE = 299,
    TK_DEFAULT = 300
  };
#endif
/* Tokens.  */
#define TK_MAIN 258
#define TK_INPUT 259
#define TK_SAIDA 260
#define TK_WHILE 261
#define TK_DO 262
#define TK_FOR 263
#define TK_IF 264
#define TK_ELSE 265
#define TK_END_LOOP 266
#define TK_ID 267
#define TK_DEC_VAR 268
#define TK_GLOBAL_VAR 269
#define TK_TIPO_VOID 270
#define TK_TIPO_CHAR 271
#define TK_TIPO_INT 272
#define TK_TIPO_FLOAT 273
#define TK_COMENTARIO 274
#define TK_UN_SUM 275
#define TK_UN_SUB 276
#define TK_LESS 277
#define TK_GREATER 278
#define TK_LE 279
#define TK_HE 280
#define TK_EQ 281
#define TK_DIFF 282
#define TK_NOT 283
#define TK_AND 284
#define TK_OR 285
#define TK_CHAR 286
#define TK_FLOAT 287
#define TK_BOOL 288
#define TK_NUM 289
#define TK_STRING 290
#define TK_INT 291
#define TK_FIM 292
#define TK_ERROR 293
#define TK_BREAK 294
#define TK_CONTINUE 295
#define TK_RETURN 296
#define TK_ADD_VETOR 297
#define TK_SWITCH 298
#define TK_CASE 299
#define TK_DEFAULT 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   500

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

#define YYUNDEFTOK  2
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,     2,     2,     2,     2,    49,     2,
      56,    57,    54,    52,    63,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    60,
      50,    47,    51,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    48,    59,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   124,   124,   124,   132,   139,   148,   184,   191,   197,
     203,   207,   211,   215,   219,   223,   236,   247,   257,   267,
     277,   282,   287,   295,   347,   484,   597,   691,   723,   752,
     818,   866,   886,   903,   923,   930,   933,   939,   946,   952,
     961,   967,   972,   972,  1006,  1010,  1014,  1018,  1024,  1031,
    1034,  1040,  1062,  1068,  1092,  1093,  1097,  1101,  1108,  1134,
    1149,  1149,  1171,  1177,  1177,  1199,  1199,  1211,  1211,  1234,
    1234,  1263,  1263,  1288,  1288,  1295,  1296,  1299,  1300,  1303,
    1308,  1314,  1323,  1333,  1339,  1344,  1349,  1354,  1359,  1364,
    1369,  1374,  1379,  1384,  1407,  1430,  1449,  1463,  1483,  1599,
    1648,  1700,  1752,  1774,  1781,  1789,  1797,  1805,  1815,  1823
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_MAIN", "TK_INPUT", "TK_SAIDA",
  "TK_WHILE", "TK_DO", "TK_FOR", "TK_IF", "TK_ELSE", "TK_END_LOOP",
  "TK_ID", "TK_DEC_VAR", "TK_GLOBAL_VAR", "TK_TIPO_VOID", "TK_TIPO_CHAR",
  "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_COMENTARIO", "TK_UN_SUM",
  "TK_UN_SUB", "TK_LESS", "TK_GREATER", "TK_LE", "TK_HE", "TK_EQ",
  "TK_DIFF", "TK_NOT", "TK_AND", "TK_OR", "TK_CHAR", "TK_FLOAT", "TK_BOOL",
  "TK_NUM", "TK_STRING", "TK_INT", "TK_FIM", "TK_ERROR", "TK_BREAK",
  "TK_CONTINUE", "TK_RETURN", "TK_ADD_VETOR", "TK_SWITCH", "TK_CASE",
  "TK_DEFAULT", "'!'", "'='", "'|'", "'&'", "'<'", "'>'", "'+'", "'-'",
  "'*'", "'/'", "'('", "')'", "'{'", "'}'", "';'", "'['", "']'", "','",
  "':'", "$accept", "S", "$@1", "BLOCOGLOBAL", "FUNCOES", "BLOCOCONTEXTO",
  "BLOCO", "COMANDOS", "COMANDO", "DECLARACAO", "VALORES", "CHAMADAFUNCAO",
  "NOMECHAMADA", "ARGS", "MOREARGS", "FIMARGS", "FUNCTIONS", "FUNCAO",
  "$@2", "TIPORETORNO", "NOME", "ARGUMENTOS", "MOREARGUMENTS",
  "FIMARGUMENTS", "TIPOARGUMENTO", "ENTRADA", "SAIDA", "IF", "$@3", "ELSE",
  "ELSEE", "$@4", "$@5", "FOR", "$@6", "WHILE", "$@7", "DOWHILE", "$@8",
  "SWITCH", "$@9", "BLOCK", "CASELIST", "CASE", "DEFAULTSTM", "BREAK",
  "CONTINUE", "E", "DEC", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    33,    61,   124,    38,
      60,    62,    43,    45,    42,    47,    40,    41,   123,   125,
      59,    91,    93,    44,    58
};
# endif

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      63,  -186,  -186,  -186,  -186,    34,   169,  -186,    63,  -186,
    -186,   -13,    27,   174,    54,    26,    36,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,   232,   215,  -186,     5,  -186,    56,
      33,  -186,    38,    39,    40,    42,    44,   250,  -186,  -186,
      86,   215,   215,  -186,  -186,    52,   227,   -32,    98,   215,
    -186,  -186,     0,   271,  -186,  -186,  -186,  -186,  -186,  -186,
     101,  -186,  -186,  -186,    65,  -186,  -186,  -186,   215,  -186,
    -186,  -186,  -186,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,  -186,  -186,    60,   307,   313,   215,    89,
     439,   215,    57,   -28,   319,    -6,   123,    73,    78,    75,
      81,    82,    83,  -186,  -186,    90,  -186,  -186,   -17,   439,
     439,   165,   165,   445,   445,     8,     8,    51,    51,    59,
    -186,  -186,   325,    91,    92,   439,    93,   215,    77,  -186,
      94,    96,    97,   215,   130,   140,    72,   215,   215,   145,
      78,    95,   215,  -186,  -186,  -186,   102,  -186,  -186,   154,
    -186,   215,   215,   110,   439,   128,   215,   215,   119,   331,
     118,   122,   124,   367,   373,   129,  -186,  -186,  -186,    78,
     127,    51,    51,   232,   135,   379,   385,    78,    78,  -186,
     215,   215,    78,   138,   215,  -186,    10,   139,   136,   232,
    -186,  -186,  -186,  -186,   391,   262,  -186,   163,   427,  -186,
    -186,   232,   152,  -186,   215,   178,   164,   177,   163,    78,
    -186,  -186,   433,   160,  -186,   162,  -186,  -186,   101,    78,
     201,   130,  -186,  -186,   189,  -186,   171,  -186
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      41,    45,    46,    47,    44,     0,     6,     5,    41,    42,
       1,     0,     0,   109,     0,     0,     0,   106,   105,   108,
     104,   107,    81,    82,     0,     0,     6,     0,     4,     6,
       0,    14,     0,     0,     0,     0,     0,     0,   103,    40,
       0,     0,     0,    93,    94,     0,     0,    23,     0,     0,
     109,   102,   109,     0,     2,    69,    71,    67,    60,    73,
      15,    16,    17,    18,     0,    20,     8,    11,    35,    12,
      13,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    48,     0,     0,     0,     0,     0,
      98,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    63,    62,    19,     0,    36,    38,    39,    87,
      88,    89,    90,    91,    92,    83,    84,    85,    86,    49,
      58,    59,     0,     0,     0,    24,    25,     0,     0,    95,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    55,     0,    50,    52,     0,
      99,     0,     0,     0,    29,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    66,    33,    37,     0,
      53,   100,   101,     0,     0,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,    43,    54,     0,    32,     0,
      97,    96,     3,    70,     0,     0,    61,     0,     0,    51,
      26,     0,     0,    72,     0,     0,     0,    75,    77,     0,
      31,    30,     0,     0,    74,     0,    76,    78,     0,     0,
       6,     6,    64,    68,     0,    80,     0,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,  -186,  -186,  -186,   211,  -137,   -29,  -186,   109,
    -185,  -186,  -186,  -186,   111,  -186,   230,  -186,  -186,  -186,
    -186,  -186,    66,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
      61,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,    43,  -186,  -186,  -186,  -186,   -24,   -22
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,    96,    26,     6,    27,   135,    28,    29,    30,
     187,    31,    32,   105,   106,   107,     7,     8,    40,     9,
      85,   146,   147,   148,   149,    33,    34,    60,   100,    61,
     103,   139,   140,    62,    99,    63,    97,    64,    98,    65,
     101,   206,   207,   208,   216,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    53,    51,   166,   202,    73,    74,    75,    76,    77,
      78,    55,    56,    57,    58,    91,   210,    86,    87,   127,
      43,    44,    90,   130,   131,    94,   143,   144,   145,    92,
      73,    74,   185,   128,    10,    79,    80,    81,    82,    48,
     192,   193,    45,    41,   108,   196,   142,    46,    59,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,    -9,
      11,    12,    81,    82,   122,    53,    47,   125,    13,    14,
      15,   -54,   218,    73,    74,   143,   144,   145,     1,     2,
       3,     4,   223,    42,    16,    14,    15,    17,    18,    19,
      20,    21,    49,    67,    68,    22,    23,    24,    84,    69,
      70,    52,    71,   154,    72,   160,   123,   124,    88,   159,
      93,   102,    25,   163,   164,    -9,   119,    16,   108,   126,
      17,    18,    19,    20,    21,   104,   132,   171,   172,   133,
      24,   136,   175,   176,    11,    12,   134,   137,   138,   155,
     153,   -65,    13,    14,    15,    25,   161,   141,   151,   152,
     156,   188,   157,   158,   165,   167,   194,   195,    16,   169,
     198,    17,    18,    19,    20,    21,   170,   188,   173,    22,
      23,    24,    -9,    11,    12,   174,   177,   179,   180,   188,
     212,    13,    14,    15,   181,   184,    25,    73,    74,    -9,
     186,   224,   225,   189,    43,    44,   197,    16,   200,   201,
      17,    18,    19,    20,    21,    11,    12,   205,    22,    23,
      24,   211,   213,    13,    14,    15,    45,    79,    80,    81,
      82,    46,   215,   214,   220,    25,   221,    52,   226,    16,
     -34,   227,    17,    18,    19,    20,    21,    54,    39,    52,
      22,    23,    24,    16,    50,   162,    17,    18,    19,    20,
      21,   217,   199,   168,     0,    16,    24,    25,    17,    18,
      19,    20,    21,    17,    18,    19,    20,    21,    24,     0,
       0,    25,    73,    74,    75,    76,    77,    78,     0,   222,
       0,     0,     0,    89,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    73,    74,    75,    76,    77,    78,     0,
       0,     0,    79,    80,    81,    82,     0,     0,     0,     0,
      83,     0,     0,     0,    79,    80,    81,    82,     0,     0,
       0,     0,   204,    79,    80,    81,    82,     0,    95,    73,
      74,    75,    76,    77,    78,    73,    74,    75,    76,    77,
      78,    73,    74,    75,    76,    77,    78,    73,    74,    75,
      76,    77,    78,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,   120,    79,    80,    81,    82,     0,
     121,    79,    80,    81,    82,     0,   129,    79,    80,    81,
      82,     0,   150,    79,    80,    81,    82,     0,   178,    73,
      74,    75,    76,    77,    78,    73,    74,    75,    76,    77,
      78,    73,    74,    75,    76,    77,    78,    73,    74,    75,
      76,    77,    78,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,   182,    79,    80,    81,    82,     0,
     183,    79,    80,    81,    82,     0,   190,    79,    80,    81,
      82,     0,   191,    79,    80,    81,    82,     0,   203,    73,
      74,    75,    76,    77,    78,    73,    74,    75,    76,    77,
      78,    73,    74,    75,    76,    77,    78,    73,    74,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,     0,   209,    79,    80,    81,    82,     0,
     219,    79,    80,    81,    82,     0,     0,    79,    80,    81,
      82
};

static const yytype_int16 yycheck[] =
{
      29,    25,    24,   140,   189,    22,    23,    24,    25,    26,
      27,     6,     7,     8,     9,    47,   201,    41,    42,    47,
      20,    21,    46,    29,    30,    49,    16,    17,    18,    61,
      22,    23,   169,    61,     0,    52,    53,    54,    55,    13,
     177,   178,    42,    56,    68,   182,    63,    47,    43,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     3,
       4,     5,    54,    55,    88,    89,    12,    91,    12,    13,
      14,    12,   209,    22,    23,    16,    17,    18,    15,    16,
      17,    18,   219,    56,    28,    13,    14,    31,    32,    33,
      34,    35,    56,    60,    56,    39,    40,    41,    12,    60,
      60,    12,    60,   127,    60,   134,    17,    18,    56,   133,
      12,    10,    56,   137,   138,    59,    56,    28,   142,    62,
      31,    32,    33,    34,    35,    60,     3,   151,   152,    56,
      41,    56,   156,   157,     4,     5,    58,    56,    56,    62,
      47,    58,    12,    13,    14,    56,     6,    57,    57,    57,
      56,   173,    56,    56,     9,    60,   180,   181,    28,    57,
     184,    31,    32,    33,    34,    35,    12,   189,    58,    39,
      40,    41,     3,     4,     5,    47,    57,    59,    56,   201,
     204,    12,    13,    14,    60,    56,    56,    22,    23,    59,
      63,   220,   221,    58,    20,    21,    58,    28,    59,    63,
      31,    32,    33,    34,    35,     4,     5,    44,    39,    40,
      41,    59,    34,    12,    13,    14,    42,    52,    53,    54,
      55,    47,    45,    59,    64,    56,    64,    12,    39,    28,
      56,    60,    31,    32,    33,    34,    35,    26,     8,    12,
      39,    40,    41,    28,    12,   136,    31,    32,    33,    34,
      35,   208,   186,   142,    -1,    28,    41,    56,    31,    32,
      33,    34,    35,    31,    32,    33,    34,    35,    41,    -1,
      -1,    56,    22,    23,    24,    25,    26,    27,    -1,   218,
      -1,    -1,    -1,    56,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    60,    52,    53,    54,    55,    -1,    57,    22,
      23,    24,    25,    26,    27,    22,    23,    24,    25,    26,
      27,    22,    23,    24,    25,    26,    27,    22,    23,    24,
      25,    26,    27,    22,    23,    24,    25,    26,    27,    52,
      53,    54,    55,    -1,    57,    52,    53,    54,    55,    -1,
      57,    52,    53,    54,    55,    -1,    57,    52,    53,    54,
      55,    -1,    57,    52,    53,    54,    55,    -1,    57,    22,
      23,    24,    25,    26,    27,    22,    23,    24,    25,    26,
      27,    22,    23,    24,    25,    26,    27,    22,    23,    24,
      25,    26,    27,    22,    23,    24,    25,    26,    27,    52,
      53,    54,    55,    -1,    57,    52,    53,    54,    55,    -1,
      57,    52,    53,    54,    55,    -1,    57,    52,    53,    54,
      55,    -1,    57,    52,    53,    54,    55,    -1,    57,    22,
      23,    24,    25,    26,    27,    22,    23,    24,    25,    26,
      27,    22,    23,    24,    25,    26,    27,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    57,    52,    53,    54,    55,    -1,
      57,    52,    53,    54,    55,    -1,    -1,    52,    53,    54,
      55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    17,    18,    66,    69,    81,    82,    84,
       0,     4,     5,    12,    13,    14,    28,    31,    32,    33,
      34,    35,    39,    40,    41,    56,    68,    70,    72,    73,
      74,    76,    77,    90,    91,   110,   111,   112,   113,    81,
      83,    56,    56,    20,    21,    42,    47,    12,    13,    56,
      12,   113,    12,   112,    70,     6,     7,     8,     9,    43,
      92,    94,    98,   100,   102,   104,    72,    60,    56,    60,
      60,    60,    60,    22,    23,    24,    25,    26,    27,    52,
      53,    54,    55,    60,    12,    85,   112,   112,    56,    56,
     112,    47,    61,    12,   112,    57,    67,   101,   103,    99,
      93,   105,    10,    95,    60,    78,    79,    80,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,    56,
      57,    57,   112,    17,    18,   112,    62,    47,    61,    57,
      29,    30,     3,    56,    58,    71,    56,    56,    56,    96,
      97,    57,    63,    16,    17,    18,    86,    87,    88,    89,
      57,    57,    57,    47,   112,    62,    56,    56,    56,   112,
      72,     6,    74,   112,   112,     9,    71,    60,    79,    57,
      12,   112,   112,    58,    47,   112,   112,    57,    57,    59,
      56,    60,    57,    57,    56,    71,    63,    75,   113,    58,
      57,    57,    71,    71,   112,   112,    71,    58,   112,    87,
      59,    63,    75,    57,    60,    44,   106,   107,   108,    57,
      75,    59,   112,    34,    59,    45,   109,   107,    71,    57,
      64,    64,    95,    71,    72,    72,    39,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    67,    66,    68,    69,    70,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    77,    78,    78,    79,    79,    80,
      81,    81,    83,    82,    84,    84,    84,    84,    85,    86,
      86,    87,    87,    88,    89,    89,    89,    89,    90,    91,
      93,    92,    94,    96,    95,    97,    95,    99,    98,   101,
     100,   103,   102,   105,   104,   106,   106,   107,   107,   108,
     109,   110,   111,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     1,     1,     0,     3,     2,     0,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     2,     2,     2,     4,     4,     8,     5,     3,     5,
       9,     3,     1,     5,     1,     0,     1,     3,     1,     1,
       2,     0,     0,     7,     1,     1,     1,     1,     1,     0,
       1,     4,     1,     2,     0,     1,     1,     1,     4,     4,
       0,     6,     2,     0,     8,     0,     3,     0,    10,     0,
       6,     0,     7,     0,     8,     1,     2,     1,     2,     6,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     7,     7,     3,     5,
       6,     6,     2,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
  case 2:
#line 124 "sintatico.y"
                                                                    {cout<<"Entro na main"<<endl;entryMain++;}
#line 1699 "y.tab.c"
    break;

  case 3:
#line 125 "sintatico.y"
                                {
					cout << "/*Salve Kappa!*/\n" << "\n#include <iostream>\n#include<string.h>\n#include<stdio.h>\nusing std::string;\n\n" + yyvsp[-7].traducao + "\nint main(void)\n{\n" << 
					"//------------------ Escopo Variáveis ------------------\\\\ \n" << yyvsp[-7].traducao_dec << yyvsp[-6].traducao_dec << yyvsp[0].traducao_dec << 
					"//------------------ Escopo Atribuições ------------------\\\\ \n" << yyvsp[-6].traducao << yyvsp[0].traducao << "\treturn 0;\n}" << endl;
				}
#line 1709 "y.tab.c"
    break;

  case 4:
#line 133 "sintatico.y"
                                {
					yyval.traducao = yyvsp[0].traducao;
					yyval.traducao_dec = yyvsp[0].traducao_dec;
				}
#line 1718 "y.tab.c"
    break;

  case 5:
#line 140 "sintatico.y"
                                {
					cout<<"FUNCOES"<<endl;
					entryFunc = 0;
					yyval = yyvsp[0];
				}
#line 1728 "y.tab.c"
    break;

  case 6:
#line 148 "sintatico.y"
                                {
					if(globalTabSym.empty() != 1){
						variable ref;
						ref.tipo = "";
						ref.nome = "";
						ref.valor = "";
						ref.tmp = "";
						vector<variable> aux;
						aux.push_back(ref);
						globalTabSym.push_back(aux);
						mapAtual++;
						//cout<<"Entro aqui"<<endl;
						//cout<<"GLOBAL TAB SMY = "<<globalTabSym.size() <<endl;
					}
					cout<<"MAPA ATUAL = "<< mapAtual<<endl;
					//if(mapAtual == 1 && globalTabSym.size() == 2 && globalTabSym[1][0].nome == ""){
						//globalTabSym.pop_back();
						//mapAtual--;
					//}
					/*if(globalTabSym.empty() == 1 && entryMain == 1){
						variable ref;
						ref.tipo = "";
						ref.nome = "";
						ref.valor = "";
						ref.tmp = "";
						vector<variable> aux;
						aux.push_back(ref);
						globalTabSym.push_back(aux);
						mapAtual++;
					}*/
					cout<<"blococontexto"<<endl;
					//cout<<entryMain<<endl;
					cout<<"MAPA ATUAL = "<< mapAtual<<endl;
					//cout<<"GLOBAL TAB SMY = "<<globalTabSym.size() <<endl;
				}
#line 1768 "y.tab.c"
    break;

  case 7:
#line 185 "sintatico.y"
                                {
					yyval.traducao = yyvsp[-1].traducao;
					yyval.traducao_dec = yyvsp[-1].traducao_dec;
				}
#line 1777 "y.tab.c"
    break;

  case 8:
#line 192 "sintatico.y"
                                {
					yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
					yyval.traducao_dec = yyvsp[-1].traducao_dec + yyvsp[0].traducao_dec;
				}
#line 1786 "y.tab.c"
    break;

  case 9:
#line 197 "sintatico.y"
                                {
					yyval.traducao = "";
					yyval.traducao_dec = "";
				}
#line 1795 "y.tab.c"
    break;

  case 10:
#line 204 "sintatico.y"
                                {
					yyval = yyvsp[-1];
				}
#line 1803 "y.tab.c"
    break;

  case 11:
#line 208 "sintatico.y"
                                {
					yyval = yyvsp[-1];
				}
#line 1811 "y.tab.c"
    break;

  case 12:
#line 212 "sintatico.y"
                                {
					yyval = yyvsp[-1];
				}
#line 1819 "y.tab.c"
    break;

  case 13:
#line 216 "sintatico.y"
                                {
					yyval = yyvsp[-1];
				}
#line 1827 "y.tab.c"
    break;

  case 14:
#line 220 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 1835 "y.tab.c"
    break;

  case 15:
#line 224 "sintatico.y"
                                {
					yyval = yyvsp[0];
					if(mapAtual > 0){
						globalTabSym.pop_back();
						mapAtual--;
					}
					cout<<"BLOCOCONTEXTO IF"<<endl;
					//cout<<"mapa atual" <<mapAtual<<endl;
					//cout<<"MAPA ATUAL = "<< mapAtual<<endl;
					//cout<<"GLOBAL TAB SMY = "<<globalTabSym.size() <<endl;
					loops.pop();
				}
#line 1852 "y.tab.c"
    break;

  case 16:
#line 237 "sintatico.y"
                                {
					yyval = yyvsp[0];
					if(mapAtual > 0){
						globalTabSym.pop_back();
						mapAtual--;
					}
					cout<<"BLOCOCONTEXTO ELSE"<<endl;
					//cout<<"mapa atual" <<mapAtual<<endl;
					//loops.pop();
				}
#line 1867 "y.tab.c"
    break;

  case 17:
#line 248 "sintatico.y"
                                {	
					yyval = yyvsp[0];
					if(mapAtual > 0){
						globalTabSym.pop_back();
						mapAtual--;
					}
					loops.pop();
					cout<<"BLOCOCONTEXTO FOR"<<endl;
				}
#line 1881 "y.tab.c"
    break;

  case 18:
#line 258 "sintatico.y"
                                {	
					yyval = yyvsp[0];
					if(mapAtual > 0){
						globalTabSym.pop_back();
						mapAtual--;
					}
					loops.pop();	
					cout<<"BLOCOCONTEXTO WHILE"<<endl;
				}
#line 1895 "y.tab.c"
    break;

  case 19:
#line 268 "sintatico.y"
                                {
					yyval = yyvsp[-1];
					if(mapAtual > 0){
						globalTabSym.pop_back();
						mapAtual--;
					}
					loops.pop();
					cout<<"BLOCOCONTEXTO DOWHILE"<<endl;
				}
#line 1909 "y.tab.c"
    break;

  case 20:
#line 278 "sintatico.y"
                {
                    yyval = yyvsp[0];
					cout<<"BLOCOCONTEXTO SWITCH"<<endl;
                }
#line 1918 "y.tab.c"
    break;

  case 21:
#line 283 "sintatico.y"
                                {
					yyval = yyvsp[-1];
					cout<<"BREAK"<<endl;
				}
#line 1927 "y.tab.c"
    break;

  case 22:
#line 288 "sintatico.y"
                                {
					yyval = yyvsp[-1];
					cout<<"CONTINUE"<<endl;
				}
#line 1936 "y.tab.c"
    break;

  case 23:
#line 296 "sintatico.y"
                                {
					cout<<"tk_dec_var tk_id"<<endl;
					cout<<"MAPA ATUAL "<<mapAtual<<endl;
					if(mapAtual == 0 && entryMain == 0 && entryFunc == 0){//Verifica se essa declaração está sendo feita antes da main
						yyerror("Só é permitido declarar variável global antes do escopo da main com o modificador \"global\".\n");
					}
					if(mapAtual == 1 && entryMain == 1){//Esse if informa que já teve declaração de variável global antes da main
						if(verifyVariableGlobal(yyvsp[0].label) != true){//Dessa forma preciso verificar com o verifyVariableGlobal se a variável não foi declarada antes 
							cout<<"teste1"<<endl;
							variable ref;
							ref.tipo = "";
							ref.nome = yyvsp[0].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
							
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
						yyval.traducao = "\tvar " + ref.nome + ";\n";
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[0].label + ".\n");
						}
					}
					else{
						if(verifyVariableLocal(yyvsp[0].label) != true){
							cout<<"teste2"<<endl;
							variable ref;
							ref.tipo = "";
							ref.nome = yyvsp[0].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
							
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
						yyval.traducao = "\tvar " + ref.nome + ";\n";
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[0].label + ".\n");
						}
					}	
				}
#line 1992 "y.tab.c"
    break;

  case 24:
#line 348 "sintatico.y"
                                {
					cout<<"tk_dec_var tk_id = e"<<endl;
					if(mapAtual == 0 && entryMain == 0 && entryFunc == 0){//Verifica se essa declaração está sendo feita antes da main
						yyerror("Só é permitido declarar variável global antes do escopo da main com o modificador \"global\".\n");
					}	

					if(mapAtual == 1 && entryMain == 1){//Esse if informa que já teve declaração de variável global antes da main
						if(verifyVariableGlobal(yyvsp[-2].label) == false){//Dessa forma preciso verificar com o verifyVariableGlobal
							if(verifyVariableGlobal(yyvsp[0].label) && yyvsp[0].tmp == ""){//Se eu não colocar $4.tmp == "" ele não irá interpretar quando alguma operação vier, 
								variable *var1 = returnVariable(yyvsp[0].label);//pois quando tem alguma operação o $4.tmp não fica = ""
								variable ref;
								if(var1->valor != ""){
									cout<<"teste1"<<endl;
									ref.tipo = var1->tipo;
									ref.nome = yyvsp[-2].label;
									ref.valor = var1->valor;
									ref.tmp = genLabel();
									if(var1->tipo == "char *"){
										yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
										yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = (char*) malloc(" + to_string(var1->valor.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
										ref.tmp + "," + var1->tmp + " );\n";
									}
									else{
										yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
										yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = " + var1->tmp + ";\n";
									}
									if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
										vector<variable> aux;
										aux.push_back(ref);
										globalTabSym.push_back(aux);
									}
									else{
										globalTabSym[mapAtual].push_back(ref);
									}
								}
								else{
									yyerror("Voce ainda não inicialiou a variavel " + var1->nome + ".\n");
								}
							} 
							else{
								cout<<"teste2"<<endl;
								variable ref;
								ref.tipo = yyvsp[0].tipo;
								ref.nome = yyvsp[-2].label;
								ref.valor = yyvsp[0].label;
								ref.tmp = genLabel();
								if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){//o tamanho da estrutura tem que ser maior que o tamanho do map
									vector<variable> aux;//pois se for igual, globalTabSym[mapAtual] não vai ter nenhum elemento, com isso tenho que adicionar um elemento(vetor nesse caso)
									aux.push_back(ref);//pra depois poder adicionar somente as variables
									globalTabSym.push_back(aux);
								}
								else{
									globalTabSym[mapAtual].push_back(ref);
								} 
								if(yyvsp[0].tipo == "char *"){
									yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
									//$$.traducao = $4.traducao + "\t" + ref.tmp + " = " + $4.tmp + ";\n";
									yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = (char*) malloc(" + to_string(yyvsp[0].label.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
									ref.tmp + "," + yyvsp[0].tmp + " );\n";	
								}
								else{
									yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
									yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = " + yyvsp[0].tmp + ";\n";
								}
							}
						}
						else{
							yyerror("Você já declarou a variável " + yyvsp[-2].label + ".\n");
						}
					}
					else{
						if(verifyVariableLocal(yyvsp[-2].label) == false){
							if(verifyVariableLocal(yyvsp[0].label) && yyvsp[0].tmp == ""){//Se eu não colocar $4.tmp == "" ele não irá interpretar quando alguma operação vier, 
								variable *var1 = returnVariable(yyvsp[0].label);//pois quando tem alguma operação o $4.tmp não fica = ""
								variable ref;
								if(var1->valor != ""){
									cout<<"teste3"<<endl;
									ref.tipo = var1->tipo;
									ref.nome = yyvsp[-2].label;
									ref.valor = var1->valor;
									ref.tmp = genLabel();
									if(var1->tipo == "char *"){
										yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
										yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " =  (char*) malloc(" + to_string(var1->valor.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
										ref.tmp + "," + var1->tmp + " );\n";
									}
									else{
										yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
										yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = " + var1->tmp + ";\n";
									}
									if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
										vector<variable> aux;
										aux.push_back(ref);
										globalTabSym.push_back(aux);
									}
									else{
										globalTabSym[mapAtual].push_back(ref);
									}
								}
								else{
									yyerror("Voce ainda não inicialiou a variavel " + var1->nome + ".\n");
								}
							} 
							else{
								cout<<"teste4"<<endl;
								variable ref;
								ref.tipo = yyvsp[0].tipo;
								ref.nome = yyvsp[-2].label;
								ref.valor = yyvsp[0].label;
								ref.tmp = genLabel();
								if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){//o tamanho da estrutura tem que ser maior que o tamanho do map
									vector<variable> aux;//pois se for igual, globalTabSym[mapAtual] não vai ter nenhum elemento, com isso tenho que adicionar um elemento(vetor nesse caso)
									aux.push_back(ref);//pra depois poder adicionar somente as variables
									globalTabSym.push_back(aux);
								}
								else{
									globalTabSym[mapAtual].push_back(ref);
								}
								//cout<<"salvando no indice "<< mapAtual<<endl;
								if(yyvsp[0].tipo == "char *"){
									yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
									//$$.traducao = $4.traducao + "\t" + ref.tmp + " = " + $4.tmp + ";\n";
									yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " =  (char*) malloc(" + to_string(yyvsp[0].label.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
									ref.tmp + "," + yyvsp[0].tmp + " );\n";	
								}
								else{
									yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
									yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = " + yyvsp[0].tmp + ";\n";
								}
							}
						}
						else{
							yyerror("Você já declarou a variável " + yyvsp[-2].label + ".\n");
						}		
					}
				}
#line 2133 "y.tab.c"
    break;

  case 25:
#line 485 "sintatico.y"
                                {	
					cout<<"tk_dec_var tk_id = [ ]"<<endl;
					if(mapAtual == 0 && entryMain == 0 && entryFunc == 0){//Verifica se essa declaração está sendo feita antes da main
						yyerror("Só é permitido declarar vetor global antes do escopo da main com o modificador \"global\".\n");
					}

					if(mapAtual == 1 && entryMain == 1){
						if(verifyVariableGlobal(yyvsp[-2].label) != true){//Com isso, eu sei que teve declaração antes da main. Dessa forma preciso verificar com o verifyVariableGlobal
							cout<<"teste1"<<endl;//Se a variável não foi declarada antes ja
							variable ref;
							ref.tipo = "";
							ref.nome = yyvsp[-2].label;
							ref.valor = ""; //Forço a variável a receber uma string vazia pois irei fazer comparações utilizando a string "vazia"
							ref.tmp = genLabel();
							ref.vetor.isVector = "true";
							ref.vetor.tmVetor = "";
							ref.vetor.tmp = genLabel();
								
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							yyval.traducao = "\tvar *" + ref.nome + ";\n";
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[-2].label + ".\n");
						}
					}
					else{
						if(verifyVariableLocal(yyvsp[-2].label) != true){
							cout<<"teste1"<<endl;
							variable ref;
							ref.tipo = "";
							ref.nome = yyvsp[-2].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
							ref.vetor.isVector = "true";
							ref.vetor.tmVetor = "";
							ref.vetor.tmp = genLabel();
								
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							yyval.traducao = "\tvar *" + ref.nome + ";\n";
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[-2].label + ".\n");
						}
					}
				}
#line 2195 "y.tab.c"
    break;

  case 26:
#line 598 "sintatico.y"
                                {
					cout<<"tk_dec_var tk_id [ ] = {valores}"<<endl;
					if(mapAtual == 0 && entryMain == 0 && entryFunc == 0){//Verifica se essa declaração está sendo feita antes da main
						yyerror("Só é permitido declarar vetor global antes do escopo da main com o modificador \"global\".\n");
					}	

					if(mapAtual == 1 && entryMain == 1){
						if(verifyVariableGlobal(yyvsp[-6].label) != true){
							cout<<"teste1"<<endl;
							variable ref;
							ref.tipo = yyvsp[-1].tipo;
							ref.nome = yyvsp[-6].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
							ref.vetor.isVector = "true";
							ref.vetor.tmVetor = std::to_string(auxArray.size());
							ref.vetor.tmp = genLabel();
								
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							string aux1;
							string aux2;
							aux1 = "\t" + ref.tmp + " = (" + yyvsp[-1].tipo + "*) malloc(" + std::to_string(auxArray.size()) + "* sizeof(" + yyvsp[-1].tipo + "));//vetor\n\t" + ref.vetor.tmp + " = 0;\n";
							
							for(int i = 0; i < auxArray.size(); i++){
								aux2 = aux2 + "\t" + yyvsp[-6].label + " [" + ref.vetor.tmp + "] = " + auxArrayTmp[i] + ";\n\t" + ref.vetor.tmp + " = " + ref.vetor.tmp + " + 1;\n";
							}
							
							yyval.traducao_dec = "\t" + yyvsp[-1].tipo + " = *" + ref.tmp + yyvsp[-1].traducao_dec;
							//$$.traducao ="\t" + $2.label + "[ ] = {" + $7.label + "};\n" + $7.traducao + aux1 + aux2;	
							yyval.traducao = yyvsp[-1].traducao + aux1 + aux2;
							auxArray.clear();//Limpa o array pra ser usado outra vez
							auxArrayTmp.clear();//Limpa o array pra ser usado outra vez
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[-6].label + ".\n");
						}
					}
					else{
						if(verifyVariableLocal(yyvsp[-6].label) != true){
							cout<<"teste2"<<endl;
							variable ref;
							ref.tipo = yyvsp[-1].tipo;
							ref.nome = yyvsp[-6].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
							ref.vetor.isVector = "true";
							ref.vetor.tmVetor = std::to_string(auxArray.size());
							ref.vetor.tmp = genLabel();
								
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							string aux1;
							string aux2;
							aux1 = "\t" + ref.tmp + " = (" + yyvsp[-1].tipo + "*) malloc(" + std::to_string(auxArray.size()) + "* sizeof(" + yyvsp[-1].tipo + "));//vetor\n\t" + ref.vetor.tmp + " = 0;\n";
							
							for(int i = 0; i < auxArray.size(); i++){
								aux2 = aux2 + "\t" + yyvsp[-6].label + " [" + ref.vetor.tmp + "] = " + auxArrayTmp[i] + ";\n\t" + ref.vetor.tmp + " = " + ref.vetor.tmp + " + 1;\n";
							}
							
							yyval.traducao_dec = "\t" + yyvsp[-1].tipo + " = *" + ref.tmp + yyvsp[-1].traducao_dec;
							//$$.traducao ="\t" + $2.label + "[ ] = {" + $7.label + "};\n" + $7.traducao + aux1 + aux2;	
							yyval.traducao = yyvsp[-1].traducao + aux1 + aux2;
							auxArray.clear();
							auxArrayTmp.clear();
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[-6].label + ".\n");
						}
					}
					/*string aux1;
					string aux2;
					string tmp = genLabel();
					aux1 = "\t(" + $7.tipo + "*) malloc(" + std::to_string(auxArray.size()) + "* sizeof(" + $7.tipo + "));//vetor\n\t" + tmp + " = 0;\n";
					
					for(int i =0;i<auxArray.size();i++){
						aux2 = aux2 + "\t" + $2.label + " [" + tmp + "] = " + auxArrayTmp[i] + ";\n\t" + tmp + " = " + tmp + " + 1;\n";
					}
					
					$$.traducao_dec = $7.traducao_dec;
					//$$.traducao ="\t" + $2.label + "[ ] = {" + $7.label + "};\n" + $7.traducao + aux1 + aux2;	
					$$.traducao = $7.traducao + aux1 + aux2;*/				
				}
#line 2293 "y.tab.c"
    break;

  case 27:
#line 692 "sintatico.y"
                                {
					cout<<"tk_global tk_dec_var tk_id"<<endl;
					if(mapAtual == 0 && entryMain == 0 || mapAtual == 0 && entryMain == 1){//Comparação que faz com que uma variável global seja criada somente dentro da main
						if(verifyVariableGlobal(yyvsp[-2].label) != true){//ou antes dela. E também só pode ser criada fora de qualquer escopo(for, if, while)
							cout<<"teste1"<<endl;
							variable ref;
							ref.tipo = "";
							ref.nome = yyvsp[-2].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
							ref.vetor.isVector = "true";
							ref.vetor.tmVetor = "";
							ref.vetor.tmp = genLabel();
								
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							yyval.traducao = "\tglobal var *" + ref.nome + ";\n";
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[-2].label + ".\n");
						}
					}
					else{
						yyerror("Declaração de variável global somente fora de função ou antes do bloco main, ambas com o modificador \"global\".\n");
					}
				}
#line 2329 "y.tab.c"
    break;

  case 28:
#line 724 "sintatico.y"
                                {
					cout<<"tk_global tk_dec_var tk_id"<<endl;
					if(mapAtual == 0 && entryMain == 0 || mapAtual == 0 && entryMain == 1){//Comparação que faz com que uma variável global seja criada somente dentro da main
						if(verifyVariableGlobal(yyvsp[0].label) != true){//ou antes dela. E também só pode ser criada fora de qualquer escopo(for, if, while)
							cout<<"teste1"<<endl;
							variable ref;
							ref.tipo = "";
							ref.nome = yyvsp[0].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
								
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							yyval.traducao = "\tglobal var " + ref.nome + ";\n";
						}else{
							yyerror("Voce já declarou a variável " + yyvsp[0].label + ".\n");
						}
					}
					else{
						yyerror("Declaração de variável global somente fora de função ou antes do bloco main, ambas com o modificador \"global\".\n");
					}
				}
#line 2362 "y.tab.c"
    break;

  case 29:
#line 753 "sintatico.y"
                                {
					cout<<"tk_global tk_dec_var tk_id = e"<<endl;
					if(mapAtual == 0 && entryMain == 0 || mapAtual == 0 && entryMain == 1){
						if(verifyVariableGlobal(yyvsp[0].label) && yyvsp[0].tmp == ""){//Se eu não colocar $4.tmp == "" ele não irá interpretar quando alguma operação vier, 
							variable *var1 = returnVariable(yyvsp[0].label);//pois quando tem alguma operação o $4.tmp não fica = ""
							variable ref;
							if(var1->valor != ""){
								cout<<"teste1"<<endl;
								ref.tipo = var1->tipo;
								ref.nome = yyvsp[-2].label;
								ref.valor = var1->valor;
								ref.tmp = genLabel();
								if(var1->tipo == "char *"){
									yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
									yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = (char*) malloc(" + to_string(var1->valor.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
									ref.tmp + "," + var1->tmp + " );\n";
								}
								else{
									yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
									yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = " + var1->tmp + ";\n";
								}
								if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
									vector<variable> aux;
									aux.push_back(ref);
									globalTabSym.push_back(aux);
								}
								else{
									globalTabSym[mapAtual].push_back(ref);
								}
							}
							else{
								yyerror("Voce ainda não inicialiou a variavel " + var1->nome + ".\n");
							}
						} 
						else{
							cout<<"teste2"<<endl;
							variable ref;
							ref.tipo = yyvsp[0].tipo;
							ref.nome = yyvsp[-2].label;
							ref.valor = yyvsp[0].label;
							ref.tmp = genLabel();
							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){//o tamanho da estrutura tem que ser maior que o tamanho do map
								vector<variable> aux;//pois se for igual, globalTabSym[mapAtual] não vai ter nenhum elemento, com isso tenho que adicionar um elemento(vetor nesse caso)
								aux.push_back(ref);//pra depois poder adicionar somente as variables
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							if(yyvsp[-1].tipo == "char *"){
								yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
								//$$.traducao = $5.traducao + "\t" + ref.tmp + " = " + $5.tmp + ";\n";
								yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = (char*) malloc(" + to_string(yyvsp[0].label.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
								ref.tmp + "," + yyvsp[0].tmp + " );\n";	
							}
							else{
								yyval.traducao_dec = yyvsp[0].traducao_dec + "\t" + ref.tipo + " " + ref.tmp + ";\n";
								yyval.traducao = yyvsp[0].traducao + "\t" + ref.tmp + " = " + yyvsp[0].tmp + ";\n";
							}
						}
					}
					else{
						yyerror("Declaração de variável global somente fora de função ou antes do bloco main, ambas com o modificador \"global\".\n");
					}
				}
#line 2432 "y.tab.c"
    break;

  case 30:
#line 819 "sintatico.y"
                                {
					cout<<"tk_global tk_dec_var tk_id = e"<<endl;
					if(mapAtual == 0 && entryMain == 0 || mapAtual == 0 && entryMain == 1){
						if(verifyVariableGlobal(yyvsp[-6].label) != true ){
							cout<<"teste1"<<endl;
							variable ref;
							ref.tipo = yyvsp[-1].tipo;
							ref.nome = yyvsp[-6].label;
							ref.valor = ""; 
							ref.tmp = genLabel();
							ref.vetor.isVector = "true";
							ref.vetor.tmVetor = std::to_string(auxArray.size());
							ref.vetor.tmp = genLabel();

							if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
								vector<variable> aux;
								aux.push_back(ref);
								globalTabSym.push_back(aux);
							}
							else{
								globalTabSym[mapAtual].push_back(ref);
							}
							string aux1;
							string aux2;
							aux1 = "\t" + ref.tmp + " = (" + yyvsp[-1].tipo + "*) malloc(" + std::to_string(auxArray.size()) + "* sizeof(" + yyvsp[-1].tipo + "));//vetor\n\t" + ref.vetor.tmp + " = 0;\n";
							
							for(int i = 0; i < auxArray.size(); i++){
								aux2 = aux2 + "\t" + yyvsp[-6].label + " [" + ref.vetor.tmp + "] = " + auxArrayTmp[i] + ";\n\t" + ref.vetor.tmp + " = " + ref.vetor.tmp + " + 1;\n";
							}
							
							yyval.traducao_dec = "\t" + yyvsp[-1].tipo + " = *" + ref.tmp + yyvsp[-1].traducao_dec;
							//$$.traducao ="\t" + $2.label + "[ ] = {" + $7.label + "};\n" + $7.traducao + aux1 + aux2;	
							yyval.traducao = yyvsp[-1].traducao + aux1 + aux2;
							auxArray.clear();//Limpa o array pra ser usado outra vez
							auxArrayTmp.clear();//Limpa o array pra ser usado outra vez
						}
						else{
							yyerror("Voce já declarou a variável " + yyvsp[-6].label + ".\n");
						}
					}
					else{
						yyerror("Declaração de variável global somente fora de função ou antes do bloco main, ambas com o modificador \"global\".\n");
					}
				}
#line 2481 "y.tab.c"
    break;

  case 31:
#line 867 "sintatico.y"
                                {
					if(yyvsp[-2].tipo != yyvsp[0].tipo){
						yyerror("Atribuição do tipo " + yyvsp[-2].tipo + " ao vetor de tipo " + yyvsp[0].tipo + ".\n");
					}
					else{
						yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
						yyval.tipo = yyvsp[-2].tipo;
						yyval.label = yyvsp[-2].label + " , " +  yyvsp[0].label;
						variable *var1 = returnVariable(yyvsp[-2].label);
						if(var1->valor != ""){
							auxArray.insert(auxArray.begin(),var1->nome);
							auxArrayTmp.insert(auxArrayTmp.begin(),var1->tmp);
						}
						else{
							auxArray.insert(auxArray.begin(),yyvsp[-2].label);
							auxArrayTmp.insert(auxArrayTmp.begin(),yyvsp[-2].tmp);
						}
					}
				}
#line 2505 "y.tab.c"
    break;

  case 32:
#line 887 "sintatico.y"
                                {	
					yyval = yyvsp[0];
					yyval.label = yyvsp[0].label;
					variable *var1 = returnVariable(yyvsp[0].label);
					if(var1->valor != ""){
						auxArray.insert(auxArray.begin(),var1->nome);
						auxArrayTmp.insert(auxArrayTmp.begin(),var1->tmp);
					}
					else{
						auxArray.insert(auxArray.begin(),yyvsp[0].label);
						auxArrayTmp.insert(auxArrayTmp.begin(),yyvsp[0].tmp);
					}
				}
#line 2523 "y.tab.c"
    break;

  case 33:
#line 904 "sintatico.y"
                                {
					cout<<"CHAMADA FUNCAO "<<endl;
					
					if(verifyFunction(yyvsp[-4].label)){
						Function *aux = returnFunction(yyvsp[-4].label);
						if(aux->argumentos == yyvsp[-2].tipo){
							yyval.traducao_dec = yyvsp[-2].traducao_dec;
							yyval.traducao = yyvsp[-2].traducao + "\t" + yyvsp[-4].label + "( " + yyvsp[-2].tmp + " );\n";
						}
						else{
							yyerror("Argumentos passados diferentes dos tipos de argumentos declarados na função");
						}
					}
					else{
						yyerror("Função " + yyvsp[-4].label + " não declarada.");
					}
				}
#line 2545 "y.tab.c"
    break;

  case 34:
#line 924 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 2553 "y.tab.c"
    break;

  case 35:
#line 930 "sintatico.y"
                                {
					yyval.tipo = "";
				}
#line 2561 "y.tab.c"
    break;

  case 36:
#line 934 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 2569 "y.tab.c"
    break;

  case 37:
#line 940 "sintatico.y"
                                {
					yyval.traducao_dec = yyvsp[-2].traducao_dec + yyvsp[0].traducao_dec;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao;
					yyval.tipo = yyvsp[-2].tipo + " " + yyvsp[0].tipo; 
					yyval.tmp = yyvsp[-2].tmp + " , " + yyvsp[0].tmp;
				}
#line 2580 "y.tab.c"
    break;

  case 38:
#line 947 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 2588 "y.tab.c"
    break;

  case 39:
#line 953 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 2596 "y.tab.c"
    break;

  case 40:
#line 962 "sintatico.y"
                                {
					yyval.traducao_dec = yyvsp[-1].traducao_dec + yyvsp[0].traducao_dec;
					yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
				}
#line 2605 "y.tab.c"
    break;

  case 41:
#line 967 "sintatico.y"
                                {

				}
#line 2613 "y.tab.c"
    break;

  case 42:
#line 972 "sintatico.y"
                                     {entryFunc = 1;}
#line 2619 "y.tab.c"
    break;

  case 43:
#line 973 "sintatico.y"
                                {
					cout<<"FUNCAO"<<endl;

					if(yyvsp[-6].label == "void" && tipoRetorno != ""){
						yyerror("Função " + yyvsp[-4].label+ " é tipo void e não apresenta retorno.");
					}
					if(yyvsp[-6].label != "void" && tipoRetorno == ""){
						yyerror("Função " + yyvsp[-4].label + " diferente de void sem retorno.");
					}
					if(yyvsp[-6].label != "void" && yyvsp[-6].label != tipoRetorno){
						yyerror("Tipo do retorno da função " + yyvsp[-4].label + " diferente do tipo declarado na função.");
					}
					Function func;
					func.retorno = yyvsp[-6].label;
					func.nome = yyvsp[-4].label;
					func.argumentos = yyvsp[-2].label;
					//func.bloco.traducao_dec = $7.traducao_dec;
					//func.bloco.traducao = $7.traducao;
				 	funcoes.push_back(func);

					yyval.traducao_dec = yyvsp[-2].traducao_dec + yyvsp[0].traducao_dec;
					yyval.traducao = yyvsp[-6].label + " " + yyvsp[-4].label + " ( " + yyvsp[-2].traducao + " ){\n" + yyvsp[0].traducao + "}\n";
					if(mapAtual > 0){
						globalTabSym.pop_back();
						mapAtual--;
					}
					else{
						globalTabSym[mapAtual].clear();
					}
					entryFunc = 0;
					tipoRetorno = "";
				}
#line 2656 "y.tab.c"
    break;

  case 44:
#line 1007 "sintatico.y"
                                {
					yyval.label = "float";
				}
#line 2664 "y.tab.c"
    break;

  case 45:
#line 1011 "sintatico.y"
                                {
					yyval.label = "void";
				}
#line 2672 "y.tab.c"
    break;

  case 46:
#line 1015 "sintatico.y"
                                {
					yyval.label = "char";
				}
#line 2680 "y.tab.c"
    break;

  case 47:
#line 1019 "sintatico.y"
                                {
					yyval.label = "int";
				}
#line 2688 "y.tab.c"
    break;

  case 48:
#line 1025 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 2696 "y.tab.c"
    break;

  case 49:
#line 1031 "sintatico.y"
                                {

				}
#line 2704 "y.tab.c"
    break;

  case 50:
#line 1035 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 2712 "y.tab.c"
    break;

  case 51:
#line 1041 "sintatico.y"
                                {
					cout<<"tipo argumento tk_id ; morearguments "<<mapAtual<<endl;
					variable ref;
					ref.tipo = yyvsp[-3].label;
					ref.nome = yyvsp[-2].label;
					ref.valor = ""; 
					ref.tmp = genLabel();
						
					if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
						vector<variable> aux;
						aux.push_back(ref);
						globalTabSym.push_back(aux);
					}
					else{
						globalTabSym[mapAtual].push_back(ref);
					}
					
					yyval.label = yyvsp[-3].label + " " + yyvsp[0].label;
					yyval.traducao_dec = "\t" + yyvsp[-3].label + " " + ref.tmp + ";\n" + yyvsp[0].traducao_dec;
					yyval.traducao = yyvsp[-3].label + " " + ref.tmp + " , " + yyvsp[0].traducao;
				}
#line 2738 "y.tab.c"
    break;

  case 52:
#line 1063 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 2746 "y.tab.c"
    break;

  case 53:
#line 1069 "sintatico.y"
                                {
					cout<<"tipoargumento tk_id "<<mapAtual<<endl;
					variable ref;
					ref.tipo = yyvsp[-1].label;
					ref.nome = yyvsp[0].label;
					ref.valor = ""; 
					ref.tmp = genLabel();
						
					if(globalTabSym.empty() == 1 || globalTabSym.empty() == 0 && globalTabSym.size() == mapAtual ){
						vector<variable> aux;
						aux.push_back(ref);
						globalTabSym.push_back(aux);
					}
					else{
						globalTabSym[mapAtual].push_back(ref);
					}
					
					yyval.label = yyvsp[-1].label;
					yyval.traducao_dec = "\t" + yyvsp[-1].label + " " + ref.tmp + ";\n";
					yyval.traducao = yyvsp[-1].label + " " + ref.tmp;
				}
#line 2772 "y.tab.c"
    break;

  case 55:
#line 1094 "sintatico.y"
                                {
					yyval.label = "float";
				}
#line 2780 "y.tab.c"
    break;

  case 56:
#line 1098 "sintatico.y"
                                {
					yyval.label = "char";	
				}
#line 2788 "y.tab.c"
    break;

  case 57:
#line 1102 "sintatico.y"
                                {
					yyval.label = "int";
				}
#line 2796 "y.tab.c"
    break;

  case 58:
#line 1109 "sintatico.y"
                                {	
					cout<<"tk_input ( E )"<<endl;
					if(verifyVariableGlobal(yyvsp[-1].label)){
						cout<<"teste1"<<endl;
						variable *var1 = returnVariable(yyvsp[-1].label);
						
						if(var1->tipo == ""){
							string aux = genLabel();
							yyval.traducao_dec = yyvsp[-1].traducao_dec;
							yyval.traducao = yyvsp[-1].traducao + "\tinput( " + var1->nome + " );\n" + "\t" + var1->tmp + " = " + aux + ";\n";
							yyval.traducao = "\tcin >> " + var1->tmp + ";\n";
						}
						else{
							string aux = genLabel();
							yyval.traducao_dec = yyvsp[-1].traducao_dec + "\t" + var1->tipo + " " + aux + ";\n";
							yyval.traducao = yyvsp[-1].traducao + "\tinput( " + var1->nome + " );\n" + "\t" + var1->tmp + " = " + aux + ";\n";
							yyval.traducao = "\tcin >> " + var1->tmp + ";\n";
						}
					}
					else{
						yyerror("Você não declarou a variável " + yyvsp[-1].label + "\n");
					}
				}
#line 2824 "y.tab.c"
    break;

  case 59:
#line 1135 "sintatico.y"
                                {
					cout<<"tk_saida ( E )"<<endl;
					if(verifyVariableGlobal(yyvsp[-1].label)){
						cout<<"teste1"<<endl;
						variable *var1 = returnVariable(yyvsp[-1].label);
						yyval.traducao_dec = yyvsp[-1].traducao_dec;
						yyval.traducao = yyvsp[0].traducao + "\tcout << " + var1->tmp + ";\n";
					}
					else{
						yyerror("Você não declarou a variável " + yyvsp[-1].label + "\n");
					}
				}
#line 2841 "y.tab.c"
    break;

  case 60:
#line 1149 "sintatico.y"
                                    {Execucao atual = genBlock("If");
					loops.push(atual);}
#line 2848 "y.tab.c"
    break;

  case 61:
#line 1151 "sintatico.y"
                                {
					cout<<"TK_IF"<<endl;
					variable *var1 = returnVariable(yyvsp[-2].label);
					string aux = genLabel();
					if(yyvsp[-2].tipo == "bool"){
						yyval.traducao_dec = yyvsp[-2].traducao_dec + yyvsp[0].traducao_dec + "\tint " + aux + ";\n";
						yyval.traducao = yyvsp[-2].traducao + "\t" + aux + " = " + yyvsp[-2].tmp + ";\n\tif ( !" + aux + ") goto " + loops.top().Fim + ";\n\t{\n" + yyvsp[0].traducao + "\t}\n\t" + 
						loops.top().Fim + ":\n";
					}
					else if(var1->nome == yyvsp[-2].label && var1->tipo != "char"){
						yyval.traducao_dec = yyvsp[-2].traducao_dec + yyvsp[0].traducao_dec + "\tint " + aux + ";\n";
						yyval.traducao = yyvsp[-2].traducao + "\t" + aux + " = " + var1->tmp + ";\n\tif ( !" + aux + ") goto " + loops.top().Fim + ";\n\t{\n" + yyvsp[0].traducao + "\t}\n\t" +
						loops.top().Fim + ":\n";
					}
					else{
						yyerror("Somente expressões booleanas são validas dentro da condicional");
					}
				}
#line 2871 "y.tab.c"
    break;

  case 62:
#line 1172 "sintatico.y"
                                {
					yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
				}
#line 2879 "y.tab.c"
    break;

  case 63:
#line 1177 "sintatico.y"
                                 {if(mapAtual > 0){
								globalTabSym.pop_back();
							 }}
#line 2887 "y.tab.c"
    break;

  case 64:
#line 1180 "sintatico.y"
                                {
					valorBlock--;
					Execucao atual = genBlock("Else");
					variable *var1 = returnVariable(yyvsp[-3].label);
					string aux = genLabel();
					if(yyvsp[-3].tipo == "bool"){
						yyval.traducao_dec = yyvsp[-3].traducao_dec + yyvsp[-1].traducao_dec + "\tint " + aux + ";\n" + yyvsp[0].traducao_dec;
						yyval.traducao = yyvsp[-3].traducao + "\t" + aux + " = " + yyvsp[-3].tmp + ";\n\tif ( !" + aux + ") goto " + atual.Fim + ";\n\t{\n" + yyvsp[-1].traducao + "\t}\n\t" + 
						atual.Fim + ":\n" + yyvsp[0].traducao;
					}
					else if(var1->nome == yyvsp[-3].label && var1->tipo != "char"){
						yyval.traducao_dec = yyvsp[-3].traducao_dec + yyvsp[-1].traducao_dec + "\tint " + aux + ";\n" + yyvsp[0].traducao_dec;
						yyval.traducao = yyvsp[-3].traducao + "\t" + aux + " = " + var1->tmp + ";\n\tif ( !" + aux + ") goto " + atual.Fim + ";\n\t{\n" + yyvsp[-1].traducao + "\t}\n\t" + 
						atual.Fim + ":\n" + yyvsp[0].traducao;
					}
					else{
						yyerror("Somente expressões booleanas são validas dentro da condicional");
					}
				}
#line 2911 "y.tab.c"
    break;

  case 65:
#line 1199 "sintatico.y"
                                         {if(mapAtual > 0){
								globalTabSym.pop_back();
							 }}
#line 2919 "y.tab.c"
    break;

  case 66:
#line 1202 "sintatico.y"
                                {
					valorBlock--;
					Execucao atual = genBlock("Else");
					cout<<"Else"<<endl;
					yyval.traducao_dec = yyvsp[0].traducao_dec;
					yyval.traducao = "\t" + atual.Inicio + ":\n\t{\n"+ yyvsp[0].traducao + "\t}\n\t" + atual.Fim + ":\n";
				}
#line 2931 "y.tab.c"
    break;

  case 67:
#line 1211 "sintatico.y"
                                         {Execucao atual = genBlock("For");
					loops.push(atual);}
#line 2938 "y.tab.c"
    break;

  case 68:
#line 1213 "sintatico.y"
                                {	
					string inicio = loops.top().Inicio;
					string fim = loops.top().Fim;
					//Empilha os nomes de inicio e fim dos blocos
					cout<<"TK_FOR()"<<endl;
					string aux = genLabel();

					if(yyvsp[-4].tipo != "bool"){
						yyerror("Condição de verificação precisa ser booleana.");
					}

					int posChange = yyvsp[-4].traducao.find_first_of(";");
					posChange++;
					yyvsp[-4].traducao.insert(posChange, "\n"+ inicio+":" ); // Inicio -> Inicio bloco
					yyval.traducao_dec = yyvsp[-6].traducao_dec + yyvsp[-4].traducao_dec + yyvsp[-2].traducao_dec + yyvsp[0].traducao_dec;
					//$$.traducao = "\tfor( " + $4.label + " ; " + $6.tmp + " ; " + $8.label + "++ ){";
					yyval.traducao = "\n" + yyvsp[-6].traducao + yyvsp[-4].traducao + "\t" + aux + " = !( " + yyvsp[-4].tmp + " );\n\tif( " +
					aux + " ) goto "+ fim +";\n\t{\n" + yyvsp[0].traducao + "\t}\n" + yyvsp[-2].traducao + "\tgoto "+ inicio +";\n"+fim+":\n";
				}
#line 2962 "y.tab.c"
    break;

  case 69:
#line 1234 "sintatico.y"
                                   {Execucao atual = genBlock("While");
					loops.push(atual);}
#line 2969 "y.tab.c"
    break;

  case 70:
#line 1236 "sintatico.y"
                                {
					cout<<"TK_WHILE()"<<endl;
					variable *var1 = returnVariable(yyvsp[-2].label);
					string aux = genLabel();
					string inicio = loops.top().Inicio;
					string fim = loops.top().Fim;
					if(var1->nome == yyvsp[-2].label && var1->tipo != "char"){
						yyval.traducao_dec = yyvsp[-2].traducao_dec + yyvsp[0].traducao_dec + "\tint " + aux + ";\n";
						yyval.traducao = "\n" + inicio + ":\n" + "\t" + aux + " = !( " + var1->tmp + " );\n\tif( " + aux + " ) goto "+fim+";\n\t{\n" +       
						yyvsp[0].traducao + "\t}\n\tgoto "+ inicio +";\n"+fim+":\n";
					}
					else if(yyvsp[-2].tipo == "bool"){
						int posChange = yyvsp[-2].traducao.find_first_of(";");
						posChange = yyvsp[-2].traducao.find(";",posChange + 1);
						posChange++;
						//cout<<"temp 4"<<$4.tmp<<endl;
						yyvsp[-2].traducao.insert(posChange, "\n"+inicio+":");
						yyval.traducao_dec = yyvsp[-2].traducao_dec + yyvsp[0].traducao_dec + + "\tint " + aux + ";\n";
						yyval.traducao = "\n" + yyvsp[-2].traducao  + "\t" + aux + " = !( " + yyvsp[-2].tmp + " );\n\tif( " + aux + " ) goto "+fim+";\n\t{\n" +       
						yyvsp[0].traducao + "\t}\n\tgoto "+inicio+";\n"+fim+":\n";
					}
					else{
						yyerror("Expressão de condição não permitida\n");
					}
				}
#line 2999 "y.tab.c"
    break;

  case 71:
#line 1263 "sintatico.y"
                                {Execucao atual = genBlock("DoWhile");
					loops.push(atual);}
#line 3006 "y.tab.c"
    break;

  case 72:
#line 1265 "sintatico.y"
                                {
					string inicio = loops.top().Inicio;
					string fim = loops.top().Fim;
					cout<<"TK_DO WHILE()"<<endl;
					variable *var1 = returnVariable(yyvsp[-1].label);
					string aux = genLabel();

					if(var1->nome == yyvsp[-1].label && var1->tipo != "char"){
						yyval.traducao_dec = yyvsp[-4].traducao_dec + yyvsp[-1].traducao_dec + "\tint " + aux + ";\n";
						yyval.traducao = "\n"+inicio+":\n\t{\n" + yyvsp[-4].traducao + "\t}\n\t"+ aux + " = !( " + var1->tmp + " );\n\tif( " + aux + " ) goto "+fim+"\n" + yyvsp[-1].traducao +
						"\tgoto "+inicio+";" + "\n"+fim+":\n";
					}
					else if(yyvsp[-1].tipo == "bool"){
						yyval.traducao_dec = yyvsp[-4].traducao_dec + yyvsp[-1].traducao_dec;
						yyval.traducao = "\n"+inicio+":\n\t{\n" + yyvsp[-4].traducao + "\t}\n\t"+ aux + " = !( " + yyvsp[-1].tmp + " );\n\tif( " + aux + " ) goto " + fim +"\n"+ yyvsp[-1].traducao +
						"\tgoto "+inicio+";" +"\n"+fim+":\n";
					}
					else{
						yyerror("Expressão de condição não permitida\n");
					}
				}
#line 3032 "y.tab.c"
    break;

  case 73:
#line 1288 "sintatico.y"
                            {Execucao atual = genBlock("Switch");
					loops.push(atual);}
#line 3039 "y.tab.c"
    break;

  case 74:
#line 1290 "sintatico.y"
                {
                    cout<<"TK_Switch"<<endl;
                }
#line 3047 "y.tab.c"
    break;

  case 79:
#line 1304 "sintatico.y"
                {
                }
#line 3054 "y.tab.c"
    break;

  case 80:
#line 1309 "sintatico.y"
                                {
					
				}
#line 3062 "y.tab.c"
    break;

  case 81:
#line 1315 "sintatico.y"
                                {
					if(loops.empty() == true){
						yyerror("Comando break fora de um loop.\n");
					}
					yyval.traducao = "\n\tgoto " + loops.top().Fim + ";//Break\n";
				}
#line 3073 "y.tab.c"
    break;

  case 82:
#line 1324 "sintatico.y"
                                {
					if(loops.empty() == true){
						yyerror("Comando continue fora de um loop.\n");
					}
					yyval.traducao = "\n\tgoto " + loops.top().Inicio + ";//Continue\n";
				}
#line 3084 "y.tab.c"
    break;

  case 83:
#line 1334 "sintatico.y"
                                {
					cout<<"E+E"<<endl;
					//operacao = "soma";
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "soma");
				}
#line 3094 "y.tab.c"
    break;

  case 84:
#line 1340 "sintatico.y"
                                {
					cout<<"E-E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "subtracao");
				}
#line 3103 "y.tab.c"
    break;

  case 85:
#line 1345 "sintatico.y"
                                {
					cout<<"E*E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "multiplicacao");
				}
#line 3112 "y.tab.c"
    break;

  case 86:
#line 1350 "sintatico.y"
                                {
					cout<<"E/E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "divisao");
				}
#line 3121 "y.tab.c"
    break;

  case 87:
#line 1355 "sintatico.y"
                                {
					cout<<"E TK_LESS E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "tk_less");
				}
#line 3130 "y.tab.c"
    break;

  case 88:
#line 1360 "sintatico.y"
                                {
					cout<<"E TK_LE E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "tk_greater");
				}
#line 3139 "y.tab.c"
    break;

  case 89:
#line 1365 "sintatico.y"
                                {
					cout<<"E TK_LE E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "tk_le");
				}
#line 3148 "y.tab.c"
    break;

  case 90:
#line 1370 "sintatico.y"
                                {
					cout<<"E TK_HE E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "tk_he");
				}
#line 3157 "y.tab.c"
    break;

  case 91:
#line 1375 "sintatico.y"
                                {
					cout<<"E TK_EQ E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "tk_eq");
				}
#line 3166 "y.tab.c"
    break;

  case 92:
#line 1380 "sintatico.y"
                                {
					cout<<"E TK_DIFF E"<<endl;
					criaOperacao(&yyval, yyvsp[-2], yyvsp[0], "tk_diff");
				}
#line 3175 "y.tab.c"
    break;

  case 93:
#line 1385 "sintatico.y"
                                {
					cout<<"TK_ID TK_UN_SUM"<<endl;
					if(verifyVariableGlobal(yyvsp[-1].label) == false){
						yyerror("Você não declarou a variável " + yyvsp[-1].label + "\n");	
					}
					variable *v1 = returnVariable(yyvsp[-1].label);
					string aux = genLabel();
					
					if(v1->tipo == ""){
						v1->tipo = "int";
						v1->valor = "0";
						yyval.traducao_dec = yyvsp[-1].traducao_dec + "\tint " + v1->tmp + ";\n" + "\tint " + aux + ";\n";
						yyval.traducao = yyvsp[-1].traducao + "\t" + aux + " = 1;\n" + "\t" +  v1->tmp + " = " + v1->tmp + " + " + aux + ";\n";
					}
					else if(v1->tipo == "float" || v1->tipo == "int"){
						yyval.traducao_dec = yyvsp[-1].traducao_dec + "\t" + v1->tipo + " " + aux + ";\n";
						yyval.traducao = yyvsp[-1].traducao + "\t" + aux + " = 1;\n" + "\t" +  v1->tmp + " = " + v1->tmp + " + " + aux + ";\n";
					}
					else{
						yyerror("Soma não permitida\n");		
					}
				}
#line 3202 "y.tab.c"
    break;

  case 94:
#line 1408 "sintatico.y"
                                {
					cout<<"TK_ID TK_UN_SUB"<<endl;
					if(verifyVariableGlobal(yyvsp[-1].label) == false){
						yyerror("Você não declarou a variável " + yyvsp[-1].label + "\n");	
					}
					variable *v1 = returnVariable(yyvsp[-1].label);
					string aux = genLabel();
					
					if(v1->tipo == ""){
						v1->tipo = "int";
						v1->valor = "0";
						yyval.traducao_dec = yyvsp[-1].traducao_dec + "\tint " + v1->tmp + ";\n" + "\tint " + aux + ";\n";
						yyval.traducao = yyvsp[-1].traducao + "\t" + aux + " = 1;\n" + "\t" +  v1->tmp + " = " + v1->tmp + " - " + aux + ";\n";
					}
					else if(v1->tipo == "float" || v1->tipo == "int"){
						yyval.traducao_dec = yyvsp[-1].traducao_dec + "\t" + v1->tipo + " " + aux + ";\n";
						yyval.traducao = yyvsp[-1].traducao + "\t" + aux + " = 1;\n" + "\t" +  v1->tmp + " = " + v1->tmp + " - " + aux + ";\n";
					}
					else{
						yyerror("Soma não permitida\n");		
					}
				}
#line 3229 "y.tab.c"
    break;

  case 95:
#line 1431 "sintatico.y"
                                {
					if(yyvsp[-1].tmp != ""){
						//---------------------------------- Uma forma --------------------------------//
						//string aux = genLabel();
						//$$.traducao_dec = $2.traducao_dec + $6.traducao_dec;
						//$$.traducao = $2.traducao + $6.traducao;
						//$$.tmp = $2.tmp + "&&" + $6.tmp;
						//---------------------------------- Outra forma --------------------------------//
						string aux = genLabel();
						yyval.traducao_dec = yyvsp[-1].traducao_dec + "\tint " + aux + ";\n";
						yyval.traducao = yyvsp[-1].traducao + "\t" +  aux + " = " + yyvsp[-1].tmp + ";\n";
						yyval.tipo = "int";
						yyval.tmp = "!(" + aux + ")";
					}
					else{
						yyerror("Comparação não permitida\n");
					}
				}
#line 3252 "y.tab.c"
    break;

  case 96:
#line 1450 "sintatico.y"
                                {
					if(yyvsp[-5].tmp != "" && yyvsp[-1].tmp != ""){
						string aux = genLabel();
						string aux1 = genLabel();
						yyval.traducao_dec = yyvsp[-5].traducao_dec + yyvsp[-1].traducao_dec + "\tint " + aux + ";\n" + "\tint " + aux1 + ";\n";
						yyval.traducao = yyvsp[-5].traducao + yyvsp[-1].traducao + "\t" +  aux + " = " + yyvsp[-5].tmp + ";\n" + "\t" +  aux1 + " = " + yyvsp[-1].tmp + ";\n";
						yyval.tipo = "int";
						yyval.tmp = aux + " || " + aux1;
					}
					else{
						yyerror("Comparação não permitida\n");
					}	
				}
#line 3270 "y.tab.c"
    break;

  case 97:
#line 1464 "sintatico.y"
                                {
					if(yyvsp[-5].tmp != "" && yyvsp[-1].tmp != ""){
						//---------------------------------- Uma forma --------------------------------//
						//string aux = genLabel();
						//$$.traducao_dec = $2.traducao_dec + $6.traducao_dec;
						//$$.traducao = $2.traducao + $6.traducao;
						//$$.tmp = $2.tmp + "&&" + $6.tmp;
						//---------------------------------- Outra forma --------------------------------//
						string aux = genLabel();
						string aux1 = genLabel();
						yyval.traducao_dec = yyvsp[-5].traducao_dec + yyvsp[-1].traducao_dec + "\tint " + aux + ";\n" + "\tint " + aux1 + ";\n";
						yyval.traducao = yyvsp[-5].traducao + yyvsp[-1].traducao + "\t" +  aux + " = " + yyvsp[-5].tmp + ";\n" + "\t" +  aux1 + " = " + yyvsp[-1].tmp + ";\n";
						yyval.tipo = "int";
						yyval.tmp = aux + " && " + aux1;
					}
					else{
						yyerror("Comparação não permitida\n");
					}
				}
#line 3294 "y.tab.c"
    break;

  case 98:
#line 1484 "sintatico.y"
                                {
					cout<<"tk_id = E"<<endl;
					bool encontrei = false;
					bool found = false;
					encontrei = verifyVariableGlobal(yyvsp[-2].label);
					found = verifyVariableGlobal(yyvsp[0].label);
					variable *var1 = returnVariable(yyvsp[-2].label);
					variable *var2 = returnVariable(yyvsp[0].label);

				//------------------------------------------------ Atribuições sem valores iniciais ------------------------------------------------//
					if(encontrei == true && found == true && var1->tipo == "" && var2->tipo != "" && yyvsp[0].tmp == "")  {//Se o $3.tmp for igual a vazio a atribuição é somente de variável
						if(var2->tipo == "char *"){//e não da soma de duas coisas, pois se fosse da soma de duas coisas o $3.tmp iria ter valor
							var1->valor = var2->valor;
							var1->tipo = var2->tipo;
							yyval.traducao_dec ="\t" + var1->tipo + " " + var1->tmp + ";\n";
							yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " =  (char *) malloc(" + to_string(var2->valor.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
							var1->tmp + "," + var2->tmp + " );\n";
						}
						else{
							var1->valor = var2->valor;
							var1->tipo = var2->tipo;
							yyval.traducao_dec ="\t" + var1->tipo + " " + var1->tmp + ";\n";
							yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = " + var2->tmp + ";\n"; 
						}
						cout<<"Tst1"<<endl;
					}
					else if(encontrei == true && var1->tipo == ""){
						if(yyvsp[0].tipo == "char *"){
							var1->valor = yyvsp[0].label;
							var1->tipo = yyvsp[0].tipo;
							yyval.traducao_dec = "\t" + var1->tipo + " " + var1->tmp + ";\n" + yyvsp[0].traducao_dec;
							yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " =  (char *) malloc(" + to_string(yyvsp[0].label.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
							var1->tmp + "," + yyvsp[0].tmp + " );\n";
						}
						else{
							var1->valor = yyvsp[0].label;
							var1->tipo = yyvsp[0].tipo;
							yyval.traducao_dec = "\t" + var1->tipo + " " + var1->tmp + ";\n" + yyvsp[0].traducao_dec;
							yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = " + yyvsp[0].tmp +  ";\n";
						}
						cout<<"Tst2"<<endl;
					}
				//------------------------------------------------ Atribuições com valores iniciais ------------------------------------------------//
					else if(encontrei == true && found == true && var1->tipo == "float" && var2->tipo == "int" ){//If que verifica se a variavel que está recebendo
						string aux = genLabel();
						var1->valor = var2->valor;//a atribuição é do tipo float, permitindo ser adicionado uma variável do tipo int ou float
						//Não preciso do traducao_dec pois a variavel que está recebendo a atribuição e a variável que está sendo atribuida, já foram inicializadas
						
						if(var2->tmp.size() < 8){
							yyval.traducao_dec = yyvsp[0].traducao_dec + "\tfloat " + aux + ";\n";
							yyval.traducao = "\t" + aux + " = (float)" + var2->tmp + ";\n" + "\t" + var1->tmp + " = " + aux + ";\n";//Não preciso propagar o $3.traducao pois eles ja foram feitos antes
						}
						else{
							string aux1 = genLabel();
							yyval.traducao_dec = yyvsp[0].traducao_dec + "\tint " + aux + ";\n" + "\tfloat " + aux1 + ";\n";
							yyval.traducao = "\t" + aux + " = " + var2->tmp + ";\n" + "\t" + aux1 + " = (float)" + aux + ";\n" + "\t" + var1->tmp + " = " + aux1 + ";\n";
						}
						cout<<"Tst3"<<endl;
					}
					//else if(encontrei == true && var1->tipo == "float" && ($3.tipo == "int" || $3.tipo == "float"))
					else if(encontrei == true && var1->tipo == "float" && yyvsp[0].tipo == "int"){//Verifica se a variável que está recebendo a atribuição é do tipo
						string aux = genLabel();
						var1->valor = yyvsp[0].label;//float e se o valor qualquer adicionado é do tipo int ou float para fazer a atribuição

						if(yyvsp[0].tmp.size() < 8){
							yyval.traducao_dec = yyvsp[0].traducao_dec + "\tfloat " + aux + ";\n";
							yyval.traducao = yyvsp[0].traducao + "\t" + aux + " = (float)" + yyvsp[0].tmp + ";\n" + "\t" + var1->tmp + " = " + aux + ";\n";
						}
						else{
							string aux1 = genLabel();
							yyval.traducao_dec = yyvsp[0].traducao_dec + "\tint " + aux + ";\n" + "\tfloat " + aux1 + ";\n";
							yyval.traducao = yyvsp[0].traducao + "\t" + aux + " = " + yyvsp[0].tmp + ";\n" + "\t" + aux1 + " = (float)" + aux + ";\n" + "\t" + var1->tmp + " = " + aux1 + ";\n" ;
						}
						cout<<"Tst4"<<endl;
					}
					else if(encontrei == true && found == true && var1->tipo != "" && var1->tipo == var2->tipo && yyvsp[0].tmp == ""){//Verifica se o termo a ser atribuido é do mesmo tipo da variável a recebe-lo
						
						if(var2->tipo == "char *"){//e não da soma de duas coisas, pois se fosse da soma de duas coisas o $3.tmp iria ter valor
							var1->valor = var2->valor;
							yyval.traducao_dec = yyvsp[0].traducao_dec;
							yyval.traducao = "\t" + var1->tmp + " =  (char *) malloc(" + to_string(var2->valor.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
							var1->tmp + "," + var2->tmp + " );\n";
						}
						else{
							var1->valor = var2->valor;
							yyval.traducao_dec = yyvsp[0].traducao_dec;
							yyval.traducao ="\t" + var1->tmp + " = " + var2->tmp + ";\n";//Salva o novo valor na variavel e na tabela de simbolos
						}
						cout<<"Tst5"<<endl;
					}
					else if(encontrei == true && var1->tipo == yyvsp[0].tipo){//Verifica se o termo a ser atribuido é um valor qualquer
						
						if(yyvsp[0].tipo == "char *"){
							var1->valor = yyvsp[0].label;
							yyval.traducao_dec = yyvsp[0].traducao_dec;
							yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " =  (char *) malloc(" + to_string(yyvsp[0].label.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + 
							var1->tmp + "," + yyvsp[0].tmp + " );\n";
						}
						else{
							var1->valor = yyvsp[0].label;
							yyval.traducao_dec = yyvsp[0].traducao_dec;
							yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = " + yyvsp[0].tmp + ";\n";
						}
						cout<<"Tst6"<<endl;
					}
					else if(found == true && var2->valor == ""){
						yyerror("Você não inicializou a variável " + yyvsp[0].label + ".\n");
					}
					else if(encontrei == false){
						yyerror("Você não declarou a variavel " + yyvsp[-2].label + ".\n");	
					}
					else{
						yyerror("Atribuição não permitida, tipo da variável a ser atribuida é diferente do tipo de atribuição.\n");
					}
				}
#line 3414 "y.tab.c"
    break;

  case 99:
#line 1600 "sintatico.y"
                                {
					bool encontrei = false;
					bool found = false;
					encontrei = verifyVariableGlobal(yyvsp[-4].label);
					found = verifyVariableGlobal(yyvsp[-1].label);
					variable *var1 = returnVariable(yyvsp[-4].label);
					variable *var2 = returnVariable(yyvsp[-1].label);
				
				//------------------------------------------------ Atribuições sem valores iniciais ------------------------------------------------//
					if(encontrei == true && found == true && var1->tipo == "" && var2->tipo != "" && var2->tipo != "bool" && yyvsp[-1].tmp == ""){
						var1->tipo = var2->tipo;
						yyval.traducao_dec = yyvsp[-1].traducao_dec + "\t" + var1->tipo + " *" + var1->tmp + ";\n";
						yyval.traducao = "\t" + var1->tmp + " = (" + var1->tipo + "*) malloc( 1 * sizeof(" + var1->tipo + "));//vetor\n\t" + var1->vetor.tmp + " = 0;\n" + 
						"\t" + var1->nome + "[" + var1->vetor.tmp + "] = " + var2->tmp + ";\n\t" + var1->vetor.tmp + " = " + var1->vetor.tmp + " + 1;\n";
					}
					else if(encontrei == true && found == false && var1->tipo == "" && yyvsp[-1].tipo != "bool"){
						var1->tipo = yyvsp[-1].tipo;
						yyval.traducao_dec = yyvsp[-1].traducao_dec + "\t" + var1->tipo + " *" + var1->tmp + ";\n";
						yyval.traducao = yyvsp[-1].traducao + "\t" + var1->tmp + " = (" + var1->tipo + "*) malloc( 1 * sizeof(" + var1->tipo + "));//vetor\n\t" + var1->vetor.tmp + " = 0;\n" + 
						"\t" + var1->nome + "[" + var1->vetor.tmp + "] = " + yyvsp[-1].tmp + ";\n\t" + var1->vetor.tmp + " = " + var1->vetor.tmp + " + 1;\n";
					}
				//------------------------------------------------ Atribuições com valores iniciais ------------------------------------------------//	
					else if(encontrei == true && found == true && var1->tipo != "" && var1->tipo != "bool" && var1->tipo == var2->tipo && yyvsp[-1].tmp == ""){
						yyval.traducao_dec = yyvsp[-1].traducao_dec;
						yyval.traducao = yyvsp[-1].traducao + "\t" + var1->tmp + " = (" + var1->tipo + "*) realloc(" + var1->tmp + " , " + var1->vetor.tmVetor + 
						" + 1 * sizeof(" + var1->tipo + "));//vetor\n" + "\t" + var1->nome + "[" + var1->vetor.tmp + "] = " + var2->tmp + ";\n\t" + var1->vetor.tmp + " = " + 
						var1->vetor.tmp + " + 1;\n";
						int aux = std::stoi(var1->vetor.tmVetor) + 1;
						var1->vetor.tmVetor = to_string(aux);
					}
					else if(encontrei == true && var1->tipo != "" && var1->tipo != "bool" && var1->tipo == yyvsp[-1].tipo ){
						yyval.traducao_dec = yyvsp[-1].traducao_dec;
						yyval.traducao = yyvsp[-1].traducao + "\t" + var1->tmp + " = (" + var1->tipo + "*) realloc(" + var1->tmp + " , " + var1->vetor.tmVetor + 
						" + 1 * sizeof(" + var1->tipo + "));//vetor\n" + "\t" + var1->nome + "[" + var1->vetor.tmp + "] = " + yyvsp[-1].tmp + ";\n\t" + var1->vetor.tmp + " = " + 
						var1->vetor.tmp + " + 1;\n";
						int aux = std::stoi(var1->vetor.tmVetor) + 1;
						var1->vetor.tmVetor = to_string(aux);
					}	
					else if(found == true && var2->valor == ""){
						yyerror("Você não inicializou a variável " + yyvsp[-1].label + ".\n");
					}
					else if(encontrei == false){
						yyerror("Variável " + yyvsp[-4].label + " não declarada.\n");
					}
					else{
						yyerror("Atribuição não permitida, tipo da variável a ser atribuida é diferente do tipo do vetor.\n");
					}
				}
#line 3467 "y.tab.c"
    break;

  case 100:
#line 1649 "sintatico.y"
                                {
					cout<<"tk_id = (TK_TIPO_INT) E"<<endl;
					bool encontrei = false;
					bool found = false;
					encontrei = verifyVariableGlobal(yyvsp[-5].label);
					found = verifyVariableGlobal(yyvsp[0].label);
					variable *var1 = returnVariable(yyvsp[-5].label);
					variable *var2 = returnVariable(yyvsp[0].label);

					//------------------------------------------------ Atribuições sem valores iniciais ------------------------------------------------//
					if(encontrei == true && found == true && var1->tipo == "" && var2->tipo == "float" && yyvsp[0].tmp == ""){//Se o $3.tmp for igual a vazio a atribuição é somente de variável
						int aux = std::stoi(var2->valor);
						var1->valor = std::to_string(aux);//e não da soma de duas coisas, pois se fosse da soma de duas coisas
						var1->tipo = "int";//o $3.tmp iria ter valor			
						yyval.traducao_dec ="\t" + var1->tipo + " " + var1->tmp + ";\n";
						yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = (int)" + var2->tmp + ";\n";
						cout<<"Tst1"<<endl;
					}
					else if(encontrei == true && var1->tipo == "" && yyvsp[0].tipo == "float"){
						int aux = std::stoi(yyvsp[0].label);
						var1->valor = std::to_string(aux);
						var1->tipo = "int";
						yyval.traducao_dec = "\t" + var1->tipo + " " + var1->tmp + ";\n" + yyvsp[0].traducao_dec;
						yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = (int)" + yyvsp[0].tmp +  ";\n";
						cout<<"Tst2"<<endl;
					}
					//------------------------------------------------ Atribuições com valores iniciais ------------------------------------------------//
					else if(encontrei == true && found == true && var1->tipo == "int" && var2->tipo == "float" ){//If que verifica se a variavel que está recebendo
						int aux = std::stoi(var2->valor);
						var1->valor = std::to_string(aux);//a atribuição é do tipo float, permitindo ser adicionado uma variável do tipo int ou float
						var1->tipo = "int";//Não preciso do traducao_dec pois a variavel que está recebendo a atribuição e a variável que está sendo atribuida, já foram inicializadas
						yyval.traducao_dec = yyvsp[0].traducao_dec;
						yyval.traducao = "\t" + var1->tmp + " = (int)" + var2->tmp + ";\n";//Não preciso propagar o $3.traducao pois eles ja foram feitos antes
						cout<<"Tst3"<<endl;
					}
					else if(encontrei == true && var1->tipo == "int" && yyvsp[0].tipo == "float"){//Verifica se a variável que está recebendo a atribuição é do tipo
						int aux = std::stoi(yyvsp[0].label);
						var1->valor = std::to_string(aux);//float e se o valor qualquer adicionado é do tipo int ou float para fazer a atribuição
					 	var1->tipo = "int";
						yyval.traducao_dec = yyvsp[0].traducao_dec;
						yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = (int)" + yyvsp[0].tmp + ";\n" ;

						cout<<"Tst4"<<endl;
					}
					else if(found == true && var2->valor == ""){
						yyerror("Você não inicializou a variável " + yyvsp[0].label + ".\n");
					}
					else{
						yyerror("Atribuição não permitida, tipo da variável a ser atribuida é diferente do tipo de atribuição.\n");
					}
				}
#line 3523 "y.tab.c"
    break;

  case 101:
#line 1701 "sintatico.y"
                                {
					cout<<"tk_id = (TK_TIPO_FLOAT) E"<<endl;
					bool encontrei = false;
					bool found = false;
					encontrei = verifyVariableGlobal(yyvsp[-5].label);
					found = verifyVariableGlobal(yyvsp[0].label);
					variable *var1 = returnVariable(yyvsp[-5].label);
					variable *var2 = returnVariable(yyvsp[0].label);
					//cout
					//------------------------------------------------ Atribuições sem valores iniciais ------------------------------------------------//
					if(encontrei == true && found == true && var1->tipo == "" && var2->tipo == "int" && yyvsp[0].tmp == ""){//Se o $3.tmp for igual a vazio a atribuição é somente de variável
						float aux = std::stof(var2->valor);
						var1->valor = std::to_string(aux);//e não da soma de duas coisas, pois se fosse da soma de duas coisas
						var1->tipo = "float";//o $3.tmp iria ter valor			
						yyval.traducao_dec ="\t" + var1->tipo + " " + var1->tmp + ";\n";
						yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = (float)" + var2->tmp + ";\n";
						cout<<"Tst1"<<endl;
					}
					else if(encontrei == true && var1->tipo == "" && yyvsp[0].tipo == "int"){
						float aux = std::stof(yyvsp[0].label);
						var1->valor = std::to_string(aux);
						var1->tipo = "float";
						yyval.traducao_dec = "\t" + var1->tipo + " " + var1->tmp + ";\n" + yyvsp[0].traducao_dec;
						yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = (float)" + yyvsp[0].tmp +  ";\n";
						cout<<"Tst2"<<endl;
					}
					//------------------------------------------------ Atribuições com valores iniciais ------------------------------------------------//
					else if(encontrei == true && found == true && var1->tipo == "float" && var2->tipo == "int" ){//If que verifica se a variavel que está recebendo
						float aux = std::stof(var2->valor);
						var1->valor = std::to_string(aux);//a atribuição é do tipo float, permitindo ser adicionado uma variável do tipo int ou float
						var1->tipo = "float";//Não preciso do traducao_dec pois a variavel que está recebendo a atribuição e a variável que está sendo atribuida, já foram inicializadas
						yyval.traducao_dec = yyvsp[0].traducao_dec;
						yyval.traducao = "\t" + var1->tmp + " = (float)" + var2->tmp + ";\n";//Não preciso propagar o $3.traducao pois eles ja foram feitos antes
						cout<<"Tst3"<<endl;
					}
					else if(encontrei == true && var1->tipo == "float" && yyvsp[0].tipo == "int"){//Verifica se a variável que está recebendo a atribuição é do tipo
						float aux = std::stof(yyvsp[0].label);
						var1->valor = std::to_string(aux);//float e se o valor qualquer adicionado é do tipo int ou float para fazer a atribuição
					 	var1->tipo = "float";
						yyval.traducao_dec = yyvsp[0].traducao_dec;
						yyval.traducao = yyvsp[0].traducao + "\t" + var1->tmp + " = (float)" + yyvsp[0].tmp + ";\n" ;
						cout<<"Tst4"<<endl;
					}
					else if(found == true && var2->valor == ""){
						yyerror("Você não inicializou a variável " + yyvsp[0].label + ".\n");
					}
					else{
						yyerror("Atribuição não permitida, tipo da variável a ser atribuida é diferente do tipo de atribuição.\n");
					}
					
				}
#line 3579 "y.tab.c"
    break;

  case 102:
#line 1753 "sintatico.y"
                                {
					if(entryFunc == 1){
						bool encontrei = false;
						encontrei = verifyVariableLocal(yyvsp[0].label);
						variable *var1;
						var1 = returnVariable(yyvsp[0].label);
						cout<<"TIPO DA VARIAVELLLLLLLLLLLLLL "<<yyvsp[0].tipo<<endl;
						if(encontrei){
							yyval.traducao = "\treturn " + var1->tmp + ";\n";
							tipoRetorno = var1->tipo;
						}
						else{
							yyval.traducao_dec = yyvsp[0].traducao_dec;
							yyval.traducao = yyvsp[0].traducao + "\treturn " + yyvsp[0].tmp + ";\n";
							tipoRetorno = yyvsp[0].tipo;
						}
					}
					else{
						yyerror("Retorno fora de função.");
					}
				}
#line 3605 "y.tab.c"
    break;

  case 103:
#line 1775 "sintatico.y"
                                {
					yyval = yyvsp[0];
				}
#line 3613 "y.tab.c"
    break;

  case 104:
#line 1782 "sintatico.y"
                                {
					cout<<"tk_num"<<endl;
					yyval.tipo = "int";
					yyval.tmp = genLabel();
					yyval.traducao_dec = "\t" + yyval.tipo + " " + yyval.tmp + ";\n";
					yyval.traducao = "\t" + yyval.tmp + " = " + yyval.label + ";\n";
				}
#line 3625 "y.tab.c"
    break;

  case 105:
#line 1790 "sintatico.y"
                                {
					cout<<"tk_float"<<endl;
					yyval.tipo = "float";
					yyval.tmp = genLabel();
					yyval.traducao_dec = "\t" + yyval.tipo + " " + yyval.tmp + ";\n";
					yyval.traducao = "\t" + yyval.tmp + " = " + yyval.label + ";\n";
				}
#line 3637 "y.tab.c"
    break;

  case 106:
#line 1798 "sintatico.y"
                                {
					cout<<"tk_char"<<endl;
					yyval.tipo = "char";
					yyval.tmp = genLabel();
					yyval.traducao_dec = "\t" + yyval.tipo + " " + yyval.tmp + ";\n";
					yyval.traducao = "\t" + yyval.tmp + " = " + yyval.label + ";\n";
				}
#line 3649 "y.tab.c"
    break;

  case 107:
#line 1806 "sintatico.y"
                                {
					cout<<"tk_string"<<endl;
					yyval.tipo = "char *";
					yyval.tmp = genLabel();
					
					yyval.traducao_dec = "\t" + yyval.tipo + " " + yyval.tmp + ";\n";
					yyval.traducao = "\t" + yyval.tmp + " =  (char*) malloc(" + to_string(yyval.label.size()-2)  + "* sizeof(char));\n" + "\tstrcpy( " + yyval.tmp + "," +
					yyval.label + " );\n";
				}
#line 3663 "y.tab.c"
    break;

  case 108:
#line 1816 "sintatico.y"
                                {
					cout<<"tk_bool"<<endl;
					yyval.tipo = "bool";
					yyval.tmp = genLabel();
					yyval.traducao_dec = "\tint " + yyval.tmp + ";\n";
					yyval.traducao = "\t" + yyval.tmp + " = " + yyval.label + ";\n";
				}
#line 3675 "y.tab.c"
    break;

  case 109:
#line 1824 "sintatico.y"
                                {	
					cout<<"tk_id"<<endl;
					bool encontrei = false;
					encontrei = verifyVariableGlobal(yyvsp[0].label);
					variable *var1;
					
					if(encontrei == true){
						var1 = returnVariable(yyvsp[0].label);
						yyval.tipo = var1->tipo;
					}

					if(!encontrei){
						yyerror("Você não declarou a variável " + yyvsp[0].label + "\n");	
					}
				}
#line 3695 "y.tab.c"
    break;


#line 3699 "y.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
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
#line 1842 "sintatico.y"


#include "lex.yy.c"
#include <stdlib.h>

int yyparse();

int main(int argc, char* argv[]){
		
	yyparse();

	return 0;
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}	

string genLabel(){
	return "temp" + to_string(valorVar++);
}

Execucao criaBloco(string inicio, string fim){
	Execucao nova;
	nova.Inicio = inicio;
	nova.Fim = fim;
	return nova;
}

Execucao genBlock(string tipo){
	Execucao nova;
	string numero = to_string(valorBlock++);
	nova.Inicio = "INICIO_"+ tipo +"_"+ numero;
	nova.Fim = "FIM_"+ tipo +"_"+ numero;
	return nova;
}

bool verifyFunction(string nome){
	
	for(int i = 0; i < funcoes.size(); i++){
		if(funcoes[i].nome == nome){
			return true;
		}
	}
	return false;
}

bool verifyVariableGlobal(string nome){
	
	for(int i = globalTabSym.size(); i > 0; i--){
			for(int y = 0; y < globalTabSym[i-1].size(); y++){
				if(globalTabSym[i-1][y].nome == nome){
					return true;
				}
			}
	}
	return false;
}

bool verifyVariableLocal(string nome){
	
	if(globalTabSym.empty() == 0 && globalTabSym.size() > mapAtual){
		for(int i = 0; i < globalTabSym[mapAtual].size(); i++){
			if(globalTabSym[mapAtual][i].nome == nome){
					return true;
			}
		}
	}
	return false;
}

Function *returnFunction(string nome){

	funcaoAux.argumentos = "";
	funcaoAux.nome = "";
	funcaoAux.retorno = "";

	for(int i = 0; i < funcoes.size(); i++){
		if(funcoes[i].nome == nome){
			return &funcoes[i];
		}
	}
	return &funcaoAux;
}

variable *returnVariable(string nome){

	auxiliar.tipo = "";
	auxiliar.nome = "";
	auxiliar.valor = "";
	auxiliar.tmp = "";

	for(int i = globalTabSym.size(); i > 0; i--){
		for(int y = 0; y < globalTabSym[i-1].size(); y++){
			if(globalTabSym[i-1][y].nome == nome){
				return &globalTabSym[i-1][y];
			}
		}
	}
	return &auxiliar;
}

/*
void apagaMap(){
	globalTabSym[mapAtual].clear();
}

void imprimeMap(){
	for(int i = 0; i < globalTabSym.size(); i++){
		for(int y = 0; y < globalTabSym[i].size();y++){
			cout<<globalTabSym[i][y].nome<<endl;
		}
	}
}*/

void criaOperacao(atributos *dolardolar, atributos dolar1, atributos dolar3, string operacao){//variable v1, variable v2,
	
	variable *v1 = returnVariable(dolar1.label);
	variable *v2 = returnVariable(dolar3.label);

	if(operacao == "soma"){
	//-------------------------------------------------------- Soma de inteiro --------------------------------------------------------//
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//int var + int var
			int aux = std::stoi(v1->valor) + std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " + " + v2->tmp;
			//dolardolar->operacao = "soma";
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//int var + int num
			int aux = std::stoi(v1->valor) + std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " + " + dolar3.tmp;
			//dolardolar->operacao = "soma";
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num + int var
			int aux = std::stoi(dolar1.label) + std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " + " + v2->tmp;
			//dolardolar->operacao = "soma";
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num + int num
			int aux = std::stoi(dolar1.label) + std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " + " + dolar3.tmp;
			//dolardolar->operacao = "soma";
		}
	//--------------------------------------------------------- Soma de float ---------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var + float var
			float aux1 = std::stof(v1->valor) + std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " + " + v2->tmp;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var + int var
			float aux1 = std::stof(v1->valor) + std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v2->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " + " + aux;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var + float var
			float aux1 = std::stof(v1->valor) + std::stof(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " + " + v2->tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var + float num
			float aux1 = std::stof(v1->valor) + std::stof(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " + " + dolar3.tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var + int num
			float aux1 = std::stof(v1->valor) + std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " + " + aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var + float num
			float aux1 = std::stof(v1->valor) + std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao ="\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " + " + dolar3.tmp;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "float"){//float num + int var
			float aux1 = std::stof(v2->valor) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" + aux + " = (float)" + v2->tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " + " + aux;
		}	
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "float"){//float num + float var
			float aux1 = std::stof(v2->valor) + std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " + " + v2->tmp;
		}
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "int"){//int num + float var
			float aux1 = std::stof(v2->valor) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao =dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " + " + v2->tmp;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num + float num
			float aux1 = std::stof(dolar3.label) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " + " + dolar3.tmp;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num + int num
			float aux1 = std::stof(dolar3.label) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " + " + aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num + float num
			float aux1 = std::stof(dolar3.label) + std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " + " + dolar3.tmp;
		}
		else{
			yyerror("Soma não permitida\n");
		}
		//-------------------------------------------------------- Fim Soma --------------------------------------------------------//
	}
	else if(operacao == "subtracao"){
	//-------------------------------------------------------- Subtração de inteiro --------------------------------------------------------//
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//var int - var int
			int aux = std::stoi(v1->valor) - std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " - " + v2->tmp;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//var int - int num
			int aux = std::stoi(v1->valor) - std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " - " + dolar3.tmp;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num - var int
			int aux = std::stoi(dolar1.label) - std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " - " + v2->tmp;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num - int num
			int aux = std::stoi(dolar1.label) - std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " - " + dolar3.tmp;
		}
	//--------------------------------------------------------- Subtracão de float ---------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var - float var
			float aux1 = std::stof(v1->valor) - std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " - " + v2->tmp;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var - int var
			float aux1 = std::stof(v1->valor) - std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v2->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " - " + aux;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var - float var
			float aux1 = std::stof(v1->valor) - std::stof(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " - " + v2->tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var - float num
			float aux1 = std::stof(v1->valor) - std::stof(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " - " + dolar3.tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var - int num
			float aux1 = std::stof(v1->valor) - std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " - " + aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var - float num
			float aux1 = std::stof(v1->valor) - std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao ="\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " - " + dolar3.tmp;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "float"){//float num - int var
			float aux1 = std::stof(v2->valor) - std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" + aux + " = (float)" + v2->tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " - " + aux;
		}	
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "float"){//float num - float var
			float aux1 = std::stof(v2->valor) - std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " - " + v2->tmp;
		}
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "int"){//int num - float var
			float aux1 = std::stof(v2->valor) - std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao =dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " - " + v2->tmp;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num - float num
			float aux1 = std::stof(dolar3.label) - std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " - " + dolar3.tmp;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num - int num
			float aux1 = std::stof(dolar3.label) - std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " - " + aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num - float num
			float aux1 = std::stof(dolar3.label) - std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " - " + dolar3.tmp;
		}
		else{
			yyerror("Subtração não permitida\n");
		}
		//-------------------------------------------------------- Fim Subtracao --------------------------------------------------------//
	}
	else if(operacao == "multiplicacao"){
	//-------------------------------------------------------- Multiplicação de inteiro --------------------------------------------------------//
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//var int * var int
			int aux = std::stoi(v1->valor) * std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " * " + v2->tmp;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//var int * int num
			int aux = std::stoi(v1->valor) * std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " * " + dolar3.tmp;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num * var int
			int aux = std::stoi(dolar1.label) * std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " * " + v2->tmp;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num * int num
			int aux = std::stoi(dolar1.label) * std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " * " + dolar3.tmp;
		}
	//--------------------------------------------------------- Multiplicação de float ---------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var * float var
			float aux1 = std::stof(v1->valor) * std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " * " + v2->tmp;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var * int var
			float aux1 = std::stof(v1->valor) * std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v2->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " * " + aux;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var * float var
			float aux1 = std::stof(v1->valor) * std::stof(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " * " + v2->tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var * float num
			float aux1 = std::stof(v1->valor) * std::stof(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " * " + dolar3.tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var * int num
			float aux1 = std::stof(v1->valor) * std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " * " + aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var * float num
			float aux1 = std::stof(v1->valor) * std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao ="\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " * " + dolar3.tmp;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "float"){//float num * int var
			float aux1 = std::stof(v2->valor) * std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" + aux + " = (float)" + v2->tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " * " + aux;
		}	
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "float"){//float num * float var
			float aux1 = std::stof(v2->valor) * std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " * " + v2->tmp;
		}
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "int"){//int num * float var
			float aux1 = std::stof(v2->valor) * std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao =dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " * " + v2->tmp;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num * float num
			float aux1 = std::stof(dolar3.label) * std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " * " + dolar3.tmp;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num * int num
			float aux1 = std::stof(dolar3.label) * std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " * " + aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num * float num
			float aux1 = std::stof(dolar3.label) * std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " * " + dolar3.tmp;
		}
		else{
			yyerror("Multiplicação não permitida\n");
		}
		//-------------------------------------------------------- Fim Multiplicação --------------------------------------------------------//
	}
	else if(operacao == "divisao"){
	//-------------------------------------------------------- Divisão de inteiro --------------------------------------------------------//
		if(dolar3.label == "0" || v2->valor == "0"){
			yyerror("Impossível dividir por zero\n");
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//var int / var int
			int aux = std::stoi(v1->valor) / std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " / " + v2->tmp;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//var int / int num
			int aux = std::stoi(v1->valor) / std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = v1->tmp + " / " + dolar3.tmp;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num / var int
			int aux = std::stoi(dolar1.label) / std::stoi(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " / " + v2->tmp;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num / int num
			int aux = std::stoi(dolar1.label) / std::stoi(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "int";
			dolardolar->label = std::to_string(aux);
			dolardolar->tmp = dolar1.tmp + " / " + dolar3.tmp;
		}
	//--------------------------------------------------------- Divisão de float ---------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var / float var
			float aux1 = std::stof(v1->valor) + std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " / " + v2->tmp;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var / int var
			float aux1 = std::stof(v1->valor) + std::stof(v2->valor);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = "\t" +  aux + " = (float)" + v2->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " / " + aux;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var / float var
			float aux1 = std::stof(v1->valor) + std::stof(v2->valor);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " / " + v2->tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var / float num
			float aux1 = std::stof(v1->valor) + std::stof(dolar3.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " / " + dolar3.tmp;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var / int num
			float aux1 = std::stof(v1->valor) + std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = v1->tmp + " / " + aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var / float num
			float aux1 = std::stof(v1->valor) + std::stof(dolar3.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao ="\t" +  aux + " = (float)" + v1->tmp + ";\n" + dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " / " + dolar3.tmp;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "float"){//float num / int var
			float aux1 = std::stof(v2->valor) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" + aux + " = (float)" + v2->tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " / " + aux;
		}	
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "float"){//float num / float var
			float aux1 = std::stof(v2->valor) + std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " / " + v2->tmp;
		}
		else if(v2->valor != "" && v2->tipo == "float" && dolar1.tipo == "int"){//int num / float var
			float aux1 = std::stof(v2->valor) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao =dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " / " + v2->tmp;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num / float num
			float aux1 = std::stof(dolar3.label) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = aux + " / " + dolar3.tmp;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num / int num
			float aux1 = std::stof(dolar3.label) + std::stof(dolar1.label);
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n";
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " / " + aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num / float num
			float aux1 = std::stof(dolar3.label) + std::stof(dolar1.label);
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec;
			dolardolar->traducao = dolar1.traducao + dolar3.traducao;
			dolardolar->tipo = "float";
			dolardolar->label = std::to_string(aux1);
			dolardolar->tmp = dolar1.tmp + " / " + dolar3.tmp;
		}
		else{
			yyerror("Divisão não permitida\n");
		}
		//-------------------------------------------------------- Fim Divisão --------------------------------------------------------//
	}
	else if(operacao == "tk_less"){
	//-------------------------------------------------------- < de inteiro --------------------------------------------------------//	
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//int var < int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " < " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//int var < int num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " < " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num < int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " < " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num < int num
			string aux = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = "+ dolar1.tmp + " < " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
	//-------------------------------------------------------- < de float --------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var < float var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " +  aux + " < " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var < int var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " +  v1->tmp + " < " + aux + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var < float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " +  v1->tmp + " < " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var < float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " < " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var < int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + v1->tmp + " < " + aux + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var < float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " + aux + " < " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "int" ){//float num < int var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " < " + aux + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "float"){//float num < float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " < " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && dolar1.tipo == "int" && v2->tipo == "float" ){//int num < float var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " < " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num < float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " < " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num < int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " < " + aux + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num < float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " < " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux1;
		}
		else{
			yyerror("Comparação não permitida\n");
		}
	}
	else if(operacao == "tk_greater"){
	//-------------------------------------------------------- > de inteiro --------------------------------------------------------//	
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//int var > int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " > " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//int var > int num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " > " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num > int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " > " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num > int num
			string aux = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = "+ dolar1.tmp + " > " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
	//-------------------------------------------------------- > de float --------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var > float var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " +  aux + " > " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var > int var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " +  v1->tmp + " > " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var > float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " +  v1->tmp + " > " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var > float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " > " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var > int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + v1->tmp + " > " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var > float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " + aux + " > " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "int" ){//float num > int var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " > " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "float"){//float num > float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " > " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && dolar1.tipo == "int" && v2->tipo == "float" ){//int num > float var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " > " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num > float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " > " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num > int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " > " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num > float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " > " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else{
			yyerror("Comparação não permitida\n");
		}
	}
	else if(operacao == "tk_le"){
	//-------------------------------------------------------- <= de inteiro --------------------------------------------------------//	
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//int var <= int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " <= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//int var <= int num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " <= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num <= int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " <= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num <= int num
			string aux = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = "+ dolar1.tmp + " <= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
	//-------------------------------------------------------- <= de float --------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var <= float var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " +  aux + " <= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var <= int var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " +  v1->tmp + " <= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var <= float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " +  v1->tmp + " <= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var <= float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " <= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var <= int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + v1->tmp + " <= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var <= float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " + aux + " <= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "int" ){//float num <= int var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " <= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "float"){//float num <= float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " <= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && dolar1.tipo == "int" && v2->tipo == "float" ){//int num <= float var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " <= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num <= float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " <= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num <= int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " <= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num <= float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " <= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else{
			yyerror("Comparação não permitida\n");
		}	
	}
	else if(operacao == "tk_he"){
	//-------------------------------------------------------- >= de inteiro --------------------------------------------------------//	
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//int var >= int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " >= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//int var >= int num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " >= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num >= int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " >= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num >= int num
			string aux = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = "+ dolar1.tmp + " >= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
	//-------------------------------------------------------- >= de float --------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var >= float var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " +  aux + " >= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var >= int var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " +  v1->tmp + " >= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var >= float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " +  v1->tmp + " >= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var >= float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " >= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var >= int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + v1->tmp + " >= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var >= float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " + aux + " >= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "int" ){//float num >= int var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " >= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "float"){//float num >= float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " >= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && dolar1.tipo == "int" && v2->tipo == "float" ){//int num >= float var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " >= " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num >= float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " >= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num >= int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " >= " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num >= float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " >= " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else{
			yyerror("Comparação não permitida\n");
		}	
	}
	else if(operacao == "tk_eq"){
	//-------------------------------------------------------- == de inteiro --------------------------------------------------------//	
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//int var == int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " == " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//int var == int num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " == " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num == int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " == " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num == int num
			string aux = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = "+ dolar1.tmp + " == " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
	//-------------------------------------------------------- == de float --------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var == float var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " +  aux + " == " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var == int var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " +  v1->tmp + " == " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var == float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " +  v1->tmp + " == " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var == float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " == " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var == int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + v1->tmp + " == " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var == float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " + aux + " == " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "int" ){//float num == int var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " == " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "float"){//float num == float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " == " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && dolar1.tipo == "int" && v2->tipo == "float" ){//int num == float var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " == " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num == float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " == " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num == int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " == " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num == float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " == " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->tipo != "" && v2->tipo != "" && v1->tipo == v2->tipo){
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " == " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == dolar3.tipo){
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " == " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else{
			yyerror("Comparação não permitida\n");
		}		
	}
	else if(operacao == "tk_diff"){
	//-------------------------------------------------------- != de inteiro --------------------------------------------------------//	
		if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "int"){//int var != int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " != " + v2->tmp + ";\n";
			dolardolar->tipo = "bool"; 
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "int"){//int var != int num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " != " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && v2->tipo == "int" && dolar1.tipo == "int"){//int num != int var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " != " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "int"){//int num != int num
			string aux = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = "+ dolar1.tmp + " != " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
	//-------------------------------------------------------- != de float --------------------------------------------------------//
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "int" && v2->tipo == "float"){//int var != float var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " +  aux + " != " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "int"){//float var != int var
			string aux = genLabel();
			string aux1 = genLabel();	
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " +  v1->tmp + " != " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v2->valor != "" && v1->tipo == "float" && v2->tipo == "float"){//float var != float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " +  v1->tmp + " != " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "float"){//float var != float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " != " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v1->valor != "" && v1->tipo == "float" && dolar3.tipo == "int"){//float var != int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + v1->tmp + " != " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->valor != "" && v1->tipo == "int" && dolar3.tipo == "float"){//int var != float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v1->tmp + ";\n" + "\t" +  aux1 + " = " + aux + " != " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "int" ){//float num != int var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + v2->tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " != " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v2->valor != "" && dolar1.tipo == "float" && v2->tipo == "float"){//float num != float var
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " != " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(v2->valor != "" && dolar1.tipo == "int" && v2->tipo == "float" ){//int num != float var
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " != " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "float"){//float num != float num
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " != " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == "float" && dolar3.tipo == "int"){//float num != int num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar3.tmp + ";\n" + "\t" +  aux1 + " = " + dolar1.tmp + " != " + aux + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(dolar1.tipo == "int" && dolar3.tipo == "float"){//int num != float num
			string aux = genLabel();
			string aux1 = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tfloat " + aux + ";\n" + "\tint " + aux1 + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = (float)" + dolar1.tmp + ";\n" + "\t" +  aux1 + " = " + aux + " != " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux1;
		}
		else if(v1->tipo != "" && v2->tipo != "" && v1->tipo == v2->tipo){
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + v1->tmp + " != " + v2->tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else if(dolar1.tipo == dolar3.tipo){
			string aux = genLabel();
			dolardolar->traducao_dec = dolar1.traducao_dec + dolar3.traducao_dec + "\tint " + aux + ";\n";
			dolardolar->traducao = dolar1.traducao + dolar3.traducao + "\t" +  aux + " = " + dolar1.tmp + " != " + dolar3.tmp + ";\n";
			dolardolar->tipo = "bool";
			dolardolar->tmp = aux;
		}
		else{
			yyerror("Comparação não permitida\n");
		}		
	}	
	else{
	}
}
