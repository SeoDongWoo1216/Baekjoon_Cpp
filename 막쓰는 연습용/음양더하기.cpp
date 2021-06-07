/*
    ���α׷��ӽ� : ������ϱ�
    ���̰� ���� �����迭, bool�� �迭�� �ް�
    bool�� �迭�� true�� �ε������� ���,
                  false�� �ε������� �������ؼ� �����迭���� ���� ��ȯ�ϴ� ����
*/

/*
    ����
    1. bool�� �迭�� false�� �ε����� ���ϱ�
    2. �ش��ϴ� �ε����� �����迭�� ��ҿ� -1���ؼ� ������ �������
    3. �����迭�� ��� ��Ҹ� ������
    4. result�� ��ȯ
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) 
{
    int result = 0;
    for (int i = 0; i < signs_len; i++)     // bool�� �迭 ��Ұ� false�� �ε����� -1�� ���ؼ� ���� �迭 ��ҿ� ������ �������
    {
        if (signs[i] == false)
        {
            absolutes[i] *= -1;
        }
    }

    for (int i = 0; i < absolutes_len; i++)  // ��� �����迭����� ���� result�� ����
    {
        result += absolutes[i];
    }
    
    printf("%d\n", result);
    return 0;
}

int main()
{
    int absolutes[3] = { 4, 7, 12 };
    bool signs[3] = { true, false, true };

    solution(absolutes, 3, signs, 3);
}