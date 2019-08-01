
#include "../header/myheader.h"

class LT0405
{
public:

// details
//        vector<char> hex = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
//        string res = "";
//        if(num == 0)
//            return "0";
//        int count = 0;
//        while(num && count < 8)
//        {
//            res = hex[num & 15] + res;
//            num >>= 4;
//            count++;
//        }
//        return res;
// 4字节，8个16进制。。每次都是最低位的4位换算成16进制。然后再>>。。
// & 位与，，，，位，，，，，



//Runtime: 4 ms, faster than 68.06% of C++ online submissions for Convert a Number to Hexadecimal.
//Memory Usage: 8 MB, less than 89.27% of C++ online submissions for Convert a Number to Hexadecimal.

    // N->16进制，{Z-N} -> 补码。
    // 实际上就是 Z -> 补码的16进制形式且没有前导0.
    string lt0405a(int num)
    {
        if (num == 0)
            return "0";
        char i2c[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        bitset<32>* bs = nullptr;
        if (num >= 0)
        {
            bs = new bitset<32>(num);
        }
        else
        {
            int64_t t2 = (((int64_t)1)<<33) + num;          // + 优先级大于 << ....
            int32_t t3 = (int32_t) t2;
            bs = new bitset<32>(t3);
        }
        string ans;
        for (int i = 31; i > 0; i -= 4)
        {
            int t1 = bs->test(i) * 8 + bs->test(i - 1) * 4 + bs->test(i - 2) * 2 + bs->test(i - 3);
            if (ans.length() != 0 || t1 != 0)
                ans += i2c[t1];
        }
        return ans;
    }
};

int main()
{
    int num = -2;

    LT0405 lt;
    cout<<endl<<lt.lt0405a(num)<<endl;

    bitset<32>* bs = new bitset<32>(-1);
    cout<<endl<<*bs<<endl;
    cout<<bs->test(4)<<endl;
    cout<<bs->operator[](4)<<endl;      // .....

    return 0;
}
