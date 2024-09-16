//
// Created by gydgem on 9/16/2024.
//

#ifndef GRAPHLAB1_TASK2HANDLER_H
#define GRAPHLAB1_TASK2HANDLER_H

#include <format>
#include <iostream>
#include "../GraphTypes/Graph.h"
#include "../GraphAlgorithm/bellmanFordShortestPath.h"

namespace hgem {

    class Task2Handler {
        using GraphType = Graph<std::string, int64_t, std::string, int64_t>;

        GraphType graph;

    public:
        Task2Handler();

        void task2();
    };

} // hgem

#endif //GRAPHLAB1_TASK2HANDLER_H
