
#include "../header/myheader.h"

class LT0941
{
public:

// D D
//      int start = 0;
//      int end = A.length-1;
//      while (start < end) {
//        if (A[start+1] > A[start]) {
//          start++;
//        } else if (A[end-1] > A[end]) {
//          end--;
//        } else {
//          break;
//        }
//      }
//      return start != 0 && end != A.length-1 && start == end;

//        int n = A.size(), i = 0, j = n - 1;
//        while (i + 1 < n && A[i] < A[i + 1]) i++;
//        while (j > 0 && A[j - 1] > A[j]) j--;
//        return i > 0 && i == j && j < n - 1;


//Runtime: 60 ms, faster than 90.39% of C++ online submissions for Valid Mountain Array.
//Memory Usage: 22.7 MB, less than 8.66% of C++ online submissions for Valid Mountain Array.
    bool lt0941a(vector<int>& A)
    {
        int t2 = 0;
        bool inc = true;
        if (A.size() < 3 || A[0] >= A[1] || A[A.size() - 1] >= A[A.size() - 2])
            return false;
        int lst = A[0] - 1;

        for (int i = 0; i < A.size(); i++)
        {
            t2 = A[i];
            if (t2 == lst)
                return false;

            if (inc)
            {
                if (t2 < lst)
                {
                    inc = false;
                }
            }
            else
            {
                if (t2 > lst)
                    return false;
            }
            lst = t2;
        }
        return true;
    }

};

int main()
{

//    vector<int> v = {2,1};
//    vector<int> v = {3,5,5};
    vector<int> v = {0,3,2,1};

    LT0941 lt;

    cout<<lt.lt0941a(v)<<endl;

    return 0;
}
