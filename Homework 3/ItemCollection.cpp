#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "AudioCD.h"
#include "Book.h"
#include "DVD.h"
#include "ItemCollection.h"

void ItemCollection::AddItem() {
  int itemID;
  double cost;
  char status;
  int loanPeriod;
  cout << "ADD ITEM" << endl;
  cout << "Please enter the Item ID:" << endl;
  cin >> itemID;
  cout << "Please enter the item cost: " << endl;
  cin >> cost;
  cout << "Please enter the item status: " << endl;
  cin >> status;
  cout << "Please enter the item loan period: " << endl;
  cin >> loanPeriod;
  cout << "What type of item are you adding? (1. Book, 2. CD, 3. DVD): "
       << endl;
  char choice;
  cin >> choice;

  switch (choice) {
  case '1': {
    string author, title, category;
    int ISBN;
    cout << "Please enter the book's title :" << endl;
    getline(cin, title);
    cout << "Please enter the book's author :" << endl;
    getline(cin, author);
    cout << "Please enter the book's ISBN :" << endl;
    cin >> ISBN;
    cin.ignore();
    cout << "Please enter the book's category :" << endl;
    getline(cin, category);

    LibraryItem *newItem = new Book(title, author, ISBN, category);
    newItem->SetItemID(itemID);
    newItem->SetCost(cost);
    newItem->SetStatus(status);
    newItem->SetLoanPeriod(loanPeriod);

    itemList.push_back(newItem);

    cout << "Book added sucessfully." << endl;
    break;
  }
  case '2': {
    string artist, cdTitle, releaseDate, genre;
    int numTracks;
    cout << "Please enter the CD's title :" << endl;
    getline(cin, cdTitle);
    cin.ignore();
    cout << "Please enter the CD's artist :" << endl;
    getline(cin, artist);
    cout << "Please enter the CD's release date :" << endl;
    getline(cin, releaseDate);
    cout << "Please enter the CD's track count :" << endl;
    cin >> numTracks;
    cin.ignore();
    cout << "Please enter the CD's genre :" << endl;
    getline(cin, genre);

    LibraryItem *cdItem =
        new AudioCD(artist, cdTitle, numTracks, releaseDate, genre);
    cdItem->SetItemID(itemID);
    cdItem->SetCost(cost);
    cdItem->SetStatus(status);
    cdItem->SetLoanPeriod(loanPeriod);
    itemList.push_back(cdItem);
    break;
  }
  case '3':
    string dvdTitle, dvdCategory, studio, releaseDate;
    int runTime;
    cout << "Please enter the DVD's title :" << endl;
    getline(cin, dvdTitle);
    cout << "Please enter the DVD's category :" << endl;
    getline(cin, dvdCategory);
    cout << "Please enter the DVD's studio :" << endl;
    getline(cin, studio);
    cout << "Please enter the DVD's release date :" << endl;
    getline(cin, releaseDate);
    cout << "Please enter the DVD's run time (in minutes):" << endl;
    cin >> runTime;

    LibraryItem *newDVD =
        new DVD(dvdTitle, dvdCategory, runTime, studio, releaseDate);
    newDVD->SetItemID(itemID);
    newDVD->SetCost(cost);
    newDVD->SetStatus(status);
    newDVD->SetLoanPeriod(loanPeriod);
    itemList.push_back(newDVD);
    break;
  }
}

void ItemCollection::DeleteItem(int itemID) {
  for (auto it = itemList.begin(); it != itemList.end(); ++it) {
    if ((*it)->GetItemID() == itemID) {
      //  delete *it;
      itemList.erase(it);
      break;
    } else {
      cout << "Item not found. Please try again." << endl;
    }
  }
}
void ItemCollection::EditItem(int itemID) {
  for (auto it = itemList.begin(); it != itemList.end(); ++it) {
    if ((*it)->GetItemID() == itemID) {
      EditItemDetails(*it);
      break;
    }
  }
}

void ItemCollection::EditItemDetails(LibraryItem *item) {}

LibraryItem *ItemCollection::FindItem(int itemID) {
  for (int i = 0; i < itemList.size(); i++) {
    if (itemList.at(i)->GetItemID() == itemID) {
      return itemList.at(i);
      break;
    }
  }
  cout << "Item not found. Please try again." << endl;
  return nullptr;
}

void ItemCollection::PrintAllItems() {
  cout << "ITEM COLLECTION:" << endl;
  for (int i = 0; i < itemList.size(); i++) {
    cout << "Item ID: " << itemList.at(i)->GetItemID() << endl;
  }
}

void ItemCollection::PrintSpecificItem(int itemID) {
  LibraryItem *foundItem = FindItem(itemID);
  if (foundItem->GetItemID() != 0) {
    cout << "ITEM DETAILS:" << endl;
    foundItem->PrintInfo();
  }
}