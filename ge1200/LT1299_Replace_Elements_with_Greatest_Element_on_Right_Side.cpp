
#include "../header/myheader.h"

class LT1299
{
public:


// D D

//mx = max(mx, exchange(A[i], mx));

// T exchange( T& obj, U&& new_value );          return The old value of obj


//Runtime: 20 ms, faster than 96.52% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
//Memory Usage: 15 MB, less than 24.29% of C++ online submissions for Replace Elements with Greatest Element on Right Side.
    vector<int> lt1299a(vector<int>& arr)
    {
        int lstmx = -1;
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            int t1 = arr[i];
            arr[i] = lstmx;
            lstmx = max(lstmx, t1);
        }
        return arr;
    }

};

int main()
{

    LT1299 lt;


    return 0;
}
