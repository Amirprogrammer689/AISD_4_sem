#include <iostream>
#include "../include/Graph.h"
#include "../include/Task.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    // �������� ����� � �������������� ���������
    Graph<int, int> graph;
    graph.add_vertex(1);
    graph.add_vertex(2);
    graph.add_vertex(3);
    graph.add_vertex(4);
    graph.add_vertex(5);

    // ���������� ���� ����� ���������
    graph.add_edge(2, 5, 2);
    graph.add_edge(1, 5, 8);
    graph.add_edge(1, 3, 1);
    graph.add_edge(3, 5, 10);
    graph.add_edge(3, 4, 3);
    graph.add_edge(3, 2, 1);
    graph.add_edge(2, 3, 7);
    graph.add_edge(4, 5, 9);
    graph.add_edge(5, 1, 5);

    std::cout << "����:\n";
    graph.print_edges();

    // ����� ������� ������� � ������� �����
    std::cout << "������� ������� 4: " << graph.degree(4) << std::endl;
    std::cout << "������� �����: " << graph.order() << std::endl;

    // ����� ������ ������
    std::cout << "�������: ";
    for (const auto& v : graph.vertices()) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // ����� �����
    std::cout << "����� �����: ";
    std::vector<int> visited;
    graph.walk(1, [&visited](const int vertex) { visited.push_back(vertex); });
    for (int v : visited)
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << std::endl;

    // ����� ����������� ����
    auto path = graph.shortest_path(1, 5);
    std::cout << "���������� ���� �� 1 �� 5: ";
    for (const auto& edge : path) {
        std::cout << edge.from << " -> " << edge.to << " (" << edge.distance << ") ";
    }

    std::cout << std::endl;

    // ����� �����������
    std::cout << "����������: " << graph.find_an_emergency_room() << std::endl;

    // �������� ������� ����� � ������� � �����
    std::cout << "����� 3->2 ������������ � �����: " << graph.has_edge(3, 2) << std::endl;
    std::cout << "������� 1 ������������ � �����: " << graph.has_vertex(1) << std::endl;

    // �������� ����� � ������ �� �����
    graph.remove_edge(3, 2);
    graph.remove_vertex(1);
    graph.remove_vertex(2);

    graph.print_edges();

    // ��������� �������� ������� ����� � ������� � �����
    std::cout << "����� 3->2 ������������ � �����: " << graph.has_edge(3, 2) << std::endl;
    std::cout << "������� 1 ������������ � �����: " << graph.has_vertex(1) << std::endl;

    return 0;
}
