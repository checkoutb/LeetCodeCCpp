
#include "../../header/myheader.h"

class LT5713
{
public:




// AC
// mk_cpp 传入一个 234进去。
    int lt5713(string word)
    {
        unordered_set<string> set2;
        for (int i = 0; i < word.size(); ++i)
        {
            if (std::isdigit(word[i]))
            {
                string s;
//                for (int j = i; std::isDigit(word[j]); ++j)
//                {
//                    if (word[j] == '0' && s.empty())
//                        continue;
//                    s.push_back(word[j]);
//                }
                for (; std::isdigit(word[i]); ++i)
                {
                    if (word[i] == '0' && s.empty())
                        continue;
                    s.push_back(word[i]);
                }
                if (set2.find(s) == set2.end())
                    set2.insert(s);
            }
        }
        #ifdef __test
        for (string s : set2)
            cout<<s<<", ";
        cout<<endl;
        #endif // __test
        return set2.size();
    }

};

int main()
{
//    string s = "a123bc34d8ef34";
//    string s = "leet1234code234";
    string s = "a1b01c001";

    LT5713 lt;

    cout<<lt.lt5713(s)<<endl;

    return 0;
}
