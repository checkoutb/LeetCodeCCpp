
#include "../header/myheader.h"

class LT1604
{
public:

// D D

// 388ms
// unordered_map<string, vector<int>> keys;
// int m = stoi(keyTime[i].substr(3,2));
// for { sort(vector<time>) }


// 524ms
//#include <bits/stdc++.h>
//
//using namespace std;
//
///* g++ -g -fsanitize=address -lasan -std=c++11 -Dfoo_ */
//
///* freopen("input.txt", "rt", stdin); */
///* freopen("output.txt", "wt", stdout); */
//
//#define ALL(c)          (c).begin(), (c).end()
//#define ALLR(c)         (c).rbegin(), (c).rend()
//#define FOR(i,a,b)      for (int i=(a); i < (b); ++i)
//#define FORR(i,a,b)     for (int i=(a); i > (b); --i)
//#define FOR_ALL(i,c)    for (__typeof((c).begin()) i=(c).begin();   \
//                             i != (c).end(); ++i)
//#define FOR_ALLR(i,c)   for (__typeof((c).rbegin()) i=(c).rbegin(); \
//                             i != (c).rend(); ++i)
//#define SZ(array)       (sizeof(array)/sizeof(array[0]))
//#define lc(x)           (x<<1)     /* 2*x */
//#define rc(x)           (x<<1 | 1) /* 2*x+1 */
//#define lowbit(x)       (x & (-x)) /* 0b10100 -> 0b100 */
//
//typedef long long       LL;
//typedef map<int,int>    MII;
//typedef pair<int,int>   PII;
//typedef set<int>        SI;
//typedef vector<bool>    VB;
//typedef vector<double>  VD;
//typedef vector<int>     VI;
//typedef vector<string>  VS;
//
///* check if a key is in container C */
//template <class C>
//inline bool in_(const typename C::key_type& k, const C& A)
//{ return A.find(k) != A.end(); }
//inline bool in_(const string& s, const string& S)
//{ return S.find(s) != string::npos; }
//
//struct Solution {
//    VS alertNames(const VS& name, const VS& time)
//    {
//        const int n = name.size();
//        map<string,VI> xs;
//        FOR(i,0,n) {
//            int hh,mm; sscanf(time[i].c_str(), "%d:%d", &hh,&mm);
//            xs[name[i]].push_back(hh*60+mm);
//        }
//        VS ans;
//        FOR_ALL(x,xs) {
//            VI& A = x->second;
//            sort(ALL(A));
//            FOR(i,0,A.size()) if (i+2 < A.size()) {
//                if (A[i+2]-A[i] <= 60)
//                    ans.push_back(x->first);
//            }
//        }
//        sort(ALL(ans));
//        ans.erase(unique(ALL(ans)), ans.end());
//        return ans;
//    }
//};
// ......


//    for (int i = 0; i < names.size(); ++i)
//        log[names[i]].push_back(stoi(times[i].substr(0, 2)) * 60 + stoi(times[i].substr(3)));
//    for (auto &p : log) {
//        sort(begin(p.second), end(p.second));
//        for (int i = 0, j = 0; i < p.second.size(); ++i) {
//            while(p.second[i] - p.second[j] > 60)
//                ++j;
//            if (i - j >= 2) {
//                res.push_back(p.first);
//                break;
//            }
//        }
//    }


//Runtime: 556 ms, faster than 26.53% of C++ online submissions for Alert Using Same Key-Card Three or More Times in a One Hour Period.
//Memory Usage: 119 MB, less than 21.63% of C++ online submissions for Alert Using Same Key-Card Three or More Times in a One Hour Period.
    vector<string> lt1604b(vector<string>& keyName, vector<string>& keyTime)
    {
        int sz1 = keyName.size();
        unordered_map<string, pair<int, int>> map2;     // name : <lastlast, last>
        set<pair<int, string>> set2;        // time : name          //  name : time  will be better ?
        set<string> ans;
        for (int i = 0; i < sz1; ++i)
        {
            string& name = keyName[i];
            string& tm = keyTime[i];
            int tm2 = ((tm[0] - '0') * 10 + (tm[1] - '0')) * 60 + (tm[3] - '0') * 10 + (tm[4] - '0');
            set2.insert({tm2, name});
        }
        for (set<pair<int, string>>::iterator it = begin(set2); it != end(set2); it++)
        {
            string name = it->second;
            int tm2 = it->first;
            if (ans.find(name) != ans.end())
                continue;
            if (map2.find(name) == map2.end())
            {
                map2[name] = {-1, tm2};
                continue;
            }
            pair<int, int>& p = map2[name];
            if (p.first >= 0 && tm2 - p.first <= 60)
                ans.insert(name);
            else
                p.first = std::__exchange(p.second, tm2);
        }
        return vector<string>(begin(ans), end(ans));
    }

// error 无序。
// 时间应该是有序的。 // 12:13 00:11 12:14.
    vector<string> lt1604a(vector<string>& keyName, vector<string>& keyTime)
    {
        int sz1 = keyName.size();
//        vector<string> ans;
        unordered_map<string, pair<int, int>> map2;         // name : <lastlast, last>
        set<string> ans;
        for (int i = 0; i < sz1; ++i)
        {
            string name = keyName[i];
            if (ans.find(name) != ans.end())
                continue;
            string tm = keyTime[i];
            int tm2 = ((tm[0] - '0') * 10 + (tm[1] - '0')) * 60 + (tm[3] - '0') * 10 + (tm[4] - '0');
            if (map2.find(name) == map2.end())
            {
                map2[name] = {-1, tm2};
                continue;
            }
            pair<int, int>& p = map2[name];
            if (p.second > tm2)
            {
                p.first = -1;
                p.second = tm2;
            }
            else
            {
                if (p.first >= 0 && tm2 - p.first <= 60)
                    ans.insert(name);
                p.first = p.second;
                p.second = tm2;
            }
        }
        return vector<string>(begin(ans), end(ans));
    }

};

int main()
{
//    vector<string> vs1 = {"daniel","daniel","daniel","luis","luis","luis","luis"};
//    vector<string> vs2 = {"10:00","10:40","11:00","09:00","11:00","13:00","15:00"};

//    vector<string> vs1 = {"alice","alice","alice","bob","bob","bob","bob"};
//    vector<string> vs2 = {"12:01","12:00","18:00","21:00","21:20","21:30","23:00"};

//    vector<string> vs1 = {"john","john","john"};
//    vector<string> vs2 = {"23:58","23:59","00:01"};

//    vector<string> vs1 = {"leslie","leslie","leslie","clare","clare","clare","clare"};
//    vector<string> vs2 = {"13:00","13:20","14:00","18:00","18:51","19:30","19:49"};
//
//    vector<string> vs1 = {};
//    vector<string> vs2 = {};
//
//    vector<string> vs1 = {};
//    vector<string> vs2 = {};

//    vector<string> vs1 = {"a","a","a","a","a","a","b","b","b","b","b"};
//    vector<string> vs2 = {"23:27","03:14","12:57","13:35","13:18","21:58","22:39","10:49","19:37","14:14","10:41"};

    vector<string> vs1 = {"a","a","a"};
    vector<string> vs2 = {"12:57","13:35","13:18"};         // ... 13:18 不是第二天的？
    //  in a single day. , 以为这是说 跨天 不算 就是 23:55  25:57  00:02 这种跨天，不触发 警告。
    //      结果，这里是说， 所有的 time 是 某一天内的。。。。


    LT1604 lt;

    vector<string> ans = lt.lt1604b(vs1, vs2);
    for (string& s : ans)
        cout<<"   "<<s;

    return 0;
}
