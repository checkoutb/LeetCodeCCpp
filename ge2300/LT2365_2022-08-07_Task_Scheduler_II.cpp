
#include "../header/myheader.h"

class LT2365
{
public:

    // D¡¡£Ä



//Runtime: 268 ms, faster than 100.00 % of C++ online submissions for Task Scheduler II.
//Memory Usage : 102.2 MB, less than 100.00 % of C++ online submissions for Task Scheduler II.
    // day from 1
    long long lt2365a(vector<int>& tasks, int space)
    {
        unordered_map<int, long long> map2;
        long long ans = 0LL;

        for (int i = 0; i < tasks.size(); ++i)
        {
            int t2 = tasks[i];
            long long lst = map2[t2];
            lst = lst == 0LL ? -space : lst;
            ans = max(ans, lst + space) + 1;
            map2[t2] = ans;
        }
        return ans;
    }

};

int main()
{

    LT2365 lt;

    //myvi v = { 1,2,1,2,3,1 };
    //int sp = 3;

    myvi v = { 5,8,8,5 };
    int sp = 2;

    cout << lt.lt2365a(v, sp) << endl;

    return 0;
}
