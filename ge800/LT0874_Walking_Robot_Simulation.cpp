
#include "../header/myheader.h"

class LT0874
{
public:

// D D

// baxian guohai...



//Runtime: 276 ms, faster than 63.17% of C++ online submissions for Walking Robot Simulation.
//Memory Usage: 45.6 MB, less than 13.62% of C++ online submissions for Walking Robot Simulation.
    int lt0874a(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        map<int, vector<int>> map2;
        map<int, vector<int>> map3;
        for (int i = 0; i < obstacles.size(); i++)
        {
            map2[obstacles[i][0]].push_back(obstacles[i][1]);
            map3[obstacles[i][1]].push_back(obstacles[i][0]);
        }
        for (auto& p : map2)
        {
            std::sort(begin(p.second), end(p.second));
        }
        for (auto& p : map3)
        {
            std::sort(begin(p.second), end(p.second));
        }
        int ans = 0;
        int dir[][2] = {{1, 0},{0, -1},{-1, 0},{0, 1}};
        int di = 3;
        int x = 0;
        int y = 0;
        for (int i = 0; i < commands.size(); i++)
        {
            int t2 = commands[i];
            if (t2 < 0)
            {
                if (t2 == -1)
                {
                    di = (di + 1) % 4;
                }
                else
                {
                    di = (di + 3) % 4;
                }
            }
            else
            {
                if (di % 2 == 1)
                {
                    if (map2.find(x) != map2.end())
                    {
                        vector<int>& v = map2[x];
                        vector<int>::iterator it = std::lower_bound(begin(v), end(v), y);
                        if (di == 1)
                        {
                            if (it != v.begin())
                            {
                                it--;
                                int t3 = *(it);
                                y = (y + t2 * dir[di][1]) > t3 ? y + t2 * dir[di][1] : t3 + 1;
                            }
                            else
                            {
                                y += t2 * dir[di][1];
                            }
                        }
                        else
                        {
                            while (it != v.end() && *it == y)           // 0,0...
                                it++;
                            if (it != v.end())
                            {
                                int t3 = *it;
                                y = (y + t2 * dir[di][1]) < t3 ? y + t2 * dir[di][1] : t3 - 1;
                            }
                            else
                            {
                                y += t2 * dir[di][1];
                            }
                        }
                    }
                    else
                    {
                        x += t2 * dir[di][0];
                        y += t2 * dir[di][1];
                    }
                }
                else
                {
                    if (map3.find(y) != map3.end())
                    {
                        vector<int>& v = map3[y];
                        vector<int>::iterator it = std::lower_bound(begin(v), end(v), x);
                        if (di == 0)
                        {
                            if (it != v.end())
                            {
                                int t3 = *it;
                                x = (x + t2 * dir[di][0]) < t3 ? x + t2 * dir[di][0] : t3 - 1;
                            }
                            else
                            {
                                x += t2 * dir[di][0];
                            }
                        }
                        else
                        {
                            if (it != v.begin())
                            {
                                it--;
                                int t3 = *it;
                                x = (x + t2 * dir[di][0]) > t3 ? x + t2 * dir[di][0] : t3 + 1;
                            }
                            else
                            {
                                x += t2 * dir[di][0];
                            }
                        }
                    }
                    else
                    {
                        x += t2 * dir[di][0];
                        y += t2 * dir[di][1];
                    }
                }
                #ifdef __test
                cout<<di<<", "<<x<<", "<<y<<endl;
                #endif // __test
                ans = max(ans, x * x + y * y);
            }
        }

        return ans;
    }

};

int main()
{

//    vector<int> v1 = {4,-1,3};
//    vector<vector<int>> vv2 = {};

//    vector<int> v1 = {4,-1,4,-2,4};
//    vector<vector<int>> vv2 = {{2,4}};


//    vector<int> v1 = {7,-2,-2,7,5};
//    vector<vector<int>> vv2 = {{-3,2},{-2,1},{0,1},{-2,4},{-1,0},{-2,-3},{0,-3},{4,4},{-3,3},{2,2}};

    vector<int> v1 = {2,2,5,-1,-1};
    vector<vector<int>> vv2 = {{-3,5},{-2,5},{3,2},{5,0},{-2,0},{-1,5},{5,-3},{0,0},{-4,4},{-3,4}};



    LT0874 lt;

    cout<<lt.lt0874a(v1, vv2)<<endl;

    return 0;
}
