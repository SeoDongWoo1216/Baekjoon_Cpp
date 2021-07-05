/*
  백준 3009번 문제 : 네번째 점
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