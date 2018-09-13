#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 20//최대 단어 길이
#define MAX_NUM 100000//최대 단어 수
#define WORDS_PER_LINE 5//줄당 출력 단어 수
#define ASCENDING 1//오름차순 정렬 - 1일시 오름차순, 0일시 내림차순 정렬 (디버깅용 단어 리스트를 오름차순 된걸로 가져와서 따로 만들어 두었습니다.)
#include <stdio.h>
#include <string.h>

char buffer[MAX_LEN];
char grid[MAX_NUM][MAX_LEN];
int counter[MAX_NUM] = { 0 };
int len = 0;
char alphabetic(char subject[MAX_LEN], char object[MAX_LEN]) {// 알바벳순 확인
    for (int i = 0; i < MAX_LEN; i++) {
        int a = subject[i], b = object[i];
        if (a > b || b == '\0')return ASCENDING;//subject is later
        if (a < b || a == '\0')return !ASCENDING;//object is later
    }
    return -1;
}
void insertionSort(int begin, int end) {//삽입정렬
    for (int i = begin + 1; i <= end; i++) {
        int counterBuf = counter[i];
        for (int k = 0; k < MAX_LEN; k++) {
            buffer[k] = grid[i][k];
        }
        int j;
        for (j = i; j > begin&&alphabetic(grid[j - 1], buffer) > 0; j--) {
            for (int k = 0; k < MAX_LEN; k++) {
                grid[j][k] = grid[j - 1][k];
            }
            counter[j] = counter[j - 1];
        }
        if (i != j) {
            for (int k = 0; k < MAX_LEN; k++) {
                grid[j][k] = buffer[k];
                counter[j] = counterBuf;
            }
        }
    }
}
void out(char target[MAX_NUM][MAX_LEN], int len) {//출력
    FILE *fp;
    fopen_s(&fp, "out.txt", "w");
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            if (target[i][j] != '\0') {
                printf("%c", target[i][j]);
                fprintf(fp, "%c", target[i][j]);
            }
            else break;
        }
        fprintf(fp, " %d ", counter[i]);
        printf(" %d ", counter[i]);
        if (i%WORDS_PER_LINE == WORDS_PER_LINE - 1) {
            printf("\n");
            fprintf(fp,"\n");
        }
    }
    fclose(fp);
}
void read_dictionary() {//입력 - 6자 미만 입력은 필터링, 대소문자는 관련없이(역시 디버깅용 단어 리스트 때문에 구현하였습니다.)
    FILE*  fp;
    fopen_s(&fp, "harry.txt", "r");
    int  i = 0;
    while (fscanf_s(fp, "%s ", grid[i], MAX_LEN) != EOF) {
        for (int k = 0; k < strlen(grid[i]); k++) {
            if (grid[i][k] >= 'A'&&grid[i][k] <= 'Z')grid[i][k] = grid[i][k] - 'A' + 'a';
        }
        int isDup = 0;
        for (int k = 0; k < i - 1; k++) {
            if (strcmp(grid[i], grid[k]) == 0) {
                counter[k] += 1;
                isDup = 1;
            }
        }
        if (isDup) {
            continue;
        }
        if (strlen(grid[i]) >= 6) {
            counter[i] = 1;
            i++;
        }
    }
    len = i;
    fclose(fp);
}
int main()
{
    read_dictionary();
    insertionSort(0, len);
    out(grid, len);
    getchar();
    getchar();
    return 0;
}