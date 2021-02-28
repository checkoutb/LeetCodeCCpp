
#include "../header/myheader.h"

class LT1702
{
public:

// D D

//We don't need touch the starting 1s, they are already good.
//
//For the rest part,
//we continually take operation 2,
//making the string like 00...00011...11
//
//Then we continually take operation 1,
//making the string like 11...11011...11.
//        int ones = 0, zeros = 0, n = s.length();
//        for (auto& c : s) {
//            if (c == '0')
//                zeros++;
//            else if (zeros == 0)
//                ones++;               // 前缀1
//            c = '1';
//        }
//        if (ones < n)
//            s[ones + zeros - 1] = '0';
//        return s;
// 前缀1 + 所有0 + 剩下的1。
// 前缀1 + 11...1 + 0 + 剩下的1




//Runtime: 160 ms, faster than 90.12% of C++ online submissions for Maximum Binary String After Change.
//Memory Usage: 40.4 MB, less than 96.35% of C++ online submissions for Maximum Binary String After Change.
// 010  001 101
// 000110  000101  000011 001011  010011  011011  010111
// 000110
// 100110
// 110110
// 110101
// 110011
// 111011
//    --- 000110  000101  000011  100011 110011 111011
// 把0 放前面，然后从前往后
// 1110
// 0101 0011 1011
// 01101 01011  00111 10111
// 111011
// 101011  100111 110111 ,no   101011 100111 010111  001111 101111...
// 000110  000101  000011 001011  000111
// 如果前面全0，就从前面开始， 如果不是全0，就继续往前。
// 01001 00101 00011 10011 11011
//       01101 01011 00111 10111
// 直接把所有的1放最后，然后 前面 11110
// bu,  1101011  1100111 1110111
// 应该是 往前走， 直到 前面没有0。
// 000110 000101 000011 001011
// 0110 0011 1011
// 00101  00011 11011  10101 10011 11011
// 000110 000101 000011
// 10101011 10100111 10001111 00011111 11011111
    string lt1702a(string binary)
    {
        int cnt1 = 0;
        for (char ch : binary)
            cnt1 += (ch == '1');
        int cnt0 = binary.size() - cnt1;
        if (cnt0 <= 1)
            return binary;
//cout<<cnt1<<", "<<cnt0<<endl;
        for (int i = 0; i < binary.size(); ++i)
        {
            if (binary[i] == '0')
            {
                if (cnt0 > 1)
                {
//                    cout<<cnt0<<", "<<i<<endl;
                    cnt0--;
                    binary[i] = '1';
                    binary[i + 1] = '0';                // .
                    if (cnt0 == 1)
                    {
                        binary[i + 1] = '0';
                        for (int j = i + 2; j < binary.size(); ++j)
                            binary[j] = '1';
                    }
                }
                else
                {
//                cout<<"asd "<<i<<endl;
//                    binary[i] = '0';
//                    for (int j = i + 1; j < binary.size(); ++j)
//                        binary[j] = '1';
//                    break;
                }
            }
//            cout<<binary<<endl;
            #ifdef __test
            cout<<binary<<" . ."<<cnt0<<endl;
            #endif // __test
        }
        return binary;

//        int cnt1 = 0;
//        for (char ch : binary)
//            cnt1 += (ch == '1');
//        if (cnt1 == binary.size())
//            return binary;
//
//        string ans(cnt1, "1");
//        ans = "0" + ans;
//        if (ans.size() == binary.size())
//            return ans;
//
//        ans = string(binary.size() - ans.size()) + ans;


//        int cnt0 = 0;
//        for (char ch : binary)
//            cnt0 += (ch == '0');
//        for (int i = binary.size() - 1; i > 0; --i)
//        {
//
//        }
    }

};

int main()
{
    string s = "000110";
//    string s = "01";
//    string s = "01111001100000110010";      // "11111111110111111111"



    LT1702 lt;

    cout<<lt.lt1702a(s)<<endl;

    return 0;
}
