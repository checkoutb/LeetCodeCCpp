
#include "../header/myheader.h"

class LT2571
{
public:

    // D D

    // return __builtin_popcount(n ^ (n * 3));


    //int res = 0;
    //while (n > 0) {
    //    if ((n & 3) == 3) {
    //        n++;
    //        res++;        // 多个1，应该是把 res += 2分开了， 因为上面是 +1， 所以 还会剩一个1 的，所以这里 暂时+1， 剩余的1 会由下面来res+1。
    //    }
    //    else {
    //        res += n & 1;             // 3代表 multiple 1, 所以这里是 单个1 或 0， 如果是1， 就res+1
    //        n >>= 1;
    //    }
    //}
    //return res;

    //If it's single 1, res += 1
    //If it's multiple 1s, res += 2
    // 和代码不太一样，不是这么的直接。



    //Runtime0 ms
    //    Beats
    //    100 %
    //    Memory6.2 MB
    //    Beats
    //    14.29 %
    // add   1111 + 1 = 10000       11
    //  1110111 +1+1 100001000 -1-1 4, +1 +1 10000000 -1 3
    // 追加 或 独立。
    // 11100111  4, 4
    // 111000111 5 , 4
    // 连续1， 2种：  只有一个1，直接减去， 否则， +1 然后减去。
    // 差2
    // 单个1， 直接减
    // 连续1， 看 2个 连续1 之间 是否大于2. 大于2 各自处理。
    // 111010111   4 .. ..
    // 1110010111 5, 5
    // 11101010111 5, 6,   单个1可以认为是-1.
    // 111010100111 6,6
    // 0的个数 - 单个1 的个数 <= 2，就合并。
    // 1110011100111 6 6
    // 111001110011100111 8 8
    // 11100111011100111  7 
    // 10111 3
    // ==2 douyiyang
    int lt2571a(int n)
    {
        vector<int> vi;
        while (n > 0)
        {
            vi.push_back(n % 2);
            n >>= 1;
        }
        //reverse(begin(vi), end(vi));

        int ans = 0;

        vector<int> v2;
        int cnt = 1;
        for (int i = 1; i < vi.size(); ++i)
        {
            if (vi[i] != vi[i - 1])
            {
                v2.push_back(vi[i - 1] ? cnt : -cnt);
                cnt = 1;
            }
            else
            {
                ++cnt;
            }
        }
        v2.push_back(cnt);

        for (int i = 0; i < v2.size(); ++i)
        {
            if (v2[i] > 0)
            {
                if (v2[i] == 1)
                {
                    ++ans;
                }
                else
                {
                    cnt = 0;
                    int j = i + 1;
                    for (; j < v2.size(); ++j)
                    {
                        if (v2[j] > 0)
                        {
                            ;
                        }
                        else if (v2[j] <= -2)
                        {
                            break;
                        }
                        else if (v2[j] == -1)
                            ++cnt;
                    }
                    --j;
                    ans += 2 + cnt;
                    i = j;
                }
            }
        }

        return ans;

        //for (int i = 0; i < vi.size(); ++i)
        //{
        //    if (vi[i] == 1)
        //    {
        //        int st = i + 1;
        //        if (st < vi.size())
        //        {
        //            if (vi[i] == 0)
        //            {
        //                ++ans;
        //                continue;
        //            }

        //        } 
        //    }
        //}

    }

};

int main()
{

    LT2571 lt;

    int n = 39;
    //int n = 54;


    cout << lt.lt2571a(n) << endl;

    return 0;
}
