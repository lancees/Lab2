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
    LinkedType(ItemType * i, int icount) ;

    int length() const;
    int index(ItemType& f) const ;
    void apppendItem(const LinkedType<ItemType> &lt);
    bool submatchType(const LinkedType<ItemType> &lt) const;

    void append(const LinkedTypeInterface<ItemType> &lt); // I don't know how to use these unless i have getters/setters and move attributes to interface
    bool submatch(const LinkedTypeInterface<ItemType> &lt) const;
    void loadNodesFromItems() ;
    void print() const ;
    void otherLink(ItemType * i, int icount);

    ~LinkedType();
};

template<class ItemType>
LinkedType<ItemType>::LinkedType(ItemType * i, int icount) { // array is only used to create nodes
    itemCount = icount;
    items = new ItemType[itemCount]; // wanted to practice arrays, allows construction with an array
    for (int j=0; j<itemCount; j++)  {
        items[j] = i[j];
    }
    loadNodesFromItems();
}

template<class ItemType>
int LinkedType<ItemType>::length() const {
    return itemCount;
}


template<class ItemType>
int LinkedType<ItemType>::index(ItemType& f) const {
    Node<ItemType> * thisNode = head;
    int i = -1;
    int index = i;
    while(thisNode != nullptr) {
        i++;
        if (thisNode->getItem() == f){
            index = i;
            return index+1; // +1 for human readable position
        }
        thisNode = thisNode->getNext();
    }
    return index; // did not find
}


template<class ItemType>
void LinkedType<ItemType>::append(const LinkedTypeInterface<ItemType> &lt)  {
    // How do i pass LinkedTypeInterface when all my attributes are at the LinkedType level? getters and setters?!?
}

template<class ItemType>
void LinkedType<ItemType>::apppendItem(const LinkedType<ItemType> &lt)  { // does not apppend items
    Node<ItemType> * thisNode = head;
    while (thisNode->getNext() != nullptr) {
        thisNode = thisNode->getNext();
    }
    Node<ItemType> * newNode;
    Node<ItemType> * ltHead = lt.head;
    while (ltHead != nullptr) {
        itemCount++;
        newNode = new Node<ItemType>(ltHead->getItem(), ltHead->getNext());
        thisNode->setNext(newNode);
        thisNode = thisNode->getNext();
        ltHead = ltHead->getNext();
    }
}

template<class ItemType>
bool LinkedType<ItemType>::submatch(const LinkedTypeInterface<ItemType> &lt) const { // had to implement
    return false;
}

template<class ItemType>
bool LinkedType<ItemType>::submatchType(const LinkedType<ItemType> &lt) const {
    if (lt.itemCount >0) {
        Node<ItemType> *hayNode = head;
        while (hayNode != nullptr) {
            Node<ItemType> *strandNode = new Node<ItemType>(hayNode->getItem(),
                                                            hayNode->getNext()); // is this a memory leak?
            Node<ItemType> *nedNode = lt.head;
            while (nedNode != nullptr && strandNode != nullptr && strandNode->getItem() == nedNode->getItem()) {
                nedNode = nedNode->getNext();
                strandNode = strandNode->getNext();
            }
            if (nedNode == nullptr) {
                return true;
            }
            hayNode = hayNode->getNext();
        }
    }
    return false;
}
template<class ItemType>
void LinkedType<ItemType>::loadNodesFromItems() { // resets entire link to items. i think this is a memory link?
    if (itemCount >0 ) {
        head = new Node<ItemType>(items[0]);
        Node<ItemType> * thisNode;
        Node<ItemType> * lastNode = nullptr;
        for (int k = itemCount - 1; k>0; k--) {
            thisNode = new Node<ItemType>(items[k], nullptr);
            thisNode->setNext(lastNode);
            lastNode = thisNode;
        }
        head->setNext(lastNode);
    }
}
template<class ItemType>
void LinkedType<ItemType>::print() const {
    Node<ItemType> * thisNode = head;
    while (thisNode != nullptr)  {
        std::cout << thisNode->getItem();
        thisNode = thisNode->getNext();
    }
    std::cout << std::endl;
}

template<class ItemType>
void LinkedType<ItemType>::otherLink(ItemType * i, int icount) {
    someLink = new LinkedType<ItemType>(i, icount);
}



template<class ItemType>
LinkedType<ItemType>::~LinkedType() {
    delete items;
};
#endif //LAB2_LINKEDTYPE_H
