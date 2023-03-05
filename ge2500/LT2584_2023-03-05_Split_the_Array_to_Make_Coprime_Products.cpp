
#include "../header/myheader.h"

class LT2584
{
public:

    // D



    // 1000 �͹��ˡ�  ����޷� �� 1000���� �� ���� �����ɾ��Ļ��� ʣ����Ǹ��� Ҳ��һ�� ������
    // ���� ��� testcase �а��������� 9999997 (��֪���ǲ�����������Լ������) ���֣���tle��
    //      ��Ϊ һ�� 9999997 �Ҿ͵� ѭ�� prm�� prm ��7��� Ԫ�ء�

    // if you know, you know.. if you don't know, you never know.   ��Ȼ�Ҽǵ� ��ǰҲ�����ֵ�:
    //          ���� ֻ��Ҫ �� sqrt(max) �Ϳ����ˣ�  ʣ��� �Ǹ��� �����1�� ��ô Ҳ��һ��prime��




    // g

    // tle
    // ������Ϊ�� mod, ���� ŷ�������� ���ײ���ȥ������
    // Ӧ���� ǰ��벿�� �� ��벿�� ������ ��ͬ�� ������
    // 100 0000 ���ڵ������� 8���������
    // hint Ҳ�����֣� ���� 100���ڵ����� ���û�а취�ɡ�
    // ����Ԥ���� ���� Ԥ����� һ���֡�
    // ������ȫ������ɡ�
    int lt2584a(vector<int>& nums)
    {
        static vector<bool> vb(1000001, false);      // vst
        static vector<int> prm;
        if (prm.empty())
        {
            for (int i = 2; i < 1000000; ++i)       // ���� cout �� �� testcase���ܣ�leetcode ֻ��ӡһ�Ρ�  ���ǻ��� tle��
            {
                if (!vb[i])
                {
                    for (int j = i + i; j <= 1000000; j += i)
                        vb[j] = true;

                    prm.push_back(i);
                }
            }
        }

        map<int, int> map2;
        //map<int, int> map3;

        //vector<int> v2(prm.size());
        //vector<int> v3(prm.size());

        vector<int> lst(prm.size());
        int sz1 = nums.size();
        int t2 = 0;
        
        vector<vector<int>> vvi(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            t2 = nums[i];
            for (int j = 0; j < prm.size() && t2 != 1; ++j)
            {
                bool b2 = false;
                while (t2 % prm[j] == 0)
                {
                    t2 /= prm[j];
                    if (!b2)
                    {
                        b2 = true;
                        vvi[i].push_back(j);
                        lst[j] = i;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i <= ans; ++i)
        {
            for (int j : vvi[i])
            {
                ans = max(ans, lst[j]);
            }
        }
        if (ans > sz1 - 2)
            return -1;
        return ans;
    }

};

int main()
{

    LT2584 lt;

    myvi v = { 4,7,8,15,3,5 };


    cout << lt.lt2584a(v) << endl;

    v = { 4,7,15,8,3,5 };

    cout << lt.lt2584a(v) << endl;


    return 0;
}
