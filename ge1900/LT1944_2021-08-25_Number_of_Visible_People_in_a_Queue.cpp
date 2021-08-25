
#include "../header/myheader.h"

class LT1944
{
public:

// D

//    for (int i = heights.size() - 1; i >= 0; --i) {
//        int h = heights[i], cnt = 0;
//        for (; !mono.empty() && mono.back() < h; ++cnt)
//            mono.pop_back();
//        heights[i] = cnt + !mono.empty();
//        mono.push_back(h);
//    }
// 记录的是 移除的个数。。。


//        for (int i = 0; i < n; ++i) {
//            while (!stack.empty() && A[stack.back()] <= A[i])
//                res[stack.back()]++, stack.pop_back();
//            if (!stack.empty())
//                res[stack.back()]++;
//            stack.push_back(i);
//        }


// g


    vector<int> lt1944d(vector<int>& heights)
    {

    }


// error...
// 感觉是反向的。 stack。
// hint。。。 好像不需要单调。。。
// 不，始终搞不清 3,2,1 这种。 结果应该是 1,1,0
    vector<int> lt1944c(vector<int>& heights)
    {
        stack<int> stk1;
        int sz1 = heights.size();
        vector<int> ans(sz1);
        stk1.push(heights[sz1 - 1]);
        for (int i = sz1 - 2; i >= 0; --i)
        {
            while (!stk1.empty() && stk1.top() > heights[i])
            {
                stk1.pop();
            }
            stk1.push(heights[i]);
            ans[i] = stk1.size();
        }
        return ans;
    }


//..... buxing
// unique, 所以能维持一个 单调增队列。
    vector<int> lt1944b(vector<int>& heights)
    {
        int sz1 = heights.size();
        vector<int> ans(sz1);
        vector<int> que1;
        int mx = -1;
        for (int i = 1; i < sz1; ++i)
        {
            if (heights[i] > mx)
            {
                mx = heights[i];
                que1.push_back(mx);
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            if (que1.front() == heights[i])
                que1.erase(que1.begin());

        }

        return ans;
    }


// tle...
//min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).
// tle?
    vector<int> lt1944a(vector<int>& heights)
    {
        int sz1 = heights.size();
        vector<int> ans(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = 0;
            int mx = 0;
            for (int j = i + 1; j < sz1; ++j)
            {
                if (heights[j] > mx)
                {
                    mx = heights[j];
                    t2++;
                }
                if (heights[j] > heights[i])      // unique
                    break;
            }
            ans[i] = t2;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {10,6,8,5,11,9};
    myvi v = {5,1,2,3,10};

    LT1944 lt;

    myvi v2 = lt.lt1944c(v);

    showVectorInt(v2);

    return 0;
}
