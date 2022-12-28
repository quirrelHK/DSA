#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if (n == 1) return 1;

    return n*fact(n-1);
}

float stirling_inter(int x, vector<vector<int>> data, int rows){

    int a = data[rows/2][0],h = data[1][0]-data[0][0];
    float u = (x - a)/(float)h;

    float val = data[rows/2][1],p_odd = 1,p_even=1;
    
    int k=0,l=1;
    for(int i = 1; i < rows; ++i){
        for(int j = 0; j < rows-i; ++j){
            data[j][1] = data[j+1][1] - data[j][1];
        }
        if (i%2==1){
            p_odd*=(pow(u,k+1) - (k%2))/fact(i);
            val = val + p_odd*(data[(rows-i)/2][1] + data[((rows-i)/2)-1][1])/2;
            ++k;
        }
        
        else{
           p_even*=(u*u - (l-1))/fact(i);
            val = val + p_even*data[(rows-i)/2][1];
            ++l; 
        }
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
    
    cout << "F(x): " << stirling_inter(find_x,data,rows);
    return 0;
}


