
#include "../../header/myheader.h"

class LT
{
public:




// ？？？？？？？？？？ 为什么 cout<<mn3 就是正确的，  不加就是错误的？  leetcode 和本地都是这样的。
// 不是， 是 cout<<endl 就是正确的，  不加就是 错误的。 不知道为什么。
// 这里没有什么缓冲啊。

// minSumSkip 中 minsum 没有初始化导致 默认值是外部(ltb) 的同名的minsum 的值。

// 不， 是因为 minSumSkip 中没有初始化，导致 沿用上一次的结果。 也不是啊。 是沿用第一次的结果。不知道为什么。
// 并且也不知道 endl 的作用。

// g。 应该是 未定义行为的 结果吧。 test() 的结果 就不是 继承上次/第一次 执行的值。


// Runtime104 ms
// Beats
// 86.5%
// Memory14.8 MB
// Beats
// 86.58%
    vector<vector<int>> ltb(int n, vector<vector<int>>& edges)
    {
        for (int i = 0; i < edges.size(); ++i)
        {
            edges[i].push_back(i);
        }
        std::sort(begin(edges), end(edges), [](const vector<int>& v1, const vector<int>& v2) -> bool {
            return v1[2] < v2[2];
        });

        int minsum = minSumSkip(n, edges, -1);

        // minsum = 1234123;
        // minSumSkip(n, edges, 1);     // 不是ltb的minsum的原因， 是因为 继承。
        // exit(9);

        // #ifdef __test
        // cout<<minsum<<endl;
        // #endif

        vector<vector<int>> ans(2, vector<int>());
        int mn2 = 0;
        for (int i = 0; i < edges.size(); ++i)
        {
            // only min weight should check.. i think. but
            int mn3 = minSumChosen(n, edges, i);
            
            // #ifdef __test
            // cout<<mn3;
            // // cout<<endl;                           // ???? 为什么加上这个就ok，不加就错误？
            // #endif

            if (mn3 != minsum)
                continue;

// cout<<endl;              // 在调用minSumSkip前 endl下就可以了。

            mn2 = minSumSkip(n, edges, i);

            cout<<mn3<<"-"<<mn2<<"\n"<<endl;

            if (mn2 == minsum)
            {
                ans[1].push_back(edges[i][3]);
            }
            else
                ans[0].push_back(edges[i][3]);
        }
        return ans;
    }

    int minSumSkip(int n, vector<vector<int>>& vvi, int skip)
    {
        // cout<<endl;              // 无效的。 需要在 ltb 中调用这个方法前，endl，应该是 进入方法的时候 就初始化成了 ltb的minsum的值。
        vector<int> uf(n, -1);
        int a,b,w;
        int minsum;                 // !!!!!!!!!!!!!!!!!!! 这个的问题。 不带初始化的话，这里一直是 7， 估计是ltb 中的 minsum 重名 导致的。
                        // 
        cout<<minsum<<" 1111 \n";
        for (int i = 0; i < vvi.size(); ++i)
        {
            if (i == skip)
                continue;
            a = vvi[i][0];
            b = vvi[i][1];
            w = vvi[i][2];
            if (ufa(uf, a) != ufa(uf, b))
            {
                uf[ufa(uf, a)] = ufa(uf, b);
                minsum += w;
            }
        }
        // cout<<endl;
        cout<<"min skip "<<minsum<<"\n";
        return minsum;
    }

    int minSumChosen(int n, vector<vector<int>>& vvi, int chosen)
    {
        vector<int> uf(n, -1);
        int a, b, w;
        int minsum = vvi[chosen][2];
        uf[vvi[chosen][0]] = vvi[chosen][1];

        for (int i = 0; i < vvi.size(); ++i)
        {
            a = vvi[i][0];
            b = vvi[i][1];
            w = vvi[i][2];
            if (ufa(uf, a) != ufa(uf, b))
            {
                minsum += w;
                uf[ufa(uf, a)] = ufa(uf, b);
            }
        }
        return minsum;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges___error(int n, vector<vector<int>>& edges)
    {
        vector<int> uf(n, -1);
        for (int i = 0; i < edges.size(); ++i)
        {
            edges[i].push_back(i);
        }
        std::sort(std::begin(edges), end(edges), [](const vector<int>& v1, const vector<int>& v2) -> bool{
            return v1[2] < v2[2];
        });

        std::vector<vector<int>> vvi(n);
        int a, b, w;
        vector<int> need;
        int minsum = 0;
        for (int i = 0; i < edges.size(); ++i)
        {
            a = edges[i][0];
            b = edges[i][1];
            w = edges[i][2];
            vvi[a].push_back(i);
            vvi[b].push_back(i);

            if (ufa(uf, a) != ufa(uf, b))
            {
                need.push_back(i);
                minsum += w;
                uf[ufa(uf, a)] = ufa(uf, b);
            }
        }
        vector<vector<int>> ans(2);
        // for (int i = 0; i < need.size(); ++i)
        for (int i = 0; i < edges.size(); ++i)
        {
            // ？ circle， edges' weight all 1 . all edges are pseudo-critical
            // brute-force ?

            if (calMinSum(n, edges, need[i]) == minsum)
            {
                ans[1].push_back(edges[need[i]][3]);
            }
            else
            {
                ans[0].push_back(edges[need[i]][3]);
            }
        }
        return ans;
    }

    int calMinSum(int n, vector<vector<int>>& edges, int skip)
    {
        vector<int> uf(n, -1);
        int minsum = 0;
        int a, b, w;
        for (int i = 0; i < edges.size(); ++i)
        {
            if (i == skip)
                continue;
            a = edges[i][0];
            b = edges[i][1];
            w = edges[i][2];

            if (ufa(uf, a) != ufa(uf, b))
            {
                minsum += w;
                uf[ufa(uf, a)] = ufa(uf, b);
            }
        }
        return minsum;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int test();

int main()
{

    LT lt;

    // int n{5};
    // myvvi vv = {{0,1,1},{1,2,1},{2,3,2},{0,3,2},{0,4,3},{3,4,3},{1,4,6}};

    // myvvi vv2 = lt.ltb(n, vv);

    // for (myvi& vi : vv2)
    // {
    //     showVectorInt(vi);
    // }

    cout<<test()<<", "<<test()<<"\n";
    cout<<test()<<endl;
    cout<<test()<<endl;
    cout<<test()<<endl;
    
// 3, 32768
// 32768
// 32647
// 32647
// 。。。 感觉是单纯的 巧合。。

    return 0;
}

int test()
{
    int a;
    a += 3;
    return a;
}
