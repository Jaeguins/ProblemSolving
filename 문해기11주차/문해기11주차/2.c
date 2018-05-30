#include <stdio.h>

double field[500][500];
double answer[500];
int N;

int getAnswer() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (field[j][i] == 0) continue;
            double tmp = field[i][i] / field[j][i];
            for (int k = 0; k < N + 1; k++) {
                field[j][k] = field[j][k] * tmp - field[i][k];
            }
        }
    }
    if (!field[N - 1][N - 1]) {
        if (field[N - 1][N]) return 1;
        else return 0;
    }
    for (int i = N - 1; i >= 0; i--) {
        double k = field[i][N];
        for (int j = N - 1; j > i; j--) {
            k -= field[i][j] * answer[j];
        }
        answer[i] = k / field[i][i];
    }
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2lf \n",i+1, answer[i]);
    }
}
int main() {
    FILE* f;
    fopen_s(&f, "data.txt", "r");
    fscanf_s(f, "%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N + 1; j++) {
            fscanf_s(f, "%lf", &field[i][j]);
        }
    }
    int result = getAnswer();
    if (!result) {
        printf("infinite solution");
    }
    else if(result==1){
        printf("no solution");
    }
    getchar();
    getchar();
}