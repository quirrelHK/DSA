%{
    #include<stdio.h>
    #include<string.h>
    int i=0;
%}

%%

([0-9a-zA-Z]) {i++;}

"\n" {printf("%d\n",i); i=0;}

%%

int yywrap(void) {}

int main(){
    yylex();
    return 0;
}