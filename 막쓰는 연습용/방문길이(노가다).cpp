#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _MAX 50

typedef struct location {
    int x;
    int y;
}Location;

typedef struct road {
    Location from;
    Location to;
}Road;

/// <param name="dirs">이동 경로 문자열</param>
/// <returns>걸은 길의 수</returns>
int solution(const char* dirs) {
    int answer = 0;
    int cnt = 0;
    Location list[_MAX] = { 0 };
    Road list_road[_MAX] = { 0 };
    int i;




    for (i = 1; dirs[cnt] != NULL; i++) {
        if (dirs[i - 1] == 'U') {
            list[i].x = list[i - 1].x;
            list[i].y = list[i - 1].y + 1;
        }
        else if (dirs[i - 1] == 'D') {
            list[i].x = list[i - 1].x;
            list[i].y = list[i - 1].y - 1;
        }
        else if (dirs[i - 1] == 'R') {
            list[i].x = list[i - 1].x + 1;
            list[i].y = list[i - 1].y;
        }
        else if (dirs[i - 1] == 'L') {
            list[i].x = list[i - 1].x - 1;
            list[i].y = list[i - 1].y;
        }
        if (list[i].x < -5 || list[i].x > 5 || list[i].y < -5 || list[i].y > 5) {
            list[i].x = list[i - 1].x;
            list[i].y = list[i - 1].y;
        }
        cnt++;
    }
    /*printf("시작 : [0, 0]\n");
    for (int i = 1; i <= cnt; i++) {
       printf("%c : [%d, %d]\n", dirs[i-1], list[i].x, list[i].y);
    }*/

    Road road;
    Location from, to;

    // 점 + 점 => 길 
    for (int i = 1; i <= cnt; i++) {
        from.x = list[i - 1].x;
        from.y = list[i - 1].y;
        to.x = list[i].x;
        to.y = list[i].y;
        road.from = from;
        road.to = to;
        list_road[i - 1] = road;
    }
    int a1, a2, a3, a4, b1, b2, b3, b4;
    for (i = 0; i < cnt; i++) {
        a1 = list_road[i].from.x;
        a2 = list_road[i].from.y;
        a3 = list_road[i].to.x;
        a4 = list_road[i].to.y;

        for (int j = i + 1; j < cnt; j++) {
            b1 = list_road[j].from.x;
            b2 = list_road[j].from.y;
            b3 = list_road[j].to.x;
            b4 = list_road[j].to.y;
            if (a1 == a3 && a2 == a4) {
                answer--;
                break;
            }
            if (a1 == b1 && a2 == b2 && a3 == b3 && a4 == b4) {
                answer--;
                break;
            }
            if (a1 == b3 && a2 == b4 && a3 == b1 && a4 == b2) {
                answer--;
                break;
            }
        }
    }
    answer += cnt;
    return answer;

}

int main() {
    const char dirs[] = "ULURRDLLU";
    int answer = solution(dirs);
    printf("%s : %d\n", dirs, answer);
    const char dirs2[] = "LULLLLLLU";
    answer = solution(dirs2);
    printf("%s : %d\n", dirs2, answer);
    const char dirs3[] = "LURDUL";
    answer = solution(dirs3);
    printf("%s : %d\n", dirs3, answer);

    return 0;
}