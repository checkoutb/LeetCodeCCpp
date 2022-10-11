
#include "../header/myheader.h"

class LT2418
{
public:






//Runtime: 54 ms, faster than 76.58% of C++ online submissions for Sort the People.
//Memory Usage: 20.7 MB, less than 86.58% of C++ online submissions for Sort the People.
    vector<string> lt2418a(vector<string>& names, vector<int>& heights)
    {
        //sort(begin(names), end(names), [&](string))
        int sz1 = names.size();
        vector<pair<int, string>> vp(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            vp[i].first = heights[i];
            vp[i].second = names[i];
        }
        sort(begin(vp), end(vp));
        for (int i = 0; i < sz1; ++i)
        {
            names[sz1 - 1 - i] = vp[i].second;
        }
        return names;
    }

};

int main()
{

    LT2418 lt;


    return 0;
}
