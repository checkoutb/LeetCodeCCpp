
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        for (int i = 1; i < ratings.size(); i++) {
//            if (ratings[i] > ratings[i - 1]) {
//                rewards[i] = rewards[i - 1] + 1;
//            }
//        }
//        for (int k = ratings.size() - 2; k >= 0; k--) {
//            if (ratings[k] > ratings[k + 1]) {
//                rewards[k] = max(rewards[k], rewards[k + 1] + 1);
//            }
//        }
// .. 真的正反2遍。。。 道心不坚啊。。。



// one-pass, O(1)空间



// AC
// 212
// 112
//
// 正反2遍？

// pri_q
    int lta(vector<int>& ratings)
    {
//        int sz1 = ratings.size();
//        vector<int> vi(sz1, 1);

//        priority_queue<int> priq(begin(ratings), end(ratings));

        priority_queue<pair<int, int>> priq;
        for (int i = 0; i < ratings.size(); ++i)
        {
            priq.push(std::make_pair(-ratings[i], i));          // max-heap....negate.
        }
        vector<int> vi(ratings.size(), 1);
        while (!priq.empty())
        {
            pair<int, int> p = priq.top();
            priq.pop();
            #ifdef __test
            cout<<p.first<<endl;
            #endif // __test
//            int t1 = p.first;       // value
            int t2 = p.second;      // index
            if (t2 > 0 && ratings[t2] > ratings[t2 - 1] && vi[t2] <= vi[t2 - 1])
                vi[t2] = vi[t2 - 1] + 1;
            if (t2 < vi.size() - 1 && ratings[t2] > ratings[t2 + 1] && vi[t2] <= vi[t2 + 1])
                vi[t2] = vi[t2 + 1] + 1;
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        return std::accumulate(begin(vi), end(vi), 0);
    }

};

int main()
{
//    myvi v = {1,0,2};
//    myvi v = {1,2,2};
//    myvi v = {2,3,2,3,2,3};
    myvi v = {1,2,3,4,5,4,3,3,2,1};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
