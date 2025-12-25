def comparison(str1, str2):
    if len(str1) > len(str2):
        print("Строка 1 меньше строки 2")
        return 0
    elif len(str1) < len(str2):
        print("Строка 1 больше строки 2")
        return 0
    else:
        for i in range(len(str1)):
            if ord(str1[i]) > ord(str2[i]):
                print("Строка 1 меньше строки 2")
                return 0
            elif ord(str1[i]) < ord(str2[i]):
                print("Строка 1 больше строки 2")
                return 0

string1 = input("Введите строку 1: ")
string2 = input("Введите строку 2: ")
comparison(string1, string2)