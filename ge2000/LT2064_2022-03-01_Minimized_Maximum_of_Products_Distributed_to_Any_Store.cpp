
#include "../header/myheader.h"

class LT2064
{
public:


// D D

//        while (left < right) {
//            int mid = (left + right) / 2, sum = 0;
//            for (auto it: A)
//                sum += (ceil(it/(double)mid));
//            if (sum > n)
//                left = mid + 1;
//            else
//                right = mid;
//        }


//        while (left < right) {
//            int mid = (left + right) / 2, sum = 0;
//            for (int a : A)
//                sum += (a + mid - 1) / mid;
//            if (sum > n)
//                left = mid + 1;
//            else
//                right = mid;
//        }



//Runtime: 387 ms, faster than 30.00% of C++ online submissions for Minimized Maximum of Products Distributed to Any Store.
//Memory Usage: 84.5 MB, less than 51.07% of C++ online submissions for Minimized Maximum of Products Distributed to Any Store.
    int lt2064b(int n, vector<int>& quantities)
    {
        int mx = *std::max_element(begin(quantities), end(quantities));
        std::sort(begin(quantities), end(quantities));
        int l = 1, r = mx;
        int ans = 1;
        while (l <= r)
        {
            int t2 = n;
            int cap = (l + r) / 2;
            for (int i = quantities.size() - 1; (i >= 0) && (t2 >= 0); i--)
            {
                t2 -= (quantities[i] / cap + (quantities[i] % cap != 0));
//                cout<<"? "<<t2<<", "<<quantities[i]<<", "<<t2<<", "<<i<<endl;
            }
//            cout<<l<<", "<<r<<", "<<cap<<", "<<t2<<endl;
            if (t2 > 0)
            {
                ans = cap;
                r = cap - 1;
            }
            else if (t2 == 0)
            {
                ans = cap;
                r = cap - 1;
            }
            else
            {
//                ans = l;
                l = cap + 1;
            }
        }
        return ans;
    }



// erfen?
// tle....
// n个仓库，m种产品，
// sort 从后往前算。 每次 / 2。并且记录原值和兄弟。
// 或者，sum(m)/n 然后每种产品尽量往这个值分。..但是感觉不太靠谱。。
// 优先队列。
    int lt2064a(int n, vector<int>& quantities)
    {
//        int sum2 = std::accumulate(begin(quanties), end(quanties), 0);
//        int avg = sum2 / n;

        priority_queue<tuple<int, int, int>> priq;            // max cnt per bucket, total, number of bucket
        for (int cnt : quantities)
        {
            priq.push(make_tuple(cnt, cnt, 1));
            n--;
//            priq.push(make_pair(cnt, 1));
        }

        while (n > 0)
        {
            tuple<int, int, int> tup = priq.top();
            priq.pop();
            n--;
            int t2 = std::get<1>(tup);
            int t3 = std::get<2>(tup) + 1;
            priq.push(make_tuple((t2 / t3) + (t2 % t3 != 0), t2, t3));
        }
        return std::get<0>(priq.top());
    }

};

int main()
{

    LT2064 lt;

//    int n = 6;
//    myvi v = {11, 6};

//    int n = 7;
//    myvi v = {10,15,10};

//    int n = 3;
//    myvi v = {2000};

    int n = 26;
    myvi v = {24,18,12,6,3,24,5,19,10,20,2,18,27,3,13,22,11,16,19,13};


    cout<<lt.lt2064b(n, v)<<endl;

    return 0;
}
