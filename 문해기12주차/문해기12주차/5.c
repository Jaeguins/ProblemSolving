#include <stdio.h>
#include <string.h>
#define MAX_WORD 4000
#define MAX_LEN 20

char dict[MAX_WORD][MAX_LEN];
char grid[MAX_LEN][MAX_LEN];
int n_words, size;

void read_dictionary() {
    FILE*  fp;
    fopen_s(&fp, "dictionary.txt", "r");
    int  i = 0;
    while (fscanf_s(fp, "%s\n", dict[i], 16) != EOF)i++;
    n_words = i;
    fclose(fp);
}
void read_grid() {
    FILE* fp;
    fopen_s(&fp, "input_grid.txt", "r");
    char g;
    fscanf_s(fp, "%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fscanf_s(fp, "%c", &grid[i][j]);
            if (grid[i][j] == '\n')fscanf_s(fp, "%c", &grid[i][j]);
        }
    }
    fclose(fp);
}
int search(int ind) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int m = -1; m < 2; m++) {
                for (int n = -1; n < 2; n++) {
                    if (m == 0 && n == 0) continue;
                    char tmp[17];
                    for (int k = 0; k < MAX_LEN; k++) {
                        if (i + (m*k) >= 0 && i + (m*k) < size && j + (n*k) >= 0 && j + (n*k) < size)
                        {
                            tmp[k] = grid[i + (m*k)][j + (n*k)];
                            tmp[k + 1] = '\0';
                            if (strcmp(dict[ind], tmp) == 0) {
                                return 1;
                            }
                        }
                        else {
                            break;
                        }
                    }
                    
                }
            }
        }
    }
    return 0;
}



int main() {
    read_dictionary();
    read_grid();
    int i;
    for (int i = 0; i < n_words; i++) {
        int result = search(i);
        if (result) {
            printf("%s\n", dict[i]);
        }
    }
    getchar();
    getchar();
}