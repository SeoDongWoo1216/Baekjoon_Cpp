/*
    ���α׷��ӽ� ���� �ڵ� ç���� ����2 : ����� ������ ����
    left, right �� ���� ���� �־����� left~right ������ ����� ������ ���ؼ�
    ����� ������ ¦���� +, ����� ������ Ȧ���� -�� ���� return �ϴ� ����
*/

/*
    Ǯ��
    2�� for������ ù��° for���� left ~ right ���� ����
                  �ι�° for���� 1���� ù��° for���� ������ŭ ����
    �ι�° for������ ����� ã���鼭 count�� ++����
    �ι�° for���� �������� count�������� result�� ¦��, Ȧ�� �϶� ���ϰų� ����
*/

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;



int solution(int left, int right)
{
    int result = 0;
    for (int i = left; i <= right; i++)   // left~right���� for�� ����
    {
        int count = 0;
        for (int j = 1; j <= i; j++)      // 1���� i(ù��° for������)���� for�� ����
        {
            if (i % j == 0)               // ���� ����� count++
            {
                count++;
            }
        }

        if (count % 2 == 0)               // ����� ������ ¦���� result�� �ش� ������ ������
        {
            result += i;
        }
        else if (count % 2 != 0)          // ����� ������ Ȧ���� result�� �ش� ������ ����
        {
            result -= i;
        }
    }

    return result;                        // result�� ��ȯ
}

int main()
{
    int a, b;
    cin >> a >> b;
    int res = solution(a, b);
    cout << res << endl;
}