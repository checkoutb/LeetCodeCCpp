
#include "../../header/myheader.h"

class LT6109
{
public:




    // vi 代表的是 这天有 多少 人能够 传播出去。
    // 

    //   1  2  3  4  5  6   day
    //show vector<int> :
    //0, 1, 0, 1, 1, 0, 0,          // 第一天的时候，只有一个人知道，根据delay，forget， 他会在3，4传播
    //    show vector<int> :
    //0, 1, 0, 1, 1, 0, 0,          // 第二天， 还是只有一个人知道， 但是 没有新增
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 1,          // 第三天   新增一人，所以有2个人知道，并且 新增的这人会在 5.6传播
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 2,          // 4， 新增一人， 有3个人知道， 并且今天新增的人会在 6传播
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 2,          // 5， 新增一人，遗忘一人， 所以 3人知道， 并且今天新增的人 不会传播了。
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 2,          // 6， 新增2人，没有人遗忘， 所以 5个人。
    //    5

    // 问题在于，为什么 我 累加 最后的 forget 个值，  也是 ans。

    // 应该是 vi 保存 [i]这天开始记得 -  [i] 这天开始遗忘   的人 ，  然后 一个int 保存 [i] 这天的 总人数？
    // 不对的， 因为看起来，这个 结果是 这天 没有遗忘秘密的人，  因为 上面 第六天新增的2个人， 他们在第6天是不知道秘密的，第8天才会记得。
    // 感觉这道题目要被喷了。。

    // 。。。 share， 不是记得。。 所以 新增的人 是知道的，只不过 不share。

    // 所以最后的 forget 个值 是没有问题的， forget之前的值 他们已经忘记了。

    // 对对对，所以 没有问题。  所以 最后记得秘密的人 就是 最后 forget天 内 被 share的人。





    // AC 。。。。++，有点崩 了。。。  不知道为什么对。。。
    // fibonacci
    // 遗忘的这天不能share .. delay天前 到 forget天为止。
    // 算是一个 sliding window?
    // 反过来算，不是 几天前。  而是 今天可以 扩散到 哪些天。
    // ....no
    int lta(int n, int delay, int forget)
    {

        vector<int> vi(n + 1);
        vi[1] = 1;
        const int MOD = 1e9 + 7;
        
        int t2 = 0;

        for (int i = 1; i <= n; ++i)
        {
            int st = i + delay;
            int en = i + forget - 1;
            //st = min(st, n);
            
            en = min(en, n);

            int t2 = vi[1];

            for (int j = st; j <= en; ++j)
            {
                vi[j] = (vi[i] + vi[j]) % MOD;
            }
#ifdef __test
        showVectorInt(vi);
#endif
        }

        int ans = 0;

        for (int i = 0; i < forget; ++i)
        {
            ans = (ans + vi[n - i]) % MOD;
        }

        return ans;


//        vector<int> vi(n + 1);
//        vi[1] = 1;
//        const int MOD = 1e9 + 7;
//        int ans = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            int st = i + delay;
//            int en = i + forget;
//            st = min(st, n);
//            en = min(en, n);
//
//            for (int j = st; j < en; ++j)
//            {
//                vi[j] = (vi[i] + vi[j]) % MOD;
//            }
//        }
//
//#ifdef __test
//        showVectorInt(vi);
//#endif
//
//        return vi[n];


        //vector<int> vi(n + 1);
        //vi[1] = 1;

        //for (int i = 2; i <= n; ++i)
        //{

        //}
        //return vi[n];
    }

};

int main()
{

    LT6109 lt;

    myvi v = { 6,2,4 };
    //myvi v = { 4,1,3 };

    cout << lt.lta(v[0], v[1], v[2]) << endl;

    return 0;
}
