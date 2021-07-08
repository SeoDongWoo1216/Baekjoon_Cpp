/*
   ���α׷��ӽ� ����/ť : �ٸ��� ������ Ʈ��
   Ʈ���� ������ ����, �ٸ��� �ö� �� �ִ� Ʈ�� ��, �ٸ��� �ߵ� �� �ִ� ���԰� �־�����
   ��� Ʈ���� �ٸ��� �ǳʷ��� �ּ� �� �ʰ� �ɸ����� return �ϴ� ����
*/

/*
   ����
   1. ���� ó�� ���°� ���� ���� ����������(FIFO) ����� ���÷��� ť�� ���� Ǯ�����ϴ�.
   2. �ɸ��� �ð�(Time), �ٸ��� Ʈ������ ������(weightSum), �ٸ��� Ʈ������Ʈ�� Queue, ���° Ʈ������ �˰����� idx ����
   
   3. �ٸ��� Ʈ���� �ö󰥶����� weightSum�� ���Ը� ���ϰ�, �� Ʈ���� ť�� ����
   4. ť�� ���� ���̸鼭 .size()�� �ٸ��� ���̿� �������� Ʈ���� �����ߴٴ� �ǹ��̹Ƿ� Ʈ���� ���鼭 ���Ե� ����(�̶� idx++����)
   5. ���� ������ Ʈ���̸� ���� �������� ���ϰų� ť�� �������� �ٸ� ���̸�ŭ Time�� �����༭ �����Ŵ
*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int Time = 0;          // �ɸ� �ð� (answer)
    int weightSum = 0;     // �ٸ� �� Ʈ������ ���� ��
    queue<int> on_bridge;  // �ٸ� �� Ʈ�� ����Ʈ
    int idx = 0;           // Ʈ���� �ε���(���° Ʈ������)

    while (1)
    {
        Time++;  // 1�� �߰�

        // �ٸ��� Ʈ���� ����� �ٸ� ���̿� ���� = Ʈ���� ���������� �������
        if (on_bridge.size() == bridge_length) 
        {
            weightSum = weightSum - on_bridge.front(); // Ʈ���� ������ŭ �����տ��� ���� Ʈ���� ���Ը� ����
            on_bridge.pop();    
        }


        if (weightSum + truck_weights[idx] <= weight)  // Ʈ�� �߰��� �� ������ �߰�
        { 
            if (idx == truck_weights.size() - 1)       // ������ ������ Ʈ���� ��� => �ٸ����̸�ŭ Time�� �����ְ� ����
            {                                          // (������ Ʈ���� �ٸ� ���̸�ŭ���� ������Ǵϱ�)
                Time += bridge_length;
                break;
            }

            on_bridge.push(truck_weights[idx]);       // ���� Ʈ���� ť�� �߰�
            weightSum += truck_weights[idx];          // �߰��� Ʈ���� ���� �����տ� �߰�
            idx++;                                    // ���� ������ Ʈ���� �������� idx�� ++����
        }
        else 
        {
            on_bridge.push(0);                        // Ʈ���� �� �� �ø��� 0���� Ʈ�� �о��ֱ�
        }
    }

    cout << Time << endl;
    return Time;
}

int main()
{
    solution(2, 10, { 7,4,5,6 });
    solution(100, 100, { 10 });
    return 0;
}