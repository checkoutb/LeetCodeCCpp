
#include "../header/myheader.h"

class LT1792
{
public:

// D D

//    auto profit = [&](double pass, double total) {
//        return (pass + 1) / (total + 1) - pass / total;
//    };
//    double total = 0;
//    priority_queue<pair<double, array<int, 2>>> pq;
//    for (auto &c : classes) {
//        total += (double) c[0] / c[1];
//        pq.push({profit(c[0], c[1]), {c[0], c[1]}});
//    }
//    while (extraStudents--) {
//        auto [added_profit, c] = pq.top(); pq.pop();
//        total += added_profit;
//        pq.push({profit(c[0] + 1, c[1] + 1), {c[0] + 1, c[1] + 1}});
//    }
//    return total / classes.size();
// .. profit


//    def maxAverageRatio(self, A, k):
//        h = [(a / b - (a + 1) / (b + 1), a, b) for a, b in A]
//        heapify(h)
//        while k:
//            v, a, b = heapq.heappop(h)
//            a, b = a + 1, b + 1
//            heapq.heappush(h, (-(a + 1) / (b + 1) + a / b, a, b))
//            k -= 1
//        return sum(a / b for v, a, b in h) / len(h)

// 确实，直接减就是了，不必通分。



// 好像没有足够的样本，就是100%。
//Runtime: 880 ms, faster than 100.00% of C++ online submissions for Maximum Average Pass Ratio.
//Memory Usage: 93.6 MB, less than 100.00% of C++ online submissions for Maximum Average Pass Ratio.
// 阅读理解。。
// 感觉是  优秀的人 优先 到 人数少的班级里， 这样能获得 最大的平均通过率。
// [[2,4],[3,9],[4,5],[2,10]] 4
// 4/4 4/9 5/5 2/10
// 。。 加入后， 班级人数也会上升。
// 3/5 - 2/4        0.1
// 4/10 - 3/9       0.066666
// 5/6 - 4/5        0.03333
// 3/11 - 2/10      0.0727272
// (a+1)/(b+1) - (a/b)
// ((a+1)*b - a(b+1)) / (b*(b+1))
// (ab + b - ab - a) / (b*b + b)
// (b - a) / (b*b + b)      2/4  2/20
// 3/9  6/(90)
// heap / priority_queue
    double lt1792a(vector<vector<int>>& classes, int extraStudents)
    {
        priority_queue<pair<double, pair<int, int>>> priq;
        for (vector<int>& vi : classes)
        {
            priq.push({1.0 * (vi[1] - vi[0]) / (1.0 * vi[1] * vi[1] + vi[1]), {vi[0], vi[1]}});
        }
        for (int i = 0; i < extraStudents; ++i)
        {
            pair<double, pair<int, int>> p = priq.top();
            priq.pop();
            #ifdef __test
            cout<<", "<<p.first<<endl;
            #endif // __test
            int a = p.second.first + 1;
            int b = p.second.second + 1;
            priq.push({1.0 * (b - a) / (1.0 * b * b + b), {a, b}});
        }
        double ans = 0;
        int sz1 = priq.size();
        while (!priq.empty())
        {
            pair<double, pair<int, int>> p = priq.top();
            ans += 1.0 * p.second.first / p.second.second;
            priq.pop();
        }
        return ans / sz1;
    }

};

int main()
{

//    myvvi vv = {{1,2},{3,5},{2,2}};
//    int e = 2;

    myvvi vv = {{2,4},{3,9},{4,5},{2,10}};
    int e = 4;

    LT1792 lt;

    cout<<lt.lt1792a(vv, e);

    return 0;
}
