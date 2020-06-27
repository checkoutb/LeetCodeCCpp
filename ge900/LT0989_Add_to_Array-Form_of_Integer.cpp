
#include "../header/myheader.h"

class LT0989
{
public:

//Runtime: 92 ms, faster than 38.43% of C++ online submissions for Add to Array-Form of Integer.
//Memory Usage: 29.9 MB, less than 5.11% of C++ online submissions for Add to Array-Form of Integer.
    vector<int> lt0989a(vector<int>& A, int K)
    {
        queue<int> que2;

        while (K > 0)
        {
            que2.push(K % 10);
            K /= 10;
        }
        int mxsz1 = max(A.size(), que2.size());
        int minsz1 = min(A.size(), que2.size());
        int jinwei = 0;
        int sza = A.size();
        vector<int> ans;

        for (int i = 0; i < mxsz1; i++)
        {
            int k2 = jinwei;
            if (!que2.empty())
            {
                k2 += que2.front();
                que2.pop();
            }

                                                    // Line 924: Char 34: runtime error: addition of unsigned offset to 0x6020000008b0 overflowed to 0x6020000008ac (stl_vector.h)
//            if (A.size() - 1 - i >= 0 && A.size() - 1 - i < A.size())           // ? 后半个不是必然成立吗？为什么没有后半个的时候，leetcode会报错？
            if (sza - 1 - i >= 0)                   // 。。。 估计是因为 只有前半个的时候 A.size() - 1 - i 是unsigned。 加上后半个后，就转成signed int了。  这行就不会报错。
                k2 += A[sza - i - 1];

            ans.push_back(k2 % 10);
            jinwei = k2 / 10;
        }
        if (jinwei > 0)
            ans.push_back(jinwei);
        vector<int> result(ans.rbegin(), ans.rend());
        return result;
    }

};

int main()
{

//    vector<int> v = {1,2,0,0};
//    int k = 34;

//    vector<int> v = {2,1,5};
//    int k = 806;

    vector<int> v = {0};
    int k = 23;

    LT0989 lt;

    vector<int> ans = lt.lt0989a(v, k);

    for_each(ans.begin(), ans.end(), fun_cout);
    cout<<endl;

    return 0;
}
