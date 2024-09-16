//
// Created by gydgem on 9/17/2024.
//

#ifndef GRAPHLAB1_TASK3HANDLER_H
#define GRAPHLAB1_TASK3HANDLER_H

#include <vector>
#include <cstdint>
#include <optional>
#include <format>
#include <iostream>
#include "../GraphAlgorithm/floydWarshallShortestPath.h"

namespace hgem {

    class Task3Handler {
        std::vector<std::vector<std::optional<int64_t>>> graph;
    public:
        Task3Handler();

        void task3();
    };

} // hgem

#endif //GRAPHLAB1_TASK3HANDLER_H
