
#include "../header/myheader.h"

class LT2049
{
public:

// D D


//int dfs(vector<vector<int>> &al, vector<long long> &s, int i) {
//    long long prod = 1, sum = 1;
//    for (int j : al[i]) {
//        int cnt = dfs(al, s, j);
//        prod *= cnt;
//        sum += cnt;
//    }
//    s[i] = prod * (max(1ll, (long long)al.size() - sum));
//    return i != 0 ? sum : count(begin(s), end(s), *max_element(begin(s), end(s)));
//}


//    int countHighestScoreNodes(vector<int>& P) {
//        long N = P.size(), ans = 0, maxScore = 0;
//        vector<vector<int>> G(N); // build the graph -- G[i] is a list of the children of node `i`.
//        for (int i = 1; i < N; ++i) G[P[i]].push_back(i);
//        function<int(int)> dfs = [&](int u) { // Post-order traversal. Returns the size of the subtree rooted at node `u`.
//            long score = 1, cnt = 1;
//            for (int v : G[u]) {
//                int c = dfs(v);
//                cnt += c;
//                score *= c;
//            }
//            long other = N - cnt; // The count of nodes not in this subtree rooted at node `u`.
//            if (other) score *= other;
//            if (score > maxScore) {
//                maxScore = score;
//                ans = 0;
//            }
//            if (score == maxScore) ++ans;
//            return cnt;
//        };
//        dfs(0);
//        return ans;
//    }
// .. function ，一时间没分清 是java 还是 c++..    go倒是写过 def。来内置函数。


// 土拨鼠的怒吼。
//Runtime: 1964 ms, faster than 5.12% of C++ online submissions for Count Nodes With the Highest Score.
//Memory Usage: 231.9 MB, less than 5.12% of C++ online submissions for Count Nodes With the Highest Score.

//206 / 206 test cases passed, but took too long.

// tle。。。。。应该是 while(parent != -1) 太慢了。 这个导致 n^2 / nlogn 了。。 那就改bfs 试下。
// 现在就是怎么根据 parent 来遍历
// for for (for) 还是 queue。
// 根据parent 可以构造 children，但是 好像没有什么用。
// 数组的值 是 非叶子结点，所以可以找出叶子结点，然后 bottom-up
// 而且 叶子结点的删除 不会分裂树，非叶子结点会。。这就要用到children了。 除了root以外， children 的数量 + 1 就是 分裂出的树。
// 那就不太需要 notLeaf 了。毕竟也是遍历的时候用到的。
    int lt2049a(vector<int>& parents)
    {
        int sz1 = parents.size();
//        unordered_set<int> notLeaf(begin(parents), end(parents));
        vector<vector<int>> children(sz1, vector<int>());
        map<long, int> map2;         // product - count
        vector<int> subtreecnt(sz1, 1);       // [node as root]'s subtree's count
        int ans = 0;
//        showVectorInt(subtreecnt);
        for (int i = 1; i < sz1; i++)
        {
            children[parents[i]].push_back(i);
        }
        queue<int> que1;
        unordered_set<int> set2;
        for (int i = 1; i < sz1; i++)
        {
            if (children[i].size() == 0 && (set2.find(parents[i]) == end(set2)))
            {
                que1.push(parents[i]);
                set2.insert(parents[i]);
            }
        }
        set2.clear();
        while (!que1.empty())
        {
            int node = que1.front();
            que1.pop();
            subtreecnt[node] = 1 + subtreecnt[children[node][0]] + (children[node].size() == 1 ? 0 : subtreecnt[children[node][1]]);
//            if (parents[node] != -1 && set2.find(parents[node]) == end(set2))       // 。。 后续的会覆盖前面的。。。我++
            if (parents[node] != -1)
            {
                if (children[parents[node]].size() == 2 && subtreecnt[parents[node]] == 1)      // 父结点有2个child，但是没有被计算过，那么说明node 是第一个结点，跳过。
                {
                    subtreecnt[parents[node]] = 2;      // 下次就不会continue了。
                    continue;
                }
                que1.push(parents[node]);
//                set2.insert(parents[node]);
            }
        }

//        for (int i = 1; i < sz1; i++)
//        {
//            if (children[i].size() == 0)        // leaf
//            {
//                subtreecnt[i] = 1;
//                int t2 = i;
//                while (parents[t2] != -1)
//                {
////                    subtreecnt[parents[t2]] += subtreecnt[t2];        // 2个叶子结点，第二个叶子会导致 第一个叶子的重复加一遍。
////                    subtreecnt[parents[t2]] += 1;         // 这个也不对。。。难道只能 bfs？
//                    // 不需要更新，直接重新计算就是了。。。
//                    subtreecnt[parents[t2]] = 1 + subtreecnt[children[parents[t2]][0]] + (children[parents[t2]].size() == 1 ? 0 : subtreecnt[children[parents[t2]][1]]);           // 不能保证t2 是 children[parent[t2]] 的 [0] 还是 [1]
//                    t2 = parents[t2];
//                }
//            }
//        }

        if (children[0].size() == 1)
            map2[sz1 - 1]++;
        else if (children[0].size() == 2)
            map2[1L * subtreecnt[children[0][0]] * subtreecnt[children[0][1]]]++;

        int t2, t3;     // case 中不能出现 声明。
        for (int i = 1; i < sz1; i++)
        {
            switch (children[i].size())
            {
            case 0:
                map2[sz1 - 1]++;
                break;
            case 1:
                t2 = subtreecnt[children[i][0]];
                map2[1L * (sz1 - 1 - t2) * t2]++;
                break;
            case 2:
                t2 = subtreecnt[children[i][0]];
                t3 = subtreecnt[children[i][1]];
                map2[1L * (sz1 - 1 - t2 - t3) * t2 * t3]++;
                break;
            }
        }

        #ifdef __test
        for(auto& p : map2)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        cout<<"---------"<<endl;
        for (int i = 0; i < sz1; i++)
        {
            cout<<i<<" : ";
            for (int a : children[i])
            {
                cout<<a<<"-"<<subtreecnt[a]<<", ";
            }
            cout<<endl;
        }
        #endif // __test

        ans = rbegin(map2)->second;
        return ans;
    }

//    int dfsatotal()       //... not TreeNode, just v.size..

};

int main()
{

    LT2049 lt;

//    myvi v = {-1,2,0,2,0};
//    myvi v = {-1, 2, 0};
//    myvi v = {-1,3,3,5,7,6,0,0};        // 2
    /*
        0
    6      7
  5      4
 3
1 2
    */
    // 3*4

//    myvi v = {-1,6,9,2,0,6,0,4,4,11,12,1,7};            // 1
/*
            0
    4               6
  7   8          1    5
12              11
10            9
            2
          3

  */
    myvi v = {-1,8,9,7,6,2,9,8,0,0};            // 2


    cout<<lt.lt2049a(v)<<endl;

    return 0;
}
