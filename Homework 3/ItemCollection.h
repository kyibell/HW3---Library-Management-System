#ifndef ITEMCOLLECTION_H
#define ITEMCOLLECTION_H

#include <string>
#include <vector>
using namespace std;

#include "ItemCollection.h"
#include "LibraryItem.h"

class ItemCollection {
public:
  void AddItem(); 
  void DeleteItem(int itemID);
  void EditItem(int itemID);
  void EditItemDetails(LibraryItem *item);
  LibraryItem* FindItem(int itemID);
  void PrintAllItems(); 
  void PrintSpecificItem(int itemID);

private:
  vector<LibraryItem*> itemList;  

};

#endif