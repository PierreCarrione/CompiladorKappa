/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
