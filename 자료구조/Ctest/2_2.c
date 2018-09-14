#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 20
#define MAX_NUMOF_PEOPLE 20
#define MAX_LENGTH_OF_COMMAND 100
char buffer[MAX_LENGTH_OF_COMMAND];
char* names[MAX_NUMOF_PEOPLE];
char* numbers[MAX_NUMOF_PEOPLE];
char* autoSave = "phonebooks.txt";
int rear = 0;
void interAct();
void add();
void find();
void status();
void delete();
void load(char* fileName);
void export();
void import();
void save(char* fileName);
void sort();
int main() {
    load(autoSave);
    while (1) interAct();
}
void interAct() {
    printf("$ ");
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    if (!strcmp(buffer, "add")) add();
    else if (!strcmp(buffer, "find")) find();
    else if (!strcmp(buffer, "status")) status();
    else if (!strcmp(buffer, "delete")) delete();
    else if (!strcmp(buffer, "save")) export();
    else if (!strcmp(buffer, "read")) import();
    save(autoSave);
    if (!strcmp(buffer, "exit")) {
        exit();
    }
}
void import() {
    char* tFileName;
    scanf_s("%s", tFileName, MAX_LENGTH_OF_COMMAND);
    load(tFileName);
}
void export() {
    char*tFileName;
    scanf_s("%s", tFileName, MAX_LENGTH_OF_COMMAND);
    scanf_s("%s", tFileName, MAX_LENGTH_OF_COMMAND);
    save(tFileName);
}
void save(char* fileName) {
    FILE *fp;
    fopen_s(fp, fileName, "w");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    for (int i = 0; i < rear; i++) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}
void load(char* fileName) {
    char* buf1;
    char* buf2;
    FILE *fp;
    fopen_s(fp, *fileName, "r");
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    while ((fscanf_s(fp, "%s", buf1, MAX_LENGTH_OF_COMMAND) != EOF)) {
        int modified = 0;
        for (int i = 0; i < rear; i++) {
            if (!strcmp(buf1, names[i])) {
                fscanf_s(fp, "%s", buf2, MAX_LENGTH_OF_COMMAND);
                numbers[i] = strdup(buf2);
                modified = 1;
                break;
            }
        }
        if (modified) {
            fscanf(fp, "%s", buf2);
            names[rear] = strdup(buf1);
            numbers[rear] = strdup(buf2);
            rear++;
        }
    }
    fclose(fp);
}
void add() {
    if (rear == MAX_NUMOF_PEOPLE) {
        printf("error : phonebook is full.");
        return;
    }
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int i = rear - 1;
    while (i >= 0 && strcmp(names[i], names[rear]) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = strdup(buffer);
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    numbers[i + 1] = strdup(buffer);
    rear += 1;
    printf("%s was added successfully", names[rear - 1]);
}
void find() {
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int index = search(buffer);
    if(index==-1) printf("No person names '%s' exists.\n", buffer);
    else printf("%s\n", numbers[index]);
}
void status() {
    for (int i = 0; i < rear; i++)
        printf("%s %s\n", names[i], numbers[i]);
    printf("Totla %d person(people).\n", rear);
}
void remove() {
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int i;
    int index = search(buffer);
    /* returns -1 if not exists */
    if (index == -1) {
        printf("No person named '%s' exists.\n", buffer);
        return;
    }
    for (int j = index; j < rear - 1; j++) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }
    rear--;
    printf("'%s' was deleted successfully. \n", buffer);
}