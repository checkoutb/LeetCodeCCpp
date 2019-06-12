
#include "../header/myheader.h"

class LT0378
{
public:


// discuss

// 每一行都二分。。。
//		int n = matrix.size();
//		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
//		int mid = 0;
//		while (le < ri)
//		{
//			mid = le + (ri-le)/2;
//			int num = 0;
//			for (int i = 0; i < n; i++)
//			{
//				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
//				num += pos;
//			}
//			if (num < k)
//			{
//				le = mid + 1;
//			}
//			else
//			{
//				ri = mid;
//			}
//		}
//		return le;



// ...gg...
    int lt0378b(vector<vector<int>>& matrix, int k)
    {
        int result = 0;
        int sz1 = matrix.size();
        int arr1[sz1] = {-1};
        for (int i = 0; i < sz1; i++)
            arr1[i] = -1;

        int r = -1;
        bool flag1 = false;
        bool flag2 = true;
        while (k > 0)
        {
            r++;
            if (r == sz1 - 1)
            {
                if (flag1)
                {
                    break;
                }
                else
                {
                    flag1 = true;
                }
                arr1[r]++;
                r = -1;
                continue;
            }
            if (arr1[r] == sz1 - 1)
                continue;
            if (r >= 1 && arr1[r - 1] == -1)
            {
                r = -1;
                continue;
            }

            flag1 = false;

            int mi1 = arr1[r + 1] + 1;
            int m1 = matrix[r + 1][mi1];

            int m2 = INT_MAX;
            if (r >= 1 && (arr1[r - 1] + 1 < sz1))
            {
                m2 = matrix[r - 1][arr1[r - 1] + 1];
            }

            int i = arr1[r] + 1;
            for (; i < sz1; i++)
            {
                if (matrix[r][i] > m1)
                {
                    break;
                }
                if (matrix[r][i] > m2)
                {
                    break;
                }
            }
            i--;

            #ifdef __test
            cout<<k<<", "<<i<<", "<<arr1[r]<<", "<<r<<", "<<m1<<", "<<m2<<", "<<arr1[r - 1] + 1<<endl;
            system("pause");
            #endif // __test

            k = k - i + arr1[r];
            arr1[r] = i;
        }

        #ifdef __test
        cout<<k<<", "<<endl;
        for(auto& p : arr1)
            cout<<p<<", ";
        cout<<endl;
        #endif // __test

        // 最后一行？
        if (k > 0)
        {
//            arr1[r]
        }
        if (k < 0)
        {
            arr1[r] += k;
        }
        result = matrix[r][arr1[r]];
        return result;
    }


// ......36/85...前提错误了。。副对角线不一定必然大于前一个对角线。
    // 副对角线 必然大于前一个副对角线，但是对角线本身无法保证有序。所以是 1+...+n < k.  n+1.
    // n^2 + n - 2k = 0.
    // (-1 +- sqrt(1-(4*-2k)))/(2)
    // -0.5 + sqrt(1+8k)/2
    // 还有 经过 主对角线后，是减少。。是递减数列。
    int lt0378a(vector<vector<int>>& matrix, int k)
    {
        int result = 0;
        int sz1 = matrix.size();
        int half = (sz1 * (sz1 + 1)) / 2;
        if (k <= half)
        {
            double n0 = ((-1 + sqrt(1 + 8 * k)) / 2);
            int n1 = (int) n0;
            int n2 = n1 + (n0 - n1 > 0.00002 ? 1 : 0);        // 1+..+n == k 的时候。。n2 == n1..
            int t1 = (n1 * (n1 + 1)) / 2;
            int t2 = k - t1;
            // 第n2 个副对角线的 第t2大。。。大数据量的话应该用 最小堆。优先队列？

            #ifdef __test
            cout<<".."<<n1<<",,"<<n2<<".."<<t1<<".."<<t2<<endl;
            #endif // __test

            priority_queue<int> pri;
            for (int i = 0; i < n2; i++)
            {
                pri.push(matrix[i][n2 - i - 1]);
            }
            while (t2 > 0)
            {
                t2--;
                pri.pop();
            }
            result = pri.top();
        }
        else
        {
            // sz1-1 ... x......
            k = k - half;
            int t1 = sz1 - 1;
            while (k > t1)
            {
                k -= (t1--);
            }
//            t1++;
            int t2 = sz1 * 2 - 1 - t1;      // x+y
            priority_queue<int> pri;
            for (int i = sz1 - t1; i < sz1; i++)
            {
                pri.push(matrix[i][t2 - i]);
            }
            while (k > 0)
            {
                k--;
                pri.pop();
            }
            result = pri.top();
        }
        return result;
    }
};

int main()
{
//    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
//    int k = 8;
//    vector<vector<int>> matrix = {{-5}};
//    int k = 1;

//    vector<vector<int>> matrix = {{1,2},{3,3}};
//    int k = 2;

//    vector<vector<int>> matrix = {{1,3,5},
//                                  {6,7,12},
//                                  {11,14,14}};
//    int k = 9;

    vector<vector<int>> matrix = {{1,4,7,11,15},
                                  {2,5,8,12,19},
                                  {3,6,9,16,22},
                                  {10,13,14,17,24},
                                  {18,21,23,26,30}};
    int k = 20;



    LT0378 lt;
    cout<<endl<<lt.lt0378b(matrix, k)<<endl;

    return 0;
}
