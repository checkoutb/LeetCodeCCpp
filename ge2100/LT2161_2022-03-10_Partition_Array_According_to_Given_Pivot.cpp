
#include "../header/myheader.h"

class LT2161
{
public:

// D D


//        vector<int> ans;
//        for(int i=0;i<nums.size();i++){
//            if(nums[i]<pivot){ans.push_back(nums[i]);}
//        }
//         for(int i=0;i<nums.size();i++){
//            if(nums[i]==pivot){ans.push_back(nums[i]);}
//        }
//         for(int i=0;i<nums.size();i++){
//            if(nums[i]>pivot){ans.push_back(nums[i]);}
//        }
// ...

//        int left = 0, right = size(nums) - count_if(cbegin(nums), cend(nums), [&pivot](const auto& x) { return x > pivot; });


//	vector<int> res(n.size());
//    int lo = 0, eq = count_if(begin(n), end(n), [&](int n) { return n < p; }),
//        hi = eq + count(begin(n), end(n), p);
//    for (int n : n)
//        res[n < p ? lo++ : n == p ? eq++ : hi++] = n;
//	return res;


//vector<int> pivotArray(vector<int>& n, int p) {
//    stable_partition(stable_partition(begin(n), end(n), [&](int n){ return n < p; }), end(n), [&](int n){ return n == p; });
//    return n;
//}


//    copy_if(begin(n), end(n), back_inserter(res), [&](int n){ return n < p; });
//    copy_if(begin(n), end(n), back_inserter(res), [&](int n){ return n == p; });
//    copy_if(begin(n), end(n), back_inserter(res), [&](int n){ return n > p; });

// ... stl 恐怖如斯。。。



//Runtime: 393 ms, faster than 14.76% of C++ online submissions for Partition Array According to Given Pivot.
//Memory Usage: 123.3 MB, less than 90.49% of C++ online submissions for Partition Array According to Given Pivot.
// 保持先后顺序。
    vector<int> lt2161a(vector<int>& nums, int pivot)
    {
        vector<int> ans(nums.size());
        int cnteq = 0;
        int cntle = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == pivot)
                cnteq++;
            else if (nums[i] < pivot)
                cntle++;
        }
        for (int i = 0; i < cnteq; ++i)
            ans[i + cntle] = pivot;
        int stle = 0;
        int stgt = cntle + cnteq;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
                ans[stle++] = nums[i];
            else if (nums[i] > pivot)
                ans[stgt++] = nums[i];
        }
        return ans;
    }

};

int main()
{

    LT2161 lt;


    return 0;
}
