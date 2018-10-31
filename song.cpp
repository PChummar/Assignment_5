#include "Song.h"	
#include <iostream>
using namespace std;

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
			if(length > rhs.length){
				return true;
			}
			else if(length == rhs.length){
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
			if(length < rhs.length){
				return true;
			}
			else if(length == rhs.length){
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
	return ((artist == rhs.artist) && (title == rhs.title) &&(length == rhs.length));
}