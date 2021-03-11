
#include "../header/myheader.h"

class LT1722
{
public:

// D D

//        vector<int> ds(source.size(),-1);
//        for(auto& sw:allowedSwaps){
//            int i=find(ds,sw[0]),j=find(ds,sw[1]);
//            if(i!=j){
//                if(ds[i]>ds[j])
//                    swap(i,j);
//                ds[i]+=ds[j];
//                ds[j]=i;
//            }
//        }
//        vector<multiset<int>> cycles(source.size());
//        for(int i=0;i<source.size();++i)
//            if(source[i]!=target[i])
//                cycles[find(ds,i)].insert(source[i]);
//        for(int i=0;i<target.size();++i){
//            if(source[i]!=target[i]){
//                auto& cycle=cycles[find(ds,i)];
//                auto it=cycle.find(target[i]);
//                if(it!=cycle.end())
//                    cycle.erase(it);
//                else
//                    ++res;
//            }
//        }

// ???  i!=j 里那段在干什么？
//ds[i] += ds[j]; seems just counting (negative) how many elements there are in the current union.
//i and j are both roots. It's not necessary for this problem but I think it's a useful trick.
// 。。嗯， 最开始的时候全是-1, 每次 都会把 A的 负数(最开始-1) 加到 B上， 然后 B指向 A。
// 所以 这个值 就是 这棵树的 结点数。  并且 有判断 dsi dsj, 这样就把 小的树附加到 大的树，来减少 寻路长度。


//    def minimumHammingDistance(self, source, target, edges):
//        res = n = len(source)
//        G = [set() for i in xrange(n)]
//        for i, j in edges:
//            G[i].add(j)
//            G[j].add(i)
//        seen = [0] * n
//
//        def dfs(i):
//            seen[i] = 1
//            found.append(i)
//            for j in G[i]:
//                if not seen[j]:
//                    dfs(j)
//
//        for i in xrange(n):
//            if seen[i]: continue
//            found = []
//            dfs(i)
//            count1 = collections.Counter(source[j] for j in found)
//            count2 = collections.Counter(target[j] for j in found)
//            res -= sum((count1 & count2).values())
//        return res



//Runtime: 296 ms, faster than 95.50% of C++ online submissions for Minimize Hamming Distance After Swap Operations.
//Memory Usage: 109.2 MB, less than 96.56% of C++ online submissions for Minimize Hamming Distance After Swap Operations.
    int lt1722b(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps)
    {
        int sz1 = source.size();
        vector<int> uf(sz1, -1);
        unordered_set<int> set2;
        for (vector<int>& vi : allowedSwaps)
        {
            int t1 = ufb1(uf, vi[0]);
            int t2 = ufb1(uf, vi[1]);
            if (t1 != t2)
            {
                uf[t1] = t2;
            }
            set2.insert(vi[0]);
            set2.insert(vi[1]);
        }
        unordered_map<int, vector<int>> map2;           // ufb1 : source's index
        for (int i : set2)
        {
            int t1 = ufb1(uf, i);
            map2[t1].push_back(i);
        }
        int ans = 0;
        int notSame = 0;
        for (pair<int, vector<int>> p : map2)
        {
            vector<int>& vi = p.second;
            unordered_map<int, int> map3;
            for (int i : vi)
            {
                #ifdef __test
//                cout<<p.first<<" : "<<i<<endl;
                #endif // __test
                map3[source[i]]++;
                map3[target[i]]--;
            }
            int t2 = 0;
            for (pair<int, int> p2 : map3)
            {
                #ifdef __test
//                cout<<p2.second<<endl;
                #endif // __test
                t2 += std::abs(p2.second);
            }
            notSame += t2 / 2;                   // ... /2
        }
        for (int i = 0; i < sz1; ++i)
        {
            if (set2.find(i) == set2.end())
            {
                if (source[i] != target[i])
                {
                    ans++;
                }
            }
        }
        #ifdef __test
//        cout<<ans<<", "<<notSame<<endl;
        #endif // __test
        ans += notSame;
        return ans;
    }

    int ufb1(vector<int>& uf, int idx)
    {
        if (uf[idx] == -1)
            return idx;
        int ans = ufb1(uf, uf[idx]);
        uf[idx] = ans;
        return ans;         // return uf[idx] == -1 ? idx : uf[idx] = ufa1(uf, uf[idx]);
    }



// tle
// uf , map / vector
    int lt1722a(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps)
    {
        int sz1 = source.size();
        vector<int> uf(sz1, -1);
        for (vector<int>& vi : allowedSwaps)
        {
            int t1 = ufa1(uf, vi[0]);
            int t2 = ufa1(uf, vi[1]);
            if (t1 != t2)
            {
                uf[t1] = t2;
            }
        }           // if ((t1 = ufa1()) != (t2 = ufa1())) {uf[t1] = t2}
        unordered_map<int, int> map2;           // source's idx : ufa1
        unordered_map<int, vector<int>> map3;   // ufa1 : source's value with idx with same ufa1
        unordered_map<int, vector<int>> map4;   //        target
        for (vector<int>& vi : allowedSwaps)
        {
            if (map2.find(vi[0]) == map2.end())
            {
                int t1 = ufa1(uf, vi[0]);
                map2[vi[0]] = t1;
                map3[t1].push_back(source[vi[0]]);
                map4[t1].push_back(target[vi[0]]);
            }
            if (map2.find(vi[1]) == map2.end())
            {
                int t1 = ufa1(uf, vi[1]);
                map2[vi[1]] = t1;
                map3[t1].push_back(source[vi[1]]);
                map4[t1].push_back(target[vi[1]]);
            }
        }
        int notSame = 0;
        for (unordered_map<int, vector<int>>::iterator it = map3.begin(); it != map3.end(); it++)
        {
            int k = it->first;
            vector<int> vs = it->second;
            vector<int> vt = map4[k];
            for (int i = 0; i < vs.size(); ++i)
            {
                int t2 = vs[i];
                for (int j = 0; j < vt.size(); ++j)
                {
                    if (t2 == vt[j])
                    {
                        vt[j] = -1;
                        goto AAA;
                    }
                }
                notSame++;

                AAA:
                continue;
            }
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (map2.find(i) == map2.end())
            {
                if (target[i] != source[i])
                    ans++;
            }
        }
        ans += notSame;
        return ans;
    }

    int ufa1(vector<int>& uf, int idx)
    {
        if (uf[idx] == -1)
            return idx;
        int ans = ufa1(uf, uf[idx]);
        uf[idx] = ans;
        return ans;         // return uf[idx] == -1 ? idx : uf[idx] = ufa1(uf, uf[idx]);
    }

};

int main()
{
//    myvi v1 = {1,2,3,4};
//    myvi v2 = {2,1,4,5};
//    myvvi vv = {{0,1},{2,3}};

//    myvi v1 = {1,2,3,4};
//    myvi v2 = {1,3,2,4};
//    myvvi vv = {};

    myvi v1 = {5,1,2,4,3};
    myvi v2 = {1,5,4,2,3};
    myvvi vv = {{0,4},{4,2},{1,3},{1,4}};

    LT1722 lt;

    cout<<lt.lt1722b(v1, v2, vv)<<endl;

    return 0;
}
