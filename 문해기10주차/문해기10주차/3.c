#include <stdio.h>
int intersect(int v[], int h[]) {
    if (h[0]<=v[0] && v[0]<=h[2] && v[1] <= h[1] && h[1] <= v[3]) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    FILE* input;
    fopen_s(&input, "input3.txt", "r");
    int V[1000][4], H[1000][4];
    int lenV = 0, lenH=0;
    int N;
    fscanf_s(input, "%d", &N);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        fscanf_s(input, "%d", &x1);
        fscanf_s(input, "%d", &y1);
        fscanf_s(input, "%d", &x2);
        fscanf_s(input, "%d", &y2);
        if (x1 == x2) {
            V[lenV][0] = x1;
            V[lenV][1] = y1;
            V[lenV][2] = x2;
            V[lenV][3] = y2;
            lenV += 1;
        }
        else {
            H[lenH][0] = x1;
            H[lenH][1] = y1;
            H[lenH][2] = x2;
            H[lenH][3] = y2;
            lenH += 1;
        }
    }
    for (int i = 0; i < lenV; i++) {
        for (int j = 0; j < lenH; j++) {
            if (intersect(V[i], H[j])) {
                printf("[ %d , %d ]\n", V[i][0], H[j][1]);
            }
        }
    }
    getchar();
    getchar();
}