
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END_OF_FILE = 258,
     C_AUTO = 259,
     C_BREAK = 260,
     C_CASE = 261,
     C_CHAR = 262,
     C_VARCHAR = 263,
     C_CONST = 264,
     C_CONTINUE = 265,
     C_DEFAULT = 266,
     C_DO = 267,
     C_DOUBLE = 268,
     C_ENUM = 269,
     C_EXTERN = 270,
     C_FLOAT = 271,
     C_FOR = 272,
     C_GOTO = 273,
     C_INT = 274,
     C_LONG = 275,
     C_REGISTER = 276,
     C_RETURN = 277,
     C_SHORT = 278,
     C_SIGNED = 279,
     C_SIZEOF = 280,
     C_STATIC = 281,
     C_STRUCT = 282,
     C_SWITCH = 283,
     C_TYPEDEF = 284,
     C_UNION = 285,
     C_UNSIGNED = 286,
     C_VOID = 287,
     C_VOLATILE = 288,
     C_WHILE = 289,
     C_ELIPSIS = 290,
     C_ELSE = 291,
     C_IF = 292,
     C_CONSTANT = 293,
     C_IDENTIFIER = 294,
     C_TYPE_NAME = 295,
     C_STRING_LITERAL = 296,
     C_RIGHT_ASSIGN = 297,
     C_LEFT_ASSIGN = 298,
     C_ADD_ASSIGN = 299,
     C_SUB_ASSIGN = 300,
     C_MUL_ASSIGN = 301,
     C_DIV_ASSIGN = 302,
     C_MOD_ASSIGN = 303,
     C_AND_ASSIGN = 304,
     C_XOR_ASSIGN = 305,
     C_OR_ASSIGN = 306,
     C_INC_OP = 307,
     C_DEC_OP = 308,
     C_PTR_OP = 309,
     C_AND_OP = 310,
     C_EQ_OP = 311,
     C_NE_OP = 312,
     C_RIGHT_OP = 313,
     C_LEFT_OP = 314,
     C_OR_OP = 315,
     C_LE_OP = 316,
     C_GE_OP = 317,
     C_APRE_BINARY = 318,
     C_APRE_BIT = 319,
     C_APRE_BYTES = 320,
     C_APRE_VARBYTES = 321,
     C_APRE_NIBBLE = 322,
     C_APRE_INTEGER = 323,
     C_APRE_NUMERIC = 324,
     C_APRE_BLOB_LOCATOR = 325,
     C_APRE_CLOB_LOCATOR = 326,
     C_APRE_BLOB = 327,
     C_APRE_CLOB = 328,
     C_SQLLEN = 329,
     C_SQL_TIMESTAMP_STRUCT = 330,
     C_SQL_TIME_STRUCT = 331,
     C_SQL_DATE_STRUCT = 332,
     C_SQL_DA_STRUCT = 333,
     C_FAILOVERCB = 334,
     C_NCHAR_CS = 335,
     C_ATTRIBUTE = 336,
     M_INCLUDE = 337,
     M_DEFINE = 338,
     M_UNDEF = 339,
     M_FUNCTION = 340,
     M_LBRAC = 341,
     M_RBRAC = 342,
     M_DQUOTE = 343,
     M_FILENAME = 344,
     M_IF = 345,
     M_ELIF = 346,
     M_ELSE = 347,
     M_ENDIF = 348,
     M_IFDEF = 349,
     M_IFNDEF = 350,
     M_CONSTANT = 351,
     M_IDENTIFIER = 352,
     EM_SQLSTART = 353,
     EM_ERROR = 354,
     TR_ADD = 355,
     TR_AFTER = 356,
     TR_AGER = 357,
     TR_ALL = 358,
     TR_ALTER = 359,
     TR_AND = 360,
     TR_ANY = 361,
     TR_ARCHIVE = 362,
     TR_ARCHIVELOG = 363,
     TR_AS = 364,
     TR_ASC = 365,
     TR_AT = 366,
     TR_BACKUP = 367,
     TR_BEFORE = 368,
     TR_BEGIN = 369,
     TR_BY = 370,
     TR_BIND = 371,
     TR_CASCADE = 372,
     TR_CASE = 373,
     TR_CAST = 374,
     TR_CHECK_OPENING_PARENTHESIS = 375,
     TR_CLOSE = 376,
     TR_COALESCE = 377,
     TR_COLUMN = 378,
     TR_COMMENT = 379,
     TR_COMMIT = 380,
     TR_COMPILE = 381,
     TR_CONNECT = 382,
     TR_CONSTRAINT = 383,
     TR_CONSTRAINTS = 384,
     TR_CONTINUE = 385,
     TR_CREATE = 386,
     TR_VOLATILE = 387,
     TR_CURSOR = 388,
     TR_CYCLE = 389,
     TR_DATABASE = 390,
     TR_DECLARE = 391,
     TR_DEFAULT = 392,
     TR_DELETE = 393,
     TR_DEQUEUE = 394,
     TR_DESC = 395,
     TR_DIRECTORY = 396,
     TR_DISABLE = 397,
     TR_DISCONNECT = 398,
     TR_DISTINCT = 399,
     TR_DROP = 400,
     TR_DESCRIBE = 401,
     TR_DESCRIPTOR = 402,
     TR_EACH = 403,
     TR_ELSE = 404,
     TR_ELSEIF = 405,
     TR_ENABLE = 406,
     TR_END = 407,
     TR_ENQUEUE = 408,
     TR_ESCAPE = 409,
     TR_EXCEPTION = 410,
     TR_EXEC = 411,
     TR_EXECUTE = 412,
     TR_EXIT = 413,
     TR_FAILOVERCB = 414,
     TR_FALSE = 415,
     TR_FETCH = 416,
     TR_FIFO = 417,
     TR_FLUSH = 418,
     TR_FOR = 419,
     TR_FOREIGN = 420,
     TR_FROM = 421,
     TR_FULL = 422,
     TR_FUNCTION = 423,
     TR_GOTO = 424,
     TR_GRANT = 425,
     TR_GROUP = 426,
     TR_HAVING = 427,
     TR_IF = 428,
     TR_IN = 429,
     TR_IN_BF_LPAREN = 430,
     TR_INNER = 431,
     TR_INSERT = 432,
     TR_INTERSECT = 433,
     TR_INTO = 434,
     TR_IS = 435,
     TR_ISOLATION = 436,
     TR_JOIN = 437,
     TR_KEY = 438,
     TR_LEFT = 439,
     TR_LESS = 440,
     TR_LEVEL = 441,
     TR_LIFO = 442,
     TR_LIKE = 443,
     TR_LIMIT = 444,
     TR_LOCAL = 445,
     TR_LOGANCHOR = 446,
     TR_LOOP = 447,
     TR_MERGE = 448,
     TR_MOVE = 449,
     TR_MOVEMENT = 450,
     TR_NEW = 451,
     TR_NOARCHIVELOG = 452,
     TR_NOCYCLE = 453,
     TR_NOT = 454,
     TR_NULL = 455,
     TR_OF = 456,
     TR_OFF = 457,
     TR_OLD = 458,
     TR_ON = 459,
     TR_OPEN = 460,
     TR_OR = 461,
     TR_ORDER = 462,
     TR_OUT = 463,
     TR_OUTER = 464,
     TR_OVER = 465,
     TR_PARTITION = 466,
     TR_PARTITIONS = 467,
     TR_POINTER = 468,
     TR_PRIMARY = 469,
     TR_PRIOR = 470,
     TR_PRIVILEGES = 471,
     TR_PROCEDURE = 472,
     TR_PUBLIC = 473,
     TR_QUEUE = 474,
     TR_READ = 475,
     TR_REBUILD = 476,
     TR_RECOVER = 477,
     TR_REFERENCES = 478,
     TR_REFERENCING = 479,
     TR_REGISTER = 480,
     TR_RESTRICT = 481,
     TR_RETURN = 482,
     TR_REVOKE = 483,
     TR_RIGHT = 484,
     TR_ROLLBACK = 485,
     TR_ROW = 486,
     TR_SAVEPOINT = 487,
     TR_SELECT = 488,
     TR_SEQUENCE = 489,
     TR_SESSION = 490,
     TR_SET = 491,
     TR_SOME = 492,
     TR_SPLIT = 493,
     TR_START = 494,
     TR_STATEMENT = 495,
     TR_SYNONYM = 496,
     TR_TABLE = 497,
     TR_TEMPORARY = 498,
     TR_THAN = 499,
     TR_THEN = 500,
     TR_TO = 501,
     TR_TRIGGER = 502,
     TR_TRUE = 503,
     TR_TYPE = 504,
     TR_TYPESET = 505,
     TR_UNION = 506,
     TR_UNIQUE = 507,
     TR_UNREGISTER = 508,
     TR_UNTIL = 509,
     TR_UPDATE = 510,
     TR_USER = 511,
     TR_USING = 512,
     TR_VALUES = 513,
     TR_VARIABLE = 514,
     TR_VARIABLES = 515,
     TR_VIEW = 516,
     TR_WHEN = 517,
     TR_WHERE = 518,
     TR_WHILE = 519,
     TR_WITH = 520,
     TR_WORK = 521,
     TR_WRITE = 522,
     TR_PARALLEL = 523,
     TR_NOPARALLEL = 524,
     TR_LOB = 525,
     TR_STORE = 526,
     TR_ENDEXEC = 527,
     TR_PRECEDING = 528,
     TR_FOLLOWING = 529,
     TR_CURRENT_ROW = 530,
     TR_LINK = 531,
     TR_ROLE = 532,
     TR_WITHIN = 533,
     TK_BETWEEN = 534,
     TK_EXISTS = 535,
     TO_ACCESS = 536,
     TO_CONSTANT = 537,
     TO_IDENTIFIED = 538,
     TO_INDEX = 539,
     TO_MINUS = 540,
     TO_MODE = 541,
     TO_OTHERS = 542,
     TO_RAISE = 543,
     TO_RENAME = 544,
     TO_REPLACE = 545,
     TO_ROWTYPE = 546,
     TO_SEGMENT = 547,
     TO_WAIT = 548,
     TO_PIVOT = 549,
     TO_UNPIVOT = 550,
     TO_MATERIALIZED = 551,
     TO_CONNECT_BY_NOCYCLE = 552,
     TO_CONNECT_BY_ROOT = 553,
     TO_NULLS = 554,
     TO_PURGE = 555,
     TO_FLASHBACK = 556,
     TO_VC2COLL = 557,
     TO_KEEP = 558,
     TA_ELSIF = 559,
     TA_EXTENTSIZE = 560,
     TA_FIXED = 561,
     TA_LOCK = 562,
     TA_MAXROWS = 563,
     TA_ONLINE = 564,
     TA_OFFLINE = 565,
     TA_REPLICATION = 566,
     TA_REVERSE = 567,
     TA_ROWCOUNT = 568,
     TA_STEP = 569,
     TA_TABLESPACE = 570,
     TA_TRUNCATE = 571,
     TA_SQLCODE = 572,
     TA_SQLERRM = 573,
     TA_LINKER = 574,
     TA_REMOTE_TABLE = 575,
     TA_SHARD = 576,
     TA_DISJOIN = 577,
     TA_CONJOIN = 578,
     TA_SEC = 579,
     TA_MSEC = 580,
     TA_USEC = 581,
     TA_SECOND = 582,
     TA_MILLISECOND = 583,
     TA_MICROSECOND = 584,
     TI_NONQUOTED_IDENTIFIER = 585,
     TI_QUOTED_IDENTIFIER = 586,
     TI_HOSTVARIABLE = 587,
     TL_TYPED_LITERAL = 588,
     TL_LITERAL = 589,
     TL_NCHAR_LITERAL = 590,
     TL_UNICODE_LITERAL = 591,
     TL_INTEGER = 592,
     TL_NUMERIC = 593,
     TS_AT_SIGN = 594,
     TS_CONCATENATION_SIGN = 595,
     TS_DOUBLE_PERIOD = 596,
     TS_EXCLAMATION_POINT = 597,
     TS_PERCENT_SIGN = 598,
     TS_OPENING_PARENTHESIS = 599,
     TS_CLOSING_PARENTHESIS = 600,
     TS_OPENING_BRACKET = 601,
     TS_CLOSING_BRACKET = 602,
     TS_ASTERISK = 603,
     TS_PLUS_SIGN = 604,
     TS_COMMA = 605,
     TS_MINUS_SIGN = 606,
     TS_PERIOD = 607,
     TS_SLASH = 608,
     TS_COLON = 609,
     TS_SEMICOLON = 610,
     TS_LESS_THAN_SIGN = 611,
     TS_EQUAL_SIGN = 612,
     TS_GREATER_THAN_SIGN = 613,
     TS_QUESTION_MARK = 614,
     TS_OUTER_JOIN_OPERATOR = 615,
     TX_HINTS = 616,
     SES_V_NUMERIC = 617,
     SES_V_INTEGER = 618,
     SES_V_HOSTVARIABLE = 619,
     SES_V_LITERAL = 620,
     SES_V_TYPED_LITERAL = 621,
     SES_V_DQUOTE_LITERAL = 622,
     SES_V_IDENTIFIER = 623,
     SES_V_ABSOLUTE = 624,
     SES_V_ALLOCATE = 625,
     SES_V_ASENSITIVE = 626,
     SES_V_AUTOCOMMIT = 627,
     SES_V_BATCH = 628,
     SES_V_BLOB_FILE = 629,
     SES_V_BREAK = 630,
     SES_V_CLOB_FILE = 631,
     SES_V_CUBE = 632,
     SES_V_DEALLOCATE = 633,
     SES_V_DESCRIPTOR = 634,
     SES_V_DO = 635,
     SES_V_FIRST = 636,
     SES_V_FOUND = 637,
     SES_V_FREE = 638,
     SES_V_HOLD = 639,
     SES_V_IMMEDIATE = 640,
     SES_V_INDICATOR = 641,
     SES_V_INSENSITIVE = 642,
     SES_V_LAST = 643,
     SES_V_NEXT = 644,
     SES_V_ONERR = 645,
     SES_V_ONLY = 646,
     APRE_V_OPTION = 647,
     SES_V_PREPARE = 648,
     SES_V_RELATIVE = 649,
     SES_V_RELEASE = 650,
     SES_V_ROLLUP = 651,
     SES_V_SCROLL = 652,
     SES_V_SENSITIVE = 653,
     SES_V_SQLERROR = 654,
     SES_V_THREADS = 655,
     SES_V_WHENEVER = 656,
     SES_V_CURRENT = 657,
     SES_V_GROUPING_SETS = 658
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 24 "ulpCompy.y"

    char *strval;



/* Line 1676 of yacc.c  */
#line 461 "ulpCompy.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




