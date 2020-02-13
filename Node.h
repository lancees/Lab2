//
// Created by Lance Sander on 2/10/20.
//

#ifndef LAB2_NODE_H
#define LAB2_NODE_H
template<class ItemType>
class Node {
private:
    ItemType item;
    Node * next;
public:
    Node() {}
    Node(ItemType item) : item(item), next(nullptr) {}
    Node(ItemType item, Node * next) : item(item), next(next) {}

    ItemType getItem() const {
        return item;
    }

    void setItem(ItemType item) {
        Node::item = item;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node* next) {
        this->next = next;
    }

};

#endif //LAB2_NODE_H