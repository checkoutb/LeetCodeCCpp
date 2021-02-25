
#include "../header/myheader.h"

class LT0962
{
public:

// D


//        List<Integer> s = new ArrayList<>();
//        int res = 0, n = A.length;
//        for (int i = 0; i < n; ++i) {
//            if (s.size() == 0 || A[i] < A[s.get(s.size() - 1)]) {
//                s.add(i);
//            } else {
//                int left = 0, right = s.size() - 1, mid = 0;
//                while (left < right) {
//                    mid = (left + right) / 2;
//                    if (A[s.get(mid)] > A[i]) {
//                        left = mid + 1;
//                    } else {
//                        right = mid;
//                    }
//                }
//                res = Math.max(res, i - s.get(left));
//            }
//        }
//        return res;
// . ...   1 3 3 3 2 ,  3不会进入 s 的。   只记录 值小于A[0]的 下表。 并且标准越来越小。  来降低 二分的消耗。


    int lt0962a(vector<int>& A)
    {

    }

};

int main()
{

    LT0962 lt;


    return 0;
}
