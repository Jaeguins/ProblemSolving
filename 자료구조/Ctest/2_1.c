#include <stdio.h>
#define MAX_INPUT_LINE 120//�ִ� �Է� ���ڿ� ��
int main() {
    int tData = 0, dataInd = 0;
    char minused = 0;
    char buffer[MAX_INPUT_LINE];
    int sum = 0;
    gets_s(&buffer, MAX_INPUT_LINE);//buffer�� �� �о�ְ�
    for (int i = 0; i < sizeof(buffer); i++) {//�ѱ��ھ� �̾Ƽ�
        if (buffer[i] < 58 && buffer[i]>47) {//�����ΰ�?
            if (tData != 0)
                tData *= 10;//������ �ִ� ���ڰ� ������ ���ڸ� �÷��ְ�
            tData += (buffer[i] - 48);//ASCII -> ������ ��ȯ �� ����
        }
        else if (buffer[i] == '-') {//�����̸�
            minused = 1;//���� Ʈ���� On
        }
        else {//���ڰ� �ƴϸ�
            if (tData != 0||minused) {//�����ڱ����� ���ڿ��ٸ�
                if (minused)sum -= tData;//������� ����
                else sum += tData;//������ ���ϰ�
                tData = 0;//���ʱ�ȭ
                minused = 0;
            }
        }
    }
    if (tData > 0) sum += tData;//�࿩�� ���� �����ϼ��� �����Ƿ�
    printf("%d\n", sum);//���
    getchar();
}