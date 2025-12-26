def heap_sort(array):
    n = len(array)
    # Рассматриваем список, как двоичное дерево
    for i in range(n // 2 - 1, -1, -1):
        # Идём от последнего родителя, который равен n // 2 - 1 до начала списка
        parent = i
        while True:
            left_child = 2 * parent + 1
            right_child = 2 * parent + 2
            max_idx = parent

            if left_child < n and array[left_child] > array[max_idx]: # Если левый ребенок больше родителя
                max_idx = left_child # Меняем их местами
            if right_child < n and array[right_child] > array[max_idx]: # Если правый ребенок больше родителя
                max_idx = right_child # Меняем их местами
            if max_idx == parent: # Если родитель и дети расставлены корректно
                break # Завершаем while
            # Если цикл не завершился, значит max_idx больше parent, меняем их местами в списке
            array[parent], array[max_idx] = array[max_idx], array[parent]
            # Присваиваем переменной parent значение max_idx для дальнейших проверок корректности родителя и детей
            parent = max_idx

    for end in range(n - 1, 0, -1):
        # Меняем местами первый и последний элементы дерева, максимальный элемент фиксируется в конце списка
        array[0], array[end] = array[end], array[0]
        parent = 0
        # Делаем проверку с начала дерева на корректность родителя и детей
        while True:
            left_child = 2 * parent + 1
            right_child = 2 * parent + 2
            max_idx = parent
            if left_child < end and array[left_child] > array[max_idx]: # Если левый ребенок больше родителя
                max_idx = left_child # Меняем их местами
            if right_child < end and array[right_child] > array[max_idx]: # Если правый ребенок больше родителя
                max_idx = right_child # Меняем их местами
            if max_idx == parent: # Если родитель и дети расставлены верно
                break # Завершаем цикл
            # Если цикл не завершился, значит max_idx больше parent, меняем их местами в списке
            array[parent], array[max_idx] = array[max_idx], array[parent]
            # Присваиваем переменной parent значение max_idx для дальнейших проверок корректности родителя и детей
            parent = max_idx

    return array

elements = list(map(int, input("Введите числа: ").split()))
print("Отсортированный список: ", heap_sort(elements))