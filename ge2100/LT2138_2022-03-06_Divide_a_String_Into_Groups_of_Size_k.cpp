
#include "../header/myheader.h"

class LT2138
{
public:

// D D

//    vector<string> res((s.size() + k - 1) / k, string(k, fill));
//    for (int i = 0; i < s.size(); ++i)
//        res[i / k][i % k] = s[i];
//    return res;


//Runtime: 3 ms, faster than 69.26% of C++ online submissions for Divide a String Into Groups of Size k.
//Memory Usage: 7 MB, less than 21.17% of C++ online submissions for Divide a String Into Groups of Size k.
    vector<string> lt2138a(string s, int k, char fill)
    {
        vector<string> ans;

        for (int i = 0; i < s.size(); i += k)
        {
            if (i + k < s.size())
            {
                ans.push_back(s.substr(i, k));
            }
            else
            {
                string s2 = s.substr(i);
                while (s2.size() < k)
                    s2.push_back(fill);
                ans.push_back(s2);
            }
        }

        return ans;
    }

};

int main()
{

    LT2138 lt;


    return 0;
}
