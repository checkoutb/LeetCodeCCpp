
#include "myheader.h"
#include <iomanip>


//struct MyKey
//{
//	int key;
//};
//
//struct MyKeyHashHasher
//{
//	size_t operator()(const MyKey &k) const noexcept
//	{
//		return std::hash<int>{}(k.key);
//	}
//};
//
//struct MyKeyHashComparator
//{
//	bool operator()(const MyKey &k1, const MyKey &k2) const noexcept
//	{
//		return k1.key == k2.key;
//	}
//};
//
//int main()
//{
//	std::unordered_set<MyKey,MyKeyHashHasher,MyKeyHashComparator> ss;
//	return 0;
//}





//class Hasher {
//public:
//    size_t operator() (string const& key) const {
//        size_t hash = 0;
//        for(size_t i = 0; i < key.size(); i++) {
//            hash += key[i] % 7;
//        }
//        return hash;
//    }
//};
//
//int main(int argc, char const *argv[]) {
//
//    unordered_multimap<int, int, Hasher, equal_to<int>> hashmap;






class MyClass
{
public:
    // 这个什么版本支持的。。这个从 LeetCode的 details 中复制的。
    // discuss里也有。https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/discuss/477659/4%2B-DP-Solutions
//    int memo[27][27][301] = {[0 ... 26][0 ... 26][0 ... 300] = -1};

    int dp[27][27][301];

    void myPrint()
    {
        memset(dp,-1,sizeof dp);
        cout<<"ZXC "<<dp[1][1][11]<<endl;
//        cout<<memo[22][22][33]<<endl;
    }
};

int asdf = 10;

