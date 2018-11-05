#include "library.h"


Artist* artist_directory[27];
Library* index_directory[INDEX_SIZE];

Song* initSong(char* title, char* path, int index) {
    Song* ret = (Song*)malloc(sizeof(Song));
    strcpy(ret->title, title);
    strcpy(ret->path,path);
    ret->index = index;
    return ret;
}

Library* initLibrary(Song* song) {
    Library* ret = (Library*)malloc(sizeof(Library));
    ret->next = NULL;
    ret->prev= NULL;
    ret->song = song;
    return ret;
}

Artist* initArtist(char* name) {
    Artist* ret = (Artist*)malloc(sizeof(Artist));
    strcpy(ret->name, name);
    ret->tail = NULL;
    ret->head = NULL;
    ret->next = NULL;
    return ret;
}

void addSong(Artist* artist, Song* song) {
    Library* artistLib = initLibrary(song);
    Library* pointer = artist->head;
    if (pointer == NULL) {
        artist->head = artistLib;
        artist->tail = artistLib;
        return;
    }
    while(1)
    if (pointer->next==NULL||strcmp(artistLib->song->title, pointer->next->song->title) > 0) {//TODO can be changed
        if (pointer->next != NULL) {
            artistLib->next = pointer->next;
            pointer->next->prev = artistLib;
        }
        pointer->next = artistLib;
        artistLib->prev = pointer;
        artist->tail = artistLib;
        break;
    }
    else pointer = pointer->next;

    Library* indexLib = initLibrary(song);
    Library* pointer = index_directory[song->index%INDEX_SIZE];
    if (pointer == NULL) index_directory[song->index%INDEX_SIZE] = indexLib;
    else {
        while (pointer->next != NULL)pointer = pointer->next;
        pointer->next = indexLib;
    }
}

void addArtist(Artist* artist) {
    int index = (artist->name)[0] - 'a';
    Artist* pointer = artist_directory[index];
    if (pointer== NULL) {
        artist_directory[index] = artist;
        return;
    }
    while (1)
        if (pointer->next == NULL || strcmp(artist->name,pointer->next->name) > 0) {//TODO can be changed
            if (pointer->next != NULL) artist->next = pointer->next;
            pointer->next = artist;
            break;
        }
        else pointer = pointer->next;
}

Song* findSongByIndex(int index) {
    Library* pointer = index_directory[index%INDEX_SIZE];
    if (pointer == NULL)return NULL;
    do {
        if (pointer->song->index == index)return pointer->song;
        if (pointer->next == NULL)return NULL;
        pointer = pointer->next;
    } while (1);
}

Song* popSongByIndex(int index) {
    Library* pointer = index_directory[index%INDEX_SIZE];
    Library* prev = NULL;
    if (pointer == NULL)return NULL;
    do {
        if (pointer->song->index == index) {
            if(prev!=NULL)prev->next = pointer->next;
            Song* ret = pointer->song;
            free(pointer);
            return ret;
        }
        if (pointer->next == NULL)return NULL;
        prev = pointer;
        pointer = pointer->next;
    } while (1);
}

Artist* findArtistByName(char* name) {
    int index = name[0] - 'a';
    Artist* pointer = artist_directory[index];
    if (pointer == NULL) return NULL;
    while (pointer!=NULL) {
        if (strcmp(pointer->name, name) == 0) {
            return pointer;
        }
        else pointer = pointer->next;
    }
    return NULL;
}

void removeSongByIndex(int index) {
    Song* song = popSongByIndex(index);
    Artist* artist=findArtistByName(song->artist->name);
    Library* pointer = artist->head;
    while (pointer != NULL) {
        if (pointer->song->index == song->index) {
            pointer->next->prev = pointer->prev;
            pointer->prev->next = pointer->next;
            free(pointer);
            free(song);
            return;
        }
        else pointer = pointer->next;
    }
}