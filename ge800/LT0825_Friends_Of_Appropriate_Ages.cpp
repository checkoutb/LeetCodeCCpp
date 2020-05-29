
#include "../header/myheader.h"

class LT0825
{
public:


// D D
// res += a.second * (b.second - (a.first == b.first ? 1 : 0));     map<age,count>

//        for(int i=15; i<121 ;i++)
//        {
//            for(int j=0.5*i +8 ;j<=i;j++)
//                ans+=v[j]*(v[i]-(i==j));
//        }
// 1<=age<=120


// 怀疑人生了。

//Runtime: 120 ms, faster than 24.21% of C++ online submissions for Friends Of Appropriate Ages.
//Memory Usage: 29.1 MB, less than 33.33% of C++ online submissions for Friends Of Appropriate Ages.
    int lt0825c(vector<int>& ages)
    {
        int ans = 0;
        std::sort(begin(ages), end(ages));

        int t1 = ages[0];
        int t2 = 0;

        for (int i = 0; i < ages.size(); i++)
        {
            int factor = 1;
            while (i + 1 < ages.size() && ages[i] == ages[i + 1])
            {
                i++;
                factor++;
            }
            int t3 = ages[i] + 14;
            while (t1 * 2 <= t3)
            {
                t2++;
                t1 = ages[t2];
            }

            #ifdef __test
            cout<<i<<" - "<<t2<<" ... "<<t1<<", "<<t3<<endl;
            #endif // __test

            ans += max(0, i - t2) * factor;
        }

        return ans;
    }


// error
    int lt0825b(vector<int>& ages)
    {
        int ans = 0;
        map<int, int> map2;
        for (int i : ages)
        {
            map2[i]++;
        }
        vector<int> a;
        for (auto p : map2)
        {
            if (p.second >= 2)
            {
                ans += (p.second * (p.second - 1) - (p.second - 1) * p.second / 2);
            }
        }
        #ifdef __test
        cout<<ans<<endl;
        #endif // __test
        std::sort(ages.begin(), ages.end());
        int fst100 = std::lower_bound(ages.begin(), ages.end(), 100) - ages.begin();
        int lst100 = std::upper_bound(ages.begin(), ages.end(), 100) - ages.begin();
        for (int i = 1; i < ages.size(); i++)
        {
            int t1 = ages[i] + 14;
            for (int j = 0; j < i; j++)
            {
                if (ages[j] * 2 > t1)
                    ans++;
            }
        }
        for (int i = fst100 + 1; i < ages.size(); i++)
        {
            int t1 = ages[i] + 14;
            for (int j = fst100; j < i; j++)
            {
                if (ages[j] * 2 > t1)
                    ans++;
            }
        }
        return ans;
    }


// 73 / 83 tle..
    int lt0825a(vector<int>& ages)
    {
        int ans = 0;
        for (int i = 0; i < ages.size(); i++)
        {
            for (int j = 0; j < ages.size(); j++)
            {
                if (i == j)
                    continue;
                if (canRequest(ages[i], ages[j]))
                {
                    cout<<ages[i]<<" : "<<ages[j]<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }

    // b*2-14 > a > b
    bool canRequest(int a, int b)
    {
        if (b > 100 && a < 100)
            return false;
        if (b > a)
            return false;
        if (b * 2 - 14 <= a)
            return false;
        return true;
    }
};

int main()
{

    vector<int> ages = {101,56,69,48,30};

//    vector<int> ages = {20,30,100,110,120};

//    vector<int> ages = {16,16,16,16};

//    vector<int> ages = {16,16};

//    vector<int> ages = {16,17,18};

    LT0825 lt;

    cout<<lt.lt0825c(ages)<<endl;

    return 0;
}
