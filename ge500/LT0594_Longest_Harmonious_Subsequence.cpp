
#include "../header/myheader.h"

class LT0594
{
public:


// D D
//        if (map.containsKey(key + 1)) {
//            result = Math.max(result, map.get(key + 1) + map.get(key));
//        }


// sort ye keyi.



//Runtime: 200 ms, faster than 65.57% of C++ online submissions for Longest Harmonious Subsequence.
//Memory Usage: 42 MB, less than 22.95% of C++ online submissions for Longest Harmonious Subsequence.
// this or sort&&iterate?
    int lt0594a(vector<int>& nums)
    {
        map<int, int> map2;
        for (int n : nums)
        {
            map2[n]++;
        }
        int ans = 0;
        int len1 = 0;
        int len2 = 0;
        int lastNum = -10;
        int nowNum = 0;
        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            nowNum = it->first;
            len1 = it->second;
            if (nowNum == lastNum + 1)
                ans = max(ans, len1 + len2);
            len2 = len1;
            lastNum = nowNum;
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {1,2,3,4};

    LT0594 lt;

    cout<<lt.lt0594a(v)<<endl;

    return 0;
}
