
#include "../header/myheader.h"

class LT0322
{
public:

    // discuss ... need[a] = min(need[a], need[a-c] + 1);
    // dp

    // 114/182 time out...
    int lt0322a(vector<int>& coins, int amount)
    {
        int result = 0;
        sort(coins.begin(), coins.end());

        result = recursiona1(coins, amount, 0, coins.size() - 1, amount / coins[0] + 1);

        if (result == (amount / coins[0] + 1))
        {
            result = -1;
        }

        return result;
    }

    int recursiona1(vector<int>& coins, int am, int counts, int inc, int max1)
    {

        #ifdef __test
        cout<<endl<<am<<", "<<counts<<", "<<inc<<", "<<max1<<endl;
//        cout<<coins[inc]<<endl;
        #endif // __test

        if (counts >= max1)
            return -1;
        if (am == 0)
            return counts;
        if (inc < 0)
            return -1;

        int t1 = am / coins[inc];
        if (t1 == 0)
        {
            int t2 = recursiona1(coins, am, counts, inc - 1, max1);     // 和下面for可以合并。

            if (t2 == -1)
                return -1;
            if (t2 > max1)
                t2 = max1;
            else
                max1 = t2;

            return max1;
        }
        else
        {
//            int t2 = max1;
            int t3 = max1;
            for (int i = t1; i >= 0; i--)
            {
                t3 = recursiona1(coins, am - (coins[inc] * i), counts + i, inc - 1, max1);
                if (t3 == -1)
                    continue;
                if (t3 > max1)
                    t3 = max1;
                else
                    max1 = t3;
            }
            return max1;
        }
    }


//    bool canMakeUp(vector<int>& coins, int amount)
//    {
////        bool result = false;
//        int t1 = 0;
//        for (vector<int>::iterator it = coins.begin(); it != coins.end(); it++)
//        {
//            t1 = amount
//        }
//
//        return false;
//    }

};


int main()
{

//Input: coins = [1, 2, 5], amount = 11
//Output: 3
//Explanation: 11 = 5 + 5 + 1
//
//Input: coins = [2], amount = 3
//Output: -1


//    int arr[] = {1, 2, 5};
//    int amount = 11;

//    int arr[] = {2};
//    int amount = 3;

    int arr[] = {288,160,10,249,40,77,314,429};
    int amount = 9208;

    sort(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    vector<int> v(arr, arr + (sizeof(arr) / sizeof(arr[0])));

    LT0322 lt;
    cout<<endl<<endl<<lt.lt0322a(v, amount)<<endl;

    return 0;
}
