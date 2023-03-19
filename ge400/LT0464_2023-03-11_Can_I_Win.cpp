
#include "../header/myheader.h"

class LT0464
{
public:

    // D D

//private:
//    int mem[1 << 20] = {};
//    bool dfs(int maxChoosableInteger, int desiredTotal, int k) {
//        if (desiredTotal <= 0) return 0;
//        if (mem[k] != 0) return mem[k] > 0;
//
//        for (int i = 0; i < maxChoosableInteger; i++) {
//            if (!(k & (1 << i)) && !dfs(maxChoosableInteger, desiredTotal - i - 1, k | (1 << i))) {
//                return mem[k] = 1;
//            }
//        }
//        return !(mem[k] = -1);
//    }
//public:
//    bool canIWin(int maxChoosableInteger, int desiredTotal) {
//        int m = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
//        if (desiredTotal < 2) return 1;
//        if (m < desiredTotal) return 0;
//        if (m == desiredTotal) return maxChoosableInteger % 2;
//        return dfs(maxChoosableInteger, desiredTotal, 0);
//    }




    //Runtime136 ms
    //    Beats
    //    69.69 %
    //    Memory50.1 MB
    //    Beats
    //    53.46 %
    // ×´Ì¬Ñ¹Ëõdp
    bool lt0464a(int n, int tar)
    {
        //vector<bool> vb(tar + 1);

        //vector<int> vi((1 << n) - 1, -1);

        if ((1 + n) * n / 2 < tar)
            return false;

        vector<pair<bool, bool>> vp((1 << (n + 1)) - 1);

        dfsa1(vp, n, tar, 0, 0);
        return vp[0].second;
    }

    bool dfsa1(vector<pair<bool, bool>>& vp, int n, int tar, int got, int state)
    {
        if (got > tar)
            return false;

        if (vp[state].first)
        {
            return vp[state].second;
        }
        int t2 = tar - got;
        if (t2 <= n && (state & (1 << t2)) == 0)
        {
            vp[state].first = true;
            vp[state].second = true;
            return true;
        }

        bool b2 = false;
        for (int i = 1; (i <= n); ++i)
        {
            if ((state & (1 << i)) == 0)
            {
                b2 = !dfsa1(vp, n, tar, got + i, state | (1 << i));
                if (b2)
                    break;
            }
        }
        vp[state].first = true;
        vp[state].second = b2;
        return b2;
    }

};

int main()
{

    LT0464 lt;

    int n = 10;
    int tar = 11;

    //int n = 6;
    //int tar = 8;

    cout << lt.lt0464a(n, tar) << endl;

    return 0;
}
