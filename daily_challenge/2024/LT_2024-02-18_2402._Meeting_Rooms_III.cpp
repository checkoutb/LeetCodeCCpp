
#include "../../header/myheader.h"
#include <format>

class LT
{
public:




// Runtime
// 328ms
// Beats78.29%of users with C++
// Memory
// 108.53MB
// Beats50.54%of users with C++

    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        std::vector<int> vcnt(n, 0);
        std::set<int> unused;
        for (int i = 0; i < n; ++i)
            unused.insert(i);

        std::priority_queue<pair<long long, int>, std::vector<pair<long long, int>>, std::greater<>> priq;

        std::sort(std::begin(meetings), std::end(meetings));

        for (auto& vi : meetings)
        {
            int st{vi[0]}, en{vi[1]};
            while (!priq.empty() && priq.top().first <= st)
            {
                // std::pair<int, int> p = priq.top();
                // unused.insert(p.second);
                unused.insert(priq.top().second);
                priq.pop();
            }
            if (unused.empty()) {
                std::pair<long long, int> p = priq.top();         // same end time, top is the lowest number room
                priq.push(std::make_pair(p.first + en - st, p.second));
                ++vcnt[p.second];
                // std::cout<<std::format("11 st {}, use {}.\n", st, p.second);
                priq.pop();
            } else {
                priq.push(std::make_pair(en, *unused.begin()));
                ++vcnt[*unused.begin()];
#ifdef __test
                // std::cout<<std::format("22 st {}, use {}.\n", st, *unused.begin());
#endif
                unused.erase(unused.begin());
            }
        }

#ifdef __test
        // showVectorInt(vcnt);
#endif

        int ans = 0;
        int mx = -1;
        for (int i = 0; i < n; ++i)
        {
            if (vcnt[i] > mx)
            {
                ans = i;
                mx = vcnt[i];
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;

    int n{3};
    myvvi vv = {{1,20},{2,10},{3,5},{4,9},{6,8}};

    cout<<lt.mostBooked(n, vv);

    return 0;
}
