
#include "../header/myheader.h"

class LT1073
{
public:

// D D

//    vector<int> addBinary(vector<int>& A, vector<int>& B) {
//        vector<int> res;
//        int carry = 0, i = A.size() - 1, j = B.size() - 1;
//        while (i >= 0 || j >= 0 || carry) {
//            if (i >= 0) carry += A[i--];
//            if (j >= 0) carry += B[j--];
//            res.push_back(carry & 1);
//            carry = (carry >> 1);
//        }
//        reverse(res.begin(), res.end());
//        return res;
//    }
//
//    vector<int> addNegabinary(vector<int>& A, vector<int>& B) {
//        vector<int> res;
//        int carry = 0, i = A.size() - 1, j = B.size() - 1;
//        while (i >= 0 || j >= 0 || carry) {
//            if (i >= 0) carry += A[i--];
//            if (j >= 0) carry += B[j--];
//            res.push_back(carry & 1);
//            carry = -(carry >> 1);                // 就这里 和 正数2 不同。
//        }
//        while (res.size() > 1 && res.back() == 0)
//            res.pop_back();
//        reverse(res.begin(), res.end());
//        return res;
//    }



//Runtime: 4 ms, faster than 98.96% of C++ online submissions for Adding Two Negabinary Numbers.
//Memory Usage: 19.5 MB, less than 58.33% of C++ online submissions for Adding Two Negabinary Numbers.

// 1 -2 4 -8 16 -32 64 -128 256 -512 1024
// 1 -2 -1 4 5 2 3 -8 -7 -10 -9 -4 -3 -6 -5
// 1 4 16 64 256
// -2 -8 -32 -128
// 等于 低位*-2 。
// 1 1 1 1 1
//     1 0 1
//         0  2
//       0    0
//     0         1
//   0
// 1
// 1 0 1    5
// 0 0 1    1
//     0  1     2
//   1    1    -2
// 0
// 1
// 0 0 0 1 0 1
// 0 0 0 0 0 1
//           0  1
//         1    -1
//       0      1
//     1
//   1
    vector<int> lt1073a(vector<int>& arr1, vector<int>& arr2)
    {
        vector<int> ans;
        int idx1 = arr1.size() - 1;
        int idx2 = arr2.size() - 1;
        int t2 = 0;
        while (idx1 >= 0 || idx2 >= 0 || t2 != 0)
        {
            t2 *= -1;
            int v1 = idx1 >= 0 ? arr1[idx1--] : 0;
            int v2 = idx2 >= 0 ? arr2[idx2--] : 0;
            int v3 = v1 + v2 + t2;

            #ifdef __test
            cout<<v3<<", "<<t2<<endl;
            #endif // __test

            if (v3 < 0)
            {
                t2 = -1;
                ans.push_back(1);
            }
            else
            {
                ans.push_back(v3 % 2);
                t2 = v3 / 2;
            }
//            idx1--;
//            idx2--;
        }
        while (ans.back() == 0 && ans.size() > 1)
            ans.pop_back();

        std::reverse(begin(ans), end(ans));
        return ans;
    }

};

int main()
{
//    myvi v = {1,1,1,1,1};
//    myvi v2 = {1,0,1};

    myvi v = {1};
    myvi v2 = {1};

    LT1073 lt;

    myvi v3 = lt.lt1073a(v, v2);

    showVectorInt(v3);

    return 0;
}
