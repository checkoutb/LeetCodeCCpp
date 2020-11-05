
#include "../header/myheader.h"

class LT1122
{
public:

// D D

//        k = {b: i for i, b in enumerate(B)}
//        return sorted(A, key=lambda a: k.get(a, 1000 + a))

//        return sorted(A, key=(B + sorted(A)).index)


// map, 是有序的， 所以 arr1 全部放到map， 先 遍历arr2，把map中arr2的 先放到ans，然后遍历 map，此时map中就是 不在arr2中的元素及它们的个数。

//int[] cnt = new int[1001];    代替map。 也是有序的。




//Runtime: 4 ms, faster than 90.19% of C++ online submissions for Relative Sort Array.
//Memory Usage: 8.4 MB, less than 99.01% of C++ online submissions for Relative Sort Array.
// bucket
    vector<int> lt1122a(vector<int>& arr1, vector<int>& arr2)
    {
        int i2 = arr1.size() - 1;
        unordered_set<int> set2(begin(arr2), end(arr2));
        unordered_map<int, int> map1;
        for (int i = 0; i <= i2; i++)
        {
            if (set2.find(arr1[i]) != set2.end())
            {
                map1[arr1[i]]++;
            }
            else
            {
                int t2 = arr1[i2];
                arr1[i2] = arr1[i];
                arr1[i] = t2;
                i--;
                i2--;
            }
        }
        int i3 = 0;
        for (int i = 0; i < arr2.size(); i++)
        {
            int cnt = map1[arr2[i]];
            while (cnt-- > 0)
            {
                arr1[i3++] = arr2[i];
            }
        }
        sort(begin(arr1) + i2 + 1, end(arr1));
        return arr1;
    }

};

int main()
{
    vector<int> v = {2,3,1,3,2,4,6,19,7,9,2,7,19,7,19,19};
    vector<int> v2 = {2,1,4,3,9,6,19};

    LT1122 lt;

    vector<int> ans = lt.lt1122a(v, v2);

    for_each(begin(ans), end(ans), fun_cout);

    return 0;
}
