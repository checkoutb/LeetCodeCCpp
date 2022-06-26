
#include "../header/myheader.h"

class LT2322
{
public:


    // D

    // 思路应该是这样的，不过代码改不下去了。。。




    // error          23 / 65 test cases passed.
    //[28, 24, 29, 16, 31, 31, 17, 18]
    //[[0, 1], [6, 0], [6, 5], [6, 7], [3, 0], [2, 1], [2, 4]]          except 8

    // 无向连通树
    // 删除2条边，就会变成 3个连通。
    // 3个连通的 各自的所有value 的 xor。 的 最大 - 最小
    // 需要 最小的score， 就是 最大 最接近 最小。
    // 每删除一条边，它的 下面 的节点 就是 新的树的root。 而且 xor 挺好用的。
    // for for 1000 应该能抗住吧。
    // 先要确定root， 这样 移除边的时候， 就知道 新的树的 root了。
    // 以0为root。 value 就是 父节点。
    // 更应该反向。得用 map。 反向的话，计算 xor 比较简单。 不不不。
    // ..
    // xr1, xr2 是哪侧的？ 如果是2侧，那么都需要xor， 如果是同侧，那么只需要 xor 一个。
    int lt2322a(vector<int>& nums, vector<vector<int>>& edges)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1, -1);
        //vi[0] = -1;
        //vi[0] = -2;
        vi[1] = -2;
        unordered_map<int, vector<int>> map2;
        for (vector<int>& ege : edges)
        {
            map2[ege[0]].push_back(ege[1]);
            map2[ege[1]].push_back(ege[0]);
        }
        queue<int> que1;
        //que1.push(0);
        que1.push(1);

        queue<int> qnode;

        while (!que1.empty())
        {
            int fnt = que1.front();
            que1.pop();
            bool b2 = true;
            for (int i : map2[fnt])
            {
                if (vi[i] == -1)
                {
                    b2 = false;
                    vi[i] = fnt;
                    que1.push(i);
                }
            }
#ifdef __test
//            cout << b2 << ",-- " << fnt << endl;
#endif
            if (b2)
            {
                qnode.push(fnt);
            }
        }


        //vi[0] = -1;
        vi[1] = -1;
        //vector<int> xr(sz1, 0);
        vector<int> xr(begin(nums), end(nums));
        unordered_set<int> set2;

        while (!qnode.empty())
        {
            int fnt = qnode.front();
            qnode.pop();
            if (vi[fnt] != -1)
            {
                xr[vi[fnt]] ^= xr[fnt];
                qnode.push(vi[fnt]);
                if (set2.find(vi[fnt]) == set2.end())
                    set2.insert(vi[fnt]);
            }

//            int fnt = qnode.front();
//#ifdef __test
//            cout << "leaf: " << fnt << endl;
//#endif
//            qnode.pop();
//            //xr[fnt] = nums[fnt]; //...
//            while (vi[fnt] != -1)
//            {
//                xr[vi[fnt]] ^= xr[fnt];
//                fnt = vi[fnt];
//            }
        }
        
#ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            cout << i << " p: " << vi[i] << ", xr: " << xr[i] << ", val: " << nums[i] << endl;
        }
#endif

        int ans = INT_MAX;
        int t2 = 0;
        int t3 = 0;
        int xr1 = 0;
        int xr2 = 0;
        int xrr = 0;
        int ta = 0;
        int tb = 0;
        for (int i = 0; i < sz1 - 1; ++i)
        {
            t2 = edges[i][0];
            t3 = edges[i][1];

#ifdef __test
            cout << t2 << ", " << t3 << ", " << vi[t2] << " -- " << vi[t3] << endl;
#endif

            if (vi[t2] == t3)
            {
                ta = t2;
                xr1 = xr[t2];
            }
            else
            {
                ta = t3;
                xr1 = xr[t3];
#ifdef __test
                cout << t3 << ", ixr " << xr1 << endl;
#endif
            }

            int ori_xr1 = xr1;

            for (int j = i + 1; j < sz1 - 1; ++j)
            {
                t2 = edges[j][0];
                t3 = edges[j][1];
                
                xr1 = ori_xr1;

#ifdef __test

#endif

//                if (vi[t2] == t3)
//                {
//                    ta = t2;
//                    xr1 = xr[t2];
//                }
//                else
//                {
//                    ta = t3;
//                    xr1 = xr[t3];
//#ifdef __test
//                    cout << t3 << ", ixr " << xr1 << endl;
//#endif
//                }


                if (vi[t2] == t3)
                {
                    tb = t2;
                    xr2 = xr[t2];
                }
                else
                {
                    tb = t3;
                    xr2 = xr[t3];
                }

                bool ba = true;        // i is j's parent
                bool bb = true;        // j is i's parent
                bool bc = true;        // not parent

                int t12 = ta;
                while (t12 != -1)
                {
                    if (t12 == tb)
                    {
                        ba = false;
                        bb = true;
                        bc = false;
                    }
                    t12 = vi[t12];
                }

                if (ba)
                {
                    t12 = tb;
                    while (t12 != -1)
                    {
                        if (t12 == ta)
                        {
                            ba = true;
                            bb = false;
                            bc = false;
                        }
                        t12 = vi[t12];
                    }
                }

                if (bc)
                {
                    bb = ba = false;
                }

                if (ba)
                {
                    // r -> i -> j
                    xrr = xr[1] ^ xr1;
                    xr1 = xr1 ^ xr2;
                }
                else if (bb)
                {
                    // r -> j -> i
                    xrr = xr[1] ^ xr2;
                    xr2 ^= xr1;
                }
                else
                {
                    // r - j   ,,,  r - i
                    xrr = xr[1] ^ xr1 ^ xr2;
                }

#ifdef __test
                cout << ba << ", " << bb << ", " << bc << endl;
                cout << " ---------  " << ta << ", " << t2 << ", " << t3 << endl;
                cout << i << ", " << j << ", " << xrr << ", " << xr1 << ", " << xr2 << endl;
#endif

                ans = min(ans, max({ xrr,xr1,xr2 }) - min({ xrr,xr1,xr2 }));
            }
        }

        return ans;
    }

};

int main()
{

    LT2322 lt;

    //myvi v = { 1,5,5,4,11 };
    //myvvi vv = { {1,0},{1,2},{1,3},{3,4} };

    myvi v = { 5,5,2,4,4,2 };
    myvvi vv = { {1,0},{1,2},{5,2},{4,3},{1,3} };

    cout << lt.lt2322a(v, vv) << endl;

    return 0;
}
