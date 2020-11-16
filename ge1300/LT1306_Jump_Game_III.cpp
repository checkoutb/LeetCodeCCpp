
#include "../header/myheader.h"

class LT1306
{
public:

// D D

//    bool canReach(vector<int>& arr, int start) {
//        if (start >= 0 && start < arr.size() && arr[start] >= 0) {
//            if (arr[start] == 0) {
//                return true;
//            }
//            arr[start] = -arr[start];
//            return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
//        }
//        return false;
//    }
// arr[start] >= 0
//

//unordered_set<int> vis;
//bool canReach(vector<int>& arr, int st) {
//    if (st >= 0 && st < arr.size() && vis.insert(st).second) {
//        return arr[st] == 0 ||
//            canReach(arr, st + arr[st]) || canReach(arr, st - arr[st]);
//    }
//    return false;
//}


//    bool canReach(vector<int>& A, int i) {
//        return 0 <= i && i < A.size() && A[i] >= 0 && (!(A[i] = -A[i]) || canReach(A, i + A[i]) || canReach(A, i - A[i]));
//    }

// visited.


//Runtime: 72 ms, faster than 44.61% of C++ online submissions for Jump Game III.
//Memory Usage: 26.9 MB, less than 34.65% of C++ online submissions for Jump Game III.
    bool lt1306a(vector<int>& arr, int start)
    {
        unordered_set<int> can;
        can.insert(start);
        int sz2 = -1;
        while (sz2 != can.size())
        {
            sz2 = can.size();
            unordered_set<int> can2;
            for (int i : can)
            {
                if (arr[i] == 0)
                {
                    return true;
                }
                if ((i - arr[i]) >= 0)
                    can2.insert(i - arr[i]);
                if ((i + arr[i]) < arr.size())
                    can2.insert(i + arr[i]);
            }
            can.insert(begin(can2), end(can2));
        }
        return false;
    }

};

int main()
{
//    vector<int> v = {4,2,3,0,3,1,2};
//    int t = 5;

    vector<int> v = {4,2,3,0,3,1,2};
    int t = 0;

//    vector<int> v = {3,0,2,1,2};
//    int t = 2;

    LT1306 lt;

    cout<<lt.lt1306a(v, t);

    return 0;
}
