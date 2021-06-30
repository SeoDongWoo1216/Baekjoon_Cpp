/*
  ���α׷��ӽ� : �Ǻ���ġ ��
  F(0) = 0, F(1) = 1 �϶� 1�̻��� n�� ���� F(n) = F(n-2) + F(n-1)�� �Ǻ���ġ ���� ����
  
  2 �̻��� n�� �Է����� n��° �Ǻ���ġ ���� 1234567���� ���� �������� �����ϴ� ����
*/

/*
  ���� 
  1. �Ǻ���ġ ���� F(n) = F(n-2) + F(n-1) ��Ģ�� ������. 
  2. 
  (ù��° c) = a + b
  (�ι�° c) = b + (ù��° c) �� �ǹǷ�
  c���� a + b, a���� b, b���� c�� ���Խ�����
  3. �Ǻ���ġ ���� 1234567���� ���� �������� �����϶�� �����Ƿ� 
    c�� ���Ҷ����� ���������� ���ؼ� ���� ��ȯ
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n)
{
    int a = 0; // n - 2
    int b = 1; // n - 1
    int c = 0; // n

    if (n == 1) return 1;

    for (int i = 2; i <= n; i++)
    {
        // f(n) = f(n - 2) + f(n - 1)
        c = (a + b) % 1234567;
        a = b;
        b = c;
    }
    cout << c << endl;
    return c;
}

int main()
{
    solution(3);   // 2
    solution(5);   // 5
    return 0;
}