
#include "../header/myheader.h"

class LT1284
{
public:

// D D



//private static final int[] d = {0, 0, 1, 0, -1, 0};
//        for (int step = 0; !q.isEmpty(); ++step) {                    // 666      for(step; !empty(); ++step)
//            for (int sz = q.size(); sz > 0; --sz) {
//                int cur = q.poll();
//                if (cur == 0) // All 0s matrix found.
//                    return step;
//                for (int i = 0; i < m; ++i) { // traverse all m * n bits of cur.
//                    for (int j = 0; j < n; ++j) {
//                        int next = cur;
//                        for (int k = 0; k < 5; ++k) { // flip the cell (i, j) and its neighbors.
//                            int r = i + d[k], c = j + d[k + 1];                           // 666 把所有的+-变成一维的，还把00放进去了。
//                            if (r >= 0 && r < m && c >= 0 && c < n)
//                                next ^= 1 << (r * n + c);
//                        }
//                        if (seen.add(next)) // seen it before ?
//                            q.offer(next); // no, put it into the Queue.
//                    }
//                }
//            }
//        }






//Runtime: 4 ms, faster than 79.38% of C++ online submissions for Minimum Number of Flips to Convert Binary Matrix to Zero Matrix.
//Memory Usage: 7 MB, less than 68.04% of C++ online submissions for Minimum Number of Flips to Convert Binary Matrix to Zero Matrix.
// bfs
// 1 <= m, n <= 3
// 3*3 = 9.  can use int !!!  but.. 还是试下吧。
    int lt1284a(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();        // static field
        unordered_set<int> set2;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                t2 = (t2 << 1) | mat[i][j];
            }
        }
        if (t2 == 0)
            return 0;

        queue<int> que1;
        que1.push(t2);
        int bitmx = sz1 * sz2;
        int cnt = 0;
        while (!que1.empty())
        {
            cnt++;
            for (int asd = que1.size(); asd > 0; --asd)
            {
                int t2 = que1.front();
                que1.pop();
                for (int of = 0; of < bitmx; of++)
                {
                    int t3 = flipa1(t2, of, sz1, sz2);
                    if (set2.find(t3) != set2.end())
                        continue;
                    if (t3 == 0)
                        return cnt;
                    set2.insert(t3);
                    que1.push(t3);
                }
            }
        }
        return -1;
    }

    int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int flipa1(int a, int idx, int sz1, int sz2)
    {
        int mx = sz1 * sz2;
        int i = idx / sz2;
        int j = idx % sz2;
        int ta = a;
        a = a ^ (1 << idx);         // idx 0
        for (int a2 = 0; a2 < 4; ++a2)          // ...第一次： for (int a = 0; a < 4; ++i) ... 恐怖如斯。。
        {
            int t1 = i + arr[a2][0];
            int t2 = j + arr[a2][1];
            if (t1 >= 0 && t2 >= 0 && t1 < sz1 && t2 < sz2)
            {
                int tidx = t1 * sz2 + t2;
//                cout<<" ."<<tidx<<", "<<a<<", "<<(1 << tidx)<<", "<<(a ^ (1 << tidx))<<endl;
                a = a ^ (1 << tidx);
//                cout<<"        "<<a<<endl;
            }
        }
        #ifdef __test
//        cout<<ta<<" -> "<<a<<endl;
        #endif // __test
        return a;
    }

};

int main()
{
//    myvvi vv = {{0,0},{0,1}};
//    myvvi vv = {{0}};
//    myvvi vv = {{1,1,1},{1,0,1},{0,0,0}};
    myvvi vv = {{1,0,0},{1,0,0}};

    LT1284 lt;

    cout<<lt.lt1284a(vv)<<endl;

    return 0;
}
