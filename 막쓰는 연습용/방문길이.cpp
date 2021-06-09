/*
	방문길이

*/
#include <iostream>
using namespace std;



struct coordinate
{
	int x = 5;
	int y = 5;
}XY;




int solution(string dirs)
{
	bool boolary[11][11] = { false };
	int startX = XY.x;
	int startY = XY.y;
	boolary[startX][startY] = true;   // 출발지는 트루
	

	int count = 0;          

	for (int i = 0; i < dirs.size(); i++)
	{
		if (dirs[i] == 'U')
		{
			if (XY.y + 1 > 10) continue;
			XY.y++;
		}

		else if (dirs[i] == 'D')
		{
			if (XY.y - 1 < 0) continue;
			XY.y--;
		}

		else if (dirs[i] == 'R')
		{
			if (XY.x + 1 > 10) continue;
			XY.x++;
		}

		else if (dirs[i] == 'L')
		{
			if (XY.x - 1 < 0) continue;
			XY.x--;
		}

		if (boolary[XY.x][XY.y] == 1 && boolary[startX][startY] == 1) continue;

		boolary[XY.x][XY.y] = true;
		count++;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (boolary[i][j] == true) count++;
		}
	}

	cout << count << endl;
	return count;
}

int main()
{
	char dirs[] = "ULURRDLLU";
	char dirs1[] = "LULLLLLLU";
	char dirs3[] = "RRRRRRRRRRRRRRRRRRRRRUUUUUUUUUUUUULU";
	char dirs2[] = "LURDLURDLURDLURDRULD";

	/*for (int i = 0; i < sizeof(dirs) / sizeof(dirs[0]); i++)  // 문자열 출력용
	{
		cout << dirs[i] << endl;
	}*/

	solution(dirs);
	
}