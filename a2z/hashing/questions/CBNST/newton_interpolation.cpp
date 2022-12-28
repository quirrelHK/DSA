#include<bits/stdc++.h>
using namespace std;

float newton_interpolation(int year, vector<vector<int>> data, int rows){
    int sign = 1;
    int a,h = data[1][0]-data[0][0];
    if (year < data[1][0])
        a = data[0][0];
    else{
        a = data[rows-1][0];
        sign = -1;
    }
    float u = (year - a)/(float)h;
    
    float val;
    if (sign == 1)
        val = data[0][1];
    else
        val = data[rows-1][1];

    float p = 1;
    int j;
    for(int i = 1; i < rows; ++i){
        for(j = 0; j < rows-i; ++j){
            data[j][1] = data[j+1][1] - data[j][1];
        }
        p = p*(u-sign*(i-1))/i;
        if (sign == 1)
            val = val + p*data[0][1];
        else
            val = val + p*data[--j][1];
    }
    return val;

}

int main(){
    int rows;
    cin >> rows;
    vector<vector<int>> data (rows, vector<int>(2,0));

    for(int i = 0; i < rows; ++i){
        int year, popu;
        cin >> year >> popu;

        data[i][0] = year;
        data[i][1] = popu;
    }

    int find_year;
    cin >> find_year;
    
    cout << "Population: " << newton_interpolation(find_year,data,rows);
    return 0;
}