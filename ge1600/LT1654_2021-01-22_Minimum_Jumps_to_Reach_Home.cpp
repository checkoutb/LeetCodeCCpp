
#include "../header/myheader.h"

class LT1654
{
public:

// D D

//2.Can't go back twice, so max is Math.max(max value in forbidden, 2000) + 2 * b;
// 感觉好像不太对，  至少不可能 2 * 吧。 应该是 1 *


//max_val=max([x]+forbidden) +a+b
// 最大 + a + b
//Not sure if you can prove max_val = max([target] + forbidden) + a + b is safe,
//But you can prove max_val = max([target] + forbidden) + a + a + b is safe



// mx 应该怎么取？  100 * 的话 是 540ms。    5 * 是错误的。
//Runtime: 68 ms, faster than 57.24% of C++ online submissions for Minimum Jumps to Reach Home.
//Memory Usage: 28.4 MB, less than 33.49% of C++ online submissions for Minimum Jumps to Reach Home.
// 不能连退2次，  进a, 退b，  不能负数，
// 能一直向前， 所以需要一个限制，   b > a呢
    int lt1654a(vector<int>& forbidden, int a, int b, int x)
    {
        queue<int> que2;
        unordered_set<int> set2(begin(forbidden), end(forbidden));
//        unordered_set<int> forb(begin(forbidden), end(forbidden));
        que2.push(0);
        int ans = -1;
        int mx = 0;
        if (a > b)
        {
            mx = x + b + 1;
        }
        else
        {
            mx = 1 + 10 * (max(a,max(b,x)));
        }
        while (!que2.empty())
        {
            ans++;
            int sz1 = que2.size();
            while (sz1-- > 0)
            {
                int pst = que2.front();
                que2.pop();
                if (pst == x || -pst == x)
                    return ans;
                if (pst < 0)
                {
                    pst = -pst + a;
                    if (pst < mx && set2.find(pst) == set2.end())
                    {
                        que2.push(pst);
                        set2.insert(pst);
                    }
                }
                else
                {
                    int pst2 = pst + a;
                    if (pst2 < mx && set2.find(pst2) == set2.end())
                    {
                        que2.push(pst2);
                        set2.insert(pst2);
                    }
                    pst2 = pst - b;
                    if (pst2 < mx && pst2 > 0 && set2.find(pst2) == set2.end())
                    {
                        pst2 = -pst2;
                        que2.push(pst2);
                        set2.insert(pst2);
                    }
                }
            }
        }

        return -1;
    }

};

int main()
{
//    myvi v = {14,4,18,1,15};
//    int a{3},b{15},x{9};

//    myvi v = {8,3,16,6,12,20};
//    int a{15},b{13},x{11};

//    myvi v = {1,6,2,14,5,17,4};
//    int a{16},b{9},x{7};

    myvi v = {162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,
    154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98};
    int a = 29;
    int b = 98;
    int x = 80;

    LT1654 lt;

    cout<<lt.lt1654a(v,a,b,x);

    return 0;
}
