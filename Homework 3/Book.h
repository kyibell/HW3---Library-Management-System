#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
    public:

    Book();
    Book(string title, string author, int ISBN, int LibraryID, double cost, char status);

    void SetTitle(string name);
    void SetAuthor(string author);
    void SetISBN(int ISBN);
    void SetLibraryID(int LibraryID);
    void SetCost(double cost);
    void SetStatus(char status);
    void PrintBook(Book book);

    string GetTitle() const;
    string GetAuthor() const;
    int GetISBN() const;
    int GetLibraryID() const;
    double GetCost() const;
    char GetStatus() const;

    private:

    string title;
    string author;
    int ISBN;
    int LibraryID;
    double cost;
    char status;

};

#endif