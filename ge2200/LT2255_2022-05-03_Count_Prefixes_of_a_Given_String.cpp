
#include "../header/myheader.h"

class LT2255
{
public:

// D D

//    return accumulate(words.begin(), words.end(), 0, [&](int sum, string& w) {return sum + (s.compare(0, w.size(), w) == 0);});


//        for(auto i:words)
//            if(!s.find(i))
//                c++;


//        for(auto it: words)
//        {
//            string str = s.substr(0, it.size());
//            if(str == it) count++;
//        }


//return (int) Arrays.stream(words).filter(s::startsWith).count();


//return count_if(begin(words), end(words), [&](const auto &w){ return s.compare(0, w.size(), w) == 0; });



//Runtime: 13 ms, faster than 48.82% of C++ online submissions for Count Prefixes of a Given String.
//Memory Usage: 11.9 MB, less than 68.77% of C++ online submissions for Count Prefixes of a Given String.
// 1 <= words[i].length, s.length <= 10
    int lt2255a(vector<string>& words, string s)
    {
        unordered_map<string, int> map2;
        for (string& w : words)
        {
            if (w[0] == s[0])
            {
                map2[w]++;
            }
        }

        int ans = 0;
        string k;
        for (int i = 0; i < s.size(); ++i)
        {
            k.push_back(s[i]);
            ans += map2[k];
        }
        return ans;
    }

};

int main()
{

    LT2255 lt;


    return 0;
}
