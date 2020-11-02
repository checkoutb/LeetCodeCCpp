
#include "../header/myheader.h"

class LT1027
{
public:

// D

//dp[index][diff] equals to the length of arithmetic sequence at index with difference diff.
//        unordered_map<int, unordered_map<int, int>> dp;
//        int res = 2, n = A.size();
//        for (int i = 0; i < n; ++i)
//            for (int j = i + 1; j < n; ++j)  {
//                int d = A[j] - A[i];
//                dp[d][j] = dp[d].count(i) ? dp[d][i] + 1 : 2;
//                res = max(res, dp[d][j]);
//            }
//        return res;

// ,,,


// tle....
    int lt1027b(vector<int>& A)
    {
        int sz1 = A.size();
        int ans = min(sz1, 2);
//        unordered_map<int, vector<pair<int, int>>> map2;       // diff, lastVal+cnt
//        unordered_map<int, unordered_map<int, int>> map2;       // diff, nextVal+cnt
//        unordered_map<int, queue<pair<int, int>>> map2;         // diff, nextVal+cnt
//        queue<tuple<int,int,int>> que2;     // diff, nextVal, cnt         // md bukebian, zhiyou std::get<1>(tup)
//        queue<vector<int,int,int>> que2;
        vector<vector<int>> vv;
        for (int i = 1; i < sz1; i++)
        {
            int sz2 = vv.size();
            bool contain1 = false;      //
            bool contain2 = false;
            unordered_set<int> set2;
            int av = A[i];
            for (int i = 0; i < sz2; i++)
            {
                if (vv[i][1] == av)
                {
                    set2.insert(vv[i][0]);
                    vv[i][1] = av + vv[i][0];
                    vv[i][2]++;
                    ans = max(ans, vv[i][2]);
                }
            }
            for (int j = 0; j < i; j++)
            {
                int diff = av - A[j];
                if (set2.find(diff) == set2.end())
                {
                    vv.push_back({diff, av + diff, 2});
                    set2.insert(diff);
                }
            }

//            #ifdef __test
//            cout<<"    sz: "<<vv.size()<<endl;
//            for (vector<int>& v : vv)
//            {
//                cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
//            }
//            #endif // __test
        }
        return ans;
    }



// tle
    int lt1027a(vector<int>& A)
    {
        int sz1 = A.size();
        int ans = std::min(sz1, 2);
        vector<vector<vector<int>>> vvv(sz1);            // vector<multimap>
        for (int i = 1; i < sz1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j];
                vvv[i].push_back({diff, 2});
                for (vector<int>& v : vvv[j])
                {
                    if (v[0] == diff)
                    {
                        vvv[i].push_back({diff, v[1] + 1});
                        ans = max(ans, v[1] + 1);
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> vv = {{3,6,9,12},{9,4,7,2,10},{20,1,15,3,10,5,8}};

    LT1027 lt;

    for (vector<int>& v : vv)
    {
        cout<<lt.lt1027b(v)<<endl<<endl;
    }

    return 0;
}
