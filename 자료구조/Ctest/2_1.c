#include <stdio.h>
#define MAX_INPUT_LINE 120//최대 입력 문자열 수
int main() {
    int tData = 0, dataInd = 0;
    char buffer[MAX_INPUT_LINE];
    int sum = 0;
    gets_s(&buffer, MAX_INPUT_LINE);//buffer에 다 밀어넣고
    for (int i = 0; i < sizeof(buffer); i++) {//한글자씩 뽑아서
        if (buffer[i] < 58 && buffer[i]>47) {//숫자인가?
            if (tData > 0)
                tData *= 10;//이전에 있던 숫자가 있으면 한자리 올려주고
            tData += (buffer[i] - 48);//ASCII -> 십진수 전환 후 더함
        }
        else {//숫자가 아니면
            if (tData > 0) {//전글자까지가 숫자였다면
                sum += tData;//누산 후 숫자 초기화
                tData = 0;
            }
        }
    }
    if (tData > 0) sum += tData;//행여나 끝이 숫자일수도 있으므로
    printf("%d\n", sum);//출력
    getchar();
}