def check_position(queen, posted_quens):
    row, col = queen
    for temp_row, temp_col in posted_quens:
        if ((temp_row == row) or (temp_col == col) or (abs(temp_row - row) == abs(temp_col - col))):
            return False
    return True

def solutions(n):
    solutions = []
    positions = [-1] * n
    row = 0

    while True:
        found = False
        start_col = positions[row] + 1
        for col in range(start_col, n):
            if check_position((row, col), [(r, positions[r]) for r in range(row) if positions[r] != -1]):
                positions[row] = col
                found = True
                break

        if not found:
            positions[row] = -1
            if row == 0:
                break
            row -= 1
        else:
            if row == n - 1:
                solution = []
                for r in range(n):
                    solution.append((r, positions[r]))
                solutions.append(solution)
                positions[row] = -1
                row -= 1
            else:
                row += 1

    return solutions

n = int(input("Введите N: "))
solutions = solutions(n)
print("Количество решений: ", len(solutions))