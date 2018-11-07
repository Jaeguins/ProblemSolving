#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "library.h"
#include "string_tools.h"
#define BUFFER_LENGTH 100
char buffer[BUFFER_LENGTH];

void process_command() {
    char command_line[BUFFER_LENGTH];
    char copied[BUFFER_LENGTH];
    char *command, *arg1, *arg2;
    printf("which save list do you want to? : ");
    char* fPath=NULL;
    scanf("%s", fPath);
    readList(fPath);
    while (1) {
        printf("$ ");
        if (read_line(command_line, BUFFER_LENGTH) <= 0)
            continue;
        strcpy(copied, command_line);
        command = strtok(command_line, " ");
        if (strcmp(command, "print") == 0) {
            arg1 = strtok(NULL, " ");
            if (arg1 == NULL) {
                printf("Invalid arguments.\n");
                continue;
            }
            //TODO specify handle functions
        }
    }
}

void handle_add() {

}
int main() {
    process_command();
}