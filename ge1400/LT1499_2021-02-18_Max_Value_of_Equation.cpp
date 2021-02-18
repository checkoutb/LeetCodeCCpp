
#include "../header/myheader.h"

class LT1499
{
public:

// Discuss
//yi + yj + |xi - xj| == yi + yj + xi - xj when xi > xj;
//that is you just need to find the max yj - xj where xi - xj <= k;
// Mono deque


// max-heap , priority_queue
//        for(int i=1;i<pts.size();i++) {
//            int sum = pts[i][0]+pts[i][1];
//            while(!pq.empty() && pts[i][0]-pq.top().second>k) pq.pop();
//            if(!pq.empty())ans = max(ans,sum+pq.top().first);
//            pq.push({pts[i][1]-pts[i][0],pts[i][0]});
//            cout<<i<<' '<<ans<<'\n';
//        }


//    deque<int> d;
//    for (int j = 0; j < p.size(); ++j) {
//        while (!d.empty() && p[j][0] - p[d.front()][0] > k)
//            d.pop_front();
//        if (!d.empty())
//            res = max(res, p[d.front()][1] - p[d.front()][0] + p[j][1] + p[j][0]);
//        while (!d.empty() && p[d.back()][1] - p[d.back()][0] < p[j][1] - p[j][0])
//            d.pop_back();
//        d.push_back(j);
//    }
//    return res;

//


// 感觉是 y轴最大， 前x个中，按y轴排列，
// que.front < xi , pop.     set.remove. bu, multiset.remove是移除全部， map<y, x>
// ymx - k
// 但是 k=2*10^8 的话，依然要 全部扫一遍的。 按照y轴排序？ 但是不知道什么情况算结束，依然会全扫一遍。
    int lt1499b(vector<vector<int>>& points, int k)
    {

    }


// 63 / 65   tle
//0 <= k <= 2 * 10^8  感觉必然tle啊。。。
// 想起来，之前 有个方法可以 O(n) 来处理 这种类似 sliding window， 但忘记了。。 queue?  这个好像不行，因为没有办法确定 值
// 这个也不算 滑动窗口，感觉 滑动窗口 通常是 处理 无序的东西？
    int lt1499a(vector<vector<int>>& points, int k)
    {
        int ans = INT_MIN;
        for (int i = 0; i < points.size(); ++i)
        {
            int xi = points[i][0];
            int yi = points[i][1];
            for (int j = i + 1; j < points.size(); ++j)
            {
                if (points[j][0] > xi + k)
                    goto AAA;
                ans = max(ans, points[j][0] - xi + yi + points[j][1]);
            }

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{1,3},{2,0},{5,10},{6,-10}};
//    int k{1};

    myvvi vv = {{0,0},{3,0},{9,2}};
    int k{3};

    LT1499 lt;

    cout<<lt.lt1499a(vv, k)<<endl;

    return 0;
}
