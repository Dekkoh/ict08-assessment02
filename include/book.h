#include <string>
#include <optional>

using namespace std;

class Book
{
public:
    string title;
    string author;
    string isbn;
    bool availability;

private:
    int setBookDetails(string isbn, string author = "", string title = "", optional<bool> availability = nullopt);
    Book displayBookDetails(string isbn);
    int borrowBook(string isbn);
    int returnBook(string isbn);
};