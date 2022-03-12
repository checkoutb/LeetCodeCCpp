
#include "../header/myheader.h"

class LT2160
{
public:

// D D

//        string s = to_string(num);
//        sort(s.begin(), s.end());
//        int res = (s[0] - '0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';


//    auto s = to_string(num);
//    nth_element(begin(s), begin(s) + 1, end(s));
//    return (s[0] -'0' + s[1] - '0') * 10 + s[2] - '0' + s[3] - '0';


//Runtime: 4 ms, faster than 22.93% of C++ online submissions for Minimum Sum of Four Digit Number After Splitting Digits.
//Memory Usage: 5.8 MB, less than 99.84% of C++ online submissions for Minimum Sum of Four Digit Number After Splitting Digits.
// 小的放前面  2个2位数 的和 应该 必然 <=  1+3weishu
    int lt2160a(int num)
    {
        int arr[4] = {num % 10, num / 10 % 10, num / 100 % 10, num / 1000};
        std::sort(begin(arr), end(arr));
        return arr[0] * 10 + arr[1] * 10 + arr[2] + arr[3];
    }

};

int main()
{

    LT2160 lt;


    return 0;
}
