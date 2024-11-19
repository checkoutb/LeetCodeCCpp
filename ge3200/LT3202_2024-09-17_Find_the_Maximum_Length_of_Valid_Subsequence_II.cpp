
#include "../header/myheader.h"

class LT3202
{
public:


    // D D

        // vector<vector<int>> diff(k, vector<int>(k,0));
        // int maxi=0;

        // for(int i=0;i<n;i++){
        //     int mod = nums[i]%k;

        //     for(int j=0;j<k;j++){
        //         diff[mod][j] = max(diff[mod][j], 1+diff[j][mod]);
        //         maxi=max(maxi, diff[mod][j]);
        //     }
        // }





        // vector<vector<int>> positions(k);
        // for (int i = 0; i < nums.size(); ++i)
        //     positions[nums[i] % k].push_back(i);
        // sort(begin(positions), end(positions),
        //      [](const auto& a, const auto& b) { return a.size() > b.size(); });
        // int maxLength = max(2, (int)positions[0].size());

        // for (int i = 0; i < k; ++i) {
        //     for (int j = i + 1;
        //          j < k && positions[i].size() + positions[j].size() > maxLength;
        //          ++j) {
        //         int length_ij = (positions[i][0] < positions[j][0]) +
        //                         (positions[i].back() < positions[j].back());
        //         for (int k = 0, l = 0;
        //              k < positions[i].size() && l < positions[j].size(); ++k) {
        //             if (positions[j][l] < positions[i][k])
        //                 length_ij += 2;
        //             while (l < positions[j].size() &&
        //                    positions[j][l] < positions[i][k])
        //                 ++l;
        //         }
        //         maxLength = max(maxLength, length_ij);
        //     }
        // }











    

// Runtime
// 2538ms
// Beats5.03%
// Analyze Complexity
// Memory
// 218.29MB
// Beats10.44%
    

    // %k
    // sub[0] % k == sub[2] % k,  [1] % k == [3] % k
    // len < 10^3    1000
    //       [0] % k == [1] % k
    // for for for   must will tle
    //
    // map[last ele % k][last last] = max length
    // no, map[last last][last],  last last is now ele
    // last last == -1
    int maximumLength(vector<int>& nums, int k) {
        std::map<int, std::map<int, int>> mmap2;
        int sz1 = nums.size();
        int ans = 0;
        for (int i = 0; i < sz1; ++i) {
            int t2 = nums[i] % k;

            for (std::pair<const int, int>& p : mmap2[t2]) { // <last, length>
                mmap2[p.first][t2] = std::max(mmap2[p.first][t2], p.second + 1);
            }

            for (std::pair<const int, int>& p : mmap2[-1]) {
                mmap2[p.first][t2] = std::max(mmap2[p.first][t2], 2);
            }

            mmap2[-1][t2] = 1;
        }
        for (std::pair<const int, std::map<int, int>>& p : mmap2) {
            for (std::pair<const int, int>& p2 : p.second) {
                ans = std::max(ans, p2.second);
            }
        }
        return ans;
    }



    int fun2(vector<int>& nums, int k) {

        // [last last][last]
        std::vector<std::vector<int>> vvi(1001, std::vector<int>(1000, 0)); // 1001 == map[-1]

        int sz1 = nums.size();
        int ans = 0;

        for (int i = 0; i < sz1; ++i) {
            int t2 = nums[i] % k;

            for (int lst : vvi[t2]) {
                // ...... it need more time.. .... no...
            }
        }
    }

    
};

int main()
{

    LT3202 lt;


    return 0;
}
