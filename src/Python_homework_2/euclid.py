def euclid(number1, number2): #Реализация расширенного алгоритма Евклида
    if number2 == 0:
        return number1, 1, 0
    else:
        standart_euclid, x1, y1 = euclid(number2, number1 % number2)
        x = y1
        y = x1 - (number1 // number2) * y1
        return standart_euclid, x, y

print("Введите 2 целых числа: ")
num1 = int(input())
num2 = int(input())

if (num1 % 1 == 0) and (num2 % 1 == 0): #Проверка на чисел на целостность
    nod, var1, var2 = euclid(num1, num2)
    print(nod, "=", num1*var1, "+", num2*var2, "| Это верно!")
else:
    print("Введите целые числа!!")