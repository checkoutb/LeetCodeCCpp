
#include "../header/myheader.h"

class LT0282
{
public:

// D D

//            if (start == 0)
//                dfs(num, target, i + 1, str + ret, x, x);
//            else {
//                dfs(num, target, i + 1, str + "*" + ret, sum - last + x * last, x * last);
//                dfs(num, target, i + 1, str + "+" + ret, sum + x, x);
//                dfs(num, target, i + 1, str + "-" + ret, sum - x, -x);
//            }
// 。。。 把 连乘的值传给后面了。


//class Solution {
//public:
//    vector<string> addOperators(string num, int target) {
//        std::vector<std::string> res;
//        int size = num.size();
//        std::string exp;
//        std::function<void(int, int64_t, int64_t)> f;
//
//        f = [&](int index, int64_t resultSoFar, int64_t prevVal) {
//            if (!exp.empty() && exp[0] != '+')
//                return;
//
//            if (index == size) {
//                if (resultSoFar == target) {
//                    res.push_back("");
//                    res.back().append(exp.begin() + 1, exp.end());
//                }
//                return;
//            }
//
//            int prevExpSize = exp.size();
//            for (int i = index; i < size; ++i) {
//                int s = i - index + 1;
//                if (num[index] == '0' && s > 1)
//                    continue;
//
//                exp.push_back('+');
//                exp.append(num.begin() + index, num.begin() + i + 1);
//                int64_t val = std::atoll(exp.c_str() + prevExpSize + 1);
//                f(i + 1, resultSoFar + val, val);
//
//                exp[prevExpSize] = '-';
//                f(i + 1, resultSoFar - val, -val);
//
//                exp[prevExpSize] = '*';
//                int64_t r = (resultSoFar - prevVal) + (val * prevVal);
//                f(i + 1, r, val * prevVal);
//                exp.resize(prevExpSize);
//            }
//        };
//
//        f(0, 0, 0);
//        return res;
//    }
//};
// lambda 直接访问外部变量。。



//Runtime: 400 ms, faster than 50.44% of C++ online submissions for Expression Add Operators.
//Memory Usage: 94.3 MB, less than 71.57% of C++ online submissions for Expression Add Operators.

// hint 1 Note that a number can contain multiple digits.
//      已经掉过坑了 10-5
// hint 2 Since the question asks us to find all of the valid expressions, we need a way to iterate over all of them. (Hint: Recursion!)
//      ?? 所以tle了
// hint 3 We can keep track of the expression string and evaluate it at the very end. But that would take a lot of time.
//              Can we keep track of the expression's value as well so as to avoid the evaluation at the very end of recursion?
//      但是* 优先级怎么确定
// hint 4 Think carefully about the multiply operator. It has a higher precedence than the addition and subtraction operators.
//1 + 2 = 3
//1 + 2 - 4 --> 3 - 4 --> -1
//1 + 2 - 4 * 12 --> -1 * 12 --> -12 (WRONG!)
//1 + 2 - 4 * 12 --> -1 - (-4) + (-4 * 12) --> 3 + (-48) --> -45 (CORRECT!)
//          ?? 似乎可以： 如果下一个符号是*， 那么把 自己*前缀 传给下一个 数值。  如果下一个不是*，那么就计算 前面的表达式的值 传给后面的前缀是1
// hint 5 We simply need to keep track of the last operand in our expression
//              and reverse it's effect on the expression's value while considering the multiply operator.
//      ok， 保持上一个操作符， 如果 现在是*，那么就 reverse 效果。 。。 但是连乘 怎么弄。？？？？？
//  ？？？ hint5 是描述 hint4的最后一个 推导：
//     1+2-4 == -1
//      碰到*， 检查到上一个是-，所以reverse，    -(-4)    ,,估计是这样的，  1+2+(-4),  所以 就变成了  -(-4)
//          但是  连乘 怎么弄。。 也可以。
//  1+2 -4*4*4
//  1+2 == 3
//  3-4  == -1
// 需要 记录 这个连乘 的值有多大啊。  不如 把 自己×前缀 给后面
// ..是否* 是自己选择的。。
    vector<string> lt0282c(string num, int target)
    {
        int sz1 = num.size();
        vector<int> vi(sz1);
        for (int i = 0; i < sz1; ++i)
            vi[i] = num[i] - '0';
        vector<string> ans;
        long t2 = 0;
        string t2s;
        for (int i = 0; i < sz1; ++i)
        {
            t2 *= 10;
            t2 += vi[i];
            t2s += to_string(vi[i]);
            dfsc1(vi, target, i + 1, t2, ans, t2s, 0);
            if (t2 == 0L)
            {
                break;          // 不能append
            }
        }
        return ans;
    }
    // string的消耗 究竟恐怖吗？
    void dfsc1(vector<int>& vi, int tar, int idx, long prev, vector<string>& ans, string exp, long result)
    {
        #ifdef __test
//        cout<<idx<<", "<<exp<<", "<<prev<<", "<<result<<endl;
        #endif // __test
        if (idx == vi.size())
        {
            if ((result + prev) == tar)
            {
                ans.push_back(exp);
            }
            return;
        }
        // ... 好烦，  000000.。。
        // 。。如果和前一个合并，，还是得reverse。。。
        // 不，prev 不和 结果合并。
        // 默认+，  如果是-，prev自己先乘-1.
        // 12*3 36
        // 12*34  == 12*3*10 + 12*4
        // 为什么合并，，， 而不是 在这里就决定有多长！！！！

//        string sss = to_string(vi[idx]);
//
//        // +
//        dfsc1(vi, tar, idx + 1, vi[idx], ans, exp + "+" + sss, result + prev);
//
//        // -
//        dfsc1(vi, tar, idx + 1, vi[idx] * -1, ans, exp + "-" + sss, result + prev);
//
//        // *
//        int t2 = prev * vi[idx];
//        dfsc1(vi, tar, idx + 1, 1,)
//
//
//        // append

        long t2 = 0;
        string t2s;
        for (int i = idx; i < vi.size(); ++i)
        {
            t2 *= 10;
            t2 += (vi[i]);
            t2s += to_string(vi[i]);
            // t2 和 t2前面的符号。
            dfsc1(vi, tar, i + 1, t2, ans, exp + "+" + t2s, result + prev);
            dfsc1(vi, tar, i + 1, t2 * -1, ans, exp + "-" + t2s, result + prev);
            dfsc1(vi, tar, i + 1, t2 * prev, ans, exp + "*" + t2s, result);
            if (t2 == 0L)
            {
                break;
            }
        }
    }



// tle
// 4种选择。不切，+-*
    vector<string> lt0282b(string num, int target)
    {
        vector<int> vi(num.size());
        for (int i = 0; i < num.size(); ++i)
        {
            vi[i] = num[i] - '0';
        }
        vector<string> ans;
        vector<int> ops(num.size());
        dfsb1(vi, 1, target, ans, ops);             // 1. not 0.
//        unordered_set<string> set2(begin(ans), end(ans));
//        #ifdef __test
//        cout<<ans.size()<<" <> ";
//        #endif // __test
//        ans.clear();
//        for (unordered_set<string>::iterator it = begin(set2); it != end(set2); it++)
//        {
//            ans.push_back(*it);
//        }
//        #ifdef __test
//        cout<<ans.size()<<endl;
//        #endif // __test
        return ans;
    }

