/*
	���α׷��ӽ� Lv2 : ���� ū ����
	n�� ���� ū ���ڸ� �����ϴ� ����.
	1. n�� ���� ū ���ڴ� n���� ū �ڿ���
	2. n�� ���� ū ���ڿ� n�� 2������ ��ȯ������ 1�� ������ ����.
	3. n�� ���� ū ���ڴ� ���� 1, 2�� �����ϴ� �� �� ���� ������
*/

/*
	����
	1. �Է¹��� ���� 2���� ��ȯ �������� 1�� ���� ���ϱ�
	2. �Է¹��� �� + 1 �� 2���� ��ȯ�������� 1�� ���� ���ϱ�
	3. ���� 1, 2 �� 1�� ������ ���ٸ� ����
	4. ���� 1�� ������ ���� �ʴٸ� 2�� while������ 1�� ������Ű�鼭 ���ѹݺ�
*/


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n)
{
	int answer = 0;

	int temp = n;      // �Է¹��� ���� temp�� ����
	int tempcount = 0; // 2���� ��ȯ������ 1�� count ���� ����


	// 2���� ��ȯ�ϸ鼭 1�� count�ϴ� while��
	while (temp)
	{
		if(temp % 2 == 1) tempcount++;  
		temp = temp / 2;
	}
	

	// ���� ���ڸ� ã������ while��
	while (1)
	{
		int rescount = 0;  // 2���� ��ȯ������ 1�� count ���� ����
		int res = ++n;     // n�� ++�ϸ鼭 ã���� ����
		while (res)        // res�� 2���� ��ȯ
		{
			if (res % 2 == 1) rescount++;  // 2������ ��ȯ������ 1�� ���� count����
			res /= 2;
		}
		if (tempcount == rescount) break;  // temp�� 1���� == res�� 1������ ������ while �� ����
	}
	
	answer = n;            // while���� ��������� n�� ���� ���
	cout << n << endl;

	return answer;
}

int main()
{
	solution(78);
	solution(15);

	return 0;
}