
#include "../header/myheader.h"

class LT1007
{
public:






    int lt1007b(vector<int>& A, vector<int>& B)
    {
        int arr1[7] = {0};
        int arr2[7] = {0};
        std::fill(begin(arr1), end(arr1), -1);
        std::fill(begin(arr2), end(arr2), -1);
        arr1[A[0]] = 0;
        arr1[B[0]] = 1;
        arr2[A[0]] = 1;
        arr2[B[0]] = 0;

        for (int i = 1; i < A.size(); i++)
        {

        }

        return -3;

    }


// error
    int lt1007a(vector<int>& A, vector<int>& B)
    {
        int arr[7] = {0};
        std::fill(begin(arr), end(arr), -1);
        arr[A[0]] = 0;
        arr[B[0]] = 1;
        int arr2[7] = {0};
        std::fill(begin(arr2), end(arr2), -1);
        arr2[A[0]] = 1;
        arr2[B[0]] = 0;
        for (int i = 1; i < A.size(); i++)
        {
            if (arr[A[i]] != -1)
            {

            }
            else if (arr[B[i]] != -1)
            {
                arr[B[i]]++;
            }


            if (arr2[B[i]] != -1)
            {

            }
            else if (arr2[A[i]] != -1)
            {
                arr2[A[i]]++;
            }
            for (int j = 1; j < 7; j++)
            {
                if (j == A[i] || j == B[i])
                    continue;
                if (arr[j] != -1)
                    arr[j] = -1;
                if (arr2[j] != -1)
                    arr2[j] = -1;
            }

        }
        int ans = INT_MAX;
        #ifdef __test
        for_each(begin(arr), end(arr), fun_cout);
        cout<<endl;
        for_each(begin(arr2), end(arr2), fun_cout);
        cout<<endl;
        #endif // __test
        for (int i = 1; i < 7; i++)
        {
            if (arr[i] != -1)
            {
                ans = min(ans, min(arr[i], (int) A.size() - arr[i]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

//    vector<int> A = {2,1,2,4,2,2};
//    vector<int> B = {5,2,6,2,3,2};

    vector<int> A = {1,2,1,1,1,2,2,2};
    vector<int> B = {2,1,2,2,2,2,2,2};


    LT1007 lt;

    cout<<lt.lt1007a(A, B);

    return 0;
}
