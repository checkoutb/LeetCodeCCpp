
#include "../header/myheader.h"

class LT1356
{
public:

// D D

//    static bool compare(int a,  int b){
//        int c1 = __builtin_popcount(a);
//        int c2 = __builtin_popcount(b);
//        if(c1 == c2)
//            return a < b;
//        return c1 < c2;
//    }


//        return Arrays.stream(arr)
//                     .boxed()
//                     .sorted(Comparator.comparingInt(i -> Integer.bitCount(i) * 10000 + i)).mapToInt(i -> i)
//                     .toArray();

//        return Arrays.stream(arr)
//                     .boxed()
//                     .sorted((i, j) -> Integer.bitCount(i) != Integer.bitCount(j) ? Integer.bitCount(i) - Integer.bitCount(j) : i - j)
//                     .mapToInt(i -> i)
//                     .toArray();


//return sorted(A, key=lambda a: [bin(a).count('1'), a])

//        sort(arr.begin(), arr.end(),[](const int& a, const int& b){
//            int countA = __builtin_popcount(a), countB = __builtin_popcount(b);
//            return countA==countB ? a<b:countA<countB;});



//Runtime: 56 ms, faster than 5.07% of C++ online submissions for Sort Integers by The Number of 1 Bits.
//Memory Usage: 11.8 MB, less than 6.18% of C++ online submissions for Sort Integers by The Number of 1 Bits.
// sort 改不改原来的顺序？ hui.
    vector<int> lt1356a(vector<int>& arr)
    {
        sort(begin(arr), end(arr));
//        #ifdef __test
//        showVectorInt(arr);
//        #endif // __test
        unordered_map<int, int> map2;
        for (int i = 0; i < arr.size(); ++i)
        {
            int t = arr[i];
            int cnt = 0;
            while (t > 0)
            {
                cnt += (t % 2);
                t >>= 1;
            }
            map2[arr[i]] = cnt;
        }

//        #ifdef __test
//        for (auto& p : map2)
//        {
//            cout<<p.first<<" : "<<p.second<<endl;
//        }
//        #endif // __test

        sort(begin(arr), end(arr), [&map2](int t1, int t2) { return map2[t1] == map2[t2] ? t1 < t2 : map2[t1] < map2[t2]; });
        return arr;
    }

};

int main()
{

//    vector<int> v = {0,1,2,3,4,5,6,7,8};
//    vector<int> v = {1024,512,256,128,64,32,16,8,4,2,1};
//    vector<int> v = {2,3,5,7,11,13,17,19};
    vector<int> v = {7850,8192,1878,2687,6878,7410,763,365,9869,8744,2741,4871,5844,2715,3335,9651,6677};


    LT1356 lt;

    vector<int> v2 = lt.lt1356a(v);

    showVectorInt(v2);

    return 0;
}
