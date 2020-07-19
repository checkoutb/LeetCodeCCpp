
#include "../header/myheader.h"

class LT0896
{
public:


//        bool inc = true, dec = true;
//        for (int i = 1; i < A.size(); ++i)
//            inc &= A[i - 1] <= A[i], dec &= A[i - 1] >= A[i];
//        return inc || dec;



//Runtime: 208 ms, faster than 24.63% of C++ online submissions for Monotonic Array.
//Memory Usage: 53 MB, less than 11.17% of C++ online submissions for Monotonic Array.
    bool lt0896a(vector<int>& A)
    {
        if (A[0] == A[A.size() - 1])
        {
            return (*max_element(begin(A), end(A)) == *min_element(begin(A), end(A)));
        }
        bool isInc = A[A.size() - 1] > A[0];
        for (int i = 1; i < A.size(); i++)
        {
            if (isInc)
            {
                if (A[i] < A[i - 1])
                    return false;
            }
            else
            {
                if (A[i] > A[i - 1])
                    return false;
            }
        }
        return true;
    }

};

int main()
{

    LT0896 lt;


    return 0;
}
