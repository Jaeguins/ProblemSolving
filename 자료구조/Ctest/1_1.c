#define _CRT_SECURE_NO_WARNINGS
#define MAX_LEN 20//�ִ� �ܾ� ����
#define MAX_NUM 100000//�ִ� �ܾ� ��
#define WORDS_PER_LINE 5//�ٴ� ��� �ܾ� ��
#define ASCENDING 1//�������� ���� - 1�Ͻ� ��������, 0�Ͻ� �������� ���� (������ �ܾ� ����Ʈ�� �������� �Ȱɷ� �����ͼ� ���� ����� �ξ����ϴ�.)
#include <stdio.h>
#include <string.h>

char buffer[MAX_LEN];
char grid[MAX_NUM][MAX_LEN];
int counter[MAX_NUM] = { 0 };
int len = 0;
char alphabetic(char subject[MAX_LEN], char object[MAX_LEN]) {// �˹ٺ��� Ȯ��
    for (int i = 0; i < MAX_LEN; i++) {
        int a = subject[i], b = object[i];
        if (a > b || b == '\0')return ASCENDING;//subject is later
        if (a < b || a == '\0')return !ASCENDING;//object is later
    }
    return -1;
}
void insertionSort(int begin, int end) {//��������
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
void out(char target[MAX_NUM][MAX_LEN], int len) {//���
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
void read_dictionary() {//�Է� - 6�� �̸� �Է��� ���͸�, ��ҹ��ڴ� ���þ���(���� ������ �ܾ� ����Ʈ ������ �����Ͽ����ϴ�.)
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