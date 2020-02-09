//
// Created by Lance Sander on 2/8/20.
//

#ifndef LAB2_LINKEDTYPE_H
#define LAB2_LINKEDTYPE_H
#include "LinkedTypeInterface.h"


template<class ItemType>
class LinkedType : public LinkedTypeInterface<ItemType>{
public:
    LinkedType() {};


    int length() const {
        return 0;
    }

    int index(ItemType &f) const {
        return 0;
    }

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


#endif //LAB2_LINKEDTYPE_H
