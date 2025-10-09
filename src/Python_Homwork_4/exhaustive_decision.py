from itertools import permutations

def check_positions(posted_quens):
    for i in range(0, len(posted_quens)):
        for j in range(i + 1, len(posted_quens)):
            if ((posted_quens[i][0] == posted_quens[j][0]) or (posted_quens[i][1] == posted_quens[j][1]) or
                    (abs(posted_quens[i][0] - posted_quens[j][0]) == abs(posted_quens[i][1] - posted_quens[j][1]))):
                return False
    return True

n = int(input("Введите n: "))
row = [i for i in range(n)]
options = permutations(row, n)
cnt = 0
for i in options:
    possible_solution = []
    for j in range(n):
        possible_solution.append([j, i[j]])
    if check_positions(possible_solution):
        cnt += 1
print("Количество решение: ", cnt)