// all_of, any_of, none_of- returns true or false(also work for arrays)
// lambda function is used for writing temporary functions(makes code short)

#include<bits/stdc++.h>
using namespace std;


int main(){
    // add 2 to a integer
   cout <<  [](int x){return x+2;}(2) << endl;  // syntax- [](paramters){return value;}(passed parameters)

   auto sum = [](int x, int y){return x+y;}; // assigned the lambda function to a variable

   cout << sum(5,6) << endl; 

   vector<int> v = {-2,-3,-5};

    // returns true if ALL elements return true else false (like ending)
   cout << all_of(v.begin(), v.end(), [](int x){return x>0;}) << endl;  // takes every element and applies lambda funtion to each element

    // returns true evern if one elements gives true (like oring)
    cout << any_of(v.begin(),v.end(), [](int x){return x>0;}) << endl;

    // returns true if all are false
    cout << none_of(v.begin(), v.end(), [](int x){return x>0;}) << endl;

    // check if all are even

    cout << all_of(v.begin(),v.end(), [](int x){return x%2==1;}) << endl;

}