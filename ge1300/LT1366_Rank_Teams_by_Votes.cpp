
#include "../header/myheader.h"

class LT1366
{
public:




    string lt1366b(vector<string>& votes)
    {
        vector<unordered_map<char, int>> vmap2(votes[0].size());     // rank, team:count
        for (string& s : votes)
        {
            for (int i = 0; i < s.size(); ++i)
            {
                vmap2[i][s[i]]++;
            }
        }
        vector<pair<char, int>> vp(votes[0].size());            // rank, <team, count>

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
                vmap3[i][p.second].insert(p.first);
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

    LT1366 lt;


    return 0;
}
