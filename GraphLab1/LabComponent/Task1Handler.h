//
// Created by gydgem on 9/16/2024.
//

#ifndef GRAPHLAB1_TASK1HANDLER_H
#define GRAPHLAB1_TASK1HANDLER_H

#include "../GraphTypes/Graph.h"
#include "../GraphAlgorithm/dijkstrasShortestPath.h"

namespace hgem {

    class Task1Handler {
        using GraphType = Graph<std::string, int64_t, std::string, int64_t>;

        GraphType graph;

    public:
        Task1Handler();

        void task1();
    };

} // hgem

#endif //GRAPHLAB1_TASK1HANDLER_H
