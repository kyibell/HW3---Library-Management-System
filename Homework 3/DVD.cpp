#include <iostream>
using namespace std;

#include "DVD.h"

//Default Constructor
DVD::DVD() {
  this->title = "Unknown";
  this->category = "Unknown";
  this->runtime = 0;
  this->studio = "Unknown";
  this->releaseDate = "Unknown";
}

//Initialized Constructor
DVD::DVD(string title, string category, int runtime, string studio, string releaseDate) {
  this->title = title;
  this->category = category;
  this->runtime = runtime;
  this->studio = studio;
  this->releaseDate = releaseDate;
}

//Setters

void DVD::SetTitle(string title) { this->title = title; }
void DVD::SetCategory(string category) { this->category = category; }
void DVD::SetRuntime(int runtime) { this->runtime = runtime; }
void DVD::SetStudio(string studio) { this->studio = studio; }
void DVD::SetReleaseDate(string releaseDate) { this->releaseDate = releaseDate; }

//Getters
string DVD::GetTitle() const { return title; }
string DVD::GetCategory() const { return category; }
int DVD::GetRuntime() const { return runtime; }
string DVD::GetStudio() const { return studio; }
string DVD::GetReleaseDate() const { return releaseDate; }

//Print DVD
void DVD::PrintInfo() {
  cout << "Title: " << title << endl;
  cout << "Category: " << category << endl;
  cout << "Runtime: " << runtime << endl;
  cout << "Studio: " << studio << endl;
  cout << "Release Date: " << releaseDate << endl;
}

