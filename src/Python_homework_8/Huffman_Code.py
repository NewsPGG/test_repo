import heapq
import struct

def encode(msg):
    # Если пользователь не ввёл ничего, возвращаем пустое закодированное сообщение и пустой словарь
    if not msg:
        return "", {}

    # Подсчёт частоты символов
    freq = {}
    for char in msg:
        # Добавляет 1 к найденному ключу. Если ключ не найден, создаёт его, инициализирует значением 0
        freq[char] = freq.get(char, 0) + 1

    # Создание кучи
    # Список сгенерированных списков вида [частота встречи, [символ, пустая строка для двоичной записи символа]]
    heap = [[value, [char, ""]] for char, value in freq.items()]
    # Сортировка списка с помощью heap sort
    heapq.heapify(heap)

    # Построение дерева Хаффмана
    while len(heap) > 1:
        # Первый символ с наименьшей частотой
        lo = heapq.heappop(heap)
        # Второй символ с наименьшей частотой
        hi = heapq.heappop(heap)
        # Проходимся по спискам вида [символ, код двоичной записи символа] в lo
        for pair in lo[1:]:
            # Добавляем 0 к строке для двоичной записи символа перед ней
            pair[1] = '0' + pair[1]
        # Проходимся по спискам вида [символ, код двоичной записи символа] в hi
        for pair in hi[1:]:
            # Добавляем 1 к строке для двоичной записи символа перед ней
            pair[1] = '1' + pair[1]
        # Добавляем в сортированный список список вида [сумма частот символов, [символ, код], [символ, код], ...]
        heapq.heappush(heap, [lo[0] + hi[0]] + lo[1:] + hi[1:])

    # Создание таблицы кодирования
    huffman_table = {}
    # Проходимся по всем спискам вида [символ, код]
    for pair in heap[0][1:]:
        # Добавляем в словарь в качестве ключа символ, в качестве значения код
        huffman_table[pair[0]] = pair[1]

    # Кодирование сообщения
    encoded_msg = ''.join(huffman_table[char] for char in msg)

    return encoded_msg, huffman_table

def decode(encoded, table):
    # Если пользователь ничего не ввёл, возвращаем пустую строку
    if not encoded:
        return ""

    # Создание обратной таблицы
    reverse_table = {v: k for k, v in table.items()}
    print(reverse_table)

    # Декодирование
    # Переменная для текущего кода
    current_code = ""
    # Список раскодированных символов
    decoded_chars = []
    # Проходим по каждому биту закодированной записи
    for bit in encoded:
        # Добавляем бит в конец текущего кода
        current_code += bit
        # Если текущий код есть в таблице для раскодировки
        if current_code in reverse_table:
            # Добавляем в список раскодированных символов значение с соответствующим кодом из таблицы
            decoded_chars.append(reverse_table[current_code])
            # Сбрасываем текущий код
            current_code = ""

    return ''.join(decoded_chars)


def encode_to_file(msg, filename):
    # Применяем функцию encode для переданного сообщения
    encoded, table = encode(msg)

    # Открываем файл в формате write-binary
    with open(filename, 'wb') as file:
        # Записываем размер таблицы, упаковывая его в 4 байта
        file.write(struct.pack('i', len(table)))

        # Записываем каждый символ и его код
        for char, code in table.items():
            # Записываем символ как 4-байтовый Unicode
            file.write(struct.pack('i', ord(char)))
            # Записываем длину кода и сам код
            file.write(struct.pack('i', len(code)))
            # Преобразуем битовую строку в байты
            code_bytes = int(code, 2).to_bytes((len(code) + 7) // 8, 'big')
            # Записываем преобразованную строку
            file.write(code_bytes)

        # Записываем закодированное сообщение
        file.write(struct.pack('i', len(encoded)))
        # Преобразуем сообщение, записанное в битах, в байты
        encoded_bytes = int(encoded, 2).to_bytes((len(encoded) + 7) // 8, 'big')
        # Записываем в файл преобразованное сообщение
        file.write(encoded_bytes)

    return table


def decode_from_file(filename):
    # Открываем файл в формате read-binary
    with open(filename, 'rb') as file:
        table = {}

        # Читаем размер таблицы, записанный в файле 4 байтами
        table_size = struct.unpack('i', file.read(4))[0]
        # Читаем саму таблицу
        for i in range(table_size):
            # Читаем символ
            char_code = struct.unpack('i', file.read(4))[0]
            char = chr(char_code)

            # Читаем длину кода
            code_length = struct.unpack('i', file.read(4))[0]

            # Читаем код
            # Вычисляем, сколько байтов было использовано для хранения строки
            code_bytes_len = (code_length + 7) // 8
            # Читаем из файла нужное число байтов
            code_bytes = file.read(code_bytes_len)
            # Преобразование байтов обратно в целое число
            code_int = int.from_bytes(code_bytes, 'big')
            # Преобразуем число в битовую строку (если длина строки меньше длины кода, добавляем нули в начало)
            code = bin(code_int)[2:].zfill(code_length)
            # Добавляем в словарь в качестве ключа символ, в качестве значения - код символа
            table[char] = code

        # Читаем закодированное сообщение
        # Читаем из файла 4 байта и распаковываем их
        encoded_length = struct.unpack('i', file.read(4))[0]
        # Вычисляем сколько байтов занимает закодированное сообщение
        encoded_bytes_len = (encoded_length + 7) // 8
        # Читаем из файла вычисленное число байтов
        encoded_bytes = file.read(encoded_bytes_len)
        # Преобразование байтов в целое число
        encoded_int = int.from_bytes(encoded_bytes, 'big')
        # Преобразуем целое число в битовую строку (если длина строки меньше длины кода, добавляем в начало нули)
        encoded = bin(encoded_int)[2:].zfill(encoded_length)

        return decode(encoded, table)


last_code_message = None
while 1:
    print("Введите операцию, которую хотите сделать:\n"
          "0 - выйти из меню\n"
          "1 - кодирование введённого сообщения\n"
          "2 - раскодировать последнее сохранённое сообщение\n"
          "3 - кодирование файла\n"
          "4 - раскодировать файла"
            )
    operation = int(input())

    if operation == 0:
        break

    if operation == 1:
        input_message = input("Введите сообщение, которое хотите закодировать: ")
        last_code_message = encode(input_message)
        print("\nУспешно!\n", last_code_message)

    if operation == 2:
        try:
            print(decode(last_code_message[0], last_code_message[1]))
            last_code_message = None
            print("\nЗакодирвоанное сообщение очищено!\n")
        except:
            print("\nНет закодированного сообщения!\n")

    if operation == 3:
        input_file = input("Введите путь к файлу или сообщение, который(ое) хотите закодировать: ")
        input_to_file = input("Введите путь к файлу, в который хотите поместить закодированный текст: ")
        try:
            file = open(input_file)
            text = file.readline()
            encode_to_file(text, input_to_file)
            file.close()
            print("\nУспешно закодировано!\n")
        except:
            try:
                encode_to_file(input_file, input_to_file)
                print("\nУспешно закодировано!\n")
            except:
                print("\nКодировщику что-то не понравилось! Попробуйте снова!\n")

    if operation == 4:
        file_input = input("Введите путь в файлу, который хотите раскодировать: ")
        try:
            print(decode_from_file(file_input))
            with open(file_input, "w") as f:
                f.truncate(0)
                print("\nФайл очищен!\n")
        except:
            print("\nФайл пуст или не существует :(\n")
