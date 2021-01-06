
#include "../header/myheader.h"

class LT0888
{
public:

// D D


//        bitset<200002> bf;
//        for(auto n: B) {
//            sumB += n;
//            bf.set(2*n);
//        }
//        for(auto n: A) {
//            int det = 2*n - diff;
//            if(det > 0 && det < 200002 && bf.test(det)) {
//                return {n, (2*n-diff)/2};
//            }
//        }




//Runtime: 168 ms, faster than 81.67% of C++ online submissions for Fair Candy Swap.
//Memory Usage: 47.3 MB, less than 73.49% of C++ online submissions for Fair Candy Swap.
    vector<int> lt0888a(vector<int>& A, vector<int>& B)
    {
        int suma = std::accumulate(begin(A), end(A), 0);
        int sumb = std::accumulate(begin(B), end(B), 0);
        int t2 = (sumb - suma) / 2;
        unordered_set<int> setb(begin(B), end(B));
        for (int i = 0; i < A.size(); ++i)
        {
            if (setb.find(A[i] + t2) != setb.end())
            {
                return {A[i], A[i] + t2};
            }
        }
        return {-1,-1};
    }

};

int main()
{
//    myvi va = {1,1};
//    myvi vb = {2,2};

//    myvi va = {1,2};
//    myvi vb = {2,3};

//    myvi va = {2};
//    myvi vb = {1,3};

    myvi va = {1,2,5};
    myvi vb = {2,4};

    LT0888 lt;

    myvi v = lt.lt0888a(va,vb);

    cout<<v[0]<<" : " <<v[1]<<endl;

    return 0;
}
