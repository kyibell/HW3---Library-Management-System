#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <string>
using namespace std;

class Book : public LibraryItem  {
    public:

  //Constructors 
    Book(); //Default
    Book(string title, string author, int ISBN, string category);  

//Setters
    void SetTitle(string name);
    void SetAuthor(string author);
    void SetISBN(int ISBN);
    void SetLibraryID(int LibraryID);
    void SetCost(double cost);
    void SetStatus(char status);
    void SetCategory(string category);
//Getters
    string GetTitle() const;
    string GetAuthor() const;
    int GetISBN() const;
    int GetLibraryID() const;
    double GetCost() const;
    char GetStatus() const;
    string SetCategory() const;

//Print Function
    void PrintInfo() const override;

    private:

    string title;
    string author;
    int ISBN;
    int LibraryID;
    double cost;
    char status;
    string category;

};

#endif