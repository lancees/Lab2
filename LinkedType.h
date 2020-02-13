//
// Created by Lance Sander on 2/8/20.
//

#ifndef LAB2_LINKEDTYPE_H
#define LAB2_LINKEDTYPE_H
#include "LinkedTypeInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedType : public LinkedTypeInterface<ItemType>{
public:
    int itemCount = 0;
    ItemType * items; // array
    Node<ItemType> * head;
    Node<ItemType> * node;

    LinkedType() {};

    LinkedType(ItemType * i, int iCount) {
        itemCount = iCount;
        items = new ItemType[itemCount];
        head = new Node<ItemType>(i[0]);
        std::cout << "putting " << i[0] << " into head" << std::endl;
        for (int j=0; j<itemCount; j++)  {
            items[j] = i[j];
//            std::cout << j << i[j] << " - " << items[j] << " // " << std::endl;
        }
        Node<ItemType> * thisNode = new Node<ItemType>();
        Node<ItemType> * lastNode = new Node<ItemType>();
        for (int k = iCount - 1; k>=1; k--) {
            thisNode = new Node<ItemType>(i[k]);
            std::cout << k << " - ";
            if (k == iCount - 1) {
                std::cout << " setting to // " << i[k];
                thisNode->setNext(nullptr);
            } else {
                std::cout << " setting to // " << i[k];
                thisNode->setNext(lastNode);
            }
            std::cout << std::endl;
            lastNode = thisNode;
        }
        head->setNext(thisNode);
        std::cout << head->getItem() << " in construction" << std::endl;
    }
    void loopNodes() {
        Node<ItemType> * thisNode = head;
//        std::cout << head->getItem() << " // " << std::endl;
        thisNode = head;
//        std::cout << thisNode->getItem() << " // " << std::endl;
//        thisNode = thisNode->getNext();
//        std::cout << thisNode->getItem() << " // " << std::endl;
        while (thisNode != nullptr)  {
            std::cout << thisNode->getItem() << std::endl;
            thisNode = thisNode->getNext();
        }
//        std::cout << thisNode->getItem() << " // " << std::endl;
    }
    void testy() {
        std::cout << "testyLinkedType - " << std::endl;
        for (int i = 0; i < itemCount; i++) {
//            std::cout << *items++ << std::endl;
        }
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
