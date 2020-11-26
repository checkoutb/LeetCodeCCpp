
#include "../header/myheader.h"

class LT1471
{
public:

// D D

// nth_element ， 是执行一半的  快速排序，来快速获得 第x个元素。  返回void
//		std::nth_element(arr.begin(), arr.begin() + (n - 1) / 2, arr.end());
//		int median = arr[(n - 1) / 2];
//		std::nth_element(arr.begin(), arr.begin() + k, arr.end(), [&median](int a, int b) {
//			if (abs(a - median) != abs(b - median)) return abs(a - median) > abs(b - median);
//			return a > b;
//		});
//		for (int i = 0; i < k; i++) ans.push_back(arr[i]);
// 而且影响数组，所以 找到 第K个时， 说明 前面的 都是 >= k的，


//    nth_element(begin(arr), begin(arr) + (arr.size() - 1) / 2, end(arr));
//    int m = arr[(arr.size() -1) / 2];
//    partial_sort(begin(arr), begin(arr) + k, end(arr), [&](int a, int b) {
//        return abs(a - m) == abs(b - m) ? a > b : abs(a - m) > abs(b - m);
//    });
//    arr.resize(k);
//    return arr;
// 。。 partial_sort




// 第二个sort 不必， 可以双指针 指向头 尾。  最大值 必然在 头尾
//Runtime: 952 ms, faster than 24.37% of C++ online submissions for The k Strongest Values in an Array.
//Memory Usage: 80.9 MB, less than 81.72% of C++ online submissions for The k Strongest Values in an Array.
    vector<int> lt1471a(vector<int>& arr, int k)
    {
        sort(begin(arr), end(arr));
        int med = arr[(arr.size() - 1) / 2];
        sort(begin(arr), end(arr), [&med](const int& a, const int& b) { return abs(a-med) == abs(b-med) ? a > b : abs(a - med) > abs(b - med); });
        #ifdef __test
        showVectorInt(arr);
        #endif // __test
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }

};

int main()
{
//    vector<int> v = {1,2,3,4,5};
//    vector<int> v = {1,1,3,5,5};
//    vector<int> v = {6,7,11,7,6,8};
    vector<int> v = {6,-3,7,2,11};

    std::nth_element(begin(v), begin(v) + 2, end(v));
    showVectorInt(v);

    int k{2};

    LT1471 lt;

    vector<int> ans = lt.lt1471a(v,k);
    showVectorInt(ans);
//    vector<int>

    return 0;
}
