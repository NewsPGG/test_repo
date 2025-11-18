arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]

for i in range(len(arr) - 1):
    for j in range(i, len(arr)):
        if arr[i] > arr[j]:
            arr[i], arr[j] = arr[j], arr[i]

print(arr)