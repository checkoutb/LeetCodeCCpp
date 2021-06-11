
#include "../header/myheader.h"

class LT1439
{
public:

// D D

// 二分的
//    int kthSmallest(vector<vector<int>>& mat, int k) {
//        int m = mat.size(), n = mat[0].size();
//        int left = m, right = 5000 * m + 1;
//        while(left < right){
//            int t = (left + right) / 2;
//            if(count(mat, m, n, t, 0, 0, k) >= k)
//                right = t;
//            else
//                left = t + 1;
//        }
//        return left;
//    }
//    int count(vector<vector<int>> &mat, int m, int n, int t, int sum, int cur, int k){
//        if(sum > t) return 0;
//        if(cur == m) return 1;
//        int ans = 0;
//        for(int i = 0; i < n; i++){
//            int cnt = count(mat, m, n, t, sum + mat[cur][i], cur + 1, k - ans);
//            if(cnt == 0) break;
//            ans += cnt;
//            if(ans > k) break;
//        }
//        return ans;
//    }
// ？？？


// 靠的hint。不然估计不行。
//Runtime: 20 ms, faster than 95.56% of C++ online submissions for Find the Kth Smallest Sum of a Matrix With Sorted Rows.
//Memory Usage: 15.5 MB, less than 67.14% of C++ online submissions for Find the Kth Smallest Sum of a Matrix With Sorted Rows.
// ... 从mat的每行 各取 一个元素，组成一个数组。
// 最小的是 第一列，最大的是最后一列。
//Save all visited sums and corresponding indexes in a priority queue.
//Then, once you pop the smallest sum so far,
//you can quickly identify the next m candidates for smallest sum by incrementing each row index by 1.
    int lt1439a(vector<vector<int>>& mat, int k)
    {
        auto fun1 = [](const std::pair<int, vector<int>>& p1, const std::pair<int, vector<int>>& p2)
        {
            return p1.first > p2.first;
        };
        priority_queue<std::pair<int, vector<int>>, vector<std::pair<int, vector<int>>>, decltype(fun1)> priq(fun1);
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        int t2 = 0;
        vector<int> vi(sz1 + 1, 0);
        for (int i = 0; i < sz1; ++i)
        {
            t2 += mat[i][0];
        }
        priq.push({t2, vi});
        while (k-- > 1 && !priq.empty())
        {
            pair<int, vector<int>> fnt = priq.top();
            priq.pop();
            t2 = fnt.first;
            #ifdef __test
            cout<<t2<<endl;
            showVectorInt(fnt.second);
            cout<<endl;
            #endif // __test
            for (int i = fnt.second[fnt.second.size() - 1]; i < fnt.second.size() - 1; ++i)
            {
                if (fnt.second[i] < sz2 - 1)
                {
                    vi = fnt.second;
                    vi[i]++;
                    vi[vi.size() - 1] = i;
                    int t4 = t2 - mat[i][fnt.second[i]] + mat[i][fnt.second[i] + 1];
                    #ifdef __test
                    cout<<"push : "<<t4<<endl;
                    showVectorInt(vi);
                    cout<<" - - - "<<endl;
                    #endif // __test
                    priq.push(std::make_pair(t4, vi));
                }
//                priq.push(std::make_pair())
            }
        }

        return priq.top().first;
    }

};

int main()
{
//    myvvi vv = {{1,3,11},{2,4,6}};
//    int k = 5;
//    int k = 9;

//    myvvi vv = {{1,10,10},{1,4,5},{2,3,6}};
//    int k = 7;

    myvvi vv = {{1,1,10},{2,2,9}};
    int k = 7;


    LT1439 lt;

    cout<<lt.lt1439a(vv, k)<<endl;

    return 0;
}
