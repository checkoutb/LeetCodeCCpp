
#include "../header/myheader.h"

class LT2363
{
public:

    // D D



//Runtime: 50 ms, faster than 100.00 % of C++ online submissions for Merge Similar Items.
//Memory Usage : 16.8 MB, less than 60.00 % of C++ online submissions for Merge Similar Items.
    vector<vector<int>> lt2363a(vector<vector<int>>& items1, vector<vector<int>>& items2)
    {
        map<int, int> map2;
        for (vector<int>& vi : items1)
            map2[vi[0]] += vi[1];
        for (vector<int>& vi : items2)
            map2[vi[0]] += vi[1];
        vector<vector<int>> ans;
        for (auto& p : map2)
            ans.push_back({p.first, p.second});
        return ans;
    }

};

int main()
{

    LT2363 lt;


    return 0;
}
