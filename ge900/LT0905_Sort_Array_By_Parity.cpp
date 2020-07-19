
#include "../header/myheader.h"

class LT0905
{
public:

// D D
//        for (int i = 0, j = 0; j < A.size(); j++)
//            if (A[j] % 2 == 0) swap(A[i++], A[j]);


//        vector<int> res(size, 0);
//        int start = 0, end = size - 1;
//        for (int i = 0; i < size; i++) {
//            if (A[i] % 2 == 1) {
//                res[end--] = A[i];
//            } else {
//                res[start++] = A[i];
//            }
//        }


//    auto is_even = [] (auto e) { return e % 2 == 0; };
//    partition (A.begin (), A.end (), is_even);
//    return A;

//use & rather than % to determine if a number is even or odd

// A.sort((a, b) => { return a % 2 - b % 2; });


//Runtime: 28 ms, faster than 27.03% of C++ online submissions for Sort Array By Parity.
//Memory Usage: 16.2 MB, less than 84.93% of C++ online submissions for Sort Array By Parity.
    vector<int> lt0905a(vector<int>& A)
    {
        int l = 0;
        int r = A.size() - 1;
        while (l < r)
        {
            while (l < r)
            {
                if (A[l] % 2 == 1)
                {
                    break;
                }
                l++;
            }
            while (r > l)
            {
                if (A[r] % 2 == 0)
                {
                    break;
                }
                r--;
            }
            if (l < r)
            {
                int t1 = A[l];
                A[l] = A[r];
                A[r] = t1;
            }
        }
        return A;
    }

};

int main()
{

    vector<int> a = {3,1,2,4};

    LT0905 lt;

    vector<int> v = lt.lt0905a(a);

    for_each(begin(v), end(v), fun_cout);
    cout<<endl;

    return 0;
}
