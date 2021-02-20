
#include "../header/myheader.h"

class LT1671
{
public:

// D D

// LIS。，，Longest increasing sequence。。。。

//        int N = A.size(), ans = N;
//        vector<int> a(N), b(N), v;
//        for (int i = 0 ; i < N; ++i) {
//            int x = A[i];
//            auto it = lower_bound(begin(v), end(v), x);
//            a[i] = it - begin(v);
//            if (it != end(v)) *it = x;
//            else v.push_back(x);
//        }
//        v.clear();
//        for (int i = N - 1; i >= 0; --i) {
//            int x = A[i];
//            auto it = lower_bound(begin(v), end(v), x) ;
//            b[i] = it - begin(v);
//            if (it != end(v)) *it = x;
//            else v.push_back(x);
//        }
//        for (int i = 1; i < N; ++i) {
//            if (a[i] && b[i]) ans = min(ans, N - (a[i] + b[i] + 1));
//        }


//For this problem, we build our stack l from the left. We need to store the size of LIS for each point (dp[i]).
//
//Then, we build another stack r from the right.
//Therefore, for each element i, we can find out the length of increasing (size of the left stack at i, which stored in dp[i])
//and decreasing (right stack size) subsequences originating from i. The result is the maximum value for all potential peaks.
// 所以上面的就是在 构造/更新 LIS， 不丢失数据，防止后续出一个大数。

// 因为是LIS，必须有序， 所以 lower_bound 找到的值 必然在之前出现，之前出现，又>=自己， 冲突的
// lower bound 是 >=， 所以需要更新成 小一点的数， 让后续能正确识别。  0 1 2 5 3 4 ，这种， 某个时间点是  0 1 2 5, 然后计算3, 会找到 5这个元素， 就需要更新成3,变成0123, 再来一个4,就正确了。
// 当前值， 和lower bound 找到的值 在LIS 中 是冲突的， 并且 lowerBound >= 当前值， 所以用当前值替换lowerBound，加入到LIS中。



//Runtime: 276 ms, faster than 47.52% of C++ online submissions for Minimum Number of Removals to Make Mountain Array.
//Memory Usage: 12 MB, less than 84.67% of C++ online submissions for Minimum Number of Removals to Make Mountain Array.
// 如果 i 在 最终结果(山)中，且是顶点，那么 前面 需要删除多少结点
//                                      后面
// 前面第一个小于自己的， stack。  不， 要判断多个的。 应该是 向前搜索，直到 仅小于自己的元素。  map？ 或者遍历一遍。。。
    int lt1671a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> vi1(sz1);
        vector<int> vi2(sz1);
        int ans = INT_MAX;
//        vector<>

//        for (int i = 0; i < sz1; ++i)
//        {
//            int mnmxi = -1;
//            int mnmx = INT_MIN;
//            int t2 = vi1[i];
//            for (int j = i - 1; j >= 0; --j)
//            {
//                if (nums[j] < t2)
//                {
//                    if (nums[j] > mnmx)
//                    {
//                        mnmxi = j;
//                        mnmx = nums[j];
//                    }
//                }
//            }
//            if (mnmxi == -1)        // all greater than nums[i]
//            {
//                vi1[i] = i;     // delete all prev
//            }
//            else
//            {
//                int mndel = INT_MAX;
//                for (int j = i - 1; j >= 0; --j)
//                {
//                    mndel = min(mndel, vi1[j] + i - j - 1);
//                }
//                vi1[i] = mndel;
//            }
//        }

        funa1(nums, vi1);
        std::reverse(begin(nums), end(nums));
        funa1(nums, vi2);
        std::reverse(begin(vi2), end(vi2));

        #ifdef __test
        showVectorInt(vi1);
        showVectorInt(vi2);
        #endif // __test

        for (int i = 1; i < sz1 - 1; ++i)
        {
            if (vi1[i] == i)    // del all prev, no one less than nums[i]
            {
                continue;
            }
            if (vi2[i] == (sz1 - i - 1))     //
            {
                continue;
            }
            ans = min(ans, vi1[i] + vi2[i]);
        }

        return ans;
    }

    void funa1(vector<int>& nums, vector<int>& vi1)
    {
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            int mnmxi = -1;
            int mnmx = INT_MIN;
            int t2 = nums[i];
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j] < t2)
                {
                    if (nums[j] > mnmx)
                    {
                        mnmxi = j;
                        mnmx = nums[j];
                    }
                }
            }
//            cout<<mnmxi<<", "<<i<<", "<<t2<<""<<endl;
            if (mnmxi == -1)        // all greater than nums[i]
            {
                vi1[i] = i;     // delete all prev
            }
            else
            {
                int mndel = INT_MAX;
                for (int j = i - 1; j >= mnmxi; --j)
                {
                    if (t2 > nums[j])
                        mndel = min(mndel, vi1[j] + i - j - 1);
                }
                vi1[i] = mndel;
            }
        }
    }

};

int main()
{
//    myvi v = {1,3,1};
//    myvi v = {2,1,1,5,6,2,3,1};
//    myvi v = {4,3,2,1,1,2,3,1};
//    myvi v = {1,2,3,4,4,3,2,1};
    myvi v = {9,8,1,7,6,5,4,3,2,1};     // 2            .... 0 < i < arr.length - 1 .. 不能90度 悬崖。。。
//    myvi v = {100,92,89,77,74,66,64,66,64}; // 6        // ..100 删除后， 92就不能选了。。 因为92是90度悬崖。


    LT1671 lt;

    cout<<lt.lt1671a(v);

    return 0;
}
