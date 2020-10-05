
#include "../header/myheader.h"

class LT0667
{
public:


// D D
// res[i] = k > 1 ? (k-- % 2 != 0 ? l++ : r--) : l++;


//    a = range(1, n+1)
//    for i in range(1, k):
//        a[i:] = a[:i-1:-1]
// py

//  a = (1..n).to_a
//  (1...k).each { |i| a[i..-1] = a[i..-1].reverse }
// ruby



//Runtime: 4 ms, faster than 76.17% of C++ online submissions for Beautiful Arrangement II.
//Memory Usage: 7.7 MB, less than 54.70% of C++ online submissions for Beautiful Arrangement II.

// 升序，1个差
// 升序，然后把1放最后，就是 2个差。 (1,2)。。不算。 k<n
// 升序，把2放最后，就是3个差。 1,3,4,5,2        1,3,2, k<n。 。。 把不是1,n的任意数放最后，大概率是3，小概率是2。 1，3，4，2 就是2。 移动一个后，多出一个差额2，所以 max-移动的数 != 2.
// k=4, 选2个，移除，多出一个2/3的差额。然后 max-某个移除数  和 另一个移除数-1  需要 是 distinct的。

// min mx mn mx mn mx mn mx mx-1 mx-2...
    vector<int> lt0667a(int n, int k)
    {
        vector<int> ans(n, 0);
        int mn = 1;
        int mx = n;
        ans[0] = mn++;
        int i = 1;
        while (k > 1)
        {
            if (ans[i - 1] < mx)
            {
                ans[i] = mx--;
            }
            else
            {
                ans[i] = mn++;
            }
            i++;
            k--;
        }
        if (i != n)
        {
            int step = (ans[i - 1] < mx ? 1 : -1);
            int st = (step < 0 ? mx : mn);
            for (; i < n; i++, st += step)
            {
                ans[i] = st;
            }
        }
        return ans;
    }

};

int main()
{
    int n{3}, k{2};

    LT0667 lt;

    vector<int> v = lt.lt0667a(n, k);

    for_each(begin(v), end(v), fun_cout);
    cout<<endl;

    return 0;
}
