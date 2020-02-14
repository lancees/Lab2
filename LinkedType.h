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
    LinkedType<ItemType> * someLink;

    LinkedType() {};

    LinkedType(ItemType * i, int icount) {
        itemCount = icount;
        items = new ItemType[itemCount]; // wanted to better learn arrays
        head = new Node<ItemType>(i[0]);
        for (int j=0; j<itemCount; j++)  {
            items[j] = i[j];
        }
        Node<ItemType> * thisNode;
        Node<ItemType> * lastNode = nullptr;
        for (int k = itemCount - 1; k>0; k--) {
            thisNode = new Node<ItemType>(i[k], nullptr);
            thisNode->setNext(lastNode);
            lastNode = thisNode;
        }
        head->setNext(lastNode);
    }
    void print() const {
        Node<ItemType> * thisNode = head;
        while (thisNode != nullptr)  {
            std::cout << thisNode->getItem();
            thisNode = thisNode->getNext();
        }
        std::cout << std::endl;
    }

    int length() const {
        return itemCount;
    }

    int index(ItemType& f) const {
        Node<ItemType> * thisNode = head;
        int i = -1;
        int index = i;
        while(thisNode != nullptr) {
            if (thisNode->getItem() == f){
                index = i;
            }
            thisNode = thisNode->getNext();
            i++;
        }
        return index;
    }

    void otherLink(ItemType * i, int icount);


    void append(const LinkedTypeInterface<ItemType> &lt);

    bool submatch(const LinkedTypeInterface<ItemType> &lt) const;

    ~LinkedType();

};

template<class ItemType>
LinkedType<ItemType>::~LinkedType() {

}

template<class ItemType>
void LinkedType<ItemType>::append(const LinkedTypeInterface<ItemType> &lt)  {
    Node<ItemType> * thisNode = head;
    while (thisNode != nullptr) {
        thisNode = thisNode->getNext();
    }
    Node<ItemType> * newNode;
    Node<ItemType> * ltHead = lt.head;
    if (lt.head == nullptr) {
        std::cout << "nullptr";
    }
//    std::cout << ltHead->getItem();
//    ltHead->getNext();
    lt.print();
    std::cout << "---";
    while (ltHead != nullptr) {
        newNode = new Node<ItemType>(ltHead->getItem(), ltHead->getNext());
        std::cout << newNode->getItem() << " // " << std::endl;
        thisNode->setNext(newNode);
        ltHead = ltHead->getNext();
    }
}

template<class ItemType>
bool LinkedType<ItemType>::submatch(const LinkedTypeInterface<ItemType> &lt) const {
    return false;
}

template<class ItemType>
void LinkedType<ItemType>::otherLink(ItemType * i, int icount) {
    someLink = new LinkedType<ItemType>(i, icount);
    someLink->print();
}

#endif //LAB2_LINKEDTYPE_H
