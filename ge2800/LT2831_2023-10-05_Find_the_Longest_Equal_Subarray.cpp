
#include "../header/myheader.h"

class LT2831
{
public:

// D D

//        int ans = 0;
//        unordered_map<int,int> mpp;
//        int i = 0, j = 0;
//        while(j < nums.size()){
//            mpp[nums[j]]++;
//
//            ans = max(ans,mpp[nums[j]]);
//
//            while(j-i+1 > ans+k && i<j){
//                mpp[nums[i]]--;
//                i++;
//            }
//            j++;
//        }
//        return ans;


//        int maxf = 0, i = 0, n = A.size();
//        unordered_map<int, int> count;
//        for (int j = 0; j < n; j++) {
//            maxf = max(maxf, ++count[A[j]]);
//            if (j - i + 1 - maxf > k)
//                --count[A[i++]];
//        }
//        return maxf;



//Runtime519 ms
//Beats
//33.93%
//Memory230.1 MB
//Beats
//35.26%

// 1 1 2 2 1 1 2 1
// 1 : 0 1 4 5 7
// 5 > 0 + 3-0 + 2
// 7 > 0 + 4-0 + 2
// 7 > 1 + 4-1 + 2
// 7 > 4 + 4-2 + 2
    int longestEqualSubarray(vector<int>& nums, int k)
    {
        map<int, vector<int>> map2;
        for (int i = 0; i < nums.size(); ++i)
        {
            map2[nums[i]].push_back(i);
        }
        int ans = 0;
        for (auto& [_, vi] : map2)
        {
            int st = 0;
            for (int i = 0; i < vi.size(); ++i)
            {
                while (vi[i] > vi[st] + (i - st) + k)
                {
                    ++st;
                }
                ans = max(ans, i - st + 1);
            }
        }
        return ans;
    }

};

int main()
{

    LT2831 lt;


    return 0;
}
