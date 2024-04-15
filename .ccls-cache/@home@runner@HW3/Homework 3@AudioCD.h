#ifndef AUDIOCD_H
#define AUDIOCD_H

#include <string>
#include "LibraryItem.h"

using namespace std;

class AudioCD : public LibraryItem {

private:
  string artist;
  string title;
  int numTracks;
  string releaseDate;
  string genre;

public:
//Constructors
  AudioCD();
  AudioCD(string artist, string title, int numTracks, string releaseDate, string genre);

//CD Setters
  void SetArtist(string artist);
  void SetTitle(string title);
  void SetNumTracks(int numTracks);
  void SetReleaseDate(string releaseDate);
  void SetGenre(string genre);

//CD Getters
  string GetArtist() const;
  string GetTitle() const;
  int GetNumTracks() const;
  string GetReleaseDate() const;
  string GetGenre() const;

//Print Function
  void PrintInfo() const override;

};

#endif