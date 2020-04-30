
#include "../header/myheader.h"

class LT0739
{
public:


// discuss
// stack 保存下标. 从前向后遍历，如果当前下标的温度>栈顶下标的温度，出栈，当前下标就是出栈下标的下一个温度更高的天。当前下标压栈。


//Runtime: 212 ms, faster than 37.55% of C++ online submissions for Daily Temperatures.
//Memory Usage: 12.4 MB, less than 100.00% of C++ online submissions for Daily Temperatures.
    vector<int> lt0739a(vector<int>& T)
    {
        int arr[101] = {0};
        vector<int> ans(T.size(), 0);
        for (int i = T.size() - 1; i >= 0; i--)
        {
            arr[T[i]] = i;
            for (int j = 30; j <= T[i]; j++)
            {
                arr[j] = i;
            }
            for (int j = T[i] + 1; j <= 100; j++)
            {
                if (arr[j] != 0)
                {
                    ans[i] = arr[j] - i;
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73};

    LT0739 lt;

    vector<int> ans = lt.lt0739a(t);

    for_each(ans.begin(), ans.end(), fun_cout);

    return 0;
}
