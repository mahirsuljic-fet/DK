%option noyywrap

%{
extern int brojRijeci;
extern int brojKaraktera;
extern int brojLinija;
%}

%%

[\n]          { brojLinija++; brojKaraktera++; }
[^ \t\n\r]+   { brojRijeci++; brojKaraktera += yyleng; }
[ \t\r]+      { brojKaraktera += yyleng; }

%%

int brojRijeci = 0;
int brojKaraktera = 0;
int brojLinija = 0;

int main() {
  yylex();
  printf("Broj linija:    %d\nBroj rijeci:    %d\nBroj karaktera: %d\n", brojLinija, brojRijeci, brojKaraktera);
}
