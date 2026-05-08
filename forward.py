# This exists because
# they don't teach you how to differentiate a 
# for loop in calculus classes!

class Dual:
    def __init__(self, real, dual):
        self.real = real
        self.dual = dual

    def __add__(self, other):
        real = self.real + other.real
        dual = self.dual + other.dual
        return Dual(real, dual)
    
    def __radd__(self, other):
        return Dual(self.real + other, self.dual)
    
    def __mul__(self, other):
        real = self.real * other.real
        dual = self.real * other.dual + self.dual * other.real
        return Dual(real, dual)
    
    def __rmul__(self, other):
        return Dual(self.real * other, self.dual * other)

def diff(f, x):
    return f(Dual(x, 1)).dual

def f(x):
    y = x

    for _ in range(3):
        y = y * y + x

    return y

x = int(input("Enter x: "))
print(f"Value of f({x}): {f(x)}")
print(f"And f'({x}): {diff(f, x)}")


