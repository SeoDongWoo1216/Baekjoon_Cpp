/*
    프로그래머스 : 영어끝말잇기
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, vector<string> words)
{
	vector<int> answer;
	vector<string> temp;

	int count = 1;
	int Humancount = 1;
	int flag = 1;
	for (int i = 1; i < words.size(); i++)
	{
		Humancount++;
		count++;

		if (words[i].front() == words[i - 1].back())
		{
			for (int j = 0; j < i; j++)
			{
				if (words[i] == words[j])
				{
					flag = 0;
					break;
				}
			}
		}
		else
		{
			answer.push_back(Humancount);
			answer.push_back(count);
			cout << Humancount << " " << count << endl;
			break;
		}
		if (flag == 0)
		{
			answer.push_back(Humancount);
			answer.push_back(count);
			cout << Humancount << " " << count << endl;
			break;
		}
		if (Humancount == n) Humancount = 1;
		if (count == n) count = 1;




	}
	return answer;
}

int main()
{
	vector<string> 개어렵네 = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
	//                           1        2       3       1        2       3        1          2       3
	solution(3, 개어렵네);  // 3명이서 temp의 끝말잇기시작



	vector<string> 매우어렵네 = { "hello", "one", "even", "never", "now", "world", "draw" };
	solution(2, 매우어렵네);
}
