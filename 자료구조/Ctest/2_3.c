#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 50
#define MAX_WORD_PER_LINE 80
#define CHARACTER_PER_LINE 40
char line[80][50];
int main() {
    FILE *read, *write;
    char buffer[MAX_WORD_LENGTH];
    fopen_s(&read, "harry.txt", "r");
    fopen_s(&write, "aligned.txt", "w");
    int wInd = 0, lLength = 0;
    while (fscanf_s(read, "%s ", &buffer, MAX_WORD_LENGTH) != EOF) {
        if (lLength+strlen(buffer) > CHARACTER_PER_LINE-wInd) {
            for (int i = 0; i < wInd-1; i++) {
                fprintf(write,"%s ", line[i]);
            }
            fprintf(write,line[wInd - 1]);
            fprintf(write,"\n");
            wInd = 0;
            lLength = 0;
        }
        lLength += strlen(buffer);
        strcpy_s(line[wInd++], 50, buffer);
    }
    for (int i = 0; i < wInd; i++) {
        fprintf(write, "%s", line[i]);
        fprintf(write, " ");
    }
    fclose(read);
    fclose(write);
    getchar();
    getchar();
}