
#include "../header/myheader.h"

class LT0949
{
public:


// D D
//string largestTimeFromDigits(vector<int>& A) {
//  sort(begin(A), end(A), greater<int>());
//  do if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
//      return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
//  while (prev_permutation(begin(A), end(A)));
//  return "";
//}

// do while... 还能不写大括号。。
// prev_permutation    函数功能是输出所有比当前排列小的排列，顺序是从大到小。


//Runtime: 4 ms, faster than 75.24% of C++ online submissions for Largest Time for Given Digits.
//Memory Usage: 10 MB, less than 10.08% of C++ online submissions for Largest Time for Given Digits.
    string lt0949b(vector<int>& A)
    {
        vector<int> tms;
        for (int i = 0; i < 4; i++)
        {
            if (A[i] > 2)
                continue;
            for (int j = 0; j < 4; j++)
            {
                if (j == i)
                    continue;
                if (A[i] == 2 && A[j] > 3)
                    continue;
                for (int k = 0; k < 4; k++)
                {
                    if (k == j || k == i)
                        continue;
                    if (A[k] > 5)
                        continue;

                    for (int m = 0; m < 4; m++)
                    {
                        if (m == k || m == j || m == i)
                        {
                            continue;
                        }
                        tms.push_back(A[i]*1000 + A[j]*100 + A[k]*10 + A[m]);
                    }
                }
            }
        }
        if (tms.size() == 0)
            return "";
        sort(tms.rbegin(), tms.rend());
        return (tms[0] / 100 >= 10 ? "" : "0") + to_string(tms[0] / 100) + ":" + (tms[0] % 100 >= 10 ? "" : "0") + to_string(tms[0] % 100);
    }


    // error
    string lt0949a(vector<int>& A)
    {
        int t1 = 0, t2 = 0, t3 = 0, t4 = 0;
        int tx = -1;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] <= 2 && A[i] >= t1)
            {
                t1 = max(t1, A[i]);
                tx = i;
            }
        }
        if (tx == -1)
            return "";

        A[tx] = 10;
        int tmx = (t1 == 2 ? 3 : 9);
        tx = -1;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] <= tmx && A[i] >= t2)
            {
                t2 = A[i];
                tx = i;
            }
        }
        if (tx == -1)
        {
            return "";
        }

        A[tx] = 10;

        tx = -1;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] <= 5 && A[i] >= t3)
            {
                t3 = A[i];
                tx = i;
            }
        }
        if (tx == -1)
            return "";
        A[tx] = 10;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] < 10)
                t4 = A[i];
        }

        return to_string(t1) + to_string(t2) + ":" + to_string(t3) + to_string(t4);
    }

};

int main()
{

//    vector<int> v = {1,2,3,4};

    vector<int> v = {2,0,6,6};

    LT0949 lt;

    cout<<lt.lt0949b(v)<<endl;

    return 0;
}
