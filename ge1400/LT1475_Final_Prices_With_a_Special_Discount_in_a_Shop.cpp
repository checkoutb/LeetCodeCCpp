
#include "../header/myheader.h"

class LT1475
{
public:

// D D

// stack...
//            while(!stk.empty() && prices[stk.top()] >= prices[i]){
//                prices[stk.top()] -= prices[i];
//                stk.pop();
//            }
//            stk.push(i);
// 每次 push下标， 后续，如果出现 一个 价格小于 top价格 的 ， 就 知道折扣了。

//        for (int i = n - 1; i >= 0; i--) {
//            while (!st.isEmpty() && ps[i] < st.peek()) st.pop();
//            res[i] = ps[i] - (st.isEmpty() ? 0 : st.peek());
//            st.push(ps[i]);
//        }
// 反序遍历， push值，  后续 如果 当前的价格 小于 top， 就pop。  直到出现一个 小于等于当前价格的，
// 10 2 6 ？？ 这种不就没有办法了吗。。 但是 ac了。
//class Solution {
//    public int[] finalPrices(int[] prices) {
//        int n = prices.length, res[] = new int[n];
//        Stack<Integer> st = new Stack<>();
//        for (int i = n - 1; i >= 0; i--) {
//            while (!st.isEmpty() && prices[i] < st.peek()) st.pop();
//            res[i] = prices[i] - (st.isEmpty() ? 0 : st.peek());
//            st.push(prices[i]);
//        }
//        return res;
//    }
//}
// 而且 java的好快啊。  大部分1-2ms，，，  c的大部分4/8ms。。。
// 。。。 是 第一个小于它的，  没有问题，   如果当前<top, 肯定pop掉了， 因为  前面的（((如果有这种的话))） 碰到的第一个小于它的 肯定会是当前，而不可能是top。




//Runtime: 8 ms, faster than 57.32% of C++ online submissions for Final Prices With a Special Discount in a Shop.
//Memory Usage: 10.2 MB, less than 63.43% of C++ online submissions for Final Prices With a Special Discount in a Shop.
    vector<int> lt1475b(vector<int>& prices)
    {
        int sz1 = prices.size();
        vector<int> ans(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            int v = prices[i];
            for (int j = i + 1; j < sz1; ++j)
                if (prices[j] <= v)
                {
                    v -= prices[j];
                    break;
                }
            ans[i] = v;
        }
        return ans;
    }


// error ,,  这里时 后续 小于自己 的 最大价格。。
// 后续第一个小于自己的 价格。
    vector<int> lt1475a(vector<int>& prices)
    {
        multiset<int> mset2(begin(prices), end(prices));
        #ifdef __test
        for (multiset<int>::iterator it = mset2.begin(); it != mset2.end(); it++)
            cout<<*it<<", ";
        cout<<endl;
        #endif // __test
        int sz1 = prices.size();
        vector<int> ans(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            int v = prices[i];
            mset2.erase(v);
            if ((i == sz1 - 1) || *mset2.begin() > v)
            {
                ans[i] = v;
            }
            else
            {
                auto it = mset2.upper_bound(v);
                it--;
                #ifdef __test
                cout<<i<<", "<<v<<", "<<*it<<endl;
                #endif // __test
                ans[i] = v - *it;
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {8,4,6,2,3};
//    vector<int> v = {1,2,3,4,5};
    vector<int> v = {10,1,1,6};

    LT1475 lt;

    vector<int> ans = lt.lt1475b(v);
    showVectorInt(ans);

    return 0;
}
