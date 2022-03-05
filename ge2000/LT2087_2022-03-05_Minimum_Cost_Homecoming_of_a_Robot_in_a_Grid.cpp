
#include "../header/myheader.h"

class LT2087
{
public:





// g

// D
// 确实，机器人 面向 房子 走是最短的，并且 这样走的 所有路径的 sum 都是一样的。。。可惜了，



    int lt2087c(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
    {
        int sz1 = rowCosts.size();
        int sz2 = colCosts.size();
        vector<int> vi(sz1, 0);
        int mni = min(startPos[0], homePos[0]);
        int mnj = min(startPos[1], homePos[1]);
        int mxi = max(startPos[0], homePos[0]);
        int mxj = max(startPos[1], homePos[1]);
        int sti = startPos[0];
        int eni = homePos[0];
        int chi = sti > eni ? -1 : 1;
        int stj = startPos[1];
        int enj = homePos[1];
        int chj = stj > enj ? -1 : 1;


        if (sti != eni)
            for (int i = sti + chi; i != eni; i += chi)
            {
                vi[i] = vi[sti - chi] + rowCosts[i];
            }

        if (stj != enj)
            for (int j = stj + chj; j != enj; j += chj)
            {
                int t2 = vi[sti];
                vi[sti] += colCosts[j];
                if (sti != eni)
                    for (int i = sti + chi; i != eni; i += chi)
                    {
                        int t3 = vi[sti];
                        vi[sti] = min(vi[sti] + colCosts[j], t2 + rowCosts[i]);
                        t2 = t3;
                    }
            }
        return vi[eni];
    }

// error
// 一维数组 扫描过去。
// 主要是 r 不一定在 h的 左上。 有点。。
    int lt2087b(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
    {
        int mni = min(startPos[0], homePos[0]);
        int mnj = min(startPos[1], homePos[1]);
        int mxi = max(startPos[0], homePos[0]);
        int mxj = max(startPos[1], homePos[1]);
        int sti = 0, chi = 1, lmi = mxi - mni + 1;
        int stj = 0, chj = 1, lmj = mxj - mni + 1;
        if (mni == startPos[0])
        {
            ;
        }
        else
        {
            sti = mxi;
            chi = -1;
            lmi = mni;
        }
        if (mnj == startPos[1])
        {
            ;
        }
        else
        {
            stj = mxj;
            chj = -1;
            lmj = mnj;
        }
        vector<int> vi(mxi - mni + 1, 0);
        #ifdef __test
        cout<<sti<<" "<<lmi<<" "<<chi<<" - "<<stj<<", "<<lmj<<" "<<chj<<endl;
        #endif // __test
        for (int i = sti + chi; i != lmi; i += chi)
        {
            vi[i] = vi[i - chi] + rowCosts[i + mni];
        }
        for (int j = stj; j != lmj; j += chj)
        {
            int t2 = 123123123;
            int t3 = 0;
            for (int i = sti; i != lmi; i += chi)
            {
                t3 = vi[i];
                vi[i] = min(t2 + rowCosts[i + mni], vi[i] + colCosts[j]);
                t2 = t3;
            }
        }
        return vi[homePos[0] - mni];
    }



// Memory Limit Exceeded
// 上下移动 看 rowCost， 左右移动 看 colCost
// top-down？
// 应该至少是 向着 房子前进的，不可能远离的。 这个再说吧。  10^5 ^2 ...有点大。。  确实应该只能 向房子走。
// 加的移动后的 r/c de cost
    int lt2087a(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts)
    {
        int sz1 = rowCosts.size();
        int sz2 = colCosts.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
//        vvi[startPos[0]][startPos[1]] = 0;
        dfsa1(vvi, startPos[0], startPos[1], homePos[0], homePos[1], rowCosts, colCosts, 0);

//        #ifdef __test
//        for (myvi& vi : vvi)
//        {
//            showVectorInt(vi);
//        }
//        #endif // __test

        return vvi[homePos[0]][homePos[1]];
    }

    void dfsa1(vector<vector<int>>& vvi, int ri, int rj, int hi, int hj, vector<int>& rc, vector<int>& cc, int cst)
    {
//        #ifdef __test
//        cout<<ri<<", "<<rj<<", "<<vvi.size()<<", "<<vvi[0].size()<<", "<<", "<<vvi[ri][rj]<<", "<<cst<<endl;
//        #endif // __test
        if (ri < 0 || rj < 0 || ri == vvi.size() || rj == vvi[0].size() || vvi[ri][rj] <= cst)
            return;
        vvi[ri][rj] = cst;
        if (ri == hi && rj == hj)
            return;
        if (ri != hi)
        {
            if (ri > hi)
            {
                ri--;
//                if (ri >= 0)
//                {
                    dfsa1(vvi, ri, rj, hi, hj, rc, cc, cst + rc[ri]);
//                }
                ri++;
            }
            else
            {
                ri++;
//                if (ri < vvi.size())
                    dfsa1(vvi, ri, rj, hi, hj, rc, cc, cst + rc[ri]);
                ri--;       // for if rj != hj ....
            }
//            dfsa1(vvi, ri + (ri > hi ? -1 : 1), rj, hi, hj, rc, cc, cst + rc[ri]);
        }
        if (rj != hj)
        {
            rj += (rj > hj ? -1 : 1);
            dfsa1(vvi, ri, rj, hi, hj, rc, cc, cst + cc[rj]);
//            if (rj > hj)
//            {
//                rj--;
//
////                if (rj >=)
//            }
////            dfsa1(vvi, ri, rj + (rj > hj ? -1 : 1), hi, hj, rc, cc, cst + cc[rj]);
        }
    }

};

int main()
{

    LT2087 lt;

    myvi vr = {1,0};
    myvi vh = {2,3};
    myvi vrr = {5,4,3};
    myvi vc = {8,2,6,7};

//    myvi vr = {0,0};
//    myvi vh = {0,0};
//    myvi vrr = {12,1,3};
//    myvi vc = {2,3,4};

    cout<<lt.lt2087c(vr, vh, vrr, vc);

    return 0;
}
