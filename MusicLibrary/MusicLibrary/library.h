#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define INDEX_SIZE 10
#define MAX_BUFFER_LENGTH 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getCap();
struct library;
typedef struct artist {
    char* name;
    struct library* tail;
    struct library* head;
    struct artist* next;
}Artist;

typedef struct song {
    Artist* artist;
    char* title;
    char* path;
    int index;
    struct song* next;
}Song;

typedef struct library {
    struct library* next;
    struct library* prev;
    Song* song;
}Library;


void addArtist(Artist* artist);

void addSong(Artist* artist,Song* song);

Song* removeSongByIndex(int index);

Song* findSongByIndex(int index);

Artist* findArtistByName(char* name);

void readList(char* path);

void writeList(char* path);

Artist* getArtistHead(int i);

Artist* initArtist(char* name);

Song* initSong(char* title, char* path, int index);

void playSongByIndex(int index);