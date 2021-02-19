
#include "../header/myheader.h"

class LT1673
{
public:

// D D

// stack
// ？ while (当前元素 < top)， pop， 这样 stack 的最下面那个就是 最小的。  deque？

//Use a mono incrasing stack.
//if stack.size() - 1 + A.size() - i >= k, we can pop the stack.

//        vector<int> stack;
//        for (int i = 0; i < A.size(); ++i) {
//            while (!stack.empty() && stack.back() > A[i] && stack.size() - 1 + A.size() - i >= k)
//                stack.pop_back();
//            if (stack.size() < k)
//                stack.push_back(A[i]);
//        }
//        return stack;

//        vector<int> stack;
//        int nums_to_delete = nums.size()-k;
//        for (int i = 0; i < nums.size(); i++) {
//            while (!stack.empty() && nums[i] < stack.back() && nums_to_delete) {
//                stack.pop_back();
//                nums_to_delete--;
//            }
//            stack.push_back(nums[i]);
//        }
//        return vector<int>(stack.begin(), stack.begin()+k);


//Runtime: 324 ms, faster than 15.31% of C++ online submissions for Find the Most Competitive Subsequence.
//Memory Usage: 121.4 MB, less than 7.06% of C++ online submissions for Find the Most Competitive Subsequence.
    vector<int> lt1673c(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<int> ans;
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.first == p2.first ? p1.second > p2.second : p1.first > p2.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> priq(comp);

        for (int i = 0; i < sz1 - k; ++i)
        {
            priq.push(std::make_pair(nums[i], i));
        }
        int st = 0;
        for (int i = sz1 - k; i < sz1; ++i)
        {
            priq.push(std::make_pair(nums[i], i));
            while (priq.top().second < st)
            {
                priq.pop();
            }
            int v = priq.top().first;
            st = priq.top().second;
            ans.push_back(v);
            priq.pop();
        }
        return ans;
    }

// unfinish
// pair<int, index>
// map
    vector<int> lt1673b(vector<int>& nums, int k)
    {
        map<int, vector<int>> map2;
        vector<int> ans;
        int sz1 = nums.size();
        for (int i = 0; i < sz1 - k; ++i)
        {
            map2[nums[i]].push_back(i);
        }
        for (int i = sz1 - k; i < sz1; ++i)
        {
            map2[nums[i]].push_back(i);
            pair<int, vector<int>> pivi = *begin(map2);

            //.......剔除好烦。。

        }
        return ans;
    }


// ... error, 要清空的。。 而且不知道 最小元素 的 下标。
// 感觉好像很简单，就是 前 x个元素 组成 heap。但是看submission， 1*tle + 2*wrong...
// heap 能使用vector的部分元素？neng.
// make_heap 是最大堆。
    vector<int> lt1673a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
//        std::make_heap(begin(nums), begin(nums) + (sz1 - k + 1), [](const& int a, const& int b){ return a < b; });
//        #ifdef __test
//        showVectorInt(nums);
//        #endif // __test
        vector<int> ans;
        vector<int> hp = vector<int>(begin(nums), begin(nums) + (sz1 - k));
        for (int i = sz1 - k; i < sz1; ++i)
        {
            hp.push_back(nums[i]);
            std::make_heap(begin(hp), end(hp), [](const int a, const int b){ return a > b; });
            std::pop_heap(begin(hp), end(hp), [](const int a, const int b){ return a > b; });       // no &
            int mn = hp.back();
            hp.pop_back();
            ans.push_back(mn);
            #ifdef __test
            cout<<i<<", "<<mn<<endl;
            #endif // __test
        }
        return ans;
    }

};

int main()
{
//    myvi v = {3,5,2,6};
//    int k = 2;

    myvi v = {2,4,3,3,5,4,9,6};
    int k = 4;

    LT1673 lt;

    vector<int> vi = lt.lt1673c(v, k);

    showVectorInt(vi);

    return 0;
}
