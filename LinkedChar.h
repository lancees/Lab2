//
// Created by Lance Sander on 2/8/20.
//

#ifndef LAB2_LINKEDCHAR_H
#define LAB2_LINKEDCHAR_H

<ItemType>
class LinkedChar {
    virtual LinkedChar() = 0;

    virtual LinkedChar(const std::string s) = 0;

    virtual int length() const = 0;

    virtual int index(char ch) const = 0;

    virtual void append(const LinkedChar& lc) = 0;

    virtual bool submatch(const LinkedChar& lc) const = 0;

    virtual ~LinkedChar() = 0;

};




#endif //LAB2_LINKEDCHAR_H
