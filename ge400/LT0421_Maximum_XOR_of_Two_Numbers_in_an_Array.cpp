
#include "../header/myheader.h"

class LT0421
{


// O(n)...想不出。。最多做到，map<int, List<int>>, <第一个1所在位，值>。然后再对key最大的处理。

// discuss
// trie, 结点没有值，靠左右子树来表示0/1，root的左右子树是int的首位。
// 对每个值，从首位开始根据位的值 来搜索xor最大的 bit，如果有，那么就走这里，没有就走另一边。有就<<1 ,+1, 没有就<<0,+0.


//class Solution {
//public:
//    class TreeNode {
//    public:
//        TreeNode* next[2];
//        TreeNode () {next[0] = NULL; next[1] = NULL;};
//    };
// 内部类。。


public:


// tle..... 28/29 passed..
    int lt0421b(vector<int>& nums)
    {
        int ans = 0;
        map<int, set<int>> map2;
        for (auto& n : nums)
        {
            int cnt = 0;
            int n2 = n;
            while (n2 > 0)
            {
                cnt++;
                n2 >>= 1;
            }
            set<int> set1 = map2[cnt];
            set1.insert(n);
            map2[cnt] = set1;
        }

        set<int> set2 = (map2.rbegin())->second;

        for (auto& p1 : set2)
        {
            for (auto& p2 : nums)
            {
                ans = max(ans, p1 ^ p2);
            }
        }
        return ans;
    }

    // error... 应该是 对从头开始的每个0 寻找该位是首位且为1的 set，如果所有的0都无法找到，那么就应该是取map的key最小的那个set。
    int lt0421a(vector<int>& nums)
    {
        int ans = 0;
        map<int, set<int>> map2;
        for (auto& n : nums)
        {
            int cnt = 0;
            int n2 = n;
            while (n2 > 0)
            {
                cnt++;
                n2 >>= 1;
            }
            set<int> set1 = map2[cnt];
            set1.insert(n);
            map2[cnt] = set1;
        }

        set<int> set2 = (map2.rbegin())->second;            // end()--， 似乎无定义。 rbegin。

        #ifdef __test
        for (auto& p : map2)
        {
            cout<<p.first<<endl;
            for (int i : p.second)
            {
                cout<<", "<<i;
            }
            cout<<endl;
        }
        cout<<endl<<"set2 : "<<endl;
        for_each(set2.begin(), set2.end(), fun_cout);
        cout<<endl;
        #endif // __test

        for (int n : set2)
        {
            int t1 = 0;
            int cnt = 0;
            int n2 = n;
            while (n2 > 0)
            {
                if (n2 % 2 == 0)
                {
                    t1 = cnt;
                }
                n2 >>= 1;
                cnt++;
            }
            set<int> set3 = map2[cnt];

            #ifdef __test
            cout<<cnt<<",cnt "<<endl;
            #endif // __test

            while (set3.empty() && cnt>0)
            {
                set3 = map2[--cnt];
            }
            if (set3.empty())
            {
                set3 = set2;
            }
            for (int i : set3)
            {
                #ifdef __test
                cout<<"ma : "<<(i ^ n)<<" . . "<<i<<endl;
                #endif // __test
                ans = max(ans, i ^ n);
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {3,5,10,25,2,8};

    LT0421 lt;
    cout<<endl<<lt.lt0421b(nums)<<endl;

    return 0;
}
