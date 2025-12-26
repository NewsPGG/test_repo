class FrozenMatrix:
    # Сохранение матриц, как кортеж кортежей для неизменяемости
    def __init__(self, data):
        self.data = tuple(tuple(row) for row in data)

    # Узнать длину "множества матриц"
    def __len__(self):
        return len(self.data)

    # Сравнение матриц
    def __eq__(self, other):
        if not isinstance(other, FrozenMatrix):
            return False
        return self.data == other.data

    # Хеширование данных
    def __hash__(self, data):
        return hash(self.data)