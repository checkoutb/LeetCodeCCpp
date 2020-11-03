
#include "../header/myheader.h"

class LT1073
{
public:


// D

//  for (auto bit = 0; bit < sz || carry != 0; ++bit) {
//    auto b1 = bit < a1.size() ? a1[a1.size() - bit - 1] : 0;
//    auto b2 = bit < a2.size() ? a2[a2.size() - bit - 1] : 0;
//    auto sum = b1 + b2 + carry;
//    res.push_back(abs(sum) % 2);
//    carry = sum < 0 ? 1 : sum > 1 ? -1 : 0;
//  }

// 进位    carry = sum < 0 ? 1 : sum > 1 ? -1 : 0;     还有 push_back的abs。



// error
    vector<int> lt1073b(vector<int>& arr1, vector<int>& arr2)
    {
        vector<int> ans;
        int sz1 = arr1.size();
        int sz2 = arr2.size();
        int szmx = max(sz1, sz2);
        int t1, t2;
        int t = 0;
        for (int i = 0; i < szmx; i++)
        {
            t1 = (sz1 - i - 1) >= 0 ? arr1[sz1 - i - 1] : 0;
            t2 = (sz2 - i - 1) >= 0 ? arr2[sz2 - i - 1] : 0;
            t = t1 + t2 + t;
            ans.push_back(abs(t) % 2);          // abs
            if (t > 1)
            {
                t = (i % 2 == 0 ? -1 : 1);
            }
            else
            {
                t = 0;
            }
        }
        if (t == 1)
        {
            ans.push_back(1);
        }
        else if (t == -1)
        {
            ans.push_back(1);
            ans.push_back(1);
        }
        while (ans.size() > 1 && ans.back() == 0)
            ans.pop_back();
        reverse(begin(ans), end(ans));
        return ans;
    }


// error
    vector<int> lt1073a(vector<int>& arr1, vector<int>& arr2)
    {
        vector<int> ans;
        int sz1 = arr1.size();
        int sz2 = arr2.size();
        int szmn = min(sz1, sz2);
        int t = 0;
        int bas = 1;
        int t2 = 0;
        for (int i = 0; i < szmn; i++)
        {
            t2 = (t + arr1[sz1 - i - 1] + arr2[sz1 - i - 1]) * bas;
//            if ()
            ans.push_back((t2 + abs(bas) * 3) % abs(bas));
            cout<<t<<", "<<t2<<", "<<bas<<", "<<ans.back()<<endl;
            bas *= -2;
        }
        if (sz1 > sz2)
        {
            for (int i = sz1 - szmn; i >= 0; i--)
            {
                t2 = t + arr1[i] * bas;
                t = t2 / bas;
                ans.push_back(t2 % bas);
                bas *= -2;
            }
        }
        else
        {
            for (int i = sz2 - szmn; i >= 0; i--)
            {
                t2 = t + arr2[i] * bas;
                t = t2 % bas;
                ans.push_back(t2 / bas);
                bas *= -2;
            }
        }
        while (ans.back() == 0)
            ans.pop_back();
        std::reverse(begin(ans), end(ans));
        return ans;
    }

};

int main()
{

//    vector<int> v1 = {1,1,1,1,1};
//    vector<int> v2 = {1,0,1};
//    vector<int> v1 = {1};
//    vector<int> v2 = {1};
//    vector<int> v1 = {1};
//    vector<int> v2 = {1,1};
    vector<int> v1 = {1};
    vector<int> v2 = {1,0,1};

    LT1073 lt;

    vector<int> v = lt.lt1073b(v1,v2);

    for_each(v.begin(), v.end(), fun_cout);

    return 0;
}
