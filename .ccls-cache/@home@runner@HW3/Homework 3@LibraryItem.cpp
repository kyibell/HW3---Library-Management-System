#include <iostream>
#include <string>

using namespace std;

#include "LibraryItem.h"

//Default Constructor
LibraryItem::LibraryItem() {
  this->itemID = 0;
  this->cost = 0.0;
  this->status = 'U';
  this->loanPeriod = 0;
}

//Initilized Constructor
LibraryItem::LibraryItem(int itemID, double cost, char status, int loanPeriod) {
  this->itemID = itemID;
  this->cost = cost;
  this->status = status;
  this->loanPeriod = loanPeriod;
}

//Setters

void LibraryItem::SetItemID(int itemID) { this->itemID = itemID; }
void LibraryItem::SetCost(double cost) { this->cost = cost; }
void LibraryItem::SetStatus(char status) {this->status = status; }
void LibraryItem::SetLoanPeriod(int loanPeriod) {this->loanPeriod = loanPeriod; }

//Getters

int LibraryItem::GetItemID() const { return itemID; }
double LibraryItem::GetCost() const { return cost; }
char LibraryItem::GetStatus() const { return status; }
int LibraryItem::GetLoanPeriod() const { return loanPeriod; }

//Print LibraryItem
void LibraryItem::PrintInfo() const {
  cout << "Item ID: " << itemID << endl;
  cout << "Cost: " << cost << endl;
  cout << "Status: " << status << endl;
  cout << "Loan Period: " << loanPeriod << endl;
}
