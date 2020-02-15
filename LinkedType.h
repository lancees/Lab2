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
    void append(const LinkedType<ItemType> &lt);
    bool submatch(const LinkedType<ItemType> &lt) const;

    void append(const LinkedTypeInterface<ItemType> &lt); // I don't know how to use these unless i have getters/setters and move attributes to interface
    bool submatch(const LinkedTypeInterface<ItemType> &lt) const;
    void loadNodesFromItems() ;
    void print() const ;
    void otherLink(ItemType * i, int icount);

    ~LinkedType();
};

template<class ItemType>
LinkedType<ItemType>::LinkedType(ItemType * i, int icount) { // create by array, array is only used to create nodes
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
            return index; // optional but terminates loop sooner
        }
        thisNode = thisNode->getNext();
    }
    return index;
}


template<class ItemType>
void LinkedType<ItemType>::append(const LinkedTypeInterface<ItemType> &lt)  {
    // How do i pass LinkedTypeInterface when all my attributes are at the LinkedType level? getters and setters?!?
}

template<class ItemType>
void LinkedType<ItemType>::append(const LinkedType<ItemType> &lt)  { // does not append items
    Node<ItemType> * thisNode = head;
    while (thisNode->getNext() != nullptr) {
        thisNode = thisNode->getNext();
    }
    Node<ItemType> * newNode;
    Node<ItemType> * ltHead = lt.head;
    while (ltHead != nullptr) {
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
bool LinkedType<ItemType>::submatch(const LinkedType<ItemType> &lt) const { // this works but feel like it could be done better
    Node<ItemType> * haystackNode = head;
    while(haystackNode->getNext() != nullptr) {
        Node<ItemType> * needleNode = lt.head;
       if (haystackNode->getItem() == needleNode->getItem())  {
           Node<ItemType> * substackNode = haystackNode;
           while(needleNode->getNext() != nullptr && substackNode->getItem() == needleNode->getItem()) {
                needleNode = needleNode->getNext();
               substackNode = substackNode->getNext();
           }
           if (needleNode->getNext() == nullptr) {
               return true;
           }
       }
       haystackNode = haystackNode->getNext();
    }
    return false;
}
template<class ItemType>
void LinkedType<ItemType>::loadNodesFromItems() { // resets entire link to items. i think this is a memory link. what happens to prior leak?
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