int main()
{
    cout<<asdf<<endl;
    int asdf = 1000;
    cout<<"222 "<<asdf<<endl;

    // 默认是最大堆，下面是最小堆。
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

//    cout.setf(ios::fixed);        // == cout<<setiosflags(ios::fixed) == cout<<fixed;
    cout<<setiosflags(ios::fixed)<<setprecision(15)<<1.000000000000001<<endl;          // include iomanip
    cout.unsetf(ios::fixed);
    cout<<1.000000000000001<<endl;

    try
    {
//        throw -2;         // int
//        throw "error";      // ..not string, it is    const char* chp,   must const.
//        throw 1.23;       // double
//        throw string("asdasd");     // string
        throw new string("zzz");        // string *
    }
    catch (int i)
    {
        cout<<"catch: i "<<i<<endl;
    }
    catch (double d)
    {
        cout<<"catch: d "<<d<<endl;
    }
    catch (const char* chp)
    {
        cout<<"catch: char* "<<chp<<endl;
    }
    catch (string *s)
    {
        cout<<"catch: &s "<<s<<", "<<*s<<endl;
        delete s;
    }
    catch (string s)
    {   // 我竟然尝试把 {}删除。。。  后来一想，java也不能删除的吧(还真没有试过不写{})。。。可能是 catch { 同行，导致代码压缩，有种不需要{}的错觉。。
        cout<<"catch: s "<<s<<endl;
    }
    catch (...)         // must be the last handler
    {
        cout<<"catch: "<<"......"<<endl;
    }
//    catch (string s)
//    {
//        cout<<"catch: "<<s<<endl;
//    }


    string s = "asd";
    vector<string> vs;
    vs.push_back(string(1, s[0]));
    cout<<vs[0]<<endl;


    using ti = tuple<int, int, int>;
    priority_queue<ti, vector<ti>, greater<>> pq;
    pq.emplace(1,5,1123);
    cout<<std::get<2>(pq.top())<<endl;
    auto [t1,t2,_] = pq.top();              // _ 是变量名字，不能重复，  []中变量个数要等于声明的tuple的元素个数。
                                    // 类型必须auto。 反正用int 不行。说 structured binding declaration cannot have type 'int'
    cout<<t1<<", "<<t2<<", "<<_<<endl;

    int arr[2][2] = {{1,2},{3,4}};
    auto& [x,y] = arr[1];
    cout<<x<<", "<<y<<endl;


//    long long dp[steps+1][max_pos+1];
//    memset(dp, 0, sizeof(dp));            // 设置每个 byte 的值。

//        int dp[n+1][d+1];
//        fill_n(&dp[0][0],(n+1)*(d+1),1e9);


    cout<<std::numeric_limits<int>::max()<<endl;


    int mod(1e9+7);
    cout<<mod<<endl;
//    int mod2{1e9 + 7};            // connot convert double to int...
//    cout<<mod2<<endl;


    cout<<__builtin_popcount(7)<<endl;          // sum(every bit)

//return vector<int>(arr.begin() + l + 1, arr.begin() + r);

//            std::partial_sort()       // 数组的开始，最后一个有序的位置，数组的结束。


//int m = nums.size(), n = nums[0].size(), o = m * n;


// cnt is a map.
//for (auto [_, freq] : cnt) frequencies.push_back(freq);



// *2, /2,  <<1, >>1  消耗


//    int memo[27][27][301] = {[0 ... 26][0 ... 26][0 ... 300] = -1};
//    cout<<memo[22][22][33]<<endl;
    MyClass mc;
    mc.myPrint();


//    fill(&dp[0][0][0],&dp[0][0][0]+(n+1)*27*27,INT_MAX) ;


//vvi.emplace_back((vector<int>){startTime[i], endTime[i], profit[i]});


//    iota(begin(idx), end(idx), 0);
//    sort(begin(idx), end(idx), [&](int i, int j) { return startTime[i] > startTime[j]; });
// [0,1,2,3...n] 代表下标，然后借助数组，排序。  这样经过idx转换后的 下标 就是 有序情况下的下标



//    auto fun = [&matrix](const pair<int, int>& p1, const pair<int, int>& p2){ return matrix[p1.first][p1.second] > matrix[p2.first][p2.second]; };
//    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(fun)> que1(fun);


//        int maxSum[n][n];
//        memset(maxSum,0,sizeof maxSum);


//res.erase(it) always returns the next valid iterator, if you erase the last element it will point to .end()
// while (it != res.end()) {
//        it = res.erase(it);
// }

//for ( ; it != res.end(); ) {
//  if (condition) {
//    it = res.erase(it);
//  } else {
//    ++it;
//  }
//}

//for( ; it != res.end();)
//{
//    it = res.erase(it);
//}


//        return all_of(begin(char_count), end(char_count),
//                      [&](int c) { return c % words.size() == 0; });


// LT 1897
//    vector<string> vs = {"abc", "aaa", "bbb"};
//    vector<int> arr(123, 0);
//    myvi v2 = std::accumulate(begin(vs[0]), end(vs[0]), arr, [](vector<int>& arr, char& ch){          // 前面是 和， 后面是 元素。。。
//                        cout<<ch<<", "<<", "<<arr.size()<<endl;
//                        arr[0] = 222;
//                        arr[1] = 432;
//                        return arr;
//                    });
//    cout<<arr[0]<<", "<<arr[1]<<endl;           // 0.0 ....  初始值不会被修改。
//    cout<<v2[0]<<", "<<v2[1]<<endl;
//
//    myvi v3 = std::accumulate(begin(vs), end(vs), arr, [](vector<int>& arr, string& s){
//                                    return std::accumulate(begin(s), end(s), arr, [](vector<int>& arr, char& ch){
//                                                                arr[ch]++;
//                                                                return arr;
//                                                           });
//                              });
//    for (int i = 'a'; i <= 'c'; ++i)
//    {
//        cout<<v3[i]<<endl;
//    }


// vector<int> 的 == , 是比较元素的。


// ==  优先级 高于  位运算，逻辑运算，  (乘 / 除 / + / >> / ^ /......)后赋值



// partial_sort 是 heap 来完成的。
    myvi v2 = {7,6,5,4,3,2,1};
    std::partial_sort(begin(v2), begin(v2) + 2, end(v2));
    showVectorInt(v2);
    // 是 第一个参数 到 第三个参数 之间的范围，有序后， 放到 第一个到 第二个参数 之间。 所以 后n个不可能。。除非 自定义方法，然后 降序。
    std::partial_sort(begin(v2), begin(v2) + 2, end(v2), [](const int a, const int b){
                        return a > b;
                      });
    showVectorInt(v2);


//vector<vector<int>> vvi = grid;             // copy or reference ?  it is copy .... & ref
// vector<vector<int>>& vvi = grid;



// not std::
//__builtin_ffs(x)          // sz1 - last 1's index
//__builtin_clz(x)          // prefix 0's count
//__builtin_ctz(x)          // suffix 0's count
//__builtin_popcount(x)     // 1's count
//__builtin_parity(x)       // 1's count % 2 == 1(or 0)
//这些函数都有相应的usigned long和usigned long版本，只需要在函数名后面加上l或ll就可以了，比如int __builtin_clzll。



//int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;


// 1947
//inner_product(begin(s[i]), end(s[i]), begin(m[j]), 0, plus<int>(), equal_to<int>())


// 827 daily
//      if (g[i][j] == 0) {
//        unordered_set<int> s = { get(i + 1, j, g), get(i - 1, j, g), get(i, j + 1, g), get(i, j - 1, g) };
//        res = max(res, 1 + accumulate(begin(s), end(s), 0, [&](int a, int b) {return a + sizes[b]; }));
//      }


// 1964 discuss 最长单调递增序列。


//https://en.cppreference.com/w/cpp/thread
// sem_wait
// condition_variable


//The __builtin_popcount() function is for g++ only. For C++20 use popcount(). For other compilers use bitset<26>().count().


//clock_t clock(void);
//CLOCKS_PRE_SEC


//http://www.cs.yale.edu/homes/aspnes/classes/223/notes.html


// partial_sum


// 转换复数
//        sscanf(x.c_str(), "%d+%di", &a, &b);

//        char buff;
//        stringstream aa(a), bb(b), ans;
//        aa >> ra >> buff >> ia >> buff;


//        istringstream in(preorder);
//        vector<string> v;
//        string t = "";
//        int cnt = 0;
//        while (getline(in, t, ',')) v.push_back(t);


// nth_element

// std::sort requires that if comp(a,b)==true, comp(b,a)==false
//https://en.cppreference.com/w/cpp/named_req/Compare
//    For all a, comp(a,a)==false
//    If comp(a,b)==true then comp(b,a)==false
//    if comp(a,b)==true and comp(b,c)==true then comp(a,c)==true
// comp: 第一个参数 是否 大于 第二个参数。     a>a 是false。   主要是 最终返回的 默认值 需要是 false(走到最后的 都是相等的情况，相等的时候 是false。)。


// std::set is typically implemented as a binary search tree(RB tree in GCC 4.8).
// It costs O(nlogn) to construct.
// While std::unordered_set uses hash table, O(n) is expected. That's why @oynasun observes unordered_set is faster.


// LT283
// fill(remove(nums.begin(), nums.end(),0), nums.end(), 0);
// std::stable_partition(nums.begin(), nums.end(), [](int n){return n!=0;});



//nums.erase(unique(begin(nums), end(nums)), end(nums));
// unique返回 A ForwardIt to the new end of the range.
// erase：Removes the elements in the range [first, last).


//    string s1 = "1234";
//    string s2 = s1;
//    cout<<&s1<<", "<<&s2<<endl;         // 2 location
////    string s3 =
//    reverse(begin(s1), end(s1));
//    cout<<s1<<", "<<s2<<endl;       // 4321 1234



//    for (auto &[prefix, cnt] : map2) {


//auto [it1, it2] = minmax_element(begin(n), end(n));
//    int smaller = count_if(begin(nums), end(nums), [&](int n){ return n < target; });
//    int equal = count(begin(nums), end(nums), target);


//int *dp = new int[prices.size()];




//const auto mm = minmax_element(begin(n), end(n));


//stable_partition(stable_partition(begin(n), end(n), [&](int n){ return n < p; }), end(n), [&](int n){ return n == p; });


//copy_if(begin(n), end(n), back_inserter(res), [&](int n){ return n > p; });

//            rightset.erase(nums[i + sz1]);              // Removes all elements with the key equivalent to key.


// LT2185
//    return count_if(begin(ws), end(ws), [&](const string &w){
//       return w.compare(0, pref.size(), pref) == 0;
//    });
//
//    return count_if(begin(ws), end(ws), [&](const string &w){
//       return w.starts_with(pref);
//    });
//
//return (int)Stream.of(words).filter(w -> w.startsWith(pref)).count();     // java


//stable_sort



// stoi(string )        stol        stoll
// to_string

// atoi(char* )


//vector<int>& vi = vv[1][1];
//vi = vv[1][2];              // 这步是将 [1][2] 赋值给 [1][1]， 不是 让 vi re-ref [1][2]

// LT2245
//array<int, 2> operator+(const array<int, 2> &l, const array<int, 2> &r) { return { l[0] + r[0], l[1] + r[1] }; }
//array<int, 2> operator-(const array<int, 2> &l, const array<int, 2> &r) { return { l[0] - r[0], l[1] - r[1] }; }
//int pairs(const array<int, 2> &p) { return min(p[0], p[1]); }
//
//class Solution {
//public:
//int factors(int i, int f) {
//    return i % f ? 0 : 1 + factors(i / f, f);
//}
//int maxTrailingZeros(vector<vector<int>>& grid) {
//    int m = grid.size(), n = grid[0].size(), res = 0;
//    vector<vector<array<int, 2>>> h(m, vector<array<int, 2>>(n + 1)), v(m + 1, vector<array<int, 2>>(n));
//    for (int i = 0; i < m; ++i)
//        for (int j = 0; j < n; ++j) {
//            array<int, 2> f25 = { factors(grid[i][j], 2), factors(grid[i][j], 5) };
//            v[i + 1][j] = v[i][j] + f25;
//            h[i][j + 1] = h[i][j] + f25;
//        }
//    for (int i = 0; i < m; ++i)
//        for (int j = 0; j < n; ++j) {
//            auto v1 = v[i + 1][j], v2 = v[m][j] - v[i][j];
//            auto h1 = h[i][j], h2 = h[i][n] - h[i][j + 1];
//            res = max({res, pairs(v1 + h1), pairs(v1 + h2), pairs(v2 + h1), pairs(v2 + h2)});
//        }
//    return res;
//}
//};


//        unordered_set<int> set3 = getall4test(circles);
//        cout<<set2.size()<<", "<<set3.size()<<endl;
//        vector<int> diff;
//        set<int> set21(begin(set2), end(set2));
//        set<int> set31(begin(set3), end(set3));
////        std::set_difference(begin(set21), end(set21), begin(set31), end(set31), std::inserter(diff, begin(diff)));        // ok
////        std::set_difference(begin(set21), end(set21), begin(set31), end(set31), begin(diff));         // error
//        std::set_difference(begin(set21), end(set21), begin(set31), end(set31), std::back_inserter(diff));      // ok
//        cout<<diff.size()<<endl;
//        showVectorInt(diff);


//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//
//#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>



//        int n(size(nums)), minAverageDifference(INT_MAX), index;
//        long long sumFromFront(0), sumFromEnd(0);


//    vector<long long> ps{0};
//    for (int n : nums)
//        ps.push_back(n + ps.back());



//    string s = "asd";
//    unordered_map<string, int> map2;
//    map2[s] = 1;
//    s.push_back('a');
//    map2[s] = 2;
//
//    for (auto& p : map2)
//    {
//        cout<<p.first<<", "<<p.second<<endl;        // asd:1   asda:2
//    }




//    int cnt[201] = {}, hash[201] = {}, res = 0;
//    for (int sz = 0; sz < nums.size(); ++sz) {
//        unordered_map<int, vector<int>> s;
//        auto collision = [&](const auto &ids, int i) {
//            for (int j : ids)
//                if (equal(begin(nums) + i, begin(nums) + i + sz + 1, begin(nums) + j))
//                    return true;
//            return false;
//        };
//        for (int i = 0; i + sz < nums.size(); ++i) {
//            cnt[i] += nums[i + sz] % p == 0;
//            if (cnt[i] <= k) {
//                hash[i] = ((long long)hash[i] * 200 + nums[i + sz]) % 1000000007;
//                if (!collision(s[hash[i]], i)) {
//                    s[hash[i]].push_back(i);
//                    ++res;
//                }
//            }
//        }
//    }
//    return res;
// Rolling Hash (Collision Check)
// https://leetcode.com/problems/k-divisible-elements-subarrays/discuss/1996294/O(n-2)%3A-Rabin-Karp-vs.-Trie
// Rabin-Karp






//    // <isBST, min, max, sum>
//    std::tuple<bool, int, int, int> dfsa1(TreeNode* node, int& ans)
//
//            bool b2;
//            int mn;
//            int mx;
//            int sum2;
//            std::tie(b2, mn, mx, sum2) = dfsa1(node->left, ans);
//
//            tuple<bool, int, int, int> t2 = dfsa1(node->right, ans);
//            bool b2 = std::get<bool>(t2);
//            int mn = std::get<1>(t2);
//            int mx = std::get<2>(t2);
//            int sum2 = std::get<3>(t2);


//    array<int, 3> dfs(TreeNode* n) {
//        auto l = n->left ? dfs(n->left) : array<int, 3>{0, n->val, n->val - 1};



//    struct BSTNode{
//        int mn;
//        int mx;
//        int sum;
//        bool isBST;
//    };
//    BSTNode findBST(TreeNode* root,int &res){
//        if(!root){
//            return {INT_MAX,INT_MIN,0,true};
//        }



// 都可以，都是传递数组 int arr[10001] = {};
//    int dfsc1(TreeNode* node, int* arr, int depth)
//    int dfsc1(TreeNode* node, int (&arr)[10001], int depth)


//    transform(begin(c), end(c), begin(r), begin(c), [](int c, int r){ return c - r; });
// 数组按位相减





// LT2288
    //stringstream ss2;
    //double discountPercentage = (100 - discount) / 100.0;
    //ss2 << fixed << setprecision(2) << (discountPercentage * price);
    //return "$" + ss2.str();

//        long long t2 = strtoll(vs[i].substr(1).c_str(), nullptr, 10);
//        t2 *= (100 - discount);
//        string ns = std::to_string(t2);


//        std::ostringstream oss;
//        std::copy(begin(vs), end(vs) - 1, std::ostream_iterator<string>(oss, " "));
//        oss << vs.back();
//        string ans = oss.str();


//        istringstream iss(sentence);
//        vector<string> vs;
//        string t;
//        while (getline(iss, t, ' '))
//            vs.push_back(t);

/*
class NumMatrix {
    vector<vector<int>> vvi;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();
        vvi = vector<vector<int>>(sz1, vector<int>(sz2, 0));
        //cout << vvi.size() << ", " << vvi[0].size() << endl;
*/




// daily - 2022-6-4 - LT0051-N-Queues
//                vector<vector<bool>> v(begin(vvb), end(vvb));
                //std::copy(begin(vvb), end(vvb), std::back_inserter(v));
//                cout << &v[0] << ", " << &vvb[0] << endl;     // 2种都是不同地址。 都是150ms左右。。copy的内存消耗大30% (27mb vs 39mb)。




// std::prev(it, distance) 内部使用了    std::advance(it, -n);




//https://leetcode.com/problems/short-encoding-of-words/discuss/125811/C%2B%2BJavaPython-Easy-Understood-Solution-with-Explanation
// 中的回复
// You can use string_view to get an O(1) substr.
//        unordered_set<string_view> S(words.begin(), words.end());
//        for (auto& w : words) {
//            string_view sv(w);
//            for (int i = 1; i < w.size(); i++) S.erase(sv.substr(i));
//        }
//        return accumulate(S.begin(), S.end(), 0, [](int total, const string_view& w){ return total + w.size() + 1; });


//string_view::substr()的返回值类型是string_view，不产生新的字符串，不会进行内存分配。





//LT1473
// .. 我写 dfs+memo 的时候，他们写 bottom-up,  我写bottom-up 的时候，他们写 top-down...

// 感觉是 稀疏矩阵，或者 稠密矩阵的区别。 这道题目，它应该很稀疏，毕竟 如果 houses已经刷漆，那么可以砍掉很多分支，还有neighour的数量也可以剔除很多分支。 所以是稀疏的。
//      不像 其它的dp， for for 全部走一遍，需要遍历全部分支。




// LT0975
// 对数组每个元素，找后续比这个元素大的 且 最小的， 找比这个元素小的 且最大的。。用for(n..1) {map.lower_bound()}





//LT1631
    //Using BFS is actually an improvement of Bellman - Ford, called Shortest Path Faster Algorithm, https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
    //SPFA removes the unnecessary edge relaxations, thus reducing the time complexity, but worst case still the same as Bellman - Ford.




//sort(nums.begin(), nums.end(), greater<int>());
//sort(nums.rbegin(), nums.rend());




//LT1589
    //vector<int> cnt(nums.size());
    //for (auto& r : requests) {
    //    cnt[r[0]] += 1;
    //    if (r[1] + 1 < nums.size())
    //        cnt[r[1] + 1] -= 1;
    //}
    //partial_sum(begin(cnt), end(cnt), begin(cnt));
    //sort(begin(nums), end(nums));
    //sort(begin(cnt), end(cnt));
    //return inner_product(begin(nums), end(nums), begin(cnt), 0,
    //    [](int res, long long m) { return (res + m) % 1000000007; }, multiplies<long long>());






//long long t2 = std::atoll(s.c_str());
//long long t2 = std::stoll(s);






    //unordered_map<int, int> counter;
    //for (int i = 0; i < n; i++) {
    //    for (int j = i; j < n; j++) {
    //        counter = { {0,1} };




// Psacal
    //vector<vector<int>> r(numRows);

    //for (int i = 0; i < numRows; i++) {
    //    r[i].resize(i + 1);
    //    r[i][0] = r[i][i] = 1;

    //    for (int j = 1; j < i; j++)
    //        r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    //}




    //vector<int> res = { 1, 0 };
    //for (int i : initial)
    //    res = min(res, { (malware[find(i)] == 1) * (-area[find(i)]), i });





//LT1178
// tmp = val
// tmp = (tmp - 1) & val        // 获得所有的 排列 (随机删除x个1的，x是0-bitCount)

// tmp = (tmp - 1) & tmp        // 获得所有的 1 的个数




    //auto val = [&](int i) { return s[i] - '`'; };
    //for (int i = s.size() - 1; i >= 0; --i) {
    //    hash = (hash * power + val(i)) % mod;






cout << sizeof(long) << " vs. " << sizeof(long long) << endl;

// long is 4 bits in the Microsoft's compiler. It could make sense to use more specific types, like int64_t











//        vector<int> x;
//        for (auto r : rectangles) {
//            x.push_back(r[0]);
//            x.push_back(r[2]);
//        }
//        sort(x.begin(), x.end());
//        vector<int>::iterator end_unique = unique(x.begin(), x.end());
//        x.erase(end_unique, x.end());




    //tmp = counter(a);
    //for (i = 0; i < 26; ++i)
    //    if (tmp[i] < count[i])
    //        break;
    //if (i == 26) res.push_back(a);
// no goto



    //struct pairHash {
    //    size_t operator()(const pair<int, int>& x) const { return x.first ^ x.second; }
    //};
    
    //    unordered_set<pair<int, int>, pairHash> ls;
// 自定义hash





    //auto comp = [&](auto& a, auto& b)
    //{
    //    return a[2] > b[2];
    //};
    //priority_queue<node, vector<node>, decltype(comp)> pq(comp);
















































// Kadane



// Fenwick


// Segment

// Binary Indexed Tree



// KMP


// Rabin-Karp   2个人的名字。


//Fisher-Yates Algorithm and Knuth Shuffle


// flood-fill


// sweep line


// Manacher  最长回文 O(n)


// LT1334
//Floyd: 14ms
//Dijkstra: 32ms
//SPFA: 64ms
//Bellman: 251ms

// Prim, Kruskal


//Hierholzer’s algorithm

//Kahn's algo


// 凸包
// Graham Scan
// Andrew’s Monotone Chain
// Jarvis March

//Sprague-Grundy theorem


// Tarjan 计算 割边
//LT1192.. 代码在 daily_challenge, 2022-5-18
/*

https://www.cnblogs.com/nullzx/p/7968110.html

假设DFS中我们从顶点U访问到了顶点V（此时顶点V还未被访问过），那么我们称顶点U为顶点V的父顶点，V为U的孩子顶点。
在顶点U之前被访问过的顶点，我们就称之为U的祖先顶点。

显然如果顶点U的所有孩子顶点可以不通过父顶点U而访问到U的祖先顶点，那么说明此时去掉顶点U不影响图的连通性，U就不是割点。
相反，如果顶点U至少存在一个孩子顶点，必须通过父顶点U才能访问到U的祖先顶点，那么去掉顶点U后，顶点U的祖先顶点和孩子顶点就不连通了，说明U是一个割点。


割点：判断顶点U是否为割点，用U顶点的dfn值和它的所有的孩子顶点的low值进行比较，
如果存在至少一个孩子顶点V满足low[v] >= dfn[u]，就说明顶点V访问顶点U的祖先顶点，必须通过顶点U，
而不存在顶点V到顶点U祖先顶点的其它路径，所以顶点U就是一个割点。对于没有孩子顶点的顶点，显然不会是割点。

桥（割边）：low[v] > dfn[u] 就说明V-U是桥

*/
// 看起来是： dfn[] 就是第一次访问这个 结点是的 时间序号。
// low[]，初始值 是dfn， 然后遍历 子结点后， 子结点会返回 它所遇到的最小序号。 然后更新本结点的low，然后返回本结点的low
// 然后 遍历边，如果出现 low[x] > dfn[y] , 那么就是桥。

// 因为 割边 的 对立 应该(可能) 是 环。。 环是 肯定没有 割边的， 所以 low 就是 找环。






// LT1483
// binary lifting
//
// Jump array is a logarithmic data structure. For each node, it stores 1st, 2nd, 4th, 8th and so on ancestors.
//
// sparse table






// suffix array

// LCP array





//Morris Traversal



//AKS素数测试








//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/discuss/777019/Python-Clear-explanation-Powerful-Ultimate-Binary-Search-Template.-Solved-many-problems.
//def binary_search(array) -> int:
//    def condition(value) -> bool:
//        pass
//
//    left, right = 0, len(array)
//    while left < right:
//        mid = left + (right - left) // 2
//        if condition(mid):
//            right = mid
//        else:
//            left = mid + 1
//    return left

















}

