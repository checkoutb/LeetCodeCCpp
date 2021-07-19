
#include "../header/myheader.h"

class LT1898
{
public:

// D D

//    int get(string s, string p, vector<int> &rem, int k){
//        for(int i=0; i<k ; i++)
//        {
//            s[rem[i]]='*';
//        }
// ...  188ms


//    int l = 0, r = rem.size();
//    vector<int> map(s.size(), INT_MAX);
//    for (int i = 0; i < rem.size(); ++i)
//         map[rem[i]] = i;
//    while (l < r) {
//        int m = (l + r + 1) / 2, j = 0;
//        for (int i = 0; i < s.size() && j < p.size(); ++i)
//            if (map[i] >= m && s[i] == p[j])
//                ++j;
//        if (j == p.size())
//            l = m;
//        else
//            r = m - 1;
//    }
// 都是while 后直接 return 的。


//        int L = 0, R = A.size();
//        while (L <= R) {
//            int M = (L + R) / 2;
//            if (valid(s, p, A, M)) L = M + 1;
//            else R = M - 1;
//        }
//        return R;


// 200-300 ms
//Runtime: 648 ms, faster than 15.24% of C++ online submissions for Maximum Number of Removable Characters.
//Memory Usage: 146.6 MB, less than 18.58% of C++ online submissions for Maximum Number of Removable Characters.
// 移除前 k 个 removable中的元素 代表的 下标
// 同时移动的。
// 只能硬算啊。。肯定tle。
// hint: binary search .... zhe ye keyi?
    int lt1898a(string s, string p, vector<int>& removable)
    {
        int l = 0;
        int r = removable.size() - 1;
        bool can = false;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            vector<int> vi(begin(removable), begin(removable) + mid + 1);
            string rms = rm(s, vi);
            #ifdef __test
            cout<<l<<", "<<mid<<", "<<r<<", "<<vi.size()<<", "<<rms<<endl;
            #endif // __test
            if (isSub(rms, p))
            {
                l = mid;
                can = true;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (can)
            return l + 1;

        vector<int> vi(begin(removable), begin(removable) + l + 1);
        string rms = rm(s, vi);
        int ans = 0;
        if (isSub(rms, p))
        {
            ans = vi.size();
        }
        else
        {
            ans = 0;
        }
        return ans;
//        return can ? l + 1 : 0;
//        return r + 1;
//        return l + 1;
    }

    string rm(string& s, vector<int> vi)
    {
        std::sort(begin(vi), end(vi));
        string ans;
        int idx = 0;
        for (int i = 0; i < s.size(); ++i)
        {
//            #ifdef __test
//            cout<<"     . "<<i<<", "<<idx<<", "<<ans<<endl;
//            #endif // __test
            if (idx < vi.size() && i == vi[idx])
            {
                idx++;
            }
            else
            {
                ans += string(1, s[i]);
            }
        }
        return ans;
    }

    bool isSub(string& s, string& p)
    {
        int si = 0;
        int pi = 0;
        for (; si < s.size() && pi < p.size(); ++si)
        {
            if (s[si] == p[pi])
            {
                pi++;
            }
        }
        return pi == p.size();
    }

};

int main()
{
    string s = "abcacb";
    string p = "ab";
    myvi v = {3,1,0};

//    string s = "abcbddddd";
//    string p = "abcd";
//    myvi v = {3,2,1,4,5,6};

//    string s = "abcab";
//    string p = "abc";
//    myvi v = {0,1,2,3,4};

    LT1898 lt;

    cout<<lt.lt1898a(s, p, v)<<endl;

    return 0;
}
