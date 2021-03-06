/*
    프로그래머스 배달

    (마을a, 마을b, 마을a에서 마을b까지 걸리는 시간) 으로 이루어진 2차원 배열 road,
    마을의 개수 N, 걸리는 시간 K 가 주어진 상태에서 1번 마을에서 K 시간 이내에 배달 가능한 마을의 개수를 구하는 문제
*/

/*
    구현
    1. 최대 마을의 개수 만큼 배열을 메모리에 할당 : graph[51][51], memset 함수 사용
    2. 주어지는 road 배열을 graph에 할당(이때 min을 사용해서 최소의 경로를 저장 => 예를들어 1 -> 2 로 가는 경로가 여러개 있을경우)
    3. 마을 -> 마을로 가는 모든 경로를 구함
    4. 1번 마을에서 다른 마을까지 걸리는 경로를 검사해서 걸리는 시간이 K 이하이면 answer를 ++해서 반환
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int graph[51][51];
int INF = 10001;

int solution(int N, vector<vector<int> > road, int K)
{
    int answer = 0;
    memset(graph, INF, sizeof(graph));  // graph를 메모리에 할당


    // 배열에 경로를 저장
    // min을 사용하는 이유는 예를들어 1 -> 2 경로가 1개가 아니고 2개 이상일때 그 중에서 최소 시간만 배열에 저장하기 위해 사용.
    for (int i = 0; i < road.size(); i++)
    {
        graph[road[i][0]][road[i][1]] = graph[road[i][1]][road[i][0]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
    }


    // 각 마을에서 다른 마을까지 걸리는 시간을 계산
    // graph[i][j] : i -> j 걸리는 시간을 뜻함
    // graph[i][k] + graph[k][j] : i -> k -> j 걸리는 시간 (i -> j 를 가는 길에 k를 거치면 더 빨리 갈 수 있는 길인지 검사)
    // min을 통해 i -> j 가 더 적니?  i -> k -> j 가 더 적니? 를 검사하고 graph[i][j] 에 저장함
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }


    // 1 -> 1,  2 -> 2 (자기자신)은 가는 시간이 0이니까 0으로 초기화해줌
    for (int i = 1; i <= N; i++) graph[i][i] = 0;


    // 만약 1번 마을에서 각 마을로 가는 시간이 3시간 이하면 answer++ 해줌
    for (int i = 1; i <= N; i++)
    {
        if (graph[1][i] <= K) answer++;
    }

    cout << answer << endl;
    return answer;
}

int main()
{
    vector<vector<int>> road1 = { {1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2} };
    vector<vector<int>> road2 = { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} };
    solution(5, road1, 3);   // 4 출력
    solution(6, road2, 4);   // 4 출력
    return 0;
}