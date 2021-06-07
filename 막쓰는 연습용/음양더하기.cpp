/*
    프로그래머스 : 음양더하기
    길이가 같은 정수배열, bool형 배열을 받고
    bool형 배열의 true인 인덱스에는 양수,
                  false인 인덱스에는 음수로해서 정수배열들의 합을 반환하는 문제
*/

/*
    구현
    1. bool형 배열의 false인 인덱스를 구하기
    2. 해당하는 인덱스의 정수배열의 요소에 -1을해서 음수로 만들어줌
    3. 정수배열의 모든 요소를 더해줌
    4. result값 반환
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) 
{
    int result = 0;
    for (int i = 0; i < signs_len; i++)     // bool형 배열 요소가 false인 인덱스에 -1을 곱해서 정수 배열 요소에 음수로 만들어줌
    {
        if (signs[i] == false)
        {
            absolutes[i] *= -1;
        }
    }

    for (int i = 0; i < absolutes_len; i++)  // 모든 정수배열요소의 합을 result에 저장
    {
        result += absolutes[i];
    }
    
    printf("%d\n", result);
    return 0;
}

int main()
{
    int absolutes[3] = { 4, 7, 12 };
    bool signs[3] = { true, false, true };

    solution(absolutes, 3, signs, 3);
}