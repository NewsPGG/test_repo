def check_position(queen, posted_quens):
    # Проверка позиций добавленного ферзя и уже расставленных на доске ферзей
    row, col = queen
    for temp_row, temp_col in posted_quens:
        if ((temp_row == row) or (temp_col == col) # Проверка на ряды и столбцы
                or (abs(temp_row - row) == abs(temp_col - col))): # Проверка на диагонали
            return False
    return True

def solutions(n): # Поиск всевозможных решений для n
    solutions = [] # Список для внесения найденных корректных решений
    positions = [-1] * n # Список для проверки занятости ряда
    row = 0

    while True:
        found = False # Переменная для проверки постановки ферзя
        start_col = positions[row] + 1 # Ряд, с которого начинается выполнение цикла
        for col in range(start_col, n):
            # Проверка потенциального ферзя и уже добавленных на корректность расстановки
            if check_position((row, col),
                    [(r, positions[r]) for r in range(row) if positions[r] != -1]):
                positions[row] = col # Изменение значения с -1 на номер столбца
                found = True # Изменение значения переменной для проверки постановки ферзя
                break # Выход из цикла for, так как найден столбец для ферзя

        if not found: # Если столбец для ферзя не найден
            positions[row] = -1 # Изменяем значение списка с индексом ряда на -1
            if row == 0:
                break # Если не нашли ряда для постановки ферзя, выходим из цикла
            row -= 1 # Ищем место для ферзя в меньшем на 1 ряде

        else: # Если столбец для ферзя найден
            if row == n - 1: # Сравниваем значение ряда и n
                solution = []
                for r in range(n):
                    # Добавляем в список solution
                    solution.append((r, positions[r]))
                solutions.append(solution) # Добавляем найденное решение в список всех решений
                positions[row] = -1 # Изменяем значение для поиска следующих решений
                row -= 1 # Возвращаемся к 0 ряду
            else:
                row += 1 # Переходим в следующий ряд

    return solutions

n = int(input("Введите N: "))
solutions = solutions(n)
print("Количество решений: ", len(solutions))