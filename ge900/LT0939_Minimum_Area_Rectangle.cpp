
#include "../header/myheader.h"

class LT0939
{
public:



// tle
    int lt0939a(vector<vector<int>>& points)
    {
        unordered_map<int, vector<int>> mapx;
        unordered_map<int, vector<int>> mapy;
        for (int i = 0; i < points.size(); i++)
        {
            mapx[points[i][0]].push_back(i);
            mapy[points[i][1]].push_back(i);
        }
        int ans = INT_MAX;
        for (unordered_map<int, vector<int>>::iterator it = mapx.begin(); it != mapx.end(); it++)
        {
            int t2 = it->first;
            vector<int>& v = it->second;
            for (int i = 0; i < v.size(); i++)
            {
                vector<int>& vy = mapy[points[v[i]][1]];
                if (vy.size() == 0)
                    continue;
                for (int j = i + 1; j < v.size(); j++)
                {
                    vector<int> vy2 = mapy[points[v[j]][1]];
                    if (vy2.size() == 0)
                        continue;
                    for (int& y1 : vy)
                    {
                        if (y1 == v[i])
                            continue;
                        for (int& y2 : vy2)
                        {
                            if (y2 == v[j])
                                continue;
                            if (points[y1][0] == points[y2][0])
                            {
                                ans = min(abs((points[v[i]][1] - points[v[j]][1]) * (points[v[i]][0] - points[y1][0])), ans);
                            }
                        }
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,1},{1,3},{3,1},{3,3},{2,2}};

    vector<vector<int>> vv = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};

    LT0939 lt;

    cout<<lt.lt0939a(vv)<<endl;

    return 0;
}
