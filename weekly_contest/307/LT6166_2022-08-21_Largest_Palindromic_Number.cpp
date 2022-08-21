
#include "../../header/myheader.h"

class LT6166
{
public:



    // AC
    string largestPalindromic(string num)
    {
        int arr[10] = { 0 };
        int cntnot0 = 0;
        for (char ch : num)
        {
            arr[ch - '0']++;
            if (ch != '0')
                cntnot0++;
        }
        vector<char> vc;

        string ans;
        char ch = 'A';      // max single
        for (int i = 9; i > 0; --i)
        {
            if (arr[i] > 0)
            {
                for (int j = 0; j < arr[i] / 2; ++j)
                {
                    ans.push_back(char(i + '0'));
                }
                if (arr[i] % 2 && ch == 'A')
                    ch = char(i + '0');
            }
        }

        if (!ans.empty())
        {
            for (int j = 0; j < arr[0] / 2; ++j)
            {
                ans.push_back('0');
            }
            if (arr[0] % 2 && ch == 'A')
                ch = '0';
        }

        string rev(ans);
        reverse(begin(rev), end(rev));

        if (ch != 'A')
            ans.push_back(ch);
        ans += rev;

        if (ans.empty())
            ans = "0";

        return ans;
    }

};

int main()
{

    LT6166 lt;

    //string s = "444947137";
    //string s = "000000000098";

    //string s = "00000";

    string s = "00011";

    cout << lt.largestPalindromic(s) << endl;

    return 0;
}
