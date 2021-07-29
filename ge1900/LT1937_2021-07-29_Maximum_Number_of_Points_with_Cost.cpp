
#include "../header/myheader.h"

class LT1937
{
public:

// D


//    for (auto &row : p) {
//        for (long long j = 0, run_max = 0; j < row.size(); ++j) {
//            run_max = max(run_max - 1, prev_row[j]);
//            cur_row[j] = run_max;
//        }
//        for (long long j = row.size() - 1, run_max = 0; j >= 0; --j) {
//            run_max = max(run_max - 1, prev_row[j]);
//            cur_row[j] = max(cur_row[j], run_max) + row[j];
//        }
//        swap(cur_row, prev_row);
//    }
// 从左到右，从右到左。





// tle...
// 1 1 1 999  1 1   必然选 999
// 只需要比较  这行的max 以及 max - sz2 范围内的 值。  max - max(mxi, sz2 - mxi)
    long long lt1937b(vector<vector<int>>& points)
    {
        long long ans = 0LL;
        int sz1 = points.size();
        int sz2 = points[0].size();
//        vector<pair<int, int>> vp;
//        vector<long long> vll(sz2, 0LL);
        vector<long long> vll(begin(points[0]), end(points[0]));

        for (int i = 1; i < sz1; ++i)
        {
            vector<long long> vll2(sz2, 0LL);
//            vp.clear();
            int mx = 0;
            for (int j = 0; j < sz2; ++j)
            {
                mx = max(mx, points[i - 1][j]);
            }
            int t2 = mx - sz2;
            for (int j = 0; j < sz2; ++j)
            {
                if (points[i - 1][j] > t2)
                {
                    #ifdef __test
                    cout<<points[i][j]<<endl;
                    #endif // __test
                    for (int k = 0; k < sz2; ++k)
                    {
                        vll2[k] = max(vll2[k], vll[j] + points[i][k] - abs(k - j));
                    }
                }
//                    vp.push_back(std::make_pair(points[i][j], j));
            }
//            for (int i)
            swap(vll, vll2);
            #ifdef __test
            for (long long ll : vll)
                cout<<ll<<", ";
            cout<<endl;
            #endif // __test
        }
        ans = *max_element(begin(vll), end(vll));
        return ans;
    }



// tle...       int... long long..
    long long lt1937a(vector<vector<int>>& points)
    {
        int sz1 = points.size();
        int sz2 = points[0].size();
        vector<int> vi(sz2, 0);
        for (int i = 0; i < sz1; ++i)
        {
            vector<int> vi2(sz2, 0);
            for (int j = 0; j < sz2; ++j)
            {
                for (int k = 0; k < sz2; ++k)
                {
                    vi2[j] = max(vi2[j], vi[k] + points[i][j] - abs(k - j));
//                    vi[j] = max(vi[j], )            // 要两层的。 或者一个temp
                }
            }
            swap(vi, vi2);
        }
        int ans = *max_element(begin(vi), end(vi));
        return ans;
    }

};

int main()
{

//    myvvi vv = {{1,2,3},{1,5,1},{3,1,1}};
    myvvi vv = {{1,5},{2,3},{4,2}};

    LT1937 lt;

    cout<<lt.lt1937b(vv)<<endl;

    return 0;
}
