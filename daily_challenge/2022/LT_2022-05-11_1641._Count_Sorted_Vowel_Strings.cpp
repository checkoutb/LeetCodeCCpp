
#include "../../header/myheader.h"

class LT
{
public:

// D D



//Now we have n characters, we are going to insert 4 l inside.
//We can add in the front, in the middle and in the end.
//How many ways do we have?
//For the 1st l, we have n+1 position to insert.
//For the 2nd l, we have n+2 position to insert.
//For the 3rd l, we have n+3 position to insert.
//For the 4th l, we have n+4 position to insert.
//Also 4 l are the same,
//there are (n + 1) * (n + 2) * (n + 3) * (n + 4) / 4! ways.
// ..因为是 非降序列，所以我们有 4个位置，这4个位置 就是 变化的位置。 所以有了 (n+1)*(n+2)*(n+3)*(n+4)
// 4个都相同，所以 是 组合，不是排列。


// (n+4) C 4
//return comb(n+4,4)



//        vector<int> dp = {0,1,1,1,1,1};
//        for (int i = 1; i <= n; ++i)
//            for (int k = 1; k <= 5; ++k)
//                dp[k] += dp[k - 1];
//        return dp[5];


//Runtime: 4 ms, faster than 35.46% of C++ online submissions for Count Sorted Vowel Strings.
//Memory Usage: 5.9 MB, less than 58.60% of C++ online submissions for Count Sorted Vowel Strings.
    int lta(int n)
    {
        int arr[5] = {1,1,1,1,1};           // index: how many char smaller than index, value: count

        while (n-- > 1)
        {
            for (int i = 1; i < 5; ++i)
            {
                arr[i] += arr[i - 1];
            }
        }

        int ans = std::accumulate(begin(arr), end(arr), 0);
        return ans;
    }

};

int main()
{

    LT lt;

//    int n(2);
    int n{33};

    cout<<lt.lta(n)<<endl;

    return 0;
}
