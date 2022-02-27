
#include "../header/myheader.h"

class LT2053
{
public:




//Runtime: 17 ms, faster than 86.96% of C++ online submissions for Kth Distinct String in an Array.
//Memory Usage: 14.7 MB, less than 56.86% of C++ online submissions for Kth Distinct String in an Array.
    string lt2053a(vector<string>& arr, int k)
    {
//        unordered_set<string> set2(begin(arr), end(arr));
        unordered_map<string, int> map2;
        for (string& s : arr)
            map2[s]++;

        int cnt = 1;
        for (string& s : arr)
        {
            if (map2[s] == 1)
            {
                if (cnt++ == k)
                {
                    return s;
                }
            }
        }
        return "";
    }

};

int main()
{

    LT2053 lt;


    return 0;
}
