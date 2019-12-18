
#include "../header/myheader.h"

class LT0481
{
public:

// magical_string += string(magical_string[index++] - '0', magical_string.back() ^ 3);
// count(magical_string.begin(), magical_string.begin() + n, '1');
// ..........



//Runtime: 8 ms, faster than 79.19% of C++ online submissions for Magical String.
//Memory Usage: 13 MB, less than 100.00% of C++ online submissions for Magical String.

    int lt0481a(int n)
    {
        queue<int> que1;
        int ans = n > 0;
        int t = 1;
//        que1.push(1);
//        que1.push(2);
        que1.push(2);

        int i = 3;
        int qf = 0;
        while (i <= n)           // i+que1.size < n
        {
            qf = que1.front();
            ans += (qf == 1);
            que1.pop();
            que1.push(t);
            if (qf > 1)
                que1.push(t);

            t = t % 2 + 1;
            i++;
        }
        return ans;
    }
};

int main()
{
    int n = 6;

    LT0481 lt;

    cout<<lt.lt0481a(n)<<endl;

    return 0;
}
