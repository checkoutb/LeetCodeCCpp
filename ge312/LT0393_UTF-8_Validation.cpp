
#include "../header/myheader.h"

class LT0393
{
public:


// details
//        int conts = 0;
//        for(int i = 0; i < data.size(); i++) {
//            int val = data[i] & 0xFF;
//            if(conts) {
//                if((val & 0xC0) != 0x80) return false;
//                conts--;
//                continue;
//            }
//
//            if(val >= 0xF0 && val < 0xF8) conts = 3;
//            else if(val >= 0xE0 && val < 0xF0) conts = 2;
//            else if(val >= 0xC0 && val < 0xE0) conts = 1;
//            else if(val >= 0x80) return false;
//        }
//        cout << conts << endl;
//        return !conts;
// 0x。。。


// discuss
//        int count = 0;
//        for (auto c : data) {
//            if (count == 0) {
//                if ((c >> 5) == 0b110) count = 1;
//                else if ((c >> 4) == 0b1110) count = 2;
//                else if ((c >> 3) == 0b11110) count = 3;
//                else if ((c >> 7)) return false;
//            } else {
//                if ((c >> 6) != 0b10) return false;
//                count--;
//            }
//        }
//        return count == 0;
// 0b。。。




//Runtime: 12 ms, faster than 95.92% of C++ online submissions for UTF-8 Validation.
//Memory Usage: 9.6 MB, less than 34.04% of C++ online submissions for UTF-8 Validation.


    // 如果能一个byte表示的，那么就转成0开头的一个byte的utf-8... 就是 ascii 码
    // 如果需要n个byte表示，那么 前n个bit全是1，n+1 bit是0.，后面的n-1个byte 的前2位bit是 10.
    // data中一个int 就是 byte的值。 所以肯定255之内。

    // 是每个int 转 010101 数组，还是 &1100000, &1110000


    bool lt0393a(vector<int>& data)
    {
        int a1 = 128;
        int a11 = 128 + 64;
        int a111 = 128 + 64 + 32;
        int a1111 = 128 + 64 + 32 + 16;
        int a11111 = a1111 + 8;

        int t1 = 0;
        int t2 = 0;
        for (int i = 0, sz1 = data.size(); i < sz1; i++)
        {
            t1 = data[i];

            #ifdef __test
            cout<<t1<<", "<<t2<<endl;
            #endif // __test

            if (t1 < a1)
            {
                if (t2 != 0)
                {
                    return false;
                }
            }
            else
            {
                if (t1 >= a1 && t1 < a11)
                {
                    t2--;
                    if (t2 < 0)
                    {
                        return false;
                    }
                }
                else
                {
                    if (t2 != 0)
                        return false;
                    if (t1 >= a11 && t1 < a111)
                    {
                        t2 = 1;
                    }
                    else if (t1 >= a111 && t1 < a1111)
                    {
                        t2 = 2;
                    }
                    else if (t1 >= a1111 && t1 < a11111)
                    {
                        t2 = 3;
                    }
                    else if (t1 >= a11111)
                    {
                        return false;
                    }
                }
            }
        }

        return t2 == 0;
    }
};

int main()
{
    vector<int> v = {240,162,138,147};

    LT0393 lt;
    cout<<lt.lt0393a(v)<<endl;

    return 0;
}
