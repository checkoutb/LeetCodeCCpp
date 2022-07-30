
#include "../header/myheader.h"

class LT0552
{
public:

    // D D

    //int a0l0 = 1, //"..."
    //    a0l1 = 1, //"...L"
    //    a0l2 = 0, //"...LL"
    //    a1l0 = 1, //"...A..."
    //    a1l1 = 0, //"...A...L"
    //    a1l2 = 0; //"...A...LL"

    //int i = 1;
    //if (n > 50000)
    //{
    //    i = 50000;
    //    a0l0 = 673561657;
    //    a0l1 = 579884284;
    //    a0l2 = 168286508;
    //    a1l0 = 883463666;
    //    a1l1 = 224283386;
    //    a1l2 = 791154896;
    //}
    // 物理加速。。。 可以的。




        //f[i][0][0]      | 0 0 1 0 0 0 |     f[i - 1][0][0]
        //f[i][0][1]      | 1 0 1 0 0 0 |     f[i - 1][0][1]
        //f[i][0][2] =    | 0 1 1 0 0 0 | *   f[i - 1][0][2]
        //f[i][1][0]      | 0 0 1 0 0 1 |     f[i - 1][1][0]
        //f[i][1][1]      | 0 0 1 1 0 1 |     f[i - 1][1][1]
        //f[i][1][2]      | 0 0 1 0 1 1 |     f[i - 1][1][2]
    // https://leetcode.com/problems/student-attendance-record-ii/discuss/101633/Improving-the-runtime-from-O(n)-to-O(log-n)



    //long[] PorL = new long[n + 1]; // ending with P or L, no A
    //long[] P = new long[n + 1]; // ending with P, no A
    //PorL[0] = P[0] = 1; PorL[1] = 2; P[1] = 1;

    //for (int i = 2; i <= n; i++) {
    //    P[i] = PorL[i - 1];
    //    PorL[i] = (P[i] + P[i - 1] + P[i - 2]) % M;
    //}

    //long res = PorL[n];
    //for (int i = 0; i < n; i++) { // inserting A into (n-1)-length strings
    //    long s = (PorL[i] * PorL[n - i - 1]) % M;
    //    res = (res + s) % M;
    //}

        //Let's say it is on the position i.
        //How many elements are to the left of(before) A ? There are i - 1 elements before A.
        //What sequence do we have before A ? PorL!
        //How many PorL sequences of length i - 1 there are ? PorL[i]
        //How many elements are to the right(after) A ? There are n - (i - 1) - 1 = n - i elements after A.
        //What sequence do we have after A ? PorL!
        //How many PorL sequences of length n - i there are ? PorL[n - i]
        //If you pick one particular PorL sequence that can be to the left of A, how many sequences can you pick for the part which is after A ? PorL[n - i]
        //you have PorL[i - 1] sequences available for the left partand for each of them you can pick ANy sequence from PorL[n - i], so the total number is PorL[i - 1] * PorL[n - i]




//Runtime: 52 ms, faster than 82.82 % of C++ online submissions for Student Attendance Record II.
//Memory Usage : 5.9 MB, less than 88.08 % of C++ online submissions for Student Attendance Record II.
    int lt0552b(int n)
    {
        int arr0[3] = { 0 };        // continue index days late, and never absent
        int arr1[3] = { 0 };        // continue index days late, and absent 1 day
        const int MOD = 1e9 + 7;

        int at0[3] = { 0 };
        int at1[3] = { 0 };


        // first day
        arr0[0] = 1;        // P
        arr0[1] = 1;        // L
        arr1[0] = 1;        // A

        for (int i = 1; i < n; ++i)
        {
            // absent
            at1[0] = ((arr0[0] + arr0[1]) % MOD + (arr0[2]) % MOD) % MOD;

            // late
            //at0[3] = arr0[2];
            at0[2] = arr0[1];
            at0[1] = arr0[0];
            at0[0] = 0;

            //at1[3] = arr1[2];
            at1[2] = arr1[1];
            at1[1] = arr1[0];
            //at1[0] = 0;

            // present
            at0[0] = ((arr0[0] + arr0[1]) % MOD + (arr0[2] + at0[0]) % MOD) % MOD;
            at1[0] = ((arr1[0] + arr1[1]) % MOD + (arr1[2] + at1[0]) % MOD) % MOD;

            for (int m = 0; m < 3; ++m)
            {
                arr0[m] = at0[m];
                arr1[m] = at1[m];
            }
        }
        int ans = 0;
        for (int i = 0; i < 3; ++i)
        {
            ans = (ans + (arr0[i] + arr1[i]) % MOD) % MOD;
        }
        return ans;
    }


    // .. 好像是不能 >= 3 天的 持续 late
    int lt0552a(int n)
    {
        int arr0[4] = { 0 };        // continue index days late, and never absent
        int arr1[4] = { 0 };        // continue index days late, and absent 1 day
        const int MOD = 1e9 + 7;

        int at0[4] = { 0 };
        int at1[4] = { 0 };


        // first day
        arr0[0] = 1;        // P
        arr0[1] = 1;        // L
        arr1[0] = 1;        // A

        for (int i = 1; i < n; ++i)
        {
            // absent
            at1[0] = ((arr0[0] + arr0[1]) % MOD + (arr0[2] + arr0[3]) % MOD) % MOD;

            // late
            at0[3] = arr0[2];
            at0[2] = arr0[1];
            at0[1] = arr0[0];
            at0[0] = 0;

            at1[3] = arr1[2];
            at1[2] = arr1[1];
            at1[1] = arr1[0];
            //at1[0] = 0;

            // present
            at0[0] += ((arr0[0] + arr0[1]) % MOD + (arr0[2] + arr0[3]) % MOD) % MOD;            // += 会溢出。 += 使得 at[0] 保存的数字 > 1e9+7
            at1[0] += ((arr1[0] + arr1[1]) % MOD + (arr1[2] + arr1[3]) % MOD) % MOD;

            for (int m = 0; m < 4; ++m)
            {
                arr0[m] = at0[m];
                arr1[m] = at1[m];
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; ++i)
        {
            ans = (ans + (arr0[i] + arr1[i]) % MOD) % MOD;
        }
        return ans;
    }

};

int main()
{

    LT0552 lt;

    int n = 10101;


    cout << lt.lt0552b(n) << endl;

    return 0;
}
