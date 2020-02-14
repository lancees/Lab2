//
// Created by Lance Sander on 2/8/20.
//

#ifndef LAB2_LINKEDTYPEINTERFACE_H
#define LAB2_LINKEDTYPEINTERFACE_H
#include "Node.h"
#include <cstddef>
template<class ItemType>
class LinkedTypeInterface {
public:
    Node<ItemType> * head;
    // virtual LinkedTypeInterface() = 0;

    // virtual LinkedTypeInterface(const ItemType& t) = 0;

    virtual int length() const = 0;

    virtual int index(ItemType& f) const = 0;

    virtual void append(const LinkedTypeInterface& lt) = 0;

    virtual bool submatch(const LinkedTypeInterface& lt) const = 0;
    virtual void otherLink(ItemType * i, int icount) = 0;
    virtual void print() const = 0;

    virtual ~LinkedTypeInterface()=0;

};

template<class ItemType>
LinkedTypeInterface<ItemType>::~LinkedTypeInterface() = default;


#endif //LAB2_LINKEDTYPEINTERFACE_H
