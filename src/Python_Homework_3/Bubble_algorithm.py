def bubble(list_numbers):
    flag = 1
    while flag:
        flag = 0
        for i in range(len(list_numbers) - 1):
            if list_numbers[i] > list_numbers[i + 1]:
                list_numbers[i], list_numbers[i + 1] = list_numbers[i + 1], list_numbers[i]
                flag = 1
    return list_numbers

count = int(input("Введите количество чисел, которое Вы планируете ввести: "))
numbers = [] # Список для хранения введённых чисел
cnt = 0 # Количество введённых значений
while cnt < count:
    var = int(input("Введите значениче: "))
    numbers.append(var)
    cnt += 1

print(bubble(numbers))