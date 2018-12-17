#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORD_LENGTH 100
#define MAX_IGNORE_NUMBER 100

typedef struct Node {
    void* before;
    void* next;
    char data[MAX_WORD_LENGTH];
    int count;
}Node;
void addWord(char* word);
char isInIgnore(char* word);
void printAll();
int ignoreNum = 0;
Node *word_list[27];
char ignoreField[MAX_IGNORE_NUMBER][MAX_WORD_LENGTH];
int main() {
    FILE *harry, *ignore;
    fopen_s(&harry, "harry.txt", "r");
    fopen_s(&ignore, "ignore_5_1.txt", "r");
    char buffer[MAX_WORD_LENGTH];
    while (fscanf_s(ignore, "%s ", &buffer, MAX_WORD_LENGTH) != EOF) {
        strcpy_s(ignoreField[ignoreNum++], MAX_WORD_LENGTH, _strdup(buffer));
    }
    while (fscanf_s(harry, "%s ", &buffer, MAX_WORD_LENGTH) != EOF) {
        if (strlen(buffer) > 2 && !isInIgnore(buffer)) {
            addWord(buffer);
        }
    }
    printAll();
    getchar();
    getchar();
}
char isInIgnore(char* word) {
    int count = 0;
    while (count++ < ignoreNum) {
        if (strcmp(ignoreField[count], word) == 0)return 1;
    }
    return 0;
}
void addWord(char* word) {
    char head = *word - 'a';
    if (word_list[head] == NULL) {
        word_list[head] = malloc(sizeof(Node));
        strcpy_s(word_list[head]->data, MAX_WORD_LENGTH, _strdup(word));
        word_list[head]->count = 1;
        word_list[head]->before = NULL;
        word_list[head]->next = NULL;
        return;
    }
    Node* pointer = word_list[head];
    while (1) {
        Node* tNode;
        if (strcmp(pointer->data, word) == 0) {
            pointer->count += 1;
            break;
        }
        else if (strcmp(pointer->data, word) > 0) {
            tNode = (Node*)malloc(sizeof(Node));
            strcpy_s(tNode->data, MAX_WORD_LENGTH, _strdup(word));
            tNode->count = 1;
            if ((Node*)pointer->before == NULL) {
                tNode->before = NULL;
                tNode->next = pointer;
                pointer->before = tNode;
                word_list[head] = tNode;
            }
            else
            {
                ((Node*)pointer->before)->next = tNode;
                tNode->before = pointer->before;
            }
            tNode->next = pointer;
            pointer->before = tNode;
            break;
        }
        else if (strcmp(pointer->data, word) < 0) {
            if (pointer->next == NULL) {
                tNode = (Node*)malloc(sizeof(Node));
                strcpy_s(tNode->data, MAX_WORD_LENGTH, _strdup(word));
                tNode->count = 1;
                pointer->next = tNode;
                tNode->before = pointer;
                tNode->next = NULL;
                break;
            }
            else {
                pointer = (Node*)pointer->next;
            }
        }
    }
}
void printAll() {
    for (int i = 0; i < 27; i++) {
        Node* tWord = word_list[i];
        while (tWord != NULL) {
            printf("%s : %d\n", tWord->data, tWord->count);
            tWord = tWord->next;
        }
    }
}