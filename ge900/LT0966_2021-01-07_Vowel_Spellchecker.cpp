
#include "../header/myheader.h"

class LT0966
{
public:

// D D


//transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

//std::tolower()


//string lowerKey(string &s) {
//  return accumulate(begin(s), end(s), string("_"), [](string k, char c) { return k + (char)tolower(c); });
//}
//string vowelKey(string &s) {
//  return accumulate(begin(s), end(s), string(""), [](string k, char c) { return k +
//    (char)(string("aeiou").find(tolower(c)) != string::npos ? '*' : tolower(c)); });
//}
//  unordered_map<string, string> words;
//  for (auto w : wordlist) {
//    words.insert({ w, w }), words.insert({ lowerKey(w), w }), words.insert({ vowelKey(w), w });
//  }



//Runtime: 108 ms, faster than 80.65% of C++ online submissions for Vowel Spellchecker.
//Memory Usage: 32.8 MB, less than 94.62% of C++ online submissions for Vowel Spellchecker.
// long == 8byte
//length <= 7
// bitset, but...
    vector<string> lt0966a(vector<string>& wordlist, vector<string>& queries)
    {
        unordered_set<string> set1(begin(wordlist), end(wordlist));
        unordered_map<string, string> map2;     // all lowercase
        unordered_map<string, string> map3;     // all lowercase && vowel -> _
        vector<char> vowels = {'a','o','u','i','e'};
        unordered_set<char> set2(begin(vowels), end(vowels));

        for (string& s : wordlist)
        {
            string val(s);
            for (int i = 0; i < s.size(); ++i)
            {
                s[i] = char (s[i] < 'a' ? s[i] - 'A' + 'a' : s[i]);
            }
            if (map2.find(s) == map2.end())
                map2[s] = val;
            for (int i = 0; i < s.size(); ++i)
            {
                if (set2.count(s[i]))
                {
                    s[i] = '_';
                }
            }
            if (map3.find(s) == map3.end())
                map3[s] = val;
        }

        vector<string> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            string& s = queries[i];
            if (set1.count(s))
            {
                ans[i] = s;
                continue;
            }
            for (int i = 0; i < s.size(); ++i)
                if (s[i] < 'a')
                    s[i] = char (s[i] - 'A' + 'a');
            if (map2.find(s) != map2.end())
            {
                ans[i] = map2[s];
                continue;
            }
            for (int i = 0; i < s.size(); ++i)
                if (set2.find(s[i]) != set2.end())
                    s[i] = '_';
            if (map3.find(s) != map3.end())
                ans[i] = map3[s];
        }
        return ans;
    }


};

int main()
{
    vector<string> vs = {"KiTe","kite","hare","Hare"};
    vector<string> vq = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};

    LT0966 lt;

    vector<string> vv = lt.lt0966a(vs, vq);

    for (string& s : vv)
        cout<<s<<endl;

    return 0;
}
