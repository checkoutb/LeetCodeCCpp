
#include "../header/myheader.h"

class LT0541
{
public:



//        for(int i = 0; i < s.size(); i += 2*k)
//        {
//            int start = i, end = min(i + k -1, int(s.size()) - 1);
//            while(start < end)
//                swap(s[start++], s[end--]);
//        }

//        for (int i = 0; i < s.size(); i += 2 * k)
//            reverse(s.begin() + i, min(s.begin() + i + k, s.end()));



//Runtime: 8 ms, faster than 66.47% of C++ online submissions for Reverse String II.
//Memory Usage: 10.1 MB, less than 10.00% of C++ online submissions for Reverse String II.

    string lt0541a(string s, int k)
    {
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (i / k % 2 == 0)
            {
                if (i / k * k + k > s.size())
                {
                    ans += s[s.size() - i - 1 + i / k * k];
                }
                else
                {
                    ans += s[i / k * k + k - i % k - 1];
                }
            }
            else
            {
                ans += s[i];
            }
        }

        return ans;
    }
};

int main()
{
//    string s = "abcdefg";
//    int k = 2;

//    string s = "a";
//    int k = 2;

//    string s = "abcdefg";
//    int k = 8;

    string s = "abcdefg";
    int k = 3;


    LT0541 lt;

    cout<<lt.lt0541a(s, k)<<endl;

    return 0;
}
