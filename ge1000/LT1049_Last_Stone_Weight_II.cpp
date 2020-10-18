
#include "../header/myheader.h"

class LT1049
{
public:

// D
// 分2组，使得2组 的 差最小，背包问题



    int lt1049b(vector<int>& stones)
    {
        priority_queue<int> pri(begin(stones), end(stones));
        int t1, t2;
        while (pri.size() >= 2)
        {
            int t1 = pri.top();
            pri.pop();
            int t2 = pri.top();
            pri.pop();
            pri.push(t1 - t2);
        }
        return pri.top();
    }


// 。。。 8，2，4，4，8 。。
// 感觉要么1，要么0，要么 一个最大的石头把其他全撞碎。
    int lt1049a(vector<int>& stones)
    {
        int sum2 = std::accumulate(begin(stones), end(stones), 0);
        int max2 = *std::max_element(begin(stones), end(stones));
        if (max2 > (sum2 - max2))
        {
            return max2 - (sum2 - max2);
        }
        else
        {
            return sum2 % 2;
        }
    }

};

int main()
{

//    vector<int> v = {8,2,4,4,8};
    vector<int> v = {31,26,33,21,40};

    LT1049 lt;

    cout<<lt.lt1049b(v)<<endl;

    return 0;
}
