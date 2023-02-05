
#include "../header/myheader.h"

class LT2523
{
public:

    // D D

    //vector<int> arr;
    //if (left <= 2)
    //{
    //    left = 2;
    //    arr.push_back(left);
    //}
    //if (left % 2 == 0)
    //{
    //    left++;
    //}
    //for (int i = left; i <= right; i      +=       2       )
    //{
    //    bool flag = true;
    //    for (int j = 2; j * j <= i; ++j)
    //    {


    //vector<int> closestPrimes(int left, int right) {
    //    static vector<bool> preComputed(1000001, true);



    //Runtime854 ms
    //    Beats
    //    35.42 %
    //    Memory6.1 MB
    //    Beats
    //    98.9 %
    vector<int> lt2523a(int left, int right)
    {
        bitset<1000003> bs;     // all false
        int a = INT_MIN + 123123;
        int b = -1;
        int lst = -1;
        for (int i = 2; i <= right; ++i)
        {
            if (!bs[i])
            {
                // prime
                for (int j = i + i; j <= right; j += i)
                {
                    bs.set(j);
                }
                if (lst >= left && (i - lst) < (b - a))
                {
                    a = lst;
                    b = i;
                }
                lst = i;
            }
        }
        vector<int> ans(2, -1);
        if (a > 0)
        {
            ans[0] = a;
            ans[1] = b;
        }
        return ans;
    }

};

int main()
{

    LT2523 lt;

    //int a = 10, b = 19;
    int a = 4, b = 6;

    showVectorInt(lt.lt2523a(a, b));

    return 0;
}
