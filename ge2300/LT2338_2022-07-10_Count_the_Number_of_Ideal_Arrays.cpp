
#include "../header/myheader.h"

class LT2338
{
public:

    // D

    // https://cp-algorithms.com/algebra/module-inverse.html


        //N = The number of ways to create a ideal array of length len2 from a strictly increasing ideal array of length len1
        //N = nChooseK(len2 - 1, len1 - 1)
        //There are len2 - 1 of potential places to put the bars
        //There are len1 - 1 bars to place


        //Just find number of sequences having all numbers unique such that a[i] is divisible by a[i - 1].
        //This count is conntained in tot array.Multiplying this count with the number of ways to expand this array into a N sized array.This ways is stored in dp[i][j] where i refers to number of unique elementsand j refers to size of the array.

        //Also the maximum length of sequence having a[i] divisible by a[i - 1] is just 14(1, 2, 4, 8, ...., 2 ^ 13).

        //For calculating dp[i][j]:-
        //Number of ways to fill j sized array with i unique elements is sum of number of ways to fill 1 to j - 1 sized array with i - 1 unique elements as we can add the remainig space with current element.


    // 有那么一点点了，  主要就是 要unique， 因为  1,1,1,x,x 的个数 是和 1,x,x 是一样的，所以 可以减少很多。
    // 扩展是 直接 每个元素乘以一个值来扩展的， 所以 长度是 2^n 次方。
    // 为了unique，所以 必须是 全体元素乘以某个值， {1,2} -> {1,2}+{3,6}/{4,8}/{5,10} ... 乘以2不行， 这个是怎么剔除的？
    //      {1,5} -> {1,5}+{10,50} .   首先 必须大于，所以 后续的第一个元素 必须大于 前面的 最后一个元素， 然后就是 找到 。。。 或许直接 最后一个元素*2/3/4/5 这样更快？       最大公约数？



    // tle

/*


1 1 1 1 1 1
1 1 1 1 1 2
1 1 1 1 1 3
...
1 1 1 1 1 10

1 1 1 1 2 2/4/6/8/10

1 1 1 1 3 3/6/9

1 1 1 1 4 4/8
1 1 1 1 5 5/10
1 1 1 1 6 6


1 1 1 2 2 2/4/6/8/10
1 1 1 2 4 4/8
1 1 1 2 6 6
1 1 1 2 8 8


[值作为第一个][长度]
但是 内存会炸。  先试下。  
或许 map，应该是稀疏的，所以 top-down

添加，是在前面添加，那么会改变 vvi，  后面添加不行，不知道最后一个元素是多少。

所以没有办法 top-down ？ 因为vvi的不是最终结果  。。 不过可以 一维数组，不会炸内存。

。。3层for，，不知道能不能过。 虽然最里面的应该是 log(maxValue)? 不是，应该 比log 大， 比 n 小。 
2层for是：  v + v/2 + v/3 + v/4 + v/5 ... + 1 = ? ， 1+0.5+0.333+0.25+0.2+0.166+  差不多 2.?v？,反正肯定存在固定值c，使得前面的 加法的值 < cv , 所以 里面两层 for 是 O(maxValue) ，所以 不会tle？
    那这样的话， 最内层的是 小于 log(maxValue) 的


*/
    int lt2338a(int n, int maxValue)
    {
//        vector<vector<int>> vvi(maxValue + 1, vector<int>(n, -11));

        vector<int> vi(maxValue + 1, 1);

        const int MOD = 1e9 + 7;

        for (int i = 1; i < n; ++i)
        {
            vector<int> vi2(maxValue + 1, 0);

            for (int i = 1; i <= maxValue; ++i)
            {
                //for (int j = 1; i * j <= maxValue; ++j)
                for (int j = i; j <= maxValue; j += i)
                {
                    vi2[i] = (vi2[i] + vi[j]) % MOD;
                }
            }

            swap(vi, vi2);
        }
        
        int ans = 0;
        for (int i : vi)
        {
            ans = (ans + i) % MOD;
        }
        return ans;

    }

    //int dfsa1(int mxl, int len, int mxv, int v, vector<vector<int>>& vvi)
    //{
    //    if (vvi[len][v] > -11)
    //        return vvi[len][v];

    //}

};

int main()
{

    LT2338 lt;

    //myvi v = { 2,5 };

    myvi v = { 5,3 };

    cout << lt.lt2338a(v[0], v[1]) << endl;

    return 0;
}
