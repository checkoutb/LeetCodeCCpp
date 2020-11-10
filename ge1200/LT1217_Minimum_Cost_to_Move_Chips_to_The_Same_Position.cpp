
#include "../header/myheader.h"

class LT1217
{
public:

// D D

//  int cnt[2] = {};
//  for (auto p : chips) ++cnt[p % 2];
//  return min(cnt[0], cnt[1]);



//Runtime: 4 ms, faster than 53.92% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
//Memory Usage: 7.6 MB, less than 97.34% of C++ online submissions for Minimum Cost to Move Chips to The Same Position.
//    position[i] + 2 or position[i] - 2 with cost = 0.
//    position[i] + 1 or position[i] - 1 with cost = 1.
// +-2 是0， 1是1。 那就只需要看 多少 硬币 距离自己 是 奇数距离。。。 好像只需要 看 前2个位置就可以了， 毕竟 其他的位置都是 +-2 无消耗移到前2个。
// 等于就是 min(奇数下标的硬币数， 偶数下标的硬币数) ？
    int lt1217a(vector<int>& position)
    {
        int odd = 0;
        int even = 0;
        for (int i = 0; i < position.size(); i++)
        {
            if (position[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        return min(even, odd);
    }

};

int main()
{

//    vector<int> v = {1,2,3};
//    vector<int> v = {2,2,2,3,3};
    vector<int> v = {1, 1000000};

    LT1217 lt;

    cout<<lt.lt1217a(v)<<endl;

    return 0;
}
