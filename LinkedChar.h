//
// Created by Lance Sander on 2/9/20.
//
#include <string>
#include "LinkedType.h"
#ifndef LAB2_LINKEDCHAR_H
#define LAB2_LINKEDCHAR_H
class LinkedChar : public LinkedType<char>{
public:
    LinkedChar() {}
    LinkedChar(std::string s) {
        itemCount = s.size();
        items   = new char[itemCount];
        for (int j = 0; j < itemCount; j++) {
           items[j] = s[j] ;
        }
    }
    void testy() {
        // std::cout << "testyLC - " << items << std::endl;
    }
//    void append(const LinkedTypeInterface &lt);
//
//    bool submatch(const LinkedTypeInterface &lt) const;

    ~LinkedChar();
};
#endif //LAB2_LINKEDCHAR_H

//void LinkedChar::append(const LinkedTypeInterface &lt) {
//
//}
//
//bool LinkedChar::submatch(const LinkedTypeInterface &lt) const {
//    return false;
//}

LinkedChar::~LinkedChar() {
}

