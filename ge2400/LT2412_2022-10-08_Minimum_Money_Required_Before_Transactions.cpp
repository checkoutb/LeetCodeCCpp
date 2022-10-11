
#include "../header/myheader.h"

class LT2412
{
public:

    // D

    // �ȿ�Ǯ��
    // �����Ǯ��ʱ�� ������ ����cost
    // 




    // hint is answer
    // ��Ǯ���� ���� [1] ����

    // ��Ǯ���ȸ㡣    ����Ǯ��ͬ���� Ͷ���� ����
    //    Ȼ��׬Ǯ�ģ� ���׬��Ǯ ��ͬ���� Ͷ����ǰ��
    long long lt2412a(vector<vector<int>>& transactions)
    {
        long long ans = 0LL;

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> priq;
        int sz1 = transactions.size();
        for (int i = 0; i < sz1; ++i)
        {
            int t1 = transactions[i][0];
            int t2 = transactions[i][1];


            if (t1 < t2)
            {
                priq.push(std::make_pair(t2 - t1, t1));
            }
            else
            {
                priq.push(std::make_pair(t2 - t1, -t1));
            }
        }

        long long a = 0LL;

        while (!priq.empty())
        {
            a += priq.top().first;
            priq.pop();
            ans = min(ans, a);
        }
        ans = -ans;

        return ans;

        //sort(begin(transactions), end(transactions), [](const vector<int>& v1, const vector<int>& v2) 
        //    {
        //        int t1 = v1[1] - v1[0];
        //        int t2 = v2[1] - v2[0];

        //        if (t1 < 0)
        //        {
        //            if (t2 >= 0)
        //            {
        //                return true;
        //            }
        //            else
        //            {
        //                
        //            }
        //        }
        //        else
        //        {
        //            if (t2 >= 0)
        //            {

        //            }
        //            else
        //            {

        //            }
        //        }

        //    });

    }

};

int main()
{

    LT2412 lt;


    return 0;
}
