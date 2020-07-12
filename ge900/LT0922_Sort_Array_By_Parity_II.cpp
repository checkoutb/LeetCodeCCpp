
#include "../header/myheader.h"

class LT0922
{
public:

// D D
//static auto fast = [](){
//    ios::sync_with_stdio(0);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    return 0;
//}();
// ...

//        for(int i=0;i<n;++i){
//            if(a[i] % 2 != i % 2){
//                int j = i;
//                int parity = i & 1;
//                while(j < n && (a[j] & 1) != parity)
//                    ++j;
//                swap(a[i], a[j]);
//            }
//        }


//    for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
//        while (i < A.size() && A[i] % 2 == 0) i += 2;
//        while (j < A.size() && A[j] % 2 == 1) j += 2;
//        if (i < A.size()) swap(A[i], A[j]);
//    }
// 各自的第一个不符合


//Runtime: 36 ms, faster than 96.71% of C++ online submissions for Sort Array By Parity II.
//Memory Usage: 21.6 MB, less than 54.62% of C++ online submissions for Sort Array By Parity II.
    vector<int> lt0922a(vector<int>& A)
    {
        int oddi = 1;
        int eveni = 0;
        vector<int> ans(A.size(), 0);
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 1)
            {
                ans[oddi] = A[i];
                oddi += 2;
            }
            else
            {
                ans[eveni] = A[i];
                eveni += 2;
            }
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {4,2,5,7};

    LT0922 lt;

    vector<int> ans = lt.lt0922a(v);

    for_each(begin(ans), end(ans), fun_cout);
    cout<<endl;

    return 0;
}
