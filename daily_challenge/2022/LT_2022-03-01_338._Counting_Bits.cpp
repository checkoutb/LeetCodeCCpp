
#include "../../header/myheader.h"

class LT
{
public:


//        while(x){
//            x = (x&(x-1));
//            cnt++;
//        }


//        for(int i = 1 ; i<=n ; i++){
//            res[i] = res[i&(i-1)]+1 ;
//        }


//for (int i=1; i<=num; i++) f[i] = f[i >> 1] + (i & 1);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Counting Bits.
//Memory Usage: 7.9 MB, less than 48.88% of C++ online submissions for Counting Bits.
// 应该是复制。
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1);
        if (n == 0)
            return ans;

        ans[1] = 1;
        int idx = 2;
        while (idx <= n)
        {
            for (int i = 0; i < idx && (idx + i) <= n; i++)
            {
                ans[idx + i] = 1 + ans[i];
            }
            idx <<= 1;
        }

        return ans;
    }

};

int main()
{

    LT lt;

    int n = 5;

    showVectorInt(lt.countBits(n));

    return 0;
}
