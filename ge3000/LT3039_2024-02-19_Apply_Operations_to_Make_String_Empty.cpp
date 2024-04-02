
#include "../header/myheader.h"

class LT3039
{
public:



// Runtime
// 99ms
// Beats25.00%of users with C++
// Memory
// 31.57MB
// Beats25.00%of users with C++


    string lastNonEmptyString(string s)
    {
        int cnt[123] {0};
        int lst[123] {0};

        // for (char ch : s)
        for (int i = 0; i < s.size(); ++i)
        {
            ++cnt[static_cast<int>(s[i])];
            lst[static_cast<int>(s[i])] = i;
        }
        int mxcnt = 0;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (cnt[i] > mxcnt)
                mxcnt = cnt[i];
        }

        string ans;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (cnt[i] == mxcnt)
                ans.push_back(char(i));
        }

        std::sort(std::begin(ans), end(ans), [&lst](const char& c1, const char& c2){
            return lst[int(c1)] < lst[int(c2)];
        });
        return ans;
    }

};

int main()
{

    LT3039 lt;


    return 0;
}
