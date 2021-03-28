
#include "../../header/myheader.h"

class LT5715
{
public:




// AC

// [2, 1000] 应该不会 tle 吧
// 现在偶数， 原数组[偶数/2]
// 现在奇数， 原数组[n/2 + 奇数/2(自动截0)]
// 分散
//
    int lt5715a(int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
//            if (i % 2 == 0)
//                int t2 = i * 2;
//            int cnt = 1;
            int t2 = i;
            int cnt = 0;
            do
            {
                if (t2 < n / 2)
                {
                    t2 *= 2;
                }
                else
                {
                    t2 = (t2 - n / 2) * 2 + 1;
                }
                cnt++;
            } while (t2 != i);
            ans = max(ans, cnt);
        }
        return ans;
    }

};

int main()
{
//    int n = 2;
//    int n = 4;
    int n = 6;

    LT5715 lt;

    cout<<lt.lt5715a(n)<<endl;

    return 0;
}
