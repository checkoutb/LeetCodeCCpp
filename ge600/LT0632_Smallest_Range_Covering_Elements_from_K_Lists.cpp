
#include "../header/myheader.h"

class LT0632
{
public:


// D D

// std::sort(items.begin(), items.end(), [](std::pair<int, int>& a, std::pair<int, int>& b) { return a.first < b.first; });
// 替代all


//        vector<int> cur_index(nums.size(), 1);
//        multiset<pair<int, int>> heap;
//        for (int i = 0; i < nums.size(); i++) {
//            heap.insert({nums[i][0], i});
//        }
//        vector<int> result = {heap.begin()->first, heap.rbegin()->first};
//        while (true) {
//            auto p = heap.begin();
//            int i = p->second;
//            if (cur_index[i] == nums[i].size())
//                break;
//            heap.erase(heap.begin());
//            heap.insert({nums[i][cur_index[i]++], i});
//            int diff = heap.rbegin()->first - heap.begin()->first;
//            if (diff < result[1] - result[0]) {
//                result[0] = heap.begin()->first;
//                result[1] = heap.rbegin()->first;
//            }
//        }
//        return result;
// multiset -> heap ...



//        int best_left=-1e6, best_right=1e6, left, right;
//        for (int i=0; i<nums.size(); i++)
//        {
//            for (int j=0; j<nums[i].size(); j++)
//            {
//                left = nums[i][j];
//                right = left;
//                // cout<<i<<" "<<j<<" "<<left<<endl;
//                for (int k=0; k<nums.size(); k++)
//                {
//                    if (k == i)
//                        continue;
//                    if (left > nums[k].back())
//                    {
//                        right = INT_MAX;
//                        continue;
//                    }
//                    int pos = lower_bound(nums[k].begin(), nums[k].end(), left) - nums[k].begin();
//                    // cout<<k<<" "<<pos<<"-"<<nums[k][pos]<<endl;
//                    right = max(right, nums[k][pos]);
//                    if (right-left >= best_right-best_left) // THIS LINE CHANGED EVERYTHING !!!
//                    {
//                        break;
//                    }
//                }
//                if (right-left < best_right-best_left)
//                {
//                    best_right = right;
//                    best_left = left;
//                }
//            }
//        }
//        return {best_left, best_right};


//Runtime: 80 ms, faster than 100.00% of C++ online submissions for Smallest Range Covering Elements from K Lists.
//Memory Usage: 16 MB, less than 43.67% of C++ online submissions for Smallest Range Covering Elements from K Lists.
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        vector<int> all;
        int i = 0;
        int ans = INT_MAX;
        vector<int> ansv(2, 0);
        for (vector<int>& v : nums)
        {
            for (int n : v)
            {
                all.push_back(n * 10000 + (n < 0 ? -1 : 1) * i);            // -15 -> -149995...
            }
            i++;
        }
        std::sort(begin(all), end(all));            // or use min-heap...
        vector<int> v3(nums.size(), 0);

        #ifdef __test
        for_each(begin(all), end(all), fun_cout);
        cout<<endl;
        #endif // __test

        int not0 = nums.size();
        int j = 0;
        for (int i = 0; i < all.size(); i++)
        {
            if (v3[abs(all[i] % 10000)] == 0)
            {
                not0--;
            }
            v3[abs(all[i] % 10000)]++;
            if (not0 == 0)      // manzu hou, meici dou hui chengli a.
            {
                for (; ; j++)
                {
                    if (v3[abs(all[j] % 10000)] == 1)          // v3[(all[j] % 10000 + 10000) % 10000] == 1     刚开始，构造all时，i没有乘以符号位，所以会出现 -9995.不过，all构造对了后，只会出现-5。
                    {
                        if (all[i] / 10000 - all[j] / 10000 < ans)
                        {
                            ansv[0] = all[j] / 10000;
                            ansv[1] = all[i] / 10000;
                            ans = all[i] / 10000 - all[j] / 10000;
                        }
                        break;
                    }
                    v3[abs(all[j] % 10000)]--;
                }
            }
        }
        return ansv;
    }

};

int main()
{

//    vector<vector<int>> vv = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
//    vector<vector<int>> vv = {{1,2,3},{1,2,3},{1,2,3}};

//    vector<vector<int>> vv = {{10,10},{11,11}};

//    vector<vector<int>> vv = {{1},{2},{3},{7}};

//    vector<vector<int>> vv = {{-1,-4},{7},{-2,4}};

    vector<vector<int>> vv = {{0,26,29,29,42,42,44},{-8,48,59,61,62,65,69,70},{7,37,44,45},{-5,42,62,64,70,71,72},{14,16,17,17,17,18},{-15,60,70,73,74,75,76},{15,15,15,16}};

    LT0632 lt;

    vector<int> v = lt.smallestRange(vv);

    cout<<v[0]<<", "<<v[1]<<endl;

    return 0;
}
