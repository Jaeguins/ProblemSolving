#include <stdio.h>
#define MAX_INPUT_LINE 120//�ִ� �Է� ���ڿ� ��
int main() {
    int tData = 0, dataInd = 0;
    char buffer[MAX_INPUT_LINE];
    int sum = 0;
    gets_s(&buffer, MAX_INPUT_LINE);//buffer�� �� �о�ְ�
    for (int i = 0; i < sizeof(buffer); i++) {//�ѱ��ھ� �̾Ƽ�
        if (buffer[i] < 58 && buffer[i]>47) {//�����ΰ�?
            if (tData > 0)
                tData *= 10;//������ �ִ� ���ڰ� ������ ���ڸ� �÷��ְ�
            tData += (buffer[i] - 48);//ASCII -> ������ ��ȯ �� ����
        }
        else {//���ڰ� �ƴϸ�
            if (tData > 0) {//�����ڱ����� ���ڿ��ٸ�
                sum += tData;//���� �� ���� �ʱ�ȭ
                tData = 0;
            }
        }
    }
    if (tData > 0) sum += tData;//�࿩�� ���� �����ϼ��� �����Ƿ�
    printf("%d\n", sum);//���
    getchar();
}