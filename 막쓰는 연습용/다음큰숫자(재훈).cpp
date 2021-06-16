#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer;
    int cnt_m = 1, cnt_k = 1, m = n, k = n + 1, i = 2;

    while (1)
    {
        while (m / 2 > 1)
        {
            if (m % 2 == 1) cnt_m++;
            m = m / 2;

            if (k % 2 == 1) cnt_k++;
            k = k / 2;
        }
        m = n;
        k = n + i;
        i++;
        if (cnt_m == cnt_k)
        {
            answer = k - 1;
            break;
        }
        cnt_m = 1, cnt_k = 1;
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;
    printf("%d", solution(n));
}