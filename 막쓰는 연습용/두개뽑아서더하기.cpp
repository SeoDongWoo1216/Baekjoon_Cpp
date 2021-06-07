/*
    프로그래머스 두개뽑아서더하기(C)
	정수배열이 주어질때 서로 다른 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를
	오름차순으로 담아 return 하는 문제
*/

/*
	구현
	1. 두개를 더했을때 가장 큰 수를 찾아서 그 수만큼의 공간을가지는 bool형 배열 선언(가장 많은 개수만큼 만드는 경우임)
	2. bool형 배열의 모든 요소를 false로 초기화
	3. 두개를 더했을때의 경우의 수를 bool형 배열의 요소를 true로 바꿔줌( 2 + 1 = 3 이면 bool형배열[3] = true; 로 만들어줌)
	4. boolary의 true의 요소만큼의 크기를가지는 int형 배열선언
	5. boolary의 true를 가지는 인덱스를 int형 배열에 하나씩 넣어줌
	6. 출력
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int arr[], size_t arr_len)
{
	int temp = 0;
	for (int i = 0; i < arr_len; i++)               // 1. 받은 배열에서 두가지를 더했을때 가장 큰 수를 찾기(temp에 저장)
	{
		for (int j = i + 1; j < arr_len; j++)
		{
			if (temp < arr[i] + arr[j])
			{
				temp = arr[i] + arr[j];
			}
		}
	}

	bool* boolary = (bool*)malloc(sizeof(bool) * temp + 1); //    가장 큰 수 만큼의 공간을 가지는 bool형 배열(boolary) 선언
	
	for (int i = 0; i <= temp; i++)                         // 2. bool형 배열의 요소를 전부 0으로 초기화
	{
		boolary[i] = false;
	}

	int boolCount = 0;                               // 3. 두 개를 더했을때의 경우의 수를 bool형 배열 요소에 true로 해줌.
	int count = 0;                                   //    예를들어 뽑은 수가 2, 1 이면 2 + 1 = 3 인데
	for (int i = 0; i < arr_len; i++)                //    boolary[3] = true;  가 되는것임
	{
		for (int j = i + 1; j < arr_len; j++)
		{
			boolCount = arr[i] + arr[j];             //    두 개를뽑아서 더한것을 boolCount에 저장
			if (boolary[boolCount] == false)         //    만약 boolCount가 false 가 아니면 ( => 중복방지)
			{
				boolary[boolCount] = true;           
				count++;                             //    boolary에서 true의 개수를 세기위한 count변수
			}
		}
	}

	int answerCount = 0;
	int* answer = (int*)malloc(sizeof(int) * count); // 4. boolary에서 true의 개수(count)만큼 int형 배열(answer) 선언
	for (int i = 0; i <= temp; i++)
	{
		if (boolary[i] == true)                      //    boolary의 요소중에 true인 인덱스를 answer의 처음부터 추가해줌
		{                                            //    예를들어 처음의 true값이 boolary[3] = true; 면
			answer[answerCount++] = i;               //    answer[0] = 3; 이 저장됨
		}
	}

	for (int i = 0; i < count; i++)                  //    answer에 저장된 배열 요소 출력
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