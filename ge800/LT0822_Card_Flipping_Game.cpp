
#include "../header/myheader.h"

class LT0822
{
public:


// D D
// set 保存 同时正反面的 int， for 2个形参，如果set不包含：ans=min(ans,val)



//Runtime: 24 ms, faster than 83.94% of C++ online submissions for Card Flipping Game.
//Memory Usage: 18.3 MB, less than 33.33% of C++ online submissions for Card Flipping Game.
    int lt0822b(vector<int>& fronts, vector<int>& backs)
    {
        int ans = 0;
        int arr[2001] = {0};
        int sz2 = fronts.size();
        for (int i = 0; i < sz2; i++)
        {
            if (fronts[i] == backs[i])
            {
                arr[fronts[i]] = -1;
            }
            else
            {
                if (arr[fronts[i]] != -1)
                {
                    arr[fronts[i]] = 1;
                }
                if (arr[backs[i]] != -1)
                {
                    arr[backs[i]] = 1;
                }
            }
        }

        for (int i = 0; i < 2001; i++)
        {
            if (arr[i] > 0)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }


//Runtime: 68 ms, faster than 12.41% of C++ online submissions for Card Flipping Game.
//Memory Usage: 20.1 MB, less than 33.33% of C++ online submissions for Card Flipping Game.
// 只要一个数字只出现在一面，最小的值就是结果啊。
    int lt0822a(vector<int>& fronts, vector<int>& backs)
    {
        int ans = 0;
        int sz2 = fronts.size();
        set<int> allNumSet;
        for (int i = 0; i < sz2; i++)
        {
            allNumSet.insert(fronts[i]);
            allNumSet.insert(backs[i]);
        }

        for (set<int>::iterator it2 = allNumSet.begin(); it2 != allNumSet.end(); it2++)
        {
            int val = *it2;
            bool appearDouble = false;
            for (int i = 0; i < sz2; i++)
            {
                if (fronts[i] == val && backs[i] == val)
                {
                    appearDouble = true;
                    break;
                }
            }
            if (!appearDouble) {
                ans = val;
                break;
            }
        }

        return ans;
    }

};

int main()
{

    vector<int> f = {1,2};
    vector<int> b = {1,1};

    LT0822 lt;

    cout<<lt.lt0822b(f, b)<<endl;

    return 0;
}
