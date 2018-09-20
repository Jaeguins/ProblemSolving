#include <stdio.h>
#include <string.h>
#define MAX_BUFFER_SIZE 80
char buffer[MAX_BUFFER_SIZE];
char IsIP() {
    int tData = 0, count = 0;
    for (int i = 0; i < sizeof(buffer); i++) {
        if (buffer[i] < 58 && buffer[i]>47) {
            if (tData > 0) tData *= 10;
            tData += buffer[i] - 48;
        }
        else if (buffer[i] == '.') {
            if (tData > 255) return 0;
            count += 1;
            tData = 0;
        }
        else if (buffer[i] == '\0') {
            if (count == 3 && tData < 256) return 1;
            else return 0;
        }
        else return 0;
    }
}
int main() {
    while (1) {
        gets_s(buffer, MAX_BUFFER_SIZE);
        if (IsIP()) printf("Yes\n");
        else printf("No\n");
    }
}