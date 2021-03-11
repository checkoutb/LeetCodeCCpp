
#include "../header/myheader.h"

class LT1738
{
public:

// D D

//        nth_element(xorMat.begin(), xorMat.begin()+k-1, xorMat.end(), greater<int>());
//        return xorMat[k-1];


//        for(i = 0; i < n; i++)
//        {
//            for(j = 0; j < m; j++)
//            {
//                if(pq.size() < k)
//                    pq.push(matrix[i][j]);
//                else
//                {
//                   if(matrix[i][j] > pq.top())
//                   {
//                       pq.pop();
//                       pq.push(matrix[i][j]);
//                   }
//                }
//            }
//        }



//for (int i = 0; i < M; ++i) {
//	for (int j = 0; j < N; ++j) {
//
//		int x = (i - 1 < 0 ? 0 : dp[i - 1][j]);
//		int y = (j - 1 < 0 ? 0 : dp[i][j - 1]);
//		int z = (i - 1 < 0 || j - 1 < 0 ? 0 : dp[i - 1][j - 1]);
//
//		dp[i][j] = (x ^ y ^ z ^ matrix[i][j]);
//
//		pq.add(dp[i][j]);
//		if (pq.size() > k) pq.poll();
//	}
//}



//Runtime: 688 ms, faster than 36.91% of C++ online submissions for Find Kth Largest XOR Coordinate Value.
//Memory Usage: 90.3 MB, less than 99.70% of C++ online submissions for Find Kth Largest XOR Coordinate Value.
    int lt1738a(vector<vector<int>>& matrix, int k)
    {
        int sz1 = matrix.size();
        int sz2 = matrix[0].size();

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 1; j < sz2; ++j)
            {
                matrix[i][j] = matrix[i][j] ^ matrix[i][j - 1];
            }
        }
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                matrix[i][j] = matrix[i][j] ^ matrix[i - 1][j];
            }
        }

//        for (int i = 1; i < sz2; ++i)
//            matrix[0][i] = matrix[0][i - 1] ^ matrix[0][i];
//        for (int i = 1; i < sz1; ++i)
//        {
//            cout<<matrix[i][0]<<", "<<matrix[i - 1][0]<<", "<<(matrix[i][0] ^ matrix[i - 1][0])<<endl;;
//            matrix[i][0] = matrix[i][0] ^ matrix[i - 1][0];
//            for (int j = 1; j < sz2; ++j)
//            {
//                matrix[i][j] = matrix[i][j - 1] ^ matrix[i][j] ^ matrix[i - 1][j];
//            }
//        }
        for (int i = 0; i < sz1; ++i)
        {
            sort(begin(matrix[i]), end(matrix[i]));
        }
        #ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                cout<<matrix[i][j]<<", ";
            }
            cout<<endl;
        }
        #endif // __test
//        vector<int> vi(sz1, sz2 - 1);
        int ans = 0;

        priority_queue<tuple<int, int, int>> priq;
        for (int i = 0; i < sz1; ++i)
        {
            priq.push(std::make_tuple(matrix[i][sz2 - 1], i, sz2 - 1));
        }
        while (k-- > 0)
        {
            tuple<int, int, int> tup = priq.top();
            priq.pop();
            ans = std::get<0>(tup);
            #ifdef __test
            cout<<". "<<ans<<endl;
            #endif // __test
            if (get<2>(tup) > 0)
                priq.push(make_tuple(matrix[get<1>(tup)][get<2>(tup) - 1], get<1>(tup), get<2>(tup) - 1));
        }

//        priority_queue<pair<int, int>> priq;
//        for (int i = 0; i < sz1; ++i)
//        {
//            priq.push(std::make_pair(matrix[i][sz2 - 1], sz2 - 1));
//        }
//        while (k-- > 0)
//        {
//            pair<int, int> p = priq.top();
//            priq.pop();
//            priq.push(make_pair(matrix[][]))
//        }
        return ans;
    }

};

int main()
{
    myvvi vv = {{5,2},{1,6}};
//    int k{1};
//    int k{2};
//    int k{3};
    int k{4};

    LT1738 lt;

    cout<<lt.lt1738a(vv, k)<<endl;

    return 0;
}
