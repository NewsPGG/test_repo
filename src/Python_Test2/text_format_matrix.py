class MatrixPresentation:
    def __init__(self, data):
        self.data = data

    def to_mtx(self):
        rows = len(self.data)
        cols = len(self.data[0])

        result = f"{rows} {cols}" + "\n"
        for row in self.data:
            result += " ".join(str(x) for x in row) + "\n"
        return result

    def from_mtx(mtx_text):
        lines = mtx_text.strip().split("\n")
        rows, cols = map(int, lines[0].split())

        data = []
        for i in range(1, rows + 1):
            row = list(map(float, lines[i].split()))
            data.append(row)

        return MatrixPresentation(data)