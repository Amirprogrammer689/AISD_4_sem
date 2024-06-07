#include <iostream>
#include "../include/Graph.h"
#include "../include/Task.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    // Создание графа с целочисленными вершинами
    Graph<int, int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);

    // Добавление рёбер между вершинами
    graph.add_edge(2, 5, 2);
    graph.add_edge(1, 5, 8);
    graph.add_edge(1, 3, 1);
    graph.add_edge(3, 5, 10);
    graph.add_edge(3, 4, 3);
    graph.add_edge(3, 2, 1);
    graph.add_edge(2, 3, 7);
    graph.add_edge(4, 5, 9);
    graph.add_edge(5, 1, 5);

    std::cout << "Граф:\n";
    graph.print_edges();

    // Вывод степени вершины и порядка графа
    std::cout << "Степень вершины 4: " << graph.degree(4) << std::endl;
    std::cout << "Порядок графа: " << graph.order() << std::endl;

    // Вывод списка вершин
    std::cout << "Вершины: ";
    for (const auto& v : graph.vertices()) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Обход графа
    std::cout << "Обход графа: ";
    std::vector<int> visited;
    graph.walk(1, [&visited](const int vertex) { visited.push_back(vertex); });
    for (int v : visited)
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << std::endl;

    // Поиск кратчайшего пути
    auto path = graph.shortest_path(1, 5);
    std::cout << "Кратчайший путь от 1 до 5: ";
    for (const auto& edge : path) {
        std::cout << edge.from << " -> " << edge.to << " (" << edge.distance << ") ";
    }

    std::cout << std::endl;

    // Поиск травмпункта
    std::cout << "Травмпункт: " << graph.find_an_emergency_room() << std::endl;

    // Проверка наличия ребра и вершины в графе
    std::cout << "Ребро 3->2 присутствует в графе: " << graph.has_edge(3, 2) << std::endl;
    std::cout << "Вершина 1 присутствует в графе: " << graph.has_vertex(1) << std::endl;

    // Удаление ребра и вершин из графа
    graph.remove_edge(3, 2);
    graph.remove_vertex(1);
    graph.remove_vertex(2);

    graph.print_edges();

    // Повторная проверка наличия ребра и вершины в графе
    std::cout << "Ребро 3->2 присутствует в графе: " << graph.has_edge(3, 2) << std::endl;
    std::cout << "Вершина 1 присутствует в графе: " << graph.has_vertex(1) << std::endl;

    return 0;
}
