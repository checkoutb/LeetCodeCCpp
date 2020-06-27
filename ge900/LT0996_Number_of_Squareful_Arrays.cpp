
#include "../header/myheader.h"

class LT0996
{
public:


// D D
// pow((int)sqrt(A[i] + A[p]), 2) == A[i] + A[p])
// Swap
//  if (p == A.size() - 1) return 1;
//  unordered_set<int> s;
//  for (auto i = p + 1; i < A.size(); ++i) {
//    if (s.insert(A[i]).second && (p == -1 || pow((int)sqrt(A[i] + A[p]), 2) == A[i] + A[p])) {
//      swap(A[i], A[p + 1]);
//      res += numSquarefulPerms(A, p + 1);
//    }
//  }
//  return res;

// unordered_map<int, unordered_set<int>> cand;
// map.first + oneOfSecond is suqare.



//Runtime: 4 ms, faster than 51.18% of C++ online submissions for Number of Squareful Arrays.
//Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Number of Squareful Arrays.
// 996...ICU...
    int lt0996a(vector<int>& A)
    {
        unordered_set<int> squareSet;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int sqt = std::sqrt(A[i] + A[j]);
                if (sqt * sqt == A[i] + A[j])
                {
                    squareSet.insert(A[i] + A[j]);
                }
            }
        }
        int ans = 0;
        unordered_set<int> choosed;          // a better choice is map<A[i], counts>.....   chose...
        for (int i = 0; i < A.size(); i++)
        {
            int lst = A[i];
            A[i] = -1;
            if (choosed.find(lst) == choosed.end())
                ans += dfsa1(A, squareSet, lst);
            choosed.insert(lst);
            A[i] = lst;
        }
        return ans;
    }

    int dfsa1(vector<int>& A, unordered_set<int>& set2, int last)
    {
        int ans = 0;
        bool allNegative = true;
        unordered_set<int> choosed;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != -1)
            {
                allNegative = false;
                int sum2 = last + A[i];

                if (set2.find(sum2) != set2.end() && choosed.find(A[i]) == choosed.end())
                {
                    int lst = A[i];
                    A[i] = -1;
                    ans += dfsa1(A, set2, lst);
                    choosed.insert(lst);
                    A[i] = lst;
                }
            }
        }
        if (allNegative)
        {
            return 1;
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {2,2,2};
    vector<int> v = {1,17,8};

    LT0996 lt;

    cout<<lt.lt0996a(v)<<endl;

    return 0;
}
