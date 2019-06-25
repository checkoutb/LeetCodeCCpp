
#include "../header/myheader.h"




// 左下角的x轴排序，y轴排序。。。最好是个map，key是左下角的x。
// 如果能在 垂直线 上合并，则 2个vector的 [0],[2] 必然分别相等。而且v1[3] == v2[1].
// 好像排序只有一半的作用，水平线上没有排序，
bool compc1(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[0] != v2[0])
    {
        return v1[0] < v2[0];
    }
    else
    {
        return v1[1] < v2[1];
    }
}

class LT0391
{
public:





// discuss
// 1. 面积相等，2. 每个点都会出现偶数。大矩形的4个角只有1次。
//x1 = Math.min(rect[0], x1);
//String s1 = rect[0] + " " + rect[1];
//if (!set.add(s1)) set.remove(s1);
//if (!set.contains(x1 + " " + y1) || !set.contains(x1 + " " + y2) || !set.contains(x2 + " " + y1) || !set.contains(x2 + " " + y2) || set.size() != 4) return false;


// sweep line
//Sort by x-coordinate.
//Insert y-interval into TreeSet, and check if there are intersections.
//Delete y-interval.










    // 第一象限，而非数组类似的第四象限

    // 1. 遍历，x_max,x_min,y_max,_ymin, 水平/垂直线组成一个 矩形(二维bool数组)。遍历，在bool数组上进行填色。
        // 第一次遍历，可以累加小矩形的 面积，对比bool数组的面积。
    // 2. 遍历，x_max,x_min,y_max,_ymin,小矩形面积和，与max,min组成的矩形面积对比。。for(for())，对比任意2个小矩形是否有重叠。
    // 3. 并查集，将2个小矩形合并成一个矩形。直至无法合并。先排序。




    // .... 42 / 46  。。。 tle。。。。
    bool lt0391c(vector<vector<int>>& rectangles)
    {
        sort(rectangles.begin(), rectangles.end(), compc1);
        int sz1 = -2;
        while (rectangles.size() != sz1)
        {
            sz1 = rectangles.size();

            int i = 0;
            while (i < rectangles.size() - 1)
            {
                vector<int>& v1 = rectangles[i];
                vector<int>& v2 = rectangles[i + 1];
                if (v1[0] == v2[0] && v1[2] == v2[2] && v1[3] == v2[1])
                {
                    v1[2] = v2[2];
                    v1[3] = v2[3];
                    rectangles.erase(rectangles.begin() + i + 1);
                }
                else
                {
                    i++;
                }
            }

            // 水平合并。。。应该按 左下顶点x轴 分组(map)。
            i = 0;
            int j = 0;
            bool flag1 = false;

            AAA:
            for(; i < rectangles.size() - 1; i++)
            {
                flag1 = true;
                for (j = i + 1; j < rectangles.size(); j++)
                {
                    vector<int>& v1 = rectangles[i];
                    vector<int>& v2 = rectangles[j];
                    // x 轴有序的。所以优先判断。
                    if (v1[2] == v2[0])
                    {
                        flag1 = false;
                        if (v1[1] == v2[1] && v1[3] == v2[3])
                        {
                            v1[2] = v2[2];
                            v1[3] = v2[3];
                            rectangles.erase(rectangles.begin() + j);
                            i++;
                            goto AAA;
                        }
                    }
                    else if(v1[2] < v2[0])      // 后面x越来越大，不可能了。如果下面flag1要起作用的话，得写在这里。
                    {
                        i++;
                        goto AAA;
                    }
                }

//                if (flag1)
//                {
//                    // 对于某个矩形，没有其他矩形的 左下x == 它的右上x，这个时候是没有办法形成矩形的。
//                    // 这里还缺一个条件，矩形的右上x不能是xMax。所以取消了这段逻辑。
//                    return false;
//                }
            }

        }

        return rectangles.size() == 1;
    }




    // 2.
    // 最好也排序下，这样可以在for(for())中提前continue。。
    // 这个更慢。。41 / 46 tle

    // 似乎只有排序，并查集这两条路。

