
#include "../header/myheader.h"

class LT1526
{
public:

// D

//        for (int a: A) {
//            res += max(a - pre, 0);
//            pre = a;
//        }
// 默认前面已经 和目标一样高， 如果自己 比前面高，那么就需要额外的步骤 来增加，否则的话，前面在增加的时候，顺便把自己也增加到目标了。


// 127 / 129     tle...
    int lt1526c(vector<int>& target)
    {
        int ans = mergeDecrease(target, 0, target.size());
        return ans;
    }
    // [st, en)
    int mergeDecrease(vector<int>& target, int st, int en)
    {
//        int mni = st;
        vector<int> mni = {st};
        int mn = target[st];
        for (int i = st + 1; i < en; ++i)
        {
            if (target[i] < mn)
            {
                mn = target[i];
//                mni.clear();
//                mni.push
                mni = {i};
            }
            else if (target[i] == mn)
            {
                mni.push_back(i);
            }
        }
        int ans = mn;
        mni.push_back(en);
//        int st
        int i = 0;
        while (i < mni.size() && st == mni[i])
        {
            st++;
            i++;
        }
        for (; i < mni.size(); ++i)
        {
//            cout<<st<<", "<<mni[i]<<endl;
            if (mni[i] > st)
                ans += (mergeDecrease(target, st, mni[i]) - mn);
            st = mni[i] + 1;
        }
        #ifdef __test
        cout<<st<<", "<<en<<", "<<ans<<endl;
        #endif // __test
        return ans;
    }


// 64 / 129 tle
    int lt1526b(vector<int>& target)
    {
        int ans = 0;
        for (int i = 0; i < target.size(); ++i)
        {
            if (target[i] != 0)
            {
                ans += target[i];
                int t2 = target[i];
                for (int j = i; j < target.size() && t2 >= 0; ++j)      // 升序就 tle。
                {
                    if (target[j] < t2)
                    {
                        t2 = target[j];
                    }
                    target[j] -= t2;
                }
            }
        }
        return ans;
    }


// tle.  61 / 129
    int lt1526a(vector<int>& target)
    {
        int ans = 0;
        for (int i = 0; i < target.size(); ++i)
        {
            while (target[i] != 0)
            {
                for (int j = i; j < target.size(); ++j)
                {
                    if (target[j] > 0)
                    {
                        target[j]--;
                    }
                    else
                    {
                        break;
                    }
                }
                ans++;
            }
            #ifdef __test
//            showVectorInt(target);
            #endif // __test
        }
        return ans;
    }

};

int main()
{
    myvi v = {1,2,3,2,1};
//    myvi v = {3,1,1,2};
//    myvi v = {3,1,5,4,2};
//    myvi v = {1,1,1,1};

    LT1526 lt;

    cout<<lt.lt1526c(v)<<endl;

    return 0;
}
