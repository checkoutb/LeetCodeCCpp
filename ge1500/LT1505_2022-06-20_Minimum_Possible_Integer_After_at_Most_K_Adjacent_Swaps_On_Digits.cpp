
#include "../header/myheader.h"

class LT1505
{
public:

    // D

    // Segment Tree， Fenwick Tree




    // g


    // 应该要 再维护一个 arr[10]， 代表 有多少 。。 不
    // 应该是 swap后， 修改 arr[10]，如果 arr[x] 的值 小于 被提前的那个值的下标，则 ++ ； 否则不需要动。   这个是 额外的arr[10]。 需要在 计算 距离的时候 考虑到。
    // 不， 如果 一直往后，导致  之前被提前的下标 在 前面了， 那么 还需要 下标差值 -- 。  需要维护 修改的下标集合。。


    //string lt1505b(string num, int k)
    //{
    //    int arr[10] = { 0 };                // next idx's index
    //    std::fill(begin(arr), end(arr), -1);

    //    string ans(num.size(), ' ');
    //    int ansi = 0;
    //    for (int i = 0; i < num.size(); ++i)
    //    {
    //        if (num[i] == 'a')
    //            continue;
    //        int n = num[i] - '0';
    //        int chose = -1;
    //        if (k > 0)
    //        {
    //            for (int a = 0; a < n; ++i)
    //            {
    //                while (arr[a] <)
    //            }
    //        }
    //    }
    //}


    // error
    // ... swap 后， 距离就发生了变化。。。
    string lt1505a(string num, int k)
    {
        vector<pair<int, vector<int>>> vp(10);
        for (int i = 0; i < num.size(); ++i)
        {
            vp[num[i] - '0'].second.push_back(i);
        }
        string ans(num.size(), ' ');
        int ansi = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            if (num[i] == 'a')
                continue;

            int n = num[i] - '0';
#ifdef __test
            //cout << n << "..." << endl;
#endif
            int chose = -1;
            if (k > 0)
                for (int a = 0; a < n; ++a)
                {
#ifdef __test
                    //cout << vp[a].first << ", " << vp[a].second.size() << ", " << k << endl;
#endif

                    while (vp[a].first < vp[a].second.size() && (vp[a].second[vp[a].first] < i))
                        vp[a].first++;

                    if (vp[a].first < vp[a].second.size() && (vp[a].second[vp[a].first] - i <= k))
                    {
                        k -= vp[a].second[vp[a].first] - i;
                        chose = vp[a].second[vp[a].first];
                        vp[a].first++;
                        break;
                    }
                }
#ifdef __test
            //cout << i << ", " << chose << ", " << ansi << endl;
#endif
            if (chose == -1)
            {
                ans[ansi++] = num[i];
            }
            else
            {
                ans[ansi++] = num[chose];
                num[chose] = 'a';
                i--;
            }
#ifdef __test
            cout << num << " - " << ans << ", " << k << endl;
#endif
        }
        return ans;
    }


    // 感觉会tle。  3万个a，k是1万。 那就 小于 3万*1万。  。。 findMinInRange 少了 判断 nowi+i<s.size()

    // 相邻才能swap。
    // 就是向后k个范围内，最小的，和自己交换，然后 k-交换次数。
    // 是 最小的 放到 当前位置， 其它的 整体后移一位。
    //string lt1505a(string num, int k)
    //{
    //    while (k > 0)
    //    {

    //    }
    //}

    //int findMinInRange(string& s, int nowi, int k)
    //{
    //    char mnch = s[nowi];
    //    int mni = nowi;
    //    for (int i = 1; i <= k; ++i)
    //    {
    //        if (s[i + nowi] < mnch)
    //        {
    //            mnch = s[i + nowi];
    //            mni = nowi + i;
    //        }
    //    }
    //    return mni == nowi ? -1 : mni;
    //}

};

int main()
{

    LT1505 lt;

    //string s = "4321";
    //int k = 4;

    //string s = "100";
    //int k = 1;

    //string s = "36789";
    //int k = 1233;

    string s = "9438957234785635408";           // "0345989723478563548"
    int k = 23;


    cout << lt.lt1505a(s, k) << endl;

    return 0;
}
