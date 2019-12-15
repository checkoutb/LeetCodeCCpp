
#include "../header/myheader.h"

LT0459
{
public:
    bool lt0459a(string s)
    {
        int arr[26] = {0};
        for (char ch : s)
            arr[ch - 'a']++;
        int min1 = 0;

    }
};

int main()
{
    string s = "abcabcacb";

    LT0459 lt;
    cout<<lt.lt0459a(s)<<endl;

    return 0;
}
