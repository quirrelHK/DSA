#include<bits/stdc++.h>
using namespace std;

int main(){
//    string str1;
//    cin >> str1;   // cin reads upto to whitespace or newline character
//    cout << str1 << endl; 
   // strings are 0 indexed

   // getline reads one line of input (i.e. upto newline)
//    string str2;
//    getline(cin, str2);
//    cout << str2 << endl;


    /* Problem with this:
        cin doesn't read \n so in buffer after reading 't' \n will still be there,
        first getline will read this \n. So, we won't get desired result.
        input:             output:
        3                  1.     (newline character here)
        abc def            2.abc def
        hello              3.hello
        there*/
    // int t;
    // cin >> t;
    // cin.ignore();    // ignores the newline character
    // while(t--){              
    //     string s;
    //     getline(cin, s);
    //     cout << s << endl;
    // }




    // reverse a string
    string strs,rev_str;
    cin >> strs;
    for(int i = strs.size()-1; i >=0; --i){
        rev_str.push_back(strs[i]);    // O(1)
        /* Alternatively:
            rev_str = rev_str + strs[i];  // makes a copy of rev_str and then add, so time complexity increases as string size increases i.e. with the value of i
            
            not a good idea; more time complexity and strs[i] is a character
            and we are concatenating it to our string*/

    }
    cout << rev_str << endl;

}
