#include <stdio.h>
#include <string.h>
#include <stdlib.h>

constexpr auto MAX = 50;
constexpr auto OUT = -6;

typedef struct visited {
    int from_x;
    int from_y;
    int to_x;
    int to_y;
}Visited;

int solution(const char* dirs) {
    int answer = 0;
    int x = 0, y = 0; // �̵� �� ��ǥ
    int nx, ny;        // �̵� �� ��ǥ
    int i, j;         // for��

    // Up, Down, Left, Right 
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    Visited list[MAX] = { 0 };


    for (i = 0; dirs[i] != NULL; i++) {
        nx = ny = OUT;

        // ���⿡ ���� ��ĭ �̵�
        if (dirs[i] == 'U') {
            nx = x + dx[0];
            ny = y + dy[0];
        }
        else if (dirs[i] == 'D') {
            nx = x + dx[1];
            ny = y + dy[1];
        }
        else if (dirs[i] == 'L') {
            nx = x + dx[2];
            ny = y + dy[2];
        }
        else if (dirs[i] == 'R') {
            nx = x + dx[3];
            ny = y + dy[3];
        }
        else break;

        // ��踦 �Ѿ��� ��� 
        if (nx > 5 || nx < -5 || ny > 5 || ny < -5) continue;

        // �ߺ� �˻� 
        for (j = 0; j < i; j++) {
            if (list[j].from_x == x && list[j].from_y == y && list[j].to_x == nx && list[j].to_y == ny) {
                answer--;
                break;
            }
            if (list[j].from_x == nx && list[j].from_y == ny && list[j].to_x == x && list[j].to_y == y) {
                answer--;
                break;
            }
        }

        // �ߺ� �˻� �� ����Ʈ�� ��� 
        // 1. �ߺ��� ���� ���� ��� �ε��� j�� �ش� ���� ��� 
        // 2. �ߺ��� ���� ���� ��� �� �ε����� �� ��ǥ�� ��� 
        if (nx != OUT && ny != OUT) {
            list[j].from_x = x;
            list[j].from_y = y;
            list[j].to_x = nx;
            list[j].to_y = ny;
            answer++;
            x = nx;
            y = ny;
        }
    }

    return answer; // �� ���� ��ȯ
}

int main() {
    int n = solution("LURDLURDLURD");
    printf("ans : %d\n", n);
}