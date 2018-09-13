#include <stdio.h>
#include <string.h>
#define MAX_COLUMN 50//최대 열의 수
#define MAX_ROW 50//최대 행의 수
#define MAX_STRINGLENGTH 50//셀 당 최대 문자열 길이
#define SEPERATOR (char)'|'//열 구분 기호

char grid[MAX_ROW][MAX_COLUMN][MAX_STRINGLENGTH];
int width[MAX_COLUMN];
int row = 0, col = 0;
void readFile() {//입력
    int rowInd = 0, colInd = 0, charInd = 0;
    char buffer;
    FILE*  fp;
    fopen_s(&fp, "tabular.txt", "r");
    fscanf_s(fp, "%d", &row);
    fscanf_s(fp, "%d", &col);
    while (fscanf_s(fp, "%c", &buffer) != EOF) {
        if (buffer == '\n') continue;//처음 줄 선정 후 줄바꿈 기호 예외처리
        if (buffer == ' ' && (grid[rowInd][colInd][charInd - 1] == ' ' || charInd == 0)) continue;//한번에 두개 이상의 공백/칸 시작시의 공백 지움
        if (buffer == '&') {// "&" 에 의한 칸 나누기
            grid[rowInd][colInd][charInd - 1] = '\0';
            charInd = 0;
            colInd += 1;
            fscanf_s(fp, "%c", &buffer);
        }
        else if (buffer == '\\') {// "\\"에 희한 줄 나누기
            char confirmer;
            fscanf_s(fp, "%c", &confirmer);
            if (confirmer == '\\') {//연속해서 '\'가 두개였을 때
                grid[rowInd][colInd][charInd - 1] = '\0';
                fscanf_s(fp, "%c", &buffer);
                rowInd += 1;
                colInd = 0;
                charInd = 0;
            }
            else {// 알고보니 '\'하나에 다른자료 였을때
                grid[rowInd][colInd][charInd++] = '\\';
                grid[rowInd][colInd][charInd++] = confirmer;
            }
        }
        else grid[rowInd][colInd][charInd++] = buffer;//그 외의 경우
        //적어놓은 칸보다 많을때를 대비한 확장(파일에 행/열길이 있는걸 몰랐을때 제작
        if (rowInd + 1 > row) row = rowInd + 1;
        if (colInd + 1 > col) col = colInd + 1;
        if (charInd > width[colInd]) width[colInd] = charInd;
    }
    fclose(fp);
}
void output() {//출력
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s", grid[i][j]);
            for (int k = 0; k < width[j] - strlen(grid[i][j]) - 1; k++) {
                printf(" ");
            }
            printf("%c",SEPERATOR);//열 구별 기호
        }
        printf("\n");//행 구별 기호
    }
}
int main() {
    readFile();
    output();
    getchar();
    getchar();
}