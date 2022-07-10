
#include "../header/myheader.h"

class LT2332
{
public:


    // D D


    //for (int i = 0; i < buses.size(); i++) {
    //    int count = 0;
    //    while (count < capacity && j < m && passengers[j] <= buses[i]) {
    //        count++;
    //        if (j == 0 || (j && passengers[j] > passengers[j - 1] + 1))
    //            ans = passengers[j] - 1;
    //        j++;
    //    }
    //
    //    if (count < capacity && (j == 0 || passengers[j - 1] != buses[i])) {
    //        ans = buses[i];
    //    }
    //}

    // for ѭ���� ֱ�Ӽ��� ans��

    

        //07 / 10 / 2022 18 : 37	Accepted	319 ms	66.3 MB	cpp
        //07 / 10 / 2022 18 : 36	Runtime Error	N / A	N / A	cpp
        //07 / 10 / 2022 18 : 34	Wrong Answer	N / A	N / A	cpp
        //07 / 10 / 2022 18 : 32	Runtime Error	N / A	N / A	cpp
//Runtime: 319 ms, faster than 50.00 % of C++ online submissions for The Latest Time to Catch a Bus.
//Memory Usage : 66.3 MB, less than 50.00 % of C++ online submissions for The Latest Time to Catch a Bus.
    // bus �뿪��ʱ�䣬 �˿�����ʱ��
    // �˿͵���ʱ�� <= bus�뿪ʱ�� �� bus ������ �Ϳ����ϳ�
    // �˿ͻ��Ŷӡ�
    // ���� �����ʱ�䣬 ���ʱ��㣬�㵽��վ�������ϳ���
    // �Ǿ����� ���һ�� �ϳ����ˣ� ����滻��(������1��)�� �ҾͿ����ϳ��ˡ�  ��Ȼ����û���Ļ�����㡣
    // �����ƣ�����ͬʱ�����ô�͵���ǰ����һ����λ��
    int lt2332a(vector<int>& buses, vector<int>& passengers, int capacity)
    {
        sort(begin(buses), end(buses));
        sort(begin(passengers), end(passengers));

        int sz1 = buses.size();
        int sz2 = passengers.size();

        int ibus = 0;
        int ipas = 0;
        int cnt = 0;

        for (; ibus < sz1; ++ibus)
        {
            int leave = buses[ibus];
            cnt = 0;
            for (int i = 0; i < capacity && ipas < sz2 && passengers[ipas] <= leave; ++i)
            {
                ++ipas;
                cnt++;
            }

        }
        --ipas;         // last passenger

#ifdef __test
        cout << ipas << endl;
#endif

        if (ipas == -1)                         // ...
        {
            return buses[ibus - 1];
        }

        if (cnt < capacity)
        {
            //return buses[ibus - 1];
            if (buses[ibus - 1] > passengers[ipas])             // .
                return buses[ibus - 1];
        }


        int ans = passengers[0] - 1;

        for (int i = ipas; i >= 1; --i)
        {
            if (passengers[i - 1] != passengers[i] - 1)
            {
                ans = passengers[i] - 1;
                break;
            }
        }
        
        return ans;
    }

};

int main()
{

    LT2332 lt;

    //myvi v = { 10,20 };               // 16
    //myvi v2 = { 2,17,18,19 };
    //int cap = 2;
    
    //myvi v = { 20,30,10 };              // 20
    //myvi v2 = { 19,13,26,4,25,11,21 };
    //int cap = 2;

    //myvi v = { 2 };             // 1
    //myvi v2 = { 2 };
    //int cap = 2;

    myvi v = { 3 };
    myvi v2 = { 4 };
    int cap = 1;

    cout << lt.lt2332a(v, v2, cap) << endl;

    return 0;
}
