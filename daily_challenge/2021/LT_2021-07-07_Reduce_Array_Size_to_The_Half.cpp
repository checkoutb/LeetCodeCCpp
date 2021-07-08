
#include "../../header/myheader.h"

class LT
{
public:

// D D

// sort后，遍历能直接知道个数(==前面就++，不等于的时候就是前值的个数)。 然后个数再sort。

//
// 看到一个桶排序，然后看到限制： arr.length is even.  不过值最高要10^5，桶排序有点不太好吧。。


//        for(int i = 0; i < arr.size(); ++i)
//        {
//            int count = 1;
//            while(i < arr.size()-1 && arr[i+1] == arr[i] )
//                count++, i++;
//            pq.push(count);
//        }
// 。。while..


//multiset<int, greater <int>> s;
// 和priority_queue的作用一样。



// AC
    int lta(vector<int>& arr)
    {
        unordered_map<int, int> map2;
        priority_queue<int> priq;
        for (int i : arr)
            map2[i]++;
        for (auto& p : map2)
        {
            priq.push(p.second);
        }
        int ans = 0;
        int sz1 = arr.size();
        int t2 = 0;
        while (t2 < (sz1 + 1) / 2)
        {
            ans++;
            t2 += priq.top();
            priq.pop();
        }
        return ans;
    }

};

int main()
{
//    myvi v = {3,3,3,3,5,5,5,2,2,7};
    myvi v = {1,2,3,4,5,6,7,8,9};

    LT lt;

    cout<<lt.lta(v)<<endl;

    return 0;
}
