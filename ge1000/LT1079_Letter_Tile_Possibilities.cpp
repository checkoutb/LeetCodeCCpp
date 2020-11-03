
#include "../header/myheader.h"

class LT1079
{
public:


// D D

//    int numTilePossibilities(string tiles) {
//        int cnt[26]={0};for(auto c: tiles) cnt[c-'A']++;
//        return solve(cnt);
//    }
//    int solve(int cnt[])
//    {
//        int sum =0;
//        for(int i=0;i<26;i++)
//        {
//            if(cnt[i]>0)
//            {
//                sum++;
//                cnt[i]--;
//                sum += solve(cnt);
//                cnt[i]++;
//            }
//        }
//        return sum;
//    }
// 这里是对cnt的 操作，所以不可能重复的， 就是 在任何一次递归中，可能选取的字符是不重复的A-Z，最多26次。


//Runtime: 112 ms, faster than 34.96% of C++ online submissions for Letter Tile Possibilities.
//Memory Usage: 13.6 MB, less than 5.14% of C++ online submissions for Letter Tile Possibilities.
    int lt1079a(string tiles)
    {
        int ans = 0;
        unordered_map<char, int> map2;
        for (char ch : tiles)
        {
            map2[ch]++;
        }
        unordered_set<string> set2;
        for (int i = 0; i < tiles.size(); i++)
        {
            dfsa1(map2, set2, i + 1, "");
            ans += set2.size();
            set2.clear();
        }
        return ans;
    }

    void dfsa1(unordered_map<char, int>& map2, unordered_set<string>& set2, int len, string s)
    {
        if (len == s.size())
        {
            set2.insert(s);
        }
        for (auto& p : map2)
        {
            if (p.second != 0)
            {
                p.second--;
                dfsa1(map2, set2, len, s + p.first);
                p.second++;
            }
        }
    }

};

int main()
{

    string s = "V";

    LT1079 lt;

    cout<<lt.lt1079a(s)<<endl;

    return 0;
}
