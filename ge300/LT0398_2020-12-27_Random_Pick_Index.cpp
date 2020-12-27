
#include "../header/myheader.h"

class LT0398
{
public:



};

// D D

//    vector<int> _nums;
//    Solution(vector<int>& nums) {
//        _nums = nums;
//    }
//
//    int pick(int target) {
//        int n=0, ret=-1, sz=_nums.size();
//        for(int i=0; i<sz; i++){
//            if(_nums[i] != target) continue;
//            n++;
//            if(rand()%n==0) ret=i;
//        }
//        return ret;
//    }

//Obviously, Prob(the 3rd char is picked) = 1/3;
//Prob(the 2nd char is picked) = 1 * 1/2 * 2/3 = 1/3;
//Prob(the 1st char is picked) = 1 * 1/2 * 2/3 = 1/3;
// 以前也有这样的一道题目， 就是 几率要平均。


//        int i=rand()%n;
//        while(ans[i]!=target){
//            i=rand()%n;
//        }
//        return i;


//        const vector<int> &arr = mp[target];
//        int index = rand()%arr.size();
//        return arr[index];


// rand() 真的很快。



//Runtime: 292 ms, faster than 5.08% of C++ online submissions for Random Pick Index.
//Memory Usage: 56.8 MB, less than 5.08% of C++ online submissions for Random Pick Index.
class Solution {
    unordered_map<int, vector<int>> map2;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (map2.find(nums[i]) == map2.end())
                map2[nums[i]].push_back(1);          // index
            map2[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        vector<int>& vi = map2[target];
        int idx = vi[0];
        int ans = vi[idx];
        idx++;
        if (idx == vi.size())
            idx = 1;
        vi[0] = idx;
        return ans;
    }
};


int main()
{
    vector<int> v = {1,2,3,3,3};

    Solution s(v);
    cout<<s.pick(3)<<endl;
    cout<<s.pick(1)<<endl;


    LT0398 lt;


    return 0;
}
