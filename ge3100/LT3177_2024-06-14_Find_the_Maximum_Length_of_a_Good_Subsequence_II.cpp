
#include "../header/myheader.h"

class LT3177
{
public:


    // D D

    // dp[i][a] = max(dp[i][a] + 1, res[i - 1] + 1)

        // vector<unordered_map<int, int>> dp(k + 1);
        // vector<int> res(k + 1);
        // for (int a : A) {
        //     for (int i = k; i >= 0; --i) {
        //         dp[i][a] = max(dp[i][a] + 1, (i > 0 ? res[i - 1] + 1 : 0));
        //         res[i] = max(res[i], dp[i][a]);
        //     }
        // }
        // return res[k];
    

// Runtime
// 2273ms
// Beats5.03%
// Analyze Complexity
// Memory
// 458.63MB
// Beats5.13%    
    // [num][diff][mx len]
    //      [diff][mx len]
    int maximumLength(vector<int>& nums, int k) {
        std::map<int, std::map<int, int>> map2;
        std::map<int, int> map3;
        map3[0] = 1;
        map2[nums[0]][0] = 1;
        int sz1 = nums.size();
        for (int i = 1; i < sz1; ++i) {
            int t2 = nums[i];
            std::map<int, int> map4;

            for (auto& p : map3) {
                if (p.first + 1 <= k)
                    if (map3.contains(p.first + 1))
                        map4[p.first + 1] = std::max(map3[p.first + 1], p.second + 1);
                    else
                        map4[p.first + 1] = p.second + 1;
            }
            map4[0] = map3[0]; // ..
            
            if (map2.contains(t2)) {
                for (std::map<int, int>::iterator it = begin(map2[t2]); it != end(map2[t2]); it++) {
                    it->second++;
                    map4[it->first] = max(map4[it->first], it->second);
                    //map3[it->first] = max(map3[it->first], it->second);
                }
            } else {
                map2[t2][0] = 1;
                //map2[t2] = map4;
            }
            for (auto& p : map3) {
                if (p.first + 1 <= k) {
                    map2[t2][p.first + 1] = max(map2[t2][p.first + 1], p.second + 1);
                }
            }

            #ifdef __test
            for (auto& p : map4) {
                std::cout<<p.first<<" : "<<p.second<<std::endl;
            }
            std::cout<<" ------------- \n";

            std::cout<<" now "<<t2<<", "<<i<<std::endl;
            for (auto& p : map2[t2]) {
                std::cout<<p.first<<" - "<<p.second<<std::endl;
            }
            std::cout<<" ========\n";
            #endif
            
            swap(map3, map4);
        }

        #ifdef __test
        for (auto& p : map3) {
            std::cout<<p.first<<", "<<p.second<<std::endl;
        }
        for (auto& p : map2) {
            std::cout<<p.first<<": \n";
            for (auto& p2 : p.second) {
                std::cout<<"  "<<p2.first<<", "<<p2.second<<std::endl;
            }
        }
        #endif
        
        int ans = 0;
        for (auto& p : map3) {
            ans = max(ans, p.second);
        }
        return ans;
    }


    // tle
    // k 50
    // 最大长度，可能的 结尾
    int maximumLength__tle(vector<int>& nums, int k) {
        int sz1 = nums.size();
        int sz2 = k + 1;
        std::vector<std::map<int, std::set<int>>> vms(sz2);
        vms[0][1].insert(nums[0]); // [diff][length].insert(last element)
        int t2;
        for (int i = 1; i < sz1; ++i) {
            t2 = nums[i];
            //vms[0][1].insert(t2); // .
            for (int k = sz2 - 1; k >= 0; --k) {
                if (vms[k].empty())
                    continue;
                for (std::map<int, std::set<int>>::reverse_iterator it = rbegin(vms[k]); it != rend(vms[k]); it++) {
                    int len = it->first;
                    if (it->second.contains(t2)) {
                        vms[k][len+1].insert(t2);
                        break;
                    } else {
                        if (k + 1 < sz2)
                            vms[k + 1][len + 1].insert(t2);
                    }
                }
            }
            vms[0][1].insert(t2);
        }
        int ans = 0;
        for (int i = 0; i < sz2; ++i) {
            if (!vms[i].empty())
                ans = std::max(ans, vms[i].rbegin()->first);
        }
        return ans;
    }


};

int main()
{

    LT3177 lt;
    // myvi v {23,30,30};
    // int k {1};

    myvi v {2,3,2,2};
    int k {2};
    
    std::cout<<lt.maximumLength(v, k)<<std::endl;
    
    return 0;
}
