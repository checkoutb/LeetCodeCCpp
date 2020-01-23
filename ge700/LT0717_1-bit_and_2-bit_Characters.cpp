
#include "../header/myheader.h"

class LT0717
{
public:






// 。。。。。还是12ms。。。
//Runtime: 12 ms, faster than 9.66% of C++ online submissions for 1-bit and 2-bit Characters.
//Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for 1-bit and 2-bit Characters.
    // 应该是从后面开始遍历。。
    // 最后2个是 00，必然知道 最后一位肯定是1bit的
    // 最后2位是 10，需要再往前看一位，110，010，；这里010可以确定最后一个char是2bit的。110，还需要往前一位。1110，0110；0110能确定，1110还需要往前一位。
    // 就是说，从后往前，第二个0 出现就能确定了。或者没有第二个0。。
    // 或者，从后往前，出现第二个0，或到头。1的个数。
    bool lt0717b(vector<int>& bits)
    {
        int sz1 = bits.size();
        if (sz1 == 1)
            return true;
        int t = 0;
        for (int i = sz1 - 2; i >= 0; i--)
        {
            if (bits[i] == 0)
                break;
            t += bits[i];
        }
        return t % 2 == 0;
    }


// most are 4ms...
//Runtime: 12 ms, faster than 9.66% of C++ online submissions for 1-bit and 2-bit Characters.
//Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for 1-bit and 2-bit Characters.
    // 感觉只有一种解码后的结果吧？这是要找一种非遍历就能确定最后一个char的方法？
    bool lt0717a(vector<int>& bits)
    {
        int sz1 = bits.size();
        int t = 0;
        for (int i = 0; i < sz1; i += t)
        {
            if (bits[i] == 0)
            {
                t = 1;
            }
            else
            {
                t = 2;
            }
        }
        bool ans = t == 1;
        return ans;
    }

};

int main()
{

    vector<vector<int>> arr = {{1,0,0},{1,1,1,0},{1,1,0}};

    LT0717 lt;

    for (vector<int> a : arr)
    {
        cout<<lt.lt0717b(a)<<endl;
    }

    return 0;
}
