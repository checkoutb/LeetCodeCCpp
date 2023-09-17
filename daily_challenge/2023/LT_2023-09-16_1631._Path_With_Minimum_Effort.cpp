
#include "../../header/myheader.h"

class LT
{
public:

    // priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> gq;


    //Runtime360 ms
    //    Beats
    //    13.16 %
    //    Memory42 MB
    //    Beats
    //    17.47 %
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int sz1 = heights.size();
        int sz2 = heights[0].size();

        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        vvi[0][0] = 0;
        int t2 = 0;
        //priority_queue<array<int, 3>, vector<array<int, 3>>, std::greater<>()> priq;     // [effort, row, col]
        //priority_queue<array<int, 3>> priq;
        priority_queue<vector<int>, vector<vector<int>>, std::greater<>> priq;
        priq.push({ 0, 0, 0 });
        const int arr[] = { 1,0,-1,0,1 };
        while (!priq.empty())
        {
            //auto [eff, row, col] = priq.top();
            vector<int> vi = priq.top();
            int eff = vi[0];
            int row = vi[1];
            int col = vi[2];
            priq.pop();
            if (row == sz1 - 1 && col == sz2 - 1)
                break;
            for (int i = 0; i < 4; ++i)
            {
                if (row + arr[i] < 0 || row + arr[i] == sz1 || col + arr[i + 1] < 0 || col + arr[i + 1] == sz2)
                    continue;
                if (max(eff, std::abs(heights[row][col] - heights[row + arr[i]][col + arr[i + 1]])) < vvi[row + arr[i]][col + arr[i + 1]])
                {
                    vvi[row + arr[i]][col + arr[i + 1]] = max(eff, std::abs(heights[row][col] - heights[row + arr[i]][col + arr[i + 1]]));
                    priq.push({ vvi[row + arr[i]][col + arr[i + 1]], row + arr[i], col + arr[i + 1] });
                }
            }
        }
        return vvi[sz1 - 1][sz2 - 1];
    }

};

int main()
{

    LT lt;

    myvvi vv = { {1, 2, 2},{3, 8, 2},{5, 3, 5} };

    cout << lt.minimumEffortPath(vv) << endl;

    return 0;
}
