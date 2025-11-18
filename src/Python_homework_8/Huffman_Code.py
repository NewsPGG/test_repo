def bubble_sort(array_number_elements, array_elements):
    for i in range(len(array_number_elements) - 1):
        for j in range(i, len(array_number_elements)):
            if array_number_elements[i] > array_number_elements[j]:
                array_number_elements[i], array_number_elements[j] = array_number_elements[j], array_number_elements[i]
                array_elements[i], array_elements[j] = array_elements[j], array_elements[i]


def tree_huffman_code(array_numbers_elements):
    if len(array_numbers_elements) == 0:
        return []

    if len(array_numbers_elements) == 1:
        return ["0"]

    # Создаем список узлов: (частота, символ, левый_потомок, правый_потомок)
    nodes = [(freq, i, None, None) for i, freq in enumerate(array_numbers_elements)]

    # Строим дерево Хаффмана
    while len(nodes) > 1:
        # Сортируем узлы по частоте
        nodes.sort(key=lambda x: x[0])

        # Берем два узла с наименьшими частотами
        left = nodes.pop(0)
        right = nodes.pop(0)

        # Создаем новый узел
        new_freq = left[0] + right[0]
        new_node = (new_freq, None, left, right)

        # Добавляем новый узел обратно в список
        nodes.append(new_node)

    # Корень дерева
    root = nodes[0]

    # Функция для обхода дерева и генерации кодов
    def generate_codes(node, current_code, codes):
        freq, symbol, left, right = node

        # Если это листовой узел (есть символ)
        if symbol is not None:
            codes[symbol] = current_code
            return

        # Рекурсивно обходим левое и правое поддерево
        if left is not None:
            generate_codes(left, current_code + '0', codes)
        if right is not None:
            generate_codes(right, current_code + '1', codes)

    # Генерируем коды
    codes = [None] * len(array_numbers_elements)
    generate_codes(root, '', codes)

    return codes


input_string = input()
elements = []
numbers_elements = []
for i in input_string:
    flag = 0
    for j in range(len(elements)):
        if elements[j] == i:
            numbers_elements[j] += 1
            flag = 1
    if flag == 0:
        elements.append(i)
        numbers_elements.append(1)

bubble_sort(numbers_elements, elements)

print(elements)
print(numbers_elements)