
#include "../header/myheader.h"

class LT2334
{
public:

    // D D

    //vector<int> stk;                            // used as a stack
    //vector<int> nextS(n, -1), prevS(n, -1);     // used for storing next and previous smaller elements

    //// firstly, let's find out the next smaller elements
    //for (int i = 0; i < n; i++) {
    //    while (!stk.empty() && a[i] < a[stk.back()]) {
    //        nextS[stk.back()] = i;
    //        stk.pop_back();
    //    }
    //    stk.push_back(i);
    //}

    //// clear up our stack
    //stk.clear();


    //for (int i = n - 1; ~i; --i) {
    


    //vector<int> st;
    //nums.push_back(0);
    //for (int i = 0; i < nums.size(); ++i) {
    //    while (!st.empty() && nums[i] < nums[st.back()]) {
    //        int val = nums[st.back()]; st.pop_back();
    //        int j = st.empty() ? -1 : st.back();
    //        if (val > threshold / (i - j - 1))
    //            return i - j - 1;
    //    }
    //    st.push_back(i);
    //}


    //for (int i = 0; i < nums.size(); ++i)
    //    nums[i] = threshold / nums[i] + 1;
    //nums.push_back(INT_MAX);
    //vector<array<int, 2>> st;
    //for (int i = 0; i < nums.size(); ++i) {
    //    int cnt = 0;
    //    while (!st.empty() && st.back()[0] <= nums[i]) {
    //        cnt += st.back()[1];
    //        if (cnt >= st.back()[0])
    //            return cnt;
    //        st.pop_back();
    //    }
    //    st.push_back({ nums[i], cnt + 1 });
    //}




//Runtime: 442 ms, faster than 66.67 % of C++ online submissions for Subarray With Elements Greater Than Varying Threshold.
//Memory Usage : 89.4 MB, less than 33.33 % of C++ online submissions for Subarray With Elements Greater Than Varying Threshold.
    // ..或者说， 在 for 寻找 st,en 的时候， 计算下， 如果 满足就直接 return，而不必计算完st，en
    int lt2334b(vector<int>& nums, int threshold)
    {
        int sz1 = nums.size();
        stack<int> stk;
        vector<int> pre(sz1, -1);
        vector<int> suf(sz1, -1);

        stk.push(0);
        for (int i = 1; i < sz1; ++i)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();

            if (!stk.empty())
                pre[i] = stk.top();

            stk.push(i);
        }
        //stk.clear();
        stk = stack<int>();
        stk.push(sz1 - 1);
        for (int i = sz1 - 2; i >= 0; --i)
        {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            if (!stk.empty())
                suf[i] = stk.top();

            stk.push(i);
        }

        for (int i = 0; i < sz1; ++i)
        {
            int st = pre[i] + 1;
            int en = suf[i] == -1 ? sz1 - 1: suf[i] - 1;

            if (nums[i] > (1.0 * threshold / (en - st + 1)))
                return en - st + 1;
        }
        return -1;
    }



    // tle.
    // 对每个元素，找到 以这个元素是最低值 的 最长的subarray，然后看 能不能满足
    // 可以用 mono stack ， 保存前一个小于它的值。。 以及 后一个小于它的值。
    // 先forfor，如果tle，那么说明可以的。
    int lt2334a(vector<int>& nums, int threshold)
    {
        int sz1 = nums.size();
        for (int i = 0; i < sz1; ++i)
        {
            int st = i;
            int en = i;     // [st, en]
            int t2 = nums[i];
            while (st > 0 && nums[st - 1] >= t2)
                st--;
            while (en < sz1 - 1 && nums[en + 1] >= t2)
                en++;

            if (t2 > (1.0 * threshold / (en - st + 1)))
                return (en - st + 1);

        }
        return -1;
    }

};

int main()
{

    LT2334 lt;

    //myvi v = { 1,3,4,3,1 };
    //int t = 6;

    myvi v = { 6,5,6,5,7 };
    int t = 8;


    cout << lt.lt2334b(v, t) << endl;

    return 0;
}
