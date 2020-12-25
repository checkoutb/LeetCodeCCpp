
#include "../header/myheader.h"

class LT0378
{
public:

// D D

// 二分。。

//        while (l < h) {
//            int m = (l+h) / 2, cnt = 0;
//
//            for (int i = 0; i < n; ++i) {
//                cnt += count(matrix[i], m);
//            }
//            if (cnt >= k) {
//                h = m;
//            } else {
//                l = m+1;
//            }
//        }

//            for(int i = 0; i<n; i++){
//                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
//            }
// 可以 distance.


//        vector<int> vec;
//        for (auto i : matrix)
//            for (int j : i)
//                vec.push_back(j);
//        nth_element(vec.begin(), vec.begin()+k-1, vec.end());
//        return vec[k-1];
// nth_element。。。



//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/85170/O(n)-from-paper.-Yes-O(rows).
// md taichangle.


//Tuple


// 不知道 myvvi 来判断有没有被访问，会不会好点。 不，估计差距在 priority_queue上。
//Runtime: 176 ms, faster than 11.88% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
//Memory Usage: 19.3 MB, less than 8.55% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
    int lt0378a(vector<vector<int>>& matrix, int k)
    {
        auto fun = [&matrix](const pair<int, int>& p1, const pair<int, int>& p2){ return matrix[p1.first][p1.second] > matrix[p2.first][p2.second]; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(fun)> que1(fun);
        unordered_set<int> set2;
        que1.push({0, 0});
        int sz1 = matrix.size();
        while (k-- > 1)
        {
            pair<int, int> pii = que1.top();
            que1.pop();
            int i = pii.first;
            int j = pii.second;
            #ifdef __test
            cout<<"pop: "<<matrix[i][j]<<endl;
            #endif // __test
            if (i + 1 < sz1 && (set2.find((i + 1) * (sz1 + 10) + j) == set2.end()))
            {
                que1.push({i + 1, j});
                set2.insert((i + 1) * (sz1 + 10) + j);
            }
            if (j + 1 < sz1 && (set2.find((i) * (sz1 + 10) + j + 1) == set2.end()))
            {
                que1.push({i, j + 1});
                set2.insert(j + 1 + (i) * (sz1 + 10));
            }
        }
        pair<int, int> pii = que1.top();
        return matrix[pii.first][pii.second];
    }

};

int main()
{
//    myvvi vv = {{1, 5, 9},{10, 11, 13},{12, 13, 15}};
//    int k{13};

    myvvi vv = {{1,3,5},{6,7,12},{11,14,14}};
    int k{6};       // 11

    LT0378 lt;

    cout<<lt.lt0378a(vv, k);

    return 0;
}
