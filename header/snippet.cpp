
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

int main()
{
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







// Kadane



// Fenwick


// Segment



// KMP


// Rabin-Karp   2个人的名字。




}

