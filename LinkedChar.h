//
// Created by Lance Sander on 2/9/20.
//
#include <string>
#include "LinkedType.h"
#ifndef LAB2_LINKEDCHAR_H
#define LAB2_LINKEDCHAR_H
class LinkedChar : public LinkedType<char>{
public:
    LinkedChar(std::string s) {
        itemCount = s.size();
        items   = new char[s.size()];
//        std::cout << s << "(" << itemCount << ")" << std::endl;
        for (int j = 0; j < itemCount; j++) {
           items[j] = s[j] ;
//           std::cout << j << " - " << items[j] << std::endl;
        }
        // std::cout << "items - " << items << "||" << *items++ << *items++ << std::endl;
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

