
#include "../header/myheader.h"

class LT0738
{
public:


// discuss
// to_string, 从后向前遍历，如果不符合递增，则记录下标，前一位-1，遍历完后，下标就是第一个不符合递增的位置，并且这个位置的前一位已经-1，所以从这个位置开始到最后全9就可以了。
// stoi


//Runtime: 4 ms, faster than 19.29% of C++ online submissions for Monotone Increasing Digits.
//Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Monotone Increasing Digits.
// 不符合递增的时候，前一位-1，自己及后续全9，然后判断前一位是否符合递增。
    int lt0738a(int N)
    {
        vector<int> v1;
        while (N > 0)
        {
            int n = N % 10;
            N /= 10;
            v1.insert(v1.begin(), n);
        }
        vector<int> v2(v1);
        for (int i = 1; i < v2.size(); i++)
        {
            if (i == 0)
                continue;
            if (v2[i] < v2[i - 1])
            {
                v2[i - 1]--;
                for (int j = i; j < v2.size(); j++)
                {
                    v2[j] = 9;
                }
                i -= 2;
            }
        }
        int ans = 0;
        for (int i = 0; i < v2.size(); i++)
        {
            ans *= 10;
            ans += v2[i];
        }
        return ans;
    }

};

int main()
{

    int arr[] = {10, 1234, 332};

    LT0738 lt;

    for (int n : arr)
        cout<<lt.lt0738a(n)<<endl;

    return 0;
}
