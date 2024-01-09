a1 = int(input("Enter the real part of first complex number: "))
b1 = int(input("Enter the imaginary part of first complex number: "))

if b1 >= 0:
    opr1 = "+"
elif b1 < 0:
    opr1 = ""

c1 = f"{a1}{opr1}{b1}i"



a2 = int(input("Enter the real part of second complex number: "))
b2 = int(input("Enter the imaginary part of second complex number: "))

if b2 >= 0:
    opr2 = "+"
elif b2 < 0:
    opr2 = ""

c2 = f"{a2}{opr2}{b2}i"

op = input("Enter the operation you want to perform(+ or -): ")

if (b1 + b2) >= 0:
    oprS = "+"
elif (b1 + b2) < 0:
    oprS = ""

if op == "+":
    cS = f"{(a1 + a2)}{oprS}{(b1 + b2)}i"
elif op == "-":
    cS = f"{a1 - a2}{b1 - b2}i"


print(f"The first complex number is {c1}")
print(f"The second complex number is {c2}")
print(f"The solution is {cS}")


