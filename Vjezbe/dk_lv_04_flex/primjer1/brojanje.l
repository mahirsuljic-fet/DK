%option noyywrap

%%

[ \t\n\r]
"exit"                  { return 0; }
[0-9]+                  { printf("Number"); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("ID duzine %d <%s>\n"), yyleng, yytext; } // ???
.                       { printf("error: \n"); }

%%

int main() {
  yylex();
}
