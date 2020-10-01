
#include "../header/myheader.h"

class LT0621
{
public:


// 最长的定框架，每次取 现在最长的n-1个任务填充到框架里。
// 如果总耗时大于框架，那么剩下的应该都是 次数平均的任务。

// 可惜，最后一步想不出： 返回 tasks.size() ans 中大的。
    int lt0621a(vector<char>& tasks, int n)
    {
        int arr['Z'] = {0};
//        int arr['Z'] = {0};

        for (char ch : tasks)
        {
            arr[ch] += n;
        }

    }


};

int main()
{

    LT0621 lt;


    return 0;
}
