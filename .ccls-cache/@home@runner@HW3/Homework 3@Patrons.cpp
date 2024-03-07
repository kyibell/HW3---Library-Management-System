#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Patron.h"
#include "Patrons.h"

void Patrons::AddPatron() {
  string patronName;
  int PatronID, outBooks;
  double fines;
  cout << "ADD PATRON INFO:" << endl;
  cout << "Please enter the Patron Name:" << endl;
  getline(cin, patronName);
  cin.ignore();
  cout << "Please enter the Patron ID:" << endl;
  cin >> PatronID;
  cout << "Please enter the Patron Fine Balance:" << endl;
  cin >> fines;
  cout << "Please enter the Number of Patron's Out Books:" << endl;
  cin >> outBooks;
  Patron newPatron = Patron(patronName, PatronID, fines, outBooks);

  patronsList.push_back(newPatron);
}

void Patrons::DeletePatron(int PatronID) {
  for (int i = 0; i < patronsList.size(); i++) {
    if (patronsList.at(i).GetIDNum() == PatronID) {
      patronsList.erase(patronsList.begin() + i);
      cout << "Patron deleted." << endl;
    } else {
      cout << "Patron not found. Pleae try again." << endl;
    }
  }
}

void Patrons::EditPatron(int PatronID) {
  bool found = false;
  int i;
  for (i = 0; i < patronsList.size(); i++) {
    if (patronsList.at(i).GetIDNum() == PatronID) {
      found = true;
      EditPatronDetails(patronsList.at(i));
      break;
    } else {
      cout << "Patron not found. Please try again." << endl;
    }
  }
}

void Patrons::EditPatronDetails(Patron &patron) {
  char choice;
  cout << "Select what you would like to edit:" << endl;
  cout << "1. Name" << endl;
  cout << "2. Fine Balance" << endl;
  cout << "3. Number of Out Books" << endl;
  cin >> choice;

  switch (choice) {
  case 1: {
    string newName;
    cout << "Enter new Name:" << endl;
    getline(cin, newName);
    patron.SetName(newName);
    break;
  }
  case 2: {
    double newFineBalance;
    cout << "Enter the new Fine Balance:" << endl;
    cin >> newFineBalance;
    patron.SetFineBalance(newFineBalance);
    break;
  }
  case 3: {
    int newOutBooks;
    cout << "Enter the new Number of Out Books:" << endl;
    cin >> newOutBooks;
    patron.SetCheckedOutBooks(newOutBooks);
    break;
  }
  }
}

Patron Patrons::FindPatron(int PatronID) {
  Patron foundPatron;
  for (int i = 0; i < patronsList.size(); i++) {
    if (patronsList.at(i).GetIDNum() == PatronID) {
      foundPatron = patronsList.at(i);
      break;
    } else {
      cout << "Patron not found. Please try again." << endl;
    }
  }
  return foundPatron;
}

void Patrons::PrintPatrons() {
  cout << "PATRONS:" << endl;
  for (int i = 0; i < patronsList.size(); i++) {
    cout << "Name: " << patronsList.at(i).GetName() << endl;
  }
}

void Patrons::PrintSpecificPatron(int PatronID) {
  Patron foundPatron = FindPatron(PatronID);
  if (foundPatron.GetName() != "") {
    cout << "PATRON DETAILS:" << endl;
    foundPatron.PrintPatron(foundPatron);
  }
}

void Patrons::PayFines(int PatronID) {
  bool found = false;
  for (int i = 0; i < patronsList.size(); i++) {
    if (patronsList.at(i).GetIDNum() == PatronID) {
      found = true;
      patronsList.at(i).SetFineBalance(0.00);
      cout << "Fines payed." << endl;
    }
  }
}