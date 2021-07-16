
#include "../../header/myheader.h"
#include <unordered_set>
#include <functional>
#include <iostream>



class LT
{
public:


// D D


//        sort(nums.begin(),nums.end());
//        for(int i=0;i<n-3;i++)
//        {
//            if(i>0&&nums[i]==nums[i-1]) continue;
//            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
//            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
//            for(int j=i+1;j<n-2;j++)
//            {
//                if(j>i+1&&nums[j]==nums[j-1]) continue;
//                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
//                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
//                int left=j+1,right=n-1;
//                while(left<right){
//                    int sum=nums[left]+nums[right]+nums[i]+nums[j];
//                    if(sum<target) left++;
//                    else if(sum>target) right--;
//                    else{
//                        total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
//                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
//                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
//                    }
//                }
//            }
//        }

// 3个点选好，然后二分搜索。  /   2个点选好，然后二分


// 降为 3sum
// 降为 2sum





// AC  140ms, beats 17%   ..
// 1 <= nums.length <= 200
    vector<vector<int>> lta(vector<int>& nums, int target)
    {
        std::sort(begin(nums), end(nums));          // let nums[j] >= nums[i]
        int sz1 = nums.size();
        unordered_map<int, unordered_set<pair<int, int>, MyKeyHashHasher, MyKeyHashComparator>> map2;         // pair<int, int> 的 hashcode 是多少？
//        unordered_set<vector<int>> set2;      // meiyoude ...
        unordered_set<string> set2;
        vector<vector<int>> ans;
        unordered_map<int, int> map3;
        for (int i : nums)
            map3[i]++;

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                int t2 = nums[i] + nums[j];
                int tar = target - t2;

                if (map2.find(tar) != map2.end())
                {
                    for (pair<int, int> p : map2[tar])
                    {
                        vector<int> vi = {p.first, p.second, nums[i], nums[j]};
                        for (int n : vi)
                        {
                            map3[n]--;
                        }
                        bool can = true;
                        for (int n : vi)
                        {
                            if (map3[n] < 0)
                                can =false;
                            map3[n]++;
                        }
                        if (can)
                        {
                            std::sort(begin(vi), end(vi));
                            string key = to_string(vi[0]) + "," + to_string(vi[1]) + "," + to_string(vi[2]) + "," + to_string(vi[3]);
                            if (set2.find(key) == set2.end())
                            {
                                set2.insert(key);
                                ans.push_back(vi);
                            }
                        }
                    }
                }
                map2[t2].insert(std::make_pair(nums[i], nums[j]));
            }
        }
        return ans;


//        for (int i = 0; i < sz1; ++i)
//        {
//            for (int j = i + 1; j < sz1; ++j)
//            {
//                map2[nums[i] + nums[j]].push_back(std::make_pair(nums[i], nums[j]));
//            }
//        }
//        unordered_set<vector<int>> set2;                // vector<int>'s hashcode ?

//        for (unordered_map<int, unordered_set<pair, pair>>::iterator it = begin(map2); it != end(map2); it++)
//        {
//            int tar = target - it->first;
//            if (map2.)
//        }

//        for (int i = 0; i < sz1; ++i)
//        {
//            for (int j = i + 1; j < sz1; ++j)
//            {
//                int t2 = nums[i] + nums[j];
//                int tar = target - t2;
//                if (map2.find(tar) != map2.end())
//                    for (pair<int, int>& p : map2[tar])
//                    {
//                        vector<int> vi = {p.first, p.second, nums[i], nums[j]};
//                        std::sort(begin(vi), end(vi));
//
//                    }
//            }
//        }
    }

struct MyKeyHashHasher
{
	size_t operator()(const pair<int, int> &k) const noexcept
	{
		return std::hash<int>{}(k.first) + std::hash<int>{}(k.second);
	}
};

struct MyKeyHashComparator
{
	bool operator()(const pair<int, int> &k1, const pair<int, int> &k2) const noexcept
	{
		return k1.first == k2.first && k1.second == k2.second;
	}
};

};

int main()
{
//    myvi v = {1,0,-1,0,-2,2};
//    int tar = 0;

    myvi v = {2,2,2,2,2};
    int tar = 8;

    LT lt;

    vector<vector<int>> vvi = lt.lta(v, tar);

    for (myvi& vi : vvi)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

//    cout<<lt.lta(v, tar)<<endl;

    return 0;
}
