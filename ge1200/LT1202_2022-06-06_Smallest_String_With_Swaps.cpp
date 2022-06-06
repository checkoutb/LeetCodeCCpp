
#include "../header/myheader.h"

class LT1202
{
public:

    // D D

    // Map<Integer, PriorityQueue<Character>> map = new HashMap<>();
    // multiset ? priority_queue...

    // map<int, priority_queue<char, vector<char>, greater<char>>> setMap;




//Runtime: 237 ms, faster than 67.84 % of C++ online submissions for Smallest String With Swaps.
//Memory Usage : 48.2 MB, less than 93.93 % of C++ online submissions for Smallest String With Swaps.
    // 应该是 uf 没有压缩 导致的慢。
//Runtime: 1508 ms, faster than 5.00 % of C++ online submissions for Smallest String With Swaps.
//Memory Usage : 48.1 MB, less than 94.28 % of C++ online submissions for Smallest String With Swaps.
    string lt1202a(string s, vector<vector<int>>& pairs)
    {
        int sz1 = s.size();
        vector<int> uf(sz1, -1);
        for (vector<int>& vi : pairs)
        {
            int t2 = ufa(uf, vi[0]);
            int t3 = ufa(uf, vi[1]);
            if (t2 != t3)
            {
                uf[t2] = t3;
                uf[vi[0]] = t3;
                // uf[vi[1]] = t3;          /// 第一次 vi[1] == t3， 死循环。
            }
        }
        unordered_map<int, vector<char>> map2;
        unordered_map<int, int> map3;       // idx

        for (int i = 0; i < sz1; ++i)
        {
            map2[ufa(uf, i)].push_back(s[i]);
        }
        for (unordered_map<int, vector<char>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            sort(begin(it->second), end(it->second));
        }
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = ufa(uf, i);
            s[i] = map2[t2][map3[t2]];
            map3[t2]++;
        }
        return s;
    }

    int ufa(vector<int>& uf, int idx)
    {

        //return (uf[idx] == -1) ? idx : ufa(uf, uf[idx]);

        // uf压缩
        if (uf[idx] == -1)
            return idx;

        int t2 = ufa(uf, uf[idx]);
        uf[idx] = t2;
        return t2;
    }

};

int main()
{

    LT1202 lt;

    string s = "dcab";
    myvvi vv = { {0,3},{1,2} };

    cout << lt.lt1202a(s, vv) << endl;

    return 0;
}
