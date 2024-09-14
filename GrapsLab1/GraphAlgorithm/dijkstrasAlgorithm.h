//
// Created by gydgem on 9/14/2024.
//

#ifndef GRAPSLAB1_DIJKSTRASALGORITHM_H
#define GRAPSLAB1_DIJKSTRASALGORITHM_H

#include <functional>
#include <queue>

namespace hgem {

    template<class TypeGraph,
            class Merger = std::plus<typename TypeGraph::TypeWeightEdge>,
            class Comparator = std::less<typename TypeGraph::TypeWeightEdge>>
    void CalcDijkstraShortestPathsIgnoreVertexWeight() {
        Merger merger;
        Comparator comparator;
        auto comp = [&](const typename TypeGraph::TypeVertex &a, const typename TypeGraph::TypeVertex &b) -> bool {
            return comparator(a.getWeightEdge, b.getWeightEdge);
        };

        std::priority_queue<typename TypeGraph::TypeVertex,
                std::vector<typename TypeGraph::TypeVertex>,
                decltype(comp)> queue(comp);


    }

} // hgem

#endif //GRAPSLAB1_DIJKSTRASALGORITHM_H
