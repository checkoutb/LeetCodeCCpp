
#include "../header/myheader.h"

class LT2914
{
public:



//     Runtime12 ms
// Beats
// 92.63%
// Memory10.3 MB
// Beats
// 93.7%
    int minChanges(string s)
    {
        size_t sz1 = s.size();
        int ans = 0;
        for (size_t i = 1; i < sz1; i += 2)
        {
            ans += s[i] != s[i - 1];
        }
        return ans;
    }

};

int main()
{

    LT2914 lt;


    return 0;
}
