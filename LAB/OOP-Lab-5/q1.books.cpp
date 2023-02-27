#include <iostream>
#include <istream>
#include <string>
#include <vector>

using namespace std;

enum class Genre {
    Fiction,
    NonFiction,
    Periodical,
    Biography,
    Children
};


class Book {

    private:

        vector<string> isbn;
        string title;
        string author;
        string copyright;
        bool available = true;
        Genre genre;

        
    public:


        Book(vector<string> isbn, string title, string author, string copyright, Genre genre) {
            this->isbn      = isbn;
            this->title     = title;
            this->author    = author;
            this->copyright = copyright;
            this->genre     = genre;
        }

        void setIsbn() {
            this->isbn = isbn;
        }

        void setTitle() {
            this->title = title;
        }

        void setAuthor() {
            this->author = author;
        }

        void setCopyright() {
            this->copyright = copyright;
        }


        void getIsbn() {
            cout << "ISBN ";
            for(int i = 0; i < isbn.size(); i++) {
                if(i == (isbn.size()-1)) {
                    cout << isbn[i];
                    break;
                }
                cout << isbn[i] << "-";
            }
            cout << endl;
        }


        void getTitle() {
            cout << title << endl;
        }

        void getAuthor() {
            cout << "The author of this book is: " << author << endl;
        }

        void getCopyright() {
            cout << "Copyright © " << author << " " << copyright << endl;
        }

        void checkIn() {
            if (available) {
                cout << "You have checked in the book " << title << "." << endl;
                available = false;
            } else {
                cout << "This book is already checked in." << endl;
            }
        }

        void checkOut() {
            if (!available) {
                cout << "You have checked out the book " << title << "." << endl;
                available = true;
            } else {
                cout << "This book is already checked out." << endl;
            }
        }


        bool compare(const Book& other) const {
            if (this->isbn.size() != other.isbn.size()) {
                return false;
            }

            for (size_t i = 0; i < this->isbn.size(); i++) {
                if (this->isbn[i] != other.isbn[i]) {
                    return false;
                }
            }

            return true;
        }
        
        void getGenre() {
            switch (genre) {
                case Genre::Fiction:
                    cout << "This book belongs to the Fiction genre." << endl;
                    break;
                case Genre::NonFiction:
                    cout << "This book belongs to the NonFiction genre." << endl;
                    break;
                case Genre::Periodical:
                    cout << "This book belongs to the Periodical genre." << endl;
                    break;
                case Genre::Biography:
                    cout << "This book belongs to the Biography genre." << endl;
                    break;
                case Genre::Children:
                    cout << "This book belongs to the Children genre." << endl;
                    break;
                default:
                    cout << "Unknown genre" << endl;
            }
        }


        void printBookInfo() {
        cout << "===========================================" << endl;
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "ISBN: ";
        for (int i = 0; i < isbn.size(); i++) {
            if (i > 0) {
                cout << "-";
            }
            cout << isbn[i];
        }
        cout << endl;
        cout << "Genre: ";
            switch (genre) {
                case Genre::Fiction:
                    cout << "Fiction";
                    break;
                case Genre::NonFiction:
                    cout << "Non-fiction";
                    break;
                case Genre::Periodical:
                    cout << "Periodical";
                    break;
                case Genre::Biography:
                    cout << "Biography";
                    break;
                case Genre::Children:
                    cout << "Children";
                    break;
            }
        cout << endl;
        cout << "Status: ";
        if (available) {
            cout << "Available." << endl;
        } else {
            cout << "Not Available." << endl;
        }
        cout << "===========================================\n";
    }
};




int main() {

    vector<string> vec = {"0", "2", "0", "1", "7", "0", "3", "5", "3", "X"};
    Book book1(vec, "Harry Potter", "J. K. Rowling", "1997", Genre::Fiction);

    vector<string> vec2 = {"1", "2", "3", "4", "5"};
    Book book2(vec2, "The Smiths", "Morissey", "2022", Genre::Biography);

    vector<string> vec3 = {"0", "2", "0", "1", "7", "0", "3", "5", "3", "X"};
    Book book3(vec3, "The Beatles", "John Lennon", "1975", Genre::Biography);


    
    //==========================CheckSameISBN===========================
    cout << "\n===========================================" << endl; 
    if (book1.compare(book2)) {
    cout << "The two books have the same ISBN number." << endl;
    } else {
    cout << "The two books have different ISBN numbers." << endl;
    }
    cout << "===========================================\n" << endl;
    //=================================================================



    //====================CheckIn, CheckOut==========================
    cout << "\n===========================================" << endl; 

    book1.checkIn();
    // book1.checkIn();
    // book1.checkOut();

    // book1.getGenre();
    cout << "===========================================\n\n" << endl;
    //=================================================================



    //====================BookInfo, GenreInfo==========================

    book1.printBookInfo();
    // book1.getGenre();

    //=================================================================


    //===========================Read Data=============================
    vector<string> line;

    string valISBN, valTitle, valAuthor, valCopyright, valGenre;
    cout<<"Enter the book ISBN: ";
    getline(cin, valISBN);
    line.push_back(valISBN);

    cout << "Enter the book title: ";
    getline(cin, valTitle);
    cout << "Enter the book Author: ";
    getline(cin, valAuthor);
    cout << "Enter the book copyright year: ";
    getline(cin, valCopyright);
    cout << "Enter the book Genre: ";
    getline(cin, valGenre);


    Book book5(line, valTitle, valAuthor, valCopyright, (valGenre == "fiction" ? Genre::Fiction : (valGenre == "nonfiction" ? Genre::NonFiction : (valGenre == "periodical" ? Genre::Periodical : (valGenre == "biography" ? Genre::Biography : Genre::Children)))));

    book5.printBookInfo();
  

    //=================================================================


    
    
    return 0;
}




