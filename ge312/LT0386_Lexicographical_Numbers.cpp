
#include "../header/myheader.h"


bool compa1(const int& a, const int& b);

int arr[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 10000000};

// 默认有 less，greater，应该是调用operator<来进行判断的。
// 真想itos。。。
bool compa1(const int& a, const int& b)
{
    int sz1 = 0;
    int sz2 = 0;
    int a1 = a;
    int b1 = b;
    while (a1 > 0)
    {
        a1 /= 10;
        sz1++;
    }
    while (b1 > 0)
    {
        b1 /= 10;
        sz2++;
    }

    if (sz1 == sz2)
    {
        return a < b;
    }

    int sz = min(sz1, sz2);

    a1 = a / arr[sz1 - sz];
    b1 = b / arr[sz2 - sz];

    if (a1 != b1)
    {
        return a1 < b1;
    }

    return sz1 < sz2;
}

class LT0386
{
public:


// discuss：

// 一次成型
//    vector<int> lexicalOrder(int n) {
//        vector<int> res(n);
//        int cur = 1;
//        for (int i = 0; i < n; i++) {
//            res[i] = cur;
//            if (cur * 10 <= n) {
//                cur *= 10;
//            } else {
//                if (cur >= n)
//                    cur /= 10;
//                cur += 1;
//                while (cur % 10 == 0)
//                    cur /= 10;
//            }
//        }
//        return res;
//    }
// 1999 + 1 = 2000 -> 2


//    public List<Integer> lexicalOrder(int n) {
//        List<Integer> res = new ArrayList<>();
//        for(int i=1;i<10;++i){
//          dfs(i, n, res);
//        }
//        return res;
//    }
//    public void dfs(int cur, int n, List<Integer> res){
//        if(cur>n)
//            return;
//        else{
//            res.add(cur);
//            for(int i=0;i<10;++i){
//                if(10*cur+i>n)
//                    return;
//                dfs(10*cur+i, n, res);
//            }
//        }
//    }
// [1, 10) 开头的数字。
// 然后继续后面加[0, 9].直到>n
// dfs 首行的if 和 for[0, 9]里的if 重复了。。不，如果n<9的话，dfs首行if是必须的。。所以是for[0, 9]中的if多余了。加上可以少一次函数调用。
//      或者最外层 i<min(10, n);


//Runtime: 136 ms, faster than 20.13% of C++ online submissions for Lexicographical Numbers.
//Memory Usage: 11.6 MB, less than 67.75% of C++ online submissions for Lexicographical Numbers.

    // 自定义comparator，然后sort。
    vector<int> lt0386a(int n)
    {

        // leetCode 上这段代码始终都是 heap-buffer-overflow...本地ok的。 ++i的问题。
        // LC上cout是
//        1, 0
//        2, 1
//        3, 2
//        4, 3
//        5, 4
//        6, 5
//        7, 6
//        8, 7
//        9, 8
//        10, 9
//        11, 10
//        12, 11

        // 本地是：
        // 1, 1
        // 2, 2
        // ...
        // 13, 13

        // 本地是：         取result + i 地址。然后i自增，然后赋值。
        // LC上，似乎是：   取result + i 地址，赋值，然后i自增。
                        // 不。。是先i自增，然后取地址，再赋值。
                        // 所以导致i==13的时候，先自增成14，result[14] 就越界了。所以也没有13，12这种输出。



        vector<int> result(n);
        for (int i = 0; i < n;)
        {
            result[i] = ++i;
            #ifdef __test
            cout<<i<<", "<<result[i - 1]<<endl;
            #endif // __test
        }



//        // 这段accepted
//        vector<int> result;
//        for (int i = 1; i <= n; i++)
//        {
//            result.push_back(i);
//        }



    // LC 上，输出5,1    10,7
//        int ar2[] = {4,5,6,7,8,9,10,11,12};
//        int a1 = 1;
//        ar2[a1] = a1++;
//        cout<<ar2[a1 - 1]<<","<<ar2[a1]<<endl;
//
//        a1 = 6;
//        ar2[a1] = ++a1;
//        cout<<ar2[a1 - 1]<<","<<ar2[a1]<<endl;


    // 本地也是5，1     10，7
//        int ar2[] = {4,5,6,7,8,9,10,11,12};
//        int a1 = 1;
//        ar2[a1] = a1++;
//        cout<<ar2[a1 - 1]<<","<<ar2[a1]<<endl;
//
//        a1 = 6;
//        ar2[a1] = ++a1;
//        cout<<ar2[a1 - 1]<<","<<ar2[a1]<<endl;
        // 都是先执行++，然后寻址，赋值。不是。

        // 数组，a1++:  保留a1; a1++; ar2 + a1; 赋 a1 原值。
            //   ++a1:  ++a1; ar2 + a1; 赋值

    // push i，i+1, push i
    // i+1, push i, push i    的区别？？？？？？？？？？？？？？？究竟是怎么压栈的，或者寄存器？



    // LC上       5，1      10，7
    // 本地       1，6      7，11
        vector<int> ar2 = {4,5,6,7,8,9,10,11,12};
        int a1 = 1;
        ar2[a1] = a1++;
        cout<<ar2[a1 - 1]<<","<<ar2[a1]<<endl;

        a1 = 6;
        ar2[a1] = ++a1;
        cout<<ar2[a1 - 1]<<","<<ar2[a1]<<endl;

        // 编译器的差异。
        // LC的数组和vector 一致。

        // 本地的vector
        // a1++:    ar2 + a1, 赋值， a1++;
        // ++a1:    ar2 + a1, a1++, 赋值
        // 区别是，++ 在赋值前还是后，，但是++肯定在寻址之后。
        //   本地先执行 = 左侧的。

        // LC，本地，vector的区别是：
        //      ++a1 :  ++ 在寻址之前还是之后。。。但是++肯定在赋值之前。
        //      a1++  差的太多了。。LC上会保留原值，i+1, 寻址，赋原值。
                                // 本地直接 寻址，赋值，++；



        // 保留原值

        // 看来以后出现 i++, 或 ++i 后，这个等式里 不能再有 i出现。就是那个 i = (i++) + (++i) + (++i);
        // 没有规定的，都是 编译器自我发挥。



        sort(result.begin(), result.end(), compa1);

        return result;
    }

private:

};



int main()
{
    int n = 13;

    LT0386 lt;
    vector<int> v2 = lt.lt0386a(n);

    cout<<endl;
    for_each(v2.begin(), v2.end(), fun_cout);
    cout<<endl;

    return 0;
}
