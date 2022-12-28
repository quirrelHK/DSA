#include <iostream>
#include <vector>

using namespace std;

// Define a function type for the derivative of y with respect to x
typedef double (*Derivative)(double x, double y);

vector<double> taylor(Derivative f, double x0, double y0, double x, double h) {
    // Initialize the vector to store the approximations for y
    vector<double> y;
    y.push_back(y0);

    // Iterate through the steps
    for (int i = 1; x0 + i*h <= x; i++) {
        // Use Taylor's method to approximate the next value of y
        y.push_back(y[i-1] + h*f(x0 + (i-1)*h, y[i-1]));
    }

    return y;
}

// Example usage:

// Define the differential equation and the initial values
double f(double x, double y) {
    return x + y*y;
}

int main() {
    double x0 = 0;
    double y0 = 1;

    // Solve the differential equation using Taylor's method
    double x = 0.1;
    double h = 0.1;
    vector<double> y = taylor(f, x0, y0, x, h);

    for (double yi : y) {
        cout << yi << endl;
    }

    return 0;
}
