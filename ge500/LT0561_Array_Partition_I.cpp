
#include "../header/myheader.h"

class LT0561
{
public:

// D D
//		int[] exist = new int[20001];
//		for (int i = 0; i < nums.length; i++) {
//			exist[nums[i] + 10000]++;
//		}
//		int sum = 0;
//		boolean odd = true;
//		for (int i = 0; i < exist.length; i++) {
//			while (exist[i] > 0) {
//				if (odd) {
//					sum += i - 10000;
//				}
//				odd = !odd;
//				exist[i]--;
//			}
//		}
//		return sum;
// 桶排序。 从最小的桶开始， 捡一个，扔一个。



//Runtime: 144 ms, faster than 87.46% of C++ online submissions for Array Partition I.
//Memory Usage: 28.1 MB, less than 94.55% of C++ online submissions for Array Partition I.
// 2633的踩。。
    int lt0561a(vector<int> nums)
    {
        std::sort(begin(nums), end(nums));
        int ans{0};
        for (int i = 0; i < nums.size(); i += 2)
        {
            ans += nums[i];
        }
        return ans;
    }

};

int main()
{

    LT0561 lt;


    return 0;
}
