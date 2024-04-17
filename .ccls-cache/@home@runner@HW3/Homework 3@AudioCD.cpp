#include <iostream>
#include <string>

#include "AudioCD.h"

//Default Constructor
AudioCD::AudioCD() {
  this->artist = "Unknown";
  this->title = "Unknown";
  this->numTracks = 0;
  this->releaseDate = "Unknown";
  this->genre = "Unknown";
}

//Initialized Constructor
AudioCD::AudioCD(string artist, string title, int numTracks, string releaseDate, string genre) {
  this->artist = artist;
  this->title = title;
  this->numTracks = numTracks;
  this->releaseDate = releaseDate;
  this->genre = genre;
}

//Setters

void AudioCD::SetArtist(string artist) { this->artist = artist; }
void AudioCD::SetTitle(string title) { this->title = title; }
void AudioCD::SetNumTracks(int numTracks) { this->numTracks = numTracks; }
void AudioCD::SetReleaseDate(string releaseDate) { this->releaseDate = releaseDate; }
void AudioCD::SetGenre(string genre) { this->genre = genre; }

//Getters
string AudioCD::GetArtist() const { return artist; }
string AudioCD::GetTitle() const { return title; }
int AudioCD::GetNumTracks() const { return numTracks; }
string AudioCD::GetReleaseDate() const { return releaseDate; }
string AudioCD::GetGenre() const { return genre; }

//Print AudioCD
void AudioCD::PrintInfo() const {
  cout << "Artist: " << artist << endl;
  cout << "Title: " << title << endl;
  cout << "Number of Tracks:" << numTracks << endl;
  cout << "Release Date: " << releaseDate << endl;
  cout << "Genre: " << genre << endl;
}
