%option noyywrap

%{

#include <vector>
#include "token.hpp"

%}

ws       [ \t\r\n]
digit    [0-9]
number   {digit}+

%%

{ws}                        { }
"("                         { return LEFT_PAREN;    }
")"                         { return RIGHT_PAREN;   }
"{"                         { return LEFT_BRACE;    }
"}"                         { return RIGHT_BRACE;   }
","                         { return COMMA;         }
"."                         { return DOT;           }
"-"                         { return MINUS;         }
"+"                         { return PLUS;          }
";"                         { return SEMICOLON;     }
"*"                         { return STAR;          }
"/"                         { return SLASH;         }
"!="                        { return BANG_EQUAL;    }
"=="                        { return EQUAL_EQUAL;   }
"<="                        { return LESS_EQUAL;    }
">="                        { return GREATER_EQUAL; }
"<"                         { return LESS;          }
">"                         { return GREATER;       }
"!"                         { return BANG;          }
"="                         { return EQUAL;         }
\".*\"                      { return STRING;        }
{digit}+(\.{digit}+)?       { return NUMBER;        }
"and"                       { return AND;           }
"class"                     { return CLASS;         }
"else"                      { return ELSE;          }
"false"                     { return FALSE;         }
"for"                       { return FOR;           }
"fun"                       { return FUN;           }
"if"                        { return IF;            }
"nil"                       { return NIL;           }
"or"                        { return OR;            }
"print"                     { return PRINT;         }
"return"                    { return RETURN;        }
"super"                     { return SUPER;         }
"this"                      { return THIS;          }
"true"                      { return TRUE;          }
"var"                       { return VAR;           }
"while"                     { return WHILE;         }
[a-zA-Z_]([0-9a-zA-Z_]+)?   { return IDENTIFIER;    }
.                           { printerr(yytext[0]);  }

%%
