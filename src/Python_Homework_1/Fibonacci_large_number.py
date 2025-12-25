print("Введите вашу фамилию: ")
familia = len(input())

fib = [1, 1]

while ((len(fib)) < (10 ** 6 + familia)):
    fib.append(fib[-2] + fib[-1])

print(fib[-1] / 239)