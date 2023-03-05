
#include "../../header/myheader.h"

class LT
{
public:



    // g


    // add mx,mn, it become slower...
    // tle. all 2 .

    // merge sort, quick sort. 可以满足 nlogn , n
    // .. merge 的空间。。
    // merge 有个 tomsort。
    vector<int> lta(vector<int>& nums)
    {
        quick(nums, 0, nums.size() - 1);
        return nums;
    }

    void quick(vector<int>& vi, int st, int en)
    {
        if (st >= en)
            return;

        // if en - st < 10,  merge sort/..

        int key = vi[st];       // <= k,  > k
        int st2 = st;
        int en2 = en;
        int mn = INT_MAX, mx = INT_MIN;
        while (st <= en)
        {
            if (vi[st] <= key)
            {
                mn = min(mn, vi[st]);
                ++st;
            }
            else
            {
                mx = max(mx, vi[st]);
                swap(vi[st], vi[en]);
                --en;
            }
        }
        if (st > en || vi[st] > key)
            --st;

        swap(vi[st2], vi[st]);

        if (mn < key)
            quick(vi, st2, st - 1);
        if (mx > key)
            quick(vi, st + 1, en2);
    }


    // error
    // [st, en]
    void merge(vector<int>& vi, int st, int en)
    {
        if (st >= en)
            return;

        int md = (st + en) / 2;
        merge(vi, st, md);
        merge(vi, md + 1, en);
        
        int t2 = st, t3 = md + 1;
        for (int i = st; i <= en; ++i)
        {
            if (vi[t2] <= vi[t3])
            {
                swap(vi[i], vi[t2]);
            }
            else
            {
                swap(vi[i], vi[t3]);
                ++t3;
                t2 = t3 - 1;
            }
        }

    }

};

int main()
{

    LT lt;

//    vector<int> vi = { 5,2,3,1 };
    myvi vi = { 5,1,1,2,0,0 };

    vi = lt.lta(vi);

    showVectorInt(vi);

    return 0;
}
