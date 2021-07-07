#include <iostream>
using namespace std;

int main()
{
	int TestCase = 0;
	int x1, y1, r1;
	int x2, y2, r2;
	
	cin >> TestCase;

	for (int i = 0; i < TestCase; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		//int r = (r1 * r1) + (r2 * r2);
		float  d = ( (x2 - x1) * (x2 - x1) ) + ( (y2 - y1) * (y2 - y1) );

		int flag = 0;

	
		
		cout << flag << endl;
	}

	return 0;
}