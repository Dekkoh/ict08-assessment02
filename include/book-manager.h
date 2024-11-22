#include <string>
#include <vector>
#include <optional>

#include "book.h"

using namespace std;

class BookManager
{
public:
    int setBookDetails(string isbn, string author = "", string title = "", optional<bool> availability = nullopt);
    Book displayBookDetails(string isbn);
    int borrowBook(string isbn);
    int returnBook(string isbn);

private:
    vector<Book> books;
    int findBookIdxByISBN(string isbn);
};