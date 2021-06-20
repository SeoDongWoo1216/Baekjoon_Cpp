/*
	���α׷��ӽ� ����Ž�� Lv2 : �Ҽ�ã��
	���ڷ� �̷���� ���ڿ� numbers�� �־������� �� ������ �������� ���� �� �ִ� �Ҽ��� ����� ���ϴ� ����
*/

/*
	����
	1. ������ �̷���� ���ڿ��� �ɰ���(num ����, allnum ���Ϳ� ����)
	2. next_permutation �Լ��� �̿��ؼ� �� ������ ������ ã�Ƽ� allnum�� ����
	3. allnum�� �ߺ� ���� �� �Ҽ��� ã�Ƽ� ��ȯ
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


/// <summary>
/// �Ҽ��� ã�� �Լ�
/// </summary>
bool isSosu(int n)
{
	if (n < 2) return false;     // ���� 0, 1�̸� �Լ� ����

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) return false;  // 2���� n-1 ���� ������ ���� ����������°� ������ �Ҽ��� �ƴϹǷ� �Լ� ����
	}

	return true;     // ������� ������ �Ҽ��̹Ƿ� true ��ȯ
}


/// <summary>
/// solution
/// </summary>
int solution(string numbers)
{

	vector<int> num;             // �� �ڸ����� �ɰ����� �޴� ����
	vector<int> allnum;          // ��� ���ڸ� ���� ����
	int len = numbers.size();

	for (int i = 0; i < len; i++)   // ���ڿ��� �� �ڸ��� �ɰ���
	{
		num.push_back(numbers[i] - '0');
		allnum.push_back(numbers[i] - '0');
	}

	sort(num.begin(), num.end());   // next_permutation �Լ��� �������� ����

	do
	{
		for (int i = 2; i <= len; i++)    // i�� 2���� �����ϴ� ������ 2�ڸ��� ~ len�ڸ������� ���ϱ� ����
		{
			string temp = "";             // ���������� ���� �ӽ� ���ڿ� ����
			for (int j = 0; j < i; j++)   // 0���� numbers�� �迭 ũ�⸸ŭ for�� ����
			{
				temp += num[j] + '0';
			}
			allnum.push_back(stoi(temp)); // ������ ���ڸ� ������ ��ȯ�ؼ� allnum�� ����
		}

	} while (next_permutation(num.begin(), num.end()));  // ���ڸ� ������


	// �ߺ�����
	sort(allnum.begin(), allnum.end());
	allnum.erase(unique(allnum.begin(), allnum.end()), allnum.end());


	// �Ҽ� ã��(������ ��Ҹ� �ϳ��� �˻��ؼ� �Ҽ����� �Ǻ�)
	int answer = 0;
	for (int i = 0; i < allnum.size(); i++)
	{
		if (isSosu(allnum[i]))  // ���� �Ҽ��� answer�� ++����
		{
			answer++;
		}
	}

	// �Ҽ������� answer�� ��ȯ
	cout << answer << endl;
	return answer;
}

int main()
{
	solution("1234");
	//solution("011");

	return 0;
}




/*
do while�� ��

// numbers = "1234"   �� ���÷� ���

len = numbers.size();  �̹Ƿ� len = 4

do
	{
		for (int i = 2; i <= len; i++)     // i�� 2���� 4���� for�� ����
		{
			string temp = "";  
			for (int j = 0; j < i; j++)    // 0���� i���� for�� ����  // i�� 2�� 2�ڸ���, i�� 3�̸� 3�ڸ���, i�� 4�� 4�ڸ����� �Ǵ� ����
			{
				temp += num[j] + '0';      // �ӽ� ������ ������ ������ ����(12, 23, 34, 13, ... , 123, 234, 124, ... , 4�ڸ��� ���)
			}
			allnum.push_back(stoi(temp));  // ������ ���ڸ� ������ ��ȯ�ؼ� allnum�� ����
		}

	} while(next_permutation(num.begin(), num.end()));  // ���ڸ� ������

*/