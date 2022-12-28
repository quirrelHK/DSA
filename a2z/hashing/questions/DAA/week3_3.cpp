/*Name: Ritesh Singh
Sec: C
Roll No: 52
Student ID: 20011347*/

#include<bits/stdc++.h>

void input(std::vector<int> &a, int n){
    int element;
    for(int i = 0; i < n; ++i){
        std::cin >> element;
        a.push_back(element);
    }
}

int main(){
    int size,cases;
     
    std::cin >> cases;
    int values[2];

    for(int i = 0; i < cases; ++i){
        std::cin >> size;
        std::vector<int> arr;

        input(arr,size);
        std::sort(arr.begin(), arr.end());
        std::set<int> s1{arr.begin(),arr.end()};
        
        if(arr.size() != s1.size())
        std::cout << "YES" << '\n';
        else
        std::cout << "NO" << '\n';

    }
    
   
    return 0;
}