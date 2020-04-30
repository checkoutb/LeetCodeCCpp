
#include "../header/myheader.h"

class LT0735
{
public:




//Runtime: 24 ms, faster than 17.87% of C++ online submissions for Asteroid Collision.
//Memory Usage: 7.4 MB, less than 100.00% of C++ online submissions for Asteroid Collision.

// ...主要是stack.pop 越界。。。次要是-2,-1,1,2

    vector<int> lt0735a(vector<int>& asteroids) {
        stack<int> stk1;
        vector<int> ans;
        for (int a : asteroids)
        {
            if (a >= 0)
            {
                stk1.push(a);
            }
            else
            {
                int b = -a;
                if (stk1.empty())
                {
                    ans.push_back(a);
                    continue;
                }
                int top = stk1.top();
                while (top <= b)
                {
                    if (top == b)
                    {
                        stk1.pop();
                        break;
                    }
                    else
                    {
                        stk1.pop();                     // ....
                        if (stk1.empty())
                        {
                            ans.push_back(a);
                            break;
                        }
                        top = stk1.top();
                    }
                }
            }
        }
        int sz1 = stk1.size();

        #ifdef __test
        cout<<sz1<<endl;
        #endif // __test
        int sz2 = ans.size();
        ans.resize(sz2 + sz1);
        while (!stk1.empty())
        {
            int top = stk1.top();
            ans[sz2 + (--sz1)] = top;
            stk1.pop();
        }
        return ans;
    }

};

int main()
{
//    vector<int> aa = {5,10,-5};

    vector<int> aa = {-2,-1,1,2};

    LT0735 lt;

    vector<int> ans = lt.lt0735a(aa);

    for_each(ans.begin(), ans.end(), fun_cout);

    return 0;
}
