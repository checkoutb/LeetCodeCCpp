
#include "../header/myheader.h"

class LT0833
{
public:



// D D
// 降序排列，这样substr + tar + substr 就不会影响到后续操作。


//Runtime: 8 ms, faster than 70.46% of C++ online submissions for Find And Replace in String.
//Memory Usage: 10.9 MB, less than 22.22% of C++ online submissions for Find And Replace in String.
    string lt0833a(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets)
    {
        if (indexes.empty())
            return S;

        vector<tuple<int, string, string>> v2;
        for (int i = 0; i < indexes.size(); i++)
        {
            v2.emplace_back(make_tuple(indexes[i], sources[i], targets[i]));
        }
        sort(begin(v2), end(v2), [](tuple<int, string, string>& t1, tuple<int, string, string>& t2){ return std::get<0>(t1) < std::get<0>(t2); });

        #ifdef __test
        for (auto p : v2)
            cout<<std::get<0>(p)<<", "<<std::get<1>(p)<<", "<<std::get<2>(p)<<endl;
        #endif // __test

        string ans;
        int v2i = 0;
        int idx = std::get<0>(v2[v2i]);
        for (int i = 0; i < S.size(); i++)
        {
            if (i < idx)
            {
                ans.push_back(S[i]);
            }
            else
            {
                tuple<int, string, string>& tup2 = v2[v2i];
                string sou = std::get<1>(tup2);
                string tar = std::get<2>(tup2);

                if (S.substr(i, sou.size()) == sou)
                    ans.append(tar);
                else
                    ans.append(S.substr(i, sou.size()));

                i += sou.size() - 1;
                v2i++;
                if (v2i >= v2.size())           // append && return.
                    idx = 1111;
                else
                    idx = std::get<0>(v2[v2i]);
            }
        }
        return ans;
    }

};

int main()
{

    string s = "abcd";
    vector<int> vi = {0,2};
//    vector<string> vs = {"a","cd"};
    vector<string> vs = {"ab","ec"};
    vector<string> vt = {"eee","ffff"};

    LT0833 lt;

    cout<<lt.lt0833a(s,vi,vs,vt)<<endl;


    return 0;
}
