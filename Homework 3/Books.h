#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <vector>
using namespace std;

#include "Book.h"

class Books {
public:
  void AddBook(); 
  void DeleteBook(int BookID);
  void EditBook(int BookID);
  void EditBookDetails(Book& book);
  Book* FindBook(int BookID);
  void PrintAllBooks(); 
  void PrintSpecificBook(int BookID);

private:
  vector<Book> booksList;
};

#endif