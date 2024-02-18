
#include "../../header/myheader.h"

class LT
{
public:





//     Runtime30 ms
// Beats
// 98.93%
// Memory15.6 MB
// Beats
// 91.73%
    int countCharacters(vector<string>& words, string chars)
    {
        std::vector<int> vi(26, 0), v2(26, 0);
        for (char ch : chars)
            ++vi[ch - 'a'];

        int ans = 0;
        for (string& s : words)
        {
            std::fill(std::begin(v2), std::end(v2), 0);
            for (char ch : s)
            {
                if (v2[ch - 'a']++ == vi[ch - 'a'])
                    goto AAA;
            }
            ans += s.size();

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
