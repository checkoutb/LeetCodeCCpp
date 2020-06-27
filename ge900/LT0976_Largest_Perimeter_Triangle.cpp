
#include "../header/myheader.h"

class LT0976
{
public:


// D D
//        for(int i = A.size() - 3; i >= 0; i--){
//            if(A[i] + A[i+1] > A[i+2])
//                return A[i] + A[i+1] + A[i+2];
//        }


// for j 无意义。


//        sort(A.begin(), A.end());
//        for (int i = A.size() - 1 ; i > 1; --i)
//            if (A[i] < A[i - 1] + A[i - 2])
//                return A[i] + A[i - 1] + A[i - 2];
//        return 0;




//Runtime: 96 ms, faster than 89.54% of C++ online submissions for Largest Perimeter Triangle.
//Memory Usage: 21.9 MB, less than 62.21% of C++ online submissions for Largest Perimeter Triangle.
    int lt0976a(vector<int>& A)
    {
        std::sort(begin(A), end(A));
        int ans = 0;
        int sz1 = A.size();
        int t3 = 0;
        int a, b, c;
        for (int i = sz1 - 1; i >= 0; i--)
        {
            a = A[i];
            if (a * 3 < ans)
                break;
            for (int j = i - 1; j > 0; j--)
            {
                b = A[j];
                c = A[j - 1];
                if (c <= a - b)
                {

                }
                else
                {
                    ans = max(ans, a + b + c);
                    break;
                }
                if (b + c <= a)
                {
                    break;
                }
            }
        }

        return ans;
    }

};

int main()
{

//    vector<int> v = {3,6,2,3};
    vector<int> v = {3,2,3,4};

    LT0976 lt;

    cout<<lt.lt0976a(v)<<endl;

    return 0;
}
