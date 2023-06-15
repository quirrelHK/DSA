#include<bits/stdc++.h>
using namespace std;

bool isKeyword(string str){
    vector<string> kw = {"if","else","int","float","break","for","while"};

    return find(kw.begin(),kw.end(),str) != kw.end();
}

bool isSeparator(char ch){
    string sep="{}[](),;";
    return sep.find(ch) != string::npos;
}

bool isOperator(char ch){
    string op="+-*/%";
    return op.find(ch)!=string::npos;
}

vector<pair<string,string>> tokenizer(string input){
    vector<pair<string,string>> res;
    string buffer="";
    bool isString=false;
    char ch;
    for(int i=0;i<input.length();++i){
        ch=input[i];
        if(ch =='"' && !isString){
            isString=true;
            continue;
        }

        if(ch=='"'){
            res.push_back({"string",buffer});
            buffer="";
            isString=false;
        }

        if(isString){
            buffer+=ch;
            continue;
        }

        if(isspace(ch) || isOperator(ch) || isSeparator(ch)){
            if(!buffer.empty()){
                if(isKeyword(buffer)){
                    res.push_back({"keyword",buffer});
                }
                else{
                    res.push_back({"identifier",buffer});
                }
                buffer="";
            }
            if(isOperator(ch)){
                res.push_back({"operator",string(1,ch)});
            }
            if(isSeparator(ch)){
                res.push_back({"separator",string(1,ch)});
            }

        }
        else{
            buffer+=ch;
        }

    }

    if(!buffer.empty()){
        if(isKeyword(buffer)){
            res.push_back({"keyword",buffer});
        }
        else{
            res.push_back({"identifier",buffer});
        }
    }

    return res;
}


int main(){
    ifstream file("input.txt");
    string input;
    getline(file,input,'\0');
    vector<pair<string,string>> tokens = tokenizer(input);

    for(auto &token:tokens){
        cout << token.first << " : " << token.second << endl;
    }
    return 0;
}