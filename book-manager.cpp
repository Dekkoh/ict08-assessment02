#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "book.cpp"

using namespace std;

class BookManager
{
public:
    int setBookDetails(string isbn, string author = "", string title = "", int availability = -1);
    int displayBookDetails(string isbn);
    int borrowBook(string isbn);
    int returnBook(string isbn);
    BookManager(vector<Book> books);
    BookManager();

private:
    vector<Book> books;
    int findBookIdxByISBN(string isbn);
};

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

int BookManager::setBookDetails(string isbn, string title, string author, int availability)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    this->books[bookIdx].title = (title != "") ? title : this->books[bookIdx].title;
    this->books[bookIdx].author = (author != "") ? author : this->books[bookIdx].author;
    this->books[bookIdx].availability = (availability != -1) ? (bool)availability : this->books[bookIdx].availability;

    cout << "Book with ISBN " << isbn << " successfully updated!" << endl << endl;
    return 0;
};

int BookManager::displayBookDetails(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    Book book = this->books[bookIdx];

    cout << "Displaying book details" << endl;

    cout << "Title: " << book.title << endl;
    cout << "Author: " << book.author << endl;
    cout << "ISBN: " << book.isbn << endl;
    cout << "Availability: " << book.availability << endl << endl;

    return 0;
}

int BookManager::borrowBook(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    if (this->books[bookIdx].availability == false)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not available!" << endl << endl;
        return -1;
    }

    this->books[bookIdx].availability = false;
    cout << "Book with ISBN " << isbn << " successfully borrowed!" << endl << endl;

    return 0;
}

int BookManager::returnBook(string isbn)
{
    int bookIdx = this->findBookIdxByISBN(isbn);

    if (bookIdx == -1)
    {
        cout << "[Error]: Book with ISBN " << isbn << " not found!" << endl << endl;
        return -1;
    }

    if (this->books[bookIdx].availability == true)
    {
        cout << "[Error]: Book with ISBN " << isbn << " already returned!" << endl << endl;
        return -1;
    }

    this->books[bookIdx].availability = true;
    cout << "Book with ISBN " << isbn << " successfully returned!" << endl << endl;

    return 0;
}

BookManager::BookManager(vector<Book> books) {
    this->books = books;
}

BookManager::BookManager() {
    this->books = books;
}
