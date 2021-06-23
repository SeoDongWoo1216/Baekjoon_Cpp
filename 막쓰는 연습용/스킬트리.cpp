/*
    ���α׷��ӽ� ��ųƮ��
    ��ų�� �����ϴ� ������ �ִ�.(���� ��ų�� �ִ�)
    ���ڹ迭�� �̷���� ��ųƮ���� �־�������, ���ڿ��� ���� ��ų�� �°� �� ������ ����� ��ȯ�ϴ� ����
*/

/*
    ����
    1. �ӽ÷� ���� ���� temp ����
    2. skill_trees �迭�� for������ �˻��ؼ� skill�� ���� ��Ұ������� temp�� ���� �����
    3. temp�� skill�� ���ؼ� ������ �´��� Ȯ��
    4. ������ ������ answer++�ϰ� ��ȯ
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;

    // ��� ����� ��ųƮ�� �˻�
    for (int i = 0; i < skill_trees.size(); i++)
    {
        vector <char> temp;  // �ӽ� ���� temp ����
        
        for (int j = 0; j < skill_trees[i].size(); j++)  // ��ųƮ���� 2���� �迭�̴� for�� 2�� ����
        {
            for (int k = 0; k < skill.size(); k++)
            {
                if (skill_trees[i][j] == skill[k])       // skill_trees �߿� skill�� ��ġ�ϴ� ���ڸ� temp�� ����
                {
                    temp.push_back(skill_trees[i][j]);
                }
            }
        }
        
        int flag = 0;
        for (int j = 0; j < temp.size(); j++)  // temp�� ���̸�ŭ skill�� ���Ͽ� ������ ��ġ�ϴ��� Ȯ��
        {
            if (temp[j] != skill[j])
            {
                flag = 1;
                break;
            }
        }
      
        if (flag == 0)   // ��ġ�ϸ� answer++
        {   
            answer++;
        }
    }
    cout << answer << endl;
    return answer;
}

int main()
{
    solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });

    return 0;
}
