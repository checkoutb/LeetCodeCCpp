
#include "../header/myheader.h"

class LT3244
{
public:


    // D D

        // vector<int> ans;
        // set<int> s;
        // for(int i = 0; i < n; i++) s.insert(i);
        // for(int i = 0; i < queries.size(); i++)
        // {
        //     for(auto j = s.lower_bound(queries[i][0] + 1); j != s.end() && *j < queries[i][1];)
        //     {
        //         auto v = j;
        //         j++;
        //         s.erase(v);
        //     }
        //     ans.push_back(s.size() - 1);
            
        // }
        // return ans;
    // 6!

    
    
    



    // 属于不可重复的代码，下次就不一定能写出来了。。
    

// Runtime
// 331ms
// Beats87.34%
// Analyze Complexity
// Memory
// 107.13MB
// Beats99.46%

    // 6, [[3,5],[2,5]]

    // 如果本次 覆盖了 之前的。
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        int szq = queries.size();
        std::vector<int> vans(szq);
        int ans = n - 1;
        std::vector<std::pair<int, int>> vpii;
        int st, en;
        for (int i = 0; i < szq; ++i) {
            st = queries[i][0], en = queries[i][1];
            std::pair<int, int> p23 = std::make_pair(st, en);
            auto it = std::upper_bound(std::begin(vpii), std::end(vpii), p23, [](const std::pair<int, int>& p1, const std::pair<int, int>& p2){
                return p1.first < p2.first;
            });

            if (it != std::begin(vpii)) {
                it = std::prev(it);
            }
            if (it != std::end(vpii) && it->second >= en && it->first >= en) {
                ans -= en - st - 1;
                vans[i] = ans;
                vpii.insert(it, p23);
                continue;
            }
            if (it != std::end(vpii) && it->second >= en && it->first <= st) {
                vans[i] = ans;
                continue;
            }
            for (; it != std::end(vpii); ) {
                if (it->second > st && it->second <= en) {
                    ans += it->second - it->first - 1;
                    it = vpii.erase(it);
                } else {
                    if (it->first >= en)
                        break;
                    else
                        it++;
                }
            }
            vpii.insert(it, p23);
            ans -= en - st - 1;
            vans[i] = ans;
        }
        
        return vans;
    }


};

int main()
{

    LT3244 lt;


    return 0;
}
