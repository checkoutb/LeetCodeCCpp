
#include "../header/myheader.h"

class LT2542
{
public:

    // D D

    // 按 nums2 从大到小。




    //Runtime502 ms
    //    Beats
    //    31.28 %
    //    Memory113.3 MB
    //    Beats
    //    19.4 %
    long long lt2542a(vector<int>& nums1, vector<int>& nums2, int k)
    {
        long long ans = 0LL;
        int sz1 = nums1.size();
        priority_queue<tuple<int, int, int>> priq;

        for (int i = 0; i < sz1; ++i)
        {
            priq.push(make_tuple(nums1[i], nums2[i], i));
        }

        long long sum2 = 0LL;
        int cnt = 0;
        map<int, vector<int>> map2;
        int n1, n2, idx;
        while (cnt < k)
        {
            ++cnt;
            std::tie(n1, n2, idx) = priq.top();
            priq.pop();

            sum2 += n1;
            map2[n2].push_back(idx);
        }
        ans = max(ans, sum2 * (map2.begin()->first));

        while (!priq.empty() && priq.size() >= map2.begin()->second.size())
        {
            for (int i : map2.begin()->second)
            {
                sum2 -= nums1[i];
            }
            cnt -= map2.begin()->second.size();
            //map2.erase(map2.begin());

            while (!priq.empty())
            {
                std::tie(n1, n2, idx) = priq.top();
                priq.pop();

                if (n2 > map2.begin()->first)
                {
                    map2[n2].push_back(idx);
                    sum2 += n1;
                    ++cnt;
                    if (cnt == k)
                        break;
                }
            }
            map2.erase(map2.begin());
            if (cnt == k)
            {
                ans = max(ans, sum2 * (map2.begin()->first));
            }
        }

        return ans;
    }

};

int main()
{

    LT2542 lt;

    myvi v1 = { 1,3,3,2 };
    myvi v2 = { 2,1,3,4 };
    int k = 3;

    //myvi v1 = { 4,2,3,1,1 };
    //myvi v2 = { 7,5,10,9,6 };
    //int k = 1;

    cout << lt.lt2542a(v1, v2, k) << endl;

    return 0;
}
