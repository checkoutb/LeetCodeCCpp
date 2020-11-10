
#include "../header/myheader.h"

class LT1202
{
public:





//Note that, in the find function, we are using path compression.
//In other words, we "flatten" our hierarchy every time we search,
//so that elements references the parent index directly: ds[i] = find(ds, ds[i]);.
//Without path compression, you will get TLE on the last test case.


// 要路径压缩，并查集 里不能是一条直线， 而应该是一个 N叉树。

//int find(vector<int>& ds, int i) {
//  return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
//}
// vector<int> ds(s.size(), -1);
//    auto i = find(ds, p[0]), j = find(ds, p[1]);
//    if (i != j)
//        ds[j] = i;



// tle
// 并查集，一个集合里的 按字典顺序排列。
    string lt1202a(string s, vector<vector<int>>& pairs)
    {
        vector<char> vc(s.size(), 'A');

        vector<int> arr(s.size());
        for (int i = 0; i < s.size(); ++i)
            arr[i] = i;

        for (vector<int>& vi : pairs)
        {
//            int t1 = min(vi[0], vi[1]);
//            int t2 = max(vi[0], vi[1]);
//            arr[t1] = t2;
            int t1 = vi[0];
            int t2 = vi[1];
            while (t1 != arr[t1])
                t1 = arr[t1];
            while (t2 != arr[t2])
                t2 = arr[t2];
            arr[t1] = t2;
        }
//        bool remain = true;
//        while (remain)
//        {
//
//
//        }

        unordered_map<int, vector<int>> map2;           // 并查集的根 ： s的下标。
        for (int i = 0; i < arr.size(); i++)
        {
            int idx = i;
            while (idx != arr[idx])
                idx = arr[idx];
            map2[idx].push_back(i);
        }
        #ifdef __test
        cout<<" . "<<map2.size()<<endl;
        #endif // __test
        int bucket[128] = {0};
        for (auto& p : map2)
        {
            for (int i = 'a'; i <= 'z'; i++)
                bucket[i] = 0;
            vector<int>& vidx = p.second;           // ordered
            for (int i : vidx)
                bucket[s[i]]++;
            int idx = -1;
            for (char i = 'a'; i <= 'z'; i++)
            {
                int cnt = bucket[i];
                while (cnt-- > 0)
                {
                    vc[vidx[++idx]] = i;
                }
            }
        }

        string ans;
        for (char ch : vc)
            ans += ch;
        return ans;
    }

};

int main()
{

    string s = "dcab";
    vector<vector<int>> vv = {{0,3},{1,2}
    ,{0,2}
    };

//    string s = "cba";
//    vector<vector<int>> vv = {{0,1},{1,2}};

    LT1202 lt;

    cout<<lt.lt1202a(s, vv)<<endl;

    return 0;
}
