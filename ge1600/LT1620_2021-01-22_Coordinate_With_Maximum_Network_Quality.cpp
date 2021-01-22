
#include "../header/myheader.h"

class LT1620
{
public:






// no. error
// 感觉 最大值 出现在 塔上。
    vector<int> lt1620a(vector<vector<int>>& towers, int radius)
    {
        for (int i = 0; i < towers.size(); ++i)
        {
            if (towers[i][2] == 0)
            {
                towers.erase(towers.begin() + i);
                i--;
            }
        }
        vector<int> anss;
        int mx = 0;
        for (int i = 0; i < towers.size(); ++i)
        {
            int t2 = 0;
            int x = towers[i][0];
            int y = towers[i][1];
            for (int j = 0; j < towers.size(); ++j)
            {
                int lenx = (x - towers[j][0]);
                int leny = (y - towers[j][1]);
                int sqt = (int) std::sqrt(lenx * lenx + leny * leny);
                if (sqt > radius)
                    continue;
                t2 += (towers[j][2] / (1 + sqt));
            }
            if (t2 == mx)
            {
                anss.push_back(i);
            }
            else if (t2 > mx)
            {
                anss = {i};
                mx = t2;
//                anss.clear();
//                anss
            }
        }
//        if (anss.size() == 1)
//            return {towers[anss[0]][0], towers[anss[0]][1]};
        if (anss.empty())
            return {0, 0};
        if (anss.size() > 1)
            sort(begin(anss), end(anss), [&towers](const int& a, const int& b) { return towers[a][0] == towers[b][0] ? towers[a][1] < towers[b][1] : towers[a][0] < towers[b][0]; });
        return {towers[anss[0]][0], towers[anss[0]][1]};
    }

};

int main()
{
//    myvvi vv = {{1,2,5},{2,1,7},{3,1,9}};
//    int r = 2;

//    myvvi vv = {{23,11,21}};
//    int r = 9;

//    myvvi vv = {{1,2,13},{2,1,7},{0,1,9}};
//    int r = 2;

//    myvvi vv = {{2,1,9},{0,1,9}};
//    int r = 2;

//    myvvi vv = {{42,0,0}};          // ... quality 0....
//    int r = 7;

    myvvi vv = {{0,1,2},{2,1,2},{1,0,2},{1,2,2}};
    int r = 1;

    LT1620 lt;

    myvi v = lt.lt1620a(vv, r);
    cout<<v[0]<<" "<<v[1]<<endl;

    return 0;
}
