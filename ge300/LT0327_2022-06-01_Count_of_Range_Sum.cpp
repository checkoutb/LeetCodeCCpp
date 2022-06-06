
#include "../header/myheader.h"

class LT0327
{
public:


    // D

    // mergeSort

    //int mid = (low + high) / 2, m = mid, n = mid, count = 0;
    //count = mergeSort(sum, lower, upper, low, mid) + mergeSort(sum, lower, upper, mid, high);
    //for (int i = low; i < mid; i++)
    //{
    //    while (m < high && sum[m] - sum[i] < lower) m++;
    //    while (n < high && sum[n] - sum[i] <= upper) n++;
    //    count += n - m;
    //}
    //inplace_merge(sum.begin()+low, sum.begin()+mid, sum.begin()+high);
    //
    // m��n��mid����ֻ��++
    // ���Ա�֤forѭ������ �����Ľ����
    // amazing
    // ���������и����⣬֮ǰ���� ���ڸ��������� prefix sum���� �ϸ�����ģ�������ѡ�� + INT_MAX ���������������ˡ���
    // ��ô������ô���㣺[1,1,-2,1,1], lower=upper=2����Ϊ����� m��n �������޷�������䰡�������������ܼ���ġ���
    // [0]+[1] �� [3]+[4] ���� ��һ��/���²� ��mergeSort�м�������� ���������� for(0-1) { +[2-4] }. �����ܼ��㵽[0]+[1]+[2]..+[4]


    // gg


    //.... lower upper ������ֱ��+�ġ���
    // �������Ƿ�Ӧ��ȫ��+INT_MAX��ת�������� ����֮��prefix sum���� �ǽ��� ��+INT_MAX+2��+1�Ƿǽ���+2������ ���� |INT_MAX| + 1 = |INT_MIN|
    // ����Ϳ��� lower_bound ...
    int lt0327a(vector<int>& nums, int lower, int upper)
    {
        int sz1 = nums.size();
        long add = 2L + INT_MAX;
#ifdef __test
        add = 10;
#endif

        long low = lower + add;
        long up = upper + add;
        vector<long> vl(sz1, 0L);
        vl[0] = nums[0];
        for (int i = 1; i < sz1; ++i)
        {
            vl[i] = vl[i - 1] + nums[i];
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            long l2 = low + nums[i];
            long u2 = up + nums[i];
            vector<long>::iterator ita = std::lower_bound(begin(vl), end(vl), l2);      // >= l2
            auto itb = upper_bound(begin(vl), end(vl), u2);     // > u2
            ans += std::distance(itb, ita);
#ifdef __test
            cout << ans << ", " << i << endl;
#endif
        }
        return ans;
    }

};

int main()
{

    LT0327 lt;

    vector<int> vi{ -2,5,-1 };
    int l{ -2 }, u{ 2 };

    cout << lt.lt0327a(vi, l, u) << endl;

    return 0;
}
