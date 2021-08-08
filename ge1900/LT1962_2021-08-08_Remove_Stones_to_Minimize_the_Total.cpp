
#include "../header/myheader.h"

class LT1962
{
public:

// D D

//    make_heap(begin(p), end(p));
//    while (--k >= 0) {
//        pop_heap(begin(p), end(p));
//        p.back() -= p.back() / 2;
//        push_heap(begin(p), end(p));
//    }
//    return accumulate(begin(p), end(p), 0);

//    int total = accumulate(begin(piles), end(piles), 0);
//    priority_queue<int> p(begin(piles), end(piles));
//    while (--k >= 0) {
//        auto st = p.top(); p.pop();
//        total -= st / 2;
//        p.push((st + 1) / 2);
//    }
//    return total;




//Runtime: 532 ms, faster than 33.33% of C++ online submissions for Remove Stones to Minimize the Total.
//Memory Usage: 98.9 MB, less than 44.44% of C++ online submissions for Remove Stones to Minimize the Total.
    int lt1962a(vector<int>& piles, int k)
    {
        priority_queue<int> priq(begin(piles), end(piles));
        while (k-- > 0)
        {
            int t2 = priq.top();
            priq.pop();
            priq.push(t2 - t2 / 2);
        }
        int ans = 0;
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

//    myvi v = {5,4,9};
//    int k(2);

    myvi v = {4,3,6,7};
    int k{3};

    LT1962 lt;

    cout<<lt.lt1962a(v, k)<<endl;

    return 0;
}
