// Arrays having dynamic size

// Local and golbal arrays have size limitations which is the same for vectors, this boundation is on "continuos memory allocation" not of arrays and vectors itself.
#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> v){
    cout << "Size: " << v.size() << endl;
    for(int i=0;i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
   /* vector<int> v;  
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        int x;
        cin >> x;
        printVec(v);   // dynamic size
        v.push_back(x);
    }
    printVec(v);
    */
   vector<int> v(5);
   printVec(v);
   v.push_back(99);
   v.push_back(55);
   printVec(v);

//    vector<int> v1(7,9);
//    printVec(v1);

    v.pop_back();
    printVec(v);

    // **** We can directly copy vectors ***
    vector<int> v2 = v;  // O(n)
    v2.push_back(11);
    printVec(v);   // Here also a copy of v is passed. So, changes in printVec will not we reflected of the original vector
    printVec(v2);

    // Pass vector by reference to reduce time complexity

}