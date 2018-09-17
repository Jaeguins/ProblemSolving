#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 50
#define MAX_WORD_PER_LINE 80
#define CHARACTER_PER_LINE 80
char line[80][50];
int main() {
    FILE *read, *write;
    char buffer[MAX_WORD_LENGTH];
    fopen_s(&read, "harry.txt", "r");//���� ����
    fopen_s(&write, "aligned.txt", "w");//���� ����
    int wInd = 0, lLength = 0;
    while (fscanf_s(read, "%s ", &buffer, MAX_WORD_LENGTH) != EOF) {//�Ѵܾ ����
        if (lLength+strlen(buffer) > CHARACTER_PER_LINE-wInd) {//�ϳ��� ���� ���� �̹��ܾ� ���� �̹� ���� ���� ��
            int spaces = CHARACTER_PER_LINE - lLength;//�ʿ��� ���� ��
            for (int i = 0; i < wInd-1; i++) {//�� �ܾ� ����
                fprintf(write,"%s", line[i]);
                for (int j = 0; j < spaces / (wInd-1); j++)//�յ��ϰ� ���������� ���� ����
                    fprintf(write, " ");
                if (spaces%(wInd-1) > 0) {//���ʺ��� ��ĭ�� �� �ִ� ����
                    fprintf(write, " ");
                    spaces -= 1;
                }
            }
            fprintf(write,line[wInd - 1]);//�� �� ������ �ܾ�
            fprintf(write,"\n");//�ٹٲ�
            wInd = 0;
            lLength = 0;
        }
        lLength += strlen(buffer);
        strcpy_s(line[wInd++], 50, buffer);
    }
    for (int i = 0; i < wInd; i++) {//��������
        fprintf(write, "%s", line[i]);
        fprintf(write, " ");
    }
    fclose(read);
    fclose(write);
    printf("finished");
    getchar();
}