
#include "../header/myheader.h"

class LT1005
{
public:


// D D

//        for(int i = 0; i < K; i++){
//            A[index] = A[index] * -1;
//            if(A[index] > A[index+1])
//                index++;
//        }


//        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
//
//        for(int x: A) pq.add(x);
//        while( K--  > 0) pq.add(-pq.poll());



//Runtime: 8 ms, faster than 96.57% of C++ online submissions for Maximize Sum Of Array After K Negations.
//Memory Usage: 9.3 MB, less than 19.37% of C++ online submissions for Maximize Sum Of Array After K Negations.
    int lt1005a(vector<int>& A, int K)
    {
        std::sort(A.begin(), A.end());
        int mi = 0;
        int mii = -1;
        while (K-- > 0)
        {
            if (mii != -1)
            {
                A[mii] = -A[mii];
                continue;
            }
            if (A[mi] < 0)
            {
                A[mi] = -A[mi];
                mi++;
            }
            else if (A[mi] == 0)
            {
                mii = mi;
            }
            else
            {
//                if (mii != -1)
//                {
//                    A[mii] = -A[mii];
//                }
//                else
//                {
                    if (mi == 0)
                    {
                        mii = 0;
                    }
                    else
                    {
                        if (A[mi] > A[mi - 1])
                        {
                            mii = mi - 1;
                        }
                        else
                        {
                            mii = mi;
                        }
                    }
                    A[mii] = -A[mii];
//                }
            }
        }
        return std::accumulate(begin(A), end(A), 0);
    }

};

int main()
{

//    vector<int> v = {4,2,3};
//    int k = 1;
//    vector<int> v = {3,-1,0,2};
//    int k = 3;

    vector<int> v = {2,-3,-1,5,-4};
    int k = 2;

    LT1005 lt;

    cout<<lt.lt1005a(v, k);

    return 0;
}
