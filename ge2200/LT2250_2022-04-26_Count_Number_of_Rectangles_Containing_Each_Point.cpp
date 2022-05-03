
#include "../header/myheader.h"

class LT2250
{
public:


// D D

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//
//#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>
//
//
//class Solution {
//public:
//    static bool comp(vector<int>& v1, vector<int>& v2) {
//        if(v1[1] == v2[1])
//            return v1[0] > v2[0];
//        return v1[1] > v2[1];
//    }
//    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
//        int n = rectangles.size(), q = points.size();
//        vector<int> ans(q, 0);
//        sort(rectangles.begin(), rectangles.end(), comp);
//        vector<vector<pair<int, int>>> queries(101);
//        for(int i = 0; i < q; i++) {
//            queries[points[i][1]].push_back({points[i][0], i});
//        }
//        int j = 0;
//        ordered_set o_set;
//
//        for(int h = 100; h > 0; h--) {
//            while(j < n && rectangles[j][1] >= h) {
//                o_set.insert({rectangles[j][0], j++});
//            }
//
//            for(int i = queries[h].size() - 1; i >= 0; i--) {
//                ans[queries[h][i].second] = o_set.size() - o_set.order_of_key({queries[h][i].first, 0});
//            }
//        }
//
//        return ans;
//    }
//};
//
// .. 库很酷。



//                auto lb = lower_bound(begin(umap[i]), end(umap[i]), p[0]);
//                sum += end(umap[i]) - lb;





//Runtime: 760 ms, faster than 40.00% of C++ online submissions for Count Number of Rectangles Containing Each Point.
//Memory Usage: 84.9 MB, less than 60.00% of C++ online submissions for Count Number of Rectangles Containing Each Point.
// 。。y<100，所以可以  for(1-100) { lower_bound }
    vector<int> lt2250b(vector<vector<int>>& rectangles, vector<vector<int>>& points)
    {
        vector<int> ans;
        vector<vector<int>> vvi(101);
        for (vector<int>& vi : rectangles)
        {
            vvi[vi[1]].push_back(vi[0]);
        }
        for (int i = 1; i <= 100; ++i)
        {
            std::sort(begin(vvi[i]), end(vvi[i]));
        }
        for (auto& vi : points)
        {
            int x = vi[0], y = vi[1];
            int cnt = 0;

            for (int i = y; i <= 100; ++i)
            {
                vector<int>& v = vvi[i];
                vector<int>::iterator it = std::lower_bound(begin(v), end(v), x);
                cnt += (int) v.size() - std::distance(begin(v), it);
            }
            ans.push_back(cnt);
        }
        return ans;
    }


// tle, 都是x很大，y很小。。。 估计还有一个case 是 x很小，y很大。。
// sort下，然后
    vector<int> lt2250a(vector<vector<int>>& rectangles, vector<vector<int>>& points)
    {
        std::sort(begin(rectangles), end(rectangles));
        vector<int> ans;
        for (vector<int>& vi : points)
        {
            int cnt = 0;
            int x = vi[0], y = vi[1];
            std::vector<vector<int>>::iterator it = std::lower_bound(begin(rectangles), end(rectangles), vi);
            for (; it != end(rectangles); it++)
            {
                if (it->operator[](1) >= y)
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }

};

int main()
{

    myvvi vv = {{1,2},{2,3},{2,5}};
    myvvi vv2 = {{2,1},{1,4}};

//    myvvi vv = {{1,1},{2,2},{3,3}};
//    myvvi vv2 = {{1,3},{1,1}};

    LT2250 lt;

    myvi v = lt.lt2250b(vv, vv2);

    showVectorInt(v);

    return 0;
}
