
#include "../header/myheader.h"

class LT3171
{
public:

    // D D

        // set<int> prev;
        // int n = nums.size();
        // int minV = INT_MAX;
        // for (int i = 0; i < n; i++){
        //     set<int> next;
        //     for (int v : prev)
        //         next.insert(v & nums[i]);
        //     next.insert(nums[i]);

        //     for (int v : next)
        //         minV = min(minV, abs(k - v));

        //     prev = next;
        // }
        // return minV;
    





// Runtime
// 1174ms
// Beats30.10%
// Analyze Complexity
// Memory
// 237.71MB
// Beats34.33%
    int minimumDifference(vector<int>& nums, int k) {
        int sz1 = nums.size();

        for (int i = sz1 - 1; i > 0; --i) {
            if (nums[i] == nums[i - 1]) {
                nums.erase(nums.begin() + i);
            }
        }
        sz1 = nums.size();
        
        //vector<int> vi(30, 0);
        //int en = -1;
        int sum2 = 0;
        std::vector<std::vector<int>> vvi(sz1, vector<int>(30, 0));
        int t2;
        for (int i = 0; i < sz1; ++i) {
            t2 = nums[i];
            for (int j = 0; j < 30; ++j) {
                if ((t2 & (1 << j)) != 0) {
                    vvi[i][j] = 1;
                }
            }
            if (i > 0) {
                for (int j = 0; j < 30; ++j) {
                    vvi[i][j] += vvi[i - 1][j];
                }
            }
        }

        #ifdef __test
        for (int i = 0; i < sz1; ++i) {
            for (int j = 0; j < 4; ++j) {
                std::cout<<vvi[i][j]<<", ";
            }
            std::cout<<std::endl;
        }
        #endif
        
        int ans = INT_MAX;
        int st, en, t3, t4;
        for (int i = 0; i < sz1; ++i) {
            st = i, en = sz1 - 1;
            t3 = t4 = INT_MAX;
            while (st <= en) {
                int md = (st + en) / 2;
                t2 = 0;
                for (int j = 0; j < 30; ++j) {
                    if ((vvi[md][j] - (i == 0 ? 0 : vvi[i - 1][j])) > 0) {
                        t2 |= (1 << j);
                    }
                }

                #ifdef __test
                std::cout<<"  "<<st<<", "<<en<<", "<<md<<", "<<t2<<std::endl;
                #endif
                
                if (t2 > k) {
                    t4 = t2;
                    en = md - 1;
                } else {
                    t3 = t2;
                    st = md + 1;
                }
            }
            #ifdef __test
            std::cout<<i<<", "<<t3<<", "<<t4<<", "<<st<<", "<<en<<std::endl;
            #endif
            ans = std::min(ans, std::abs(t3 - k));
            ans = std::min(ans, std::abs(t4 - k));
            // en = sz1 - 1;
            // while (st <= en) {
            //     int md = (st + en) / 2;
            //     t2 = 0;
            //     for (int j = 0; j < 30; ++j) {
            //         if ((vvi[md][j] - (i == 0 ? 0 : vvi[i - 1][j])) > 0) {
            //             t2 |= (1 << j);
            //         }
            //     }
            //     if (t2 > k) {
                    
            //     }
            // }
            
        }
        return ans;
    }


};

int main()
{

    LT3171 lt;

    // myvi v {1,2,4,5};
    // int k {3};

    myvi v {6};
    int k {2};
    
    std::cout<<lt.minimumDifference(v, k)<<std::endl;

    return 0;
}
