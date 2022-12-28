#include<iostream>
#include<math.h>
#define f(x) x*x-2*x-2 //cos(x)-x*exp(x) //x*log10(x)-1.2
#define COUNT 10
using namespace std;

int main(){
    float xp,xn;
    double y;
    float div;
    cout << "Enter x for which y is positive: ";
    cin >> xp;
    cout << "Enter x for which y is negative: ";
    cin >> xn;
    for(int i = 0; i < COUNT; ++i){
        div = (xp+xn)/2;
        y = f(div);
        if(y < 0){
            xn = div;
        }
        else{
            xp = div;
        }
    }
    cout << "\nRoot: " << div << endl;
    return 0;
}