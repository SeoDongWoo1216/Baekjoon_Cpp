/*
	3���� ������
	1. 10������ �Է¹����� 3������ ��ȯ
	2. 3������ �����(1100�̸� 0011�� �ٲ�) �ٽ� 10������ ��ȯ�ϴ� ����

	����
	1. �Է¹��� ���� 3������ ��ȯ(while���� ���� arr1�� ������ ������ ���� �ϳ��� ����)
	2. arr1�� �迭�� ����� arr2�� ����
	3. arr2�� �� �迭�� ��ҿ� 3�� �ŵ������� ���ؼ� 10������ ��ȯ�Ͽ� result �� ����
	4. result ��ȯ
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int solution(int n)
{
	int arr1[1000] = { 0 };  // 3������ �������� ������ �迭
	int arr2[1000] = { 0 };  // arr1���� ����� ������ �迭

	int count = 0;   // �迭 ��� �ε���
	int result = 0;  // ���� ��� ����

	
	// ���� ���� 3���� ������ �״�� ��ȯ(1�̳� 2�̸� ����� �״�� 1, 2�� �Ǳ⶧��)
	if (n < 3)
	{
		return n;
	}

	// 3���� ��ȯ
	while (1)
	{
		arr1[count] = n % 3; 
		n /= 3;

		count++;   // �ε��� ����

		if (n < 3)  //
		{
			arr1[count] = n;
			break;
		}
	}

	// �迭 ������ 
	// arr1 ������ ó�������� ���� 
	// arr2�� ó������ �������� ���̵�
	for (int i = 0; i < count + 1; i++)
	{
		arr2[i] = arr1[count - i];
	}


	
	// 3������ 10������ ��ȯ(arr2�� �� ��ҿ� 3�� �ŵ������� ���ؼ� �� ������)
	int temp = 1;
	for (int i = 0; i < count + 1; i++)
	{
		result += arr2[i] * temp;
		temp = temp * 3;
	}

	printf("%d\n", result);     // result ���(���� Ȯ���ϴ� �뵵)

	return result;              // result ��ȯ(���������� printf ����� return���ָ��)
}

int main()
{
	solution(45);   // 7 ���
	solution(125);  // 229 ���
	solution(1);    // 1 ���
}