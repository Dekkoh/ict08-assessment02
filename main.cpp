#include <iostream>
#include <vector>
#include <string>
#include "book.cpp"
#include "book-manager.cpp"

using namespace std;

enum Command
{
    DEFAULT = -1,
    EXIT = 0,
    SET_BOOK_DETAILS = 1,
    DISPLAY_BOOK_DETAILS = 2,
    BORROW_BOOK = 3,
    RETURN_BOOK = 4
};

bool isInteger(const string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
        {
            return false;
        }
    return true;
}

vector<Book> initBooks()
{
    Book book1("Harry Potter and the Sorcerer's Stone", "Rowling, J. K.", "9781338878929", true);
    Book book2("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", "9780132350884", true);
    Book book3("The Lord Of The Rings Deluxe Edition", "J.R.R. Tolkien", "9780544273443", true);
    Book book4("Percy Jackson and the Olympians: Wrath of the Triple Goddess", "Riordan, Rick", "9781368107631", true);
    Book book5("The Witcher: Classic Collection", "Sapkowski, Andrzej - Parowski, Maciej", "9781506744001", true);

    return {book1, book2, book3, book4, book5};
}

void welcome()
{
    cout << "Welcome to the Library Management system!" << endl
         << endl;
}

void listCommands()
{
    cout << "1. Set book details" << endl;
    cout << "2. Display book details" << endl;
    cout << "3. Borrow book" << endl;
    cout << "4. Return book" << endl;
    cout << "0. Exit" << endl;
}

int readCommand()
{
    string command;

    cout << "Enter command: ";
    cin >> command;
    cout << endl;

    if (!isInteger(command))
    {
        return DEFAULT;
    }

    return stoi(command);
}

string readISBN()
{
    string isbn;

    cout << "Enter book ISBN: ";
    cin >> isbn;
    cout << endl;

    return isbn;
}

string readTitle()
{
    string title;

    cout << "Enter book Title: ";
    cin.ignore();
    getline(cin, title);
    cout << endl;

    return title;
}

string readAuthor()
{
    string author;

    cout << "Enter book Author: ";
    getline(cin, author);
    cout << endl;

    return author;
}

bool readAvailability()
{
    int availability;

    cout << "Enter book Availability: ";
    cin >> availability;
    cout << endl;

    return availability;
}

void controlLoop(BookManager bookManager)
{
    welcome();

    int command = DEFAULT;
    string isbn;
    string title;
    string author;
    bool availability;

    while (command != EXIT)
    {
        listCommands();
        command = readCommand();

        switch (command)
        {
        case SET_BOOK_DETAILS:
            isbn = readISBN();
            title = readTitle();
            author = readAuthor();
            availability = readAvailability();
            cout << availability;
            bookManager.setBookDetails(isbn, title, author, availability);
            break;
        case DISPLAY_BOOK_DETAILS:
            isbn = readISBN();
            bookManager.displayBookDetails(isbn);
            break;
        case BORROW_BOOK:
            isbn = readISBN();
            bookManager.borrowBook(isbn);
            break;
        case RETURN_BOOK:
            isbn = readISBN();
            bookManager.returnBook(isbn);
            break;
        case EXIT:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid command. Please use a valid command." << endl
                 << endl;
            break;
        }
    }
}

int main()
{
    vector<Book> books = initBooks();

    BookManager bookManager(books);
    controlLoop(bookManager);

    return 0;
}
