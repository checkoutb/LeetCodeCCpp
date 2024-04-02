
#include "../header/myheader.h"
#include <array>

class LT1998
{
public:

    // D D

    // uf[max_element] 使用值作为下标，uf
    // copy + sort,  遍历， 如果 有序的[i] != 原始[i] 且 这2个值 不能uf， 那么就false。




// Runtime
// 267ms
// Beats76.43%of users with C++
// Memory
// 74.62MB
// Beats65.00%of users with C++

    // 我感觉我看过解答。。。就是 uf， prime。
    bool gcdSort(vector<int>& nums)
    {
        std::array<bool, 318> arrb { {false} };
        std::vector<int> prm(1, 2);         // ... {1, 2}
        for (int i = 3; i < arrb.size(); i += 2)
        {
            if (!arrb[i])
            {
                prm.push_back(i);
                for (int j = i + i; j < arrb.size(); j += i)
                {
                    arrb[j] = true;
                }
            }
        }
        int sz1 = nums.size();
        std::vector<int> uf(sz1, -1);

        vector<int> nums2(nums);

        // for (int i = 0; i < prm.size(); ++i)
        for (int p : prm)
        {
            int idx = -1;
            // for (int j = 0; j < )
            for (int i = 0; i < sz1; ++i)
            {
                if (nums2[i] % p == 0)
                {
                    if (idx == -1)
                        idx = ufa(uf, i);
                    else
                    {
                        int t2 = ufa(uf, i);
                        if (t2 != idx)
                        {
                            uf[t2] = idx;
                        }
                    }
                    while (nums2[i] % p == 0)
                    {
                        nums2[i] /= p;
                    }
                }
            }
        }

        map<int, vector<int>> map3;
        for (int i = 0; i < sz1; i++)
        {
            if (nums2[i] >= 2)
                map3[nums2[i]].push_back(i);
        }
        for (auto& p : map3)
        {
            vector<int>& vi2 = p.second;
            int idx = ufa(uf, vi2[0]);
            for (int i = 1; i < vi2.size(); ++i)
            {
                int t2 = ufa(uf, vi2[i]);
                if (t2 != idx)
                    uf[t2] = idx;
            }
        }

        // vector<pair<int, int>> vp;
        // for (int i = 0; i < )

        map<int, vector<int>> map2;
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = ufa(uf, i);
            map2[t2].push_back(nums[i]);
            nums[i] = t2;
        }

        for (auto& p : map2)
        {
            // sort(begin(p), end(p));
            // std::range::sort(p.second);
            sort(rbegin(p.second), rend(p.second));
        }
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = nums[i];
            nums[i] = map2[t2].back();
            map2[t2].pop_back();
            if (i > 0 && nums[i] < nums[i - 1])
                return false;
        }
#ifdef __test
        cout<<map2.size()<<'\n';
        showVectorInt(uf);
        showVectorInt(prm);
        showVectorInt(nums);
#endif
        return true;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return (uf[idx] == -1) ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int main()
{

    LT1998 lt;

    // myvi v {7,21,3};
    myvi v {5,2,6,2};
    // myvi v {1239,1652,2181.......,2181,3635,727,710};

    cout<<lt.gcdSort(v)<<endl;

    return 0;
}
