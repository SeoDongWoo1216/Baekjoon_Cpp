#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void Tri_snail(int* arr, int N, int ArrSize, int value, int Len, int depth)
{
	int n = N;
	int arrSize = ArrSize;
	int len = Len + (4 * depth);
	//int len = Len;


	for (int i = 0; i < n; i++)
	{
		len += i;
		arr[len] = value;
		value++;
	}

	n--;
	if (n == 0) return;

	for (int i = 0; i < n; i++)
	{
		arr[arrSize - N + 1 + i] = value;
		value++;
	}

	n--;
	if (n == 0) return;

	len = arrSize - N - 1;
	for (int i = 0; i < n; i++)  // 0 1 2
	{
		arr[len] = value;
		value++;
		len -= N - 1 - i;
	}

	n--;
	if (n == 0) return;
	/*if (ArrSize >= value)
	{
		Tri_snail(arr, n, arrSize, value, 0, depth + 1);
	}*/
}



int main()
{
	int n;
	
	int value = 1;
	printf("배열의 크기 입력 : ");
	scanf_s("%d", &n);

	int arrSize = (n * (n + 1)) / 2;

	int *arr = (int*)malloc(sizeof(int) * arrSize + 1);  // 요소개수만큼 동적할당

	int len = 0;
	int depth = 0;


	Tri_snail(arr, n, arrSize, value, len, depth);
	


	for (int i = 0; i < arrSize; i++)
	{
		printf("%3d", arr[i]);
	}

	printf("\n");

	return 0;
}