#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <string>
 using namespace std;
class Song
{
	private:
		string artist;
		string title;
		int size;

	public:
        //Default constructor for Song, sets artist and title to a space, and size to 0
		Song();
        //Constructor for Song, sets title, artist, and size to user given input
        Song(string artist, string title, int size);
        //overwrites ==, <, and > operators to compare songs by artist, title, and size, in that order
        bool operator ==(Song const &rhs);
        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        //overwrites assignment operator to properly copy the data of one song to another
        Song & operator=(const Song &rhs);
        //these methods return the title, artist, and size of a song respectively
        string getTitle() const;
        string getArtist() const;
        int getSize() const;
        void setTitle(string title);
        void setArtist(string artist);
        void setSize(int size);
};

#endif