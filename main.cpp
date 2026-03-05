/**
 * @file main.cpp
 * @brief Test driver for BookType stream insertion/extraction operators.
 */

#include "bookType.h"

#include <iostream>

int main() {
    using std::cin;
    using std::cout;

    BookType book1;
    cin >> book1;

    cout << book1;

    BookType book2("The C Programming Language", "978-0131103627",
                   "Brian W. Kernighan and Dennis M. Ritchie",
                   "Prentice Hall", "01/01/2026", 8, 32.50f, 59.99f);

    cout << "\nChained Output Demo:\n";
    cout << book1 << "\n" << book2;

    return 0;
}
