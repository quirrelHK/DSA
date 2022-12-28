// containers inside a vector
#include<bits/stdc++.h>
using namespace std;

void printVec(vector<int> &v){
    cout << "Size: " << v.size() << endl;
    for(int i=0;i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    // vector<pair<int,int> > v = {{1,2},{2,3},{4,5}};
    /*vector<pair<int, int>> v;
    int n;
    cin >> n;
    for(int i=0;i <n;++i){
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    printVec(v);
    */

   // **** Array of vectors ****
  
    cout << "Array of vectors " << endl;
    /* 
    // No. of rows fixed but no. of columns dynamic
   int N;
   cin >> N;
   vector<int> v[N]; // N vectors of size 0

   for(int i=0;i<N;++i){
        int n;
        cin >> n;
        for(int j=0;j<n;++j){
            int x;
            cin >> x;
            v[i].push_back(x);
        }
   }
   for(int i=0;i<N;++i){
        printVec(v[i]);
    }
    */

   // **** Vector of vectors ****
    cout << " Vector of vectors\n";
    // Both rows and columns are dynamic

    vector<vector<int>> v;
    int N;
    cin >> N;
    for(int i=0;i<N;++i){
        int n;
        cin >> n;
        vector<int> temp;    // Initially vector is empty so we cannot do v[i].push_back. So, we create a temp vector then push it back to original one
        for(int j=0;j<n;++j){
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v.push_back(temp);
    }

    for(int i=0;i <N;++i){
        printVec(v[i]);
    }
}