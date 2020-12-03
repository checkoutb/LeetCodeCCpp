
#include "../header/myheader.h"

class LT1525
{
public:

// D D

//        int left[26];
//        int right[26];
//        memset(left, 0, sizeof left);
//        memset(right, 0, sizeof right);
//        int leftCount = 0;
//        int rightCount = 0;
// 遍历一次 获得 char:count.
// 再遍历，count--， ==0，说明右侧没有这个char， 这样就知道 左右2侧 char的个数。

// 。。。。应该可以提前退出的，当左侧的char个数 > 右侧时， 就可以退出了。


//int numSplits(string s) {
//    int l[26] = {}, r[26] = {}, d_l = 0, d_r = 0, res = 0;
//    for (auto ch : s)
//        d_r += ++r[ch - 'a'] == 1;
//    for (int i = 0; i < s.size(); ++i) {
//        d_l += ++l[s[i] - 'a'] == 1;
//        d_r -= --r[s[i] - 'a'] == 0;
//        res += d_l == d_r;
//    }
//    return res;
//}


//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Number of Good Ways to Split a String.
//Memory Usage: 12.4 MB, less than 17.43% of C++ online submissions for Number of Good Ways to Split a String.
// 似乎是 中间某段 连续相同char 的长度。
    int lt1525a(string s)
    {
        int sz1 = s.size();
        vector<int> v1(sz1);
        vector<int> v2(sz1);
        int arr[123] = {0};
        int cnt = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (arr[s[i]] == 0)
            {
                cnt++;
                arr[s[i]] = 1;
            }
            v1[i] = cnt;
        }
        fill(begin(arr), end(arr), 0);
        cnt = 0;
        for (int i =  sz1 - 1; i >= 0; --i)
        {
            if (arr[s[i]] == 0)
            {
                cnt++;
                arr[s[i]] = 1;
            }
            v2[i] = cnt;
        }
        int ans = 0;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            if (v1[i] == v2[i + 1])
                ans++;
        }
        return ans;
    }

};

int main()
{
    vector<string> vs = {"aacaba","abcd","aaaaa","acbadbaada"};

    LT1525 lt;

    for (string& s : vs)
        cout<<lt.lt1525a(s)<<endl;


    return 0;
}
