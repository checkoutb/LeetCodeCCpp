
#include "../header/myheader.h"

class LT0709
{
public:

// details
//str[i]+=32;

// discuss
//    for (char& c : str) {
//        if (c >= 'A' && c <= 'Z') c += 32;
//    }


//Runtime: 4 ms, faster than 50.53% of C++ online submissions for To Lower Case.
//Memory Usage: 8.3 MB, less than 33.33% of C++ online submissions for To Lower Case.
    string lt0709b(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] <= 'Z' && str[i] >= 'A')
            {
                str[i] = (str[i] - 'A' + 'a');
            }
        }
        return str;
    }


//Runtime: 4 ms, faster than 50.53% of C++ online submissions for To Lower Case.
//Memory Usage: 8.4 MB, less than 15.38% of C++ online submissions for To Lower Case.

    string lt0709a(string str)
    {
        string ans = "";
        for (char ch : str)
        {
            if (ch <= 'Z' && ch >= 'A')
            {
                ans += (ch - 'A' + 'a');
            }
            else
            {
                ans += ch;
            }
        }
        return ans;
    }

};

int main()
{

    LT0709 lt;

    cout<<lt.lt0709b("HedF1we")<<endl;

    string str = "ABCdefG";
    str[0] = '4';
    cout<<str<<endl;

    return 0;
}
