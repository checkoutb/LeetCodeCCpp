
//#include "../header/myheader.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class LT0826
{
public:


// D D
//works.emplace_back(make_pair(difficulty[i], profit[i]));

// map<diff, max(profit)>
//    for (auto &p : m) // update the BST to reflect the maximum profit for a job
//        mx = p.second = max(p.second, mx);
//    for (int w : worker) // look up the BST to find the maximum profit for each worker
//        res += prev(m.upper_bound(w))->second;
// 第一个for是把p.second 设置为 之前+现在 出现过的 最大值。
// 。。。 prev.....

// 看来是无序的，detail 中组成pair，然后sort，快多了。
//Runtime: 444 ms, faster than 5.10% of C++ online submissions for Most Profit Assigning Work.
//Memory Usage: 35.2 MB, less than 9.09% of C++ online submissions for Most Profit Assigning Work.
// 贪婪？  youxu?
    int lt0826a(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        for (int i = 1; i < difficulty.size(); i++)
        {
            int j = i - 1;
            int vi = difficulty[i];
            int pi = profit[i];
            while (j >= 0 && difficulty[j] > vi)
            {
                difficulty[j + 1] = difficulty[j];
                profit[j + 1] = profit[j];
                j--;
            }
            j++;
            difficulty[j] = vi;
            profit[j] = pi;
        }
        int ans = 0;
        std::sort(worker.begin(), worker.end());
        int diffIndex = 0;
        int mxc = 0;

        #ifdef __test
        for_each(begin(difficulty), end(difficulty), fun_cout); cout<<endl;
        for_each(begin(profit), end(profit), fun_cout); cout<<endl;
        for_each(begin(worker), end(worker), fun_cout); cout<<endl;
        #endif // __test

        for (int i = 0; i < worker.size(); i++)
        {
            int abi = worker[i];
            while (diffIndex < difficulty.size() && difficulty[diffIndex] <= abi)
            {
                mxc = std::max(mxc, profit[diffIndex]);
                diffIndex++;
            }
            ans += mxc;
        }
        return ans;
    }

};

int main()
{

//    vector<int> diff = {6,8,10,2,4};
//    vector<int> pro = {30,40,50,10,20};
//    vector<int> w = {6,7,4,5};


    vector<int> diff = {13,37,58};
    vector<int> pro = {4,90,96};
    vector<int> w = {34,73,45};



    LT0826 lt;

    std::cout<<lt.lt0826a(diff, pro, w)<<std::endl;

    return 0;
}
