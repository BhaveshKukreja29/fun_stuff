# Implementation of Zeller's Congruence
# Reference: en.wikipedia.org/wiki/Zeller's_congruence


day = int(input("Enter the day(1, 2, .., 30): "))
month = int(input("Enter month(March=3, April=4, ... January=13, February=14): "))
year = int(input("Enter year: "))

weekdays = ["Satruday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]

def calc_weekday(day, month, year):
    if month >= 13:
        year -= 1

    k = year % 100
    j = year // 100
    f = int((13 * (month + 1)) / 5)
    h = (day + f + k + int(k / 4) + int(j / 4) - 2 * j) % 7
    return h

h = calc_weekday(day, month, year)

print(f"It is {weekdays[h]} on the said date.")


