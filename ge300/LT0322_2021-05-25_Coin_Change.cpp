
#include "../header/myheader.h"

class LT0322
{
public:

// D D

//        int count[amount+1];
//        count[0] = 0;
//        for(int i=1;i<=amount;i++)
//        {
//            count[i] = INT_MAX-1;         // .
//            for(auto c:coins)
//            {
//              if(i-c>=0)
//                count[i] = min(count[i], count[i-c]+1);       //  INT_MAX + 1
//            }
//        }
//        return count[amount] == INT_MAX-1?-1:count[amount];




//Runtime: 80 ms, faster than 47.91% of C++ online submissions for Coin Change.
//Memory Usage: 14.3 MB, less than 60.29% of C++ online submissions for Coin Change.
//... 感觉还是tle的方法。。
// 上次 LT0322 中的 ： discuss： need[a] = min(need[a], need[a-c] + 1);
// type(need) == map ?  a应该是amount， 但是c是什么？不可能是coins中的啊，不然 1000000,[1], map会爆炸的。
// 求的是 最少需要多少个coin。
// 。。。 coin是INT_MAX， amount是10000
// 依然需要 从0到 10000？
    int lt0322a(vector<int>& coins, int amount)
    {
//        int arr[10001] = {0};
        if (amount == 0)
            return 0;
        vector<int> arr(amount + 1, 0);
        for (int c : coins)
            if (c <= amount)
                arr[c] = 1;
        for (int i = 1; i <= amount; ++i)
        {
            for (int c : coins)
            {
                if (c < i && arr[i - c] != 0)
                {
                    if (arr[i] == 0)
                    {
                        arr[i] = arr[i - c] + 1;
                    }
                    else
                    {
                        arr[i] = min(arr[i], arr[i - c] + 1);
                    }
                }
            }
        }
        return arr[amount] == 0 ? -1 : arr[amount];
    }

};

int main()
{
//    myvi v = {1,2,5};
//    int a = 11;

//    myvi v = {2};
//    int a = 3;

//    myvi v = {1};
//    int a = 0;

    myvi v = {1};
    int a = 2;

    LT0322 lt;

    cout<<lt.lt0322a(v, a)<<endl;

    return 0;
}
