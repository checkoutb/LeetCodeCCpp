
#include "../header/myheader.h"

class LT1646
{
public:

// D D

//        if (f[2] == 0) {
//            for (int i = 2; i <= 100; ++i)
//                f[i] = i % 2 ? f[i / 2] + f[i / 2 + 1] : f[i / 2];
//            for (int i = 2; i <= 100; ++i)
//                f[i] = max(f[i], f[i - 1]);
//        }
//        return f[n];



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Get Maximum in Generated Array.
//Memory Usage: 6.2 MB, less than 95.65% of C++ online submissions for Get Maximum in Generated Array.
    int lt1646b(int n)
    {
        if (n == 0)
            return 0;
        int ans = 0;
        int arr[101] = {0};
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (i % 2)
            {
                arr[i] = arr[i / 2] + arr[i / 2 + 1];
            }
            else
            {
                arr[i] = arr[i / 2];
            }
        }
        #ifdef __test
        for (int i = 0; i <= n; ++i)
            cout<<arr[i]<<", ";
        cout<<endl;
        #endif // __test
        for (int i : arr)
            ans = max(ans, i);
        return ans;
    }


// error
// maximum ...
    int lt1646a(int n)
    {
        int ans = 0;
        queue<int> que1;
        que1.push(n);
        while (!que1.empty())
        {
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                int t2 = que1.front();
                que1.pop();
                switch(t2)
                {
                case 0:
                    break;
                case 1:
                    ans += 1;
                    break;
                default:
                    if (t2 % 2 == 1)
                    {
                        que1.push(t2 / 2);
                        que1.push(t2 / 2 + 1);
                    }
                    else
                    {
                        que1.push(t2 / 2);
                    }
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{
    myvi v = {7,2,3,4};

    LT1646 lt;

    for (int i : v)
        cout<<lt.lt1646b(i)<<endl;

    return 0;
}
