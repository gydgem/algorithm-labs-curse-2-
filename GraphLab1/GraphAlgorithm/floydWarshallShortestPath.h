//
// Created by gydgem on 9/17/2024.
//

#ifndef GRAPHLAB1_FLOYDWARSHALLSHORTESTPATH_H
#define GRAPHLAB1_FLOYDWARSHALLSHORTESTPATH_H

#include <vector>
#include <optional>
#include <cstdint>

namespace hgem {

    std::vector<std::vector<std::optional<int64_t>>> floydWarshallShortestPath(std::vector<std::vector<std::optional<int64_t>>>& graph);

} // hgem

#endif //GRAPHLAB1_FLOYDWARSHALLSHORTESTPATH_H
