
#include "../../header/myheader.h"

class LT
{
public:

    // D D



    //Runtime221 ms
    //    Beats
    //    73.67 %
    //    Memory73.7 MB
    //    Beats
    //    69.75 %
    int lta(vector<int>& arr)
    {
        int sz1 = arr.size();
        map<int, vector<int>> map2;

        for (int i = 0; i < sz1; ++i)
        {
            map2[arr[i]].push_back(i);
        }
        vector<int> vi(sz1, INT_MAX);     // min step
        vi[0] = 0;
        queue<int> que1;    // idx
        que1.push(0);
        int t2 = 0;
        int stp = 0;
        //set<int> vst;
        while (!que1.empty())
        {
            t2 = que1.front();
            que1.pop();
            if (t2 == sz1 - 1)
                break;
            stp = vi[t2];
            
            if ((t2 + 1 < sz1 && vi[t2 + 1] > stp + 1))
            {
                vi[t2 + 1] = stp + 1;
                que1.push(t2 + 1);
            }
            if ((t2 - 1 >= 0 && vi[t2 - 1] > stp + 1))
            {
                vi[t2 - 1] = stp + 1;
                que1.push(t2 - 1);
            }

            if (map2.find(arr[t2]) != map2.end())
            {
                for (int idx : map2[arr[t2]])
                {
                    if (idx == t2)
                        continue;

                                                // : 在bfs同一层的时候，2个相同值a的 idx 都被加入到 queue中，并且 stp 都是 4，
                                                // bfs 下一层的时候， 第一个值a 的下标 开始 计算 map2 的距离， 就把 第二个a 的 stp 设置为 4+1 了。
                    if (vi[idx] > stp + 1)          // 不加这个 就是 5， 加上就是 4.
                    {
                        vi[idx] = stp + 1;
                        que1.push(idx);
                    }
                }
                map2.erase(arr[t2]);
            }
        }

#ifdef __test
        // 加 if
        // 0, 1, 2, 3, 4, 5, 4, 5, 5, 5, 4, 3, 2, 2, 1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 4, 3, 4, 5, 5, 4, 3, 3, 4, 4, 2147483647, 5, 5, 4, 3, 3, 3, 4, 5, 5, 4, 3, 4, 3, 4, 3, 2, 1, 2, 3, 4, 5, 4, 3, 4, 3, 4, 4, 4, 3, 2, 1, 2, 1, 2, 3, 4, 4, 3, 4, 4, 5, 2147483647, 4, 3, 3, 4, 4, 3, 3, 3, 3, 3, 4,
        // no if
        // 0, 1, 2, 3, 4, 5, 4, 5, 5, 5, 4, 3, 2, 2, 1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 4, 3, 4, 5, 5, 4, 3, 3, 5, 4, 2147483647, 5, 5, 4, 3, 3, 3, 4, 5, 5, 4, 3, 5, 3, 5, 3, 2, 1, 2, 3, 5, 5, 4, 3, 4, 3, 4, 4, 4, 3, 2, 1, 2, 1, 2, 3, 4, 4, 3, 4, 4, 5, 2147483647, 4, 3, 3, 5, 4, 3, 3, 3, 3, 3, 5,
        showVectorInt(vi);
#endif

        return vi[sz1 - 1];
    }

};

int main()
{

    LT lt;

    //myvi v = { 100,-23,-23,404,100,23,23,23,3,404 };
    //myvi v = { 1 };
    //myvi v = { 7,6,9,6,9,6,9,7 };

    // 4
    myvi v = { 51,64,-15,58,98,31,48,72,78,-63,92,-5,64,-64,51,-48,64,48,-76,-86,-5,-64,-86,-47,92,-41,58,72,31,78,-15,-76,72,-5,-97,98,78,-97,-41,-47,-86,-97,78,-97,58,-41,72,-41,72,-25,-76,51,-86,-65,78,-63,72,-15,48,-15,-63,-65,31,-41,95,51,-47,51,-41,-76,58,-81,-41,88,58,-81,88,88,-47,-48,72,-25,-86,-41,-86,-64,-15,-63 };

    cout << lt.lta(v) << endl;

    return 0;
}
