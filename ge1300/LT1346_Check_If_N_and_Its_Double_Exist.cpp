
#include "../header/myheader.h"

class LT1346
{
public:

// D D

//        unordered_set<int> s;
//        for (auto n : arr) {
//            if (s.find(n * 2) != s.end() || (n % 2 == 0 && s.find(n / 2) != s.end())) {
//                return true;
//            }
//            s.insert(n);
//        }



// 1 / 3 ...
//Runtime: 20 ms, faster than 15.83% of C++ online submissions for Check If N and Its Double Exist.
//Memory Usage: 11.9 MB, less than 5.23% of C++ online submissions for Check If N and Its Double Exist.
    bool lt1346a(vector<int>& arr)
    {
        int cnt0 = 0;
//        int mx = INT_MIN;
//        int mn = INT_MAX;
        unordered_set<int> set2;
        for (int i : arr)
        {
//            mx = max(mx, i);
//            mn = min(mn, i);
            if (i == 0)
                cnt0++;
            set2.insert(i);
        }

        #ifdef __test
        for (int i : set2)
            cout<<i<<", ";
        cout<<endl;
        #endif // __test

//        mx /= 2;
//        mn /= 2;

        for (int i : arr)
        {
            if (i == 0)
            {
                if (cnt0 > 1)
                    return true;
            }
            else
            {
                if (set2.find(i * 2) != set2.end())
                    return true;
            }
        }
        return false;
    }

};

int main()
{

    vector<int> v = {3,1,7,11};

    LT1346 lt;

    cout<<lt.lt1346a(v)<<endl;

    return 0;
}
