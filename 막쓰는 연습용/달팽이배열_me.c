#include <stdio.h>

int main()
{
	int n = 4;
	int arr[4][4];

	int value = 1;

	int x = 0; 
	int y = -1;

	int inc = 1;   // ���� �迭�� ��ġ�� �÷����ϴ��� �������ϴ��� �Ǵ����ִ� ����

	while (n > 0)
	{
		for (int i = 0; i < n; i++)  // ���� ��
		{
			y += inc;
			arr[x][y] = value;
			value++;
		}
		n--;
		if (n == 0) break;   // n = 0�̸� �迭�� �� ������ ��������

		for (int i = 0; i < n; i++)  // ���� ��
		{
			x += inc;
			arr[x][y] = value;
			value++;
		}
		inc *= -1;
	}


	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}