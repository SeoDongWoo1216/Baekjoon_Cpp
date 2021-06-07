/*
    ���α׷��ӽ� �ΰ��̾Ƽ����ϱ�(C)
	�����迭�� �־����� ���� �ٸ� �� ���� ���� �̾� ���ؼ� ���� �� �ִ� ��� ����
	������������ ��� return �ϴ� ����
*/

/*
	����
	1. �ΰ��� �������� ���� ū ���� ã�Ƽ� �� ����ŭ�� ������������ bool�� �迭 ����(���� ���� ������ŭ ����� �����)
	2. bool�� �迭�� ��� ��Ҹ� false�� �ʱ�ȭ
	3. �ΰ��� ���������� ����� ���� bool�� �迭�� ��Ҹ� true�� �ٲ���( 2 + 1 = 3 �̸� bool���迭[3] = true; �� �������)
	4. boolary�� true�� ��Ҹ�ŭ�� ũ�⸦������ int�� �迭����
	5. boolary�� true�� ������ �ε����� int�� �迭�� �ϳ��� �־���
	6. ���
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len)
{
	int temp = 0;
	for (int i = 0; i < arr_len; i++)               // 1. ���� �迭���� �ΰ����� �������� ���� ū ���� ã��(temp�� ����)
	{
		for (int j = i + 1; j < arr_len; j++)
		{
			if (temp < arr[i] + arr[j])
			{
				temp = arr[i] + arr[j];
			}
		}
	}

	bool* boolary = (bool*)malloc(sizeof(bool) * temp + 1); //    ���� ū �� ��ŭ�� ������ ������ bool�� �迭(boolary) ����
	
	for (int i = 0; i <= temp; i++)                         // 2. bool�� �迭�� ��Ҹ� ���� 0���� �ʱ�ȭ
	{
		boolary[i] = false;
	}

	int boolCount = 0;                               // 3. �� ���� ���������� ����� ���� bool�� �迭 ��ҿ� true�� ����.
	int count = 0;                                   //    ������� ���� ���� 2, 1 �̸� 2 + 1 = 3 �ε�
	for (int i = 0; i < arr_len; i++)                //    boolary[3] = true;  �� �Ǵ°���
	{
		for (int j = i + 1; j < arr_len; j++)
		{
			boolCount = arr[i] + arr[j];             //    �� �����̾Ƽ� ���Ѱ��� boolCount�� ����
			if (boolary[boolCount] == false)         //    ���� boolCount�� false �� �ƴϸ� ( => �ߺ�����)
			{
				boolary[boolCount] = true;           
				count++;                             //    boolary���� true�� ������ �������� count����
			}
		}
	}

	int answerCount = 0;
	int* answer = (int*)malloc(sizeof(int) * count); // 4. boolary���� true�� ����(count)��ŭ int�� �迭(answer) ����
	for (int i = 0; i <= temp; i++)
	{
		if (boolary[i] == true)                      //    boolary�� ����߿� true�� �ε����� answer�� ó������ �߰�����
		{                                            //    ������� ó���� true���� boolary[3] = true; ��
			answer[answerCount++] = i;               //    answer[0] = 3; �� �����
		}
	}

	for (int i = 0; i < count; i++)                  //    answer�� ����� �迭 ��� ���
	{
		printf("%d ", answer[i]);
	}

	return answer;
}

int main()
{
	int arr1[4] = { 5,0,2,7 };
	int arr2[5] = { 2, 1, 3, 4, 1 };
	solution(arr2, 5);
}