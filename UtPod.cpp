#include "UtPod.h"
#include "Song.h"

#include <iostream>
#include <cstdlib>
using namespace std;

UtPod::UtPod()
{
	memSize = MAX_MEMORY;
}

UtPod::UtPod(int size)
{
	memSize = size;
}

int UtPod::addSong(Song const &s){
	if (s->songSize > (MAX_MEMORY - memSize)){
		return -1;
	}
	else{
		int size = s.getSize();
		memSize += size;
		SongNode temp = new SongNode;
		temp->Song = s;
		SongNode *tempPointer = this->songs;
		temp->next = tempPointer;
		songs = &temp;
	}
	return 0;
}

int UtPod::removeSong(Song const &s){
	SongNode *current;
	current = songs;
	if (current != NULL){
		if(current->s == s){
			SongNode *temp = songs;
			songs = current->next;
			delete(temp);
			return 0;
		}
		else{
			if(current->next == NULL){
				return -1;
			}
			else{
				SongNode *previous = current;
				current = previous->next;
				while(current->next != NULL){
					if(current->s == s){
						SongNode *deletePointer = current;
						previous->next = current;
						delete(deletePointer);
						return 0;
					}
					previous = current;
					current = current->next;
				}
				if(current->s == s){
					SongNode *deletePointer = current;
					previous->next = current;
					delete(deletePointer);
					return 0;
				}
			}
		}
		return -1;
	}	
	else{
		return -1;
	}
}

void UtPod::swap(int first, int second){
	if (first != second){
		SongNode *firstPointer;
		SongNode *secondPointer;
		SongNode *thirdPointer;
		SongNode *fourthPointer;
		int firstCounter = 1;
		int secondCounter = 1;
		if(first == 0){

			return;
		}
		if (second == 0){

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
}

void UtPod::shuffle(){
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
		printf("%s, %s, %dMB\n", current->s.getTitle(), current->s.getArtist(), current->s.getSize());
	}
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
			swap(firstIndex, leastIndex);
			firstIndex++;
			firstPointer = firstPointer->next;
		}
	}
}

void UtPod::clearMemory(){
	SongNode *firstPointer = songs;
	SongNode *secondPointer = songs;
	if(songs != NULL){
		while(secondPointer != NULL){
			secondPointer = firstPointer->next;
			delete(firstPointer);
			firstPointer = secondPointer;
		}
	}
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

~UtPod(){
	clearMemory();
	
}
