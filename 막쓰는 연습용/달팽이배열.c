#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 배열을 프린트 해주는 함수 . 배열의 크기 n과 배열을 인자로 받음
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

// 배열을 만들어 주는 함수. 배열의 크기 n과 배열을 인자로 받음 

void makearr(int n, int (*arr)[4]) 
{ 
	int value = 1; // 배열을 채워 나갈 값
	int row = 0, col = -1; // 행(row), 열(col) 을 나타내는 index 
	int inc = 1; // index 의 증감량을 나타냄. 1 또는 -1 을 가질 수 있음 
	int i, j; 
	while (n > 0) 
	{ 
		for (i = 0; i < n; i++) 
		{ 
			col += inc; // 열 index 를 inc 만큼 증가시킴. inc가 -1이면 감소 
			arr[row][col] = value; 
			value++; 
		} 
		n--;  // 전진하는 양 1 감소 
		if (n == 0) break; // 전진하는 양이 0이 되면 while 루프 빠져나옴 
		for (i = 0; i < n; i++) 
		{ 
			row += inc; // 행 index 를 inc 만큼 증가시킴. inc 가 -1이면 감소 
			arr[row][col] = value; 
			value++; 
		} 
		inc *= -1; //inc 부호바꿈. 증가가 감소로 혹은 감소가 증가로 바뀌는 효과 
	} 
}
int main(void) 
{ 
	int side = 4; 
	//printf("Input side length of arr : "); 
	// scanf("%d", &side); 
	int arr[4][4]; 
	makearr(side, arr); // 배열을 만드는 함수 호출 
	printarr(side, arr); // 배열을 프린트 해주는 함수 호출 
	return 0; 
}
