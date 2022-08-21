
#include "../header/myheader.h"

class LT1915
{
public:

    // D D


    //long long state[1 << 10];
    //memset(state, 0, sizeof(state));
    //state[0] = 1;
    //int s = 0;
    //long long ret = 0;
    //for (int i = 0; i < word.size(); ++i) {
    //    s ^= 1 << (word[i] - 'a');
    //    ret += state[s];
    //    for (int k = 0; k < 10; ++k) {
    //        ret += state[s ^ (1 << k)];
    //    }
    //    state[s]++;
    //}
    //return ret;







//Runtime: 1082 ms, faster than 28.92 % of C++ online submissions for Number of Wonderful Substrings.
//Memory Usage : 23.7 MB, less than 5.10 % of C++ online submissions for Number of Wonderful Substrings.
    // 最多一个char  奇数次。
    // 这种是真的，灵感>一切。
    // a-j 有什么用?  < 2048 ?
    long long lt1915a(string word)
    {
        int sz1 = word.size();
        vector<int> vi(sz1);
        vi[0] = 1 << (word[0] - 'a');
        for (int i = 1; i < sz1; ++i)
        {
            vi[i] = vi[i - 1] ^ (1 << (word[i] - 'a'));
        }
        long long ans = 0LL;
        unordered_map<int, int> map2;
        map2[0] = 1;
        for (int i = 0; i < sz1; ++i)
        {
            for (int a = 0; a < 10; ++a)
            {
                int t2 = vi[i] ^ (1 << a);
                if (map2.find(t2) != map2.end())
                {
                    ans += map2[t2];
                }
            }
            if (map2.find(vi[i]) != map2.end())
                ans += map2[vi[i]];

            map2[vi[i]]++;
        }
        return ans;
    }

};

int main()
{

    LT1915 lt;

    //string s = "aba";
    string s = "aabb";
    //string s = "he";


    cout << lt.lt1915a(s) << endl;

    return 0;
}
