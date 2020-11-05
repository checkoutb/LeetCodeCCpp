
#include "../header/myheader.h"

class LT1103
{
public:

// D D

// x = int(math.sqrt(candies * 2 + 0.25) - 0.5)

//        vector<int> res(n);
//        for (int i = 0; candies > 0; ++i) {
//            res[i % n] += min(candies, i + 1);
//            candies -= i + 1;
//        }
//        return res;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Distribute Candies to People.
//Memory Usage: 6.6 MB, less than 64.39% of C++ online submissions for Distribute Candies to People.
// 1+n * n == candies * 2
// n^2 + n - candies*2 = 0;
// (-1 +- genghao(1 + 8*candies))/2
    vector<int> lt1103a(int candies, int num_people)
    {
        vector<int> ans(num_people, 0);
        double d2 = (-1 + std::sqrt(1 + (long) candies * 8)) / 2.0;
        int i2 = (int) d2;
        int i3 = i2 / num_people;
        int i4 = i2 % num_people;

        for (int i = 0; i < num_people; i++)
        {
            int sum2 = 0;
            int mxcnt = i3 + (i < i4 ? 1 : 0);
            int cnt = 0;
            int t = i + 1;
            while (cnt++ < mxcnt)
            {
                sum2 += t;
                t += num_people;
            }
            ans[i] = sum2;
        }
        ans[i4] += (candies - (1 + i2) * i2 / 2);
        return ans;
    }

};

int main()
{

//    int c{7}, p{4};
    int c{10}, p{3};

    LT1103 lt;

    vector<int> v = lt.lt1103a(c, p);

    for_each (begin(v), end(v), fun_cout);

    return 0;
}
