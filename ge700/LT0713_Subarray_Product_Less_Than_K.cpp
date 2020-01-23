
#include "../header/myheader.h"

class LT0713
{
public:


// d && d
// 代码都是一个 双重循环(基本是for/while + while)，大约10+行。 也有单层循环的。


//Runtime: 140 ms
//Memory Usage: 18.3 MB

    int lt0713b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int ans = 0;
        int prod = 0;
        int sna = 0;
        int i = 0;
        int j = 0;

        while (i < sz1 && nums[i] >= k)
            i++;
        if (i == sz1)
            return 0;
        j = i;
        prod = nums[j];
        sna++;
        for (; j < sz1 - 1 || prod >= k;)
        {
            if (prod >= k)
            {
                prod /= nums[j];
                j--;
                sna--;
                break;
            }
            else
            {
                j++;
                prod *= nums[j];
                sna++;
            }
        }
        #ifdef __test
        cout<<sna<<", "<<j<<", "<<prod<<endl;
        #endif // __test
        ans += sna;
        for (; i < sz1; i++)
        {
            if (j >= i)
            {
                prod /= nums[i];
                sna--;
            }
            else
            {
                prod = nums[i];
                sna = 1;
                j = i;
            }
            for (; j < sz1 - 1 || prod >= k;)
            {
                if (prod >= k)
                {
                    prod /= nums[j];
                    j--;
                    sna--;
                    break;
                }
                else
                {
                    j++;
                    prod *= nums[j];
                    sna++;
                }
            }
            #ifdef __test
            cout<<sna<<", "<<j<<", "<<prod<<endl;
            #endif // __test
            ans += sna;
        }

        return ans;
    }


    // 35 / 84 .. stack overflow....
    int lt0713a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();

        int arr[sz1][sz1] = {{0}};
        for (int i = 0; i < sz1; i++)
        {
            arr[0][i] = 0;
            arr[i][i] = nums[i] < k ? nums[i] : -1;
        }

//        for (int i = 0; i < sz1; i++)
//        {
//            for (int j = 0; j < sz1; j++)
//                cout<<arr[i][j]<<", ";
//            cout<<endl;
//        }

        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                if (arr[i][j - 1] < 0)
                {
                    arr[i][j] = -1;
                    break;
                }
                else
                {
                    int t1 = arr[i][j - 1] * nums[j];
                    if (t1 >= k)
                    {
                        arr[i][j] = -1;
                        break;
                    }
                    else
                    {
                        arr[i][j] = t1;
                    }
                }
            }
        }

        #ifdef __test
        for (int i = 0; i < sz1; i++)
        {
            for (int j = 0; j < sz1; j++)
            {
                cout<<arr[i][j]<<", ";
            }
            cout<<endl;
        }
        #endif // __test

        for (int i = 0; i < sz1; i++)
        {
            for (int j = i; j < sz1; j++)
            {
                if (arr[i][j] > 0)
                {
                    ans++;
                }
            }
        }

        return ans;
    }

};

int main()
{

//    vector<int> v = {10,5,2,6};
//    int k = 100;

//    vector<int> v = {1,2,3};
//    int k = 0;

//    vector<int> v = {1,1,1};
//    int k = 2;

//    vector<int> v = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
//    int k = 19;

//    vector<int> v = {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
//    int k = 19;

//    vector<int> v = {9,3};
//    int k = 19;

    vector<int> v(10, 1);
    v[5] = 6;
    v[7] = 7;
    int k = 5;
    for_each(v.begin(), v.end(), fun_cout);
    cout<<endl;

    LT0713 lt;

    cout<<lt.lt0713b(v, k)<<endl;

    return 0;
}
