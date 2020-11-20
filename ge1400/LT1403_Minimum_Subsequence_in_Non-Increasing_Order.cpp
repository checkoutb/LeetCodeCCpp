
#include "../header/myheader.h"

class LT1403
{
public:

// D D


//    priority_queue<int> pq(begin(nums), end(nums));
//    while (sub_sum <= half_sum) {
//        res.push_back(pq.top());
//        sub_sum += res.back();
//        pq.pop();
//    }





//Runtime: 16 ms, faster than 58.44% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
//Memory Usage: 11 MB, less than 74.22% of C++ online submissions for Minimum Subsequence in Non-Increasing Order.
// 怎么subsequence 是无序的？。。。不过更简单
    vector<int> lt1403a(vector<int>& nums)
    {
        int sumD2 = accumulate(begin(nums), end(nums), 0) / 2;
        sort(begin(nums), end(nums), std::greater<int>());
        int i = 0;
        int sum2 = 0;
        for (; i < nums.size(); ++i)
        {
            sum2 += nums[i];
            if (sum2 > sumD2)
                break;
        }
        return vector<int>(begin(nums), begin(nums) + i + 1);
    }

};

int main()
{
//    vector<int> v = {4,3,10,9,8};
//    vector<int> v = {4,4,7,6,7};
    vector<int> v = {7};

    LT1403 lt;

    vector<int> vi = lt.lt1403a(v);
    showVectorInt(vi);

    return 0;
}
