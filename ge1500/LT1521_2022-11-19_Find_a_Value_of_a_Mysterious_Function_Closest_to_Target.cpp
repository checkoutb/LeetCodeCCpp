
#include "../header/myheader.h"

class LT1521
{
public:

    // ???
    // 直接 使用 set 记录 当前下标 到 前面 任意 下标 的 subarr 的 &， 然后 所有值 & 下一个下标，就是。。 dp


    // 找到 一个 subarray， & 后 最接近 target。
    // 感觉内存得 上百兆。。
    int lt1521a(vector<int>& arr, int target)
    {
        int sz1 = arr.size();
        vector<vector<short>> vvs(sz1, vector<short>(25));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < 25; ++j)
            {

            }
        }


    }

};

int main()
{

    LT1521 lt;


    return 0;
}
