
#include "../header/myheader.h"

class LT1894
{
public:

// D D

//return bisect.bisect(list(accumulate(A)), k % sum(A))

//    k %= accumulate(begin(chalk), end(chalk), 0l);
//    for (int i = 0; i < chalk.size(); ++i)
//        if ((k -= chalk[i]) < 0)
//            return i;
//    return 0;



//Runtime: 120 ms, faster than 95.36% of C++ online submissions for Find the Student that Will Replace the Chalk.
//Memory Usage: 81.2 MB, less than 5.45% of C++ online submissions for Find the Student that Will Replace the Chalk.
    int lt1894a(vector<int>& chalk, int k)
    {
        vector<long> vl(chalk.size(), 0L);
        vl[0] = chalk[0];
        for (int i = 1; i < chalk.size(); ++i)
        {
            vl[i] = chalk[i] + vl[i - 1];
        }
        k = k % vl[vl.size() - 1];
        return std::distance(begin(vl), std::upper_bound(begin(vl), end(vl), k));
//        for (int i = 1; i < chalk.size(); ++i)
//        {
////            chalk[i] += chalk[i - 1];     // int越界
////            chalk         // 能用 %k 吗？
//        }
//        k = k % chalk[chalk.size() - 1];
//        return std::distance(begin(chalk), std::lower_bound(begin(chalk), end(chalk), k));
    }

};

int main()
{
//    myvi v = {5,1,5};
//    int k = 22;

    myvi v = {3,4,1,2};
    int k = 25;

    LT1894 lt;

    cout<<lt.lt1894a(v, k)<<endl;

    return 0;
}
