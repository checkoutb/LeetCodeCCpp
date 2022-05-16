
#include "../header/myheader.h"

class LT2275
{
public:

// D D

//        for (int i = 1; i <= 10000000; i <<= 1) {
//            cur = 0;
//            for (int& a : A)
//                if (a & i)
//                    cur++;
//            res = max(res, cur);
//        }


//    int res = 0, max_e = *max_element(begin(cs), end(cs));
//    for (int b = 1; b <= max_e; b <<= 1) {
//        int cnt = 0;
//        for (auto n : cs)
//            cnt += (n & b) > 0;
//        res = max(res, cnt);
//    }


//    int cnt[24] = {};
//    for (auto n : cs)
//        transform(begin(cnt), end(cnt), begin(bitset<24>(n).to_string()), begin(cnt), [](int s, char ch){ return s + (ch == '1'); });
//    return *max_element(begin(cnt), end(cnt));



//Runtime: 135 ms, faster than 66.67% of C++ online submissions for Largest Combination With Bitwise AND Greater Than Zero.
//Memory Usage: 57.5 MB, less than 33.33% of C++ online submissions for Largest Combination With Bitwise AND Greater Than Zero.
// bit. 32bit.. group by bit
    int lt2275a(vector<int>& candidates)
    {
        int arr[32] = {0};
        for (int num : candidates)
        {
            for (int i = 0; num > 0; ++i)
            {
                if (num % 2)
                {
                    arr[i]++;
                }
                num >>= 1;
            }
        }
        return *max_element(begin(arr), end(arr));
    }

};

int main()
{

    LT2275 lt;


    return 0;
}
