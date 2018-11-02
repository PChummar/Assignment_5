#include "song.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Song::Song(){
	this->title = " ";
	this->artist = " ";
	this->size = 0;
}

Song::Song(string artist, string title, int size) {
	this->title = title;
	this->artist = artist;
	this->size = size;
}

string Song::getTitle() const{
	return title;
}

string Song::getArtist() const{
	return artist;
}

int Song::getSize() const{
	return size;
}

bool Song::operator >(Song const &rhs){
	bool result = false;
	if(artist > rhs.artist){
		return true;
	}
	else if(artist == rhs.artist){
		if(title > rhs.title){
			return true;
		}
		else if(title == rhs.title){
			if(size > rhs.size){
				return true;
			}
			else if(size == rhs.size){
				return false;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}
}

bool Song::operator <(Song const &rhs){
	bool result = false;
	if(artist < rhs.artist){
		return true;
	}
	else if(artist == rhs.artist){
		if(title < rhs.title){
			return true;
		}
		else if(title == rhs.title){
			if(size < rhs.size){
				return true;
			}
			else if(size == rhs.size){
				return false;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}	
}

bool Song::operator ==(Song const &rhs){
	return ((artist == rhs.artist) && (title == rhs.title) &&(size == rhs.size));
}

Song & Song::operator=(const Song &rhs){
	artist = rhs.artist;
	title = rhs.title;
	size = rhs.size;
	return *this;
}

void Song::setArtist(string artist){
    this->artist = artist;
}

void Song::setTitle(string title) {
    this->title = title;
}

void Song::setSize(int size) {
    this->size = size;
}