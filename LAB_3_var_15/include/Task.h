#ifndef TASK_INCLUDE_TASK_H
#define TASK_INCLUDE_TASK_H

#include "Graph.h"

template<typename Vertex, typename Distance>
Vertex Graph<Vertex, Distance>::find_an_emergency_room() {
    Vertex farthest_node;
    double max_avg_distance = -1;

    for (const Vertex& v : _vertices) {
        double total_distance = 0;
        size_t neighbor_count = 0;

        for (const Edge& edge : _edges[v]) {
            total_distance += edge.distance;
            neighbor_count++;
        }

        if (neighbor_count > 0) {
            double avg_distance = total_distance / neighbor_count;

            if (avg_distance > max_avg_distance) {
                max_avg_distance = avg_distance;
                farthest_node = v;
            }
        }
    }

    return farthest_node;
}

#endif
