
#include "../header/myheader.h"

class LT0740
{
public:
















/*
    1   1,2     13,2    14,13,24,   135,25,14,24    135,246,146,25,136
-1                                  024,14,03,13
-2                                                  13,24,24,3,14
                                                    max(3)+5, max(4)+6, max(4)+6, max(5)+0,max(3)+6
                                                    4zhong.
                                                    n : max(n-3)+n-1,  max(n-2)+n,  max(n-1),  max(n-3)+n
                                                    ..n-3 bu .
                                                    max(n-2)+n,max(n-3)+n, 且n-2,n-3 代表的值必须被取到。


13,14,24



*/

// discuss
// int[10003]...

// sum[i] = Max(sum[i-1], sum[i-2] + sum[i])
// 。。我的怎么是-2，-3。。。


//Runtime: 12 ms, faster than 40.63% of C++ online submissions for Delete and Earn.
//Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Delete and Earn.

    int lt0740a(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        map<int, int> map1;
        for (int n : nums)
            map1[n] += n;

        #ifdef __test
        for (pair<int, int> p : map1)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        #endif // __test

        int s = 0;
        int e = 0;
        int ans = 0;
        int j = map1.begin()->first;
        s = j;
        e = s;
        for (map<int, int>::iterator it = ++map1.begin(); it != map1.end(); it++)
        {
            if (it->first == j+1)
            {
                e = it->first;
                j++;
                continue;
            }
            ans += dpa1(s, e, map1);
            e = it->first;
            s = it->first;
            j = s;
        }
        ans += dpa1(s, e, map1);
        return ans;
    }

    int dpa1(int s, int e, map<int, int>& map1)
    {

    // 下面这2行一起，也是错的，报错就是variable-sized object may not be initialized
//        int len = e - s + 1;
//        int arr[len] = {0};
    // 但是后一行改成 int arr[len];      就通过了。。。就是{0}在编译时就知道了，但是此时arr这个变量还没有生成，编译器不知道把{0}的地址给谁。。但是为什么本地可以。。不知道舍弃了什么。

//        int arr[e - s + 1] = {0};         // ... lt 报编译错： 。variable-sized object may not be initialized

        int* arr = new int[e - s + 1];
        int i = s;
        if (i <= e)
            arr[i - s] = map1[s];
        i++;
        if (i <= e)
            arr[i - s] = map1[i];
        i++;
        if (i <= e)
            arr[i - s] = map1[i] + arr[0];
        i++;
        while (i <= e)
        {
            arr[i - s] = max(arr[i - s - 2], arr[i - s - 3]) + map1[i];
            i++;
        }

        #ifdef __test
        cout<<s<<", "<<e<<endl;
        for(int i = 0; i < e-s + 1; i++) cout<<arr[i]<<", ";
        cout<<endl;
        #endif // __test

        return max(arr[e - s], arr[(e - s - 1) < 0 ? 0 : (e - s - 1)]);
    }

};

int main()
{

    vector<int> arr = {2, 2, 3, 3, 3, 4};

    LT0740 lt;

    cout<<lt.lt0740a(arr)<<endl;

    return 0;
}
