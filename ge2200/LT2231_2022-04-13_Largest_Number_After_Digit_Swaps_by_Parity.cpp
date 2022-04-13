
#include "../header/myheader.h"

class LT2231
{
public:

// D D


//        string nums = to_string(num);
//        for(int i=0;i<nums.size();i++){
//            for(int j=i+1;j<nums.size();j++){
//                if((nums[i]&1) == (nums[j]&1) and nums[j] > nums[i]){
//                    swap(nums[i],nums[j]);
//                }
//            }
//        }
//        return stoi(nums);




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Number After Digit Swaps by Parity.
//Memory Usage: 6 MB, less than 82.72% of C++ online submissions for Largest Number After Digit Swaps by Parity.
    int lt2231b(int num)
    {
        vector<vector<int>> vvi(2);
        int t2 = num;
        while (t2 > 0)
        {
            vvi[t2 % 2].push_back(t2 % 10);
            t2 /= 10;
        }
        std::sort(begin(vvi[0]), end(vvi[0]));
        std::sort(begin(vvi[1]), end(vvi[1]));
        int t4 = 1000000000;
        int ans = 0;

        while (t4 > 0)
        {
            if (t4 <= num)
            {
                t2 = (num / t4) % 10;
                ans += vvi[t2 % 2].back() * t4;
                vvi[t2 % 2].pop_back();
            }
            t4 /= 10;
        }
        return ans;
    }


// error, not even/odd index,    it is VALUE...
    int lt2231a(int num)
    {
        string s = std::to_string(num);
        int sz1 = s.size();
        for (int i = 0; i < sz1; i += 2)
        {
            for (int j = i + 2; j < sz1; j += 2)
            {
                if (s[i] < s[j])
                {
                    swap(s[i], s[j]);
                }
            }
        }
        for (int i = 1; i < sz1; i += 2)
        {
            for (int j = i + 2; j < sz1; j += 2)
            {
                if (s[i] < s[j])
                {
                    swap(s[i], s[j]);
                }
            }
        }
        return std::stoi(s);
    }

};

int main()
{

    LT2231 lt;

    int n = 1234;
//    int n = 65875;
//    int n = 247;            // 427

    cout<<lt.lt2231b(n)<<endl;

    return 0;
}
