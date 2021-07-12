/*
  백준 3009번 문제 : 네번째 점
  다른 3좌표가 주어졌을때 좌표끼리 직사각형이되는 다른 1좌표를 구하는 문제
*/
#include <iostream>
using namespace std;

int main()
{
	int x, y;
	int tempX = 0;
	int tempY = 0;
	int t = 3;
	while (t)
	{
		cin >> x >> y;
		tempX = tempX ^ x;
		tempY = tempY ^ y;
		t--;
	}
	cout << tempX << " " << tempY << endl;
 	return 0;
}