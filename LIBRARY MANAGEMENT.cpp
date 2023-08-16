#include <iostream>
#include <cstring>

using namespace std;

class Book {
    int bookId;
    char bookTitle[50];
    char author[50];
    bool available;

public:
    void setBookDetails() {
        cout << "Enter Book ID: ";
        cin >> bookId;

        cin.ignore();

        cout << "Enter Book Title: ";
        cin.getline(bookTitle, 50);

        cout << "Enter Author: ";
        cin.getline(author, 50);

        available = true;
    }

    void displayBookDetails() {
        cout << "Book ID: " << bookId << endl;
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author: " << author << endl;
    }

    void borrowBook() {
        if (available) {
            available = false;
            cout << "Book borrowed successfully!" << endl;
        } else {
            cout << "Book is not available." << endl;
        }
    }

    void returnBook() {
        available = true;
        cout << "Book returned successfully!" << endl;
    }

    int getBookId() {
        return bookId;
    }

    const char* getBookTitle() {
        return bookTitle;
    }

    const char* getAuthor() {
        return author;
    }

    bool isAvailable() {
        return available;
    }
};

int main() {
    Book books[100];
    int numBooks = 0;

    int choice;
    char exit;

    do {
        cout << "----- Library Management System -----" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Display All Books" << endl;
        cout << "4. Borrow Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                books[numBooks].setBookDetails();
                numBooks++;
                break;
            }
            case 2: {
                int searchId;
                cout << "Enter the Book ID to search: ";
                cin >> searchId;

                bool found = false;
                for (int i = 0; i < numBooks; i++) {
                    if (books[i].getBookId() == searchId) {
                        books[i].displayBookDetails();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }

                break;
            }
            case 3: {
                if (numBooks == 0) {
                    cout << "No books available." << endl;
                    break;
                }

                cout << "----- List of Books -----" << endl;
                for (int i = 0; i < numBooks; i++) {
                    books[i].displayBookDetails();
                    cout << endl;
                }
                
                break;
            }
            case 4: {
                int borrowId;
                cout << "Enter the Book ID to borrow: ";
                cin >> borrowId;

                bool found = false;
                for (int i = 0; i < numBooks; i++) {
                    if (books[i].getBookId() == borrowId) {
                        books[i].borrowBook();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }

                break;
            }
            case 5: {
                int returnId;
                cout << "Enter the Book ID to return: ";
                cin >> returnId;

                bool found = false;
                for (int i = 0; i < numBooks; i++) {
                    if (books[i].getBookId() == returnId) {
                        books[i].returnBook();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Book not found!" << endl;
                }

                break;
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }

        cout << "Do you want to continue (y/n)? ";
        cin >> exit;

    } while (exit == 'y' || exit == 'Y');

    return 0;
}
