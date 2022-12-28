#include<bits/stdc++.h>
using namespace std;

double calc(double pre, int rows, double u){
    pre = u;
    for(int i=1;i<=rows/2; i++){
        pre *= (u-i);
    }
    
    for(int i=1;i<=rows/2-1; i++){
        pre *= (u+i);
    }
    
    return pre;
}
double bessel_interpolation(vector<vector<double>> &data, int rows, double x){
    int ind;
    if(rows%2 == 0)
        ind = rows/2-1;
    else
        ind = rows/2;
    double u = (x-data[ind][0])/(data[1][0]-data[0][0]);
    // cout << u << endl;
    int i=rows,cnt=0;
    vector<double> temp;
    temp.push_back((data[ind][2]+data[ind+1][2])/2.0);
    ind--;
    while(i != 1){
        for(int j=0;j<i-1; j++){
            data[j][2] = data[j+1][2] -data[j][2];
        }
        if(cnt%2){
            temp.push_back((data[ind][2]+data[ind+1][2])/2.0);
            ind--;
        }
        else{
            temp.push_back(data[ind+1][2]);
        }
        cnt++;
        i--;
    }
    
    double pre = 1,fact = 1;
    double ans = temp[0];
    for(int i=1; i<temp.size(); i++){
        fact *= i;
        if(i%2){
            ans += ((u-0.5)*pre*temp[i])/(double)fact;
            
        }
        else{
            pre = calc(pre,i,u);
            ans += (pre*temp[i])/(double)fact;
            
        }
    }
    return ans;
    
}

int main(){
    int rows;
    cin >> rows;
    vector<vector<double>> data (rows, vector<double>(3,0));

    for(int i = 0; i < rows; ++i){
        cin >> data[i][0] >> data[i][1];
        data[i][2] = data[i][1];
    }

    double find_x;
    cin >> find_x;
    
    cout << "F(x): " << bessel_interpolation(data,rows,find_x);
    
}