
#include "../header/myheader.h"

class LT2099
{
public:

// D D

//        vector<pair<int,int>> v;
//        for(int i=0;i<nums.size();i++){
//            v.push_back({nums[i],i});
//        }
//        sort(v.begin(),v.end(),greater<pair<int,int> > ());


//    vector<int> v(begin(nums), end(nums)), res;
//    nth_element(begin(v), begin(v) + k - 1, end(v), greater<int>());
//    int cnt = count(begin(v), begin(v) + k, v[k - 1]);
//    for (int i = 0; i < nums.size(); ++i)
//        if (nums[i] > v[k - 1] || (nums[i] == v[k - 1] && --cnt >= 0))
//            res.push_back(nums[i]);



//Runtime: 14 ms, faster than 38.09% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.
//Memory Usage: 10.2 MB, less than 7.16% of C++ online submissions for Find Subsequence of Length K With the Largest Sum.
    vector<int> maxSubsequence(vector<int>& nums, int k)
    {
        map<int, vector<int>> map2;
        for (int i = 0; i < nums.size(); i++)
        {
            map2[nums[i]].push_back(i);
        }
        vector<int> vi;
        for (map<int, vector<int>>::reverse_iterator rit = rbegin(map2); rit != rend(map2); rit++)
        {
            for (int i = 0; i < rit->second.size() && vi.size() < k; i++)
            {
                vi.push_back(rit->second[i]);
            }
        }
        std::sort(begin(vi), end(vi));
        for (int i = 0; i < vi.size(); i++)
        {
            vi[i] = nums[vi[i]];
        }
        return vi;
    }

};

int main()
{

    LT2099 lt;

//    myvi v = {2,1,3,3};
//    int k = 2;

//    myvi v = {-1,-2,3,4};
//    int k = 3;

    myvi v = {3,4,3,3};
    int k = 3;

    myvi v2 = lt.maxSubsequence(v, k);

    showVectorInt(v2);

    return 0;
}
