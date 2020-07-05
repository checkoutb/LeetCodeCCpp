
#include "../header/myheader.h"

class LT0950
{
public:

// D D
//        sort(deck.rbegin(), deck.rend());
//        deque<int> d;
//        d.push_back(deck[0]);
//        for (int i = 1; i < deck.size(); i++) {
//            d.push_front(d.back());
//            d.pop_back();
//            d.push_front(deck[i]);
//        }
//        vector<int> res(d.begin(), d.end());
//        return res;
// 反向，模拟
// rbegin,rend，是反序。
// 最后的情况是只有一张牌，然后倒数第二的情况是。。。 反之就是 把上次状态下，最下面的一张，放到最上面，然后再把新来的那张放最上面。





//Runtime: 8 ms, faster than 88.44% of C++ online submissions for Reveal Cards In Increasing Order.
//Memory Usage: 8.5 MB, less than 67.28% of C++ online submissions for Reveal Cards In Increasing Order.
    vector<int> lt0950a(vector<int>& deck)
    {
        int sz1 = deck.size();
        vector<int> ans(deck.size(), 0);
        std::sort(begin(deck), end(deck));
        int nexti = 0;
        for (int i = 0; i < sz1; i++)
        {
            ans[nexti] = deck[i];
            if (i < sz1 - 1)
            {
                while (ans[nexti] != 0)
                {
                    nexti = (nexti + 1) % sz1;
                }
                if (i < sz1 - 2)
                {
                    nexti = (nexti + 1) % sz1;
                    while (ans[nexti] != 0)
                    {
                        nexti = (nexti + 1) % sz1;
                    }
                }
            }
            #ifdef __test
            cout<<nexti<<endl;
            #endif // __test
        }
        return ans;
    }


};

int main()
{

//    vector<int> v = {17,13,11,2,3,5,7};

    vector<int> v = {1,2,3,4};

    LT0950 lt;

    vector<int> ans = lt.lt0950a(v);

    for_each(begin(ans), end(ans), fun_cout);
    cout<<endl;

    vector<int> v2 = {4,3,5,2};
    sort(v2.rbegin(), v2.rend());
    for_each(begin(v2), end(v2), fun_cout);

    return 0;
}
