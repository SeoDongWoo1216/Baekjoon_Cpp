#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) 
{
	vector<int> answer;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		for (int j = i + 1; j < numbers.size(); j++)
		{
			answer.push_back(numbers[i] + numbers[j]);
		}
	}
	sort(answer.begin(), answer.end());                                // ����
	answer.erase(unique(answer.begin(), answer.end()), answer.end());  // �ߺ� ����

	for (int i = 0; i < answer.size(); i++)  // ����غ���
	{
		cout << answer[i] << endl;
	}

	return answer;
}

int main()
{
	vector<int> arr1 = { 5,0,2,7 };
	vector<int> arr2 = { 2, 1, 3, 4, 1 };
	vector<int> arr3;
	solution(arr1);
}