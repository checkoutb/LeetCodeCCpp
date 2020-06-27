
#include "../header/myheader.h"

class LT0973
{
public:


// D D
// priority_queue

// quick sort
//    while (l <= r) {
//        int mid = helper(points, l, r);
//        if (mid == K) break;


//Runtime: 788 ms, faster than 13.17% of C++ online submissions for K Closest Points to Origin.
//Memory Usage: 57.6 MB, less than 54.62% of C++ online submissions for K Closest Points to Origin.
    vector<vector<int>> lt0973a(vector<vector<int>>& points, int K)
    {
        unordered_map<int, int> map2;
        std::sort(begin(points), end(points), [&map2](vector<int>& v1, vector<int>& v2) {
            int t1 = std::min(std::abs(v1[0]), abs(v1[1]));
            int t2 = std::max(std::abs(v1[0]), abs(v1[1]));
            int key1 = t1 * 10000 + t2;
            int val1 = map2[key1];
            if (val1 == 0 && key1 != 0)
            {
                val1 = t1 * t1 + t2 * t2;
                map2[key1] = val1;
            }

            t1 = min(abs(v2[0]), abs(v2[1]));
            t2 = max(abs(v2[0]), abs(v2[1]));
            int key2 = t1 * 10000 + t2;
            int val2 = map2[key2];
            if (val2 == 0 && key2 != 0)
            {
                val2 = t1 * t1 + t2 * t2;
                map2[key2] = val2;
            }

            return val1 < val2;
        });

        return vector<vector<int>>(begin(points), begin(points) + K);
    }

};

int main()
{

    vector<vector<int>> vv2 = {{1,3},{-2,2}};
    int k = 1;

//    vector<vector<int>> vv2 = {{3,3},{5,-1},{-2,4}};
//    int k = 2;

    LT0973 lt;

    vector<vector<int>> v = lt.lt0973a(vv2, k);

    for (auto p : v)
    {
        for_each(begin(p), end(p), fun_cout);
        cout<<endl;
    }

    return 0;
}
