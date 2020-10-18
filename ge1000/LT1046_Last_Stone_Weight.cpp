
#include "../header/myheader.h"

class LT1046
{
public:

// D D
//    Arrays.sort(stones);
//    for(int i=stones.length-1; i>0; i--) {
//      stones[i-1] = stones[i] - stones[i-1];
//      Arrays.sort(stones);
//    }
//    return stones[0];


//  multiset<int> s(begin(st), end(st));
//  while (s.size() > 1) {
//    auto w1 = *prev(s.end());
//    s.erase(prev(s.end()));
//    auto w2 = *prev(s.end());
//    s.erase(prev(s.end()));
//    if (w1 - w2 > 0) s.insert(w1 - w2);
//  }
//  return s.empty() ? 0 : *s.begin();




//Runtime: 4 ms, faster than 66.13% of C++ online submissions for Last Stone Weight.
//Memory Usage: 7.9 MB, less than 99.28% of C++ online submissions for Last Stone Weight.
    int lt1046(vector<int>& stones)
    {
        priority_queue<int> pri(begin(stones), end(stones));
        int t1, t2;
        while (pri.size() > 1)
        {
            t1 = pri.top();
            pri.pop();
            t2 = pri.top();
            pri.pop();
            if (t1 != t2)
                pri.push(t1 - t2);
        }
        return pri.empty() ? 0 : pri.top();
    }

};

int main()
{

    vector<int> v = {2,2};

    LT1046 lt;

    cout<<lt.lt1046(v)<<endl;

    return 0;
}
