
#include "../header/myheader.h"

class LT1366
{
public:

// D D

//        int tab[26][26];
//        memset(tab, 0, sizeof(tab));
//
//        for (int i = 0; i < N; i++)
//            for (int j = 0; j < M; j++)
//                tab[i][A[j][i] - 'A']++;
// 代替map


//        vector<vector<int>> count(26, vector<int>(27));
//        for (char& c: votes[0])
//            count[c - 'A'][26] = c;
//
//        for (string& vote: votes)
//            for (int i = 0; i < vote.length(); ++i)
//                --count[vote[i] - 'A'][i];
//        sort(count.begin(), count.end());
//        string res;
//        for (int i = 0; i < votes[0].length(); ++i)
//            res += count[i][26];
// vector<vector<int>>, 默认的sort 就是 按 vector<int> 来升序的。。



//Runtime: 28 ms, faster than 38.62% of C++ online submissions for Rank Teams by Votes.
//Memory Usage: 11 MB, less than 66.74% of C++ online submissions for Rank Teams by Votes.
// 数据结构。
    string lt1366b(vector<string>& votes)
    {
        string ans;
        unordered_map<char, vector<int>> map2;
        for (char ch : votes[0])
            map2[ch] = vector<int>(votes[0].size());
        for (string& s : votes)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                map2[s[i]][i]++;
            }
        }
        vector<char> vc(begin(votes[0]), end(votes[0]));
        std::sort(begin(vc), end(vc), [&map2](const char& c1, const char& c2) {
            vector<int>& v1 = map2[c1];
            vector<int>& v2 = map2[c2];
            for (int i = 0; i < v1.size(); ++i)
            {
                if (v1[i] != v2[i])
                {
                    return v1[i] > v2[i];
                }
            }
            return c1 < c2;
        });
        ans = string(begin(vc), end(vc));
        return ans;
    }


// ...
    string lt1366a(vector<string>& votes)
    {
        vector<unordered_map<char, int>> vmap2(votes[0].size());     // rank, team:count
        for (string& s : votes)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                vmap2[i][s[i]]++;
            }
        }
        vector<map<int, vector<char>>> vmap3(votes[0].size());      // rank, count:{teams};
        for (int i = 0; i < vmap2.size(); ++i)
        {
            for (auto& p : vmap2[i])
            {
                vmap3[i][p.second].push_back(p.first);
            }
        }
//        unordered_set<char> set2(begin(votes[0], end(votes[0])));
        string ans;
//        while (!set2.empty())
//        {
//
//        }
        while (ans.size() < votes.size())
        {

            for (int i = 0; i < votes[0].size(); ++i)
            {
                map<int, vector<char>>& map3 = vmap3[i];

            }
        }
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"ABC","ACB","ABC","ACB","ACB"};
//    vector<string> vs = {"WXYZ","XYZW"};
//    vector<string> vs = {"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
//    vector<string> vs = {"BCA","CAB","CBA","ABC","ACB","BAC"};
    vector<string> vs = {"M","M","M"};

    LT1366 lt;

    cout<<lt.lt1366b(vs);

    return 0;
}
