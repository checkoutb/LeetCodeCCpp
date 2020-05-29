
#include "../header/myheader.h"

class LT0819
{
public:


// D D
// std::tolower..

//        for (auto & c: p) c = isalpha(c) ? tolower(c) : ' ';
//        istringstream iss(p);
//        string w;
//        pair<string, int> res ("", 0);
//        while (iss >> w)
//            if (ban.find(w) == ban.end() && ++count[w] > res.second)
//                res = make_pair(w, count[w]);

// java
// String[] words = p.replaceAll("\\W+" , " ").toLowerCase().split("\\s+");

// python
//        ban = set(banned)
//        words = re.findall(r'\w+', p.lower())
//        return collections.Counter(w for w in words if w not in ban).most_common(1)[0][0]




//Runtime: 4 ms, faster than 99.09% of C++ online submissions for Most Common Word.
//Memory Usage: 7.7 MB, less than 100.00% of C++ online submissions for Most Common Word.
    string lt0819a(string paragraph, vector<string>& banned)
    {
        map<string, int> map2;
        unordered_set<string> set2(std::begin(banned), std::end(banned));
        string word;
        for (char ch : paragraph)
        {
            if (std::isalpha(ch))
            {
                word.push_back(ch > 'Z' ? ch : ch + 'a' - 'A');
            }
            else
            {
                if (!word.empty())
                {
                    if (set2.find(word) == set2.end())
                    {
                        map2[word]++;
                    }
                    word = "";
                }
            }
        }
        if (!word.empty() && !set2.count(word))
            map2[word]++;

        int mxc = 0;
        string ans;
        for (auto p : map2)
        {
            if (p.second > mxc)
            {
                mxc = p.second;
                ans = p.first;
            }
        }
        return ans;
    }

};

int main()
{

//    string p = "Bob hit a ball, the hit BALL flew far after it was hit.";
    string p = "bob,hit..";
    vector<string> ban = {"hit"};

    LT0819 lt;

    cout<<lt.lt0819a(p, ban)<<endl;

    return 0;
}
