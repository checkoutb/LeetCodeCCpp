
#include "../header/myheader.h"
#include "LT0413_Arithmetic_Slices.cpp"

class LT0446
{
public:


// solution:
// 1.
// void dfs(int dep, vector<int>& A, vector<LL> cur) {

// 2.
// vector<map<LL, int>> cnt(n);

//    int ans;
//    int n;
//    int lt0446SolutionDfs(vector<int>& A)
//    {
//    }
//
//    void dfs(int dep, vector<int>& A, vector<LL> cur)
//    {
//        n = A.size();
//        if dep == n
//        {for(cur) {all diff is same -> ans++}}
//        else
//        dfs(dep + 1, A, cur);           // 不加自己
//        cur.push_back(A[dep]);
//        dfs(dep + 1, A, cur);       // 加自己
//    }

    // dp.
    // 对于每对[x,y], y[y-x] = y[y-x] + x[y-x],连起来也是一个，所以还要+1
    //
    int lt0446Solution1(vector<int>& A)
    {
        int ans = 0;
        int sz1 = A.size();
        vector<map<long long, int>> cnt(sz1);           // diff, number
        for (int i = 1; i < sz1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long diff = A[i] - A[j];
                cnt[i][diff] = cnt[i][diff] + cnt[j][diff] + 1;
                ans += cnt[j][diff];
            }
        }
        return ans;
    }

    // gg.....
    int lt0446d(vector<int>& A)
    {

        int ans = 0;
        int sz1 = A.size();
        multiset<int> set2;
        map<int, set<long>> map2;        // index, diff
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                long diff = (long)A[i] - A[j];
                if (map2[j].find(diff) == map2[j].end())
                    recursiond1(A, j + 1, diff, A[j], set2, 0, map2);
            }
        }
        #ifdef __test
        cout<<"set2.size  "<<set2.size()<<endl;
        #endif // __test

        for (int len : set2)
        {
            ans += (len + 1) * len / 2;
        }
        return ans;
    }

    int recursiond1(vector<int>& A, int i, long diff, long val, multiset<int>& set2, int len, map<int, set<long>>& map2)
    {
        int sz1 = A.size();
        bool flag2 = true;
        for (int j = i; j < sz1; j++)
        {
            if (val - A[j] == diff)
            {
                map2[j].insert(diff);
                flag2 = false;
                recursiond1(A, j + 1, diff, A[j], set2, len + 1, map2);
            }
        }
        if (flag2 && len > 0)
        {
            set2.insert(len);
            #ifdef __test
            cout<<"... "<<set2.size()<<", "<<len<<endl;
            #endif // __test
        }
        return 0;
    }


    // error.
    int lt0446c(vector<int>& A)
    {
        map<int, multiset<pair<int, int>>> map2;
        int sz1 = A.size();
        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                map2[A[i]-A[j]].insert(std::make_pair(i, j));
            }
        }

        for (map<int, multiset<pair<int, int>>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int diff = it->first;
            multiset<pair<int, int>> set2 = it->second;

            cout<<"..  "<<set2.size()<<endl;
            cout<<"dff : "<<diff<<endl;
            for (pair<int, int> p2 : set2)
            {
                cout<<"pair : "<<p2.first<<", "<<p2.second<<endl;
            }

            while (!set2.empty())
            {
                pair<int, int> p2 = *set2.begin();
                int t2 = -1;
                int tag2 = p2.first;
                for (auto ap = set2.begin(); ap != set2.end();)
                {
                    if (ap->first == tag2)
                    {
                        cout<<"                    "<<ap->first<<" , "<<ap->second<<endl;
                        t2++;
                        tag2 = ap->second;
                        set2.erase(ap);
                    }
                    else
                    {
                        ap++;
                    }
                }
                if (t2 > 0)
                    ans += (1 + t2) * t2 / 2;
                cout<<" . .  "<<ans<<", , "<<t2<<endl;
            }

            cout<<".......  "<<set2.size()<<endl;
        }

        return ans;
    }


    // ......error [0,1,2,2,2]
    int lt0446b(vector<int>& A)
    {
        LT0413 lt;
        return lt.lt0413a(A);
    }

    // error
    // 和413一起看了半天。。。应该是413要求连续，这里不要求连续。
    int lt0446a(vector<int>& A)
    {
        map<int, set<pair<int, int>>> map2;
        int sz1 = A.size();
        int ans = 0;
        for (int i = 0; i < sz1; i++)
            for (int j = i + 1; j < sz1; j++)
            {
                int diff = A[i] - A[j];
                map2[diff].insert(pair<int, int>(i, j));
            }

        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                int diff = A[i] - A[j];
                int num = 2;
                int t1 = j;
                set<pair<int, int>> set1 = map2[diff];

                bool flag = true;
                for (pair<int, int> p2 : set1)
                {
                    // search forward           ... error  [0,1,2,2,2]
                    if (p2.second == i)
                    {
                        flag = false;
                        break;
                    }
                }

                while (flag)
                {
                    flag = false;
                    for (pair<int, int> pa : set1)
                    {
                        if (pa.first == t1)
                        {
                            flag = true;
                            num++;
                            t1 = pa.second;
                            break;
                        }
                    }
                }

                #ifdef __test
                if (num >= 3)
                    cout<<" num: "<<num<<", i "<<i<<", j "<<j<<", diff "<<diff<<endl;
                #endif // __test

                if (num >= 3)
                {
                    num -= 2;
                    ans += (1 + num) * num / 2;
                }
            }
        }
        return ans;
    }
};

int main()
{
    cout<<"hi"<<endl;

//    vector<int> v = {2, 4, 6, 8, 10};           // 4 4 6 8 10
                                            // 2 2 4 4 6
//    vector<int> v = {2,2,4,4,6};
//    vector<int> v = {0,1,2,2,2};        // 4

//[2,4,6]
//[4,6,8]
//[6,8,10]
//[2,4,6,8]
//[4,6,8,10]
//[2,4,6,8,10]
//[2,6,10]


    LT0446 lt;
    int a = lt.lt0446Solution1(v);
    cout<<"result : "<<a<<endl;

    return 0;
}
