#include <iostream>
#include <string>
#include <iomanip>
using namespace std; 

#include "Book.h"

//Default Constructor
Book::Book() {
    this->title="None";
    this->author="Unknown";
    this->ISBN= 0;
    this->LibraryID= 0;
    this->cost= 0;
    this->status='U';
}
//Initilized Constructor
Book::Book(string title, string author, int ISBN, int LibraryID, double cost, char status) {
  this->title=title;
  this->author=author;
  this-> ISBN=ISBN;
  this->LibraryID=LibraryID;
  this->cost=cost;
  this->status=status;
}

//Setters
void Book::SetTitle(string name) {
  title = name;
}
void Book::SetAuthor(string bookAuthor){
    author = bookAuthor;
}
void Book::SetISBN(int bookISBN){
    ISBN = bookISBN;
}
void Book::SetLibraryID(int bookLibraryID){
    LibraryID = bookLibraryID;
}
void Book::SetCost(double bookCost){
    cost = bookCost;
}
void Book::SetStatus(char bookStatus){
    status = bookStatus;
}

//Getters
string Book::GetTitle() const{
    return title;
}
string Book::GetAuthor() const{
    return author;
}
int Book::GetISBN() const{
    return ISBN;
}
int Book::GetLibraryID() const{
    return LibraryID;
}
double Book::GetCost() const{
    return cost;
}
char Book::GetStatus() const{
    return status;
}

//Print Book Info
void Book::PrintBook(Book book) {
  cout << "Title: " << book.GetTitle() << endl;
  cout << "Author: " <<  book.GetAuthor() << endl;
  cout << "ISBN: " << book.GetISBN() << endl;
  cout << "Library ID: " << book.GetLibraryID() << endl;
  cout << "Cost: " << book.GetCost() << endl;
  cout << "Status: " << book.GetStatus() << endl;
}

