
#include "../header/myheader.h"

class LT1442
{
public:

// D D

// a==b  <=>  a^b==0

//        for (int i = 0; i < length; i++) {
//            int xor = arr[i];
//            for (int j = i + 1; j < length; j++) {
//                xor ^= arr[j];
//                if (xor == 0) {
//                    ans += (j - i);
//                }
//            }
//        }

//        A.insert(A.begin(), 0);
//        int n = A.size(), res = 0;
//        for (int i = 1; i < n; ++i)
//            A[i] ^= A[i - 1];
//        unordered_map<int, int> count, total;
//        for (int i = 0; i < n; ++i) {
//            res += count[A[i]]++ * (i - 1) - total[A[i]];
//            total[A[i]] += i;
//        }
//        return res;
// ?...

//        int n = A.size(), res = 0, prefix = 0;
//        unordered_map<int, int> count = {{0, 1}}, total;
//        for (int i = 0; i < n; ++i) {
//            prefix ^= A[i];
//            res += count[prefix]++ * i - total[prefix];
//            total[prefix] += i + 1;
//        }
//        return res;


//Runtime: 84 ms, faster than 21.02% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
//Memory Usage: 8.2 MB, less than 18.64% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
// 1001  1010  0111
//       0011  0100
//             1101   == 1001&0100...
    int lt1442a(vector<int>& arr)
    {
        int memo[300][300] = {{0}};
        fill(begin(memo[0]), end(memo[0]), 0);
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            memo[i][i] = arr[i];
            for (int j = i + 1; j < arr.size(); ++j)
            {
                memo[i][j] = arr[j] ^ memo[i][j - 1];
            }
        }
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = i + 1; j < arr.size(); ++j)
            {
                int a = memo[i][j - 1];
                for (int k = j; k < arr.size(); ++k)
                {
                    if (memo[j][k] == a)
                        ans++;
                }
            }
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {2,3,1,6,7};
//    vector<int> v = {1,1,1,1,1};
//    vector<int> v = {2,3};
//    vector<int> v = {1,3,5,7,9};
    vector<int> v = {7,11,12,9,5,2,7,17,22};

    LT1442 lt;

    cout<<lt.lt1442a(v)<<endl;

    return 0;
}
