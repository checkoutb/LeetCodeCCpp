
#include "../header/myheader.h"

class LT1178
{
public:

    // D D


    //int temp = val;
    //int first = s[0] - 'a';
    //int count = 0;
    //while (temp != 0) {
    //    if (((temp >> first) & 1) == 1) {
    //        if (m.find(temp) != m.end()) {
    //            count += m[temp];
    //        }
    //    }
    //    temp = (temp - 1) & val;
    //}



/*


11010100

11010000

11000000

& val, & temp 都一样啊。

不。

1111
1110  -1   1101 & 1111 = 1101       1101&1110=1100


*/


//Runtime: 1335 ms, faster than 16.28 % of C++ online submissions for Number of Valid Words for Each Puzzle.
//Memory Usage : 69.9 MB, less than 86.63 % of C++ online submissions for Number of Valid Words for Each Puzzle.
    // word 包含 puzzle 的 首字母
    // word 中的char 都在 puzzle 中。
    // puzzle 匹配几个word
    // &
    // for for 肯定tle。10^9 ...
    vector<int> lt1178a(vector<string>& words, vector<string>& puzzles)
    {
        map<int, int> map2;       // word-int : cnt

        int cnt2 = 0;
        for (string& s : words)
        {
            cnt2 = 0;
            int t2 = 0;
            for (char ch : s)
            {
                if ((t2 & (1 << (ch - 'a'))) == 0)
                {
                    cnt2++;
                    t2 |= (1 << (ch - 'a'));
                }
                if (cnt2 > 7)
                    break;
            }
            if (cnt2 <= 7)
                map2[t2]++;
        }

#ifdef __test
        for (auto& p : map2)
        {
            cout << p.first << " - " << p.second << endl;
        }
        cout << " ================ " << endl;
#endif

        vector<int> ans(puzzles.size());
        //unordered_map<int, int> map3;
        unordered_map<char, unordered_map<int, int>> map3;      // first char
        for (int i = 0; i < puzzles.size(); ++i)
        {
            int t2 = 0;
            for (char ch : puzzles[i])
                t2 |= (1 << (ch - 'a'));

            if (map3[puzzles[i][0]].find(t2) != map3[puzzles[i][0]].end())
            {
                ans[i] = map3[puzzles[i][0]][t2];
                continue;
            }

#ifdef __test
            cout << t2 << endl;
#endif

            int fst = (1 << (puzzles[i][0] - 'a'));
            map<int, int>::iterator iten = map2.upper_bound(t2);
            int cnt = 0;
            for (map<int, int>::iterator it = begin(map2); it != iten; it++)
            {
#ifdef __test
                cout << it->first << ", " << it->second << " ------ " << fst << ", " << t2 << endl;
#endif
                if ((it->first & fst) != 0 && (it->first | t2) == t2)
                    cnt += it->second;
            }
            ans[i] = cnt;
            map3[puzzles[i][0]][t2] = cnt;
        }

        return ans;
    }

};

int main()
{

    LT1178 lt;

    //vector<string> vs = { "aaaa","asas","able","ability","actt","actor","access" };
    //vector<string> vs2 = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };

    vector<string> vs = { "apple","pleas","please" };
    vector<string> vs2 = { "aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy" };

    myvi v = lt.lt1178a(vs, vs2);

    showVectorInt(v);

    return 0;
}
