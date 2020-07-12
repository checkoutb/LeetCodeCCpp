
#include "../header/myheader.h"

class LT0917
{
public:

// D D
//            if (!isalpha(S[i]))
//                ++i;
//            else if (!isalpha(S[j]))
//                --j;
//            else
//                swap(S[i++], S[j--]);


//Runtime: 4 ms, faster than 21.20% of C++ online submissions for Reverse Only Letters.
//Memory Usage: 6.1 MB, less than 57.97% of C++ online submissions for Reverse Only Letters.
    string lt0917a(string S)
    {
        int l = 0;
        int r = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (std::isalpha(S[i]))
            {
                l = i;
                break;
            }
        }
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (isalpha(S[i]))
            {
                r = i;
                break;
            }
        }
        while (l < r)
        {
            char ch = S[l];
            S[l] = S[r];
            S[r] = ch;

            l++;
            r--;
            while (l < S.size())
            {
                if (isalpha(S[l]))
                {
                    break;
                }
                l++;
            }
            while (r >= 0)
            {
                if (isalpha(S[r]))
                {
                    break;
                }
                r--;
            }
        }
        return S;
    }

};

int main()
{

    string s = "a-bC-dEf-ghIj";

    LT0917 lt;

    cout<<lt.lt0917a(s)<<endl;

    return 0;
}
