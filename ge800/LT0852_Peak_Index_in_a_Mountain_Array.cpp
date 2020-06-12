
#include "../header/myheader.h"

class LT0852
{
public:


// D

// 黄金分割搜索。。。


//Runtime: 24 ms, faster than 50.85% of C++ online submissions for Peak Index in a Mountain Array.
//Memory Usage: 11.7 MB, less than 34.78% of C++ online submissions for Peak Index in a Mountain Array.
// 送分题来了。
    int lt0852a(vector<int>& A)
    {
        int i = 1;
        for (; i < A.size(); i++)
        {
            if (A[i] < A[i - 1])
            {
                break;
            }
        }
        return i - 1;
    }

};

int main()
{

    vector<int> a = {0,1,2,0};

    LT0852 lt;

    cout<<lt.lt0852a(a)<<endl;

    return 0;
}
