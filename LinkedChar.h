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
        // LinkedChar::i[3] = {'a', 'b', 'c'};
        std::cout << s << s.size() << std::endl;
        char i [s.size()];
        for (int j = 0; j < s.size(); j++) {
           i[j] = s[j] ;
           std::cout << "j -" << i[j] << std::endl;
        }
        items = i;
        std::cout << "items - " << items << "||" << *items++ << *items++ << std::endl;
    }
    void testy() {
        items--;
        std::cout << "testyLC - " << items << std::endl;
    }
//    void append(const LinkedTypeInterface &lt);
//
//    bool submatch(const LinkedTypeInterface &lt) const;

    ~LinkedChar() override;
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

