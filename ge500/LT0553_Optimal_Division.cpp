
#include "../header/myheader.h"

class LT0553
{
public:


// D

// 第一个 除以 后面的全部。。 size==1 size==2 不需要()




// 现在想来，正整数的情况下 (a/b/c) == (a/(b*c)) <= (a/(b/c)), 归纳法后 (a/b/c/d/e/f/g) 的最大值 应该是 (a/(b/(c/(d/(e/(f/g))))))
// 最小值 是 (a/b/c/d/e/f/g) 。
// 将 nums 二分， 前半部分(a/(b/(c/d))), 后半部分 a/b/c/d .. 然后计算 最大结果。
// 会发现 前半部分只有一个数字时， 是最大结果。。

// gg...不关结合律的事情。 甚至还反了。
// 有结合律的存在，所以只是一分为二。
    string lt0553a(vector<int>& nums)
    {
        vector<double> v2(nums.size(), 0.0);
        double d2 = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            d2 = nums[i] / d2;
            v2[i] = d2;
        }
        int t1 = 0;
        double mxd = v2[0];
        d2 = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
        cout<<"     . "<<d2<<" / "<<v2[i]<<endl;
            if ((d2 / v2[i]) > mxd)
            {
                t1 = i;
                mxd = d2 / v2[i];
            }
            d2 /= nums[i];
        }
        #ifdef __test
        for_each(begin(v2), end(v2), fun_cout); cout<<endl;
        cout<<" . "<<t1<<" : "<<mxd<<endl;
        #endif // __test
        string ans;
        for (int i = 0; i < t1; i++)
        {
            ans += (to_string(nums[i]) + "/");
        }
        if (t1 != 0)
            ans += "(";
        for (int i = t1; i < nums.size(); i++)
        {
            ans += (to_string(nums[i]) + "/");
        }
        ans = ans.substr(0, ans.size() - 1);
        if (t1 != 0)
            ans += ")";
//        cout<<ans<<endl;
        return ans;
    }

};

int main()
{

    vector<int> v = {1000,100,10,2};

    LT0553 lt;

    cout<<lt.lt0553a(v)<<endl;

    return 0;
}
