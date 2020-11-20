
#include "../header/myheader.h"

class LT1395
{
public:

// D D

//    for (auto i = 1; i < rating.size() - 1; ++i) {
//        int less[2] = {}, greater[2] = {};
//        for (auto j = 0; j < rating.size(); ++j) {
//            if (rating[i] < rating[j])
//                ++less[j > i];
//            if (rating[i] > rating[j])
//                ++greater[j > i];
//        }
//        res += less[0] * greater[1] + greater[0] * less[1];
//    }
// 前面比他小，后面比他大  或者  前面比他大，后面比他小。



//Runtime: 4 ms, faster than 97.97% of C++ online submissions for Count Number of Teams.
//Memory Usage: 8.1 MB, less than 13.67% of C++ online submissions for Count Number of Teams.
    int lt1395a(vector<int>& rating)
    {
        vector<int> vasc(rating.size());
        vector<int> vdesc(rating.size());
        int ans = 0;
        int sz1 = rating.size();

        for (int i = 0; i < sz1; i++)
        {
            int t1 = rating[i];
            int small = 0;
            int big = 0;
            for (int j = i + 1; j < sz1; ++j)
            {
                if (rating[j] > t1)
                    big++;
                else if (rating[j] < t1)
                    small++;
            }
            vasc[i] = big;
            vdesc[i] = small;
        }
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                if (rating[i] > rating[j])
                {
                    ans += vdesc[j];
                }
                else if (rating[i] < rating[j])
                {
                    ans += vasc[j];
                }
            }
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {2,5,3,4,1};
//    vector<int> v = {2,1,3};
    vector<int> v = {1,2,3,4};

    LT1395 lt;

    cout<<lt.lt1395a(v)<<endl;

    return 0;
}