    // ops 里保存lambda的引用。
    // 和a差不多。
    // 0:连接  1+  2-  3*
    void dfsb1(vector<int>& vi, int idx, int tar, vector<string>& ans, vector<int>& ops)
    {
        #ifdef __test
//        cout<<idx<<endl;
        #endif // __test
        if (idx == vi.size())
        {
            deque<string> dq;
            string sans;
            dq.push_back(std::to_string(vi[0]));
            sans += to_string(vi[0]);
            string ss;
            for (int i = 1; i < vi.size(); ++i)
            {
                #ifdef __test
//                cout<<" . ."<<i<<", "<<ops[i]<<", "<<vi[i]<<endl;
                #endif // __test
                switch(ops[i])
                {
                case 0:
//                    {           // 必须有，否则 jump to case label, 是因为编译器认为ss 后面还会用，所以每个分支都需要初始化一下，但是编译器应该能认得出 ss是这里新建的吧。。
                        //      不要在 case 里 定义变量
                        //          把 string ss 放外面，就没有问题了。
                        ss = dq.back();
                        dq.pop_back();
                        ss += std::to_string(vi[i]);
                        dq.push_back(ss);
                        sans += std::to_string(vi[i]);
                        break;
//                    }
                case 1:
                    dq.push_back("+");
                    dq.push_back(to_string(vi[i]));
//                    cout<<"asdads"<<endl;
                    sans += ("+" + to_string(vi[i]));
//                    cout<<"zxczxc"<<endl;
                    break;
                case 2:
                    dq.push_back("-");
                    dq.push_back(to_string(vi[i]));
                    sans += ("-" + to_string(vi[i]));
                    break;
                case 3:
                    dq.push_back("*");
                    dq.push_back(to_string(vi[i]));
                    sans += ("*" + to_string(vi[i]));
                    break;
                }
            }
            long t2 = 0;
//            string op = "+";
            int op = 1;

            #ifdef __test
//            cout<<"...."<<sans<<endl;
            #endif // __test

            while (!dq.empty())
            {
                long t3 = std::stol(dq.front());
                dq.pop_front();
//                if (!dq.empty())
//                {

                if (!dq.empty() && dq.front() == "*")
                {
                    while (!dq.empty() && dq.front() == "*")
                    {
                        dq.pop_front();

                        t3 *= stol(dq.front());
                        dq.pop_front();
                    }
                }
//                else
//                {
                    switch(op)
                    {
                    case 1:
                        t2 += t3;
                        break;
                    case 2:
                        t2 -= t3;
                        break;
                    }
//                }
//                }
                if (!dq.empty() && dq.front() == "+")
                    op = 1;
                else
                    op = 2;
                if (!dq.empty())
                    dq.pop_front();
            }
            #ifdef __test
//            cout<<t2<<endl;
            #endif // __test
            if (t2 == tar)
            {
                // ...expression ... string..... i need an eval().....
                ans.push_back(sans);
            }
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            if (idx > 0 && vi[idx - 1] == 0 && i == 0)           // 这个有问题。。 10000 这种就出错了。
                continue;
            ops[idx] = i;
            dfsb1(vi, idx + 1, tar, ans, ops);
        }
//        ops[idx] = 0;
//        dfsb1(vi, idx + 1, tar, ans, ops);
//
//        dfsb1(vi, idx + 1, tar, ans, ops);
//        dfsb1(vi, idx + 1, tar, ans, ops);
//        dfsb1(vi, idx + 1, tar, ans, ops);

//        if (idx == num.size())
//        {
//            deque<int> dq;
//            dq.push_back(vi[0]);
//            int mul = 1;
////            bool isPositive = true;
//            for (int i = 1; i < vi.size(); ++i)
//            {
//                switch(ops[i])
//                {
//                case:0
//                    int t2 = dq.back();
//                    dq.pop_back();
//                    t2 *= 10;
//                    t2 += mul * vi[i];
//                    dq.push_back(t2);
//                    break;
//                case:1
//                    dq.push_back(vi[i]);
//                    mul = 1;
////                    isPositive = true;
//                    break;
//                case:2
//                    dq.push_back(-vi[i]);
//                    mul = -1;
////                    isPositive = false;
//                    break;
//                case:3
//                    int t2 = dq.back();
//                    dq.pop_back();
////                    t2        // .......
//                    break;
//                }
//            }
//        }
    }


// error   10-5
// 1 <= num.length <= 10
// 9^10 == 34yi  > INT_MAX
    vector<string> lt0282a(string num, int target)
    {
//        vector<long>
//        vector<int> vi(num.size());
        vector<string> ans;
        vector<string> ops(num.size());
        dfsa1(num, 0, target, ans, ops, 0);
        return ans;
    }

