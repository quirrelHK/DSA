#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> symbolTable;
bool isOperator(char ch){
    string op = "+-/*%^";
    return op.find(ch) != string::npos;
}

void addSymbol(string token){
    if(symbolTable.find(token) == symbolTable.end()){
        symbolTable[token]="T"+ to_string(symbolTable.size()+1);
    }
}

void printSymbol(string token,string tokenType){
    cout << token << " <"<<tokenType<<","<<symbolTable[token]<<">"<<endl;
}

void lex(string input){
    string token="";
    char ch;
    for(int i=0;i<input.length();++i){
        ch=input[i];
        switch (ch)
        {
        case ' ':
            break;

        case '=':
            printSymbol("=","1");
            break;
        case ';':
            printSymbol(";","2");
            break;
        
        default:
            if(isalpha(ch)){
                token=ch;
                while(isalnum(input[i+1])){
                    token += input[++i];
                }
                addSymbol(token);
                printSymbol(token,"3");
                token="";
            }
            else if(isdigit(ch)){
                token += ch;
                while(isdigit(input[i+1])){
                    token += input[++i];
                }
                addSymbol(token);
                printSymbol(token,"4");
                token="";
            }
            else if(isOperator(ch)){
                if(ch == '+' && input[i+1] == '+'){
                    printSymbol("++","5");
                    i++;
                }
                else if(ch == '-' && input[i+1] == '-'){
                    printSymbol("--","5");
                    i++;
                }
                else{
                    printSymbol(string(1,ch),to_string((int)ch));
                }
            }
            break;
        }
    }
}

int main(){
    string input;
    getline(cin,input);
    lex(input);
    return 0;
}

