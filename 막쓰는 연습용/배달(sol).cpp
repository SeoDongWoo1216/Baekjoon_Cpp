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
    memset(graph, INF, sizeof(graph));  // graph�� �޸𸮿� �Ҵ�

    // �迭�� ��θ� ����
    for (int i = 0; i < road.size(); i++)  
    {
        graph[road[i][0]][road[i][1]] = graph[road[i][1]][road[i][0]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
    }

    // ???
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

    // 1 -> 1, 2 -> 2�� 0�̴ϱ� 0���� �ʱ�ȭ����
    for (int i = 1; i <= N; i++) graph[i][i] = 0;


    // ���� 3�� ��θ� ������ ������ 3 ���ϸ� answer++ ����
    for (int i = 1; i <= N; i++) 
    {
        if (graph[1][i] <= K) answer++;
    }

    cout << answer << endl;
    return answer;
}

int main()
{
    vector<vector<int>> road = { {1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2} };
    solution(5, road, 3);   // 4 ���
    return 0;
}