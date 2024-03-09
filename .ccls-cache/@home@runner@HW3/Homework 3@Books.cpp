#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Book.h"
#include "Books.h"

void Books::AddBook() {
  string authorName, bookTitle;
  int bookISBN, bookLibraryID;
  double cost;
  char status;
  cout << "ADD BOOK INFO" << endl;
  cout << "Please enter the Book Title:" << endl;
  cin.ignore();
  getline(cin, bookTitle);
  cout << "Please enter the Book Author:" << endl;
  getline(cin, authorName);
  cout << "Please enter the Book ISBN:" << endl;
  cin >> bookISBN;
  cout << "Please enter the Book Library ID:" << endl;
  cin >> bookLibraryID;
  cout << "Please enter the Book Cost:" << endl;
  cin >> cost;
  cout << "Please enter the Book Status:\n 'I' - In \n 'O' - Out\n 'L' - "
          "Lost\n 'R' - Repair"
       << endl;
  cin >> status;

  Book newBook =
      Book(bookTitle, authorName, bookISBN, bookLibraryID, cost, status);

  booksList.push_back(newBook);
  cout << "Book added successfully." << endl;
}

void Books::DeleteBook(int BookID) {
  cout << "DELETE BOOK INFO" << endl;
  for (int i = 0; i < booksList.size(); i++) {
    if (booksList.at(i).GetLibraryID() == BookID) {
      booksList.erase(booksList.begin() + i);
      cout << "Book deleted." << endl;
    } else {
      cout << "Book not found. Please try again." << endl;
      cout << endl;
    }
  }
}

void Books::EditBook(int BookID) {
  bool found = false;
  int i;
  cout << "EDIT BOOK INFO" << endl;
  for (i = 0; i < booksList.size(); i++) {
    if (booksList.at(i).GetLibraryID() == BookID) {
      found = true;
      EditBookDetails(booksList.at(i));
      break;
    }
  }
  if (!found) {
    cout << "Book not found. Please try again." << endl;
  }
}

void Books::EditBookDetails(Book &book) {
  char choice;

  cout << "Select what you would like to edit:" << endl;
  cout << "1. Title" << endl;
  cout << "2. Author" << endl;
  cout << "3. ISBN" << endl;
  cout << "4. Library ID" << endl;
  cout << "5. Cost" << endl;
  cout << "6. Status" << endl;
  cin >> choice;

  switch (choice) {
  case '1': {
    string newTitle;
    cout << "Enter new Title:" << endl;
    cin.ignore();
    getline(cin, newTitle);
    book.SetTitle(newTitle);
    break;
  }
  case '2': {
    string newAuthor;
    cout << "Enter new Author:" << endl;
    cin.ignore();
    getline(cin, newAuthor);
    book.SetAuthor(newAuthor);
    break;
  }
  case '3': {
    int newISBN;
    cout << "Enter new ISBN:" << endl;
    cin >> newISBN;
    book.SetISBN(newISBN);
    break;
  }
  case '4': {
    int newLibraryID;
    cout << "Enter new Library ID:" << endl;
    cin >> newLibraryID;
    book.SetLibraryID(newLibraryID);
    break;
  }
  case '5': {
    double newCost;
    cout << "Enter new Cost:" << endl;
    cin >> newCost;
    book.SetCost(newCost);
    break;
  }
  case '6': {
    char newStatus;
    cout << "Enter new Status:" << endl;
    cin >> newStatus;
    book.SetStatus(newStatus);
    break;
  }
  default:
    cout << "Invalid choice." << endl;
    break;
  }
}

Book* Books::FindBook(int BookID) {
  Book foundBook;
  for (int i = 0; i < booksList.size(); i++) {
    if (booksList.at(i).GetLibraryID() == BookID) {
      foundBook = booksList.at(i);
      return &booksList.at(i);
      break;
    }
  }
  cout << "Book not found. Please try again." << endl;
  return nullptr;
}
void Books::PrintAllBooks() {
  cout << "BOOK COLLECTION:" << endl;
  for (int i = 0; i < booksList.size(); i++) {
    cout << "Title: " << booksList.at(i).GetTitle() << endl;
  }
}

void Books::PrintSpecificBook(int BookID) {
  Book *foundBook = FindBook(BookID);
  if (foundBook->GetTitle() != "") {
    cout << "BOOK DETAILS:" << endl;
    foundBook->PrintBook(*foundBook);
  }
}