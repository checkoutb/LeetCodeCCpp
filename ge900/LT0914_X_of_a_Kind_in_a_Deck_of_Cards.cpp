
#include "../header/myheader.h"

class LT0914
{
public:

// D D
//cout<<std::__gcd(12, 21)<<endl;

//        int res = 0;
//        for (int i : deck) count[i]++;
//        for (auto i : count) res = __gcd(i.second, res);



//Runtime: 56 ms, faster than 19.27% of C++ online submissions for X of a Kind in a Deck of Cards.
//Memory Usage: 17.7 MB, less than 32.42% of C++ online submissions for X of a Kind in a Deck of Cards.
    bool lt0914a(vector<int>& deck)
    {
        unordered_map<int, int> map2;
        for (int i : deck)
        {
            map2[i]++;
        }
        int mincnt = INT_MAX;
        for (auto& p : map2)
        {
            mincnt = min(mincnt, p.second);
        }
        if (mincnt < 2)
            return false;

        for (auto& p : map2)
        {
            if (p.second % mincnt != 0)
            {
                mincnt = gcda1(p.second, mincnt);
                if (mincnt < 2)
                    return false;
            }
        }
        return true;
    }

    inline int gcda1(int a, int b)
    {
        return b == 0 ? a : gcda1(b, a % b);
    }

};

int main()
{

    cout<<std::__gcd(28, 21)<<endl;

    vector<int> v = {1,1,1,1,2,2,2,2,2,2};

    LT0914 lt;

    cout<<lt.lt0914a(v)<<endl;

    return 0;
}
