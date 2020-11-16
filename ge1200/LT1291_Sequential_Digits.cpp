
#include "../header/myheader.h"

class LT1291
{
public:

// D D

// 用queue 来 bfs。



// cnt++, 一直到-21亿。。。
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sequential Digits.
//Memory Usage: 6.5 MB, less than 12.02% of C++ online submissions for Sequential Digits.
    vector<int> lt1291a(int low, int high)
    {
        int cnt = 0;
        int lo2 = low;
        int fstlow = 0;
        while (lo2 > 0)
        {
            cnt++;
            lo2 = lo2 / 10;
        }
        vector<int> ans;
        long n = low;
//        int sz1 = -1;
//        while (sz1 != ans.size())
        while (n <= high && cnt <= 10)
        {
//            sz1 = ans.size();
            for (int i = 1; i <= 10 - cnt; i++)
            {
                n = i;
                int t1 = i;
                int cnt2 = 1;
                while (cnt2++ < cnt)
                {
                    t1++;
                    n *= 10;
                    n += t1;
                }
//                cout<<n<<","<<cnt<<",   "<<t1<<", "<<low<<", "<<high<<endl;
//                getchar();
                if (n < low)
                    continue;
                if (n <= high)
                    ans.push_back(n);
                else
                    break;
            }
            cnt++;
        }
        return ans;
    }

};

int main()
{

//    int l{100}, h{300};
//    int l{1000}, h{13000};
//    int l{8511}, h{23553};
    int l{10}, h{1000000000};

    LT1291 lt;

    vector<int> v = lt.lt1291a(l, h);

    showVectorInt(v);

    return 0;
}
