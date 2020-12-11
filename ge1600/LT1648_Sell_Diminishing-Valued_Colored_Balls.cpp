
#include "../header/myheader.h"

class LT1648
{
public:

// D D

// .. 二分的  =  和 +1 各式各样。

// 不sort，直接while里 for全部，可以用longlong，更快。


// discuss 是 另外的风格。好像没有 二分的。。

//    sort(begin(inv), end(inv));
//    for (int i = inv.size() - 1; i >= 0 && orders > 0; --i, ++colors) {
//        long cur = inv[i], prev = i > 0 ? inv[i - 1] : 0;
//        long rounds = min(orders / colors, cur - prev);
//        orders -= rounds * colors;
//        res = (res + (cur * (cur + 1) - (cur - rounds) * (cur - rounds + 1)) / 2 * colors) % 1000000007;
//        if (cur - prev > rounds) {
//            res = (res + orders * (cur - rounds)) % 1000000007;
//            break;
//        }
//    }




//Runtime: 404 ms, faster than 61.09% of C++ online submissions for Sell Diminishing-Valued Colored Balls.
//Memory Usage: 65.3 MB, less than 68.56% of C++ online submissions for Sell Diminishing-Valued Colored Balls.
// 最大堆，优先序列， 不过 100000000， tle。
// 最后剩余的 各种颜色的球 的 数量  削峰。
// 难道 二分 找
    int lt1648(vector<int>& inventory, int orders)
    {
//        if (orders == 836556809)
//            return 373219333;
        sort(begin(inventory), end(inventory));
        int st = 0;
        int en = *max_element(begin(inventory), end(inventory));
        int mod = int (1E9 + 7);
        while (st < en)
        {
            int mid = (st + en) / 2;

            // accumulate - mid * distance..
//            int i = std::distance(begin(inventory), upper_bound(begin(inventory), end(inventory), mid));
            int sum2 = std::accumulate(upper_bound(begin(inventory), end(inventory), mid), end(inventory), 0,
                [&mid, &mod](const int& sum3, const int& now){ return (now - mid + sum3) >= mod ? mod : (now - mid + sum3);});
            if (sum2 >= orders)
            {
                // mid 越小， sum2 越大。
                st = mid + 1;
            }
            else
            {
                en = mid;
            }
            #ifdef __test
//            cout<<mid<<", ";
//            cout<<sum2<<", "<<orders<<endl;
            #endif // __test

//            int sum2 = 0;
//            for (; i < inventory.size(); ++i)
//            {
//
//            }
        }
//        #ifdef __test
//        cout<<st<<endl;
//        showVectorInt(inventory);
//        #endif // __test
        long ans = 0;
//        st += -1;
        st++;
        for (int i = 0; i < inventory.size(); ++i)
        {
            if (inventory[i] >= st && orders > 0)
            {
                int cnt1 = inventory[i] - st + 1;
//                cout<<cnt1;
//                cnt1 = min(orders, cnt1);
                // cnt1 的各个值的 差距不应该大于1。 所以要 平均。  不，最后再减。jia..
                orders -= cnt1;
                ans = (ans + long (inventory[i] + inventory[i] - cnt1 + 1) * cnt1 / 2) % mod;
//                cout<<" . ."<<ans<<". . "<<cnt1<<" ."<<endl;;
            }
        }
//        cout<<orders<<endl;
        ans = (ans + (long) orders * (st - 1)) % mod;
        return ans;
    }

};

int main()
{
//    myvi v = {2,5};
//    int a = 4;

//    myvi v = {3,5};
//    int a = 6;

//    myvi v = {2,8,4,10,6};
//    int a = 20;

//    myvi v = {1000000000};
//    int a = 1000000000;

    myvi v = {497978859,167261111,483575207,591815159};         // 373219333
    int a = 836556809;

//    myvi v = {81,86,43,41,37,51,93,23,15,22,26,89,37};      // 14758
//    int a = 256;



    LT1648 lt;

    cout<<lt.lt1648(v, a);

    return 0;
}
