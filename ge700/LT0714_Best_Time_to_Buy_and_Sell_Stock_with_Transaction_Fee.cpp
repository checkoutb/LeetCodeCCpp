
#include "../header/myheader.h"

class LT0714
{
public:


// discuss
// 2个数组 表示最大收益，一个代表这天有股票，一个代表这天没有股票
// 有股票的最大收益 = max(昨天的有股票的最大收益， 昨天没有股票-今天的价格)
// 没有股票 = max (昨天没有股票， 昨天有股票+今天价格-fee)


// 24/44 wrong...
    // 买入时成本+fee，如果卖出后价格下降超过fee，刷新最低价。
    int lt0714b(vector<int>& prices, int fee)
    {
        int sz1 = prices.size();
        int ans = 0;
        int arr[sz1][2] = {{0}};
        int max1 = prices[0] + fee;
        int max2 = prices[0] + fee;
        int min1 = prices[0] + fee;
        int min2 = INT_MAX;
        int t1 = 0;

        for (int i = 1; i < sz1; i++)
        {
            int p = prices[i];
            max1 = max(max1, p);
            if (t1 != 0)
                min2 = min(min2, p + fee);
            t1 = max(t1, (p - min1));
            if (min2 < max1)
            {
//            cout<<" . .        "<<min2<<", "<<max1<<endl;
                min1 = p + fee;
                max1 = min1;
                min2 = INT_MAX;
                ans += t1;
//        cout<<t1<<endl;
                t1 = 0;
            }
            if (t1 == 0)
                min1 = min(min1, p + fee);
        }

//        cout<<t1<<endl<<endl;

        ans += t1;
        return ans;
    }


    // 34 / 44. tle.
    int lt0714a(vector<int>& prices, int fee)
    {
        int sz1 = prices.size();
        int ans = 0;
        int arr[sz1][2] = {{0}};

        for (int i = 1; i < sz1; i++)
        {
            int t1 = arr[i - 1][0];
            int p = prices[i];
            for (int j = 0; j < i; j++)
            {
                t1 = max(t1, p - prices[j] - fee + arr[j][0]);
            }
            arr[i][0] = t1;
        }

        #ifdef __test
        for (int z = 0; z < sz1; z++)
        {
            cout<<arr[z][0]<<", ";
        }
        cout<<endl;
        #endif // __test

        ans = arr[sz1 - 1][0];
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,3,2,8,4,9};
//    int fee = 2;

//    vector<int> v = {1,3,7,5,10,3};
//    int fee = 3;


    LT0714 lt;

    cout<<lt.lt0714b(v, fee)<<endl;

    return 0;
}
