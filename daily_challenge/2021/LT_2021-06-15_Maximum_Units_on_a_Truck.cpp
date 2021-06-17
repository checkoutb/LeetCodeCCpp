
#include "../../header/myheader.h"

class LT
{
public:


// D D

// bucket sort




// AC  40ms
    int ltb(vector<vector<int>>& boxTypes, int truckSize)
    {
        int ans = 0;
        std::sort(begin(boxTypes), end(boxTypes), [](const vector<int>& v1, const vector<int>& v2){return v1[1] > v2[1];});
        #ifdef __test
        for (myvi& vi : boxTypes)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        for (int i = 0; i < boxTypes.size(); ++i)
        {
            int t1 = boxTypes[i][0];
            int t2 = boxTypes[i][1];
            if (t1 >= truckSize)
            {
                ans += truckSize * t2;
                break;
            }
            else
            {
                ans += t1 * t2;
                truckSize -= t1;
            }
        }
        return ans;
    }


// tle.... 76 / 76 test cases passed, but took too long.
// sort, priq, heap
    int lta(vector<vector<int>>& boxTypes, int truckSize)
    {
        int ans = 0;
//        vector<int> vi;
        while (truckSize > 0 && !boxTypes.empty())
        {
            std::make_heap(begin(boxTypes), end(boxTypes), [](const vector<int>& v1, const vector<int>& v2){return v1[1] < v2[1];});        // min-heap?
            std::pop_heap(begin(boxTypes), end(boxTypes));
//            vi = *boxTypes.rbegin();
            vector<int>& vi = *boxTypes.rbegin();
            #ifdef __test
            cout<<vi[0]<<", "<<vi[1]<<endl;
            #endif // __test
            if (truckSize > vi[0])
            {
                truckSize -= vi[0];
                ans += vi[0] * vi[1];
            }
            else
            {
                ans += truckSize * vi[1];
                truckSize = 0;  // .... break;
            }
            boxTypes.pop_back();
        }
        return ans;
    }

};

int main()
{

//    myvvi vv = {{1,3},{2,2},{3,1}};
//    int tsz = 4;

    myvvi vv = {{5,10},{2,5},{4,7},{3,9}};
    int tsz = 10;

    LT lt;

    cout<<lt.ltb(vv, tsz)<<endl;

    return 0;
}
