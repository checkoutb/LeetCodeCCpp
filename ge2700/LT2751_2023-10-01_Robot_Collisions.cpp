
#include "../header/myheader.h"

class LT2751
{
public:

// D D



//Runtime289 ms
//Beats
//57.27%
//Memory192.6 MB
//Beats
//85.27%

    // health - 1
    // remove lower
    // same remove both
    // only remain
    //
    // same direct:
    // diff dir:
    // stk
    vector<int> survivedRobotsHealths(
        vector<int>& positions,
        vector<int>& healths,
        string directions)
    {
        int sz1 = positions.size();
//        vector<int> ans;
//        stack<int> stkl;
        vector<pair<int, int>> ans;
        stack<pair<int, int>> stkl; // <pos, heal>
        vector<int> vi(sz1);
        std::iota(begin(vi), end(vi), 0);
        std::sort(begin(vi), end(vi), [&positions](const int a, const int b){
            return positions[a] < positions[b];
        });

        char dir = 'a';
        int heal = 0;
//        int tp;
        pair<int, int> tp;
        for (int i : vi)
        {
            dir = directions[i];
            heal = healths[i];

            if (dir == 'R')
            {
                stkl.push(std::make_pair(i, heal));
            }
            else
            {
                while (!stkl.empty())
                {
                    tp = stkl.top();
                    stkl.pop();

                    if (heal > tp.second)
                    {
                        --heal;
                    }
                    else if (heal == tp.second)
                    {
                        heal = -1;
                        break;
                    }
                    else
                    {
                        stkl.push(std::make_pair(tp.first, tp.second - 1));
                        heal = -1;
                        break;
                    }
                }
                if (heal > 0)
                {
                    ans.push_back(std::make_pair(i, heal));
                }
            }
        }
        #ifdef __test
//        showVectorInt(ans);
        #endif // __test
        if (!stkl.empty())
        {
            ans.resize(ans.size() + stkl.size());
            int idx = ans.size() - 1;
            while (!stkl.empty())
            {
                ans[idx--] = stkl.top();
                stkl.pop();
            }
        }

        vector<int> ans2(ans.size());

        sort(begin(ans), end(ans));

        for (int i = 0; i < ans.size(); ++i)
        {
            ans2[i] = ans[i].second;
        }

        return ans2;
    }

};

int main()
{

    LT2751 lt;

    myvi v = {3,5,2,6};
    myvi v2 = {10,10,15,12};
    string s = "RLRL";

//    myvi v = {1,2,5,6};
//    myvi v2 = {1,1,2,2};
//    string s = "RLRL";

//    myvi v = {4,3,2,1};
//    myvi v2 = {1,3,6,2222};
//    string s = "LLLL";

    v = lt.survivedRobotsHealths(v,v2,s);

    showVectorInt(v);

    return 0;
}
