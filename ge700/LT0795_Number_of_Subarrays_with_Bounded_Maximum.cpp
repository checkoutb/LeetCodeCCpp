
#include "../header/myheader.h"

class LT0795
{
public:



// D D
//        int result=0, left=-1, right=-1;
//        for (int i=0; i<A.size(); i++) {
//            if (A[i]>R) left=i;
//            if (A[i]>=L) right=i;
//            result+=right-left;
//        }
//        return result;




//Runtime: 104 ms, faster than 7.39% of C++ online submissions for Number of Subarrays with Bounded Maximum.
//Memory Usage: 32.7 MB, less than 16.67% of C++ online submissions for Number of Subarrays with Bounded Maximum.
    int lt0795d(vector<int>& A, int L, int R)
    {
        int ans = 0;
        int sz2 = A.size();
//        vector<int> arr(sz2, 0);
        int mx = 0;
        for (int i = 0; i < sz2; i++)
        {
            mx = A[i];
            if (mx >= L && mx <= R)
                ans++;
            for (int j = i + 1; j < sz2; j++)
            {
                mx = max(mx, A[j]);
                if (mx >= L && mx <= R)
                    ans++;
                if (mx > R)
                    break;
            }
        }
        return ans;
    }


// 38 / 43  Memory Limit Exceeded
    int lt0795c(vector<int>& A, int L, int R)
    {
        int sz2 = A.size();
        vector<vector<int>> arr(sz2, vector<int>(sz2));
        for (int i = 0; i < sz2; i++)
        {
            arr[i][i] = A[i];
            for (int j = i + 1; j < sz2; j++)
            {
                arr[i][j] = max(arr[i][j - 1], A[j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < sz2; i++)
        {
            for (int j = i; j < sz2; j++)
            {
                if (arr[i][j] >= L && arr[i][j] <= R)
                    ans++;
            }
        }
        return ans;
    }


// ........ not the sum of subarray, the max of subarray....
    int ans = 0;
    int lt0795b(vector<int>& A, int L, int R)
    {
        set<int> set2;
        for (int i = 0; i < A.size(); i++)
        {
            set2.insert(i);
            dfsb1(A, L, R, i + 1, A[0], set2);
            set2.clear();
        }
        return ans;
    }

    void dfsb1(vector<int>& A, int L, int R, int i, int sum, set<int> set2)
    {
        if (sum > R)
            return;
        if (i == A.size())
        {
            cout<<" "<<sum<<endl;
            if (sum >= L && sum <= R)
            {

            for (int i : set2)
            {
                cout<<i<<" + ";
            }
            cout<<endl;
                ans++;
            }
            return;
        }
        dfsb1(A, L, R, i + 1, sum, set2);
//        sum += A[i];
//        if (sum >= L && sum <= R)
//        {
//            ans++;
//        }
        set2.insert(i);
        dfsb1(A, L, R, i + 1, sum + A[i], set2);
    }



// [2 9 2 5 6] error
//标准库类型将size_type定义为unsigned类型
    int lt0795a(vector<int>& A, int L, int R)
    {
        int i = -1;
        int sum = 0;
        int ans = 0;
        for (int j = 0; j < A.size(); j++)
        {
            while ((i < int(A.size()) - 1) && sum < L)
            {
                i++;
                sum += A[i];
            }
            int k = i;
            int sum2 = sum;
            while (k < A.size())
            {
                if (sum2 >= L && sum2 <= R)
                {
                    #ifdef __test
                    cout<<sum2<<", "<<i<<", "<<k<<endl;
                    #endif // __test
                    ans++;
                }
                else
                    break;
                k++;
                if (k < A.size())
                    sum2 += A[k];
            }

            sum -= A[j];
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {2, 1, 4, 3};
    int l = 2, r = 3;

    // Expected 7 ? 不是说连续的subarray吗？         Return the number of (contiguous, non-empty) subarrays
    // 0, 2, 23, 3, 4,       7就不可能连续啊，会出现24这个子数组 还有02这个
//    vector<int> v = {2,9,2,5,6};
//    int l = 2;
//    int r = 8;

    LT0795 lt;

    cout<<lt.lt0795c(v, l, r)<<endl;

    return 0;
}
