
#include "../header/myheader.h"

class LT0903
{
public:

// D

// Intuition.....................................
// dp[][] 第一维表示 准备执行 那个s[] .（还没有执行）
//      第二维 表示 还有几个比当前选择的枚举 小
//      值表示 有几种   。。 初始s[0][x]全1.
//            if (S[i] == 'I')
//                for (int j = 0, cur = 0; j < n - i; j++)
//                    dp[i + 1][j] = cur = (cur + dp[i][j]) % mod;
//            else
//                for (int j = n - i - 1, cur = 0; j >= 0; j--)
//                    dp[i + 1][j] = cur = (cur + dp[i][j + 1]) % mod;


// 只需要大小，所以  1,2,3     101,102,103   所能组成的 排列个数 是一样的。 子问题？
// 是的，  1,2,3   11,16,100001  所能组成的排列数 也一样的。
// 200个元素，  下一步就是199个元素， 200个任取一个，然后199个元素的排列个数， 200 * 199个排列个数。  不 0或199 不能取。不然 下一个就选不了了。
// 从前往后，还是从后往前？
// 200个元素，第一位是199个可能的选择，，，不，第二位是根据第一位的。。所以不是直接*。。
// D   1    10
// DD  1    210
// DDD 1    3210
// DDDD1    43210
// DI       102 201

// tle
    int lt0903a(string s)
    {
        tmp = vector<int>(222, 0);
        int sz1 = s.size();
//        set<int> set2;
//        for (int i = 0; i <= sz1; ++i)
//            set2.insert(i);
        vector<int> vi(sz1 + 1, 0);
        unordered_map<int, int> map2;
        for (int i = 1; i <= sz1; ++i)
            vi[i] = i;
        int sum2 = std::accumulate(begin(vi), end(vi), 0);
        for (int i = 0; i <= sz1; ++i)
        {
            vi[i] = -1;
            sum2 -= i;
            #ifdef __test
            tmp[0] = i;
            #endif // __test
            dfsa1(s, 0, vi, map2, sum2, i);
            vi[i] = i;
            sum2 += i;
        }
        return ans;
    }
    vector<int> tmp;
    const int A = 100000;
    int ans = 0;

    int dfsa1(string& s, int idx, vector<int>& vi, unordered_map<int, int>& map2, int sum2, int prev)
    {
        if (idx == s.size())
        {
            #ifdef __test
            for (int i = 0; i <= idx; ++i)
            {
                cout<<tmp[i]<<", ";
            }
            cout<<endl;
            #endif // __test
            ans++;
            return 1;
        }
//        if (map2.find(prev * A + sum2) != map2.end())
//        {
//            #ifdef __test
//            cout<<"cache.";
//            #endif // __test
//            return map2[prev * A + sum2];
//        }
        #ifdef __test
//        cout<<idx<<", "<<prev<<", "<<s[idx]<<endl;
        #endif // __test
        int ans = 0;
        if (s[idx] == 'D')      // >
        {
            for (int i = 0; i < prev; ++i)
            {
                #ifdef __test
//                cout<<i<<endl;              // .....cao, 又出现了，  没有写return，i<prev失效。。死循环。数组越界。。
                #endif // __test
                if (vi[i] != -1)
                {
                    #ifdef __test
//                    showVectorInt(vi);
//                    cout<<idx<<": "<<i<<endl;
                    tmp[idx + 1] = i;
                    #endif // __test
                    vi[i] = -1;
                    ans += dfsa1(s, idx + 1, vi, map2, sum2 - i, i);
                    vi[i] = i;
                }
            }
        }
        else
        {
            for (int i = prev + 1; i < vi.size(); ++i)
            {
                if (vi[i] != -1)
                {
                    #ifdef __test
//                    showVectorInt(vi);
//                    cout<<idx<<", "<<i<<endl;
                    tmp[idx + 1] = i;
                    #endif // __test
                    vi[i] = -1;
                    ans += dfsa1(s, idx + 1, vi, map2, sum2 - i, i);
                    vi[i] = i;
                }
            }
        }
        return ans;
    }

};

int main()
{
    string s = "DID";

    LT0903 lt;

    cout<<lt.lt0903a(s)<<endl;

    return 0;
}
