#include <iostream>
using namespace std;

int solution(int *a, int *b)
{
	int res = 0;

	for (int i = 0; i < 4; i++)
	{
		res += a[i] * b[i];
	}

	printf("%d", res);
	return res;
}


int main()
{
	int a[1001] = {1, 2, 3, 4};
	int b[1001] = {-3, -1, 0, 2};

	solution(a, b);
}