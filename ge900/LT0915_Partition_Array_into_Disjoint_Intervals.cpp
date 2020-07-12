
#include "../header/myheader.h"

class LT0915
{
public:

// D D

//        for (int i = 1; i < a.length; i++)
//            if (localMax > a[i]) {
//                localMax = max;
//                partitionIdx = i;
//            } else max = Math.max(max, a[i]);
// localMax 是 前面出现的最大值，如果这个值 比a[i] 大，说明不符合 left <<< right. 需要后移。
// localMax 是left的最大值，当 >a[i]时， 说明 左侧的最大值 > 右侧的某个值， 需要移动 下标。


//Runtime: 108 ms, faster than 16.13% of C++ online submissions for Partition Array into Disjoint Intervals.
//Memory Usage: 21.8 MB, less than 25.34% of C++ online submissions for Partition Array into Disjoint Intervals.
    int lt0915a(vector<int>& A)
    {
        vector<int> minv(A.size());
        vector<int> maxv(A.size());
        int t2 = A[0];
        for (int i = 0; i < A.size(); i++)
        {
            t2 = max(t2, A[i]);
            maxv[i] = t2;
        }
        t2 = A[A.size() - 1];
        for (int i = A.size() - 1; i >= 0; i--)
        {
            t2 = min(t2, A[i]);
            minv[i] = t2;
        }
        int ans = 0;
        for (int i = 0; i < A.size() - 1; i++)
        {
            if (maxv[i] <= minv[i + 1])
            {
                ans = i;
                break;
            }
        }
        return ans + 1;
    }

};

int main()
{

//    vector<int> v = {5,0,3,8,6};
    vector<int> v = {1,1,1,0,6,12};

    LT0915 lt;

    cout<<lt.lt0915a(v)<<endl;

    return 0;
}
