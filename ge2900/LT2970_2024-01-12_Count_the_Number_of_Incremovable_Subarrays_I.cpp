
#include "../header/myheader.h"

class LT2970
{
public:


    // D D

	 //    int i, j, k, t, r = 0, n = nums.size();
  //       for(i = t = 0; i < n; ++i) {
  //           int a = nums[i];
  //           if (a <= t) break; else t = a;
  //       }
  //       if (i == n) return i*(i+1)/2; j = i;
		// for(i = n-1, t = 100; i >= 0; --i) {
  //           int a = nums[i];
  //           if (a >= t) break; else t = a;
		// }
		// k = i; // cout << j << ":" << k << endl;
		// for(i = 0, ++k; i <= j; ++i) {
		//     int a = (i) ? nums[i-1] : -1;
		// 	while(k < n && a >= nums[k]) ++k;
		// 	r += n-k+1;
		// }
  //       return r;

    // [j] is first down(not increase), so subarr's begin must < j (maybe must <= j, not sure, dont care)
    // [k] is last down, so subarr's end must > k
    // set subarr' begin is [0..j] , find the first element that value > [begin] and index > k
    //      and the element that after first found element are also OK (to be end of subarr)

    // so in brute force, if j from sz1-1 to i, it will be faster.
    //      when the subarr that removed [i, j] is not OK/right/good/符合/incremovable, the smaller j is also not OK.


// Runtime
// 10ms
// Beats90.71%of users with C++
// Memory
// 18.99MB
// Beats99.31%of users with C++

    // remove the subarr, remain is upupup
    // no idea... but size <= 50 。。 brute force..
    int incremovableSubarrayCount(vector<int>& nums)
    {
        size_t sz1 = nums.size();
        int ans = 0;
        for (size_t i = 0; i < sz1; ++i)
        {
            for (size_t j = i; j < sz1; ++j)        // remove [i, j]
            {
                int lst = -1;
                for (size_t k = 0; k < sz1; ++k)
                {
                    if (k >= i && k <= j)
                        continue;
                    if (nums[k] <= lst)
                        goto AAA;
                    lst = nums[k];
                }
                ++ans;

                AAA:
                continue;
            }
        }
        return ans;
    }

};

int main()
{

    LT2970 lt;


    return 0;
}
