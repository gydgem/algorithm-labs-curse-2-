//
// Created by gydgem on 9/17/2024.
//
#include "floydWarshallShortestPath.h"

namespace hgem {
    std::vector<std::vector<std::optional<int64_t>>>
    floydWarshallShortestPath(std::vector<std::vector<std::optional<int64_t>>> &graph) {
        int numberOfVertices = graph.size();
        std::vector<std::vector<std::optional<int64_t>>> dist = graph;

        for (int k = 0; k < numberOfVertices; ++k) {
            for (int i = 0; i < numberOfVertices; ++i) {
                for (int j = 0; j < numberOfVertices; ++j) {
                    if (dist[i][k] && dist[k][j]) {
                        int64_t newDist = *dist[i][k] + *dist[k][j];
                        if (!dist[i][j] || newDist < *dist[i][j]) {
                            dist[i][j] = newDist;
                        }
                    }
                }
            }
        }

        return dist;
    }

} //hgem
