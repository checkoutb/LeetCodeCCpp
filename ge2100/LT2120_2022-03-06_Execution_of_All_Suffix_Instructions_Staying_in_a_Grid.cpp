
#include "../header/myheader.h"

class LT2120
{
public:





//Runtime: 54 ms, faster than 50.16% of C++ online submissions for Execution of All Suffix Instructions Staying in a Grid.
//Memory Usage: 10.2 MB, less than 73.91% of C++ online submissions for Execution of All Suffix Instructions Staying in a Grid.
//
    vector<int> lt2120a(int n, vector<int>& startPos, string s)
    {
        vector<int> ans(s.size());
        int len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int ii = startPos[0], jj = startPos[1];
            len = 0;
            for (int j = i; j < s.size(); ++j)
            {
                switch(s[j])
                {
                case 'L':
                    --jj;
                    break;
                case 'R':
                    ++jj;
                    break;
                case 'U':
                    --ii;
                    break;
                case 'D':
                    ++ii;
                    break;
                }
                if (ii < 0 || jj < 0 || ii == n || jj == n)
                {
                    break;
                }
                else
                {
                    len++;
                }
            }
            ans[i] = len;
        }
        return ans;
    }

};

int main()
{

    LT2120 lt;


    return 0;
}
