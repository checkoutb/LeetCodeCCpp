
#include "../header/myheader.h"

class LT2185
{
public:

// D D

//            for(std::decay_t<decltype(plen)> i = 0; i < plen; ++i){
//                if(pref[i] != word[i]){
//                    --count;
//                    break;
//                }
//            }

//ans += w.find(pref) == 0;


//    return count_if(begin(ws), end(ws), [&](const string &w){
//       return w.compare(0, pref.size(), pref) == 0;
//    });

//    return count_if(begin(ws), end(ws), [&](const string &w){
//       return w.starts_with(pref);
//    });

//return (int)Stream.of(words).filter(w -> w.startsWith(pref)).count();


//Runtime: 16 ms, faster than 49.18% of C++ online submissions for Counting Words With a Given Prefix.
//Memory Usage: 9.8 MB, less than 98.39% of C++ online submissions for Counting Words With a Given Prefix.
// startswith
    int lt2185a(vector<string>& words, string pref)
    {
        int ans = 0;
        for (string& s : words)
        {
            if (s.size() < pref.size())
                continue;
            for (int i = 0; i < pref.size(); i++)
            {
                if (pref[i] != s[i])
                    goto AAA;
            }
            ++ans;
            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    LT2185 lt;


    return 0;
}
