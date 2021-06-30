/*
  프로그래머스 : 피보나치 수
  F(0) = 0, F(1) = 1 일때 1이상의 n에 대해 F(n) = F(n-2) + F(n-1)인 피보나치 수에 대해
  
  2 이상의 n이 입력됬을때 n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 문제
*/

/*
  구현 
  1. 피보나치 수는 F(n) = F(n-2) + F(n-1) 규칙을 따른다. 
  2. 
  (첫번째 c) = a + b
  (두번째 c) = b + (첫번째 c) 가 되므로
  c에는 a + b, a에는 b, b에는 c를 대입시켜줌
  3. 피보나치 수를 1234567으로 나눈 나머지를 리턴하라고 했으므로 
    c를 구할때마다 나머지값을 구해서 값을 반환
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