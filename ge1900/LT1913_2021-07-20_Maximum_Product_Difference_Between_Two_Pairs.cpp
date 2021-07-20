
#include "../header/myheader.h"

class LT1913
{
public:

// D D

//    int a = INT_MIN, b = INT_MIN, c = INT_MAX, d = INT_MAX;
//    for(int& i : nums){
//        if(i > a || i > b){
//            b = max(b, a);
//            a = i;
//        }
//        if(i < c || i < d){
//            d = min(d, c);
//            c = i;
//        }
//    }
//    return (a*b)-(c*d);


//		if(nums[i]>=largest) {
//			secondLargest = largest;
//			largest = nums[i];
//		} else if(nums[i]>secondLargest) secondLargest = nums[i];
//		if(nums[i]<=smallest) {
//			secondSmallest = smallest;
//			smallest = nums[i];
//		} else if(nums[i]<secondSmallest) secondSmallest = nums[i];




//Runtime: 28 ms, faster than 77.29% of C++ online submissions for Maximum Product Difference Between Two Pairs.
//Memory Usage: 20.4 MB, less than 14.74% of C++ online submissions for Maximum Product Difference Between Two Pairs.
// 元素都>=1， 所以  最大最小。  如果有负数的话，就应该  最大×最大 - 最小×最大。 当然distinct，就有点烦了。。还有 最小不一定是负数， 最大也不一定是正数。。。
    int lt1913a(vector<int>& nums)
    {
        int sz1 = nums.size();
        std::partial_sort(begin(nums), begin(nums) + 2, end(nums));
        int mn1 = nums[0];
        int mn2 = nums[1];
        std::partial_sort(begin(nums), begin(nums) + 2, end(nums), [](const int a, const int b){
                            return a > b;
                          });
        return nums[0] * nums[1] - mn1 * mn2;
//        std::partial_sort(begin(nums) + sz1 - 3, end(nums), end(nums));
//        #ifdef __test
//        showVectorInt(nums);
//        #endif // __test
//        return nums[sz1 - 1] * nums[sz1 - 2] - nums[0] * nums[1];
    }

};

int main()
{
//    myvi v2 = {7,6,5,4,3,2,1};
//    std::partial_sort(begin(v2), begin(v2) + 2, end(v2));
//    showVectorInt(v2);
////    std::partial_sort(end(v2) - 3, end(v2), end(v2));               // 是 第一个参数 到 第三个参数 之间的范围，有序后， 放到 第一个到 第二个参数 之间。 所以 后n个不可能。。除非 自定义方法，然后 降序。
//    std::partial_sort(begin(v2), begin(v2) + 2, end(v2), [](const int a, const int b){
//                        return a > b;
//                      });
//    showVectorInt(v2);

//    myvi v = {5,6,2,7,4};
    myvi v = {4,2,5,9,7,4,8};

    LT1913 lt;

    cout<<lt.lt1913a(v)<<endl;

    return 0;
}
