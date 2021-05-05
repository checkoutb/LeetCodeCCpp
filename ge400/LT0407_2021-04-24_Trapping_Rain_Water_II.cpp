
#include "../header/myheader.h"

class LT0407
{
public:


// D

// priority + while(!empty)


// gg
    int lt0407b(vector<vector<int>>& heightMap)
    {
        if (heightMap.size() <= 2 || heightMap[0].size() <= 2)
            return 0;
        vector<vector<bool>> vvb(heightMap.size(), vector<bool>(heightMap[0].size(), false));
        vector<vector<int>> vvi(heightMap.size(), vector<int>(heightMap[0].size(), INT_MAX >> 1));
        for (int i = 0; i < heightMap.size(); ++i)
        {
            vvi[i][0] = 0;
            vvi[i][heightMap[0].size() - 1] = 0;
        }
        for (int j = 0; j < heightMap[0].size(); ++j)
        {
            vvi[0][j] = 0;
            vvi[heightMap.size() - 1][j] = 0;
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
            {
                cout<<i<<", ";
            }
            cout<<endl;
        }
        cout<<" ==== "<<endl;
        #endif // __test
        for (int i = 1; i < heightMap.size() - 1; ++i)
        {
            dfsb1(heightMap, i, 1, vvb, heightMap[i][0], vvi);
            dfsb1(heightMap, i, heightMap[0].size() - 2, vvb, heightMap[i][heightMap[0].size() - 1], vvi);
        }
        for (int j = 1; j < heightMap[0].size() - 1; ++j)
        {
            dfsb1(heightMap, 1, j, vvb, heightMap[0][j], vvi);
            dfsb1(heightMap, heightMap.size() - 2, j, vvb, heightMap[heightMap.size() - 1][j], vvi);
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
            {
                cout<<i<<", ";
            }
            cout<<endl;
        }
        cout<<" - - - "<<endl;
        #endif // __test
        for (int i = 0; i < heightMap.size(); ++i)
        {
            for (int j = 0; j < heightMap[0].size(); ++j)
            {
                if (vvi[i][j] == INT_MAX >> 1)
                {
                    vvi[i][j] = 0;
                    dfsb1(heightMap, i + 1, j, vvb, heightMap[i][j], vvi);
                    dfsb1(heightMap, i - 1, j, vvb, heightMap[i][j], vvi);
                    dfsb1(heightMap, i, j + 1, vvb, heightMap[i][j], vvi);
                    dfsb1(heightMap, i, j - 1, vvb, heightMap[i][j], vvi);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < heightMap.size(); ++i)
        {
            for (int j = 0; j < heightMap[0].size(); ++j)
            {
                #ifdef __test
                cout<<vvi[i][j]<<", ";
                #endif // __test
                ans += vvi[i][j];
            }
            #ifdef __test
            cout<<endl;
            #endif // __test
        }
        return ans;
    }

    void dfsb1(vector<vector<int>>& map2, int i, int j, vector<vector<bool>>& visit, int h, vector<vector<int>>& vvi)
    {
//        if (visit[i][j])
//            return;
        if (i <= 0 || j <= 0 || i >= vvi.size() - 1 || j >= vvi[0].size() - 1)
            return;
        cout<<i<<", "<<j<<", "<<h<<", "<<map2[i][j]<<endl;
        if (vvi[i][j] + map2[i][j] <= h)
            return;
        if (map2[i][j] >= h)
        {
//            if (vvi[i][j] != INT_MAX >> 1)                # bu xu yao.....
//            {
                cout<<", "<<i<<", "<<j<<"  zero"<<endl;
                vvi[i][j] = 0;
//            }
//            vvi[i][j] = 0;
            return;
        }
        int t2 = h - map2[i][j];
        vvi[i][j] = t2;

        cout<<" - -- "<<i<<", "<<j<<", "<<t2<<endl;

        dfsb1(map2, i + 1, j, visit, h, vvi);
        dfsb1(map2, i - 1, j, visit, h, vvi);
        dfsb1(map2, i, j + 1, visit, h, vvi);
        dfsb1(map2, i, j - 1, visit, h, vvi);

    }

    int lt0407a(vector<vector<int>>& heightMap)
    {
        vector<vector<int>> vvi(heightMap.size(), vector<int>(heightMap[0].size(), 0));
        int t2 = 0;
        for (int i = 1; i < heightMap.size() - 1; ++i)
        {
            for (int j = 1; j < heightMap[0].size() - 1; ++j)
            {
                t2 = min(vvi[i - 1][j] + heightMap[i - 1][j], vvi[i][j - 1] + heightMap[i][j - 1]) - heightMap[i][j];
                if (t2 > 0)
                {
                    vvi[i][j] = t2;
                }
            }
        }
        for (int i = heightMap.size() - 2; i >= 0; --i)
        {
            for (int j = heightMap[0].size() - 2; j >= 0; --j)
            {
                t2 = min(vvi[i + 1][j] + heightMap[i + 1][j], vvi[i][j + 1] + heightMap[i][j + 1]) - heightMap[i][j];
                t2 = max(0, t2);
                vvi[i][j] = min(t2, vvi[i][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i < heightMap.size() - 1; ++i)
        {
            for (int j = 1; j < heightMap[0].size() - 1; ++j)
            {
                #ifdef __test
                cout<<vvi[i][j]<<", ";
                #endif // __test
                ans += vvi[i][j];
            }
            #ifdef __test
            cout<<endl;
            #endif // __test
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};

//    myvvi vv = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};

//    myvvi vv = {{5,5,5,1},
//                {5,1,1,5},
//                {5,1,5,5},
//                {5,2,5,8}};       // 3

//    myvvi vv = {{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};        // 0

    myvvi vv = {{2,2,2},{2,1,2},{2,1,2},{2,1,2}};

    LT0407 lt;

    cout<<lt.lt0407b(vv)<<endl;

    return 0;
}
