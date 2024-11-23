#pragma once

#include <string>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string isbn;
    bool availability;
    Book(string title, string author, string isbn, bool availability);
};

Book::Book(string title, string author, string isbn, bool availability) {
    this->title = title;
    this->author = author;
    this->isbn = isbn;
    this->availability = availability;
}