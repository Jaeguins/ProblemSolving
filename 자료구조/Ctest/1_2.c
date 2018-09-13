#define MAX_LEN 20//�ִ� �ܾ� ����
#define MAX_NUM 10000//�ִ� �ܾ� ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char buffer[MAX_LEN];
char grid[MAX_NUM][MAX_LEN];
int len = 0;
void read_dictionary() {//���� �Է� - 1������ �ŰܿԽ��ϴ�. 6�� �̸� ���͸�/�ҹ���ȭ�� �������� �Դϴ�.
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
                //counter[k] += 1;- 1�������� ���� ī��Ʈ
                isDup = 1;
            }
        }
        if (isDup) {
            continue;
        }
        if (strlen(grid[i]) >= 6) {
            //counter[i] = 1; - 1�������� ���� ī��Ʈ
            i++;
        }
    }
    len = i;
    fclose(fp);
}
int main()
{
    read_dictionary();
    srand(time(NULL));
    while (1) {//�Ѱ���
        int number = rand() % len, count = 0, tryCount = 1;
        char k = '\0';
        char shown[MAX_LEN] = { 0 };
        while (tryCount > 0) {//�Է� �ѹ�
            system("cls");
            printf("Try %d :\n", tryCount++);
            for (int i = 0; i < strlen(grid[number]); i++) {//���
                if (shown[i] == 0 && grid[number][i] != k) {
                    printf("*");
                }
                else printf("%c", grid[number][i]);
                if (grid[number][i] == k && shown[i] == 0) {
                    shown[i] = 1;
                    count += 1;
                }
            }
            printf("\n");
            if (strlen(grid[number]) == count) {//���� ���� ��
                printf("Try again? (y to try another game)\n");
                scanf_s(" %c", &k);//�Է�
                if (k == 'y') {//�����
                    break;
                }
                else {//����
                    printf("Game Over. Thanks for playing.");
                    getchar();
                    getchar();
                    return;
                }
            }
            else scanf_s(" %c", &k);
        }
    }
    return 0;
}