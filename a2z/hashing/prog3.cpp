#include<bits/stdc++.h>
using namespace std;

unordered_map<string,string> smybolTable;

bool isComparator(char ch){
    string comp = ">=<==!=";
    return comp.find(ch) != string::npos;
}

bool isSeparator(char ch){
    string sep="{}[](),;";
    return sep.find(ch) != string::npos;
}

void addSmybol(string str){
    if(smybolTable.find(str) == smybolTable.end()){
        smybolTable[str] = "T"+ to_string(smybolTable.size()+1);
    }
}

void printSmybol(string token, string tokenType){
    cout << token << " <" <<tokenType <<","<<smybolTable[token] <<">"<<endl; 
}


void lex(string input){
    string token="";
    char ch;
    int ind=0;
    for(int i=0;i<input.length();++i){
        ch = input[i];

        switch (ch)
        {
        case ' ':
            break;
        
        case '=':
            printSmybol("=","1");
            break;
        case ';':
            printSmybol(";","2");
            break;
        case 'i':
            if(~(input[i+1]-'f') && !isalpha(input[i+2])){
                printSmybol("if","3");
                i+=2;
            }
            break;
        case 'e':
            ind=i+1;
            while(isalpha(input[ind])) ind++;
            if(!input.substr(i,ind-i).compare("else")){
                printSmybol("else","3");
                i+=(ind-i);
            }
            break;
        default:
            if(isalpha(ch)){
                token+=ch;
                while(isalnum(input[i+1])){
                    token += input[++i];
                }
                printSmybol(token,"4");
                token="";
            }
            else if(isdigit(ch)){
                token += ch;
                while(isdigit(input[i+1])){
                    token += input[++i];
                }
                printSmybol(token,"5");
                token="";
            }
            else if(isSeparator(ch)){
                printSmybol(string(1,ch),to_string((int)ch));
            }
            else if(isComparator(ch)){
                printSmybol(string(1,ch),to_string((int)ch));
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