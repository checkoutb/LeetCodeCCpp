
#include "../../header/myheader.h"

class LT
{
public:

// D D

//return vector<int>(arr.begin() + l + 1, arr.begin() + r);

//Collections.sort(sortedArr, (num1, num2) -> Math.abs(num1 - x) - Math.abs(num2 - x));

//        int left = 0, right = A.length - k;
//        while (left < right) {
//            int mid = (left + right) / 2;
//            if (x - A[mid] > A[mid + k] - x)
//                left = mid + 1;
//            else
//                right = mid;
//        }
//        return Arrays.stream(A, left, left + k).boxed().collect(Collectors.toList());
// 二分找最左面的。 因为k是已知的。


// AC
// ans need sorted..
// 已经有序，找到k个最接近x的，  如果相同距离，小的更接近。
    vector<int> lta(vector<int>& arr, int k, int x)
    {
        vector<int> vi(k);
        int viidx = 0;
        vector<int>::iterator it = std::lower_bound(begin(arr), end(arr), x);
        int p1 = std::distance(begin(arr), it);
        int p2 = p1 - 1;        // small
        while (viidx++ < k)
        {
            if (p2 < 0)
            {
//                vi[
//                viidx++;
//                ] = arr[
                p1++;
//                ];
            }
            else if (p1 >= arr.size())
            {
//                vi[
//                viidx++;
//                ] = arr[
                p2--;
//                ];
            }
            else
            {
                if ((x - arr[p2]) <= (arr[p1] - x))
                {
//                    vi[
//                    viidx++
//                    ] = arr[
                    p2--;
//                    ];
                }
                else
                {
//                    vi[
//                    viidx++
//                    ] = arr[
                    p1++;
//                    ];
                }
            }
        }
        p2++;
        for (int i = 0; i < k; ++i)
        {
            vi[i] = arr[i + p2];
        }
        return vi;
    }

};

int main()
{
    myvi v = {1,2,3,4,5};
//    int k(4), x{3};
    int k{4}, x(-1);

    LT lt;

    myvi vi = lt.lta(v,k,x);

    showVectorInt(vi);

    return 0;
}
