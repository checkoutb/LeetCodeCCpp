
#include "../../header/myheader.h"

class LT6133
{
public:



// AC
    // i 组的 sum of grade < i+1 组的。
    // i 组的 人数 < i+1 组的
    // 最多分几组
    // ？ 最小的分数 是 第一组 ？ 然后 次小+次次小 是第二组？
    int maximumGroups(vector<int>& grades)
    {
        sort(begin(grades), end(grades));
        #ifdef __test

        #endif // __test
        int ans = 0;
        int cnt = 1;
        int sum2 = 0;
        int sz1 = grades.size();
        for (int i = 0; i < sz1; )
        {
            int t2sum = 0;
            int nxtcnt = cnt + 1;

            if (sz1 - i < cnt)                                      // ...
                break;

            for (int a = 0; a < cnt && i < sz1; ++a)
            {
                t2sum += grades[i++];
            }
            while (t2sum <= sum2 && i < sz1)
            {
                t2sum += grades[i++];
                nxtcnt++;
            }
            #ifdef __test
            cout<<i<<", "<<sum2<<", "<<t2sum<<" -- "<<nxtcnt<<" ? "<<cnt<<endl;
            #endif // __test
            if (t2sum <= sum2)
            {
                break;
            }
            ans++;
            sum2 = t2sum;
            cnt = nxtcnt;
        }
        return ans;
    }

};

int main()
{

    LT6133 lt;

    //myvi v = {10,6,12,7,3,5};
    //myvi v = {8,8};
    myvi v = {47,2,16,17,41,4,38,23,47};

    cout<<lt.maximumGroups(v)<<endl;

    return 0;
}
