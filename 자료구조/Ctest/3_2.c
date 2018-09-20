#include <stdio.h>
#include <string.h>
#define MAX_BUFFER_LENGTH 120
#define MAX_WORD_PER_LINE 80
#define CHARACTER_PER_LINE 80
char line[80][MAX_WORD_PER_LINE];
int main() {
    FILE *read, *write;
    char buffer[MAX_BUFFER_LENGTH];
    char word[MAX_BUFFER_LENGTH];
    char* context;
    fopen_s(&read, "harry.txt", "r");//���� ����
    fopen_s(&write, "aligned.txt", "w");//���� ����
    int wInd = 0, lLength = 0;
    while (fgets(&buffer, MAX_BUFFER_LENGTH, read) != NULL) {//���پ� ����
        if (strcmp(buffer,"\n")==0) {
            
            for (int i = 0; i < wInd; i++) {//���� ��������
                fprintf(write, "%s", line[i]);
                fprintf(write, " ");
            }
            fprintf(write, "\n\n");
            wInd = 0;
            lLength = 0;
            continue;
        }
        strtok_s(buffer, "\n", &context);
        strcpy_s(word, MAX_WORD_PER_LINE, strtok_s(buffer, " ", &context));//�ܾ�� �ڸ�
        do {
            if (lLength + strlen(word) > CHARACTER_PER_LINE - wInd) {//�ϳ��� ���� ���� �̹��ܾ� ���� �̹� ���� ���� ��
                int spaces = CHARACTER_PER_LINE - lLength;//�ʿ��� ���� ��
                for (int i = 0; i < wInd - 1; i++) {//�� �ܾ� ����
                    fprintf(write, "%s", line[i]);
                    for (int j = 0; j < spaces / (wInd - 1); j++)//�յ��ϰ� ���������� ���� ����
                        fprintf(write, " ");
                    if (spaces % (wInd - 1) > 0) {//���ʺ��� ��ĭ�� �� �ִ� ����
                        fprintf(write, " ");
                        spaces -= 1;
                    }
                }
                fprintf(write, line[wInd - 1]);//�� �� ������ �ܾ�
                fprintf(write, "\n");//�ٹٲ�
                wInd = 0;
                lLength = 0;
            }
            lLength += strlen(word);
            strcpy_s(line[wInd++], 50, word);
            if (strlen(context) > 0) {
                strcpy_s(word, MAX_WORD_PER_LINE, strtok_s(NULL, " ", &context));//�ܾ�� �ڸ�
            }
            else {
                break;
            }
        } while (1);
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