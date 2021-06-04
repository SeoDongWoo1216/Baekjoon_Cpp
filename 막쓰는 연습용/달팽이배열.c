#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// �迭�� ����Ʈ ���ִ� �Լ� . �迭�� ũ�� n�� �迭�� ���ڷ� ����
void printarr(int n, int (*arr)[4]) 
{ 
	int i, j; for (i = 0; i < n; i++) 
	{ 
		for (j = 0; j < n; j++) 
		{ 
			printf("%3d ", arr[i][j]); 
		} 
		printf("\n");
	} 
} 

// �迭�� ����� �ִ� �Լ�. �迭�� ũ�� n�� �迭�� ���ڷ� ���� 

void makearr(int n, int (*arr)[4]) 
{ 
	int value = 1; // �迭�� ä�� ���� ��
	int row = 0, col = -1; // ��(row), ��(col) �� ��Ÿ���� index 
	int inc = 1; // index �� �������� ��Ÿ��. 1 �Ǵ� -1 �� ���� �� ���� 
	int i, j; 
	while (n > 0) 
	{ 
		for (i = 0; i < n; i++) 
		{ 
			col += inc; // �� index �� inc ��ŭ ������Ŵ. inc�� -1�̸� ���� 
			arr[row][col] = value; 
			value++; 
		} 
		n--;  // �����ϴ� �� 1 ���� 
		if (n == 0) break; // �����ϴ� ���� 0�� �Ǹ� while ���� �������� 
		for (i = 0; i < n; i++) 
		{ 
			row += inc; // �� index �� inc ��ŭ ������Ŵ. inc �� -1�̸� ���� 
			arr[row][col] = value; 
			value++; 
		} 
		inc *= -1; //inc ��ȣ�ٲ�. ������ ���ҷ� Ȥ�� ���Ұ� ������ �ٲ�� ȿ�� 
	} 
}
int main(void) 
{ 
	int side = 4; 
	//printf("Input side length of arr : "); 
	// scanf("%d", &side); 
	int arr[4][4]; 
	makearr(side, arr); // �迭�� ����� �Լ� ȣ�� 
	printarr(side, arr); // �迭�� ����Ʈ ���ִ� �Լ� ȣ�� 
	return 0; 
}
