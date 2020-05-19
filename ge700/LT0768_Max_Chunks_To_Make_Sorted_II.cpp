
#include "../header/myheader.h"

class LT0768
{
public:



// d && d
// stack
//        for (int i = 0; i < n; i++)
//        {
//            if (st.empty() || arr[i] >= st.top()) st.push(arr[i]);
//            else {
//                int curMax = st.top();
//                st.pop();
//                while (!st.empty() && st.top() > arr[i]) st.pop();
//                st.push(curMax);
//            }
//        }
//
//        return st.size();
// pop的时候，判断了，所以保存的是小于arr[i]的数，遍历完，stack中就是保存了所有大于前面，小于后面的数。
// curMax/top 是到当前下标最大的数。如果大于top,那么就能作为一个划分。

// 排序后，sum1 sum2  如果2个sum相等，就ans++。。



// error。
// 。。。 不能排序后 对比。。。[5,4,3,2,1]...[1,2,3,4,5]     。。 下标2，3==3，认为可以划分。。
    int lt0768b(vector<int>& arr)
    {
        vector<int> arr2(arr);
        std::sort(arr2.begin(), arr2.end());

        #ifdef __test
        for_each(arr.begin(), arr.end(), fun_cout);
        cout<<endl;
        for_each(arr2.begin(), arr2.end(), fun_cout);
        cout<<endl;
        #endif // __test

        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == arr2[i])
                ans++;
        }
        return ans + 1;
    }




//Runtime: 16 ms, faster than 54.29% of C++ online submissions for Max Chunks To Make Sorted II.
//Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Max Chunks To Make Sorted II.

// 769 discuss...有个leftMax, rightMin... 实际上，只要sort下，然后sort后的数组和sort前的数组，同一个下标的值相等，就可以++。 就是快速排序。
// ans + 1... 是因为，ans代表的是 划分点， 1个划分点可以划分出2个部分， n个划分点可以得到n+1个部分。
    int lt0768a(vector<int>& arr)
    {
        int ans = 0;
        vector<int> leftMax(arr.size(), 0);
        vector<int> rightMin(arr.size(), 0);
        int m32 = arr[0];
        int sz11 = arr.size() - 1;
        leftMax[0] = arr[0];
        rightMin[sz11] = arr[sz11];
        for (int i = 1; i <= sz11; i++)
        {
            leftMax[i] = max(arr[i], leftMax[i - 1]);
            rightMin[sz11 - i] = min(arr[sz11 - i], rightMin[sz11 - i + 1]);
        }

        #ifdef __test
        for_each(leftMax.begin(), leftMax.end(), fun_cout);
        cout<<endl;
        for_each(rightMin.begin(), rightMin.end(), fun_cout);
        cout<<endl;
        #endif // __test

        for (int i = 0; i < sz11; i++)
        {
            if (leftMax[i] <= rightMin[i + 1])
                ans++;
        }
        return ans + 1;
    }

};

int main()
{

    vector<int> v2 = {2,1,3,4,4};

    LT0768 lt;

    cout<<lt.lt0768b(v2)<<endl;

    return 0;
}
