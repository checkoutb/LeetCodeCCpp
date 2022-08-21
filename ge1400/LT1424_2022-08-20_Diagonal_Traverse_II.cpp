
#include "../header/myheader.h"

class LT1424
{
public:

    // D D

    //queue<pair<int, int>> q;
    //q.push({ 0,0 }); // first row, first cell

    //// BFS
    //while (!q.empty()) {
    //    pair<int, int> p = q.front();
    //    q.pop();
    //    ans.push_back(nums[p.first][p.second]);

    //    // insert the element below, if in first column
    //    if (p.second == 0 && p.first + 1 < m) q.push({ p.first + 1, p.second });

    //    // insert the right neighbour, if exists
    //    if (p.second + 1 < nums[p.first].size())
    //        q.push({ p.first, p.second + 1 });
    //}




    //vector<vector<int>> v1;
    //int k = 0;
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < nums[i].size(); j++) {
    //        if (i + j >= v1.size()) {
    //            v1.push_back({});
    //        }
    //        v1[j + i].push_back(nums[i][j]);
    //    }
    //}
    //




//Runtime: 339 ms, faster than 81.98 % of C++ online submissions for Diagonal Traverse II.
//Memory Usage : 75.1 MB, less than 86.22 % of C++ online submissions for Diagonal Traverse II.
    // related topic: priority queue
    vector<int> lt1424b(vector<vector<int>>& nums)
    {
        priority_queue<pair<long long, int>> priq;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < nums[i].size(); ++j)
            {
                long long k = -1LL * (i + j) * INT_MAX + i;
                priq.push({ k, nums[i][j] });
            }
        }
        vector<int> ans(priq.size());
        for (int i = 0; i < ans.size(); ++i)
        {
            ans[i] = priq.top().second;
            priq.pop();
        }
        return ans;
    }


    //tle
    vector<int> lt1424a(vector<vector<int>>& nums)
    {
        int sz1 = nums.size();
        int sz2 = nums[nums.size() - 1].size();
        int szs = 0;
        for (int i = 0; i < sz1; ++i)
        {
            szs += nums[i].size();
            //sz2 = max(sz2, nums[i].size() - )
        }
        vector<int> ans(szs);
        int x = 0, y = 0;
        for (int i = 0; i < szs; ++i)
        {
            while (y >= nums[x].size())
            {
                x--;
                y++;
            }
            ans[i] = nums[x][y];
            x--;
            y++;
            if (x < 0)
            {
                x = (x + y + 1);
                y = 0;
            }
            else
            {
                while (x >= 0 && y >= nums[x].size())
                {
                    x--;
                    y++;
                }
                if (x < 0)
                {
                    x = (x + y + 1);
                    y = 0;
                }
            }
            if (x >= sz1)
            {
                y = x - sz1 + 1;
                x = sz1 - 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT1424 lt;

    //myvvi vv = { {1,2,3},{4,5,6},{7,8,9} };
    //myvvi vv = { {1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16} };
    myvvi vv = { {14,12,19,16,9},{13,14,15,8,11},{11,13,1} };

    myvi v = lt.lt1424b(vv);

    showVectorInt(v);

    return 0;
}
