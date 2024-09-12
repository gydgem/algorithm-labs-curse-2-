//
// Created by gydgem on 9/11/2024.
//

#ifndef GRAPSLAB1_EDGE_H
#define GRAPSLAB1_EDGE_H

#include <utility>

namespace hgem {

    template <class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Vertex;

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Edge {
    public:
        using TypeVertex = Vertex<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;

    private:
        TypeNameEdge nameEdge;
        TypeWeightEdge weightEdge;
        TypeVertex &currentVertex;
        TypeVertex &nextVertex;

    public:
        explicit Edge(TypeVertex &currentVertex, TypeVertex &nextVertex)
                : currentVertex(currentVertex), nextVertex(nextVertex) {
        }

        explicit Edge(TypeVertex &currentVertex, TypeVertex &nextVertex, TypeNameEdge nameEdge, TypeWeightEdge weightEdge)
                : Edge(currentVertex, nextVertex), nameEdge(std::move(nameEdge)), weightEdge(std::move(weightEdge)) {
        }

        TypeVertex &getCurrentVertex() const {
            return currentVertex;
        }

        TypeVertex &getNextVertex() const {
            return nextVertex;
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
