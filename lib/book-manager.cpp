#include <iostream>

#include "../include/book-manager.h"

using namespace std;

int BookManager::findBookIdxByISBN(string isbn)
{
    int bookIdx = -1;

    for (int i = 0; i < this->books.size(); i++)
    {
        if (this->books[i].isbn.compare(isbn) == 0)
        {
            bookIdx = i;
            break;
        }
    }

    return bookIdx;
};

int BookManager::setBookDetails(string isbn, string author = "", string title = "", optional<bool> availability = nullopt)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl;
        return -1;
    }

    this->books[bookIdx].author = (author != "") ? author : this->books[bookIdx].author;
    this->books[bookIdx].title = (title != "") ? title : this->books[bookIdx].title;
    this->books[bookIdx].availability = (availability != nullopt) ? (bool)availability : this->books[bookIdx].availability;

    cout << "Book with ISBN " << isbn << " successfully updated!" << endl;
    return 0;
};

Book BookManager::displayBookDetails(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl;
        return;
    }

    Book book = this->books[bookIdx];

    cout << "Displaying book details" << endl;

    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "ISBN: " << book.isbn << endl;
    cout << "Availability: " << book.availability << endl;

    return book;
}

int BookManager::borrowBook(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl;
        return -1;
    }

    if (this->books[bookIdx].availability == false)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not available!" << endl;
        return -1;
    }

    this->books[bookIdx].availability = false;
    cout << "Book with ISBN " << isbn << " successfully borrowed!" << endl;

    return 0;
}

int BookManager::returnBook(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl;
        return -1;
    }

    if (this->books[bookIdx].availability == true)
    {
        cout << "[Error]: Book with ISBN " << isbn << " already returned!" << endl;
        return -1;
    }

    this->books[bookIdx].availability = true;
    cout << "Book with ISBN " << isbn << " successfully returned!" << endl;

    return 0;
}
