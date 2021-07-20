
#include "../header/myheader.h"

class LT1921
{
public:


// D D

//    for (int i = 0; i < dist.size(); ++i)
//        dist[i] = (dist[i] - 1) / speed[i];               // - 1
//    sort(begin(dist), end(dist));                 // ...
//    for (int i = 0; i < dist.size(); ++i)
//        if (i > dist[i])
//            return i;
//    return dist.size();





//Runtime: 144 ms, faster than 60.18% of C++ online submissions for Eliminate Maximum Number of Monsters.
//Memory Usage: 88.7 MB, less than 24.73% of C++ online submissions for Eliminate Maximum Number of Monsters.
// 一般来说，先杀治疗。
// 杀最早到达的。
    int lt1921a(vector<int>& dist, vector<int>& speed)
    {
        priority_queue<double, vector<double>, std::greater<double>> priq;
        for (int i = 0; i < dist.size(); ++i)
        {
            priq.push(1.0 * dist[i] / speed[i]);
        }
        #ifdef __test
//        cout<<priq.top()<<endl;
        #endif // __test
        priq.pop();
        int tm2 = 1;
        int ans = 1;
        while (!priq.empty())
        {
            double d = priq.top();
            priq.pop();
            if (d <= tm2)
            {
                break;
            }
            ans++;
            tm2++;
        }
        #ifdef __test
//        cout<<priq.size()<<endl;
        #endif // __test
        return ans;
    }

};

int main()
{
//    myvi v1 = {1,3,4};
//    myvi v2 = {1,1,1};

//    myvi v1 = {1,1,2,3};
//    myvi v2 = {1,1,1,1};

    myvi v1 = {3,2,4};
    myvi v2 = {5,3,2};

    LT1921 lt;

    cout<<lt.lt1921a(v1, v2)<<endl;

    return 0;
}
