
#include "../header/myheader.h"

class LT1856
{
public:


    // D

    // monostack, stack��������һ�����Լ�С�ģ� ��ô������һ�� ��ʼ �����ڣ� min ���� �Լ���





    // tle
    // prefix sum, segment tree������ ����������
    // ���� ��ʹ segment tree�� ��Ȼ��Ҫ for for��
    // �о�Ӧ���� �������飬 Ȼ�� split by ��С��ֵ�� Ȼ�� �������� ��С��ֵ �����з֡� ����ʲôʱ�����?
    // ���� for for dp�� ��¼[i][j] �����ڵ� sum �� min�� Ȼ�� [i][j+1] ���ܼ���� sum �� min �ˡ� ����Ҳ�� for for
    // ����˵ forfor �������ģ�  dp ��������
    int lt1856a(vector<int>& nums)
    {
        int64_t ans = 0;
        vector<pair<int64_t, int64_t>> vp;               // <sum, min>
        size_t sz1 = nums.size();
        for (size_t i = 0; i < sz1; ++i)
        {
            vector<pair<int64_t, int64_t>> vp2;

            int val = nums[i];

            for (pair<int64_t, int64_t>& p : vp)
            {
                ans = max(ans, p.first * p.second);
                vp2.emplace_back(std::make_pair(p.first + val, min(p.second, (int64_t) val)));
            }

            vp2.emplace_back(make_pair((int64_t) val, (int64_t) val));

            swap(vp, vp2);
        }
        for (auto& p : vp)
        {
            ans = max(ans, p.first * p.second);
        }
        return ans % 1000000007;
    }

};

int main()
{

    LT1856 lt;

    //myvi v = { 1,2,3,2 };
    //myvi v = { 2,3,3,1,2 };
    myvi v = { 3,1,5,6,4,2 };

    cout << lt.lt1856a(v) << endl;

    return 0;
}
