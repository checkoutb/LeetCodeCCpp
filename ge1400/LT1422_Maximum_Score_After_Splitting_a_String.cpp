
#include "../header/myheader.h"

class LT1422
{
public:

// D D

//  int res = 0, zero = 0;
//	int one = count(s.begin(), s.end(), '1');
//	for (auto i = 0; i < s.length() - 1; i++)
//	{
//		if (s[i] == '0') zero++;
//		else one--;
//		res = max(res, zero + one);
//	}
//	return res;
// just count...


//	int zeros = 0, ones = 0, max = Integer.MIN_VALUE;
//	for(int i=0;i<s.length();i++) {
//		if(s.charAt(i) == '0') zeros++; else ones++;
//		if(i != s.length()-1) max = Math.max(zeros - ones, max);
//	}
//	return max + ones;
//Result = Max of (ZerosOnLeft + OnesOnRight)
//= Max of (ZerosOnLeft + (TotalOnes - OnesOnLeft))
//= Max of (ZerosOnLeft - OnesOnLeft) + TotalOnes (as TotalOnes is constant)
// .!.!


//Runtime: 4 ms, faster than 32.91% of C++ online submissions for Maximum Score After Splitting a String.
//Memory Usage: 6.5 MB, less than 66.45% of C++ online submissions for Maximum Score After Splitting a String.
    int lt1422a(string s)
    {
        int cnt1 = std::count_if(begin(s), end(s), [](const char& ch){ return ch == '1'; });
        int ans = 0;
        int cnt0 = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            char ch = s[i];
            if (ch == '0')
                cnt0++;
            else
                cnt1--;
            ans = max(ans, cnt0 + cnt1);
        }
        return ans;
    }

};

int main()
{
    string s = "00";

    LT1422 lt;

    cout<<lt.lt1422a(s);

    return 0;
}
