/*
���� 7568�� ���� (��ġ)
Ű�� ü���� �Է¹ް� Ű�� ü�� �� �� Ŭ�� ��ġ�� �� ũ�� ��� ���Ѵ�.

������� A(x,y), B(p,q) �϶�
x > p, y > q �̸� A�� B���� ��ġ�� �� ũ��.

�ٵ� ���� A(45, 181), B(55, 171) �̸�
45 < 55, 181 > 173 �̹Ƿ� A�� �����Դ� ũ���� Ű�� B�� �� ũ�Ƿ� ���� ũ�ٰ� �� �� ����.
���� ���� ������ ���Եȴ�.

�̶� ���� 2���̸� ������ �з��� 3���� ���� 1, 2, 2, 4, 5 ���� ��µ�.

Ƚ���� 2 <= N <= 50  => �迭�� ũ�Ⱑ �ɿ���
*/

/*
���� ����
1. ����ü�� ü��, Ű, ��ũ ����
2. ����ü �迭 �����Ŀ� �Է¹��� Ƚ����ŭ for������ �Է¹���
3. for�� �ι��Ἥ ���� ���, ���� ����� ���ؼ� ���� ����� �� ũ�� ���� ����� ����� +1 ����
4. ����� ���
*/

#include <iostream>
using namespace std;


typedef struct person
{
	int weight;      // ü��
	int height;      // Ű
	int rank = 1;    // ��� 1������ ����
}Human;


int main()
{
	Human arr[51];
	int count = 0;
	int num;

	cin >> num;

	// Ƚ�� �Է¹ޱ�
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i].weight >> arr[i].height;
	}


	// ����, ü�� ��
	for (int i = 0; i < num; i++)
	{
		for (int j = i+1; j < num; j++)
		{
			if (arr[i].weight < arr[j].weight && arr[i].height < arr[j].height)   // ó������ (������ - 1) ���� ��
			{
				arr[i].rank++;
			}
			else if (arr[i].weight > arr[j].weight && arr[i].height > arr[j].height) // �������� ���
			{
				arr[j].rank++;
			}
		}
	}

	// ��� ���
	for (int i = 0; i < num; i++)
	{
		cout << arr[i].rank << " ";
	}
}