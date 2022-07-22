
#include "../header/myheader.h"

class LT1307
{
public:








    bool lt1307b(vector<string>& words, string result)
    {
        unordered_set<char> no0;
        for (string& s : words)
        {
            no0.insert(s[0]);
            if (result.size() < s.size())
                return false;
        }
        no0.insert(result[0]);
        
    }

    bool eqb1()
    {

    }


    // 10^7
    bool lt1307a(vector<string>& words, string result)
    {
        unordered_set<char> no0;
        for (string& s : words)
        {
            no0.insert(s[0]);
            if (result.size() < s.size())
                return false;
        }
        no0.insert(result[0]);

        vector<int> ad(26, -1);
        vector<char> da(10, '-');
        return dfsa1(words, result, 1, 0, 1, ad, da, 0, 0);
    }

    bool dfsa1(vector<string>& vs, string& result, int len, int idx, int pw, vector<int>& ad, vector<char>& da, int val, int val2, unordered_set<char>& no0)       // alpha - digit, digit - alpha
    {
        bool done = true;
        for (int i = 0; i < vs.size(); ++i)
        {
            if (i < idx)
            {
                if (vi[i].size() > len)
                    done = false;
                continue;
            }

            if (vs[i].size() >= len)
            {
                done = false;

                char ch = vs[i][vi[i].size() - len];
                if (ad[ch] != -1)
                {
                    val += ad[ch] * pw;
                }
                else
                {
                    int j = 0;
                    if (no0.find(ch) != no0.end())
                        j++;
                    for (; j < da.size(); ++j)
                    {
                        if (da[j] == '-')
                        {
                            da[j] = ch;
                            ad[ch] = j;
                            
                            if (dfsa1(vs, result, len, i, pw, ad, da, val, val2, no0))
                                return true;

                            da[j] = '-';
                            ad[ch] = -1;
                        }
                    }
                }
            }
        }

        int t2 = val % (pw * 10) / pw;

        if (ad[result[result.size() - idx]] == -1)
        {
            if (da[t2] == '-')
            {
                da[t2] = result[result.size() - idx];
            }
            else
            {
                //if ()
            }
        }
        

        if (done)
        {

            return val == val2;
        }

        pw *= 10;


        if (dfsa1(vs, result, len + 1, 0, pw, ad, da, val, val2, no0))
            return true;

        return false;
    }

};

int main()
{

    LT1307 lt;


    return 0;
}
