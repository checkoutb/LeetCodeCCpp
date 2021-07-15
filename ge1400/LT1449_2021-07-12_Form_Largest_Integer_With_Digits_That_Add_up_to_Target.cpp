
#include "../header/myheader.h"

class LT1449
{
public:

// D D

//        for (char i = 1; i <= 9; i++){
//            for (int j = 1; j <= target; j++){
//                if (j < cost[i-1]){
//                    dp_table[j][i] = dp_table[j][i-1];
//                }
//                else{
//                    dp_table[j][i] = max(dp_table[j][i-1], 1+dp_table[j-cost[i-1]][i]);
//                }
//            }
//        }


// 4-16是线性时间。。。
//        vector<int> dp(target + 1, -10000);
//        dp[0] = 0;
//        for (int t = 1; t <= target; ++t) {
//            for (int i = 0; i < 9; ++i) {
//                dp[t] = max(dp[t], t >= cost[i] ? 1 + dp[t - cost[i]] : -10000);
//            }
//        }
//        if (dp[target] < 0) return "0";
//        string res = "";
//        for (int i = 8; i >= 0; --i) {
//            while (target >= cost[i] && dp[target] == dp[target - cost[i]] + 1) {
//                res.push_back('1' + i);
//                target -= cost[i];
//            }
//        }
//        return res;




// 不知道使用 int[10] 来代替 string，会不会好一点，  使用vi(max(cost))
// [4, 16]有很多， 也有很多分散在 100-600之间。
//Runtime: 300 ms, faster than 35.75% of C++ online submissions for Form Largest Integer With Digits That Add up to Target.
//Memory Usage: 140.8 MB, less than 61.45% of C++ online submissions for Form Largest Integer With Digits That Add up to Target.
// hint 1 & 2 : dp,   find the maximum digits to paint given a total cost.
// 子问题是  总消耗为0,1,2,3,...target 时的 最大可能。
// 因为 总消耗 变大以后， 就是在 总消耗-cost 最大的基础上  insert 一个char。   还是不清楚 频繁构建 string的消耗会不会很大
    string lt1499b(vector<int>& cost, int target)
    {
        unordered_map<int, char> map2;
        for (int i = 8; i >= 0; --i)
        {
            if (map2.find(cost[i]) == map2.end())
            {
                map2[cost[i]] = (char) (i + 1 + '0');
            }
        }
        vector<string> vi(target + 1);          // vector<>(max(cost))
        for (int i = 1; i <= target; ++i)
        {
            for (unordered_map<int, char>::iterator it = begin(map2); it != end(map2); it++)
            {
                int t2 = i - it->first;
                if (t2 == 0)
                {
                    string s(1, it->second);
                    #ifdef __test
//                    cout<<". "<<s<<". "<<(it->second)<<endl;
                    #endif // __test
                    if (firstBig(s, vi[i]))
                        vi[i] = s;
                }
                if (t2 > 0 && !vi[t2].empty())
                {
                    string s = insertMax(vi[t2], it->second);
                    if (firstBig(s, vi[i]))
                    {
                        vi[i] = s;
                    }
                }
            }
        }
        return vi[target].empty() ? "0" : vi[target];
    }

    string insertMax(string& s1, char ch)
    {
        string s(s1);
        string::iterator it = std::lower_bound(begin(s), end(s), ch, [&s](char a, char b){ return a > b; });         // rbegin  insert
        s.insert(it, ch);
        #ifdef __test
//        cout<<s1<<", "<<ch<<" -> "<<s<<endl;
        #endif // __test
        return s;
    }

    bool firstBig(string& s1, string& s2)
    {
        if (s1.size() != s2.size())
            return s1.size() > s2.size();
        return s1 > s2;     // 长度相同，字典顺序 和 自然数顺序
    }



// error
// 相同消耗，肯定是拿 大的。
// 低消耗低值， 高消耗高值    应该还是 拿低消耗， 因为 如果最终 消耗完， 那么始终需要 数字来消耗剩余的。 所以必然会多一位。
// 那就是dfs，优先拿低消耗， 直到消耗完，  第一次消耗完的就是结果。
//
    string lt1499a(vector<int>& cost, int target)
    {
        vector<int> vi(10, 0);
        map<int, int> map2;
        for (int i = cost.size() - 1; i >= 0; --i)
        {
            if (map2.find(cost[i]) == map2.end())
            {
                map2[cost[i]] = i + 1;
            }
        }
        dfsa1(map2, 0, vi, target);
        #ifdef __test
        for (auto& p : map2)
            cout<<p.first<<" : "<<p.second<<endl;
        showVectorInt(vi);
        #endif // __test

        string ans;
        for (int i = 9; i > 0; --i)
        {
            if (vi[i])
            {
                ans += string(vi[i], (char) ('0' + i));
            }
        }
        return ans.empty() ? "0" : ans;
    }
//    bool got = false;
    bool dfsa1(map<int, int>& map2, int cst, vector<int>& vi, int remain)
    {
//        cout<<cst<<", "<<remain<<endl;            // 最开始用got，返回void，后来变成返回bool，for后面没有加return，死循环。
//        getchar();
//        if (got)
//            return true;
        if (remain == 0)
        {
//            got = true;
            return true;
        }
        if (remain < cst)
            return false;

        std::map<int, int>::iterator it = map2.upper_bound(cst);
        if (it == end(map2))
            return false;
        for (int i = (remain / it->first); i >= 0; --i)
        {
            vi[it->second] += i;
            if (dfsa1(map2, it->first, vi, remain - i * it->first))
                return true;
            vi[it->second] -= i;                // --.
        }
        return false;
    }

};

int main()
{
    cout<<("11111" > "22")<<endl;       // false,, 字典顺序。
    cout<<("321" < "320")<<endl;        // true
    cout<<("885" < "155")<<endl;

    cout<<endl<<endl;

//    myvi v = {4,3,2,5,6,7,2,5,5};
//    int t = 9;

    myvi v = {7,6,5,5,5,6,8,7,8};
    int t = 12;

//    myvi v = {2,4,6,2,4,6,4,4,4};
//    int t = 5;

//    myvi v = {6,10,15,40,40,40,40,40,40};
//    int t = 47;

//    myvi v = {5,6,7,3,4,6,7,4,8};           // "884444444"
//    int t = 29;


    LT1449 lt;

    cout<<lt.lt1499b(v, t)<<endl;

    return 0;
}
