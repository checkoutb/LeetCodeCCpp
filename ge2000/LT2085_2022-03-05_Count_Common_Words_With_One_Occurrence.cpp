
#include "../header/myheader.h"

class LT2085
{
public:

// D D

//    unordered_map<string, int> m;
//    for (auto &w : words1)
//        ++m[w];
//    for (auto &w : words2)
//        if (m[w] < 2)
//            --m[w];
//    return count_if(begin(m), end(m), [](const auto &p){ return p.second == 0; });


//Runtime: 49 ms, faster than 55.87% of C++ online submissions for Count Common Words With One Occurrence.
//Memory Usage: 19.9 MB, less than 29.29% of C++ online submissions for Count Common Words With One Occurrence.
    int lt2085a(vector<string>& words1, vector<string>& words2)
    {
        unordered_map<string, int> map2;
        unordered_map<string, int> map3;
        for (string s : words1)
            map2[s]++;
        for (string s : words2)
            map3[s]++;

        int ans = 0;
        for (unordered_map<string, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            if (it->second == 1 && map3[it->first] == 1)
            {
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT2085 lt;

    vector<string> vs = {"asdasd"};
    string s = vs[0];
    string& s2 = vs[0];

    cout<<&s<<" - "<<&s2<<", "<<&vs<<", "<<(&vs[0])<<endl;      // &s2 == &vs[0]  != &s


    return 0;
}
