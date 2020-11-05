
#include "../header/myheader.h"

class LT1111
{
public:




// wufa lijie ...
    vector<int> lt1111a(string seq)
    {
        vector<int> ans(seq.size());
        int i = 0;
        int cnt1 = 0;
        for (char ch : seq)
        {
//            cout<<cnt1<<endl;
            ans[i++] = cnt1 - (ch == ')' ? 1 : 0);
            cnt1 += (ch == '(' ? 1 : -1);
        }
        return ans;
    }

};

int main()
{

    string arr[] = {"(()())","()(())()","()"};

    LT1111 lt;

    for (string& s : arr)
    {
        vector<int> ans = lt.lt1111a(s);
        for_each (begin(ans), end(ans), fun_cout);
        cout<<endl;
    }


    return 0;
}
