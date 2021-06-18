#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool isSosu(int n)
{
	if (n < 2) return false;

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) return false;
	}

	return true;
}


int solution(string numbers) 
{
	
	vector<int> num;
	vector<int> allnum;
	int len = numbers.size();

	for (int i = 0; i < len; i++)
	{
		num.push_back(numbers[i] - '0');
		allnum.push_back(numbers[i] - '0');
	}

	sort(num.begin(), num.end());

	do 
	{
		for (int i = 2; i <= len; i++)
		{
			string temp = "";
			for (int j = 0; j < i; j++)
			{
				temp += num[j] + '0';
			}
			allnum.push_back(stoi(temp));
		}

	} while(next_permutation(num.begin(), num.end()));


	sort(allnum.begin(), allnum.end());
	allnum.erase(unique(allnum.begin(), allnum.end()), allnum.end());


	int answer = 0;
	for (int i = 0; i < allnum.size(); i++)
	{
		if(isSosu(allnum[i]))
		{
			answer++;
		}
	}


	cout << answer << endl;
	return answer;
}

int main()
{
	solution("9999999");
	//solution("011");

	return 0;
}