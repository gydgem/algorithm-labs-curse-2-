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
        using pointer = std::add_pointer_t<std::remove_reference_t<value_type>>;
        using reference = value_type&;

    protected:
        std::map<TypeKey, TypeValue>::iterator pointerToMapSecondElement;

        explicit MapSecondElementIterator(std::map<TypeKey, TypeValue>::iterator pointerToEdge) : pointerToMapSecondElement(pointerToEdge){
        }

    public:
        MapSecondElementIterator()= default;

        ~MapSecondElementIterator() = default;

        reference operator*() const {
            return pointerToMapSecondElement->second;
        }

        pointer operator->() {
            return &pointerToMapSecondElement->second;
        }

        MapSecondElementIterator& operator++() {
            pointerToMapSecondElement++;
            return *this;
        }

        MapSecondElementIterator operator++(int) {
            MapSecondElementIterator temporary = *this;
            pointerToMapSecondElement++;
            return temporary;
        }

        MapSecondElementIterator& operator--() {
            pointerToMapSecondElement--;
            return *this;
        }

        MapSecondElementIterator operator--(int) {
            MapSecondElementIterator temporary = *this;
            pointerToMapSecondElement--;
            return temporary;
        }

        bool operator==(const MapSecondElementIterator& other) {
            return pointerToMapSecondElement == other.pointerToMapSecondElement;
        }

        bool operator!=(const MapSecondElementIterator& other) {
            return pointerToMapSecondElement != other.pointerToMapSecondElement;
        }
    };

} // hgem

#endif //GRAPSLAB1_MAPSECONDELEMENTITERATOR_H
