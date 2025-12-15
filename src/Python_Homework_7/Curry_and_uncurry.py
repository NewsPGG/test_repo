def curry(f, n): # Функция каррирования
    if n < 1:
        print("Арность должна быть положительным числом!")
    if n == 1:
        return f
    # Если арность > 1, рекурсивно вызываем curry, которая подставляет получаемые
    # аргументы внутренней функцией f
    return lambda x: curry(lambda *args: f(x, *args), n - 1)

def uncurry(f, n): # Функция анкаррирования
    if n < 1:
        raise ValueError("Арность должна быть положительным числом")
    # Если n положительно, создаём новую функцию для анкаррирования преданных аргументов
    def uncurried(*args):
        if len(args) != n:
            print("Получено не столько аргументов, сколько ожидается(")
        current = f
        # Проходимся по всем переданным аргументам и применяем к каждому переданную
        # в current функцию f
        for arg in args:
            current = current(arg)
        return current
    return uncurried


# Пример работы из задачи
def sum3(x, y, z):
    return x + y + z

sum3_curry = curry(sum3, 3)
sum3_uncurry = uncurry(sum3_curry, 3)
print(sum3_curry(1)(2)(3))
print(sum3_uncurry(1, 2, 3))