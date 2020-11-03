
#include "../header/myheader.h"

class LT1089
{
public:

// D D

//        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
//        for (int i = n - 1; i >= 0; --i) {
//            if (--j < n)
//                A[j] = A[i];
//            if (A[i] == 0 && --j < n)
//                A[j] = 0;
//        }


//    int n = A.length, count = 0;
//
//    for (int num : A) if (num == 0) count++;
//    int i = n - 1;
//    int write = n + count - 1;
//
//    while (i >= 0 && write >= 0)  {
//
//      if (A[i] != 0) { // Non-zero, just write it in
//        if (write < n) A[write] = A[i];
//
//      } else { // Zero found, write it in twice if we can
//        if (write < n) A[write] = A[i];
//        write--;
//        if (write < n) A[write] = A[i];
//      }
//
//      i--;
//      write--;
//    }




//Runtime: 8 ms, faster than 95.12% of C++ online submissions for Duplicate Zeros.
//Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Duplicate Zeros.
// insert + resize...
    void lt1089a(vector<int>& arr)
    {
        vector<int> i0;         // index of 0
        i0.push_back(-1);
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
            {
                i0.push_back(i);
            }
        }
        int i0i = i0.size() - 1;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int ni = i + i0i;
            if (ni < arr.size())
                arr[ni] = arr[i];
            if (i == i0[i0i])
            {
                i0i--;
                if (i + i0i < arr.size())
                {
                    arr[i + i0i] = 0;
                }
            }
        }
    }

};

int main()
{

    vector<int> v = {1,0,2,3,0,4,5,0};
//    vector<int> v = {1,0,0,2,3,4,5,6};
//    vector<int> v = {0,6,0,0,4,1,0};

    LT1089 lt;

    lt.lt1089a(v);

    for_each (begin(v), end(v), fun_cout);

    return 0;
}
