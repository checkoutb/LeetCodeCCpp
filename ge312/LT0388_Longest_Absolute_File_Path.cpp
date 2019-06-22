
#include "../header/myheader.h"

class LT0388
{
public:















//Runtime: 4 ms, faster than 82.32% of C++ online submissions for Longest Absolute File Path.
//Memory Usage: 8.9 MB, less than 31.49% of C++ online submissions for Longest Absolute File Path.
// 要么4ms，要么0ms。

// 1. 没有split。。。后来有了前导空格，就必须自己split了。。
// 2. dfs失败。。
// 3. 文件名的前导空格。。。。

// 用stack的话，2个方法可以合并的。

    // dfs + &
    int lt0388a(string input)
    {
        vector<string> v2;

        int pos = 0;
        int sz1 = input.size();
        int t1 = 0;
        int dep = 0;
        do
        {
//            t1 = input.find('\n\t', pos);         // 没有报错，但是第二个string  pos == 14,  t1 == 14
            t1 = input.find("\n", pos);

            #ifdef __test
            cout<<"      find "<<pos<<", "<<t1<<endl;
            #endif // __test

            if (t1 != -1)
            {
                #ifdef __test
                cout<<"             sub :"<<pos<<", "<<t1<<endl;
                #endif // __test

                string s2 = input.substr(pos, t1 - pos);

                if (s2.find('.') == -1)
                {
                    dep = 0;
                    int d2 = 0;
                    while (s2[d2] == '\t')
                    {
                        dep++;
                        d2++;
                    }
                }

                int i2 = 0;
                while (s2[0] == ' ' && i2 <= dep)
                {
                    s2 = s2.substr(4);
                    i2++;
                }

                #ifdef __test
                cout<<s2<<", "<<s2.size()<<"........"<<i2<<endl;
                #endif // __test

                while (i2 > 0)
                {
                    s2 = '\t' + s2;
                    i2--;
                }
                v2.push_back(s2);          // pos, length
            }
            pos = t1 + 1;

            #ifdef __test
            cout<<"pos: "<<pos<<endl;
            #endif // __test

        } while (pos != 0);

        string s2 = input.substr(input.rfind("\n") + 1, sz1);
        int i2 = 0;
        while (s2[0] == ' ' && i2 <= dep)
        {
            s2 = s2.substr(4);
            i2++;
        }
        while (i2 > 0)
        {
            s2 = '\t' + s2;
            i2--;
        }

        #ifdef __test
        cout<<s2<<", "<<s2.size()<<endl;
        #endif // __test

        v2.push_back(s2);         // sz1.超过了尾巴。

        #ifdef __test
        cout<<"------------"<<endl;
        for_each(v2.begin(), v2.end(), fun_cout_s);
        cout<<endl<<"--------"<<endl;;
        cout<<v2[1].size()<<endl<<v2[0].size()<<endl;
        #endif // __test

        int i = 0;
        int lv = 0;
        int r = 0;
//        while (i < sz1)
//            r = max(r, dfsa2(v2, i, lv));

        r = funa3(v2);
        return r;               // If there is no file in the system, return 0.
    }


    int funa3(vector<string>& v2)
    {
        int dep = 0;
        int i = 0;
        int r = 0;
        stack<int> sk1;
        sk1.push(-1);           // 前置\，
        while (i < v2.size())
        {
            string s = v2[i];
            while (!((dep < 1 || s[dep - 1] == '\t') && s[dep] != '\t'))
            {
                sk1.pop();
                dep--;
            }
            int t1 = sk1.top();
            t1 += (1 + s.size() - dep);
            sk1.push(t1);

            #ifdef __test
            cout<<s<<endl;
            show_stack_int(sk1);
            cout<<endl;
            #endif


            if (s.find('.') != -1)
            {
                #ifdef __test
//                show_stack_int(sk1);
                cout<<r<<".."<<t1<<", "<<s<<", "<<dep<<endl;
                #endif // __test
                r = max(r, t1);
            }
            i++;
            dep++;
        }
        return r;
    }

// error
    int dfsa2(vector<string>& v2, int& i, int lv)
    {
        #ifdef __test
        cout<<i<<", "<<lv<<endl;
//        system("pause");
        #endif // __test


        if (i >= v2.size())
            return 0;
        string s = v2[i];
        if ((lv < 1 || s[lv - 1] == '\t') && s[lv] != '\t' && s.find('.') != -1)
        {
            return s.size() - lv;
        }

        int r = 0;
        s = v2[i];
        int t2 = s.size() - lv;
        i++;
        lv++;
        while (i < v2.size())
        {
            s = v2[i];
            if ((lv < 1 || s[lv - 1] == '\t') && s[lv] != '\t')
            {
                int t1 = dfsa2(v2, i, lv);
                if (t1 != 0)
                    r = max(r, t1 + t2 + 1);
                i++;
            }
            else
            {
                i--;
                break;
            }
        }

        return r;
    }


