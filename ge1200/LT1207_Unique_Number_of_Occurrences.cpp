
#include "../header/myheader.h"

class LT1207
{
public:


// D D

//  short m[2001] = {}, s[1001] = {};
//  for (auto n : arr) ++m[n + 1000];
//  for (auto i = 0; i < 2001; ++i)
//      if (m[i] && ++s[m[i]] > 1) return false;
//  return true;
// mi 是长度。
// s[mi] 是 set。 如果>1，就说明 长度 重复。

//Runtime: 4 ms, faster than 91.24% of C++ online submissions for Unique Number of Occurrences.
//Memory Usage: 8.5 MB, less than 46.18% of C++ online submissions for Unique Number of Occurrences.
    bool lt1207a(vector<int>& arr)
    {
        unordered_map<int, int> map2;
        for (int i : arr)
        {
            map2[i]++;
        }
        unordered_set<int> set2;
        for (auto& p : map2)
        {
            if (set2.find(p.second) != set2.end())
            {
                return false;
            }
            set2.insert(p.second);
        }
        return true;
    }

};

int main()
{

//    vector<int> v = {1,2,2,1,1,3};
//    vector<int> v = {1,2};
    vector<int> v = {-3,0,1,-3,1,1,1,-3,10,0};

    LT1207 lt;

    cout<<lt.lt1207a(v)<<endl;

    return 0;
}
