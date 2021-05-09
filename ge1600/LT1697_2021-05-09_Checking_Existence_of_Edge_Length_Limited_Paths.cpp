
#include "../header/myheader.h"

class LT1697
{
public:


// D

//Did not see it... tried modified Floyd Warshall - too slow - and then BFS - faster but still too slow.
// .......................
// 根据 query[2] 升序， 根据edge[2]升序
// 指针指向edgeList
// uf
// 遍历 queries，while 指针[2] < query[2], uf查找edge[0],[1],不是一个集合，合并。 指针++
// 查看 query[0] [1] 是否属于同一个集合。



// tle.
    vector<bool> lt1697b(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries)
    {

        // ... 需要的时候才发现，毫无意义。。。
//        unordered_map<long, int> map2;
//        const long CCC = 1E7;
//        for (vector<int>& vi : edgeList)
//        {
//            long key = vi[0] * CCC + vi[1];
//            if (map2.find(key) != map2.end())
//            {
//                if (map2[key] > vi[2])
//                {
//                    map2[key] = vi[2];
//                    map2[vi[1] * CCC + vi[0]] = vi[2];
//                }
//            }
//            else
//            {
//                map2[key] = vi[2];
//                map2[CCC * vi[1] + vi[0]] = vi[2];
//            }
//        }

        unordered_map<int, unordered_map<int, int>> mmap2;
        for (vector<int>& vi : edgeList)
        {
            int st = vi[0], en = vi[1], len = vi[2];
            if (mmap2[st].find(en) == mmap2[st].end())
            {
                mmap2[st][en] = len;
                mmap2[en][st] = len;
            }
            else
            {
                if (mmap2[st][en] > len)
                {
                    mmap2[st][en] = len;
                    mmap2[en][st] = len;
                }
            }
        }

        vector<bool> ans(queries.size(), false);
//        unordered_set<int> set2;            // visited
        unordered_map<int, int> mxp;
        for (int i = 0; i < queries.size(); ++i)
        {
            queue<pair<int, int>> que1;                 // node, length
            int st = queries[i][0];
            int en = queries[i][1];
            int lim = queries[i][2];
            que1.push(std::make_pair(st, 0));
            mxp[st] = 0;
//            set2.insert(st);
            while (!que1.empty())
            {
                pair<int, int> p = que1.front();
                #ifdef __test
                cout<<p.first<<", "<<p.second<<endl;
                #endif // __test
                que1.pop();
//                if (p.second >= lim)
//                    continue;

                if (p.first == en)
                {
                    ans[i] = true;
                    break;
                }

                unordered_map<int, int>& map2 = mmap2[p.first];
                for (pair<int, int> p2 : map2)
                {
                    if (p2.second < lim)
                    {
                        if (mxp.find(p2.first) != mxp.end())
                        {
                            continue;
                        }

                        mxp[p2.first] = 1;
                        que1.push({p2.first, 1});
                        #ifdef __test
                        cout<<p.first<<" : "<<p2.first<<" . "<<p2.second<<endl;
                        #endif // __test
                    }

                    // 。。。 是每条边 都小于 limit，不是 总路径长。。。
//                    int len = p.second + p2.second;
//                    if (mxp.find(p2.first) == mxp.end() || mxp[p2.first] > len)
//                    {
//                        mxp[p2.first] = len;
//                        que1.push({p2.first, len});         // 突然觉得 dfs更好。。。
//                    }
                }
            }

//            que1.clear();     // meiyou
//            set2.clear();
            mxp.clear();
        }

        return ans;
    }

    // floyd . 只记得3重for循环。。。
    // n < 10^5 . no [][]
    // 但是，floyd的结果肯定需要一个数组啊。。
    // bu , 应该每个query，bfs，  queries[i][2] 可以限制住
    vector<bool> lt1697a(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries)
    {
        unordered_map<int, unordered_map<int, int>> mmap2;
        for (vector<int>& vi : edgeList)
        {
            if (mmap2[vi[0]].find(vi[1]) != mmap2[vi[0]].end())
            {
                if (mmap2[vi[0]][vi[1]] > vi[2])
                {
                    mmap2[vi[0]][vi[1]] = vi[2];
                    mmap2[vi[1]][vi[0]] = vi[2];
                }
            }
            else
            {
                mmap2[vi[0]].insert({vi[1], vi[2]});
                mmap2[vi[1]][vi[0]] = vi[2];
            }
        }
//        for (int )
        return {false};
    }

};

int main()
{
//    int n{3};
//    myvvi vv = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
//    myvvi vv2 = {{0,1,2},{0,2,5}};

//    int n{5};
//    myvvi vv = {{0,1,10},{1,2,5},{2,3,9},{3,4,13}};
//    myvvi vv2 = {{0,4,14},{1,4,13}};

//[true,false,false,true,true,false,false,true,false,true,false,true,false,false,false,true,false,true,false,true,true,true,false,true,false,false]
    int n{13};
    myvvi vv = {{9,1,53},{3,2,66},{12,5,99},{9,7,26},{1,4,78},{11,1,62},{3,10,50},{12,1,71},{12,6,63},
    {1,10,63},{9,10,88},{9,11,59},{1,4,37},{4,2,63},{0,2,26},{6,12,98},{9,11,99},{4,5,40},{2,8,25},
    {4,2,35},{8,10,9},{11,9,25},{10,11,11},{7,6,89},{2,4,99},{10,4,63}};
    myvvi vv2 = {
    {9,7,65},{9,6,1},{4,5,34},{10,8,43},
    {3,7,76}
    ,{4,2,15},{7,6,52},{2,0,50},{7,6,62},{1,0,81},{4,5,35},{0,11,86},{12,5,50},{11,2,2},{9,5,6},{12,0,95}
    ,{10,6,9},{9,4,73},{6,10,48},{12,0,91},{9,10,58},{9,8,73},{2,3,44},{7,11,83},{5,3,14},{6,2,33}
    };

    LT1697 lt;

    vector<bool> vb = lt.lt1697b(n, vv, vv2);

    for (bool b : vb)
    {
        cout<<b<<endl;
    }

    return 0;
}
