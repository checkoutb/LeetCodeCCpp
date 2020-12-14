
#include "../header/myheader.h"

class LT1678
{
public:

// D D




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Goal Parser Interpretation.
//Memory Usage: 6.4 MB, less than 40.64% of C++ online submissions for Goal Parser Interpretation.
    string lt1678a(string command)
    {
        string ans;
        for (int i = 0; i < command.size(); ++i)
        {
            if (command[i] == 'G')
                ans += 'G';
            else if (command[i] == '(')
            {
                if (command[i + 1] == ')')
                {
                    i++;
                    ans += 'o';
                }
                else
                {
                    i += 3;
                    ans += "al";
                }
            }
        }
        return ans;
    }

};

int main()
{
    vector<string> vs = {"G()(al)","G()()()()(al)","(al)G(al)()()G"};

    LT1678 lt;

    for (string& s : vs)
        cout<<lt.lt1678a(s)<<endl;

    return 0;
}
