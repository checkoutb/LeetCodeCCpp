
#include "../header/myheader.h"

class LT2013
{
public:



};


// D D

// discuss里 星多的都是 数组。。


//int m[1001][1001] = {};
//void add(vector<int> p) { ++m[p[0]][p[1]]; }
//int count(vector<int> p) {
//    int i = p[0], j = p[1], cnt = 0;
//    for (int x = 0; x <= 1000; ++x) {
//        if (x != i && m[x][j]) {
//            int sz = abs(x - i);
//            if (j + sz <= 1000)
//                cnt += m[x][j + sz] * m[i][j + sz] * m[x][j];
//            if (j >= sz)
//                cnt += m[x][j - sz] * m[i][j - sz] * m[x][j];
//        }
//    }
//    return cnt;
//}



// 但是 数组也不慢。。。
//Runtime: 376 ms, faster than 66.14% of C++ online submissions for Detect Squares.
//Memory Usage: 93.9 MB, less than 73.08% of C++ online submissions for Detect Squares.
// count: 输入一个点，返回 以这个点为顶点，且 存在一条边平行于 x轴 的 正方形的 个数。
// 重复点 是 不同的点。
// 1000 * 1000  100000，应该不算多。 或者 bit。
// map<map<>>   map<x*1000+y>。。 需要反refer。。<x, x*1000+y> <y, x*1000+y>
// 不过数组应该更慢， 100000 个元素，3000次操作， 稀疏矩阵。。
class DetectSquares {
private:
//    unordered_map<int, int> map2;     // 不需要 <x*1000+y, count>
    unordered_map<int, unordered_map<int, int>> mmap2;          // <x, <y, count>>
//    unordered_map<int, unordered_map<int, int>> mmap3;      // <y, <x, cnt>>          // .. 遍历完 mmap2， mmap3上 没有被访问过的 也不会有 点可用。
public:
    DetectSquares() {

    }

    void add(vector<int> point) {
        int x = point[0], y = point[1];
        mmap2[x][y]++;
//        mmap3[y][x]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int x2arr[2] = {0};
        int ans = 0;
        for (auto p : mmap2[x])
        {
            int y2 = p.first;
            int cnt = p.second;
            int len = abs(y2 - y);
            if (len == 0)
                continue;
//            int x2 = x - len;
//
//            x2 = x + len;
            x2arr[0] = x - len;
            x2arr[1] = x + len;
            for (int x2 : x2arr)
            {
                #ifdef __test
                cout<<x2<<", "<<x<<", "<<y<<", "<<y2<<", "<<mmap2[8][0]<<endl;
                #endif // __test
                if (mmap2[x2].find(y) != end(mmap2[x2]) && mmap2[x2].find(y2) != end(mmap2[x2]))
                {
                    ans += mmap2[x][y2] * mmap2[x2][y] * mmap2[x2][y2];          // 不需要if，不存在就是0。。 但是 会导致有默认值0，会导致膨胀。浪费CPU
                }
            }
        }
        return ans;
    }
};

int main()
{

    unordered_map<int, int> map2;
    // 0，1，1
    cout<<map2[1]<<endl;
    cout<<map2.count(1)<<endl;
    cout<<map2.size()<<endl;

    LT2013 lt;

    DetectSquares detectSquares = DetectSquares();

    // 8-0 9-8 1-8 0-0 8-8
    // 08 80 00 88
    // 一个0-0， 1个8-8。 2个 8-0  一个0-8
    // y y2 的问题。
    myvvi vv = {{5,10},{10,5},{10,10},{3,0},{8,0},{8,5},{9,0},{9,8},{1,8},{0,0},{8,0},{8,8}};       // 0,8 = 2
    for (myvi& vi : vv)
    {
        detectSquares.add(vi);
    }
    cout<<detectSquares.count({0,8});

//    detectSquares.add({3, 10});
//    detectSquares.add({11, 2});
//    detectSquares.add({3, 2});
//    cout<<endl<<detectSquares.count({11, 10}); // return 1. You can choose:
//                                   //   - The first, second, and third points
//    cout<<endl<<detectSquares.count({14, 8});  // return 0. The query point cannot form a square with any points in the data structure.
//    detectSquares.add({11, 2});    // Adding duplicate points is allowed.
//    cout<<endl<<detectSquares.count({11, 10}); // return 2. You can choose:
//                                   //   - The first, second, and third points
//                                   //   - The first, third, and fourth points


    return 0;
}
