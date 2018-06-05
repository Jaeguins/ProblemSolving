#include <stdio.h>
#include <string.h>
char dict[4000][16];
int main() {
    FILE*  fp;
    fopen_s(&fp,"dictionary.txt", "r");
    int  i = 0;
    while (fscanf_s(fp,"%s\n",dict[i],16)!=EOF)i++;
    char field[100][100];
    fopen_s(&fp,"input_grid.txt", "r");
    int N,count=0;
    char g;
    fscanf_s(fp, "%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf_s(fp, "%c", &field[i][j]);
            if (field[i][j] == '\n')fscanf_s(fp, "%c", &field[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int m = -1; m < 2; m++) {
                for (int n = -1; n < 2; n++) {
                    if (m == 0 && n == 0) continue;
                    char tmp[17];
                    for (int k = 0; k < 16; k++) {
                        if (i + (m*k) >= 0 && i + (m*k) < N && j + (n*k) >= 0 && j + (n*k) < N) {
                            tmp[k] = field[i + (m*k)][j + (n*k)];
                            tmp[k + 1] = '\0';
                            for (int l = 0; l < 4000; l++)
                                if (strcmp(dict[l], tmp)==0) {
                                    printf("%s\n", dict[l]);
                                }
                        }
                    }
                }
            }
        }
    }
    getchar();
    getchar();
}