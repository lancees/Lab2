#include <iostream>
#include <string>
//#include "LinkedType.h"
#include "LinkedChar.h"

int main() {
    LinkedChar ls =  LinkedChar("Lance is fun");
    ls.print();
    LinkedChar ls2 =  LinkedChar(" so join the party");
    ls.append(ls2);
    ls.appendString(". For old times!");
    ls.print();

    char i[] = {'F', 'u', 'n'};
    LinkedType<char> t = LinkedType<char>(i, 3);
    t.print();
    char findMe = 'u';
    t.index(findMe);
    char o[] = {'o', 't', 'h', 'e', 'r'};
    LinkedType<char> ol = LinkedType<char>(o, 5);
    char y[] = {'z'};
    LinkedType<char> yl = LinkedType<char>(y, 1);
    ol.print();
    t.append(ol);
    t.print();
    std::cout << t.submatch(yl);
    std::cout << t.submatch(ol);
    char c1 = 'h';
    char c2 = 'n';
    char c3 = 'x';
    std::cout << std::endl;
    std::cout << "Index" << std::endl;
    std::cout << t.index(c1);
    std::cout << t.index(c2);
    std::cout << t.index(c3);
    return 0;
}