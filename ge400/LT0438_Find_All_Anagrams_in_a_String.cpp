
#include "../header/myheader.h"

class LT0438
{


// detail
// 单数组，保存s,p中每个char的差距。。int变量(初始也是先psz1个元素的，所以psz1后，int变量初始化为单数组中负数的个数)：如果差距为1，++；如果差距为0，--；；这样int为0时，就说明是同素异形体。
// 没有考虑char个数差是负数的情况，因为长度定死psz1个，所以如果有负数(s中char个数多)，那么必然有其他char是s少于p的。此时count必然不为0.

// 直接vector<int> == vector<int>。。。 就可以了，不需要mismatch。。。。

//        int left = 0;
//        int right = 0;
//        vector<int> dict(26, 0);
//        for (char c : p)
//            dict[c - 'a']++;
//        int count = p.size();
//        vector<int> res;
//        while (right < s.size()) {
//            if (right - left == p.size()) {       // 2
//                dict[s[left] - 'a']++;
//                if (dict[s[left] - 'a'] > 0)
//                    count++;
//                left++;
//            }
//            dict[s[right] - 'a']--;                   // 1
//            if (dict[s[right] - 'a'] >= 0)
//                count--;
//            right++;
//            if (count == 0)
//                res.push_back(left);
//        }
//        return res;
// 和单数组一样，但更难。。
// count保存p和 s中片段 的差距。也是不计算差距为负数的情况。。也是依靠psz1.
// 初始也不一样，上面的单数组，初始是s，p中每个char的差。
// 这里初始是p中的char个数。
// 上面的int变量保存的应该是有差距的char的个数。
// 这里的count保存的是p的长度。
// 1在最开始的时候就是计算s，p的每个char的差距。因为最开始只是读入char，没有舍弃char。如果s的前缀就是p的同素异形的话，就会在right==p.size()-1时，触发res.push.
// 然后就是2+1一起，dict保存的是p和s的差距，所以s中移除char的时候，p++。

// count保存的是 p-s的值，，集合{p-(p和s的交集)}中的个数。。 集合p 与 集合p和s的交集 的差集 的个数。



//Runtime: 32 ms, faster than 76.69% of C++ online submissions for Find All Anagrams in a String.
//Memory Usage: 10.3 MB, less than 98.08% of C++ online submissions for Find All Anagrams in a String.

public:
    vector<int> lt0438a(string s, string p)
    {
        vector<int> ans;

        int psz1 = p.size();
        int ssz1 = s.size();
        if (ssz1 < psz1)
            return ans;
        int parr[26] = {0};
        int sarr[26] = {0};

        for (char ch : p)
        {
            parr[ch - 'a']++;
        }

        for (int i = 0; i < psz1; i++)
        {
            sarr[s[i] - 'a']++;
        }

        auto mis = std::mismatch(begin(sarr), end(sarr), begin(parr), end(parr));
        if (mis.first == end(sarr))
            ans.push_back(0);

        int t1, t2;
        for (int i = 0; i < ssz1 - psz1; i++)
        {
            t1 = s[i] - 'a';
            t2 = s[i + psz1] - 'a';
            sarr[t1]--;
            sarr[t2]++;
            if (sarr[t1] == parr[t1] && sarr[t2] == parr[t2])
            {
                mis = std::mismatch(begin(sarr), end(sarr), begin(parr), end(parr));
                if (mis.first == end(sarr))
                    ans.push_back(i + 1);
            }
        }

        return ans;
    }
};

int main()
{
    string s = "abca";
    string p = "abc";

    LT0438 lt;
    vector<int> ans = lt.lt0438a(s, p);

    cout<<endl;
    for_each(ans.begin(), ans.end(), fun_cout);
    cout<<endl;


    vector<int> v1 = {3,2,1,4,5};
    vector<int> v2 = {2,3,4,1,5};
    vector<int> v3 = {3,2,1,4,5};
    cout<<endl<<(v1 == v2)<<", "<<(v1 == v3)<<endl;

    return 0;
}
