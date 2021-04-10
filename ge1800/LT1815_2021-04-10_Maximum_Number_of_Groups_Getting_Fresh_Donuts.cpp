
#include "../header/myheader.h"

class LT1815
{
public:

// D

//map<vector<int>, int> dp;



// gg

//6, 3, 2, 6, 6, 6, 6, 2, 6, 6, 2,
//0
//1
// 不能贪心，662，322，，，正常应该是662 662 662

// 重排序后，开始累加，最多能让多少个sum能被batchSize整除，就是 前x个元素的和能被batchSize整除，x能取哪些。x最多。
// 只要能整除，后面来的，就能吃到新鲜的。整个数组不算。..bu,算的，因为第一个必然是新鲜的,bu.
// 先一个元素，能不能被整除
// 然后2个元素，能不能被整除
// 3个，4个，5个 一直到空。这个有可能重复计算。
// group最多30个元素，直接每次都重开，不是借助与上次的，这样就不会重复了。 或者<和，<下标s>>
    int lt1815a(int batchSize, vector<int>& groups)
    {
        for (int i = 0; i < groups.size(); ++i)
        {
            groups[i] = groups[i] % batchSize;
        }
        int ans = 0;
        int mxcnt = 1;
        while (groups.size() >= mxcnt)
        {
//            for (int i = 0; i < groups.size(); ++i)
//            {
//                if (dfsa1(groups, 0, 0, 0, mxcnt, batchSize))
//                    ans++;
//            }
            for (int i = 0; i < groups.size(); ++i)
            {
                if (groups[i] != -1)
                    if (dfsa1(groups, i + 1, groups[i], 1, mxcnt, batchSize))
                    {
                        groups[i] = -1;
                        ans++;
                        #ifdef __test
                        cout<<i<<endl;
//                        showVectorInt(groups);
                        #endif // __test
                    }
            }
            mxcnt++;
            vector<int> gp;
            for (int i = 0; i < groups.size(); ++i)
                if (groups[i] != -1)
                    gp.push_back(groups[i]);
            std::swap(groups, gp);
            #ifdef __test
            cout<<"ans : "<<ans<<", mxcnt: "<<(mxcnt - 1)<<endl;
            showVectorInt(groups);
            #endif // __test
        }
        #ifdef __test
        cout<<ans<<", "<<(groups.size())<<endl;
        #endif // __test
        return 1 + ans - (groups.empty());
//        return max(1, ans);
//        return ans - (groups.empty());
    }

    bool dfsa1(vector<int>& groups, int idx, int sum2, int cnt, int mxcnt, int bs)
    {
        if (cnt == mxcnt)
        {
            return sum2 % bs == 0;
        }
        for (int i = idx; i < groups.size(); ++i)
        {
            if (groups[i] == -1)
                continue;
            bool ans = dfsa1(groups, i + 1, sum2 + groups[i], cnt + 1, mxcnt, bs);
            if (ans)
            {
                groups[i] = -1;
                return true;
            }
        }
        return false;
    }

};

int main()
{
//    int bs = 3;
//    myvi v = {1,2,3,4,5,6};

//    int bs = 4;
//    myvi v = {1,3,2,5,2,2,1,6};

//    int bs = 7;             // 10
//    myvi v = {839562595,994462569,405916966,82304069,612871994,590853022,240211157,607701921,87771155,286392333,391799587,956454997,317347197,606070171,573694014,993283352,122745984,491525998,962888093};

    int bs = 7;         // 15
    myvi v = {2,7,5,2,3,2,6,5,3,6,2,3,7,2,2,5,4,6,6,4,7,5,6,1,6,2,6,6,2,5};


    LT1815 lt;

    cout<<lt.lt1815a(bs, v);

    return 0;
}
