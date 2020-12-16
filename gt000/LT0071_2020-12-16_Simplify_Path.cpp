
#include "../header/myheader.h"

class LT0071
{
public:

// D D

//    string res, tmp;
//    vector<string> stk;
//    stringstream ss(path);
//    while(getline(ss,tmp,'/')) {
//        if (tmp == "" or tmp == ".") continue;
//        if (tmp == ".." and !stk.empty()) stk.pop_back();
//        else if (tmp != "..") stk.push_back(tmp);
//    }
//    for(auto str : stk) res += "/"+str;
//    return res.empty() ? "/" : res;
// 第一个for 直接 pop



//Stack.pop() can be replaced by stack.poll() check size ZERO instead of throwing warning msg when stack is empty.
//stack.pollLast() and StringBuilder can be used instead of creating a lot of Strings objects in the stack.
// . diyici zhidao。  用的是 Deque。。。 Stack 没有 poll。



//Runtime: 8 ms, faster than 58.67% of C++ online submissions for Simplify Path.
//Memory Usage: 12.5 MB, less than 5.80% of C++ online submissions for Simplify Path.
    string lt0071b(string path)
    {
        stack<string> stk1;
        for (int i = 0; i < path.size(); ++i)
        {
            if (path[i] == '/')
                continue;
            string s;
            while (i < path.size() && path[i] != '/')
                s += path[i++];
            stk1.push(s);
        }
        string ans;
        int a = 0;
        while (!stk1.empty())
        {
            string s = stk1.top();
            stk1.pop();
            if (s == ".")
                continue;
            if (s == "..")
            {
                a--;
                continue;
            }
            if (a >= 0)
                ans = s + (ans.size() == 0 ? "" : "/" + ans);
            else
                a++;
        }
        ans = '/' + ans;
        return ans;
    }


// "/..."  ==> "/..."  ;;;  error
    string lt0071a(string path)
    {
        string ans;
        int a = 0;
        bool isFile = false;
        for (int i = path.size() - 1; i > 0; --i)
        {
            if (path[i] == '.')
            {
                if (path[i - 1] == '.')
                {
                    i--;
                    a--;
                }
                else
                {

                }
                isFile = false;
            }
            else if (path[i] == '/')
            {
//                if (path[i - 1] != '/')
//                {
//                    if (isFile)
//                    {
//                        a++;
//                    }
//                }
////                isFile = false;
            }
            else
            {
                isFile = true;
                string fn;
                while (std::isalnum(path[i]) || path[i] == '_')
                    fn = path[i--] + fn;
                if (a >= 0)
                {
                    ans = fn + (ans.size() != 0 ? "/" + ans : "");
                }
                else
                    a++;
            }
        }
        ans = '/' + ans;
        return ans;
    }

};

int main()
{
    string s = "/home/";
//    string s = "/../";

//    string s = "/home//foo/";
//    string s = "/a/./b/../../c/";
//    string s = "/a//b////c/d//././/..";
//    string s = "/...";


    LT0071 lt;

    cout<<lt.lt0071b(s);

    return 0;
}
