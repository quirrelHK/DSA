#include<bits/stdc++.h>
using namespace std;

float gauss_interpolation(int x, vector<vector<int>> data, int rows){

    int a = data[rows/2][0],h = data[1][0]-data[0][0];
    float u = (x - a)/(float)h;

    float val = data[rows/2][1],p = 1;
    
    int j,k=0,l=1;
    for(int i = 1; i < rows; ++i){
        for(j = 0; j < rows-i; ++j){
            data[j][1] = data[j+1][1] - data[j][1];
        }
        if (i%2==1)
            p = p*(u+k++)/i;
        
        else
            p = p*(u-l++)/i;
     
        val = val + p*data[(rows-i)/2][1];
    }
    return val;
}

int main(){

    int rows;
    cin >> rows;
    vector<vector<int>> data(rows, vector<int>(2,0));

    
    for(int i = 0; i < rows; ++i){
        int x, y;
        cin >> x >> y;

        data[i][0] = x;
        data[i][1] = y;
    }

    int find_x;
    cin >> find_x;
    
    cout << "Y(x): " << gauss_interpolation(find_x,data,rows);
    return 0;
}
