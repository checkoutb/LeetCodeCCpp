
#include "../header/myheader.h"

class LT0387
{
public:



// details

//        int arr[26] = {};
//
//        for(char ch:s){
//            ++arr[ch-'a'];
//        }
//
//        for(char ch:s){
//            if(arr[ch-'a']==1) return s.find(ch);
//        }
//
//        return -1;
// 遍历一遍s，记录下char的个数。
// 再遍历一遍s，如果这个char在s中的个数是1，说明这个就是第一个唯一char。返回下标。


// discuss
//        unordered_map<char, pair<int, int>> m;
//        int idx = s.size();
//        for (int i = 0; i < s.size(); i++) {
//            m[s[i]].first++;
//            m[s[i]].second = i;
//        }
//        for (auto &p : m) {
//            if (p.second.first == 1) idx = min(idx, p.second.second);
//        }
//        return idx == s.size() ? -1 : idx;
// <char, pair<int, int>>


//    Runtime: 36 ms, faster than 94.80% of C++ online submissions for First Unique Character in a String.
//    Memory Usage: 12.7 MB, less than 89.15% of C++ online submissions for First Unique Character in a String.

    int lt0387a(string s)
    {
        int sz1 = 26;
        int arr[sz1];
        for (int i = 0; i < sz1; i++)
        {
            arr[i] = -1;    // 可能s中不存在。
        }
        for (int j = 0, sz2 = s.size(); j < sz2; j++)
        {
            char c = s[j];
            int i = c - 'a';
            if (arr[i] < -1)
            {
                continue;
            }
            if (arr[i] == -1)
            {
                arr[i] = j;     // 下标
            }
            else
            {
                arr[i] = -2;
            }
        }
        int result = -1;
        for (int i : arr)
        {
            if (i >= 0)
            {
                result = result == -1 ? i : min(result, i);
            }
        }
        return result;
    }
};

int main()
{
    string s = "loveleetcode";

    LT0387 lt;
    cout<<lt.lt0387a(s)<<endl;

    return 0;
}
