#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define INDEX_SIZE 10
#include <stdlib.h>
#include <string.h>

typedef struct song {
    Artist* artist;
    char* title;
    char* path;
    int index;
    Song* next;
}Song;

typedef struct library {
    Library* next;
    Library* prev;
    Song* song;
}Library;

typedef struct artist {
    char* name;
    Library* tail;
    Library* head;
    Artist* next;
}Artist;

void addArtist(Artist* artist);

void addSong(Artist* artist,Song* song);

void removeSongByIndex(int index);

Song* findSongByIndex(int index);

Artist* findArtistByName(char* name);

