
#include "../header/myheader.h"

class LT2309
{
public:

    // D D



//Runtime: 3 ms, faster than 92.24 % of C++ online submissions for Greatest English Letter in Upperand Lower Case.
//Memory Usage : 6.7 MB, less than 76.75 % of C++ online submissions for Greatest English Letter in Upperand Lower Case.
    string lt2309a(string s)
    {
        short arr[26] = { 0 };
        for (char ch : s)
        {
            if (std::isupper(ch))
            {
                arr[ch - 'A'] |= (1 << 1);
            }
            else
            {
                arr[ch - 'a'] |= 1;
            }
        }
#ifdef __test
        for (short i : arr)
            cout << i << ", ";
        cout << endl;
#endif
        for (int i = 25; i >= 0; --i)
        {
            if (arr[i] == 3)
            {
                return string(1, i + 'A');
            }
        }
        return "";
    }

};

int main()
{

    LT2309 lt;

    string s = "lEeTcOdE";

    cout << lt.lt2309a(s) << endl;

    return 0;
}
