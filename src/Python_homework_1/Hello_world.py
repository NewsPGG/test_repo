import dis

def cube_bytecode():
    n = int(input("Введите натуральное число: "))
    if n >= 1:
        result = n ** 3
        print("Куб вашего числа равен ", result)

dis.dis(cube_bytecode)