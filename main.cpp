#include <iostream>
#include <string>
#include "LinkedType.h"
#include "LinkedChar.h"
#include "Node.h"

class Bag {
private:
    Node<int> * head;
public:
    Bag () : head(nullptr) {}

    void add (int item) {
        Node<int>* newNode = new Node<int>(item);
        newNode->setNext(head);
        head = newNode;
    }

    void remove(int item) {
        Node<int>* currNode = head;

        while(currNode != nullptr && currNode->getItem() != item) {
            currNode = currNode->getNext();
        }
        // remove item by removing first node
        if (currNode != nullptr) {
            currNode->setItem(head->getItem());
            Node<int> *deleteNode = head;
            head = head->getNext();
            delete deleteNode;
        }
    }

    void display () const {
        Node<int> * currNode = head;

        std::cout << "bag - " << head << " : ";
        while(currNode != nullptr) {
            std::cout << currNode << " - " << currNode->getItem() << " ";
            currNode = currNode->getNext();
        }
        std::cout << std::endl;
    }

    void clear() {

        while(head != nullptr) {
            Node<int> *deleteNode = head;
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