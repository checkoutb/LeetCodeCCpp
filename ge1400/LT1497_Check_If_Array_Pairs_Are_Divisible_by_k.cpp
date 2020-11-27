
#include "../header/myheader.h"

class LT1497
{
public:

// D D

//        vector<int> rem(k);
//        int l = 1, r = k - 1;
//        while (l < r) {
//            if (rem[l++] != rem[r--]) {
//                return false;
//            }
//        }

//        for (int i=1, j=k-1; i<j; i++, j--)
//            if (freq[i] != freq[j])
//                return false;


// 不知道为什么这么慢，
// 用 vector ，200ms
// unordered_map, 330ms
// 500左右，是 map， 有些外加 cout。。。


//        long long res = 0;
//        for(int x:arr) res +=x;
//        return (res % k == 0);  // if the sum of all elements is divisible by k then all pairs exists
// .  感觉不对吧   k=7  {7, 1,2,4} 。。。 due to weak test case ...



// 错了。。。 不能 erase(0) 的。 k的倍数是 奇数个，，，   不， 也没有问题，因为 当 k的倍数为奇数个的时候， 必然 多出一个数了， 这个数会导致 后续 return false
//Runtime: 516 ms, faster than 10.34% of C++ online submissions for Check If Array Pairs Are Divisible by k.
//Memory Usage: 70.1 MB, less than 36.99% of C++ online submissions for Check If Array Pairs Are Divisible by k.
    bool lt1497a(vector<int>& arr, int k)
    {
        unordered_map<int, int> map2;           // mod : count
        for (int& i : arr)
            map2[(i % k + k) % k]++;
        map2.erase(0);
        if (k % 2 == 0 && map2.find(k / 2) != map2.end())
        {
            if (map2[k / 2] % 2 == 1)
                return false;
            map2.erase(k / 2);
        }
        int k2 = k / 2;
        for (unordered_map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            if (it->first > k2)
                continue;
            int need = k - it->first;
            if (it->second != map2[need])
                return false;
        }
        return true;
    }

//    bool dfsa1(vector<int>& arr, int cnt, int k)
//    {
//        if (cnt == arr.size())
//            return true;
//        for (int i = 0; i < arr.size(); ++i)
//        {
//            if (arr[i] = )
//            int val = arr[i];
//            arr[i] = INT_MAX;
//            for ()
//        }
//    }

};

int main()
{

//    myvi v = {1,2,3,4,5,10,6,7,8,9};
//    int k{5};

//    myvi v = {1,2,3,4,5,6};
////    int k{7};
//    int k{10};

//    cout<<(-8 % 3)<<endl;
//
//    myvi v = {-10,10};
//    int k{2};

    myvi v = {-1,1,-2,2,-3,3,-4,4};
    int k{3};

    LT1497 lt;

    cout<<lt.lt1497a(v, k);

    return 0;
}
