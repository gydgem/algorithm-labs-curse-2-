//
// Created by gydgem on 9/15/2024.
//

#ifndef GRAPSLAB1_BELLMANFORDSHORTESTPATH_H
#define GRAPSLAB1_BELLMANFORDSHORTESTPATH_H

#include <functional>
#include <unordered_map>
#include <queue>
#include <stdexcept>

namespace hgem {

    template<class TypeGraph,
            class Container = std::unordered_map<typename TypeGraph::TypeNameVertex, typename TypeGraph::TypeWeightEdge>,
            class Merger = std::plus<typename TypeGraph::TypeWeightEdge>,
            class Compare = std::less<typename TypeGraph::TypeWeightEdge>>
    std::vector<Container> bellmanFordShortestPathIgnoreVertexWeightAndGetAllSteps(TypeGraph &graph,
                                                                                   typename TypeGraph::TypeNameVertex nameStartVertex,
                                                                                   typename TypeGraph::TypeWeightEdge weightStart = typename TypeGraph::TypeWeightEdge()) {
        Merger merger;
        Compare compare;
        std::vector<Container> result; //task required by the lab :(
        Container distancesToVertices;

        distancesToVertices.emplace(nameStartVertex, weightStart);\
        result.emplace_back(distancesToVertices); //task required by the lab :(

        for (auto iteratorVertices = ++graph.beginVertices();
             iteratorVertices != graph.endVertices();
             iteratorVertices++) {
            bool allPathFoundFlag = true;

            for (auto iteratorEdges = graph.beginEdges(); iteratorEdges != graph.endEdges(); iteratorEdges++) {
                auto sourceVertex = iteratorEdges->getSourceVertex();
                auto targetVertex = iteratorEdges->getTargetVertex();
                auto weightEdge = iteratorEdges->getWeightEdge();

                if (distancesToVertices.find(sourceVertex.getNameVertex()) == distancesToVertices.end()) {
                    continue;
                }

                if (distancesToVertices.find(targetVertex.getNameVertex()) == distancesToVertices.end() ||
                    compare(merger(distancesToVertices[sourceVertex.getNameVertex()], weightEdge),
                            distancesToVertices[targetVertex.getNameVertex()])) {
                    allPathFoundFlag = false;
                    distancesToVertices.insert_or_assign(targetVertex.getNameVertex(),
                                                         merger(distancesToVertices[sourceVertex.getNameVertex()],
                                                                weightEdge));
                }
            }

            if (allPathFoundFlag)
                break;

            result.emplace_back(distancesToVertices); //task required by the lab :(
        }

        for (auto iteratorEdges = graph.beginEdges(); iteratorEdges != graph.endEdges(); iteratorEdges++) {
            auto sourceVertex = iteratorEdges->getSourceVertex();
            auto targetVertex = iteratorEdges->getTargetVertex();
            auto weightEdge = iteratorEdges->getWeightEdge();

            if (distancesToVertices.find(sourceVertex.getNameVertex()) != distancesToVertices.end() &&
                compare(merger(distancesToVertices[sourceVertex.getNameVertex()], weightEdge),
                        distancesToVertices[targetVertex.getNameVertex()])) {
                throw std::runtime_error("Graph contains a negative-weight cycle");
            }
        }

        return std::move(result);
    }

}// hgem

#endif //GRAPSLAB1_BELLMANFORDSHORTESTPATH_H
