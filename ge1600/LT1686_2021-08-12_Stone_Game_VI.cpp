
#include "../header/myheader.h"

class LT1686
{
public:





// g


// ...hint Greedily choose the stone with the maximum aliceValues[i] + bobValues[i].


// 如果我小，那么应该拿差距最大的，  如果我大，那么应该拿差距最小的。。
    int lt1868a(vector<int>& aliceValues, vector<int>& bobValues)
    {
        int sz1 = aliceValues.size();
        vector<bool> vst(sz1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> priqab;  // alice bigger
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> priqbb;
        priority_queue<pair<int, int>> priqas;  // alice smaller
        priority_queue<pair<int, int>> priqbs;
        for (int i = 0; i < sz1; ++i)
        {
            int ta = aliceValues[i];
            int tb = bobValues[i];
            if (aliceValues[i] >= bobValues[i])
            {
                priqab.push({ta - tb, i});
                priqbs.push({ta - tb, i});
            }
            else
            {
                priqas.push({tb - ta, i});
                priqbb.push({tb - ta, i});
            }
        }
        int a = 0;
        int b = 0;
        int isA = true;
        int n = sz1;
        while (n-- > 0)
        {
            if (isA)
            {
                while (vst[priqab.top().second] == true)
                    priqab.pop();
                while (vst[priqas.top().second] == true)
                    priqas.pop();
                int idx1 = priqab.top().second;
                int idx2 = priqas.top().second;
                int t1 = aliceValues[idx1];
                int t2 = bobValues[idx1];
                int t3 = aliceValues[idx2];
                int t4 = bobValues[idx2];
                if ((t4 - t1) > (t3 - t2))
                {

                }
            }
            else
            {

            }
            isA = !isA;
        }
    }


// error
// 感觉是选差距最大的。
    int lt1686a(vector<int>& aliceValues, vector<int>& bobValues)
    {
        int sz1 = aliceValues.size();
        priority_queue<pair<int, int>> priq;
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = abs(aliceValues[i] - bobValues[i]);
            priq.push({t2, i});
        }
        int a = 0;
        int b = 0;
        int isA = true;
        while (!priq.empty())
        {
            if (isA)
            {
                a += aliceValues[priq.top().second];
                priq.pop();
            }
            else
            {
                b += bobValues[priq.top().second];
                priq.pop();
            }
            isA = !isA;
        }
        return (a == b ? 0 : (a < b) ? -1 : 1);
    }

};

int main()
{
//    myvi v1 = {1,3};
//    myvi v2 = {2,1};

//    myvi v1 = {1,2}, v2{3,1};

//    myvi v1{2,4,3}, v2{1,6,7};

    myvi v1{9,8,3,8}, v2{10,6,9,5};         // 1
    // 2,8    3,9  1,9  4,5
    // 如果我小，那么应该拿差距最大的，  如果我大，那么应该拿差距最小的。。



    LT1686 lt;

    cout<<lt.lt1686a(v1, v2)<<endl;

    return 0;
}
