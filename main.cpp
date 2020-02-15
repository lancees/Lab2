#include <iostream>
#include <string>
//#include "LinkedType.h"
#include "LinkedChar.h"

int command(std::string s) {
    if (s == "1") { return 1;}
    if (s == "2") { return 2;}
    if (s == "3") { return 3;}
    if (s == "4") { return 4;}
    if (s == "5") { return 5;}
    return 0;
}

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

    // list menu options
    /*
     *
    Enter new string and store as linked list of characters in an ADT LinkedChar class
Get current length (number of characters stored) from the LinkedChar
Find index of character in this LinkedChar
Append another LinkedChar to this LinkedChar (no shallow copy)
Test if another LinkedChar is submatch of this LinkedChar
Quit
     */
    std::string s;
    std::cout << std::endl << " Enter string " << std::endl << ">";
    std::getline(std::cin, s);
    LinkedChar lc = LinkedChar(s);

    std::cout << " 1 Show string" <<  std::endl;
    std::cout << " 2 Length" << std::endl;
    std::cout << " 3 Index" << std::endl;
    std::string appendString;
    LinkedChar appendLC = LinkedChar(appendString);
    std::cout << " 4 Append" << std::endl;
    std::string submatchString;
    LinkedChar submatchLC = LinkedChar(submatchString);
    std::cout << " 5 Submatch" << std::endl;

    std::string q = "0";
    while (q != "q") {
        std::cout << ">";
        std::getline(std::cin, q);
        switch(command(q)) {
            case 1:
                std::cout << " (Show string)" << std::endl;
                lc.print();
                break;
            case 2: std::cout << " (Length)" << std::endl;
                std::cout << " " << lc.length() << std::endl;
                break;
            case 3:
                std::cout << " (Enter char to find)" << std::endl;
                std::cout << ">";
                std::getline(std::cin, s);
                std::cout << lc.index(s[0]) << std::endl;
                break;
            case 4:
                std::cout << " (Enter append string)" << std::endl;
                std::cout << ">";
                std::getline(std::cin, appendString);
                lc.appendString(appendString);
                lc.print();
                break;
            case 5:
                std::cout << " (Enter submatch string)" << std::endl;
                std::cout << ">";
                std::getline(std::cin, submatchString);
                submatchLC = LinkedChar(submatchString);
                std::cout << lc.submatch(submatchLC) << std::endl;
                break;
        }
    }
    std::cout << "welp see ya later" << std::endl;
    return 0;
}