
#include "../header/myheader.h"

class LT0078
{
public:

// D D


//    void backtrack(vector<int> cur, vector<int>& nums, int i) {
//        res.push_back(cur);
//        for(int j = i; j < nums.size(); ++j) {
//            cur.push_back(nums[j]);
//            backtrack(cur, nums, j+1);
//            cur.pop_back();
//        }
//    }


//    for (int i = 0; i < nums.size(); i++)
//        for (int step = 1 << i, start = 0; start < num_subset; start += 2 * step)
//            for (int j = start; j < start + step; j++)
//                res[j].push_back(nums[i]);



//Runtime: 4 ms, faster than 60.40% of C++ online submissions for Subsets.
//Memory Usage: 11.5 MB, less than 13.39% of C++ online submissions for Subsets.
    vector<vector<int>> lt0078a(vector<int>& nums)
    {
        vector<vector<int>> ans;
        vector<int> path;
        dfsa1(nums, 0, ans, path);
        return ans;
    }

    void dfsa1(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& path)
    {
        if (idx >= nums.size())
        {
            ans.push_back(path);
            return;
        }
        dfsa1(nums, idx + 1, ans, path);
        path.push_back(nums[idx]);
        dfsa1(nums, idx + 1, ans, path);
        path.pop_back();
    }

};

int main()
{
//    myvi v = {1,2,3};
    myvi v = {0};

    LT0078 lt;

    myvvi vv = lt.lt0078a(v);

    for (myvi& vi : vv)
    {
        for (int i : vi)
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }

    return 0;
}
