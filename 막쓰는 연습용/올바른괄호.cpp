#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = false;     // ��ȯ�� ���� bool�� ����

    int count = 0;           // '('  , ')' �� ���� ��ȭ�� �� count

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')       // '('�� ���� count�� ++ ����
        {
            count++;
        }
        else if (s[i] == ')')  // ')' �� ���� count�� -- ����
        {
            count--;
        }

        if (count < 0)        // count�� ������ �Ǹ� false��ȯ�ϰ� �Լ� ����
        {
            return false;
        }
        // count�� ������ �Ǿ��� => ���� �̻��� �������� �����ϰ� false ��ȯ
        // 1. �� ó�� ���� )�� ������ => ¦�� �� �°� �������� ������ ����
        // 2. �߰��� ������ �Ǿ����� => for������ ���ڿ��� ������ ������ ���� ������ �������Ƿ�
        //                           ')'�� �߰��� �� ���ٴ� ���̹Ƿ� ¦�� �ȸ��� => ����

    }

    // �߰��� ����Ǵ��� ���� ���������� '('  ,  ')' �� ī��Ʈ������ ���ǹ�
    if (count == 0)        // count�� 0�� �Ǿ��� => ( ) ¦�� �¾Ҵ� => true
    {
        answer = true;
    }
    else                   // count�� 0�� �ƴϴ� => ( ) ¦�� �ȸ´� => false
    {
        answer = false;
    }

    return answer;
}

int main()
{
    string s1("()()");
    string s("(())()");
    string s4(")()(");
    string s3("(()(");
    string s2("())");
    

    solution(s);
}