
#include "../header/myheader.h"

class LT1985
{
public:

// D D

//        auto comp = [](const string& s1, const string& s2){ return s1.size() == s2.size() ? s1 < s2 : s1.size() < s2.size();};
//        sort(nums.begin(), nums.end(), comp);
//        return nums[nums.size() - k];


//    nth_element(begin(nums), begin(nums) + k - 1, end(nums), [](const auto &a, const auto &b){
//        return a.size() > b.size() ? true : a.size() < b.size() ? false : a > b;
//    });
//    return nums[k - 1];
//nth_element




//Runtime: 312 ms, faster than 47.06% of C++ online submissions for Find the Kth Largest Integer in the Array.
//Memory Usage: 76.7 MB, less than 11.76% of C++ online submissions for Find the Kth Largest Integer in the Array.
// 按长度分组，然后 相同长度的 字典顺序，就是自然数顺序。
// 加前导0,使得长度一样，然后sort。
// .. 自定义sort方法。。先比较长度， 然后operator >
    string lt1985a(vector<string>& nums, int k)
    {
        map<int, int> map2;
        for (string& s : nums)
        {
            map2[s.size()]++;
        }
        int len = -1;
        int t2 = 0;
        for (map<int, int>::reverse_iterator rit = map2.rbegin(); rit != map2.rend(); rit++)
        {
            if (t2 + (rit->second) >= k)
            {
                len = rit->first;
                break;
            }
            t2 += rit->second;
        }
        t2 = k - t2;
        vector<string> vs;
        for (string& s : nums)
        {
            if (s.size() == len)
                vs.push_back(s);
        }
        #ifdef __test
//        cout<<len<<endl;
//        for (string& s : vs)
//            cout<<s<<", ";
//        cout<<endl;
//        cout<<t2<<endl;
        #endif // __test
        std::sort(begin(vs), end(vs), std::greater<string>());
        return vs[t2 - 1];
    }

};

int main()
{
//    vector<string> vs = {"3","6","7","10"};
//    int k = 4;

//    vector<string> vs = {"2","21","12","1"};
//    int k = 3;

    vector<string> vs = {"0","0"};
    int k = 2;

    LT1985 lt;

    cout<<lt.lt1985a(vs, k)<<endl;

    return 0;
}
