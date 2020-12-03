
#include "../header/myheader.h"

class LT1567
{
public:

// D D


//        int ans = 0, pos = 0, neg = 0;
//        for (int &e : nums) {
//            if (e > 0) {
//                pos = pos > 0 ? pos + 1 : 1;
//                neg = neg > 0 ? neg + 1 : 0;
//            } else if (e < 0) {
//                int pp = pos, nn = neg;
//                pos = nn > 0 ? nn + 1 : 0;
//                neg = pp > 0 ? pp + 1 : 1;
//            } else {
//                pos = neg = 0;
//            }
//            ans = max(ans, pos);
//        }


//        // sum is used to count the number of negative numbers from zeroPosition to current index
//        int firstNegative = -1, zeroPosition = -1, sum = 0, max = 0;
//        for(int i = 0;i < nums.length; i++){
//            if(nums[i] < 0){
//                sum++;
//				// we only need to know index of first negative number
//                if(firstNegative == -1) firstNegative = i;
//            }
//			// if current number is 0, we can't use any element from index 0 to i anymore, so update zeroPosition, and reset sum and firstNegative. If it is a game, we should refresh the game when we meet 0.
//            if(nums[i] == 0){
//                sum = 0;
//                firstNegative = -1;
//                zeroPosition = i;
//            }
//            else{
//			    // consider index of zero
//                if(sum%2 == 0) max = Math.max(i - zeroPosition, max);
//				// consider index of first negative number
//                else max = Math.max(i - firstNegative, max);
//            }
//        }
//        return max;


//        int firstEvenNeg = -1, firstOddNeg = -2, res = 0, negCount = 0;  // treat 0 neg as even
//        for (int i = 0; i < nums.length; i++) {
//            if (nums[i] == 0) {  // reset everytime you met a zero;
//                negCount = 0; // neg count after last zero
//                firstEvenNeg = i;
//                firstOddNeg = -2;
//            } else {
//                if (nums[i] < 0) negCount++;  // number of negatives from last zero or head of array
//                if (negCount == 1 && firstOddNeg == -2) firstOddNeg = i;   // init odd cnt neg;
//                if (negCount % 2 == 0) res = Math.max(res, i - firstEvenNeg);
//                else if (firstOddNeg > -2) res = Math.max(res, i - firstOddNeg);
//            }
//        }
//        return res;



//Runtime: 180 ms, faster than 98.53% of C++ online submissions for Maximum Length of Subarray With Positive Product.
//Memory Usage: 58.1 MB, less than 85.92% of C++ online submissions for Maximum Length of Subarray With Positive Product.
    int lt1567a(vector<int>& nums)
    {
        int ans = 0;
        int cnt = 0;
        int ispos = true;
        int fstneg = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                cnt = 0;
                fstneg = -1;
                ispos = true;       // .
                continue;
            }
            cnt++;
            if (nums[i] < 0)
            {
                ispos = !ispos;
                if (fstneg == -1)
                    fstneg = i;
            }
            if (ispos && cnt > ans)
                ans = cnt;
            if (fstneg != -1 && !ispos && (i - fstneg) > ans)
                ans = i - fstneg;
//            cout<<ans<<", "<<i<<", "<<fstneg<<", "<<ispos<<endl;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,-2,-3,4};

//    myvi v = {0,1,-2,-3,-4};

//    myvi v = {-1,-2,-3,0,1};

//    myvi v = {-1,2};

//    myvi v = {1,2,3,5,-6,4,0,10};

    myvi v = {-16,0,-5,2,2,-13,11,8};       // 6

    LT1567 lt;

    cout<<lt.lt1567a(v);

    return 0;
}
