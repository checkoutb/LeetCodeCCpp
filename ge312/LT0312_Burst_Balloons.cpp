
#include "../header/myheader.h"


using namespace std;

// 今天才发觉，应该是LC，而不是LT，为了一致，还是继续LT吧。

//Runtime: 16 ms, faster than 99.21% of C++ online submissions for Burst Balloons.
//Memory Usage: 8.8 MB, less than 91.79% of C++ online submissions for Burst Balloons.

// 不过，是看了discuss后写的。自己写不出。

class LT0312 {
public:
    int lt0312a(vector<int>& nums) {
        int result = 0;
        nums.insert(nums.end(), 1);
        nums.insert(nums.begin(), 1);

//        cout<<"lt"<<endl;
//        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
//            cout<<*it<<",";
//        cout<<endl<<nums.size()<<endl;


        int len = nums.size();
        int arr1[len][len] = {{0}};     // 这个第0行除了第0个为0外，其他都是随机数，其他行都是0。0行不影响结果。

//        cout<<arr1[2][4]<<"aaaa"<<endl;

//        for (int i = 0; i < len; i++)
//        {
//            for (int j = 0; j < len; j++)
//            {
////                arr1[i][j] = 0;
//                cout<<arr1[i][j]<<"  ";
//            }
//            cout<<endl;
//        }

        for (int i = 1; i < len - 1; i++)           // 间距   i
        {
            for (int j = 1; j < len - i; j++)       // 起始   j
            {
                for (int k = j; k < j + i; k++)     // [起始，起始+间距]，[j, j + i - 1]
                {
                    // 计算的是 先扎 [起始，起始+间距] 的气球 的最大值，并且认为 []内剩下的最后一个气球是k
                    // 就变成了 起始-1 * k * 起始+间距+1 + 区间[起始，k)，(k, 起始+区间] 各自的最大值 作为 先扎 [] 的最大值。
                    int t1 = nums[j - 1] * nums[k] * nums[j + i] + arr1[j][k - 1] + arr1[k + 1][j + i - 1];

//                    cout<<i<<","<<j<<","<<k<<","<<t1<<","<<arr1[i][j]<<endl;

                    if (arr1[j][j + i - 1] < t1)
                        arr1[j][j + i - 1] = t1;
                }
            }
        }

        // 上三角矩阵
//        for (int i = 0; i < len; i++)
//        {
//            for (int j = 0; j < len; j++)
//            {
//                cout<<arr1[i][j]<<"  ";
//            }
//            cout<<endl;
//        }

        result = arr1[1][len - 2];

        return result;
    }
};


void fun_cout(int i)
{
    cout<<i<<",";
}

int main()
{
    cout<<"hi"<<endl;
    LT0312 lt = LT0312();
//    vector<int> v(2,1);           // 2ge 1
//    v.insert(v.begin(),3,5);

    int arr[] = {3,1,5,8};
    vector<int> v(arr, arr + 4);

    for_each(v.begin(), v.end(), fun_cout);

    int result = lt.lt0312a(v);
    cout<<result<<endl;
    return 0;
}
