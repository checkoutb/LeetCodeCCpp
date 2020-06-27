
#include "../header/myheader.h"

class LT0985
{
public:


// D D
//int sum = accumulate(begin(A), end(A), 0, [](int s, int a) { return s + (a % 2 == 0 ? a : 0); });




// 不用int& (之前2处用到了，一处是 for(int& i : A), 还有一处是 int& t2 = A[queries[i][1]])
//Runtime: 220 ms, faster than 61.37% of C++ online submissions for Sum of Even Numbers After Queries.
//Memory Usage: 45.4 MB, less than 70.43% of C++ online submissions for Sum of Even Numbers After Queries.

// ？ 为什么这么慢？ 看D D 都差不多的代码啊，差别就是vector的创建，还有int&
//Runtime: 364 ms, faster than 5.09% of C++ online submissions for Sum of Even Numbers After Queries.
//Memory Usage: 45.6 MB, less than 67.55% of C++ online submissions for Sum of Even Numbers After Queries.
//Runtime: 340 ms, faster than 6.54% of C++ online submissions for Sum of Even Numbers After Queries.
//Memory Usage: 45.3 MB, less than 75.12% of C++ online submissions for Sum of Even Numbers After Queries.
    vector<int> lt0985a(vector<int>& A, vector<vector<int>>& queries)
    {
        int sum2 = 0;
        for (int i : A)
        {
            if (i % 2 == 0)
                sum2 += i;
        }
        int szq = queries.size();
        vector<int> ans(szq, 0);
        for (int i = 0; i < szq; i++)
        {
            int t2 = A[queries[i][1]];

            if (t2 % 2 == 0)
                sum2 -= t2;

            t2 += queries[i][0];
            if (t2 % 2 == 0)
                sum2 += t2;
            A[queries[i][1]] = t2;
            ans[i] = sum2;
        }
        return ans;
    }

};

int main()
{

    vector<int> a = {1,2,3,4};
    vector<vector<int>> q = {{1,0},{-3,1},{-4,0},{2,3}};

//    vector<int> a = {5,5,4};
//    vector<vector<int>> q = {{0,1},{1,0},{4,1}};


    LT0985 lt;

    vector<int> ans = lt.lt0985a(a, q);

    for_each(begin(ans), end(ans), fun_cout);
    cout<<endl;

    return 0;
}
