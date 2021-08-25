
#include "../header/myheader.h"

class LT1980
{
public:

// D D

//        while(st.find(ans) != st.end()) {
//            ans = getStr(nums.size());
//        }
//    string getStr(int n) {
//        string ans = "";
//        for(int i = 0; i < n; i++) {
//            ans += to_string(rand() % 2);
//        }
//        return ans;
//    }
// 。。。
// 随机。。。


//        for(int mask = 0; mask < (1 << n); mask++) {
//            // Construcing binary string from mask
//            string curr = "";
//            for(int j = 0; j < n; j++) {
//                if(mask & (1 << j)) {
//                    curr += "1";
//                } else {
//                    curr += "0";
//                }
//            }
//
//            reverse(curr.begin(), curr.end());
//
// 硬算。。
// 2^16 也不大，65535 ？


//    unordered_set<int> m;
//    for (auto &n : nums)
//        m.insert(stoi(n, nullptr, 2));
//    for (int x = 0; ; ++x)
//        if (!m.count(x))
//            return bitset<16>(x).to_string().substr(16 - nums.size());
//    return "";


//    for (int i = 0; i < nums.size(); ++i)
//        nums[0][i] = nums[i][i] == '0' ? '1' : '0';
//    return nums[0];
// 这个无法理解。  而且 nums[i][i] ，的第二个 i 不会越界？


//    string res(nums.size(), '0');
//    while (any_of(begin(nums), end(nums), [&res](const auto &num){ return num == res; }))
//        generate(begin(res), end(res),  [](){ return rand() % 2 ? '1' : '0'; });
//    return res;



    string discuss1(vector<string>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
            cout<<"        "<<i<<"m "<<nums[0]<<",m "<<", "<<nums[0][7]<<endl;
            nums[0][i] = nums[i][i] == '0' ? '1' : '0';
        }
        return nums[0];
    }
    // ... 越界了的。。 不知道为什么是正确的。 我本地是错误的。。



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Unique Binary String.
//Memory Usage: 10.2 MB, less than 48.00% of C++ online submissions for Find Unique Binary String.
// sort 然后二分。
    string lt1980a(vector<string>& nums)
    {
        std::sort(begin(nums), end(nums));
        if (to_int(nums[0]) != 0)
        {
            return string(nums[0].size(), '0');
        }
        bool is1 = true;
        for (char ch : nums[nums.size() - 1])
            if (ch != '1')
                is1 = false;
        if (!is1)
        {
            return string(nums[0].size(), '1');
        }

        #ifdef __test
        for (string& s : nums)
        {
            cout<<s<<", ";
        }
        cout<<endl;
        #endif // __test
        int l = 0;
        int r = nums.size() - 1;
        while (l + 1 < r)                   // 。。 下面不能 mid +1/-1..
        {
            int mid = (l + r) / 2;
            string s2 = nums[mid];
            int tl = to_int(nums[l]);
            int tm = to_int(s2);

            #ifdef __test
            cout<<l<<", "<<mid<<", "<<r<<", "<<tl<<", "<<tm<<endl;
            #endif // __test

            if (tm - tl > (mid - l))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        #ifdef __test
        cout<<l<<endl;
        #endif // __test

        if ((l == nums.size() - 1) || (to_int(nums[l]) + 1 == to_int(nums[l + 1])))
        {
            return to_str(to_int(nums[l]) - 1, nums[0].size());
        }
        else
        {
            return to_str(to_int(nums[l]) + 1, nums[0].size());
        }
    }

    string to_str(int num, int cnt)
    {
        string ans = "";
        while (num > 0)
        {
            ans = (num % 2 == 1 ? "1" : "0") + ans;
            num >>= 1;
        }
        while (ans.size() < cnt)
        {
            ans = "0" + ans;
        }
        return ans;
    }

    int to_int(string& s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            ans <<= 1;
            ans += s[i] - '0';
        }
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"01","10"};
//    vector<string> vs = {"00","01","11"};
//    vector<string> vs = {"0000000110","0000000011","0000000001","0000000000","0000001000","0000000100","0000000101","1111111111","0000000111","0000001001"};
    vector<string> vs = {"000","001","010","011","100","101","111"};

    LT1980 lt;

    cout<<lt.lt1980a(vs)<<endl;

    cout<<lt.discuss1(vs)<<endl;

    return 0;
}
