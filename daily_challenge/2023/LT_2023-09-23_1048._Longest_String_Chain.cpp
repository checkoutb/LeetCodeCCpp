
#include "../../header/myheader.h"

class LT
{
public:

// D D

    // bool isPredecessor(string &wordI, string &wordJ) {
    //     int i = 0, j = 0;
    //     while (i < wordI.size()) {
    //         if (j < wordJ.size() && wordI[i] == wordJ[j]) {
    //             i++;
    //             j++;
    //         } else i++;
    //     }
    //     return i == wordI.size() && j == wordJ.size();
    // }


// Runtime62 ms
// Beats
// 94.72%
// Memory16.9 MB
// Beats
// 51.56%
    int longestStrChain(vector<string>& words)
    {
        sort(begin(words), end(words), [](string& s1, string& s2){
            return s1.size() < s2.size();
        });
        #ifdef __test
        for (string& s : words)
        {
            cout<<s<<endl;
        }
        #endif
        map<string, int> map2;
        // int t2 = words[0].size();
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i].size() == words[0].size())
            {
                map2[words[i]] = 1;
            }
            else
            {
                int t2 = 0;
                map2[words[i]] = 1;
                for (int j = 0; j < words[i].size(); ++j)
                {
                    string s2 = words[i].substr(0, j) + words[i].substr(j + 1, std::string::npos);
                    if (map2.find(s2) != map2.end())
                    {
                        map2[words[i]] = max(map2[words[i]], map2[s2] + 1);
                    }
                }
            }
            // t2 = words[i].size();
        }
        int ans = 0;
        for (auto &[_, cnt] : map2)
        {
            #ifdef __test
            cout<<_<<", "<<cnt<<endl;
            #endif
            ans = max(ans, cnt);
        }
        return ans;
    }


};

int main()
{

    LT lt;

    vector<string> vs = {"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};

    cout<<lt.longestStrChain(vs)<<endl;

    return 0;
}
