#include<bits/stdc++.h>
using namespace std;

double lagrange(int x, vector<vector<int>> data, int rows){
    double total=0;
    for(int i=0;i<rows;++i){
        double prod=data[i][1];
        for(int j=0;j<rows;++j){
            if(i!=j)
                prod *= (x-data[j][0])/(double)(data[i][0]-data[j][0]);
        }
        total+=prod;
    }
    return total;
}

int main(){
int rows;
    cin >> rows;
    vector<vector<int>> data (rows, vector<int>(2,0));

    for(int i = 0; i < rows; ++i){
        int x, y;
        cin >> x >> y;

        data[i][0] = x;
        data[i][1] = y;
    }

    int find_x;
    cin >> find_x;
    
    cout << "F(x): " << lagrange(find_x,data,rows);
}