
#include "../header/myheader.h"

class LT1015
{
public:


// 最多K个长度，如果没有，就是-1，，，好像是必然存在？
// 1,3,7,9
    int lt1015b(int K)
    {
        int t1;
        int ans = 0;
        unordered_set<int> set2;
        int a1 = k % 10;
        if (a1 != 1 && a1 != 3 && a1 != 7 && a1 != 9)
            return -1;
        while (set2.find(t1) == set2.end())
        {

            set2.insert(t1);
        }

    }

// 16个1。。。% 17 == 0
    int lt1015a(int K)
    {
        long long ans = 1;
        int cnt = 1;
        while (ans <= INT_MAX)
        {
            if (ans % K == 0)
            {
                break;
            }
            ans *= 10;
            ans += 1;
            cnt++;
        }
        return ans <= INT_MAX ? cnt : -1;
    }

};

int main()
{

    LT1015 lt;

    for (int i = 1; i <= 3; i++)
    {
        cout<<lt.lt1015a(i)<<endl;
    }

    return 0;
}
