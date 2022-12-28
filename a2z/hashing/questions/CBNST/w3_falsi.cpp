#include<iostream>
#include<math.h>
#define f(x) x*x*x-2*x-5//x*x-2*x-2 //cos(x)-x*exp(x) //x*log10(x)-1.2
using namespace std;

int main(){
    int count = 10;
    float x_pos,x_neg;
    double x,x_val;
    cout << "Enter x for which y is positive: ";
    cin >> x_pos;
    cout << "Enter x for which y is negative: ";
    cin >> x_neg;
    for(int i = 0; i < count; ++i){
        double f_pos = f(x_pos);
        double f_neg = f(x_neg);
        x = (x_neg*f_pos - x_pos*f_neg)/(f_pos - f_neg);
        x_val = f(x);
        if(x_val == 0){
            break;
        }
        else if(x_val < 0){
            x_neg = x;
        }
        else{
            x_pos = x;
        }
    }
    cout << "\nRoot: " << x << endl;
    return 0;
}