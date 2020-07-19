
#include "../header/myheader.h"

class LT0900
{
public:



};


// D D
//        while (curInd < seq.size()){
//            if (seq[curInd]>=n){
//                seq[curInd]-=n;
//                return seq[curInd+1];
//            }else{
//                n -= seq[curInd];
//                curInd += 2;
//            }
//        }
//        return -1;



//Runtime: 16 ms, faster than 17.65% of C++ online submissions for RLE Iterator.
//Memory Usage: 8.8 MB, less than 23.30% of C++ online submissions for RLE Iterator.

class RLEIterator {
    int i = -2;
    int cnt = -1;
    vector<int> v;
public:
    RLEIterator(vector<int>& A) {
        v = A;
        i = 0;
        cnt = A[i];
    }

    int next(int n) {
        while (cnt < n)
        {
            i += 2;
            if (i >= v.size())
            {
                cnt = -1;       // ...
                return -1;
            }
            n = n - cnt;
            cnt = v[i];
        }
        cnt -= n;
        return v[i + 1];
    }
};




int main()
{

    LT0900 lt;

    vector<int> a = {3,8,0,9,2,5};
    int arr[] = {21,1,1,2};


//["RLEIterator","next","next","next","next","next","next","next","next","next","next"]
//[[[811,903,310,730,899,684,472,100,434,611]],[358],[345],[154],[265],[73],[220],[138],[4],[170],[88]]


//    vector<int> a = {811,903,310,730,899,684,472,100,434,611};
//    int arr[] = {358,345,154,265,73,220,138,4,170,88};

    RLEIterator it(a);

    for (int i : arr)
    {
        cout<<it.next(i)<<endl;
    }

    return 0;
}
