
#include "../header/myheader.h"

class LT1526
{
public:

    // D D

    //t.insert(t.begin(), 0);
    //t.push_back(0);
    //int cost = 0, top = 0;
    //for (int x : t) {
    //    if (top < x) cost += (x - top);
    //    top = x;
    //}
    //return cost;

    //int sum = target[n - 1];
    //for (int i = n - 2; i >= 0; i--) {
    //    if (target[i] > target[i + 1]) sum += (target[i] - target[i + 1]);
    //}

    //int ans = arr[0];
    //for (int i = 1; i < arr.size(); i++)
    //{
    //    if (arr[i] > arr[i - 1])
    //    {
    //        ans += arr[i] - arr[i - 1];
    //    }
    //}


//https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/discuss/754682/Wall-of-bricks
    // 所有的增量。。


//Runtime: 136 ms, faster than 87.11 % of C++ online submissions for Minimum Number of Increments on Subarrays to Form a Target Array.
//Memory Usage : 73.2 MB, less than 63.46 % of C++ online submissions for Minimum Number of Increments on Subarrays to Form a Target Array.
    int lt1526d(vector<int>& target)
    {
        int sz1 = target.size();
        int ans = 0;
        int llst = target[0];      // last last
        int lst = -1;       // last
        int st = 0;
        for (; st < sz1 && target[st] == llst; ++st)
        {
            ;
        }
        int t3 = 0;
        if (st == sz1)
            return target[0];

        lst = target[st];
        if (llst > lst)
        {
            ans += llst;
            t3 = lst;
        }
        for (; st < sz1; ++st)
        {
            if (target[st] == lst)
                continue;
            int t2 = target[st];
            if (lst > t2 && lst > llst)     // ding
            {
                ans += lst - t3;
                t3 = lst;
            }
            else if (lst < t2 && lst < llst)     // gu
            {
                t3 = lst;
            }
            llst = lst;
            lst = t2;
        }
        if (target[sz1 - 1] > t3)
            ans += target[sz1 - 1] - t3;
        return ans;
    }


    // .......
    // 山顶，山谷。
    // 出现下降 就是山顶；出现上升 就是山谷
    int lt1526c(vector<int>& target)
    {
        //target.insert(begin(target), 0);
        //target.push_back(0);
        int sz1 = target.size();
        int ans = 0;
        int t2 = 0;
#ifdef __test
        showVectorInt(target);
#endif
        int st = 0;
        while (st + 1 < sz1 && target[st] <= target[st + 1])
            st++;
        for (int i = st + 1; i < sz1; ++i)
        {
            // .......

//            if (target[i - 1] > target[i] && (i == 1 || target[i - 2] <= target[i - 1]))      // ding
//            {
//                ans += target[i - 1] - t2;
//#ifdef __test
//                cout << "iiii " << i << ", " << ans << ", " << target[i - 1] << " - " << t2 << endl;
//#endif
//                t2 = target[i - 1];
//            }
//            else if (target[i - 1] < target[i] && (i == 1 || target[i - 2] >= target[i - 1]))     // gu
//            {
//                t2 = target[i - 1];
//#ifdef __test
//                cout << " eeeee- " << i << ", " << t2 << endl;
//#endif
//            }
        }
        if (target[sz1 - 1] > t2)
            ans += target[sz1 - 1] - t2;
        return ans;
    }


    // error
    // 按0分段，记录最后一段的 最小值。。 每次下降，就需要+ans
    int lt1526b(vector<int>& target)
    {
        int sz1 = target.size();
        int ans = 0;
        int mn = INT_MAX;
        target.push_back(0);
        for (int i = 1; i < sz1; ++i)
        {
            if (target[i] < target[i - 1])
            {
                ans += target[i - 1] - target[i];
                if (target[i] == 0)
                {
                    mn = INT_MAX;
                }
                else
                {
                    mn = min(target[i], mn);
                }
            }
        }
        return ans;
    }


    // tle。。。 应该用 差。 .. [100000,15,100000,15,100000,11.....]
    // 找到山顶，向两侧扩散。
    // 出现下降，就肯定需要
    // 前面肯定可以充满，所以只需要向后。
    int lt1526a(vector<int>& target)
    {
        int ans = 0;
        int sz1 = target.size();
        vector<int> vi(target.size(), 0);
        for (int i = 1; i < target.size(); ++i)
        {
            if (target[i] < target[i - 1])
            {
                if (target[i - 1] == vi[i - 1])
                    continue;
                int mx = target[i - 1];
                ans += mx - vi[i - 1];
                for (int j = i - 1; j < sz1; ++j)
                {
                    mx = min(mx, target[j]);
                    if (mx <= vi[j])
                        break;
                    vi[j] = mx;
                }
#ifdef __test
                cout << i << ", " << mx << ", " << ans << endl;
                showVectorInt(vi);
#endif
            }
            else if (target[i] > target[i - 1])
            {
                ;
            }
        }

#ifdef __test
        showVectorInt(vi);
#endif

        ans += -vi[sz1 - 1] + target[sz1 - 1];
        return ans;
    }

};

int main()
{

    LT1526 lt;

    //myvi v = { 1,2,3,2,1 };

    //myvi v = { 3,1,1,2 };       // 4

    //myvi v = { 3,1,5,4,2 };     // 7

    //myvi v = { 1,1,5,5,4,5,1,1 };       // 6

    myvi v = { 7,10,3,6,3,3,3,5,5,5,9 };        // 19

    cout << lt.lt1526d(v) << endl;

    return 0;
}
