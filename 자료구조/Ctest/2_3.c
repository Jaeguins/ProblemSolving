#include <stdio.h>
#include <string.h>
#define MAX_WORD_LENGTH 50
#define MAX_WORD_PER_LINE 80
#define CHARACTER_PER_LINE 80
char line[80][50];
int main() {
    FILE *read, *write;
    char buffer[MAX_WORD_LENGTH];
    fopen_s(&read, "harry.txt", "r");//읽을 파일
    fopen_s(&write, "aligned.txt", "w");//쓰는 파일
    int wInd = 0, lLength = 0;
    while (fscanf_s(read, "%s ", &buffer, MAX_WORD_LENGTH) != EOF) {//한단어씩 읽음
        if (lLength+strlen(buffer) > CHARACTER_PER_LINE-wInd) {//하나씩 띄어쓰기 포함 이번단어 까지 이번 줄의 글자 수
            int spaces = CHARACTER_PER_LINE - lLength;//필요한 띄어쓰기 수
            for (int i = 0; i < wInd-1; i++) {//한 단어 쓰기
                fprintf(write,"%s", line[i]);
                for (int j = 0; j < spaces / (wInd-1); j++)//균등하게 나누었을때 들어가는 공백
                    fprintf(write, " ");
                if (spaces%(wInd-1) > 0) {//왼쪽부터 한칸씩 더 넣는 공백
                    fprintf(write, " ");
                    spaces -= 1;
                }
            }
            fprintf(write,line[wInd - 1]);//그 줄 마지막 단어
            fprintf(write,"\n");//줄바꿈
            wInd = 0;
            lLength = 0;
        }
        lLength += strlen(buffer);
        strcpy_s(line[wInd++], 50, buffer);
    }
    for (int i = 0; i < wInd; i++) {//마지막줄
        fprintf(write, "%s", line[i]);
        fprintf(write, " ");
    }
    fclose(read);
    fclose(write);
    printf("finished");
    getchar();
}