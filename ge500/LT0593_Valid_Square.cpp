
#include "../header/myheader.h"

class LT0593
{
public:

// D D

//int d(vector<int>& p1, vector<int>& p2) {
//    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
//}
//bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
//    unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
//    return !s.count(0) && s.size() == 2;
//}

// (0,0),(0,2),(-1,√3),(1,√3)  的时候，上面会错误。
// 2个 等边三角形 组合在一起，就。。
// 不过都是 int，所以不会出现的。
// 我这个，在上面这种输入下，我会出错。。需要加个条件，每个点作为起始点的 3条边 必须 1条长，2条相同的短。



//Runtime: 4 ms, faster than 92.37% of C++ online submissions for Valid Square.
//Memory Usage: 26.3 MB, less than 8.14% of C++ online submissions for Valid Square.
    bool lt0593b(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        int len12 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        int len13 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        int len14 = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
        unordered_map<int, int> map1;
        map1[len12]++;
        map1[len13]++;
        map1[len14]++;
        if (map1.size() != 2)
            return false;
        int mx1 = max(len12, max(len13, len14));
        if (min(len12, min(len13, len14)) == 0)         // [1,1] [0,0]*3
            return false;
        if (map1[mx1] != 1)
            return false;
        vector<vector<int>> vv;
        vv.push_back(p1);
        vv.push_back(p2);
        vv.push_back(p3);
        vv.push_back(p4);
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                int len = (vv[i][0] - vv[j][0]) * (vv[i][0] - vv[j][0]) + (vv[i][1] - vv[j][1]) * (vv[i][1] - vv[j][1]);
                if (map1[len] == 0)
                    return false;
            }
        }
        return true;
    }


    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        int len12 = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
        int len13 = (p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]);
        int len14 = (p1[0] - p4[0]) * (p1[0] - p4[0]) + (p1[1] - p4[1]) * (p1[1] - p4[1]);
        unordered_map<int, int> map1;
        map1[len12]++;
        map1[len13]++;
        map1[len14]++;
        if (map1.size() != 2)
            return false;
        int mx1 = max(len12, max(len13, len14));
        if (map1[mx1] != 1)
            return false;
        vector<vector<int>> vv2;
        vector<vector<int>> vv1;
        if (mx1 == len12)
        {
            vv2.push_back(p3);
            vv2.push_back(p4);
            vv1.push_back(p2);
        }
        if (mx1 == len13)
        {
            vv2.push_back(p2);
            vv2.push_back(p4);
            vv1.push_back(p3);
        }
        if (mx1 == len14)
        {
            vv2.push_back(p2);
            vv2.push_back(p3);
            vv1.push_back(p4);
        }
        return false;
    }

};

int main()
{

    vector<vector<int>> vv = {{0,0},{1,0},{1,1},{0,1}};

    LT0593 lt;

    cout<<lt.lt0593b(vv[0], vv[1], vv[2], vv[3])<<endl;

    return 0;
}
