
#include "../header/myheader.h"

class LT1283
{
public:

// D

//        int left = 1, right = 1e6, m, sum;
//        while (left < right) {
//            m = (left + right) / 2, sum = 0;
//            for (int i : A)
//                sum += (i + m - 1) / m;               // .
//            if (sum > threshold)
//                left = m + 1;
//            else
//                right = m;
//        }
//        return left;
// ,,二分到底是多快。。。


// after discuss
    int lt1283b(vector<int>& nums, int threshold)
    {
        int sum2 = std::accumulate(begin(nums), end(nums), 0);
        int t1 = sum2 / threshold;
        int t2 = sum2 / (threshold - 1);
        return -1;
    }



// tle.
    int lt1283a(vector<int>& nums, int threshold)
    {
        std::sort(begin(nums), end(nums), std::greater<int>());
        int sum2 = std::accumulate(begin(nums), end(nums), 0);
        int t1 = sum2 / threshold;
        t1 = max(t1, 1);
        while (true)
        {
            int thre = 0;
            for (int i = 0; i < nums.size(); ++i)
            {
                thre += (nums[i] / t1 + ((nums[i] % t1) != 0));
                if (thre > threshold)
                    goto AAA;
            }

            return t1;

            AAA:
            t1++;
        }
    }

};

int main()
{

//    vector<int> v = {1,2,5,9};
//    int t = 6;

//    vector<int> v = {2,3,5,7,11};
//    int t = 11;

    vector<int> v = {19};
    int t{5};

    LT1283 lt;

    cout<<lt.lt1283a(v, t);

    return 0;
}
