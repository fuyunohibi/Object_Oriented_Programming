#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Book struct definition
struct Books {
    string title;
    vector<string> authors;
    vector<string> isbn;
};

// Function to find a book by ISBN
Books* Find(vector<Books>& books, const string& isbn) {
    for (auto& book : books) {
        for (auto& book_isbn : book.isbn) {
            if (book_isbn == isbn) {
                return &book;
            }
        }
    }
    return nullptr;
}

int main() {

    vector<Books> library = {
        {"The Great Gatsby", {"F. Scott Fitzgerald"}, {"978-00000"}},
        {"To Kill a Mockingbird", {"Harper Lee"}, {"978-00001"}},
        {"Pride and Prejudice", {"Jane Austen"}, {"978-00001"}}
    };

    // Find a book by ISBN
    string isbn_to_find = "978-00000";
    Books* found_book = Find(library, isbn_to_find);

    // Check if the book was found
    if (found_book != nullptr) {
        cout << "Book found: " << found_book->title << endl;
    } else {
        cout << "Book not found." << endl;
    }
}
