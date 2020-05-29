
#include "../header/myheader.h"

class LT0823
{
public:









// error  27/47 ...
    int lt0823b(vector<int>& A)
    {
        std::sort(A.begin(), A.end());
        int arr[1001] = {0};
        int sz2 = A.size();
        for (int i = 0; i < sz2; i++)
        {
            arr[i] = 1;
        }
        for (int i = 0; i < sz2; i++)
        {
            int val1 = A[i];
            for (int j = i; j < sz2; j++)
            {
                int val2 = A[j];
                long prod = ((long) val1) * val2;
                auto p = std::find(A.begin(), A.end(), prod);
                if (p != A.end())
                {
                    if (val1 == val2)
                    {
                        arr[p - A.begin()] += arr[i] * arr[j];
                    }
                    else
                    {
                        arr[p - A.begin()] += (arr[i] * arr[j]) * 2;
                    }
                }
            }
        }
        int ans = 0;

        #ifdef __test
        for_each(begin(arr), begin(arr) + 20, fun_cout);
        cout<<endl;
        #endif // __test

        for (int i = 0; i < 1001; i++)
        {
            ans += arr[i];
        }
        return ans;
    }

// ..
    int lt0823a(vector<int>& A)
    {
        std::sort(A.begin(), A.end());
        int mxc = std::sqrt(1e9);
        vector<int> products(A.size(), -1);
        for (int i = 0; i < A.size() && A[i] <= mxc; i++)
        {
            products[i] = A[i] * A[i];
        }
        int ans = 0;

        for (int i = 0; i < A.size() && A[i] != -1; i++)
        {
            for (int j = 0; j < A.size() && A[j] != -1; j++)
            {

            }
        }

        return ans;
    }

};

int main()
{

//    cout<<(int)1e9<<endl;
//    cout<<LONG_MAX<<endl;
//    long l2 = LONG_MAX;
//    cout<<l2<<endl;
//    cout<<LLONG_MAX<<endl;
//
//    cout<<endl<<"-------------"<<endl<<endl;

//    vector<int> a = {2, 4, 5, 10};
//    vector<int> a = {18,3,6,2};

// 777
    vector<int> a = {45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,759,
    37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48};

    LT0823 lt;

    cout<<lt.lt0823b(a)<<endl;

    return 0;
}
