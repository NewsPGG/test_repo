class Graph:
    # Создание графа
    def __init__(self):
        # Создаём граф, где ключи - вершины, значения - списки соседей
        self.add_list = {}

    # Добавление вершин
    def add_vertex(self, vertex):
        # Проверяем, существует ли вершина
        if vertex not in self.add_list:
            # Добавляем вершину, как ключ
            self.add_list[vertex] = []

    # Создание рёбер между вершинами
    def add_edge(self, value1, value2):
        # Проверка существования первой вершины
        self.add_vertex(value1)
        # Проверка существования второй вершины
        self.add_vertex(value2)
        # Добавляем в ключ value1 значение value2
        self.add_list[value1].append(value2)
        # Добавляем в ключ value2 значение value1
        self.add_list[value2].append(value1)

    # Рекурсивно обходим начальную вершину и всех соседей
    def dfs_step(self, vertex, colors):
        # Помечаем вершину как посещённую
        colors[vertex] = "gray"
        # Добавляем в результат
        print(vertex)

        # Обходим всех непосещённых соседей
        for neighbor in self.add_list[vertex]:
            if colors[neighbor] == "white":
                self.dfs_step(neighbor, colors)

        # Помечаем вершину чёрным, как отработанную
        colors[vertex] = "black"

    def dfs(self, start_vertex):
        # Делаем белый цвет всем вершинам
        colors = {vertex: "white" for vertex in self.add_list}

        # Запускаем обход графа из стартовой вершины
        self.dfs_step(start_vertex, colors)

    def __iter__(self):
        # Проверка графа на пустоту
        if not self.add_list:
            return iter([])
        # Берём первую вершину
        first_vertex = next(iter(self.add_list))
        # Возвращаем итератор по dfs от этой вершины
        return iter(self.dfs(first_vertex))
