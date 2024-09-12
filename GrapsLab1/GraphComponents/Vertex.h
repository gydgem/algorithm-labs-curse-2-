//
// Created by gydgem on 9/11/2024.
//

#ifndef GRAPSLAB1_VERTEX_H
#define GRAPSLAB1_VERTEX_H


#include <utility>
#include <vector>
#include <exception>
#include <stdexcept>


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
        std::vector<TypeEdge> outgoingEdges;
        std::vector<TypeEdge> incomingEdges;

    public:
        explicit Vertex(TypeNameVertex nameVertex, TypeWeightVertex weightVertex) :
        nameVertex(std::move(nameVertex)), weightVertex(std::move(weightVertex)){
        }

        const TypeNameVertex &getNameVertex(){
            return nameVertex;
        }

        const TypeWeightVertex &getWeightVertex(){
            return nameVertex;
        }

        void addEdge(TypeEdge edge){
            if (&edge.getCurrentVertex() != this){
                throw std::invalid_argument("The edge does not belong to the current vertex.");
            }

            outgoingEdges.push_back(edge);
            edge.getNextVertex().incomingEdges.push_back(TypeEdge(edge.getNextVertex(),
                                                                  edge.getCurrentVertex(),
                                                                  edge.getNameEdge(),
                                                                  edge.getWeightEdge()));
        }

        std::vector<TypeEdge> getAllEdge(){
            return outgoingEdges;
        }
    };

} // hgem

#endif //GRAPSLAB1_VERTEX_H
