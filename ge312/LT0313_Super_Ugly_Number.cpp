
#include "../header/myheader.h"

#include <climits>
#include <stdlib.h>

#define test

using namespace std;


// timeout
// 需要一个定容量，元素唯一，有序，易插入 的 数据结构

class LT0313
{

    static priority_queue<int, vector<int>, greater<int>> priQue;   // 需要在外部初始化。
//    static priority_queue<int, vector<int>, greater<int>> priQue2;
    static vector<int>& pri;
    initPriQue(int n, vector<int>& primes)
    {
//        priQue = priority_queue<int, vector<int>, greater<int>>();
//        priQue.push(1);
        int sz = primes.size();
        for (int i = 0; i < sz; i++)
        {
            priQue.push(primes[i]);
        }

        int nth = -1;
        int t1;
//        while (nth)
//        {
            t1 = priQue.top();
            priQue.pop();
            cout<<endl<<t1<<endl;
//            for (int i = 0; i < sz; i++)
//            {
//                priQue.
//            }
//        }

    }

public:
    int lt0313a(int n, vector<int>& primes) {
        int result = 0;
        initPriQue(n, primes);
//        for (int i = 0; i < n; i++)
//            result = nextNum()
        return result;
    }

    int lt0313b(int n, vector<int>& primes)
    {
        int result = 0;
        set<int> set1(primes.begin(), primes.end());
        int sz = primes.size();
        int nth1 = -1;
        int nth2 = -2;
        int first = primes[0];
        int count = 0;
        int last = -3;

        int cN = 100;

        while(nth1 != nth2)
        {
            int t1 = *set1.begin();
            for (int i = 0; i < sz; i++)
            {
                set1.insert(t1 * primes[i]);
            }
            count++;
            if (t1 == first)
            {
                count = 0;
            }
            if (count == n)
            {
                nth2 = nth1;
                nth1 = last;
            }
            last = t1;

            if (last > 100)
                break;
            if (set1.size() > 50)
                break;
            cN++;
            if (cN > 100)
                break;
        }

        for (set<int>::iterator iter = set1.begin(); iter != set1.end(); iter++)
            cout<<*iter<<", ";

        set<int>::iterator iter = set1.begin();
        for (int i = 0; i < n; i++)
        {
            iter++;
        }
        result = *iter;
        return result;
    }

    // timeout..本地都跑不完
    int lt0313c(int n, vector<int>& primes)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return primes[0];

        int sz = primes.size();
        set<int> set1(primes.begin(), primes.end());
        set<int> set2;
        set<int>::iterator iter2;


//        for (iter2 = set1.begin(); iter2 != set1.end(); iter2++)
//        {
//            cout<<*iter2<<", ";
//        }

//        iter2 = set1.begin();
//        cout<<*iter2<<endl;
//        cout<<*set1.begin()<<endl;
//
//        set<int>::reverse_iterator iter11 = set1.rbegin();
//        cout<<*iter11<<endl;
//        cout<<*set1.rbegin()<<endl;

//        int intMax = 1 << 31;
//        intMax--;
////        cout<<intMax<<endl;

//        cout<<">>>...??.."<<numeric_limits<int>::max()<<endl;
//        cout<<INT_MAX<<endl;

        int nth1 = -1;
        int set1sz = -1;                // ..
//        int nth2 = -2;
        while(nth1 != *set1.rbegin() || set1sz != set1.size())
        {
//            cout<<nth1<<"..."<<*set1.end()<<"...."<<endl;
//            for (iter2 = set1.begin(); iter2 != set1.end(); iter2++)
//            {
//                cout<<*iter2<<", ";
//            }
//            cout<<endl;
//            cout<<nth1<<".,.,."<<*set1.rbegin()<<endl;


            set2.clear();
            nth1 = *set1.rbegin();
            set1sz = set1.size();
            for (set<int>::iterator iter = set1.begin(); iter != set1.end(); iter++)
            {
                int t1 = *iter;
                for (int i = 0; i < sz; i++)
                {
                    long tl2 = (long) t1 * primes[i];
                    if (tl2 <= INT_MAX)
                        set2.insert((int) tl2);
                }
            }
            for (iter2 = set2.begin(); iter2 != set2.end(); iter2++)
            {
                set1.insert(*iter2);
            }
            set2.clear();
            int i2 = 0;
            for (iter2 = set1.begin(); iter2 != set1.end() && i2 < n - 1; iter2++, i2++)
            {
                set2.insert(*iter2);
            }
//            set1.clear();
            set1 = set2;

//            for (iter2 = set1.begin(); iter2 != set1.end(); iter2++)
//            {
//                cout<<*iter2<<", ";
//            }
//            system("PAUSE");

        }

//        for (iter2 = set1.begin(); iter2 != set1.end(); iter2++)
//        {
//            cout<<*iter2<<", ";
//        }
        int result = *set1.rbegin();

//        cout<<result<<endl;

        return result;
    }



//Runtime: 36 ms, faster than 95.83% of C++ online submissions for Super Ugly Number.
//Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Super Ugly Number.
// 看了discuss的。。。主要是需要一个数组来保存因子的下一个乘数。
// 并且由于丑数的确认是按递增顺序的，所以可以直接保存下标。

    int lt0313d(int n, vector<int>& primes)
    {
        int prisz = primes.size();
        int arr1[n] = {1};
        int arr2[prisz] = {0};
//        set<int> set2;

        for (int i = 1; i < n; i++)
        {
            int min = primes[0] * arr1[arr2[0]];
            int minIndex = 0;
            int t1 = 0;
            for (int j = 1; j < prisz; j++)
            {
                t1 = primes[j] * arr1[arr2[j]];
                if (t1 < min)
                {
                    min = t1;
//                    set2.clear();
//                    set2.insert(j);
                    minIndex = j;
                }
                else if (t1 == min)
                {
//                    set2.insert(j);
                    arr2[j]++;              // 等于min，意味着之前出现过min，所以这个可以直接后移了。之前出现的min可以再次得到就可以了。
                }
            }
            arr1[i] = min;
            arr2[minIndex]++;
        }

        return arr1[n - 1];
    }

};

priority_queue<int, vector<int>, greater<int>> LT0313::priQue;


void fun_cout(int i)
{
    cout<<i<<",";
}

int main()
{
//    int n = 12;
//    int arr1[] = {2, 7, 13, 19};

//    int n = 1;
//    int arr1[] = {2,3,5};


//    int n = 100000;
//    int arr1[] = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};

//    int n = 65;
//    int arr1[] = {3,5,7,11,13,19,31,37,41,43,53,59,71,73,97,101,107,109,113,151,167,179,191,197,223,233,239,251,257,263};


    int n = 100000;
    int arr1[] = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};


    int len = sizeof(arr1) / sizeof(arr1[0]);

    vector<int> v (arr1, arr1 + len);
    LT0313 lt = LT0313();
    int result = lt.lt0313d(n, v);

    LT0313 lt2;     // 无参不能有()
//    lt2.lt0313a(n, v);

    LT0313 *lt3 = new LT0313();
//    lt3->lt0313a(n,v);
    cout<<endl<<result<<endl;


    cout<<endl<<endl;

    set<int> set1;
    set1.insert(1);
    set1.insert(1);
    set1.insert(10);
    set1.insert(5);
    set1.insert(10);
//    for_each(set1.begin(), set1.end(), fun_cout);

    set<int> set2(v.begin(), v.end());
//    for_each(set2.begin(), set2.end(), fun_cout);

    return 0;
}
