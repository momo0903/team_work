#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int max) {
    return rand() % (max + 1);
}

char getRandomOperator(int hasDivision) {
    if (hasDivision) {
        int op = rand() % 4;
        switch (op) {
        case 0: return '+';
        case 1: return '-';
        case 2: return '*';
        case 3: return '/';
        }
    }
    else {
        int op = rand() % 3;
        switch (op) {
        case 0: return '+';
        case 1: return '-';
        case 2: return '*';
        }
    }
}

void generateQuestions(int num, int maxNum, int hasDecimal, int hasBracket, int hasDivision) {
    srand((unsigned)time(NULL));

    for (int i = 0; i < num; i++) {
        int num1 = getRandomNumber(maxNum);
        int num2 = getRandomNumber(maxNum);
        char op = getRandomOperator(hasDivision);

        if (op == '/' && num2 == 0) {   // ��ֹ����Ϊ0�����
            num2 = 1;   // ��������Ϊ1
        }

        if (hasDecimal) {
            float result;
            switch (op) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = (float)num1 / num2;
                break;
            }
            printf("%.2f %c %.2f = \n", (float)num1, op, (float)num2);
        }
        else {
            printf("%d %c %d = \n", num1, op, num2);
        }
    }
}

int main() {
    int numQuestions, maxNumber, hasDecimal, hasBracket, hasDivision;

    // �û��������ò�����������Ŀ��������������Ƿ���С����

    printf("��������Ŀ������");
    scanf_s("%d", &numQuestions);

    printf("�����������ֵ��");
    scanf_s("%d", &maxNumber);

    printf("�Ƿ����С��(1 for �ǣ�0 for ��)��");
    scanf_s("%d", &hasDecimal);

    printf("�Ƿ��������(1 for �ǣ�0 for ��)��");
    scanf_s("%d", &hasBracket);

    printf("�Ƿ��������(1 for �ǣ�0 for ��)��");
    scanf_s("%d", &hasDivision);

    generateQuestions(numQuestions, maxNumber, hasDecimal, hasBracket, hasDivision);

    return 0;
}