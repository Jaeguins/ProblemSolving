#include <stdio.h>
#include <string.h>
#define MAX_COLUMN 50//�ִ� ���� ��
#define MAX_ROW 50//�ִ� ���� ��
#define MAX_STRINGLENGTH 50//�� �� �ִ� ���ڿ� ����
#define SEPERATOR (char)'|'//�� ���� ��ȣ

char grid[MAX_ROW][MAX_COLUMN][MAX_STRINGLENGTH];
int width[MAX_COLUMN];
int row = 0, col = 0;
void readFile() {//�Է�
    int rowInd = 0, colInd = 0, charInd = 0;
    char buffer;
    FILE*  fp;
    fopen_s(&fp, "tabular.txt", "r");
    fscanf_s(fp, "%d", &row);
    fscanf_s(fp, "%d", &col);
    while (fscanf_s(fp, "%c", &buffer) != EOF) {
        if (buffer == '\n') continue;//ó�� �� ���� �� �ٹٲ� ��ȣ ����ó��
        if (buffer == ' ' && (grid[rowInd][colInd][charInd - 1] == ' ' || charInd == 0)) continue;//�ѹ��� �ΰ� �̻��� ����/ĭ ���۽��� ���� ����
        if (buffer == '&') {// "&" �� ���� ĭ ������
            grid[rowInd][colInd][charInd - 1] = '\0';
            charInd = 0;
            colInd += 1;
            fscanf_s(fp, "%c", &buffer);
        }
        else if (buffer == '\\') {// "\\"�� ���� �� ������
            char confirmer;
            fscanf_s(fp, "%c", &confirmer);
            if (confirmer == '\\') {//�����ؼ� '\'�� �ΰ����� ��
                grid[rowInd][colInd][charInd - 1] = '\0';
                fscanf_s(fp, "%c", &buffer);
                rowInd += 1;
                colInd = 0;
                charInd = 0;
            }
            else {// �˰��� '\'�ϳ��� �ٸ��ڷ� ������
                grid[rowInd][colInd][charInd++] = '\\';
                grid[rowInd][colInd][charInd++] = confirmer;
            }
        }
        else grid[rowInd][colInd][charInd++] = buffer;//�� ���� ���
        //������� ĭ���� �������� ����� Ȯ��(���Ͽ� ��/������ �ִ°� �������� ����
        if (rowInd + 1 > row) row = rowInd + 1;
        if (colInd + 1 > col) col = colInd + 1;
        if (charInd > width[colInd]) width[colInd] = charInd;
    }
    fclose(fp);
}
void output() {//���
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s", grid[i][j]);
            for (int k = 0; k < width[j] - strlen(grid[i][j]) - 1; k++) {
                printf(" ");
            }
            printf("%c",SEPERATOR);//�� ���� ��ȣ
        }
        printf("\n");//�� ���� ��ȣ
    }
}
int main() {
    readFile();
    output();
    getchar();
    getchar();
}