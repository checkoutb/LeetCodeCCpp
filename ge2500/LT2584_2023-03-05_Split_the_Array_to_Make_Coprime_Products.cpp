
#include "../header/myheader.h"

class LT2584
{
public:

    // D



    // 1000 就够了。  如果无法 被 1000以内 的 质数 整除干净的话， 剩余的那个数 也是一个 质数。
    // 所以 如果 testcase 中包含大量的 9999997 (不知道是不是质数，大约就这种) 这种，就tle。
    //      因为 一个 9999997 我就得 循环 prm， prm 有7万多 元素。

    // if you know, you know.. if you don't know, you never know.   虽然我记得 以前也有这种的:
    //          质数 只需要 求 sqrt(max) 就可以了，  剩余的 那个， 如果非1， 那么 也是一个prime。




    // g

    // tle
    // 本来以为是 mod, 所以 欧拉，费马 ，套不上去。。。
    // 应该是 前面半部分 和 后半部分 不存在 相同的 质因子
    // 100 0000 以内的质数。 8万个。。。
    // hint 也是这种， 但是 100万内的质数 真的没有办法吧。
    // 不必预先求。 或者 预先求出 一部分。
    // 先试下全部求出吧。
    int lt2584a(vector<int>& nums)
    {
        static vector<bool> vb(1000001, false);      // vst
        static vector<int> prm;
        if (prm.empty())
        {
            for (int i = 2; i < 1000000; ++i)       // 增加 cout 后， 用 testcase，跑，leetcode 只打印一次。  但是还是 tle了
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
