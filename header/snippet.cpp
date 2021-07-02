
#include "myheader.h"
#include <iomanip>

int main()
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > q;

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
//    memset(dp, 0, sizeof(dp));

    int mod(1e9+7);
    cout<<mod<<endl;
//    int mod2{1e9 + 7};            // connot convert double to int...
//    cout<<mod2<<endl;


    cout<<__builtin_popcount(7)<<endl;          // sum(every bit)

//return vector<int>(arr.begin() + l + 1, arr.begin() + r);


}
