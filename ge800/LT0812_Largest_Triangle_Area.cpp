
#include "../header/myheader.h"

class LT0812
{
public:


// discuss
// Graham扫描法   凸包算法

// detail
// 4ms: 先计算所有2点间的距离 并保存到len[][]， 3层for，开始计算
//        for (int i = 0; i < N; ++i)
//        {
//            for (int j = i + 1; j < N; ++j)
//            {
//                double a = len[i][j];
//                for (int k = j + 1; k < N; ++k)
//                {
//                    double b = len[i][k];
//                    double c = len[j][k];
//                    double p = 0.5 * (a + b + c);
//                    double area = sqrt(p * (p - a) * (p - b) * (p - c));


//Runtime: 24 ms, faster than 50.74% of C++ online submissions for Largest Triangle Area.
//Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Largest Triangle Area.
    double lt0812c(vector<vector<int>>& points)
    {
        double mx = 0.0;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                for (int k = j + 1; k < points.size(); k++)
                {
                    int x1 = points[i][0];
                    int x2 = points[j][0];
                    int x3 = points[k][0];
                    int y1 = points[i][1];
                    int y2 = points[j][1];
                    int y3 = points[k][1];
                    double area = 0.5 * (x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
                    area = std::abs(area);
                    mx = std::max(area, mx);
                }
            }
        }
        return mx;
    }


// error...
    double lt0812b(vector<vector<int>>& points)
    {
        vector<vector<int>> points2(points.begin(), points.end());
        std::sort(points.begin(), points.end(), [](vector<int> v1, vector<int> v2) { return v1[0] < v2[0]; });
        std::sort(points2.begin(), points2.end(), [](vector<int> v1, vector<int> v2) { return v1[1] < v2[1]; });
        double mx = 0.0;

        #ifdef __test
        for_each(points.begin(), points.end(), [](vector<int> v1) { cout<<v1[0]<<", "<<v1[1]<<endl; });
        for_each(points2.begin(), points2.end(), [](vector<int> v1) { cout<<v1[0]<<", "<<v1[1]<<endl; });
        #endif // __test

        int xmax = points[points.size() - 1][0];
        int xmin = points[0][0];
        int ymax = points2[points2.size() - 1][1];
        int ymin = points2[0][1];

        for (vector<int> v : points)
        {
            int x1 = v[0];
            int y1 = v[1];
            if (x1 == xmax || x1 == xmin || y1 == ymin || y1 == ymax)
            {
                for (vector<int> v2 : points)
                {
                    int x2 = v2[0];
                    int y2 = v2[1];
                    if (x2 == xmax || x2 == xmin || y2 == ymin || y2 == ymax)
                    {
                        for (vector<int> v3 : points)
                        {
                            int x3 = v3[0];
                            int y3 = v3[1];
                            if (x3 == xmax || x3 == xmin || y3 == ymax || y3 == ymin)
                            {
                                double area = 0.5 * (x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
                                area = std::abs(area);
                                mx = std::max(area, mx);
                            }
                        }
                    }
                }
            }
        }

        return mx;
    }


// error
    double lt0812a(vector<vector<int>>& points)
    {
        if (points.size() < 3)
        {
            return 0;
        }
        if (points.size() == 3)
        {
            int x1 = points[0][0];
            int y1 = points[0][1];
            int x2 = points[1][0];
            int y2 = points[1][1];
            int x3 = points[2][0];
            int y3 = points[2][1];

            double area = 0.5 * (x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
            area = std::abs(area);
            return area;
        }

        double mx = 0.0;

        int xmin[2] = {100,100};
        int xmax[2] = {-100,-100};
        int ymin[2] = {100,100};
        int ymax[2] = {-111,-111};

        for (vector<int> v : points)
        {
            int x = v[0];
            int y = v[1];
            if (x > xmax[0])
            {
                xmax[0] = x;
                xmax[1] = y;
            }
            if (x < xmin[0])
            {
                xmin[0] = x;
                xmin[1] = y;
            }
            if (y > ymax[1])
            {
                ymax[0] = x;
                ymax[1] = y;
            }
            if (y < ymin[1])
            {
                ymin[0] = x;
                ymin[1] = y;
            }
        }
//        (1/2)*(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
        vector<vector<int>> vv2;
        vv2.push_back({0,0});
        vv2.push_back({xmin[0], xmin[1]});
        vv2.push_back({xmax[0], xmax[1]});
        vv2.push_back({ymin[0], ymin[1]});
        vv2.push_back({ymax[0], ymax[1]});
        int arr[4][3] = {{1,2,3},{1,3,4},{1,2,4},{2,3,4}};

        #ifdef __test
        for(vector<int> v : vv2)
        {
            for_each(v.begin(), v.end(), fun_cout);
            cout<<endl;
        }
        #endif // __test

        for (int i = 0; i < 4; i++)
        {
            int x1 = vv2[arr[i][0]][0];
            int y1 = vv2[arr[i][0]][1];
            int x2 = vv2[arr[i][1]][0];
            int y2 = vv2[arr[i][1]][1];
            int x3 = vv2[arr[i][2]][0];
            int y3 = vv2[arr[i][2]][1];

            double area = 0.5 * (x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
            area = std::abs(area);
            mx = std::max(area, mx);
        }
        return mx;
    }

};

int main()
{

//    vector<vector<int>> pp = {{0,0},{0,1},{1,0},{0,2},{2,0}};

//    vector<vector<int>> pp = {{9,7},{6,10},{1,10},{2,7}};

    vector<vector<int>> pp = {{2,5},{7,7},{10,8},{10,10},{1,1}};

    LT0812 lt;

    cout<<lt.lt0812c(pp)<<endl;

    return 0;
}
