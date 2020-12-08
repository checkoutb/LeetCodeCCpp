
#include "../header/myheader.h"

class LT1615
{
public:

// D D

//        for (auto& e : roads) {
//            graph[e[0]][e[1]] = 1;
//            graph[e[1]][e[0]] = 1;
//            cnt[e[0]]++;
//            cnt[e[1]]++;
//        }
//
//        int ans = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++) {
//                if (i != j) {
//                    ans = max(ans, cnt[i] + cnt[j] - graph[i][j]);
//                }
//            }
//        }



// https://leetcode.com/problems/maximal-network-rank/discuss/889001/C%2B%2B-quadratic...-linearithmic...-linear!




//Runtime: 196 ms, faster than 58.75% of C++ online submissions for Maximal Network Rank.
//Memory Usage: 40.1 MB, less than 21.64% of C++ online submissions for Maximal Network Rank.
    int lt1615a(int n, vector<vector<int>>& roads)
    {
        if (roads.empty())
            return 0;
        unordered_map<int, unordered_set<int>> map2;
        for (vector<int>& vi : roads)
        {
            map2[vi[0]].insert(vi[1]);
            map2[vi[1]].insert(vi[0]);
        }
        map<int, vector<int>> map3;     // count : city
        for (auto& p : map2)
        {
            map3[p.second.size()].push_back(p.first);
        }
        vector<int> vi = map3.rbegin()->second;
        int cnt = map3.rbegin()->first;
        if (vi.size() > 1)
        {
            for (int i = 0; i < vi.size(); ++i)
            {
                for (int j = i + 1; j < vi.size(); ++j)
                {
                    if (map2[vi[i]].find(vi[j]) == map2[vi[i]].end())
                    {
                        return cnt * 2;
                    }
                }
            }
            return cnt * 2 - 1;
        }
        int cnt2 = (++map3.rbegin())->first;
        vector<int> vi2 = (++map3.rbegin())->second;
        for (int i = 0; i < vi.size(); ++i)
        {
            for (int j = 0; j < vi2.size(); ++j)
            {
                if (map2[vi[i]].find(vi2[j]) == map2[vi[i]].end())
                {
                    return cnt + cnt2;
                }
            }
        }
        return cnt + cnt2 - 1;


//        unordered_map<int, unordered_set<int>> map2;        // city : neighbours
//        for (vector<int>& vi : roads)
//        {
//            map2[vi[0]].insert(vi[1]);
//            map2[vi[1]].insert(vi[0]);
//        }

//        int arr[n];
//        memset(arr, 0, sizeof(arr));
//        for (vector<int>& vi : roads)
//        {
//            arr[vi[0]]++;
//            arr[vi[1]]++;
//        }
////        std::partial_sort()
////        std::nth_element();
////        int* ip = std::max_element(begin(arr), end(arr));
//        int* ip = max_element(arr, arr + n);
//        int t1 = ip - arr;
//        *ip = -1;
//        ip = max_element(arr, arr + n);
//        int t2 = ip - arr;
//
//
//        return -1;
    }

};

int main()
{
//    int n{4};
//    myvvi vv = {{0,1},{0,3},{1,2},{1,3}};

//    int n{5};
//    myvvi vv = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};

    int n{8};
    myvvi vv = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};

    LT1615 lt;

    cout<<lt.lt1615a(n,vv);

    return 0;
}
