
#include "../header/myheader.h"

class LT2076
{
public:

// D D

// For each request, check if doesn't obey any restrictions.

//        UnionFind uf(n);
//        for (auto &r : requests) {
//            int p = uf.find(r[0]), q = uf.find(r[1]); // the leaders of the two parties
//            bool valid = true;
//            if (!uf.connected(p, q)) { // Only need to check the bans if the two parties are not already connected
//                for (auto &b : bans) {
//                    int x = uf.find(b[0]), y = uf.find(b[1]); // the leaders of the two banned parties
//                    if ((x == p && y == q) || (x == q && y == p)) {
//                        valid = false;
//                        break;
//                    }
//                }
//            }
//            ans.push_back(valid);
//            if (valid) uf.connect(p, q); // connect two parties if request is valid
//        }


//        int i = find(ds, req[0]), j = find(ds, req[1]);
//        bool friends = i == j;
//        if (!friends) {
//            friends = true;
//            for (int k = 0; friends && k < enemies.size(); ++k) {
//                int x = find(ds, enemies[k][0]), y = find(ds, enemies[k][1]);
//                friends = (x != i || y != j) && (x != j || y != i);
//            }
//            if (friends)
//                ds[j] = i;
//        }
//        res.push_back(friends);

// 是 对每个request，检查 每个限制，并且request，限制 都是 uf后的。


//Runtime: 751 ms, faster than 16.23% of C++ online submissions for Process Restricted Friend Requests.
//Memory Usage: 94.4 MB, less than 10.70% of C++ online submissions for Process Restricted Friend Requests.
// uf?
// 请求也是事实
// 把不能成为朋友的 放到 top 上。
    vector<bool> lt2076a(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests)
    {
        unordered_map<int, unordered_set<int>> map2;
        unordered_map<int, unordered_set<int>> map3;        // ...
        for (vector<int>& vi : restrictions)
        {
            map2[vi[0]].insert(vi[1]);
            map2[vi[1]].insert(vi[0]);
        }
        vector<int> uf(n, -1);
        vector<bool> ans(requests.size(), false);
        for (int i = 0; i < requests.size(); ++i)
        {
            int t2 = requests[i][0];
            int t3 = requests[i][1];
            t2 = ufaa(uf, t2);
            t3 = ufaa(uf, t3);
            #ifdef __test
            if (i == 11)
            {
            cout<<t2<<", "<<t3<<endl;
            showVectorInt(uf);
            for (int x : map2[t2])
            {
                cout<<x<<" . . ";
            }
            cout<<endl;
            for (int x : map2[t3])
            {
                cout<<x<<" . . ";
            }
            cout<<endl;
            }
            #endif // __test

            if (t2 != t3 && (map2[t2].find(t3) != end(map2[t2]) || map2[t3].find(t2) != end(map2[t3])))         // 必须2边都检查。
            {
                // not friend;
                continue;
            }
            if (t2 != t3)
            {
                bool cont = false;
                for (int a : map3[t2])
                {
                    if (map2[t3].find(a) != end(map2[t3]))
                    {
                        cont = true;
                        break;
                    }
                }
                if (cont)
                    continue;
                for (int a : map3[t3])
                {
                    if (map2[t2].find(a) != end(map2[t2]))
                    {
                        cont = true;
                        break;
                    }
                }
                if (cont)
                    continue;
            }
            ans[i] = true;
            if (t2 == t3)
            {
                // already friend
                continue;
            }

            // new friend;
            map2[t3].insert(begin(map2[t2]), end(map2[t2]));
            map3[t3].insert(begin(map3[t2]), end(map3[t2]));
            map3[t3].insert(t2);

            uf[t2] = t3;
        }
        return ans;
    }

    int ufaa(vector<int>& uf, int i)
    {
        if (uf[i] == -1)
        {
            return i;
        }
        return ufaa(uf, uf[i]);
    }

};

int main()
{

    LT2076 lt;

//    int n = 3;
//    myvvi v1 = {{1,0}};
////    myvvi v2 = {{0,2},{2,1},{1,0}};
//    myvvi v2 = {{1,2},{0,2}};


//    int n = 5;
//    myvvi v1 = {{0,1},{1,2},{2,3}};
//    myvvi v2 = {{0,4},{1,2},{3,1},{3,4}};

    int n = 8;
    myvvi v1 = {{6,4},{7,5},{2,6},{1,5},{6,7},{6,5},{0,3},{5,4},{0,4},{2,7},{0,2}};
    myvvi v2 = {{6,3},{0,2},{0,5},{0,3},{6,4},{2,4},{1,0},{2,1},{2,5},{6,7},{7,0},

    {3,2},      // false

    {3,5},{2,1},{1,6},{7,4},{6,3},{1,3},{6,5},{3,7},{7,0},{6,5},{0,5},{0,4},{7,5},{7,0},{7,0},{1,3}};

    vector<bool> vb = lt.lt2076a(n, v1, v2);

    for (bool b : vb)
        cout<<b<<", ";

    cout<<endl;
    return 0;
}
