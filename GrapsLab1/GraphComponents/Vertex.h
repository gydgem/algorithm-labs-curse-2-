//
// Created by gydgem on 9/11/2024.
//

#ifndef GRAPSLAB1_VERTEX_H
#define GRAPSLAB1_VERTEX_H


#include <iterator>
#include <utility>
#include <vector>
#include <exception>
#include <stdexcept>
#include <map>
#include "../Сommon/CommonIterators/MapSecondElementIterator.h"

namespace hgem {

    template<class VertexNameT, class VertexWeightT, class EdgeNameT, class EdgeWeightT>
    class Edge;

    template<class VertexNameT, class VertexWeightT, class EdgeNameT, class EdgeWeightT>
    class Vertex {
    public:
        using TypeNameVertex = VertexNameT;
        using TypeWeightVertex = VertexWeightT;
        using TypeNameEdge = EdgeNameT;
        using TypeWeightEdge = EdgeWeightT;
        using TypeEdge = Edge<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;
        using TypeVertex = Vertex<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;

        class iterator;

    private:
        TypeNameVertex nameVertex;
        TypeWeightVertex weightVertex;
        std::map<TypeNameEdge, TypeEdge&> outgoingEdges; // you might want to replace it with a template

    public:
        explicit Vertex(TypeNameVertex nameVertex, TypeWeightVertex weightVertex) :
                nameVertex(std::move(nameVertex)),
                weightVertex(std::move(weightVertex)) {
        }

        const TypeNameVertex &getNameVertex() const{
            return nameVertex;
        }

        const TypeWeightVertex &getWeightVertex() const{
            return weightVertex;
        }

        void bindOutgoingEdge(TypeEdge &edge) {
            if (&edge.getSourceVertex() != this) {
                throw std::invalid_argument("The edge does not belong to the current vertex.");
            }

            if (outgoingEdges.find(edge.getNameEdge()) != outgoingEdges.end()) {
                throw std::invalid_argument("The edge already exists ");
            }

            outgoingEdges.emplace(edge.getNameEdge(), edge);
        }

        std::vector<TypeEdge> getAllOutgoingEdges() {
            std::vector<TypeEdge> result;

            for (auto value: outgoingEdges)
                result.emplace_back(value.second);

            return result;
        }

        TypeEdge &getOutgoingEdge(const TypeNameEdge &nameEdge) {
            if (outgoingEdges.find(nameEdge) == outgoingEdges.end()) {
                throw std::invalid_argument("edge not found");
            }

            return outgoingEdges.find(nameEdge)->second;
        }

        iterator begin() {
            return iterator(outgoingEdges.begin());
        }

        iterator end() {
            return iterator(outgoingEdges.end());
        }
    };

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Vertex<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>::iterator : public MapSecondElementIterator<TypeNameEdge, TypeEdge&> {
    public:
        friend Vertex;

    private:
        explicit iterator(std::map<TypeNameEdge, TypeEdge&>::iterator it) : MapSecondElementIterator<TypeNameEdge, TypeEdge&> (it){
        }
    };

} // hgem

#endif //GRAPSLAB1_VERTEX_H
