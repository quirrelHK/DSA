#include<bits/stdc++.h>
using namespace std;

int main(){

    int n = 10,k = 999999;
    int fact = 1;
    vector<int> numbers;
    string res = "";
    for(int i = 1; i < n; ++i){
        fact *=i;               // calculate the factorial denotes the size of permutation blocks
        numbers.push_back(i);
    }
    numbers.push_back(n);
    k = k - 1;      
    while(true){
        res+= to_string(numbers[k/fact]);   
        numbers.erase(numbers.begin() + k/fact);

        if(numbers.size() == 0) break;
        k = k%fact;
        fact = fact/numbers.size();   // size of next block of permutations
    }

    cout << res << endl;
    return 0;
}