
#include "../header/myheader.h"

class LT0728
{
public:

// 不知道有没有什么规则，能快速剔除，如百位碰到0，可以跳过100个数字之类的。。不过这样代码需要很多阿。



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Self Dividing Numbers.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Self Dividing Numbers.
    vector<int> lt0728a(int left, int right)
    {
        vector<int> ans;
        while (left <= right)
        {
            if (isSelfDivide(left))
                ans.push_back(left);
            left++;
        }
        return ans;
    }

    bool isSelfDivide(int num)
    {
        int n2 = num;
        int t1 = 0;
        while (n2 > 0)
        {
            t1 = n2 % 10;
            n2 /= 10;
            if (t1 == 0)
                return false;
            if (num % t1 != 0)
                return false;
        }
        return true;
    }

};

int main()
{

    int left = 1;
    int right = 22;

    LT0728 lt;

    vector<int> ans = lt.lt0728a(left, right);

    for_each(ans.begin(), ans.end(), fun_cout);


    return 0;
}
