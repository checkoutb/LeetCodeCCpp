
#include "../header/myheader.h"

class LT2206
{
public:

// D D

//    return all_of(begin(cnt), end(cnt), [](int cnt){ return cnt % 2 == 0; });

//        sort(begin(A), end(A));
//        for (int i = 0; i < A.size(); i += 2) {
//            if (A[i] != A[i + 1]) return false;
//        }

//        return IntStream.of(cnt).allMatch(n -> n % 2 == 0);


//        boolean[] odd = new boolean[501];
//        for (int n : nums)
//            odd[n] = !odd[n];
//        return Arrays.equals(odd, new boolean[501]);



//Runtime: 13 ms, faster than 76.92% of C++ online submissions for Divide Array Into Equal Pairs.
//Memory Usage: 13.2 MB, less than 30.77% of C++ online submissions for Divide Array Into Equal Pairs.
//Runtime: 26 ms, faster than 46.15% of C++ online submissions for Divide Array Into Equal Pairs.
//Memory Usage: 13.1 MB, less than 30.77% of C++ online submissions for Divide Array Into Equal Pairs.
//Runtime: 29 ms, faster than 38.46% of C++ online submissions for Divide Array Into Equal Pairs.
//Memory Usage: 13.1 MB, less than 30.77% of C++ online submissions for Divide Array Into Equal Pairs.
    bool lt2206a(vector<int>& nums)
    {
        int arr[501] = {0};
        for (int i : nums)
            arr[i]++;

        return std::none_of(begin(arr), end(arr), [](int ele){ return ele % 2; });

////        int t2 = accumulate(begin(arr), end(arr), 0, [](int sum2, int ele){ return sum2 + (ele % 2); });
//        int t2 = std::count_if(begin(arr), end(arr), [](int ele){ return ele % 2; });
//        return t2 == 0;
    }

};

int main()
{

    LT2206 lt;


    return 0;
}
