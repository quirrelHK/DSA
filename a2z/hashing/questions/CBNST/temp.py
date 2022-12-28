import numpy as np

def taylor(f, fprime, x0, y0, x, h):
    """
    Solve a first order differential equation using Taylor's method with a second-order approximation.
    
    Parameters:
        f (function): The derivative of the dependent variable y, with respect to the independent variable x.
        fprime (function): The second derivative of the dependent variable y, with respect to the independent variable x.
        x0 (float): The initial value of the independent variable.
        y0 (float): The initial value of the dependent variable.
        x (float): The final value of the independent variable.
        h (float): The step size to use in the approximation.
        
    Returns:
        numpy array: An array containing the approximations for y at each step.
    """
    # Initialize the array to store the approximations for y
    y = np.zeros(int((x - x0)/h) + 1)
    y[0] = y0
    
    # Iterate through the steps
    for i in range(1, len(y)):
        # Use the second-order Taylor series to approximate the next value of y
        y[i] = y[i-1] + h*f(x0 + (i-1)*h, y[i-1]) + h**2*fprime(x0 + (i-1)*h, y[i-1])/2
        
    return y

# Example usage:

# Define the differential equation and the initial values
def f(x, y):
    return x + y**2

def fprime(x, y):
    return y

x0 = 0
y0 = 1

# Solve the differential equation using Taylor's method
x = 0.1
h = 0.1
y = taylor(f, fprime, x0, y0, x, h)

print(y)
print(np.average(y[1:]))