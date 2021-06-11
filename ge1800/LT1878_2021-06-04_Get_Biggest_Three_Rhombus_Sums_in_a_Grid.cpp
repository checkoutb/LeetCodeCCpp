
#include "../header/myheader.h"

class LT1878
{
public:

// D D

//    set<int> s;
//    for (int i = 0; i < g.size(); ++i)
//        for (int j = 0; j < g[0].size(); ++j)
//            for (int sz = 0; i + sz < g.size() && i - sz >= 0 && j + 2 * sz < g[0].size(); ++sz) {
//                int x = i, y = j, r_sum = 0;
//                do r_sum += g[x++][y++]; while (x < i + sz);
//                if (sz > 0) {
//                    do r_sum += g[x--][y++]; while (y < j + 2 * sz);
//                    do r_sum += g[x--][y--]; while (x > i - sz);
//                    do r_sum += g[x++][y--]; while (x < i);
//                }
//                s.insert(r_sum);
//                if (s.size() > 3)
//                    s.erase(begin(s));
//            }
//    return vector<int>(rbegin(s), rend(s));

//        for q in range(1, (1 + min(m, n))//2):
//            for i in range(q, n - q):
//                for j in range(q, m - q):
//                    p1 = dp(i + q, j, -1) - dp(i, j - q, -1)
//                    p2 = dp(i - 1, j + q - 1, -1) - dp(i - q - 1, j - 1, -1)
//                    p3 = dp(i, j - q, 1) - dp(i - q, j, 1)
//                    p4 = dp(i + q - 1, j + 1, 1) - dp(i - 1, j + q + 1, 1)
//                    update(heap, p1 + p2 + p3 + p4)

// 还有一个 转45度后，memo  或者直接memo。


// ... burongyi...
//Runtime: 256 ms, faster than 66.52% of C++ online submissions for Get Biggest Three Rhombus Sums in a Grid.
//Memory Usage: 61.6 MB, less than 25.29% of C++ online submissions for Get Biggest Three Rhombus Sums in a Grid.
// hint2: keyi curte-force
// 每个点作为最上面的顶点，来遍历。
//
    vector<int> lt1878a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();
//        vector<int> ans(3, 0);
//        priority_queue<int, vector<int>, std::greater<int>> priq;     // 。。distinct...
//        priq.push(INT_MIN);
        set<int> set2;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
//                cout<<i<<", "<<j<<endl;
                funa1(grid, i, j, set2);
            }
        }
//        cout<<" = == "<<endl;
//        ans[2] = priq.top();
//        priq.pop();
//        ans[1] = priq.top();
//        priq.pop();
//        ans[0] = priq.top();
//        priq.pop();
        vector<int> ans;
        while (!set2.empty())
        {
            ans.push_back(*set2.rbegin());      // 可以用iterator，但不能用 reversed_iterator
            set2.erase(*set2.rbegin());
        }
        return ans;
    }

    // sz*2 - 1 == sz1 - i

    int arr[4][2] = {{1,-1},{1,1},{-1,1},{-1,-1}};
    void funa1(vector<vector<int>>& grid, int i, int j, set<int>& set2)
    {
//        int sz = min(min(i + 1, (int) grid.size() - i), min(j + 1, (int) grid[0].size() - j));
        int sz = min(min(j + 1, (int) grid[0].size() - j), ((int) grid.size() - i + 1) / 2);
//        priq.push(grid[i][j]);
//        if (set2.size() > 3)
//            priq.pop();
        set2.insert(grid[i][j]);
        if (set2.size() > 3)
            set2.erase(set2.begin());
        for (int x = 1; x < sz; ++x)        // bianchang
        {
            int t2 = 0;
            int m = i;
            int n = j;
            for (int a = 0; a < 4; ++a)
            {
                for (int b = 0; b < x; ++b)
                {
//                    cout<<m<<" - - "<<n<<" . . ."<<sz<<endl;
                    t2 += grid[m][n];
                    m += arr[a][0];
                    n += arr[a][1];
                }
//                cout<<t2<<endl;
            }
//            priq.push(t2);
//            if (priq.size() > 3)
//                priq.pop();
            set2.insert(t2);
            if (set2.size() > 3)
                set2.erase(set2.begin());
        }
    }


};

int main()
{
    myvvi vv = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
//    myvvi vv = {{1,2,3},{4,5,6},{7,8,9}};
//    myvvi vv = {{7,7,7}};

    LT1878 lt;

    myvi v = lt.lt1878a(vv);

//    cout<<v[0]<<", "<<v[1]<<", "<<v[2]<<endl;
    for (int i : v)
        cout<<i<<", ";

    return 0;
}
