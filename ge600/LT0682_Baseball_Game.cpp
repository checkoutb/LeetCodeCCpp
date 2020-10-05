
#include "../header/myheader.h"

class LT0682
{
public:


//Runtime: 8 ms, faster than 82.19% of C++ online submissions for Baseball Game.
//Memory Usage: 8.8 MB, less than 6.05% of C++ online submissions for Baseball Game.
    int lt0682a(vector<string>& ops)
    {
        stack<int> stk1;
        int t1 = 0;
        int t2 = 0;
        for (string& op : ops)
        {
            switch(op[0])           // case label is a integer.
            {
            case 43:
            {
                t1 = stk1.top();            // zheli buneng  int t1 = stk1.top... xuyao {} baowei. case meiyou zuoyongyu.
                stk1.pop();
                int t2 = stk1.top();
                stk1.push(t1);
                stk1.push(t1 + t2);
                break;
            }
            case 'D':
                stk1.push(2 * stk1.top());
                break;
            case 67:
                stk1.pop();
                break;

            default:
                int v = std::stoi(op);
                stk1.push(v);
                break;
            }
        }
        int ans = 0;
        while (!stk1.empty())
        {
            ans += stk1.top();
            stk1.pop();
        }
        return ans;
    }

};

int main()
{
//    vector<string> v = {"5","2","C","D","+"};
    vector<string> v = {"5","-2","4","C","D","9","+","+"};

    LT0682 lt;

    cout<<lt.lt0682a(v)<<endl;

    return 0;
}
