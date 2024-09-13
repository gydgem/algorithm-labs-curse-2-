//
// Created by gydgem on 9/11/2024.
//

#ifndef GRAPSLAB1_VERTEX_H
#define GRAPSLAB1_VERTEX_H


#include <utility>
#include <vector>
#include <exception>
#include <stdexcept>
#include <map>

namespace hgem {

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Edge;

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Vertex {
    public:
        using TypeEdge = Edge<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;

    private:
        TypeNameVertex nameVertex;
        TypeWeightVertex weightVertex;
        std::map<TypeNameEdge, TypeEdge> outgoingEdges; // you might want to replace it with a template

    public:
        explicit Vertex(TypeNameVertex nameVertex, TypeWeightVertex weightVertex) :
                nameVertex(std::move(nameVertex)),
                weightVertex(std::move(weightVertex)) {
        }

        const TypeNameVertex &getNameVertex() {
            return nameVertex;
        }

        const TypeWeightVertex &getWeightVertex() {
            return weightVertex;
        }

        void addEdge(TypeEdge edge) {
            if (&edge.getSourceVertex() != this) {
                throw std::invalid_argument("The edge does not belong to the current vertex.");
            }

            if (outgoingEdges.find(edge.getNameEdge()) != outgoingEdges.end()) {
                throw std::invalid_argument("The edge already exists ");
            }

            outgoingEdges.emplace(edge.getNameEdge(), std::move(edge));
        }

        std::vector<TypeEdge> getAllEdges() {
            std::vector<TypeEdge> result;

            for (auto value: outgoingEdges)
                result.emplace_back(value.second);

            return result;
        }

        TypeEdge getEdge(const TypeNameEdge& nameEdge){
            if (outgoingEdges.find(nameEdge) == outgoingEdges.end()) {
                throw std::invalid_argument("edge not found");
            }

            return outgoingEdges.find(nameEdge)->second;
        }
    };

} // hgem

#endif //GRAPSLAB1_VERTEX_H
