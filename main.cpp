/*
    Programmer: Ryan Posey
    Assignment: A5 - Operator Overloading
    Date: 03/01/2026

*/
/**
 * @file main.cpp
 * @brief Test driver for BookType operator overloads.
 */

#include "bookType.h"

#include <iomanip>
#include <iostream>

int main() {
    using std::boolalpha;
    using std::cout;
    using std::fixed;
    using std::setprecision;

    // init books
    BookType bookA("C++ Primer", "978-0134685991", "Lippman", "Pearson",
                   "03/01/2026", 9, 45.00f, 79.99f);
    BookType bookB("C++ Primer Used", "978-0134685991", "Lippman", "Pearson",
                   "03/01/2026", 5, 40.00f, 69.99f);
    BookType bookC("Data Structures", "978-0132847377", "Carrano", "Pearson",
                   "03/01/2026", 2, 20.00f, 39.99f);

    cout << fixed << setprecision(2) << boolalpha;

    // demonstrate functionality
    cout << "=== 1. Prefix increment (++book) ===\n";
    cout << "Before qty: " << bookA.getQty() << '\n';
    ++bookA;
    cout << "After qty:  " << bookA.getQty() << "\n\n";

    cout << "=== 2. Postfix increment (book++) ===\n";
    cout << "Before qty: " << bookC.getQty() << '\n';
    BookType postIncOld = bookC++;
    cout << "Old qty:    " << postIncOld.getQty() << '\n';
    cout << "New qty:    " << bookC.getQty() << "\n\n";

    cout << "=== 3. Prefix decrement (--book) ===\n";
    cout << "Before qty: " << bookB.getQty() << '\n';
    --bookB;
    cout << "After qty:  " << bookB.getQty() << "\n\n";

    cout << "=== 4. Postfix decrement (book--) ===\n";
    cout << "Before qty: " << bookA.getQty() << '\n';
    BookType postDecOld = bookA--;
    cout << "Old qty:    " << postDecOld.getQty() << '\n';
    cout << "New qty:    " << bookA.getQty() << "\n\n";

    cout << "=== 5. Decrement at zero boundary ===\n";
    bookC.setQty(0);
    cout << "Before qty: " << bookC.getQty() << '\n';
    --bookC;
    cout << "After qty:  " << bookC.getQty() << "\n\n";

    cout << "=== 6. Trade-in valid (newBook - usedBook) ===\n";
    cout << "Formula: balance = retail - (wholesale * 0.5)\n";
    cout << "Inputs: 79.99 - (40.00 * 0.5)\n";
    BookType validTrade = bookA - bookB;
    cout << "Balance: $" << validTrade.getRetail() << "\n\n";

    cout << "=== 7. Trade-in invalid (negative balance) ===\n";
    BookType inexpensive("Cheap Book", "978-0000000001", "Author", "Pub",
                         "03/01/2026", 3, 10.00f, 8.00f);
    BookType expensiveTrade("Expensive Trade", "978-0000000002", "Author",
                            "Pub", "03/01/2026", 1, 30.00f, 35.00f);
    cout << "Inputs: 8.00 - (30.00 * 0.5)\n";
    BookType invalidTrade = inexpensive - expensiveTrade;
    cout << "Returned retail (unchanged LHS): $" << invalidTrade.getRetail()
         << "\n\n";

    cout << "=== 8. == and != by ISBN ===\n";
    cout << "bookA ISBN: " << bookA.getISBN() << '\n';
    cout << "bookB ISBN: " << bookB.getISBN() << '\n';
    cout << "bookC ISBN: " << bookC.getISBN() << '\n';
    cout << "bookA == bookB: " << (bookA == bookB) << '\n';
    cout << "bookA != bookC: " << (bookA != bookC) << "\n\n";

    cout << "=== 9. < > <= >= by retail price ===\n";
    cout << "bookA retail: $" << bookA.getRetail() << '\n';
    cout << "bookC retail: $" << bookC.getRetail() << '\n';
    cout << "bookA <  bookC: " << (bookA < bookC) << '\n';
    cout << "bookA >  bookC: " << (bookA > bookC) << '\n';
    cout << "bookA <= bookC: " << (bookA <= bookC) << '\n';
    cout << "bookA >= bookC: " << (bookA >= bookC) << '\n';

    return 0;
}
