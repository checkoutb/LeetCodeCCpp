
#include "../header/myheader.h"

class LT2895
{
public:





//Runtime174 ms
//Beats
//50%
//Memory98.2 MB
//Beats
//66.67%

    // n process, n*4 core.  n*4 task
    // 1 core 1 task
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks)
    {
        sort(rbegin(tasks), rend(tasks));
        sort(begin(processorTime), end(processorTime));
        int ans = 0;
        int t2 = 0;
        for (int i = 0; i < processorTime.size(); ++i)
        {
            t2 = processorTime[i];
            ans = max(ans, t2 + tasks[i * 4]);
        }
        return ans;
    }

};

int main()
{

    LT2895 lt;


    return 0;
}
