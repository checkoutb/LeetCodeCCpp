
#include "../header/myheader.h"

class LT2115
{
public:

// D D

//Kahn's algo



// 或许应该 dfs + memo
//Runtime: 1060 ms, faster than 17.29% of C++ online submissions for Find All Possible Recipes from Given Supplies.
//Memory Usage: 93.3 MB, less than 98.18% of C++ online submissions for Find All Possible Recipes from Given Supplies.
// ... topologic.......
    vector<string> lt2115a(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        vector<string> ans;
        unordered_set<string> set2(begin(supplies), end(supplies));
        bool chg = true;
        while (chg)
        {
            chg = false;

            for (int i = 0; i < recipes.size(); ++i)
            {
                if (recipes[i] == "")
                    continue;
                for (string& s : ingredients[i])
                {
                    if (set2.find(s) == set2.end())
                        goto AAA;
                }
                ans.push_back(recipes[i]);
                chg = true;
                set2.insert(recipes[i]);
                recipes[i] = "";
                AAA:
                continue;
            }
        }

        return ans;
    }

};

int main()
{

    LT2115 lt;


    return 0;
}
