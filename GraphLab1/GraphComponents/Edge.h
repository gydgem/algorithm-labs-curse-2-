//
// Created by gydgem on 9/11/2024.
//

#ifndef GRAPSLAB1_EDGE_H
#define GRAPSLAB1_EDGE_H


#include <utility>


namespace hgem {

    template<class VertexNameT, class VertexWeightT, class EdgeNameT, class EdgeWeightT>
    class Vertex;

    template<class VertexNameT, class VertexWeightT, class EdgeNameT, class EdgeWeightT>
    class Edge {
    public:
        using TypeNameVertex = VertexNameT;
        using TypeWeightVertex = VertexWeightT;
        using TypeNameEdge = EdgeNameT;
        using TypeWeightEdge = EdgeWeightT;
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

        TypeVertex &getSourceVertex() {
            return sourceVertex;
        }

        TypeVertex &getTargetVertex() {
            return targetVertex;
        }

        const TypeNameEdge &getNameEdge() const{
            return nameEdge;
        }

        const TypeWeightEdge &getWeightEdge() const{
            return weightEdge;
        }
    };
} // namespace hgem

#endif // GRAPSLAB1_EDGE_H
