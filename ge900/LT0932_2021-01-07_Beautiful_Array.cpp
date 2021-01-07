
#include "../header/myheader.h"

class LT0932
{
public:

// D

//        vector<int> res = {1};
//        while (res.size() < N) {
//            vector<int> tmp;
//            for (int i : res) if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
//            for (int i : res) if (i * 2 <= N) tmp.push_back(i * 2);
//            res = tmp;
//        }



// gg

// [1, N]
//For every i < j, there is no k with i < k < j such that A[k] * 2 = A[i] + A[j].
// 。。枚举
// 偶数+奇数 != 2x
// 所以分成2部分，前半部分偶数，后半部分奇数。
// 1,3,5  1,5,3
// 2 4 6  2 6 4
// 小数放两边。
// 不，依然会有升序。
// 1-n升序，校验，如果存在i,k,j，那么 i+1 和 j 互换，或者i-1和j。  这种能得到结果吗？
// 感觉是一种有序的， 比如 N=5,   第一个元素是1, 那么肯定知道 2需要排在3后， 3需要排在5后， 1 5 3 2，但。。
    vector<int> lt0932a(int N)
    {



//        vector<int> ans(N);
//        for (int i = 0; i < N; ++i)
//            ans[i] = i + 1;
//        bool change = true;
//        while (change)
//        {
//            change = false;
//            for (int i = 0; i < v.size(); ++i)
//            {
//                for (int j = i + 2; j < v.size(); ++j)
//                {
//                    for (int k = i + 1; k < j; ++k)
//                    {
//                        if (ans[k] * 2 == ans[i] + ans[j])
//                        {
//
//                        }
//                    }
//                }
//            }
//        }

//        vector<int> ans(N);
//        int t2 = N / 2;     // count of even

    }
//    bool isValida1(vector<int>& v)
//    {
//        for (int i = 0; i < v.size(); ++i)
//        {
//            for (int j = i + 2; )
//        }
//    }

};

int main()
{

    LT0932 lt;


    return 0;
}
