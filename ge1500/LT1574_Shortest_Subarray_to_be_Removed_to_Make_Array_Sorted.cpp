
#include "../header/myheader.h"

class LT1574
{
public:



    int lt1574a(vector<int>& arr)
    {
        int sz1 = arr.size();
        int i = sz1 - 2;
        for (; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                break;
            }
        }
        int t2 = i + 1;     // begin of sorted array
        vector<int> vi(arr.begin() + i + 1, arr.end());

        #ifdef __test
        showVectorInt(vi);
        #endif // __test

        int ans = INT_MAX;
        bool ordered = true;
        for (i = 0; i < sz1; i++)
        {
            if (ordered && i > 0)
            {
                if (arr[i] < arr[i - 1])
                {
//                    ordered = false;
                    break;
                }
            }
//            if (!ordered)
//                break;
            int val = arr[i];
            vector<int>::iterator it = std::lower_bound(begin(vi), end(vi), val);
            if (it == end(vi))
            {
                ans = min(ans, sz1 - i);
                cout<<ans<<endl;
            }
            else
            {
                ans = min(ans, (int) std::distance(begin(vi), it) + t2 - i);
            }

//            int dis = std::distance(begin(arr), std::lower_bound(begin(arr), end(arr), val));
//            ans = min(ans, t2 - i + dis - 2);
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3,10,4,2,3,5};
    myvi v = {5,4,3,2,1};
//    myvi v = {1,2,3};

    LT1574 lt;

    cout<<lt.lt1574a(v)<<endl;

    return 0;
}
