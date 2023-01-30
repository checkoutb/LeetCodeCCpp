
#include "../header/myheader.h"

class LT2502
{
public:



};





//Runtime138 ms
//Beats
//89.60 %
//Memory30.6 MB
//Beats
//94.31 %
class Allocator {

    //unordered_map<int, vector<int>> map2;
    //vector<pair<int, int>> vp;
    vector<tuple<int, int, int>> vt;
    int sz1;

public:
    Allocator(int n) {
        sz1 = n;
    }

    int allocate(int size, int mID) {
        int lsten = 0;
        int i = 0;
        for (; i < vt.size(); ++i)
        {
            //if (vp[i].first - lsten >= size)
            if (std::get<0>(vt[i]) - lsten >= size)
            {
                break;
            }
            //lsten = vp[i].second + 1;           // [st, en]
            lsten = std::get<1>(vt[i]) + 1;
        }
        int ans = -1;
        if (i < vt.size())
        {
            vt.insert(begin(vt) + i, std::make_tuple(lsten, lsten + size - 1, mID));
            ans = lsten;
        }
        else
        {
            if (sz1 - lsten >= size)
            {
                vt.push_back(std::make_tuple(lsten, lsten + size - 1, mID));
                ans = lsten;
            }
        }

        //if (ans != -1)
        //    sort(begin(vp), end(vp));

        return ans;
    }

    int free(int mID) {
        int ans = 0;
        for (vector<tuple<int, int, int>>::iterator it = begin(vt); it != end(vt); )
        {
            if (std::get<2>(*it) == mID)
            {
                ans += std::get<1>(*it) - std::get<0>(*it) + 1;
                it = vt.erase(it);
            }
            else
            {
                it++;
            }
        }
        return ans;
    }
};



int main()
{

    LT2502 lt;


    return 0;
}
