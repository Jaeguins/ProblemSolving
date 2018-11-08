#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "library.h"
#include "string_tools.h"
#define BUFFER_LENGTH 100
char buffer[BUFFER_LENGTH];
char filePath[1000];


void enumerateSong(Artist* input) {
    Library* songPointer = input->head;
    if (songPointer != NULL) {
        Song* song = songPointer->song;
        printf("%2d : %s, %s, %s\n", song->index, song->artist, song->title, song->path);
    }
    while (songPointer->next != NULL) {
        Song* song = songPointer->song;
        printf("%2d : %s, %s, %s\n", song->index, song->artist, song->title, song->path);
        songPointer = songPointer->next;
    }

}

void handle_status() {
    for (int i = 0; i < 27; i++) {
        Artist* artistPointer = getArtistHead(i);
        if (artistPointer == NULL) {
            continue;
        }
        enumerateSong(artistPointer);
        while (artistPointer->next != NULL) {
            enumerateSong(artistPointer);
            artistPointer = artistPointer->next;
        }
    }
    printf("Done.\n");
}

void handle_add() {
    char tArtist[BUFFER_LENGTH];
    char tTitle[BUFFER_LENGTH];
    char tPath[BUFFER_LENGTH];
    printf("Artist : ");
    read_line(tArtist, BUFFER_LENGTH);
    if (strlen(tArtist) == 0) {
        printf("Empty artist unavailable.\n");
        return;
    }
    printf("Title : ");
    read_line(tTitle, BUFFER_LENGTH);
    if (strlen(tTitle) == 0) {
        printf("Empty title unavailable.\n");
        return;
    }
    printf("File : ");
    read_line(tPath, BUFFER_LENGTH);
    if (findArtistByName(tArtist) == NULL) {
        addArtist(initArtist(tArtist));
    }
    addSong(findArtistByName(tArtist), initSong(tTitle, tPath, *getCap()));
    *getCap() = *getCap() + 1;
}

void handle_search() {

}

void handle_play(int index) {

}

void handle_remove(int index) {

}

void handle_save(char* mod, char* path) {
    if (strcmp(mod, "as")==0) writeList(path);
}

void process_command() {
    char command_line[BUFFER_LENGTH];
    char copied[BUFFER_LENGTH];
    char *command, *arg1, *arg2;
    printf("which save list do you want to? : ");
    read_line(filePath,1000);
    readList(filePath);
    while (1) {
        printf("$ ");
        if (read_line(command_line, BUFFER_LENGTH) <= 0)
            continue;
        strcpy(copied, command_line);
        command = strtok(command_line, " ");
        if (strcmp(command, "status") == 0) {
            handle_status();
        }
        else if (strcmp(command, "play") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            int index = atoi(arg1);
            handle_play(index);
        }
        else if (strcmp(command, "remove") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            int index = atoi(arg1);
            handle_remove(index);
        }

        else if (strcmp(command, "add") == 0) {
            handle_add();
        }
        else if (strcmp(command, "search") == 0) {
            handle_search();
        }
        else if (strcmp(command, "save") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            else if (strcmp(arg1, "as")==0) {
                arg2 = strtok(NULL, " ");
                if (arg2 == NULL) {
                    printf("Invalid arguments.\n");
                    continue;
                }
                handle_save(arg1, arg2);
            }
            else handle_save(NULL, arg1);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("\nProgram terminated.\n");
            exit(0);
        }
    }
}

int main() {
    process_command();
}