
#include "../../header/myheader.h"

class LT
{
public:

// D D

// | 而不是 +

//        vector<int> ans(1<<n);
//        for (int i=0; i<(1<<n); i++)
//            ans[i] = i^(i>>1);
//        return ans;






// 3年前的，硬算的。。 现在反而。。
//07/02/2021 09:02	Accepted	8 ms	11.3 MB	cpp
//03/24/2018 13:34	Accepted	4 ms	N/A	java
//03/24/2018 13:34	Accepted	5 ms	N/A	java
//        List<Integer> result = new LinkedList<>();
//        Set<Integer> set = new HashSet<>();
//        int[][] bits = new int[n][2];
//        int i = 0;
//        int t = 1;
////        bits[0][1] = t;
//        for(i = 0; i < n; i++)
//        {
//            bits[i][1] = t;               // 1 2 4 8 16 32 64 。。。。
//            t *= 2;
//        }
////        long size = (long) Math.pow(2, n);
//        int size = t;
//        result.add(0);
//        set.add(0);
//        t = 0;                // 起始0,  t始终是 上一个格雷码。
//
////        System.out.println(size);
//
//        while(result.size() < size)
//        {
//            for(i = 0; i < n; i++)            // 每次只修改一位， 然后通过set来判断是否已存在。
//            {
//                if(bits[i][0] == 0)           // 没有用过？。。不，这个是代表 t的 i位 是0还是1。
                                // 4bit的序列应该是：
//      0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000
// 好像有点反序的意思。
// 由于2位的格雷码慢了，那么就只能在最后一个格雷码 + 0100  变成0110
// 由于 记录了 bits[i][0] , 所以会反向走一边。(之前由于 bits[i][0]是0,那么走if的代码，并且设置为1, +0100后，由于这个bit[][]是1,所以导致走else的代码，这样的话就回滚了。)
//
//                {
//                    t += bits[i][1];
//                    if(set.contains(t))
//                    {
//                        t -= bits[i][1];
//                        continue;
//                    }
//                    else
//                    {
//                        set.add(t);
//                        result.add(t);
//                        bits[i][0] = 1;       // 由于有set的存在，所以不会存在 +2 -2 +2 -2 这种循环。
//                        break;
//                    }
//                }
//                else
//                {
//                    t -= bits[i][1];
//                    if(set.contains(t))
//                    {
//                        t += bits[i][1];
//                        continue;
//                    }
//                    else
//                    {
//                        set.add(t);
//                        result.add(t);
//                        bits[i][0] = 0;
//                        break;
//                    }
//                }
//            }
//        }
//
//        return result;



// 2^16 = 65536 ...
// 00 01 11 10
// 000 001 011 111 110 100     -- 101  010
// 000 001 011 010      100 101 111 110
// 000 010 110 100      001 011 111 101
// 000 001 101
//这种方法基于格雷码是反射码的事实，利用递归的如下规则来构造：
//    1位格雷码有两个码字
//    (n+1)位格雷码中的前2n个码字等于n位格雷码的码字，按顺序书写，加前缀0
//    (n+1)位格雷码中的后2n个码字等于n位格雷码的码字，按逆序书写，加前缀1 [4]                --- 逆序。
//    n+1位格雷码的集合 = n位格雷码集合(顺序)加前缀0 + n位格雷码集合(逆序)加前缀1
//
    vector<int> lta(int n)
    {
//        int sz1 = 2 ^ n;      // ......xor.....   1<<n....
        int sz1 = (int) std::pow(2, n);
        vector<int> vi(sz1);
        vi[0] = 0;
        vi[1] = 1;
        int szn = 2;
        int t2 = 1;
        while (szn < sz1)
        {
            #ifdef __test
            cout<<szn<<endl;
            #endif // __test
            int t3 = 1 << t2;
            for (int i = 0; i < szn; ++i)
            {
                vi[i + szn] = vi[szn - 1 - i] + t3;
            }
            szn *= 2;
            t2++;
        }
        return vi;
    }

//    bool dfsa1(vector<int>& vi, int idx, )   + set...65536...
//    {
//        int lst = vi[idx - 1];
//        if (idx == vi.size())
//        {
//            if (isDiff1(0, lst))
//                return true;
//            return false;
//        }
//
//    }
//    bool isDiff1(int a, int b)
//    {
//        int c = a & b;
//        while (!(c & 1))
//            c >>= 1;
//        return c == 1;
//    }

};

int main()
{
//    int n = 2;
//    int n = 1;
    int n = 7;

    LT lt;

    myvi v = lt.lta(n);

    showVectorInt(v);

    return 0;
}
