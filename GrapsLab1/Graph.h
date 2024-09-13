//
// Created by gydgem on 9/12/2024.
//

#ifndef GRAPSLAB1_GRAPH_H
#define GRAPSLAB1_GRAPH_H


#include "GraphComponents/Edge.h"
#include "GraphComponents/Vertex.h"
#include <map>

namespace hgem {

    template <class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Graph {
    public:
        using TypeVertex = Vertex<TypeNameEdge, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;
        using TypeEdge = hgem::Edge<TypeNameEdge, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;

    private:
        std::map<TypeNameVertex, TypeVertex> vertices;
        std::map<TypeNameEdge, TypeEdge&> edges;

    public:
        void addVertex(const TypeNameVertex &nameVertex, const TypeWeightVertex &weightVertex) {
            if (vertices.find(nameVertex) != vertices.end()) {
                throw std::invalid_argument("The vertex already exists ");
            }

            vertices.emplace(nameVertex, TypeVertex(nameVertex, weightVertex));
        }

        void addEdge(const TypeNameVertex &nameSourceVertex,
                     const TypeNameVertex &nameTargetVertex,
                     const TypeNameEdge &nameEdge,
                     const TypeWeightVertex &weightEdge) {
            if (edges.find(nameEdge) != edges.end()) {
                throw std::invalid_argument("The edge already exists ");
            }

            if (vertices.find(nameSourceVertex) == vertices.end()) {
                throw std::invalid_argument("Source vertex not found");
            }

            if (vertices.find(nameTargetVertex) == vertices.end()) {
                throw std::invalid_argument("Target vertex not found");
            }

            TypeVertex &sourceVertex = vertices.find(nameSourceVertex)->second;
            TypeVertex &targetVertex = vertices.find(nameTargetVertex)->second;
            TypeEdge edgeToAdd(sourceVertex, targetVertex, nameEdge, weightEdge);
            

            sourceVertex.addEdge(edgeToAdd);
            edges.emplace(nameEdge, sourceVertex.getEdge(nameEdge));
        }

        TypeVertex GetVertex(const TypeNameVertex &nameVertex) {
            if (vertices.find(nameVertex)->second == vertices.end()) {
                throw std::invalid_argument("Vertex not found");
            }

            return vertices.find(nameVertex)->second;
        }

        TypeEdge GetEdge(const TypeNameEdge &nameEdge) {
            if (edges.find(nameEdge) == edges.end()) {
                throw std::invalid_argument("edge not found");
            }

            return edges.find(nameEdge)->second;
        }
    };

} // hgem

#endif //GRAPSLAB1_GRAPH_H
