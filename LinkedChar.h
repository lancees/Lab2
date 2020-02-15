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
    LinkedChar(const std::string s) ;
    void appendString(std::string s);

    ~LinkedChar();
};
LinkedChar::LinkedChar(std::string s) {
    itemCount = s.size();
    items   = new char[itemCount];
    for (int j = 0; j < itemCount; j++) {
        items[j] = s[j] ;
    }
    loadNodesFromItems();
}

void LinkedChar::appendString(std::string s) {
   LinkedChar * sl = new LinkedChar(s);
   append(*sl);
//   delete sl;

}
LinkedChar::~LinkedChar() {}
#endif //LAB2_LINKEDCHAR_H


