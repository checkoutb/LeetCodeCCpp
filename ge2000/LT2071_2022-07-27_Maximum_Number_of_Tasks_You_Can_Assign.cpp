
#include "../header/myheader.h"

class LT2071
{
public:


    // D

    // Ҫ����͵�x������ ��ǿ׳��x���� ��  ��Ϊ ��x�� ��Ȼ���γ���ԡ�
    // ������ܣ���+ҩ�����ҩ�������� x���͡�   ��������




    // g


    // �ǳԣ�����������
    // index>=m ��task ��������ġ�
    // �ԣ����Ǻ������жϡ�
    // ��
    // ������� Ҫ�� < ��ҩ�� < ����ҩ��  ����ʱ��ѡ ��ҩ�Ļ��� ���ܻ� �ٵġ�   10 < 5+6 < 12 ,   ����һ������ 15������һ����13��������
    //      �������� �˲����ܶ��� ����ġ���
    int lt2071a(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        int sz1 = tasks.size();
        int sz2 = workers.size();

        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers));

        priority_queue<int> priq;           // who eat pills

        int tki = 0;
        int wki = 0;

        for (int mxtki = min(sz1, sz2); tki < mxtki; ++tki)
        {

        }

    }


    // a single task������ ��� ����ִ���ˡ���

    // ����������Ҫ�� �������������ԡ�  ����>=����
    // ������ħҩ�� ���� strength���������� һ��������һ����
    // ��û��ʱ��Ҫ��ֱ�Ӹ� �������� ��һ���� Ȼ�� ȫ������ �Ϳ����˰�������
    // �����ᱻ���ġ�
    // �Ȱ���ȵ� ����������
    // Ȼ�󡣡� ������
    // �Ȱ� ������С�Ļ� ���ˡ� �� ����>=Ҫ��� ��С�Ĺ��ˡ�
    // Ȼ������� Ҫ��-strength ���ˡ�
    int lt2071a(vector<int>& tasks, vector<int>& workers, int pills, int strength)
    {
        sort(begin(tasks), end(tasks));
        sort(begin(workers), end(workers));

        int tki = 0;
        int wki = 0;
        for (; tki < tasks.size(); ++tki)
        {
            int t2 = tasks[tki];
            while (wki < workers.size() && workers[wki] < t2)
            {
                wki++;
            }
            if (wki == workers.size())
                break;

            workers[wki] -= t2;
            tasks[tki] = -1;
        }

        wki = 0;
        for (; tki < tasks.size() && pills > 0; ++tki)
        {
            if (tasks[tki] == -1)
                continue;

            int t2 = tasks[tki];
            while (wki < workers.size() && workers[wki] + strength < t2)
            {
                wki++;
            }
            if (wki == workers.size())
                break;

            pills--;
            workers[wki] -= t2;
            tasks[tki] = -1;
        }
        return tki;
    }

};

int main()
{

    LT2071 lt;

    //myvi t = { 3,2,1 };
    //myvi w = { 0,3,3 };
    //int p = 1;
    //int s = 1;


    myvi t = { 74, 41, 64, 20, 28, 52, 30, 4, 4, 63 };
    myvi w = { 38 };
    int p = 0;
    int s = 68;


    cout << lt.lt2071a(t, w, p, s) << endl;

    return 0;
}
