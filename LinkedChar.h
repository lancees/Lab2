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
    void append(const LinkedChar& lc);
    bool submatch(const LinkedChar& lc) const;
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

void LinkedChar::append(const LinkedChar &lc) {
    apppendItem(lc);
}
bool LinkedChar::submatch(const LinkedChar& lc) const {
    return LinkedType<char>::submatchType(lc);
}
void LinkedChar::appendString(std::string s) {
    LinkedChar sl = LinkedChar(s);
    apppendItem(sl);
}
LinkedChar::~LinkedChar() {}
#endif //LAB2_LINKEDCHAR_H


