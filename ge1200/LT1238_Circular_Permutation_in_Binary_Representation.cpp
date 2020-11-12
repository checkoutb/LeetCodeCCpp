
#include "../header/myheader.h"

class LT1238
{
public:






// n5 - start14 .. tle.
//  000  001 011 010 110 111 101 100
//  000  001 101 100 110 010 011 111
// 是不是 不可能 转换到一个数字，但是无法转换出来？
// 但是  首尾 可能不行。
// dfs？
    vector<int> lt1238a(int n, int start)
    {
        vector<int> ans;
        unordered_set<int> set2;
        vector<bool> bits(n, false);
        int t2 = 1 << (n - 1);
        int t3 = n - 1;
        int start2 = start;
        while (t2 > 0)
        {
            if (t2 <= start)
            {
                bits[t3] = true;
                start -= t2;
            }
            t2 >>= 1;
            t3--;
        }
        #ifdef __test
        for (bool b : bits)
            cout<<b<<", ";
        cout<<endl;
        #endif // __test
        set2.insert(start2);
        ans.push_back(start2);
        dfsa1(ans, set2, bits, (int) std::pow(2, n), start2);

        return ans;
    }

    // true:found.
    bool dfsa1(vector<int>& ans, unordered_set<int>& set2, vector<bool>& bits, int sz, int last)
    {
        #ifdef __test
        cout<<"  "<<ans.size()<<", "<<set2.size()<<", "<<bits.size()<<endl;
        #endif // __test

        if (ans.size() == sz)
        {
            int t1 = ans[sz - 1] ^ ans[0];
            int n = 1;
            int cnt = 1;
            while (cnt++ < 17)
            {
                if (t1 == n)
                    return true;
            }
            return false;
        }
        int num = 1;
        int tmp = 0;
        for (int i = 0; i < bits.size(); i++)
        {
            if (!bits[i])
            {
                tmp = last + num;
                if (set2.find(tmp) == set2.end())
                {
                    ans.push_back(tmp);
                    set2.insert(tmp);
                    bits[i] = true;
                    if (dfsa1(ans, set2, bits, sz, tmp))
                        return true;
                    bits[i] = false;
                    set2.erase(tmp);
                    ans.pop_back();
                }
            }
            else        // ..
            {
                tmp = last - num;
                if (set2.find(tmp) == set2.end())
                {
                    ans.push_back(tmp);
                    set2.insert(tmp);
                    bits[i] = false;
                    if (dfsa1(ans, set2, bits, sz, tmp))
                        return true;
                    bits[i] = true;
                    set2.erase(tmp);
                    ans.pop_back();
                }
            }
            num <<= 1;
        }
        return false;
    }
};

int main()
{

//    int n{2}, st{3};
//    int n{3}, st{2};
    int n{5}, st{14};

    LT1238 lt;

    vector<int> ans = lt.lt1238a(n, st);

    showVectorInt(ans);

    return 0;
}
