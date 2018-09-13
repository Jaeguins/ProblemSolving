#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 50
#define MAX_WORD_PER_LINE 80
#define CHARACTER_PER_LINE 80
char line[80][50];
int main() {
    FILE *read, *write;
    char buffer[MAX_WORD_LENGTH];
    fopen_s(&read, "harry.txt", "r");
    fopen_s(&write, "aligned.txt", "w");
    int wInd = 0, lLength = 0;
    while (fscanf_s(read, "%s ", &buffer, MAX_WORD_LENGTH) != EOF) {
        lLength += strlen(buffer) + 1;
        if (lLength > CHARACTER_PER_LINE) {
            for (int i = 0; i < wInd; i++) {
                fprintf(write,"%s", line[i]);
                fprintf(write," ");
            }
            wInd = 0;
            lLength = strlen(buffer)+1;
            fprintf(write,"\n");
        }
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