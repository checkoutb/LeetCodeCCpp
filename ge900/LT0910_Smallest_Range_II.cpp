
#include "../header/myheader.h"

class LT0910
{
public:


// D
//            int maxi = max(A[i] + K, right), mini = min(left, A[i + 1] - K);
//            res = min(res, maxi - mini);
//there are two segments (A[0]+K, A[1]+K, ..., A[i]+K, A[i+1]-K, ..., A[n]-K),
//the first one is on the left of the current point (A[i] + K is the last element of the first segment),
//the second one is on the right of the current point (A[i + 1] - K is the first element of the second segment).


//It's the same as:
//For each integer A[i], we may choose either x = 0 or x = 2 * K.


// error
    int lt0910a(vector<int>& A, int K)
    {
        int mx = *std::max_element(begin(A), end(A));
        int mn = *std::min_element(begin(A), end(A));
        if ((mx - mn) <= K)
        {
            return mx - mn;
        }
        int t1 = mx - mn;
        double avg = (mx + mn) / 2.0;
        mx = INT_MIN;
        mn = INT_MAX;
        for (int& a : A)
        {
            int t2 = 0;
            if (a > avg)
            {
                t2 = a - K;
            }
            else
            {
                t2 = a + K;
            }
            mx = max(mx, t2);
            mn = min(mn, t2);
        }
        return min(mx - mn, t1);
    }

};

int main()
{

//    vector<int> a = {1};
//    int k = 0;

//    vector<int> a = {0,10};
//    int k = 2;

    vector<int> a = {1,3,6};
    int k = 30;

    LT0910 lt;

    cout<<lt.lt0910a(a, k)<<endl;

    return 0;
}
