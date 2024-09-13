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


namespace hgem {

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Edge;

    template<class TypeNameVertex, class TypeWeightVertex, class TypeNameEdge, class TypeWeightEdge>
    class Vertex {
    public:
        using TypeEdge = Edge<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;
        using TypeVertex = Vertex<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>;

        class iterator; //allows you to iterate along the edges of the graph

    private:
        TypeNameVertex nameVertex;
        TypeWeightVertex weightVertex;
        std::map<TypeNameEdge, TypeEdge> outgoingEdges; // you might want to replace it with a template

    public:
        explicit Vertex(TypeNameVertex nameVertex, TypeWeightVertex weightVertex) :
                nameVertex(std::move(nameVertex)),
                weightVertex(std::move(weightVertex)) {
        }

        Vertex &operator=(const Vertex &) = delete;

        Vertex &operator=(Vertex&&) = delete;

        const TypeNameVertex &getNameVertex() const{
            return nameVertex;
        }

        const TypeWeightVertex &getWeightVertex() const{
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

        TypeEdge getEdge(const TypeNameEdge &nameEdge) {
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
    class Vertex<TypeNameVertex, TypeWeightVertex, TypeNameEdge, TypeWeightEdge>::iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = TypeEdge;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

        friend Vertex;

    private:
        std::map<TypeNameEdge, TypeEdge>::iterator pointerToEdge;

        explicit iterator(std::map<TypeNameEdge, TypeEdge>::iterator pointerToEdge) : pointerToEdge(pointerToEdge){
        }

    public:
        iterator()= default;

        ~iterator() = default;

        reference operator*() const {
            return pointerToEdge->second;
        }

        pointer operator->() {
            return &pointerToEdge->second;
        }

        iterator& operator++() {
            pointerToEdge++;
            return *this;
        }

        iterator operator++(int) {
            iterator temporary = *this;
            pointerToEdge++;
            return temporary;
        }

        iterator& operator--() {
            pointerToEdge--;
            return *this;
        }

        iterator operator--(int) {
            iterator temporary = *this;
            pointerToEdge--;
            return temporary;
        }

        bool operator==(const iterator& other) {
            return pointerToEdge == other.pointerToEdge;
        }

        bool operator!=(const iterator& other) {
            return pointerToEdge != other.pointerToEdge;
        }
    };

} // hgem

#endif //GRAPSLAB1_VERTEX_H
