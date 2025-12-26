print("Введите фамилию, имя и отчество: ")
familia = len(input())
name = len(input())
surname = len(input())
if surname == 0:
    surname = 19

print("Введите любое число: ")
number = int(input()) # Число, необходимое разменять

flag = 0 # Флаг для выхода из первого цикла и конечной проверки

for i in range(number // familia + 1): # Перебор различного кол-ва монет номиналом "фамилия"
    for j in range((number - familia * i) // name + 1): #Перебор различного кол-ва монет номинала "имя", исключая
        # Сумму из монет номинала "фамилия"
        cnt = number - (familia * i + name * j) # Остаток после вычета монет "фамилия" и "имя"
        if cnt % surname == 0:
            print("Для размена понадобится: ", i, "монет(а)(ы) номиналом", familia, ";", j,
                  "монет(а)(ы) номиналом", name, ";", cnt // surname, "монет(а)(ы) номиналом", surname)
            flag = 1
            break
    if flag == 1:
        break

if flag == 0:
    print("-42!")