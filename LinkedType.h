//
// Created by Lance Sander on 2/8/20.
//

#ifndef LAB2_LINKEDTYPE_H
#define LAB2_LINKEDTYPE_H
#include "LinkedTypeInterface.h"


template<class ItemType>
class LinkedType : public LinkedTypeInterface<ItemType>{
public:
    ItemType *items;
    LinkedType() {};

    LinkedType(ItemType * i, int itemCount) {
        items = i;
        std::cout << "LinkedType " << items << *items << std::endl;
        // std::cout << "Inside LinkedType " << sizeof(items)/sizeof(items[0]) << std::endl;
       // for (int j=0; j<sizeof(items); j++)  {
         //   std::cout << j << " - " << items[j] << " // " << *items << std::endl;
       // }
    }
    void testy() {
        std::cout << "testyLinkedType - " << items << *items << std::endl;
    }

    int length() const {
        return 0;
    }

    int index(ItemType &f) const {
        return 0;
    }

    void append(const LinkedTypeInterface<ItemType> &lt);

    bool submatch(const LinkedTypeInterface<ItemType> &lt) const;

    void append(const LinkedType &lt) {

    }

    bool submatch(const LinkedType &lt) const  {
        return false;
    }

    ~LinkedType();

};

template<class ItemType>
LinkedType<ItemType>::~LinkedType() {

}

template<class ItemType>
void LinkedType<ItemType>::append(const LinkedTypeInterface<ItemType> &lt) {

}

template<class ItemType>
bool LinkedType<ItemType>::submatch(const LinkedTypeInterface<ItemType> &lt) const {
    return false;
}


#endif //LAB2_LINKEDTYPE_H
