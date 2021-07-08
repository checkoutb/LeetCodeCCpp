
#include "../header/myheader.h"

class LT1289
{
public:

// D D

//        for i in xrange(1, len(A)):
//            r = heapq.nsmallest(2, A[i - 1])
//            for j in xrange(len(A[0])):
//                A[i][j] += r[1] if A[i - 1][j] == r[0] else r[0]
//        return min(A[-1])
// 原地。




//    int fm = 0, sm = 0, pos = -1;
//    for (auto i = 0; i < arr.size(); ++i) {
//        auto fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;
//        for (auto j = 0; j < arr[i].size(); ++j) {
//            auto mn = j != pos ? fm : sm;
//            if (arr[i][j] + mn < fm2) {
//                sm2 = fm2;
//                fm2 = arr[i][j] + mn;
//                pos2 = j;
//            } else sm2 = min(sm2, arr[i][j] + mn);
//        }
//        fm = fm2, sm = sm2, pos = pos2;
//    }
//    return fm;






//Runtime: 24 ms, faster than 97.36% of C++ online submissions for Minimum Falling Path Sum II.
//Memory Usage: 13.2 MB, less than 72.36% of C++ online submissions for Minimum Falling Path Sum II.
// 选了一个以后，它下方的就不能选了。
    int lt1289a(vector<vector<int>>& arr)
    {
        int sz1 = arr.size();
        int sz2 = arr[0].size();
        int ans = 0;
//        vector<vector<int>> vvi(sz1, vector<int>())
        vector<int> vi(begin(arr[0]), end(arr[0]));
        int mn1, mn2, mni1, mni2;
        for (int i = 1; i < sz1; ++i)
        {
//            vector<int> v2(sz2, 0);
//            std::partial_sort()       // 数组的开始，最后一个有序的，数组的结束。
            mn1 = mn2 = INT_MAX;
//            mni1 = mni2 = -1;
            for (int j = 0; j < sz2; ++j)
            {
                if (vi[j] < mn2)
                {
                    if (vi[j] < mn1)
                    {
                        mn2 = mn1;
                        mn1 = vi[j];
//                        mni2 = j;
                    }
                    else
                    {
                        mn2 = vi[j];
                    }
                }
            }
            for (int j = 0; j < sz2; ++j)
            {
                if (vi[j] == mn1)
                {
                    vi[j] = mn2 + arr[i][j];
                }
                else
                {
                    vi[j] = mn1 + arr[i][j];
                }
            }
            #ifdef __test
            showVectorInt(vi);
            #endif // __test
        }
//        #ifdef __test
//        for (myv)
//        #endif // __test
        ans = *min_element(begin(vi), end(vi));
        return ans;
    }

};

int main()
{
    myvvi vv = {{1,2,3},{4,5,6},{7,8,9}};

// 7
//    myvvi vv = {{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2}};


    LT1289 lt;

    cout<<lt.lt1289a(vv)<<endl;

    return 0;
}
