//
// Created by gydgem on 9/12/2024.
//

#ifndef GRAPSLAB1_GRAPH_H
#define GRAPSLAB1_GRAPH_H

#include <bits/stdc++.h>

#include "../GraphComponents/Edge.h"
#include "../GraphComponents/Vertex.h"
#include "../Сommon/CommonIterators/MapSecondElementIterator.h"
#include <map>

namespace hgem {

    template<class VertexNameT, class VertexWeightT, class EdgeNameT, class EdgeWeightT>
    class Graph {
    public:
        using TypeNameVertex = VertexNameT;
        using TypeWeightVertex = VertexWeightT;
        using TypeNameEdge = EdgeNameT;
        using TypeWeightEdge = EdgeWeightT;
        using TypeVertex = Vertex<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;
        using TypeEdge = Edge<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;

        class IteratorVertices;

        class IteratorEdges;

    private:
        std::map<TypeNameVertex, TypeVertex> vertices;
        std::map<TypeNameEdge, TypeEdge> edges; // возможно стоит создать класс который позволит у разных вершин иметь рёбра одинакового названия

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


            edges.emplace(nameEdge, edgeToAdd);
            sourceVertex.bindOutgoingEdge(edges.find(nameEdge)->second);
        }

        TypeVertex &getVertex(const TypeNameVertex &nameVertex){
            if (vertices.find(nameVertex) == vertices.end()) {
                throw std::invalid_argument("Vertex not found");
            }

            return vertices.find(nameVertex)->second;
        }

        TypeEdge &getEdge(const TypeNameEdge &nameEdge){
            if (edges.find(nameEdge) == edges.end()) {
                throw std::invalid_argument("edge not found");
            }

            return edges.find(nameEdge)->second;
        }

        IteratorVertices beginVertices() {
            return IteratorVertices(vertices.begin());
        }

        IteratorVertices endVertices() {
            return IteratorVertices(vertices.end());
        }

        IteratorVertices beginVertices() const{
            return IteratorVertices(vertices.begin());
        }

        IteratorVertices endVertices() const{
            return IteratorVertices(vertices.end());
        }

        IteratorEdges beginEdges() {
            return IteratorEdges(edges.begin());
        }

        IteratorEdges endEdges() {
            return IteratorEdges(edges.end());
        }

        IteratorEdges beginEdges() const{
            return IteratorEdges(edges.begin());
        }

        IteratorEdges endEdges() const{
            return IteratorEdges(edges.end());
        }
    };

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Graph<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>::IteratorVertices
            : public MapSecondElementIterator<TypeNameVertex, TypeVertex> {
    public:
        friend Graph;

    private:
        explicit IteratorVertices(std::map<TypeNameVertex, TypeVertex>::iterator it)
                : MapSecondElementIterator<TypeNameVertex, TypeVertex>(it) {
        }
    };

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Graph<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>::IteratorEdges
            : public MapSecondElementIterator<TypeNameEdge, TypeEdge> {
    public:
        friend Graph;

    private:
        explicit IteratorEdges(std::map<TypeNameEdge, TypeEdge> it)
                : MapSecondElementIterator<TypeNameEdge, TypeEdge>(it) {
        }
    };

} // hgem

#endif //GRAPSLAB1_GRAPH_H