    bool lt0391b(vector<vector<int>>& rectangles)
    {
        int xMax = 0;
        int yMax = 0;
        int xMin, yMin;
        xMin = yMin = INT_MAX;
        int area = 0;

        #ifdef __test
        cout<<xMax<<", "<<yMax<<endl;
        #endif // __test

        vector<int> v3;
        for(vector<vector<int>>::iterator it2 = rectangles.begin(); it2 != rectangles.end(); it2++)
        {
            v3 = *it2;
            area += (v3[2] - v3[0]) * (v3[3] - v3[1]);
            xMax = max(xMax, v3[2]);
            xMin = min(xMin, v3[0]);
            yMax = max(yMax, v3[3]);
            yMin = min(yMin, v3[1]);
        }

        #ifdef __test
        cout<<xMin<<", "<<xMax<<", "<<yMin<<", "<<yMax<<endl;
        cout<<area<<" ==? "<<(xMax - xMin) * (yMax - yMin)<<endl;
        #endif // __test

        if (area != (xMax - xMin) * (yMax - yMin))
        {
            return false;
        }

        int sz1 = rectangles.size();
        vector<int> v11;
        vector<int> v22;
        double c1x, c1y, c2x, c2y;
        double h1, h2, w1, w2;
        for (int i = 0; i < sz1; i++)
        {
            v11 = rectangles[i];
//            h1 = v11[3] - v11[1];
//            w1 = v11[2] - v11[0];
//            c1x = (0.0 + v11[2] + v11[0]) / 2;
//            c1y = (0.0 + v11[3] + v11[1]) / 2;

            for (int j = i + 1; j < sz1; j++)
            {
                v22 = rectangles[j];
//                h2 = v22[3] - v11[1];
//                w2 = v11[2] - v11[0];
//                c2x = (0.0 + v22[2] + v22[0]) / 2;
//                c2y = (0.0 + v22[3] + v22[1]) / 2;
        // |c1x - c2x| <= (w1 + w2) / 2 && |c1y - c2y| <= (h1 + h2) / 2
        // == 的时候是类似相切。

                if (abs(v11[2] + v11[0] - v22[2] - v22[0]) < (v11[2] - v11[0] + v22[2] - v22[0]) && abs(v11[3] + v11[1] - v22[3] - v22[1]) < (v11[3] - v11[1] + v22[3] - v22[1]))
                {

                    #ifdef __test
                    cout<<v11[0]<<","<<v11[1]<<","<<v11[2]<<","<<v11[3]<<"  ..  "<<v22[0]<<","<<v22[1]<<","<<v22[2]<<","<<v22[3]<<endl;
                    cout<<abs(v11[2] + v11[0] - v22[2] - v22[0])<<endl;
                    cout<<(v11[2] - v11[0] + v22[2] - v22[0])<<endl;
                    cout<<abs(v11[3] + v11[1] - v22[3] - v22[1])<<endl;
                    cout<<(v11[3] - v11[1] + v22[3] - v22[1])<<endl;
                    #endif // __test

                    return false;
                }
            }
        }

        return true;
    }



    // 1.
    // 42 / 46 test cases passed.       stack-overflow.     而且看到了负数。。Max需要初始化为INT_MIN。而不是0.
    //          而且 case里，数值范围大约是[-20000,20000]。4万*4万。16亿，最好longlong
    // 在xMin所在的垂直线上，y是一条线段。(所有x == xMin 的矩阵，[v3[0], v3[2]] 能组成一条线段)
    bool lt0391a(vector<vector<int>>& rectangles)
    {
//        int xMax, yMax;           // random.....
        int xMax = 0;
        int yMax = 0;
        int xMin, yMin;
        xMin = yMin = INT_MAX;
        int area = 0;

        #ifdef __test
        cout<<xMax<<", "<<yMax<<endl;
        #endif // __test

        vector<int> v3;
        for(vector<vector<int>>::iterator it2 = rectangles.begin(); it2 != rectangles.end(); it2++)
        {
            v3 = *it2;
            area += (v3[2] - v3[0]) * (v3[3] - v3[1]);
            xMax = max(xMax, v3[2]);
            xMin = min(xMin, v3[0]);
            yMax = max(yMax, v3[3]);
            yMin = min(yMin, v3[1]);
        }

        #ifdef __test
        cout<<xMin<<", "<<xMax<<", "<<yMin<<", "<<yMax<<endl;
        cout<<area<<" ==? "<<(xMax - xMin) * (yMax - yMin)<<endl;
        #endif // __test

        if (area != (xMax - xMin) * (yMax - yMin))
        {
            return false;
        }

        bool arr2[xMax - xMin][yMax - yMin] = {false};
        for (auto& p2 : arr2)
        {
            for (auto& p3 : p2)
            {
                p3 = false;
            }
        }

        for (vector<int> v2 : rectangles)
        {
            for (int i2 = v2[0] - xMin; i2 < v2[2] - xMin; i2++)
            {
                for (int j2 = v2[1] - yMin; j2 < v2[3] - yMin; j2++)
                {
                    if (arr2[i2][j2])
                    {
                        #ifdef __test
                        cout<<i2<<", "<<j2<<endl;
                        #endif // __test
                        return false;
                    }
                    else
                    {
                        arr2[i2][j2] = true;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> v3 = {
//        {1,1,3,3},
//        {3,1,4,2},
//        {3,2,4,4},
//        {1,3,2,4},
//        {2,3,3,4}

//        {1,1,2,3},
//        {1,3,2,4},
//        {3,1,4,2},
//        {3,2,4,4}

// runtime error: load of value 99, which is not a valid value for type 'bool' (solution.cpp)
// 应该是bool数组没有初始化
//    {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}}


    };

    LT0391 lt;
    cout<<endl<<lt.lt0391c(v3)<<endl;
    return 0;
}
