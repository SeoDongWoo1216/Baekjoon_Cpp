#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k)
{
	string answer = "";
	int numsize = number.size() - k;

	int start = 0;
	int end = k;

	int max = 0;
	int maxindex = 0;

	for (int i = 0; i < numsize; i++)
	{
		for (int j = start; j <= end; j++)
		{
			if (max < number[j])
			{
				max = number[j];
				maxindex = j;
			}
		}
		answer += max;
		start = maxindex + 1;
		end++;
		max = 0;
	}



	cout << answer << endl;
	return answer;  // 3234를 뽑아야함
}

int main()
{
	solution("1231234", 3);
	return 0;
}

//4177252841 10개 중에 4개를 빼
//           => 6자리를 뽑는거

