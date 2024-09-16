//
// Created by gydgem on 9/17/2024.
//

#include "Task3Handler.h"

namespace hgem {
    Task3Handler::Task3Handler() {
        graph = {{0,            2,            3,            6},
                 {5,            0,            std::nullopt, 2},
                 {4,            std::nullopt, 0,            4},
                 {std::nullopt, 5,            4,            0}};

    }

    void Task3Handler::task3() {
        auto res = floydWarshallShortestPath(graph);

        std::cout << "Task3\n******************************************************************************\n";

        for (const auto &row: res) {
            for (const auto &cell: row) {
                if (cell) {
                    std::cout << std::format("{:^5}", *cell); // Вывод значения на 5 символов
                } else {
                    std::cout << std::format("{:^5}", "INF"); // Вывод "INF" на 5 символов
                }
            }

            std::cout << std::endl;
        }
    }
}// hgem