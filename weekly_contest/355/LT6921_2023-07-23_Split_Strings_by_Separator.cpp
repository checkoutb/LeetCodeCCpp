
#include "../../header/myheader.h"

class LT6921
{
public:




// AC 。。。 example testcase 跑了好几遍。。。
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> vs;

        for (string& s : words)
        {
            int st = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == separator)
                {
                    if (st < i)
                    {
                        vs.push_back(s.substr(st, i - st));
                    }
                    st = i + 1;
                }
            }
            if (st != s.size())
                vs.push_back(s.substr(st));
        }

        return vs;
    }

};

int main()
{

    LT6921 lt;


    return 0;
}
