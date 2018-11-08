#include "library.h"
#include "string_tools.h"
int lastIndex=0;
Artist* artist_directory[27];
Library* index_directory[INDEX_SIZE];
Artist* getArtistHead(int i) {
    return artist_directory[i];
}
int* getCap() {
    return &lastIndex;
}
Song* initSong(char* title, char* path, int index) {
    Song* ret = (Song*)malloc(sizeof(Song));
    ret->title = (char*)malloc(sizeof(char)*strlen(title));
    ret->path= (char*)malloc(sizeof(char)*strlen(path));
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
    ret->name = (char*)malloc(strlen(name) * sizeof(char));
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
    }else while(1)
    if (pointer->next==NULL||strcmp(artistLib->song->title, pointer->next->song->title) > 0) {//TODO can be changed
        if (pointer->next != NULL) {
            artistLib->next = pointer->next;
            pointer->next->prev = artistLib;
        }
        pointer->next = artistLib;
        artistLib->prev = pointer;
        artist->tail = artistLib;
        break;
    }else pointer = pointer->next;

    Library* indexLib = initLibrary(song);
    pointer = index_directory[song->index%INDEX_SIZE];
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

void readList(char* Fpath) {
    if (strlen(Fpath) == 0) return;
    FILE* f;
    f =fopen(Fpath, "r");
    if (f == NULL) {
        return;
    }
    char buffer[MAX_BUFFER_LENGTH];
    while (read_file_line(f,buffer,MAX_BUFFER_LENGTH) != EOF) {
        int num=atoi(strtok(buffer, "|"));
        char* artist= strtok(NULL, "|");
        char* title = strtok(NULL, "|");
        char* path = strtok(NULL, "|");
        char* tPath=NULL;
        //strcpy(tPath,path);
        /*char* tArtist = strtok(path, "/"),*tName=strtok(NULL,"/"), *tBuffer=strtok(NULL,"/");
        while (strlen(tBuffer)!=0) {
            free(tArtist);
            tArtist = tName;
            tName = tBuffer;
            tBuffer = strtok(NULL, "/");
        }*/
        if (findArtistByName(artist) == NULL) {
            addArtist(initArtist(artist));
        }
        addSong(findArtistByName(artist), initSong(title, path, lastIndex++));
    }
    fclose(f);
}

void writeList(char* Fpath) {
    FILE* f;
    f = fopen(Fpath, "w");
    Song* tSong=NULL;
    for (int i = 0; i < lastIndex; i++) {
        tSong = findSongByIndex(i);
        fprintf(f, "%d|%s\n", tSong->index, tSong->path);
   }
    fclose(f);
}