    // 10-5....
    void dfsa2(string num, int idx, int target, vector<string>& ans, vector<string>& ops, int val)
    {
        if (idx == num.size())
        {
            deque<int> dq;
            dq.push_back(num[0] - '0');

        }
        return;
//        if (idx == num.size())
//        {
//            deque<char> deq;
//            deq.push_back(num[0]);
//            for (int i = 1; i < num.size(); ++i)
//            {
//                if (ops[i] == "*")
//                {
//                    int val = deq.back() - '0';
//                    deq.pop_back();
//
//                }
//                else
//                {
//                    deq.push_back(ops[i][0]);
//                    deq.push_back(num[i]);
//                }
//            }
//        }
    }


    // 1:+ 2:- 3:*
    // ops[0] is null
    // string...
    // youxianji ... 1+2*3 ?
    void dfsa1(string num, int idx, int target, vector<string>& ans, vector<string>& ops, int val)
    {
//        cout<<idx<<", "<<val<<endl;
        if (idx == num.size())
        {
            if (val == target)
            {
                string ss(1, num[0]);
                for (int i = 1; i < num.size(); ++i)
                {
                    ss += (ops[i] + num[i]);
                }
                #ifdef __test
                cout<<ss<<", "<<val<<endl;
                #endif // __test
                ans.push_back(ss);
                return;
            }
            else
            {
                return;
            }
        }

        ops[idx] = "+";
        dfsa1(num, idx + 1, target, ans, ops, val + (num[idx] - '0'));

        ops[idx] = "-";
        dfsa1(num, idx + 1, target, ans, ops, val - (num[idx] - '0'));

        ops[idx] = "*";
        dfsa1(num, idx + 1, target, ans, ops, val * (num[idx] - '0'));
    }

};

int main()
{
//    string sdf = "12345";
//    cout<<(sdf + 1)<<endl;        // no operator+..

//    string s = "123";
//    int tar = 6;

    string s = "232";
    int tar = 8;

//    string s = "105";
//    int tar = 5;

//    string s = "00";
//    int tar = 0;

//    string s = "3456237490";
//    int tar = 9191;


    vector<string> vss = {"123","232","105","00",
    "3456237490",
    ""};
    vector<int> vi = {6,8,5,0,9191};
//    vector<int> vsz = {};



    LT0282 lt;

    for (int i = 0; i < vss.size() && !vss[i].empty(); ++i)
    {
//        vector<string> vs = lt.lt0282c(s, tar);
        vector<string> vs = lt.lt0282c(vss[i], vi[i]);

        cout<<vs.size()<<endl;

        for (string& s: vs)
            cout<<s<<", ";
        cout<<endl<<" ================= "<<endl;
    }

    return 0;
}
