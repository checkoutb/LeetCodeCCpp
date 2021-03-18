
#include "../header/myheader.h"

class LT1773
{
public:

// D D

//    int idx = key == "type" ? 0 : key == "color" ? 1 : 2, res = 0;
//    return count_if(begin(items), end(items), [&](const auto &i) { return i[idx] == val; });



//Runtime: 72 ms, faster than 100.00% of C++ online submissions for Count Items Matching a Rule.
//Memory Usage: 30.8 MB, less than 100.00% of C++ online submissions for Count Items Matching a Rule.
    int lt1773a(vector<vector<string>>& items, string ruleKey, string ruleValue)
    {
        int idx = -1;
        switch (ruleKey[0])
        {
        case 't':
            idx = 0;
            break;
        case 'c':
            idx = 1;
            break;
        case 'n':
            idx = 2;
            break;
        }
        int ans = 0;
        for (vector<string>& vs : items)
        {
            if (vs[idx] == ruleValue)
                ans++;
        }
        return ans;
    }

};

int main()
{

    LT1773 lt;


    return 0;
}
