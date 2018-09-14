#include <stdio.h>
#define MAX_INPUT_LINE 120
int main() {
    int data[MAX_INPUT_LINE];
    int tData = 0,dataInd=0;
    char buffer[MAX_INPUT_LINE];
    
    gets_s(&buffer,MAX_INPUT_LINE);
    for (int i = 0; i < sizeof(data); i++) {
        if (buffer[i] < 58&&buffer[i]>47) {
            if (tData > 0)
                tData *= 10;
            tData += (buffer[i]-48);
        }
        else {
            if (tData > 0) {
                data[dataInd++] = tData;
                tData = 0;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < dataInd; i++) {
        sum += data[i];
    }
    printf("\n%d\n", sum);
    getchar();
    getchar();
}