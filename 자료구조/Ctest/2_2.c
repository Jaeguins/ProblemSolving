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
void findAll();
void status();
void removes();
void removesAll();
void load(char*);
void export();
void import();
void removeTarget(int);
void save(char*);
int search(char*);
void searchAll(int loc[MAX_NUMOF_PEOPLE], char* name);
int main() {
    load(autoSave);
    while (1) interAct();
}
void interAct() {
    printf("$ ");
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    if (!strcmp(buffer, "add")) add();
    else if (!strcmp(buffer, "find")) find();
    else if (!strcmp(buffer, "findall")) findAll();
    else if (!strcmp(buffer, "status")) status();
    else if (!strcmp(buffer, "delete")) removes();
    else if (!strcmp(buffer, "deleteall")) removesAll();
    else if (!strcmp(buffer, "save")) export();
    else if (!strcmp(buffer, "read")) import();
    save(autoSave);
    if (!strcmp(buffer, "exit")) {
        exit();
    }
}
void import() {
    char* tFileName;
    scanf_s("%s", &tFileName, MAX_LENGTH_OF_COMMAND);
    load(tFileName);
}
void export() {
    char*tFileName;
    scanf_s("%s", &tFileName, MAX_LENGTH_OF_COMMAND);
    scanf_s("%s", &tFileName, MAX_LENGTH_OF_COMMAND);
    save(tFileName);
}
void save(char* fileName) {
    FILE *fp;
    errno_t err = fopen_s(&fp, fileName, "w");
    if (err != 0) {
        printf("Open failed.\n");
        return;
    }
    for (int i = 0; i < rear; i++) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}
void load(char* fileName) {
    FILE *fp;
    errno_t err = fopen_s(&fp, fileName, "r");
    if (err != 0) {
        printf("Open failed.\n");
        return;
    }
    while ((fscanf_s(fp, "%s ", buffer, MAX_LENGTH_OF_COMMAND) != EOF)) {
        int modified = 0;
        for (int i = 0; i < rear; i++) {
            if (!strcmp(buffer, names[i])) {
                names[i] = _strdup(buffer);
                fscanf_s(fp, "%s", &buffer, MAX_LENGTH_OF_COMMAND);
                numbers[i] = _strdup(buffer);
                modified = 1;
                break;
            }
        }
        if (!modified) {
            names[rear] = _strdup(buffer);
            fscanf_s(fp, "%s", &buffer, MAX_LENGTH_OF_COMMAND);
            numbers[rear] = _strdup(buffer);
            rear++;
        }
    }
    fclose(fp);
}
void add() {
    if (rear == MAX_NUMOF_PEOPLE) {
        printf("error : phonebook is full.\n");
        return;
    }
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int i = rear - 1;
    while (i >= 0 && strcmp(names[i], buffer) > 0) {
        names[i + 1] = names[i];
        numbers[i + 1] = numbers[i];
        i--;
    }
    names[i + 1] = _strdup(buffer);
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    numbers[i + 1] = _strdup(buffer);
    rear += 1;
    printf("%s was added successfully\n", names[i + 1]);
}
void find() {
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int index = search(buffer);
    if (index == -1) printf("No person names '%s' exists.\n", buffer);
    else printf("%s\n", numbers[index]);
}
void findAll() {
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int subInd[MAX_NUMOF_PEOPLE];
    searchAll(subInd, buffer);
    for (int i = 0; i < MAX_NUMOF_PEOPLE; i++) {
        if (subInd[i] != -1) {
            printf("%s %s\n", names[subInd[i]], numbers[subInd[i]]);
        }
        else {
            printf("%d people found\n", i);
            break;
        }
    }
}
void removeTarget(int index) {
    if (index == -1) {
        printf("No person named '%s' exists.\n", buffer);
        return;
    }
    char* tName=names[index];
    for (int j = index; j < rear - 1; j++) {
        names[j] = names[j + 1];
        numbers[j] = numbers[j + 1];
    }
    rear--;
    printf("'%s' was deleted successfully. \n", tName);
}
void removes() {
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int i;
    int index = search(buffer);
    /* returns -1 if not exists */
    removeTarget(index);
}
int search(char *name) {
    int i;
    for (i = 0; i < rear; i++) {
        if (!strcmp(name, names[i])) return i;
    }
    return -1;
}
void searchAll(int locs[MAX_NUMOF_PEOPLE], char* name) {
    int index = 0;
    for (int i = 0; i < rear; i++) {
        if (strstr(names[i], name) != NULL) locs[index++] = i;
    }
    locs[index] = -1;
}
void removesAll() {
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int i,buf[MAX_NUMOF_PEOPLE];
    searchAll(buf, buffer);
    for (int i = 0; buf[i]!=-1; i++) {
        removeTarget(buf[i]);
    }
}
void status() {
    for (int i = 0; i < rear; i++)
        printf("%s  %s\n", names[i], numbers[i]);
    printf("Total %d persons.\n", rear);
}