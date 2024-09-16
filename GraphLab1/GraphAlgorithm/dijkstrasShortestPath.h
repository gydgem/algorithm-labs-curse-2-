//
// Created by gydgem on 9/14/2024.
//

#ifndef GRAPSLAB1_DIJKSTRASALGORITHM_H
#define GRAPSLAB1_DIJKSTRASALGORITHM_H

#include <functional>
#include <unordered_map>
#include <queue>

namespace hgem {

    template<class TypeGraph,
            class Container = std::unordered_map<typename TypeGraph::TypeNameVertex, typename TypeGraph::TypeWeightEdge>,
            class Merger = std::plus<typename TypeGraph::TypeWeightEdge>,
            class Compare = std::less<typename TypeGraph::TypeWeightEdge>>
    Container dijkstraShortestPathsIgnoreVertexWeight(TypeGraph &graph,
                                                      typename TypeGraph::TypeNameVertex nameStartVertex,
                                                      typename TypeGraph::TypeWeightEdge weightStart = typename TypeGraph::TypeWeightEdge()) {
        Merger merger;
        Compare compare;

        auto compareQueue =
                [&](const std::pair<typename TypeGraph::TypeWeightEdge, typename TypeGraph::TypeVertex> &valueFirst,
                    const std::pair<typename TypeGraph::TypeWeightEdge, typename TypeGraph::TypeVertex> &ValueSecond) -> bool {
                    return compare(valueFirst.first, ValueSecond.first);
                };

        Container distancesToVertices;
        std::priority_queue<std::pair<typename TypeGraph::TypeWeightEdge, typename TypeGraph::TypeVertex>,
                std::vector<std::pair<typename TypeGraph::TypeWeightEdge, typename TypeGraph::TypeVertex>>, 
                decltype(compareQueue)> queue(compareQueue);
        queue.emplace(weightStart, graph.getVertex(nameStartVertex));
        distancesToVertices.emplace(nameStartVertex, weightStart);

        while (!queue.empty()) {
            auto WeightPathAndVertex = queue.top();
            auto WeightPath = WeightPathAndVertex.first;
            auto vertex = WeightPathAndVertex.second;
            queue.pop();

            if (distancesToVertices.find(vertex.getNameVertex()) != distancesToVertices.end() &&
                compare(WeightPath, distancesToVertices.find(vertex.getNameVertex())->second)) {
                continue;
            }

            for (auto edge: vertex) {
                auto SumWeightPath = merger(edge.getWeightEdge(), WeightPath);

                if (distancesToVertices.find(edge.getTargetVertex().getNameVertex()) == distancesToVertices.end()
                    || compare(SumWeightPath, distancesToVertices.find(edge.getTargetVertex().getNameVertex())->second)) {
                    distancesToVertices.insert_or_assign(edge.getTargetVertex().getNameVertex(), SumWeightPath);
                    queue.emplace(SumWeightPath, edge.getTargetVertex());
                    continue;
                }
            }
        }

        return std::move(distancesToVertices);
    }

} // hgem

#endif //GRAPSLAB1_DIJKSTRASALGORITHM_H
