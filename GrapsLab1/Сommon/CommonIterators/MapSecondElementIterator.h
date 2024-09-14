//
// Created by gydgem on 9/14/2024.
//

#ifndef GRAPSLAB1_MAPSECONDELEMENTITERATOR_H
#define GRAPSLAB1_MAPSECONDELEMENTITERATOR_H

#include <iterator>
#include <map>

namespace hgem {

    template<class TypeKey, class TypeValue>
    class MapSecondElementIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = TypeValue;
        using difference_type = std::ptrdiff_t;
        using pointer = value_type*;
        using reference = value_type&;

    protected:
        std::map<TypeKey, TypeValue>::iterator pointerToEdge;

        explicit MapSecondElementIterator(std::map<TypeKey, TypeValue>::iterator pointerToEdge) : pointerToEdge(pointerToEdge){
        }

    public:
        MapSecondElementIterator()= default;

        ~MapSecondElementIterator() = default;

        reference operator*() const {
            return pointerToEdge->second;
        }

        pointer operator->() {
            return &pointerToEdge->second;
        }

        MapSecondElementIterator& operator++() {
            pointerToEdge++;
            return *this;
        }

        MapSecondElementIterator operator++(int) {
            MapSecondElementIterator temporary = *this;
            pointerToEdge++;
            return temporary;
        }

        MapSecondElementIterator& operator--() {
            pointerToEdge--;
            return *this;
        }

        MapSecondElementIterator operator--(int) {
            MapSecondElementIterator temporary = *this;
            pointerToEdge--;
            return temporary;
        }

        bool operator==(const MapSecondElementIterator& other) {
            return pointerToEdge == other.pointerToEdge;
        }

        bool operator!=(const MapSecondElementIterator& other) {
            return pointerToEdge != other.pointerToEdge;
        }
    };

} // hgem

#endif //GRAPSLAB1_MAPSECONDELEMENTITERATOR_H
