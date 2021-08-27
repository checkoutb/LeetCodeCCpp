
#include "../header/myheader.h"

class LT1316
{
public:






// 更慢，本地直接卡死。。
    int lt1316b(string text)
    {
        unordered_map<int, unordered_set<string>> map2;
        int sz1 = text.size();
        int ans = 0;
        for (int len = sz1; len > 0; --len)
        {
//            if (len % 2 == 1)
            for (int i = 0; i + len <= sz1; ++i)
            {
                string s(text.begin() + i, text.begin() + i + len);
                string ss = s + s;
                if (map2[s.size()].find(s) == map2[s.size()].end())
                {
                    if (map2.find(ss.size()) != map2.end())
                    {
//                        cout<<ss<<endl;
                        if (map2[ss.size()].find(ss) != map2[ss.size()].end())
                        {
                            ans++;
                        }
                    }
                    map2[s.size()].insert(s);
                }
            }
        }
        return ans;
    }



// tle.
    int lt1316a(string text)
    {
        unordered_map<string, vector<int>> map2;
        int sz1 = text.size();
        int ans = 0;
        for (int len = 1; len <= sz1 / 2; ++len)
        {
            map2.clear();
            for (int i = 0; i + len <= sz1; ++i)
            {
                string s(text.begin() + i, text.begin() + i + len);
                map2[s].push_back(i);
            }
            for (unordered_map<string, vector<int>>::iterator it = map2.begin(); it != map2.end(); it++)
            {
                if (it->second.size() > 1)
                {
                    vector<int>& vi = it->second;            // &
                    for (int i : vi)
                    {
                        int tar = i + len;
                        vector<int>::iterator vit = std::lower_bound(begin(vi), end(vi), tar);
//                        if ((*std::lower_bound(begin(vi), end(vi), tar)) == tar)
                        if (vit != end(vi) && *vit == tar)
                        {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{
//    string s = "abcabcabc";
//    cout<<string(s.begin() + 1, s.begin() + 2);
//    string s = "leetcodeleetcode";
    string s = "tkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnratkfbgwgqvdsbnukcpxlpifuhbvtdxhhhqurotspohiuwhblnra";

    LT1316 lt;

    cout<<lt.lt1316a(s)<<endl;

    return 0;
}
