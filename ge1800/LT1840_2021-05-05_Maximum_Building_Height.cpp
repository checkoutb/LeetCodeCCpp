
#include "../header/myheader.h"

class LT1840
{
public:

// D D

//We can rotate all restrictions clockwise by 45 degrees.
//The skyline of the buildings after this rotation will be rectangles with sides parallel to x or y-axis
//and the highest buildings correspond to the corners of these rectangles.


//int pass(vector<vector<int>>& r) {
//    int res = 0;
//    for (int i = 0; i < r.size() - 1; ++i) {
//        auto h1 = r[i][1], h2 = r[i + 1][1];
//        auto h = h1 + abs(r[i + 1][0] - r[i][0]);
//        if (h > h2)
//            h = h2 + (h - h2) / 2;
//        res = max(res, h);
//        r[i + 1][1] = min(h, h2);
//    }
//    return res;
//}
//int maxBuilding(int n, vector<vector<int>>& r) {
//    r.insert(r.end(), {{1, 0}, {n, n - 1}});
//    sort(begin(r), end(r));
//    pass(r);
//    reverse(begin(r), end(r));
//    return pass(r);
//}





//Runtime: 420 ms, faster than 96.28% of C++ online submissions for Maximum Building Height.
//Memory Usage: 102.4 MB, less than 74.75% of C++ online submissions for Maximum Building Height.
// discuss: greedy, 2pass
    int lt1840b(int n, vector<vector<int>>& restrictions)
    {
        int sz1 = restrictions.size();
        if (sz1 == 0)
            return n-1;
        sort(begin(restrictions), end(restrictions));
        int i1 = 1;
        int h1 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            restrictions[i][1] = min(restrictions[i][1], h1 + restrictions[i][0] - i1);
            i1 = restrictions[i][0];
            h1 = restrictions[i][1];
        }
        i1 = restrictions[sz1 - 1][0];
        h1 = restrictions[sz1 - 1][1];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            restrictions[i][1] = min(restrictions[i][1], h1 + i1 - restrictions[i][0]);
            i1 = restrictions[i][0];
            h1 = restrictions[i][1];
        }

        #ifdef __test
        for (myvi& vi : restrictions)
            cout<<vi[0]<<","<<vi[1]<<" | ";
        cout<<endl;
        #endif // __test
        int ans = 0;
        h1 = 0, i1 = 1;
        int h2 = restrictions[0][1], i2 = restrictions[0][0];
//        if (h2 > h1 + i2 - i1)
//            h2 = h1 + i2 - i1;
        ans = h2 + (i2-i1-h2+h1) / 2;
        ans = max(ans, n - restrictions[restrictions.size() - 1][0] + restrictions[restrictions.size() - 1][1]);
        for (int i = 1; i < restrictions.size(); ++i)
        {
            i1 = i2;
            h1 = h2;
            i2 = restrictions[i][0];
            h2 = restrictions[i][1];
//            if (h2 > h1 + i2 - i1)
//                h2 = h1 + i2 - i1;
            ans = max(ans, h2 + (i2-i1-h2+h1) / 2);
        }

        return ans;
    }



// tle....
// n < 10^9
// 2 2   3 3   2+(3-2)/2+
// h1+add1 == h2+add2   add1+add2=i2-i1
// 2+a1 = 3+a2    a1+a2=1
// a1-a2 = 1  a1+a2=1       a1=1+a2  a1=1-a2   a1=1  a2=0   2+1==3+0
// a1 = h2+a2-h1  a1=i2-i1-a2
// h2+a2-h1 = i2-i1-a2
// 2*a2 = i2-i1-h2+h1
// 2 2, 4 3     i h
// 4-2-3+2 = 1    a2=0.5=0
// 2 3, 4 2
// 4-2-2+3 = 3  a2=1.5=1
// 限制不代表可以达到。
// 反向限制
    int lt1840a(int n, vector<vector<int>>& restrictions)
    {
        if (restrictions.size() == 0)
            return n - 1;
        sort(begin(restrictions), end(restrictions));
        restrictions[0][1] = min(restrictions[0][1], restrictions[0][0] - 1);
        //
        for (int i = 1; i < restrictions.size(); ++i)
        {
            int t2 = restrictions[i][1];
            int i2 = restrictions[i][0];
            for (int j = i - 1; j >= 0; --j)
            {
                int tj = restrictions[j][1];
                int ij = restrictions[j][0];
                if (ij < i2 - t2)
                    break;
                if (tj + i2 - ij < t2)
                    t2 = tj + i2 - ij;
//                if (restrictions[j][1] + )
            }
            for (int j = i + 1; j < restrictions.size(); ++j)
            {
                int hj = restrictions[j][1];
                int ij = restrictions[j][0];
                if (ij > i2 + t2)
                    break;
                if (hj + ij - i2 < t2)
                    t2 = hj + ij - i2;
            }
            restrictions[i][1] = t2;
        }

        #ifdef __test
        for (myvi& vi : restrictions)
            cout<<vi[0]<<","<<vi[1]<<" | ";
        cout<<endl;
        #endif // __test

        int ans = 0;
        int h1 = 0, i1 = 1;
        int h2 = restrictions[0][1], i2 = restrictions[0][0];
//        if (h2 > h1 + i2 - i1)
//            h2 = h1 + i2 - i1;
        ans = h2 + (i2-i1-h2+h1) / 2;
        ans = max(ans, n - restrictions[restrictions.size() - 1][0] + restrictions[restrictions.size() - 1][1]);
        for (int i = 1; i < restrictions.size(); ++i)
        {
            i1 = i2;
            h1 = h2;
            i2 = restrictions[i][0];
            h2 = restrictions[i][1];
//            if (h2 > h1 + i2 - i1)
//                h2 = h1 + i2 - i1;
            ans = max(ans, h2 + (i2-i1-h2+h1) / 2);
        }

        return ans;
    }

};

int main()
{
//    int n = 5;
//    myvvi vv = {{2,1},{4,1}};

//    int n = 6;
//    myvvi vv = {};

//    int n{10};
//    myvvi vv = {{5,3},{2,5},{7,4},{10,3}};

//    int n = 10;
//    myvvi vv = {{8,5},{9,0},{6,2},{4,0},{3,2},{10,0},{5,3},{7,3},{2,4}};        // 2
//    // 0 4 2 0

    int n = 10;
    myvvi vv = {{6,0},{5,2},{7,0},{9,1},{2,4},{3,4},{4,0},{8,2},{10,0}};            // 1
    //



    LT1840 lt;

    cout<<lt.lt1840b(n, vv)<<endl;

    return 0;
}
