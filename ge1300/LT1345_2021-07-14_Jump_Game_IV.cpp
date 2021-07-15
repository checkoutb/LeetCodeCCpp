
#include "../header/myheader.h"

class LT1345
{
public:

// D D

// visit, 不需要保存 步数。

// map2的key只使用一次(就是使用后直接erase)，下次就不会再for{if(visit)} 了






// 感觉 vit的预处理 有点剑走偏锋了， 还是1,2,3,1,2,3,1,2,3...这种，感觉就不行了。

//Runtime: 128 ms, faster than 98.83% of C++ online submissions for Jump Game IV.
//Memory Usage: 62.7 MB, less than 88.84% of C++ online submissions for Jump Game IV.

// 难道压缩下？ 连续的相同数值就直接remove掉？  来个 1,2,3,1,2,3,1,2,3,1,2,3.....呢。

// 还是tle， 不过速度快了。  看testcase，只能看到 无穷的7, 后面是什么不清楚，
// 但是根据代码，应该是： 很多7然后一个1. 正常只需要2步，从第一个7跳到最后一个7,然后再 +1,  现在因为。。。算了，好像也不会有问题的。。
// tle......看了hint， 然后发现 vi 没有设置值。。
    int lt1345a(vector<int>& arr)
    {
        if (arr.size() == 1)
            return 0;
        vector<int> vit;
        vit.push_back(arr[0]);
        vit.push_back(arr[1]);          // 77777771  ->  71 ...
        for (int i = 2; i < arr.size(); ++i)
        {
            if (arr[i] != arr[i - 1] || arr[i] != arr[i - 2])           // 至少保存2个，  只保存一个的话：27777777 就错了。
            {
                vit.push_back(arr[i]);          // 50000个7, 瞬间。
            }
        }
        swap(arr, vit);
        unordered_map<int, vector<int>> map2;
        for (int i = 0; i < arr.size(); ++i)
        {
            map2[arr[i]].push_back(i);
        }
        vector<int> vi(arr.size(), INT_MAX);
//        queue<int> que1;
//        que1.push(0);
        queue<pair<int, int>> que1;
        vi[0] = 0;
        que1.push(std::make_pair(0, 0));
        while (!que1.empty())
        {
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                pair<int, int> p = que1.front();
                que1.pop();
                int t2 = p.first;
                int t3 = p.second;
                if (t2 == arr.size() - 1)
                    return t3;
                if (vi[t2] < t3)
                    continue;

                int ta = t2 + 1;
                int tb = t3 + 1;
                if (ta < arr.size())
                {
                    if (tb < vi[ta])
                    {
                        vi[ta] = tb;
                        que1.push({ta, tb});
                    }
                }

                ta = t2 - 1;
                if (ta >= 0)
                {
                    if (tb < vi[ta])
                    {
                        vi[ta] = tb;
                        que1.push(make_pair(ta, tb));
                    }
                }

                for (int i : map2[arr[t2]])
                {
                    if (tb < vi[i])
                    {
                        vi[i] = tb;
                        que1.push(make_pair(i, tb));
                    }
                }
            }
        }
        return -1;
    }

};

int main()
{
//    myvi v = {100,-23,-23,404,100,23,23,23,3,404};
//    myvi v = {7};
//    myvi v = {7,6,9,6,9,6,9,7};
//    myvi v = {6,1,9};
//    myvi v = {11,22,7,7,7,7,7,7,7,22,13};

    myvi v;
    for (int i = 1; i < 50000; ++i)
        v.push_back(7);
    v.push_back(1);           // 5000瞬间，50000就5s            // bfs不需要vi，后面的必然比本次更多步骤(set,不过没有做)

    cout<<"start"<<endl;

    LT1345 lt;

    cout<<lt.lt1345a(v)<<endl;

    return 0;
}
