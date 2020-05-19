
#include "../header/myheader.h"

class LT0765
{
public:



// detail
//        for (int i = 0; i < n; i++) {
//            irow[row[i]] = i;
//        }
// 用vector记录值所在的下标，而不是内嵌for搜索。row[i]范围是[0, row.size())

//            int a = row[i+1];
//            int b = (row[i]%2 == 0) ? row[i]+1 : row[i]-1;
//            if (a == b) continue;
//

// discuss
// union find
// https://leetcode.com/problems/couples-holding-hands/discuss/117520/Java-union-find-easy-to-understand-5-ms
//class Solution {
//    private class UF {
//        private int[] parents;
//        public int count;
//        UF(int n) {
//            parents = new int[n];
//            for (int i = 0; i < n; i++) {
//                parents[i] = i;
//            }
//            count = n;
//        }
//
//        private int find(int i) {
//            if (parents[i] == i) {
//                return i;
//            }
//            parents[i] = find(parents[i]);
//            return parents[i];
//        }
//
//        public void union(int i, int j) {
//            int a = find(i);
//            int b = find(j);
//            if (a != b) {
//                parents[a] = b;
//                count--;
//            }
//        }
//    }
//    public int minSwapsCouples(int[] row) {
//        int N = row.length/ 2;
//        UF uf = new UF(N);
//        for (int i = 0; i < N; i++) {
//            int a = row[2*i];
//            int b = row[2*i + 1];
//            uf.union(a/2, b/2);
//        }
//        return N - uf.count;
//    }
//}


//Runtime: 4 ms, faster than 25.72% of C++ online submissions for Couples Holding Hands.
//Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Couples Holding Hands.
    int lt0765a(vector<int>& row)
    {
        int ans = 0;
        int n = row.size() / 2;
        for (int i = 0; i < n; i++)
        {
            int a = row[i * 2];
            int b = row[i * 2 + 1];
            int min1 = min(a, b);
            int max1 = a + b - min1;
            if (min1 % 2 == 0 && min1 + 1 == max1)
            {
            }
            else
            {
                int tar = min1 % 2 == 0 ? min1 + 1 : min1 - 1;
                for (int j = i * 2 + 2; j < row.size(); j++)
                {
                    if (row[j] == tar)
                    {
                        ans++;
                        row[j] = max1;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<vector<int>> arr2 = {{0, 2, 1, 3}, {3, 2, 0, 1}};

    LT0765 lt;

    for (vector<int> arr : arr2)
    {
        cout<<lt.lt0765a(arr)<<endl;
    }

    return 0;
}
