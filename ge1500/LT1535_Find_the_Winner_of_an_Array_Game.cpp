
#include "../header/myheader.h"

class LT1535
{
public:

// D D

//        int cur = A[0], win = 0;
//        for (int i = 1; i < A.size(); ++i) {
//            if (A[i] > cur) {
//                cur = A[i];
//                win = 0;
//            }
//            if (++win == k) break;
//        }
//        return cur;


//        for (int i=1; i<n; i++) {
//            currentMax = max(currentMax, arr[i]); // Match.
//            matchesWon[currentMax]++;  // Increment the winner.
//            if (matchesWon[currentMax] >= k) { // Check the matches won so far.
//                return currentMax;
//            }
//        }
// .. 主要是 输了 要不要清空 ，好像不需要清空， distinct. 只遍历一遍。



//Runtime: 212 ms, faster than 49.89% of C++ online submissions for Find the Winner of an Array Game.
//Memory Usage: 63.4 MB, less than 63.40% of C++ online submissions for Find the Winner of an Array Game.
// bubble sort   k%sz1 .. bu  min , bu k>sz1 -> return max_element...
// sort后，  原arr中 第一次出现  后x (sz1-k) 个元素， 就ok？  不是。
// 还是回到 冒泡。。 所以只需要 一个指针 指向 冒泡到现在 最大的值 就可以了， 这个冒泡最多比较 k次。
// 环形数组，
    int lt1535a(vector<int>& arr, int k)
    {
        int sz1 = arr.size();
        k = min(sz1, k);
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < sz1; i++)
        {
            if (ans > arr[i])
            {
                cnt++;
            }
            else
            {
                ans = arr[i];
                cnt = min(i, 1);        // <=>  cnt = i==0 ? 0 : 1;    for when i==0,  it must route to else{  };        shibushi route?
            }
            if (cnt >= k)
                break;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {2,1,3,5,4,6,7};
//    int k{2};

//    myvi v = {3,2,1};
//    int k{10};

//    myvi v = {1,9,8,2,3,7,6,4,5};
//    int k{7};

    myvi v = {1,11,22,33,44,55,66,77,88,99};
    int k{111111};

    LT1535 lt;

    cout<<lt.lt1535a(v, k);

    return 0;
}
