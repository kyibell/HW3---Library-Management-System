#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <vector>
using namespace std;

#include "LibraryItem.h"
#include "Book.h"
#include "DVD.h"
#include "AudioCD.h"

class ItemCollection {
public:
  void AddItem(); 
  void DeleteItem(int itemID);
  void EditItem(int itemID);
  void EditItemDetails(LibraryItem& item);
  Book* FindItem(int itemID);
  void PrintAllItems(); 
  void PrintSpecificItem(int itemID);

private:
  vector<LibraryItem> itemList;

};

#endif