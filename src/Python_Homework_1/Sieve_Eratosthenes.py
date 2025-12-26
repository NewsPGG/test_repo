def f(x):
    for i in range(2, int(x**0.5) + 1):
        if (x % i == 0):
            return 0
    return 1

print("Введите число N: ")
n = int(input())
numbers = [2]

for i in range(3, n+1, 2):
    if f(i):
        numbers.append(i)

print(numbers)