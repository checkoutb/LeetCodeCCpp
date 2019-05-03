
#include "../header/myheader.h"

class LT0330
{
public:

    // gg...

    // StefanPochmann
//    long miss = 1, added = 0, i = 0;
//    while (miss <= n) {
//        if (i < nums.size() && nums[i] <= miss) {
//            miss += nums[i++];
//        } else {
//            miss += miss;
//            added++;
//        }
//    }
//    return added;


    // 2的次方 + 非2次方。
    int lt0330e(vector<int>& nums, int n)
    {
        int sz1 = nums.size();
        int result = 0;
        long long i = 1;
        int j = 0;
        long long t1 = 0;
        long long k = 0;
        for (; (i + k) < n;)
        {
            for (; j < sz1; j++)
            {
                if (nums[j] >= i)
                {
                    break;
                }
            }
            #ifdef __test
            cout<<j<<","<<nums[j]<<","<<i<<endl;
            #endif // __test
            if (nums[j] == i)
            {
                j++;
            }
            else
            {
                cout<<"add..."<<i<<endl;
                result++;
            }
            k = i + 1;
            while (nums[j] <= k)
            {
                t1 += nums[j];
                j++;
                k++;
            }
            i *= 2;

            #ifdef __test
            cout<<i<<","<<k<<","<<t1<<","<<result<<endl;
            system("pause");
            #endif // __test

        }
        return result;
    }


    // 2的次方。重复数。
    int lt0330d(vector<int>& nums, int n)
    {
        int sz1 = nums.size();
        int result = 0;
        long long i = 1;
        int j = 0;
        for (; i < n; i++)
        {
//            j = 0;
            for (; j < sz1; j++)
            {
                if (nums[j] == i)
                {
                    while (nums[j] == i)
                    {
                        j++;
                        i++;
                    }
                    j--;
                    i--;
                    break;
                }
                if (nums[j] > i)
                {
                    result++;
                    while (nums[j] == (i + 1))
                    {
                        j++;
                        i++;
                    }
                    j--;
                    i--;
                    break;
                }
            }
            i *= 2;
        }
        return result;
    }


// deprecated
    int lt0330c(vector<int>& nums, int n)
    {
        int sz1 = nums.size();
        int result = 0;
        long long i = 1;
        int j = 0;
        int t1 = 0;
        bool flag = true;
        while (i < n)
        {
            while (flag && j < sz1)
            {
                if (nums[j] > i)
                {
                    break;
                }
                else if (nums[j] == i)
                {
                    break;
                }
                j++;
            }
            if (j < sz1)
            {
                t1 = nums[j];
            }
            else
            {
                t1 = -1;
                flag = false;
            }

            if (flag)
            {
                if (t1 != i)
                {
                    result++;
                }
                else
                {
                    j++;
                }
            }

            if (flag)
            {
                while (j < sz1)
                {
                    if (nums[j] == (i + 1))
                    {
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            i = i * 2;
        }
        return result;
    }


    // 加入一个数x后，会增加[x, x*2 - 1]
    // deprecated
    int lt0330b(vector<int>& nums, int n)
    {
        int sz1 = nums.size();
        int result = 0;
        long long i = 1;                    // ..... long是32位的。。和int一样。。。。。。。。。
        int j = 0;
        int max1 = nums[sz1 - 1];
        do
        {
            j = 0;
            if (i <= max1)
            {
                for (; j < sz1; j++)
                {
                    if (nums[j] < i)
                        continue;
                    else if (nums[j] == i)
                        break;
                    else
                    {
                        result++;
                        j--;
                        break;
                    }
                }
//                for (j++; j < sz1; j++)
//                {
//                    if (nums[j] != nums[j - 1] + 1)
//                        break;
//                }
                j++;
                while (nums[j] == i)
                {
                    i++;
                    j++;
                }
//                i = nums[j - 1];
            }
            else
            {
                j = -1;
                result++;
            }

            i = i * 2;

            #ifdef __test
            cout<<i<<endl;
//            system("pause");
            #endif // __test

        } while(i < n);

        return result;
    }

    // n == INT_MAX..... stack overflow
    // deprecated
    int lt0330a(vector<int>& nums, int n)
    {
        int result = 0;
        bool arr[(long)(n) + 1] = {};       // {},{0}一样，如果没有初始化，输出是随机int值。

        #ifdef __test
        for (auto p : arr)
        {
            cout<<p<<",";
        }
        cout<<endl;
        #endif // __test

        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
        {
            for (long i = n; i > 0; i--)         // 大到小。不然重复累加。
            {
                if (!arr[i])
                    continue;
                if ((i + (*it)) <= n)
                    arr[i + (*it)] = true;
            }
            arr[*it] = true;
        }

        #ifdef __test
        for (auto p : arr)
            cout<<p<<",";
        cout<<endl;
        #endif // __test


        for (long i = 1; i <= n; i++)
        {
            if (arr[i])
                continue;
            result++;

            for (long j = n; j > 0; j--)
            {
                if (!arr[j])
                    continue;
                if ((i + j) <= n)           // 本地不报错。。。leetcode报错越界。。不知道用的是哪个编译器。。
                    arr[i + j] = true;
            }
            arr[i] = true;
        }

        return result;
    }
};

int main()
{
//    vector<int> v = {1,3};
//    int n = 6;

    vector<int> v = {1,5,10};
    int n = 20;

//    cout<<INT_MAX<<endl;

//    vector<int> v = {1,2,31,33};
//    int n = 2147483647;

//    vector<int> v = {};
//    int n = 7;

    LT0330 lt;
    cout<<endl<<lt.lt0330e(v, n);

    return 0;
}
