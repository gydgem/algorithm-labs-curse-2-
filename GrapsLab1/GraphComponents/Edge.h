//
// Created by gydgem on 9/11/2024.
//

#ifndef GRAPSLAB1_EDGE_H
#define GRAPSLAB1_EDGE_H


#include <utility>


namespace hgem {

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Vertex;

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Edge {
    public:
        using TypeVertex = Vertex<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;

    private:
        TypeNameEdge nameEdge;
        TypeWeightEdge weightEdge;
        TypeVertex &sourceVertex;
        TypeVertex &targetVertex;

    public:

        Edge(TypeVertex &sourceVertex, TypeVertex &targetVertex, TypeNameEdge nameEdge, TypeWeightEdge weightEdge)
                : nameEdge(std::move(nameEdge)),
                  weightEdge(std::move(weightEdge)),
                  sourceVertex(sourceVertex),
                  targetVertex(targetVertex) {
        }

        TypeVertex &getSourceVertex() const {
            return sourceVertex;
        }

        TypeVertex &getTargetVertex() const {
            return targetVertex;
        }

        const TypeNameEdge &getNameEdge() const {
            return nameEdge;
        }

        const TypeWeightEdge &getWeightEdge() const {
            return weightEdge;
        }
    };
} // namespace hgem

#endif // GRAPSLAB1_EDGE_H
