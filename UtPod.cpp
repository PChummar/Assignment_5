#include "UtPod.h"
#include "song.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


UtPod::UtPod()
{
	memSize = MAX_MEMORY;
    songs = NULL;
    randFlag = 0;
}

UtPod::UtPod(int size)
{
	memSize = size;
    songs = NULL;
    randFlag = 0;

}

int UtPod::addSong(Song const &s){
	if (s.getSize() > (getRemainingMemory())){
		return -1;
	}
	else{
		SongNode* newNode = new SongNode;
		newNode->s = s;
		newNode->next = songs;
		songs = newNode;
	}
	return 0;
}

int UtPod::removeSong(Song const &s){
	SongNode *current;
	current = songs;
	if (current != NULL){ //makes sure the list is not empty
		//will execute if there is only one element in the list
		if(current->next == NULL){
			if(current->s == s){
				delete(current);
				songs = NULL;
				return 0;
			}
			else{
				return -1;
			}
		}
		//will execute if there are two or more elements in the list
		else{
			//checks the first element
			if(current->s == s){
				SongNode* temp = current;
				songs = current->next;
				delete(temp);
				return 0;
			}
			//executes if first element is not the element to be removed
			else{
				SongNode* previous = current;
				current = current->next;
				while(current != NULL){
					if(current->s == s){
						SongNode* temp = current;
						previous->next = current->next;
						delete(temp);
						return 0;
					}
					else{
						previous = current;
						current = current->next;
					}
				}
				return -1;
			}
		}
	}
	return -1;
}

void UtPod::swap(int first, int second){
	int firstIndex = 0;
	int secondIndex = 0;
	SongNode *firstPointer = songs;
	SongNode *secondPointer = songs;
	SongNode* current = songs;
	while(firstIndex != first){
		current = current->next;
		firstIndex++;
	}
	firstPointer = current;
	current = songs;
	while(secondIndex != second){
		current = current->next;
		secondIndex++;
	}
	secondPointer = current;
	Song tempSong = firstPointer->s;
	SongNode* tempPointer = firstPointer->next;
	firstPointer->s = secondPointer->s;
	secondPointer->s = tempSong;
	/*
	if (first != second){
		SongNode *firstPointer;
		SongNode *secondPointer;
		SongNode *thirdPointer;
		SongNode *fourthPointer;
		int firstCounter = 1;
		int secondCounter = 1;
		if(first == 0){
			firstPointer = songs;
			firstCounter = 0;
			SongNode* current = songs;
			while(firstCounter != (second - 1)) {
				current = current->next;
				firstCounter++;
			}
			secondPointer = current;
			thirdPointer = current->next;
			songs = thirdPointer;
			fourthPointer = thirdPointer->next;
			thirdPointer->next = secondPointer;
			secondPointer->next = firstPointer;
			firstPointer->next = fourthPointer;
			return;
		}
		if (second == 0){
			firstPointer = songs;
			firstCounter = 0;
			SongNode* current = songs;
			while(firstCounter != (first - 1)) {
				current = current->next;
				firstCounter++;
			}
			secondPointer = current;
			thirdPointer = current->next;
			songs = thirdPointer;
			fourthPointer = thirdPointer->next;
			thirdPointer->next = secondPointer;
			secondPointer->next = firstPointer;
			firstPointer->next = fourthPointer;
			return;
		}
		firstPointer = songs;
		secondPointer = firstPointer->next;
		while(firstCounter != first){
			firstPointer = secondPointer;
			secondPointer = secondPointer->next;
			firstCounter++;
		}
		thirdPointer = songs;
		fourthPointer = thirdPointer->next;
		while(secondCounter != second){
			thirdPointer = fourthPointer;
			fourthPointer = fourthPointer->next;
			secondCounter++;
		}
		SongNode *tempPointer = secondPointer->next;
		firstPointer->next = fourthPointer;
		secondPointer->next = fourthPointer->next;
		thirdPointer->next = secondPointer;
		fourthPointer->next = tempPointer;
	}
	 */
}


void UtPod::shuffle(){

	if(randFlag == 0){
		srand(time(NULL));
		randFlag = 1;
	}

	int numSongs = 0;
	SongNode *current = songs;
	while(current != NULL){
		numSongs++;
		current = current->next;
	}
	for (int i = 0; i < (numSongs*5); ++i)
	{
		int first = (rand() % numSongs);
		int second = (rand() % numSongs);
		swap(first, second);
	}
}


void UtPod::showSongList(){
	SongNode *current = songs;
	while(current != NULL){
		cout << current->s.getTitle() << ", " << current->s.getArtist() << ", " << current->s.getSize() << "MB" <<endl;
		//printf("%s, %s, %dMB\n", current->s.getTitle(), current->s.getArtist(), current->s.getSize());
		current = current->next;
	}
	cout <<endl;
}

void UtPod::sortSongList(){
	int numSongs = 0;
	SongNode *current = songs;
	while(current != NULL){
		numSongs++;
		current = current->next;
	}
	if (numSongs > 2){
		SongNode *leastPointer = songs;
		SongNode *firstPointer = songs;
		SongNode *secondPointer = songs->next;
		int firstIndex = 0;
		int secondIndex = 1;
		int leastIndex = 0;
		while(firstIndex < numSongs){
			leastIndex = firstIndex;
			leastPointer = firstPointer;
			secondPointer = firstPointer->next;
			secondIndex = firstIndex + 1;
			while(secondIndex < numSongs){
				if(secondPointer->s < leastPointer->s){
					leastIndex = secondIndex;
					leastPointer = secondPointer;
				}
				secondIndex++;
				secondPointer = secondPointer->next;
			}

				firstPointer = firstPointer->next;

			swap(firstIndex, leastIndex);
			firstIndex++;
		}
	}
}

void UtPod::clearMemory(){
	SongNode *firstPointer = songs;
	SongNode *secondPointer = songs;
	//songs = NULL;
	if(firstPointer != NULL){
		while(secondPointer != NULL){
			secondPointer = firstPointer->next;
			delete(firstPointer);
			firstPointer = secondPointer;
		}
	}
	songs = NULL;
}

int UtPod::getRemainingMemory(){
	SongNode *current = songs;
	int currentMemory = 0;
	while(current !=NULL){
		currentMemory += current->s.getSize();
		current = current->next;
	}
	return (memSize - currentMemory);
}

UtPod::~UtPod(){
	clearMemory();
}
