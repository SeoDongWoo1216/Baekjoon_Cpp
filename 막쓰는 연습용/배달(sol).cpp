/*
    ���α׷��ӽ� ���

    (����a, ����b, ����a���� ����b���� �ɸ��� �ð�) ���� �̷���� 2���� �迭 road,
    ������ ���� N, �ɸ��� �ð� K �� �־��� ���¿��� 1�� �������� K �ð� �̳��� ��� ������ ������ ������ ���ϴ� ����
*/

/*
    ����
    1. �ִ� ������ ���� ��ŭ �迭�� �޸𸮿� �Ҵ� : graph[51][51], memset �Լ� ���
    2. �־����� road �迭�� graph�� �Ҵ�(�̶� min�� ����ؼ� �ּ��� ��θ� ���� => ������� 1 -> 2 �� ���� ��ΰ� ������ �������)
    3. ���� -> ������ ���� ��� ��θ� ����
    4. 1�� �������� �ٸ� �������� �ɸ��� ��θ� �˻��ؼ� �ɸ��� �ð��� K �����̸� answer�� ++�ؼ� ��ȯ
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
    memset(graph, INF, sizeof(graph));  // graph�� �޸𸮿� �Ҵ�


    // �迭�� ��θ� ����
    // min�� ����ϴ� ������ ������� 1 -> 2 ��ΰ� 1���� �ƴϰ� 2�� �̻��϶� �� �߿��� �ּ� �ð��� �迭�� �����ϱ� ���� ���.
    for (int i = 0; i < road.size(); i++)
    {
        graph[road[i][0]][road[i][1]] = graph[road[i][1]][road[i][0]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
    }


    // �� �������� �ٸ� �������� �ɸ��� �ð��� ���
    // graph[i][j] : i -> j �ɸ��� �ð��� ����
    // graph[i][k] + graph[k][j] : i -> k -> j �ɸ��� �ð� (i -> j �� ���� �濡 k�� ��ġ�� �� ���� �� �� �ִ� ������ �˻�)
    // min�� ���� i -> j �� �� ����?  i -> k -> j �� �� ����? �� �˻��ϰ� graph[i][j] �� ������
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


    // 1 -> 1,  2 -> 2 (�ڱ��ڽ�)�� ���� �ð��� 0�̴ϱ� 0���� �ʱ�ȭ����
    for (int i = 1; i <= N; i++) graph[i][i] = 0;


    // ���� 1�� �������� �� ������ ���� �ð��� 3�ð� ���ϸ� answer++ ����
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
    solution(5, road1, 3);   // 4 ���
    solution(6, road2, 4);   // 4 ���
    return 0;
}