
#include "../header/myheader.h"

class LT0354
{
public:


//        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &a, pair<int, int> &b) {
//                    return a.first < b.first || a.first == b.first && a.second > b.second;
//            });
//        vector<pair<int, int>> dp;
//        for (auto envelope: envelopes) {
//            int lo = 0, hi = dp.size();
//            while (lo < hi) {
//                int mid = (lo + hi) / 2;
//                if (dp[mid].second >= envelope.second)
//                    hi = mid;
//                else
//                    lo = mid + 1;
//            }
//            if (lo == dp.size())
//                dp.push_back(envelope);
//            else
//                dp[lo] = envelope;
//        }
//        return dp.size();

// 排序优先用first，在dp搜索用second
// 2次搜索，第一次按first优先，第二次second优先
// 由于是forEach，所以lo不可能大于dp.size().
// 应该是第一次first小，第二次second小，合并就是first小且second小，但是怎么证明？
// forEach，保证dp中现有的first必然小于等于 envelop。
//

// 第一次是first小，如果first相同，second大，，放前面。
// 所以第二次排序，碰到first相同的情况时，本次的second必然<=dp中的second。就是走dp[lo] = envelope，不走上面。
// 而且first相同，说明它应该是最后一个位置。foreach，first相同，说明本次的first>=dp中的first。

// 首先按first小，second大 排序，第二次排序的时候就能保证first必然大于已有的，只要确定second大于已有的就可以进入dp了。
// 第二次的时候如果second小，那么就更新dp[lo]，因为后续的 envelop first都是大于现有的，所以无所谓的。
// 所以dp应该不是有序(套娃的顺序)的，[1,10],[2,20], 再加入 [3,5]，会把[1,10]踢出去。但是数量是对的。
//            else
//                dp[lo] = envelope;
// 这个好像没有意义。。。不，有意义，[1,10][2,20],,,加入[2,15],加入[3,18]


// 第二遍排序的时候，只考虑second，如果second大于dp中最大second，则push_back，因为第一次的时候second是倒序的，所以second>dp中最大
// 就意味着 first>dp中最大.
// second加入dp后属于第二大，lo会是dp的最大下标。那么会刷新dp的最后一个。这个是为了上面的 [1,10][2,20],,,加入[2,15],加入[3,18]
// 把最后一个刷新成[2,15]. 如果dp最后一个first和second的1st相同，刷新没有问题，如果不相同，由于后续的first会大于现有的，也没有问题。
// 第一种是，first不变，换一个second小点的，第二种是first变大，second变小，由于已经按first排序，所以无所谓的。
// 其他情况就说明 second的first < dp中最大first，那么刷不刷新dp 无所谓的。这个不会出现，因为第一次排序了。




//        for (int i = 0; i < envelopes.size(); i++) {
//            int height = envelopes[i][1];
//            auto it = lower_bound(dp.begin(), dp.end(),
//                                  height);
//
//            if (it == dp.end())
//                dp.push_back(height);
//            else
//                *it = height;
//        }



//Runtime: 648 ms, faster than 11.35% of C++ online submissions for Russian Doll Envelopes.
//Memory Usage: 14.5 MB, less than 5.95% of C++ online submissions for Russian Doll Envelopes.

    // 排序后dp，选择排序应该能排序时dp。好多应该都可以，只不过复杂点，需要合并的时候刷新所有。
    int lt0354a(vector<vector<int>>& envelopes)
    {
        int result = 0;
        int sz1 = envelopes.size();
        if (sz1 == 0)
            return result;
//        int sz2 = encelopes[0].size();
        int t1 = 0;
        int t2 = 0;
        int arr1[sz1] = {};
//        for (int i = 0; i < sz1; i++)
//            arr1[i] = 1;
        for (int i = 0; i < sz1; i++)
        {
            t1 = i;
            t2 = envelopes[i][0];
            for (int j = i + 1; j < sz1; j++)
            {
                if (t2 > envelopes[j][0])               // ...>....
                {
                    t2 = envelopes[j][0];
                    t1 = j;
                }
            }
            swap(envelopes[i], envelopes[t1]);

//            t1 = i;
            t2 = arr1[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if ((envelopes[j][0] < envelopes[i][0]) && (envelopes[j][1] < envelopes[i][1]))
                {
                    if (arr1[j] > t2)               // 直接可以 dp[i] = Math.max(dp[i], 1 + dp[j]);
                    {
                        t2 = arr1[j];
//                        t1 = j;
                    }
                }
            }
            arr1[i] = t2 + 1;
        }

        #ifdef __test
        cout<<endl;
        for (auto& i : arr1)
            cout<<i<<", ";
        cout<<endl;
        for (vector<int>& p : envelopes)
        {
            for (int& i : p)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

        for (int i = sz1 - 1; i >= 0; i--)
        {
            if (result < arr1[i])
                result = arr1[i];
        }
        return result;
    }
};

int main()
{
//    vector<vector<int>> vv = {{5,4},{6,4},{6,7},{2,3}};

    // 37 / 85,,dp的时候，不能直接break，要找到之前最大的。而不是碰到一个就break
    vector<vector<int>> vv = {{1,2},{2,3},{3,4},{4,5},{5,6},{5,5},{6,7},{7,8}};

    LT0354 lt;

    cout<<endl<<endl<<lt.lt0354a(vv)<<endl;

    return 0;
}
