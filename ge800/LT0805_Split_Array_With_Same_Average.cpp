
#include "../header/myheader.h"

class LT0805
{
public:


// hard is always hard, easy is not easy.
// ..无法理解。。


// 59/88 tle
    bool lt0805a(vector<int>& A)
    {
        int allSum = std::accumulate(A.begin(), A.end(), 0);
        bool ans = dfsa1(A, 0, 0, 0, allSum);
        return ans;
    }

    bool dfsa1(vector<int>& a, int sum, int cnt, int index, int& allSum)
    {
        if (index == a.size())
        {
            if (cnt != 0 && cnt != a.size() - 1)
            {
                double avg1 = (double) sum / cnt;
                double avg2 = (double) (allSum - sum) / (a.size() - cnt);
                double diff = avg1 - avg2;
                if (std::abs(diff) < 0.0001)
                    return true;
            }
            return false;
        }
        if (dfsa1(a, sum + a[index], cnt + 1, index + 1, allSum))
            return true;
        if (dfsa1(a, sum, cnt, index + 1, allSum))
            return true;
        return false;
    }
};

int main()
{

//    vector<int> a = {1,2,3,4,5,6,7,8};
//    vector<int> a = {3,1};
    vector<int> a = {1,6,1};

    LT0805 lt;

    cout<<lt.lt0805a(a)<<endl;

    return 0;
}
