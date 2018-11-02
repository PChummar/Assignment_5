/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod testPod;
    cout << "Prints default size (should be 512): " << testPod.getRemainingMemory() << endl;

    UtPod testPod2(400);
    cout << "Prints size of testPod2 (should be 400 as allocated in the constructor): " <<testPod2.getRemainingMemory() << endl;

    Song s1;
    cout << "Prints title, artist, and size, as designated by the default constructor (should be blank, blank, and 0 respectively): " << s1.getTitle() << ", " << s1.getArtist() << ", " <<s1.getSize() <<endl;

    Song s2("The Beatles", "A Day In The Life", 20);
    int result = testPod2.addSong(s2);
    cout << "result = " << result << endl;
    cout << "Prints title, artist, and size, as designated by the user in the constructor: ";
    testPod2.showSongList();

    Song s3("Drake", "Headlines", 514);
    result = testPod2.addSong(s3);
    cout << "Attempts to add a song larger than the available memory, should return a -1: " << result << endl;

    Song s4("Prince", "Purple Rain", 12);
    Song s5("Prince", "When Doves Cry", 13);
    Song s6("Prince", "Purple Rain", 25);
    Song s7("Eminem", "Stan", 10);
    Song s8("Bob Dylan", "Like A Rolling Stone", 10);
    Song s9("Lil Pump", "I Love It", 10);
    testPod2.addSong(s4);
    testPod2.addSong(s5);
    testPod2.addSong(s6);
    testPod2.addSong(s7);
    testPod2.addSong(s8);
    testPod2.addSong(s9);

    cout << "Shows song list with added songs: " <<endl;
    testPod2.showSongList();
    testPod2.removeSong(s9);
    cout << "Tests ability to remove songs (should print same list without the 9th song added): " <<endl;
    testPod2.showSongList();
    testPod2.sortSongList();
    cout << "Tests ability to sort by artist, title, and size, in that order: " <<endl;
    testPod2.showSongList();

    testPod2.shuffle();
    cout << "Tests shuffle function (run program multiple times to see that it shuffles differently each time): " <<endl;
    testPod2.showSongList();
    cout << "Tests ability to calculate memory being used: " << testPod2.getRemainingMemory() << "MB" << endl;
    testPod2.clearMemory();
    cout << "Tests ability to clear memory (should print nothing): " <<endl;
    testPod2.showSongList();
    testPod2.addSong(s2);
    cout << "Adds another song and shows the list again: " <<endl;
    testPod2.showSongList();

    /*
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
          
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    
    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    result = t.addSong(s4);
    cout << "add result = " << result << endl;
    result = t.addSong(s1);
    cout << "add result = " << result << endl;
    result = t.addSong(s2);
    cout << "add result = " << result << endl;
    Song s6("Kanye West", "Power", 13);
    Song s7("Prince", "Purple Rain", 13);
    Song s8("New Order", "Blue Monday", 11);
    Song s9("Prince", "When Doves Cry", 40);
    Song s10("Prince", "When Doves Cry", 2);
    t.addSong(s6);
    t.addSong(s7);
    t.addSong(s8);
    t.addSong(s9);
    t.addSong(s10);
    t.showSongList();
    t.shuffle();
    t.showSongList();
     */
}