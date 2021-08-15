
#include "../../header/myheader.h"

class LT5843
{
public:





// AC
    int lt5843a(vector<string>& patterns, string word)
    {
        int ans = 0;
        for (string& s : patterns)
        {
            if (word.find(s) != std::string::npos)
            {
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT5843 lt;


    return 0;
}
