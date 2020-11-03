
#include "../header/myheader.h"

class LT1054
{
public:


// D D

//  unordered_map<int, int> m;
//  set<pair<int, int>> s;
//  for (auto n : b) ++m[n];
//  for (auto it = begin(m); it != end(m); ++it) s.insert({ it->second, it->first });
//  for (auto it = s.rbegin(); it != s.rend(); ++it) {
//    for (auto cnt = 0; cnt < it->first; ++cnt, pos += 2) {
//      if (pos >= b.size()) pos = 1;
//      b[pos] = it->second;
//    }
//  }
//  return b;
// .. 不需要排序的，
// if (pos >= b.size()) pos = 1; 这样就不需要2个for 了。
// 不需要排序的话， set应该是多余的啊，直接 map上 操作就可以了。
// set自带排序。
// 但是觉得 好像 真的不需要排序。。 不， 当一个值超过一半时（barcodes.size为奇数），就需要排序的。

// detail里有一个，保存 出现次数最多的 值， 然后先把这个值 安排了。这样就不需要排序了。


//Runtime: 156 ms, faster than 83.71% of C++ online submissions for Distant Barcodes.
//Memory Usage: 42.5 MB, less than 5.81% of C++ online submissions for Distant Barcodes.
    vector<int> lt1054a(vector<int>& barcodes)
    {
        unordered_map<int, int> map2;           // val - count
        for (int i : barcodes)
        {
            map2[i]++;
        }
        vector<pair<int, int>> vp;
        for (auto& p : map2)
        {
            vp.push_back({p.first, p.second});
        }
        std::sort(begin(vp), end(vp), [](pair<int, int>& p1, pair<int, int>& p2) { return p1.second > p2.second; });
        #ifdef __test
        for (pair<int, int>& pa : vp)
        {
            cout<<pa.first<<", "<<pa.second<<endl;
        }
        #endif // __test

        int sz1 = barcodes.size();
        vector<int> ans(sz1);
        int vpi = 0;
        for (int i = 0; i < sz1; i += 2)
        {
            ans[i] = vp[vpi].first;
            vp[vpi].second--;
            if (vp[vpi].second == 0)
                vpi++;
        }

        for (int i = 1; i < sz1; i += 2)
        {
            ans[i] = vp[vpi].first;
            vp[vpi].second--;
            if (vp[vpi].second == 0)
                vpi++;
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {1,1,1,2,2,2,2};
    vector<int> v = {1,1,1,1,2,2,3,3};

    LT1054 lt;

    vector<int> v2 = lt.lt1054a(v);

    for_each(v2.begin(), v2.end(), fun_cout);

    return 0;
}
