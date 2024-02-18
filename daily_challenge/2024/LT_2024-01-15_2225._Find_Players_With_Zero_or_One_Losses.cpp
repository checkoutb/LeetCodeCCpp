
#include "../../header/myheader.h"

class LT
{
public:





// Runtime
// 619ms
// Beats30.65%of users with C++
// Memory
// 173.29MB
// Beats50.63%of users with C++
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {

        std::set<int> win;
        std::map<int, int> lst;

        for (auto& vi : matches)
        {
            win.insert(vi[0]);
            ++lst[vi[1]];
        }

        std::vector<int> vfst;
        std::vector<int> vsnd;

        for (auto& p : lst)
        {
            if (p.second == 1)
            {
                vsnd.push_back(p.first);
            }
        }

        for (int i : win)
        {
            if (lst.find(i) == lst.end())
            {
                vfst.push_back(i);
            }
        }

        return {vfst, vsnd};
    }

};

int main()
{

    LT lt;


    return 0;
}
