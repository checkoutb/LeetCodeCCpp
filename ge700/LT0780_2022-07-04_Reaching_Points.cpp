
#include "../header/myheader.h"

class LT0780
{
public:

    // D D

    //while (tx >= sx && ty >= sy) {
    //    if (tx == ty) break;
    //    if (tx > ty) {
    //        if (ty > sy) tx %= ty;
    //        else return (tx - sx) % ty == 0;
    //    }
    //    else {
    //        if (tx > sx) ty %= tx;
    //        else return (ty - sy) % tx == 0;
    //    }
    //}
    //return (tx == sx && ty == sy);


    //public boolean reachingPoints(int sx, int sy, int tx, int ty) {
    //    if (sx > tx || sy > ty) return false;
    //    if (sx == tx && (ty - sy) % sx == 0) return true;
    //    if (sy == ty && (tx - sx) % sy == 0) return true;
    //    return reachingPoints(sx, sy, tx % ty, ty % tx);
    //}

    //while (sx < tx && sy < ty)
    //    if (tx < ty) ty %= tx;
    //    else tx %= ty;
    //return sx == tx && sy <= ty && (ty - sy) % sx == 0 ||
    //    sy == ty && sx <= tx && (tx - sx) % sy == 0;


//Runtime: 6 ms, faster than 9.16 % of C++ online submissions for Reaching Points.
//Memory Usage : 5.9 MB, less than 64.27 % of C++ online submissions for Reaching Points.
    // max(tx,ty) - min(tx,ty)
    bool lt0780a(int sx, int sy, int tx, int ty)
    {

        while (tx >= sx && ty >= sy)
        {
            if (tx == 0 || ty == 0)
                break;
            if (tx == sx && ty == sy)
                break;

            if (tx > ty)
            {
                if (ty == 1)
                    //tx--;
                    tx = sx;
                else
                    //tx = tx % ty;
                    tx = tx - max((tx - sx) / ty, 1) * ty;
            }
            else
            {
                if (tx == 1)
                    //ty--;
                    ty = sy;
                else
                    //ty = ty % tx;
                    ty = ty - max((ty - sy) / tx, 1) * tx;
            }
#ifdef __test
        cout << tx << ", " << ty << " ttt---sss " << sx << ", " << sy << endl;
#endif
        }
        return tx == sx && ty == sy;






        // 有x,y的分别

        //int mxs = max(sx, sy);
        //int mns = min(sx, sy);

        //int mxt = max(tx, ty);
        //int mnt = max(tx, ty);

        //while (mxt > mxs || mnt > mns)
        //{
        //    if (mnt == 0)
        //        break;
        //    int t2 = mxt % mnt;             // GCD...
        //    mxt = mnt;
        //    mnt = t2;
        //    //int t2 = mxt - mnt;           // 10000000000, 1
        //    //if (t2 > mnt)
        //    //{
        //    //    mxt = t2;
        //    //    mnt = mnt;
        //    //}
        //    //else
        //    //{
        //    //    mxt = mnt;
        //    //    mnt = t2;
        //    //}
        //}

//#ifdef __test
//
//#endif
//
//        return mxt == mxs && mnt == mns;
    }

};

int main()
{

    LT0780 lt;

    //myvi v = { 1,1,3,5 };
    myvi v = { 1,1,2,2 };

    cout << lt.lt0780a(v[0], v[1], v[2], v[3]) << endl;

    return 0;
}
