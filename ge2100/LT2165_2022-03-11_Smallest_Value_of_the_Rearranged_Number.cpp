
#include "../header/myheader.h"

class LT2165
{
public:

// D D

//        string s = to_string(abs(num));
//        sort(s.begin(), s.end());
//        if (num <= 0) {
//            return -1 * stoll(string(s.rbegin(), s.rend()));
//        }
//        int i = s.find_first_not_of('0');
//        swap(s[0], s[i]);
//        return stoll(s);


//    auto s = to_string(abs(num));
//    sort(begin(s), end(s), [&](int a, int b){ return num < 0 ? a > b : a < b; });
//    if (num > 0)
//        swap(s[0], s[s.find_first_not_of('0')]);
//    return stoll(s) * (num < 0 ? -1 : 1);


//Runtime: 3 ms, faster than 55.58% of C++ online submissions for Smallest Value of the Rearranged Number.
//Memory Usage: 6.1 MB, less than 65.31% of C++ online submissions for Smallest Value of the Rearranged Number.
    long long lt2165a(long long num)
    {
        if (num >= -9 && num <= 19)
            return num;
        bool isNeg = num < 0;
        num = abs(num);
        vector<int> vi;
        while (num > 0)
        {
            vi.push_back(num % 10);
            num /= 10;
        }
        sort(begin(vi), end(vi));
        if (isNeg)
        {
            std::reverse(begin(vi), end(vi));
        }
        long long ans = 0;
        if (vi[0] == 0)
        {
            for (int i = 1; i < vi.size(); ++i)
            {
                if (vi[i] != 0)
                {
                    ans = vi[i];
                    vi[i] = 0;
                    break;
                }
            }
        }
        else
        {
            ans = vi[0];
        }
        for (int i = 1; i < vi.size(); ++i)
        {
            ans *= 10;
            ans += vi[i];
        }
        ans *= (isNeg ? -1 : 1);
        return ans;
    }

};

int main()
{

    LT2165 lt;


    return 0;
}
