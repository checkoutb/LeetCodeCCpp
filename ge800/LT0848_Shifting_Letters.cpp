
#include "../header/myheader.h"

class LT0848
{
public:


// D D
// 从后往前，这样就一遍ok。


//Runtime: 76 ms, faster than 64.87% of C++ online submissions for Shifting Letters.
//Memory Usage: 20.2 MB, less than 30.83% of C++ online submissions for Shifting Letters.
    string lt0848a(string S, vector<int>& shifts)
    {
        int sz1 = shifts.size();
        shifts[shifts.size() - 1] = shifts[shifts.size() - 1] % 26;

        for (int i = shifts.size() - 2; i >= 0; i--)
        {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }

        for (int i = 0; i < sz1; i++)
        {
            S[i] = converta1(S[i], shifts[i]);
        }
        return S;
    }

    char converta1(char ch, int offset)
    {
        if (ch + offset > 'z')
        {
            return ch + offset - 26;
        }
        return ch + offset;
    }

};

int main()
{

    string s = "abc";
    vector<int> shifts = {3,5,9};

    LT0848 lt;

    cout<<lt.lt0848a(s, shifts)<<endl;
    return 0;
}
