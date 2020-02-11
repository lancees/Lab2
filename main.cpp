#include <iostream>
#include <string>
#include "LinkedType.h"
#include "LinkedChar.h"

class Node {
private:
    int item;
    Node * next;
public:
    Node(int item) : item(item), next(nullptr) {}

    int getItem() const {
        return item;
    }

    void setItem(int item) {
        Node::item = item;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node* next) {
        this->next = next;
    }

};

class Bag {
private:
    Node * head;
public:
    Bag () : head(nullptr) {}

    void add (int item) {
        Node * newNode = new Node(item);
        newNode->setNext(head);
        head = newNode;
    }

    void remove(int item) {
        Node * currNode = head;

        while(currNode != nullptr && currNode->getItem() != item) {
            currNode = currNode->getNext();
        }
        // remove item by removing first node
        if (currNode != nullptr) {
            currNode->setItem(head->getItem());
            Node *deleteNode = head;
            head = head->getNext();
            delete deleteNode;
        }
    }

    void display () const {
        Node * currNode = head;

        std::cout << "bag - " << head << " : ";
        while(currNode != nullptr) {
            std::cout << currNode << " - " << currNode->getItem() << " ";
            currNode = currNode->getNext();
        }
        std::cout << std::endl;
    }

    void clear() {

        while(head != nullptr) {
            Node *deleteNode = head;
            head = head->getNext();
            delete deleteNode;
            deleteNode = nullptr;
        }
    }
    ~Bag () { clear(); }
};

int main() {
    Bag bag;
    bag.display();

    bag.add(1);
    bag.add(3);
    bag.add(5);
    bag.display();

    bag.remove(3);
    bag.display();

    bag.remove(1);
    bag.display();

    bag.remove(3);
    bag.display();

    bag.clear();
    bag.display();

    LinkedChar ls =  LinkedChar("Lance is fun");
    ls.testy();

    char i[] = {'a', 'b', 'c'};
    LinkedType<char> t = LinkedType<char>(i, 3);
    t.testy();
    return 0;
}