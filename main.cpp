#include <iostream>
#include <string>
//#include "LinkedType.h"
#include "LinkedChar.h"
#include "Node.h"
int command(std::string s) {
    if (s == "1") { return 1;}
    if (s == "2") { return 2;}
    if (s == "3") { return 3;}
    if (s == "4") { return 4;}
    if (s == "5") { return 5;}
    return 0;
}

int main() {
    /*
    Enter new string and store as linked list of characters in an ADT LinkedChar class
Get current length (number of characters stored) from the LinkedChar
Find index of character in this LinkedChar
Append another LinkedChar to this LinkedChar (no shallow copy)
Test if another LinkedChar is submatchType of this LinkedChar
Quit
     */
    std::string s;
    std::cout << std::endl << " Enter string " << std::endl << ">";
    std::getline(std::cin, s);
    LinkedChar lc = LinkedChar(s);

    std::cout << " 1 Show string" <<  std::endl;
    std::cout << " 2 Length" << std::endl;
    std::cout << " 3 Index" << std::endl;
    std::cout << " 4 Append" << std::endl;
    std::cout << " 5 Submatch" << std::endl;
    std::cout << " q quit" << std::endl;

    std::string submatchString;
    LinkedChar submatchLC;
    std::string appendString;
    LinkedChar appendLC;
    std::string q = "0";
    while (q != "q") {
        std::cout << ">";
        std::getline(std::cin, q);
        switch(command(q)) {
            case 1:
                std::cout << " (print string)" << std::endl;
                lc.print();
                break;
            case 2: std::cout << " (length)" << std::endl;
                std::cout << " " << lc.length() << std::endl;
                break;
            case 3:
                std::cout << " (enter char to find)" << std::endl;
                std::cout << ">";
                std::getline(std::cin, s);
                std::cout << " (char position)" << std::endl;
                std::cout << lc.index(s[0]) << std::endl;
                break;
            case 4:
                std::cout << " (enter append string)" << std::endl;
                std::cout << ">";
                std::getline(std::cin, appendString);
                appendLC = LinkedChar(appendString);
                lc.append(appendLC);
                lc.print();
                break;
            case 5:
                std::cout << " (enter submatchType string)" << std::endl;
                std::cout << ">";
                std::getline(std::cin, submatchString);
                submatchLC = LinkedChar(submatchString);
                std::cout << " (Match result)" << std::endl;
                std::cout << lc.submatch(submatchLC) << std::endl;
                break;
        }
    }
    std::cout << "welp see ya later" << std::endl;
    return 0;
}