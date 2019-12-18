
#include "../header/myheader.h"

class LT0496
{
public:


//        for (int num : nums) {
//            while (!stack.isEmpty() && stack.peek() < num)
//                map.put(stack.pop(), num);
//            stack.push(num);
//        }
// 借助stack，所有 小于 num 的数 设置 next greater 为 num，


//Runtime: 12 ms, faster than 62.52% of C++ online submissions for Next Greater Element I.
//Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Next Greater Element I.

    vector<int> lt0496a(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans(nums1.size());

        for (int i = 0; i < nums1.size(); i++)
        {
            int t1 = nums1[i];
            int ans2 = -1;
            bool fg1 = false;
            for (int j = 0; j < nums2.size(); j++)
            {
                if (fg1)
                {
                    if (nums2[j] > t1)
                    {
                        ans2 = nums2[j];
                        break;
                    }
                }
                else
                {
                    if (nums2[j] == t1)
                    {
                        fg1 = true;
                    }
                }
            }
            ans[i] = ans2;
        }

        return ans;
    }
};

int main()
{
    vector<int> v1 = {4,1,2};
    vector<int> v2 = {1,3,4,2};

    LT0496 lt;

    vector<int> vr = lt.lt0496a(v1, v2);

    for_each(vr.begin(), vr.end(), fun_cout);
    cout<<endl;

    return 0;
}
