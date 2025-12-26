class Matrix:
    def __init__(self, data):
        self.data = data
        self.rows = len(data)
        self.cols = len(data[0])

    # Сложение матриц
    def __add__(self, other):
        if (self.rows != other.rows) or (self.cols != other.cols):
            raise ValueError("Матрицы должны иметь одинаковый размер!!!")
        result_matrix = []
        for i in range(self.rows):
            row = []
            for j in range(self.cols):
                row.append(self.data[i][j] + other.data[i][j])
            result_matrix.append(row)
        return Matrix(result_matrix)

    # Умножение на константу
    def __mul__(self):
        number = int(input())
        result_matrix = []
        for i in range(self.rows):
            row = [self.data[i][j] * number for j in range(self.cols)]
            result_matrix.append(row)
        return Matrix(result_matrix)

    # Умножение матрицы (только одинаковых по размеру)
    def __mulmatrix__(self, other):
        if self.cols != other.rows:
            raise ValueError("У матриц разный размер, я так не умею (")

        result_matrix = []
        for i in range(self.rows):
            row = []
            for j in range(other.cols):
                row.append(self.data[i][j] * other.data[i][j])
            result_matrix.append(row)
        return Matrix(result_matrix)

    # Вычисление определителя (для квадратных матриц)
    def __det__(self):
        if self.rows != self.cols:
            raise ValueError("Матрица должна быть квадратной!!")

        if self.rows == 1:
            return self.data[0][0]

        if self.rows == 2:
            return self.data[0][0] * self.data[1][1] - self.data[0][1] * self.data[1][0]

        result = 0
        for j in range(self.cols):
            minor_data = []
            for i in range(1, self.rows):
                row = [self.data[i][k] for k in range(self.cols) if k != j]
                minor_data.append(row)

            minor = Matrix(minor_data)
            sign = 1 if j % 2 == 0 else -1
            result += sign * self.data[0][j] * minor.det()
        return result

    # Итерирование по матрице
    def __iter__(self):
        return iter(self.data)