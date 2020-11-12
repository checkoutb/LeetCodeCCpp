
#include "../header/myheader.h"

class LT1223
{
public:




// gg

// while (i>n) cnt--;  -6 -36...
// 6 6 5 6 6 5
// 5 6 6 5 6 6
// 6 5 6 6 5 6
    int lt1223a(int n, vector<int>& rollMax)
    {
        int arr[6] = {1,1,1,1,1,1};       // consecutive
        int arr2[6] = {1,1,1,1,1,1};      // all count
        int arr3[6] = {0};      // temp
        int ans = 0;
        n--;
        while (n-- > 0)
        {
            std::fill(begin(arr3), end(arr3), 0);

            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if (i == j && arr[i] % rollMax[i] == 0)
                        continue;
                    arr3[j] += arr2[i];
                }
                arr[i]++;
            }

            for (int i = 0; i < 6; i++)
                arr2[i] = arr3[i];
            #ifdef __test
            for (int v : arr2)
                cout<<v<<", ";
            cout<<endl;
            #endif // __test
        }
        ans = std::accumulate(std::begin(arr2), end(arr2), 0);
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,1,2,2,2,3};
////    vector<int> v = {1,1,1,1,1,1};
//    int n = 2;

    vector<int> v = {1,1,1,2,2,3};
    int n = 3;

    LT1223 lt;

    cout<<lt.lt1223a(n, v);

    return 0;
}
