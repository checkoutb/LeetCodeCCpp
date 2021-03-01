
#include "../header/myheader.h"

class LT1711
{
public:

// D D







//Runtime: 280 ms, faster than 92.37% of C++ online submissions for Count Good Meals.
//Memory Usage: 58 MB, less than 91.80% of C++ online submissions for Count Good Meals.
// 相加 有什么特殊的 简化方法？
    int lt1711a(vector<int>& deliciousness)
    {
        unordered_map<int, int> map2;
        int ans = 0;
        const int mod = 1E9 + 7;
        int mxele = *max_element(begin(deliciousness), end(deliciousness));
        mxele <<= 1;
        for (int i = 0; i < deliciousness.size(); ++i)
        {
            for (int pw = 0; pw < 22; ++pw)
            {
                int tar = 1<<pw;
                if (tar > mxele)
                    break;
                if (tar >= deliciousness[i])
                {
                    int need = tar - deliciousness[i];
                    if (map2.find(need) != map2.end())
                    {
                        int t2 = map2[need];
                        ans = (ans + t2) % mod;
//                        cout<<i<<", "<<deliciousness[i]<<", "<<tar<<", "<<need<<", "<<t2<<endl;
                    }
                }
            }
            map2[deliciousness[i]]++;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,3,5,7,9};
    myvi v = {1,1,1,3,3,3,7};

    LT1711 lt;

    cout<<lt.lt1711a(v)<<endl;

    return 0;
}
