#include <stdio.h>
#include <string.h>
#define MAX_NAME_LENGTH 20 //이름 최대길이
#define MAX_NUMOF_PEOPLE 20 //최대 사람수
#define MAX_LENGTH_OF_COMMAND 100 // 최대 명령어(버퍼)길이
char buffer[MAX_LENGTH_OF_COMMAND];
char* names[MAX_NUMOF_PEOPLE];
char* numbers[MAX_NUMOF_PEOPLE];
char* autoSave = "phonebooks.txt";//자동저장용 파일명
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
int main() {//메인함수
    load(autoSave);//자동저장 불러오기
    while (1) interAct();
}
void interAct() {//소통 함수
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
    save(autoSave);//명령어 하나마다 자동저장
    if (!strcmp(buffer, "exit")) {
        exit();
    }
}
void import() {//들여오기
    char* tFileName;
    scanf_s("%s", &tFileName, MAX_LENGTH_OF_COMMAND);
    load(tFileName);
}
void export() {//다른이름으로 저장
    char*tFileName;
    scanf_s("%s", &tFileName, MAX_LENGTH_OF_COMMAND);
    scanf_s("%s", &tFileName, MAX_LENGTH_OF_COMMAND);
    save(tFileName);
}
void save(char* fileName) {//특정 이름으로 저장
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
void load(char* fileName) {//불러오기
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
void add() {//추가
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
void find() {//탐색
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int index = search(buffer);
    if (index == -1) printf("No person names '%s' exists.\n", buffer);
    else printf("%s\n", numbers[index]);
}
void findAll() {//전체탐색
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
void removeTarget(int index) {//해당 인덱스 제거
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
void removes() {//단일 대상 제거
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int i;
    int index = search(buffer);
    /* returns -1 if not exists */
    removeTarget(index);
}
int search(char *name) {//인덱스 검색
    int i;
    for (i = 0; i < rear; i++) {
        if (!strcmp(name, names[i])) return i;
    }
    return -1;
}
void searchAll(int locs[MAX_NUMOF_PEOPLE],char* name) {//인덱스 다중 검색(locs로 반환)
    int index = 0;
    for (int i = 0; i < rear; i++) {
        if (strstr(names[i], name) != NULL) locs[index++] = i;
    }
    locs[index] = -1;
}
void removesAll() {//여러 대상 제거
    scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
    int i,buf[MAX_NUMOF_PEOPLE],delCounter=0;
    searchAll(buf, buffer);
    for (int i = 0; buf[i]!=-1; i++) {
        printf("Are you sure to delete %s?", names[buf[i - delCounter]]);
        scanf_s("%s", buffer, MAX_LENGTH_OF_COMMAND);
        if (!strcmp(buffer, "yes")) {
            removeTarget(buf[i - delCounter]);
            delCounter += 1;
        }
    }
}
void status() {//상태 출력
    for(int i =0; i < rear; i++)
        printf("%s  %s\n", names[i], numbers[i]);
    printf("Total %d persons.\n", rear);
}