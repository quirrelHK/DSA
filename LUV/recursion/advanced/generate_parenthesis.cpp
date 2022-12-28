// Leetcode 

#include<bits/stdc++.h>
using namespace std;

vector<string> res;

void generate(string &s,int open, int close){

    if(open==0 && close==0){
        res.push_back(s);
        return;
    }

    if(open > 0){
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();    // backtracking step
    }
    if(close > 0){
        if(open < close){
            s.push_back(')');
            generate(s,open,close-1);
            s.pop_back();  // backtracking step
        }
    }
}

int main(){

    int n=5;
    string s="";
    generate(s,n,n);

    for(auto &str: res){
        cout << str << endl;
    }

}