    // error..
    int dfsa1(vector<string>& v2, int& i, int lv)
    {
        #ifdef __test
        cout<<i<<", "<<lv<<endl;
        #endif // __test

        if (i >= v2.size())
        {
            return 0;
        }

        string s = v2[i];

        if ((lv < 1 || s[lv - 1] == '\t') && s[lv] != '\t' && s.find('.') != -1)
        {
//            i++;
            #ifdef __test
            cout<<"file : "<<s<<", "<<s.size()<<endl;
            #endif // __test

            return s.size() - lv;
        }

        int r = 0;
        while (i < v2.size())
        {
            string s = v2[i];
            int t2 = s.size() - lv;

            #ifdef __test
            cout<<"          sss... "<<s<<".."<<s.size()<<" . "<<lv<<endl;
            if (t2 == 5)
            {
                cout<<"    this is 5."<<endl;
            }
            #endif // __test

            if ((lv < 1 || s[lv - 1] == '\t') && s[lv] != '\t')
            {
                i++;
                int t1 = dfsa1(v2, i, lv + 1);
                if (t1 != 0)
                    r = max(r, t1 + t2 + 1);


                #ifdef __test
                cout<<"                 . "<<t1<<", "<<t2<<", "<<lv<<".."<<r<<endl;
                #endif // __test
            }
            else
            {

                #ifdef __test
                cout<<"else, "<<i<<", "<<r<<endl;
                #endif // __test

                return r;
            }
        }

        #ifdef __test
        cout<<"dfs result : "<<i<<", "<<r<<endl;
        #endif // __test

        return r;
    }
};

int main()
{

//    string s = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    string s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
//    string s = "a";
//    string s = "dir\n    file.txt";         // .............. \t.........这里不包含文件夹，整个就是文件名字。。。。.....
//    string s = "dir\n    file.txt";     // 12...不包含 空格。。。为什么上面是直接名字。。
//    string s = "dir\n        file.txt";     // 16...这个是dir，，4个空格file.txt...4个空格表示缩进，4个空格是file.txt一部分。
                        // 文件夹不可能有空白，不然没办法分辨 和上一行是同层还是下一层了。
                // 需要上一层文件夹，来判断本层文件  文件名是否有前导空白。。。也不会啊。有空白就不可能确定了。
//dir1
//    dir2
//        dir3
//            file1.txt
// file1.txt 可能是dir3的。 也可能是  dir2的   4个空格file1.txt 啊。
// 先按最近文件夹的 可能来写。。。不可能按最长可能路径名来写吧。


//    string s = "a\n\tb1\n\t\tf1.txt\n\taaaaa\n\t\tf2.txt";          // 14
//    string s = "a\n\tb.txt\na2\n\tb2.txt";          // 9



    LT0388 lt;
    cout<<lt.lt0388a(s)<<endl;



    cout<<endl<<endl<<endl;

//    string s3 = "\tfile1.ext\n\t\ts";
//    cout<<s3.find("\n\t")<<endl;

// 这是一个warn，， '包含2个字符'  是个warn
//    cout<<s.find('\n\t', 14)<<endl;         // 似乎当 起始位置就越界的时候 返回 npos, 没有越界但是找不到返回  -1.。和cppreference上的用法有点两样。cppreference是 找不到都是npos,不管是否越界。
//                                        // https://en.cppreference.com/w/cpp/string/basic_string/find   Example最后一个，找不到，但是print中用 npos对比的。

    return 0;


//    string s = "dir\n\tasdf\n\t\tsssaw";
//
//    int i = s.find("\n\t");
//    cout<<i<<endl;
//    i = s.find("\n\t", i + 1);
//    cout<<i<<endl;
//    i = s.find("nil");
//    cout<<i<<endl;
//    i = s.find('d', 0);     // [0, end)
//    cout<<i<<endl;
//
//    i = s.find_first_of("\n\t");
//    cout<<i<<endl;
//    i = s.find_first_of("\n\t", i + 1);     // one of
//    cout<<i<<endl;
//    i = s.find_first_of("z");
//    cout<<i<<endl;
//
//    cout<<s.size()<<endl;       // 17   \n is 1.

    return 0;
}
