#ifndef DVD_H
#define DVD_H

#include <string>
#include "LibraryItem.h"

using namespace std;

class DVD : public LibraryItem {
private:
  string title;
  string category;
  int runtime;
  string studio;
  string releaseDate;

public:
//Constructors
  DVD();
  DVD(string title, string category, int runtime, string studio, string releaseDate);

//DVD Setters
  void SetTitle(string title);
  void SetCategory(string category);
  void SetRuntime(int runtime);
  void SetStudio(string studio);
  void SetReleaseDate(string releaseDate);
  

//DVD Getters
  string GetTitle() const;
  string GetCategory() const;
  int GetRuntime() const;
  string GetStudio() const;
  string GetReleaseDate() const;

//Print Function
  void PrintInfo() const override;

};


#endif