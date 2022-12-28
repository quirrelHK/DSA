#include<bits/stdc++.h>
using namespace std;

int main(){
    double num,t_num,r_num;
    int deci_place;
    cin >> num >> deci_place;

    long temp = num*(pow(10,deci_place));
    t_num = temp/pow(10,deci_place);

    temp = (num >0)?(num*pow(10,deci_place) + 0.5):(num*pow(10,deci_place) - 0.5);
    r_num = temp/pow(10,deci_place);
    cout << "For truncated:\n";
    double a_error = abs(num - t_num);
    cout << "Absolute error: " << a_error;
    cout << "\nRelative error: " << a_error/abs(num);
    cout << "\nPercentage relative error: " << (a_error/abs(num))*100;

    cout << "\n\nFor rounded:\n";
    a_error = abs(num - r_num);
    cout << "Absolute error: " << a_error;
    cout << "\nRelative error: " << a_error/abs(num);
    cout << "\nPercentage relative error: " << (a_error/abs(num))*100;


    return 0;
}