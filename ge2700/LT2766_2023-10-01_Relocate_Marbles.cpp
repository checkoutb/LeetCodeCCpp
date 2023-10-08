
#include "../header/myheader.h"

class LT2766
{
public:



//Runtime276 ms
//Beats
//58.66%
//Memory179.4 MB
//Beats
//58.66%
    vector<int> relocateMarbles(
        vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {

        map<int, int> map2;
        for (int i : nums)
            map2[i] = 1;
        int sz1 = moveFrom.size();
        for (int i = 0; i < sz1; ++i)
        {
            if (moveTo[i] == moveFrom[i])
                continue;
            map2[moveTo[i]] = 1;
            map2[moveFrom[i]] = 0;          // from then to.
        }
        vector<int> ans;
        for (auto& [k, v] : map2)
        {
            if (v == 0)
                continue;
            ans.push_back(k);
        }
        return ans;
    }

};

int main()
{

    LT2766 lt;


    return 0;
}
