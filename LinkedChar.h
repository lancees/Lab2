//
// Created by Lance Sander on 2/9/20.
//
#include <string>
#include "LinkedType.h"
#ifndef LAB2_LINKEDCHAR_H
#define LAB2_LINKEDCHAR_H
class LinkedChar : public LinkedType<std::string>{
public:
    LinkedChar(std::string s) {
        std::cout << s << s.size() << std::endl;
    }

    void append(const LinkedTypeInterface &lt);

    bool submatch(const LinkedTypeInterface &lt) const;

    ~LinkedChar() override;
};
#endif //LAB2_LINKEDCHAR_H

void LinkedChar::append(const LinkedTypeInterface &lt) {

}

bool LinkedChar::submatch(const LinkedTypeInterface &lt) const {
    return false;
}

LinkedChar::~LinkedChar() {

}
