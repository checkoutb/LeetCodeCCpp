
#include "../header/myheader.h"

class LT1477
{
public:

    // D D


    // prefix sum ，转 map<sum, idx> 由于value>0，所以prefix sum 没有重复的。
    // 然后 for(0..sz1-1)，根据当前下标的前缀和，找到 后面的 第一个能够组成target的下标，如果有，那么 min(ans,(当前数组长度 + min(之前的数组的长度)))
    //      然后 更新 min(遇到的数组长度)


    // 用 数组，表示 这个下标之前的最小的 数组长度。
    // for， 如果碰到一个 target的数组，那么就 加上  数组[st-1] 的值。




//Runtime: 224 ms, faster than 56.59 % of C++ online submissions for Find Two Non - overlapping Sub - arrays Each With Target Sum.
//Memory Usage : 82.6 MB, less than 50.29 % of C++ online submissions for Find Two Non - overlapping Sub - arrays Each With Target Sum.
    // ... non-overlapping 是指不完全重叠。。 而不是 没有任何重叠部分。
    // .....不过看了代码，好像就是这样的。。
    // ......想的是 完全不重叠， 写的是 不完全重叠， 然后错了，就以为 需要 不完全重叠。。。
    int lt1477a(vector<int>& arr, int target)
    {
        vector<pair<int, int>> vp;
        int sum2 = 0;
        int st = 0;
        int sz1 = arr.size();
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += arr[i];
            while (sum2 > target)
            {
                sum2 -= arr[st++];
            }
            if (sum2 == target)
            {
                vp.push_back({ st, i });            // [st, i]
            }
        }
        int ans = INT_MAX;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> priq;

        for (pair<int, int>& p : vp)
        {
            priq.push({ p.second - p.first + 1, p });
#ifdef __test
            cout << priq.size() << " --- " << p.first << " - " << p.second << endl;
#endif
        }

        for (int i = 0; i < vp.size(); ++i)
        {
            int st = vp[i].first;
            int en = vp[i].second;

            while ((!priq.empty()) && priq.top().second.first <= en)        // <= st 就是不完全重叠
                priq.pop();

            if (priq.empty())
                break;
            ans = std::min(ans, int(en - st + 1 + (priq.top().first)));
        }

        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

    LT1477 lt;

    //myvi v = { 3,2,2,4,3 };
    //int t = 3;

    //myvi v = { 1,6,3,4,7 };
    //int t = 7;

    //myvi v = { 4,3,2,6,2,3,4 };
    //int t = 6;

    myvi v = { 1,7,1 };
    int t = 8;

    cout << lt.lt1477a(v, t) << endl;

    return 0;
}
