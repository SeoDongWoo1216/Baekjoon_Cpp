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
    int x = 0, y = 0; // 이동 전 좌표
    int nx, ny;        // 이동 후 좌표
    int i, j;         // for문

    // Up, Down, Left, Right 
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };

    Visited list[MAX] = { 0 };


    for (i = 0; dirs[i] != NULL; i++) {
        nx = ny = OUT;

        // 방향에 따라 한칸 이동
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

        // 경계를 넘었을 경우 
        if (nx > 5 || nx < -5 || ny > 5 || ny < -5) continue;

        // 중복 검사 
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

        // 중복 검사 후 리스트에 기록 
        // 1. 중복된 길이 있을 경우 인덱스 j는 해당 길을 덮어씀 
        // 2. 중복된 길이 없을 경우 새 인덱스에 길 좌표를 기록 
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

    return answer; // 길 갯수 반환
}

int main() {
    int n = solution("LURDLURDLURD");
    printf("ans : %d\n", n);
}