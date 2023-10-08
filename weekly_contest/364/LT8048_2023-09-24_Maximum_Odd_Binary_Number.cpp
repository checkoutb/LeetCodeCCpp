
#include "../../header/myheader.h"

class LT8048
{
public:



// AC
    string maximumOddBinaryNumber(string s) {
        int cnt1 = 0;
        for (char ch : s)
        {
            if (ch == '1')
                ++cnt1;
        }
        string ans(s.size(), '0');
        --cnt1;
        ans[ans.size() - 1] = '1';
        for (int i = 0; i < ans.size() && cnt1 > 0; ++i, --cnt1)
            ans[i] = '1';

        return ans;
    }

};

int main()
{

    LT8048 lt;


    return 0;
}
