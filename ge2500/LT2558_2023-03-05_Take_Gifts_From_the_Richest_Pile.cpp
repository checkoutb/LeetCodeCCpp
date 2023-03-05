
#include "../header/myheader.h"

class LT2558
{
public:

    // D D

    //make_heap(begin(g), end(g));
    //while (k--) {
    //    pop_heap(begin(g), end(g));
    //    g.back() = sqrt(g.back());
    //    push_heap(begin(g), end(g));
    //}
    //return accumulate(begin(g), end(g), 0LL);




    // jie erdeng rentou yiyong, chong ge 1700, thx


    //Runtime8 ms
    //    Beats
    //    73.10 %
    //    Memory9.2 MB
    //    Beats
    //    66.30 %
    long long lt2558a(vector<int>& gifts, int k)
    {
        priority_queue<int> priq(begin(gifts), end(gifts));
        int t2 = 0;
        while (k-- > 0)
        {
            t2 = priq.top();
            priq.pop();
            priq.push(static_cast<int>(sqrt(t2)));
        }
        long long ans = 0LL;
        while (!priq.empty())
        {
            ans += priq.top();
            priq.pop();
        }
        return ans;
    }

};

int main()
{

    LT2558 lt;


    return 0;
}
