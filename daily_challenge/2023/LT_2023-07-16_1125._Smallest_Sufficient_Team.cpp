
#include "../../header/myheader.h"

class LT
{
public:




// tle

    vector<int> smallestSufficientTeam(
        vector<string>& req_skills,
        vector<vector<string>>& people)
    {
        unordered_map<string, int> map2;
        for (int i = 0; i < req_skills.size(); ++i)
        {
            map2[req_skills[i]] = i;
        }
//        int flg = (1 << req_skills.size()) - 1;
//        vector<vector<int>> vvi(people.size(), 0);
        vector<int> vi(people.size(), 0);
        for (int i = 0; i < people.size(); ++i)
        {
            int t2 = 0;
            for (int j = 0; j < people[i].size(); ++j)
            {
                t2 |= (1 << map2[people[i][j]]);
            }
            vi[i] = t2;
        }
        vector<int> v2(vi.size(), 0);
//        v2[v2.size() - 1] = vi[vi.size() - 1];
//        for (int i = v2.size() - 2; i >= 0; --i)
//        {
//            v2[i] = v2[i + 1] | vi[i];
//        }
        for (int i = v2.size() - 2; i >= 0; --i)
        {
            v2[i] = v2[i + 1] | vi[i + 1];      // [i] store all after [i]
        }
        pair<int, long long> pil = dfsa1(0, (1 << req_skills.size()) -1, vi, v2, 0, 0, 0LL);
        vector<int> ans;

        #ifdef __test
        cout<<pil.first<<" - "<<pil.second<<endl;
        showVectorInt(vi);
        showVectorInt(v2);
        #endif // __test

        for (int i = 0; i < vi.size(); ++i)
        {
            if ((1LL << i) & pil.second)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }

    pair<int, long long> dfsa1(int got, int flg,
        vector<int>& vi, vector<int>& v2, int idx, int cnt, long long chose)
    {
        if (got == flg)
            return std::make_pair(cnt, chose);
        if (idx == vi.size())
            return std::make_pair(INT_MAX, -1);

        if ((got | v2[idx] | vi[idx]) != flg)
            return std::make_pair(INT_MAX, -2);

        std::pair<int, long long> pil = std::make_pair(INT_MAX, -1);
        std::pair<int, long long> pil2 = pil;

        if ((got | vi[idx]) != got)     // new skill
        {
            pil = dfsa1(got | vi[idx], flg, vi, v2, idx + 1, cnt + 1, chose | (1LL << idx));
        }
        if ((v2[idx] | got) == (flg))    // skip
        {
            pil2 = dfsa1(got, flg, vi, v2, idx + 1, cnt, chose);
        }

        #ifdef __test
        cout<<idx<<", "<<pil.first<<" --- "<<pil2.first<<endl;
        #endif // __test

        return pil.first < pil2.first ? pil : pil2;
    }

};

int main()
{

    LT lt;

    vector<string> vs{"java","nodejs","reactjs"};
    vector<vector<string>> vvs{{},{"java"},{},{"nodejs"},{"nodejs","reactjs"}};

    myvi v = lt.smallestSufficientTeam(vs, vvs);

    showVectorInt(v);

    return 0;
}
