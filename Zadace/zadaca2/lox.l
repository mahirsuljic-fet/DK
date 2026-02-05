%option noyywrap

%{

#include <vector>
#include "token.hpp"

extern unsigned short int row;
extern unsigned short int column;

%}

ws       [ \t\r]
digit    [0-9]
number   {digit}+

%%

\n                          { row++; column = 1;                      }
{ws}                        { column += yyleng;                       }
"("                         { column += yyleng; return LEFT_PAREN;    }
")"                         { column += yyleng; return RIGHT_PAREN;   }
"{"                         { column += yyleng; return LEFT_BRACE;    }
"}"                         { column += yyleng; return RIGHT_BRACE;   }
","                         { column += yyleng; return COMMA;         }
"."                         { column += yyleng; return DOT;           }
"-"                         { column += yyleng; return MINUS;         }
"+"                         { column += yyleng; return PLUS;          }
";"                         { column += yyleng; return SEMICOLON;     }
"*"                         { column += yyleng; return STAR;          }
"/"                         { column += yyleng; return SLASH;         }
"!="                        { column += yyleng; return BANG_EQUAL;    }
"=="                        { column += yyleng; return EQUAL_EQUAL;   }
"<="                        { column += yyleng; return LESS_EQUAL;    }
">="                        { column += yyleng; return GREATER_EQUAL; }
"<"                         { column += yyleng; return LESS;          }
">"                         { column += yyleng; return GREATER;       }
"!"                         { column += yyleng; return BANG;          }
"="                         { column += yyleng; return EQUAL;         }
\".*\"                      { column += yyleng; return STRING;        }
{digit}+(\.{digit}+)?       { column += yyleng; return NUMBER;        }
"and"                       { column += yyleng; return AND;           }
"class"                     { column += yyleng; return CLASS;         }
"else"                      { column += yyleng; return ELSE;          }
"false"                     { column += yyleng; return FALSE;         }
"for"                       { column += yyleng; return FOR;           }
"fun"                       { column += yyleng; return FUN;           }
"if"                        { column += yyleng; return IF;            }
"nil"                       { column += yyleng; return NIL;           }
"or"                        { column += yyleng; return OR;            }
"print"                     { column += yyleng; return PRINT;         }
"return"                    { column += yyleng; return RETURN;        }
"super"                     { column += yyleng; return SUPER;         }
"this"                      { column += yyleng; return THIS;          }
"true"                      { column += yyleng; return TRUE;          }
"var"                       { column += yyleng; return VAR;           }
"while"                     { column += yyleng; return WHILE;         }
[a-zA-Z_]([0-9a-zA-Z_]+)?   { column += yyleng; return IDENTIFIER;    }
.                           { column += yyleng; printerr(yytext[0]);  }

%%

unsigned short int row = 1;
unsigned short int column = 1;

int main() {
    int t;
    std::vector<Token> tokeni;
    while ((t = yylex())) {
        Token newToken = { t, yytext, row, static_cast<unsigned short>(column - yyleng) };
        tokeni.push_back(newToken);
        std::cout << tokeni.back() << std::endl;
    }
}
