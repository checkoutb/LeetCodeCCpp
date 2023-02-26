
#include "../../header/myheader.h"

class LT
{
public:




    // g

    int lta(string word1, string word2)
    {
        int sz1 = word1.size();
        int sz2 = word2.size();

        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (word1[i] != word2[j])
                {
                    int t2 = ((i == 0 || j == 0) ? 0 : vvi[i - 1][j - 1]) + 1;
                    if (i != 0)
                        t2 = min(t2, vvi[i - 1][j]);
                }
                else
                {
                    vvi[i][j] = (i == 0 || j == 0) ? 0 : vvi[i - 1][j - 1];
                }
            }
        }

        return vvi[sz1 - 1][sz2 - 1];
    }

};

int main()
{

    LT lt;


    return 0;
}
