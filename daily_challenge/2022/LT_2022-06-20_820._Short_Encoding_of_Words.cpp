
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //unordered_set<string_view> S(words.begin(), words.end());
    //for (auto& w : words) {
    //    string_view sv(w);
    //    for (int i = 1; i < w.size(); i++) S.erase(sv.substr(i));
    //}
    //return accumulate(S.begin(), S.end(), 0, [](int total, const string_view& w) { return total + w.size() + 1; });


    // If we reverse all stringsand then sort the vector, then strings will appear as["em", "emit", "bell"].Now we just need to check if the next string starts with the previous one, so we can encode it.




//Runtime: 2619 ms, faster than 5.45 % of C++ online submissions for Short Encoding of Words.
//Memory Usage : 13.7 MB, less than 98.51 % of C++ online submissions for Short Encoding of Words.
    // endWith
    int lta(vector<string>& words)
    {
        int ans = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words.size(); ++j)
            {
#ifdef __test
                cout << "? " << words[i].size() << ", " << words[j].size() << endl;
#endif
                if (i == j || (words[i].size() < words[j].size()))            // [i] = "xx"+[j]
                    continue;
                int szi = words[i].size();
                int szj = words[j].size();
                if (szj == 0)
                    continue;
                for (int k = 1; k <= szj; ++k)
                {
                    if (words[i][szi - k] != words[j][szj - k])
                        goto AAA;
                }
#ifdef __test
                cout << "; " << words[i] << ", " << words[j] << "..." << words[j].size() << endl;
#endif
                words[j] = "";

                AAA:
                continue;
            }
        }
#ifdef __test
        for (string& s : words)
        {
            cout << ". " << s << endl;
        }
#endif
        for (string& s : words)
        {
            if (s.size())
                ans += s.size() + 1;
        }
        return ans;
    }

};

int main()
{

    LT lt;

    //vector<string> vs = { "time","me","bell" };
    vector<string> vs = { "t" };

    cout << lt.lta(vs) << endl;

    return 0;
}
