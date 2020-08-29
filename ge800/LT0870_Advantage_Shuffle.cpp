
#include "../header/myheader.h"

class LT0870
{
public:


// D D
//  multiset<int> s(begin(A), end(A));
//  for (auto i = 0; i < B.size(); ++i) {
//    auto p = *s.rbegin() <= B[i] ? s.begin() : s.upper_bound(B[i]);
//    A[i] = *p;
//    s.erase(p);
//  }
//  return A;


//        Arrays.sort(A);
//        int n=A.length;
//        int[] res= new int[n];
//        PriorityQueue<int[]> pq= new PriorityQueue<>((a,b)->b[0]-a[0]);
//        for (int i=0; i<n; i++) pq.add(new int[]{B[i], i});
//        int lo=0, hi=n-1;
//        while(!pq.isEmpty()){
//            int[] cur= pq.poll();
//            int idx=cur[1], val=cur[0];
//            if (A[hi]>val) res[idx]=A[hi--];
//            else res[idx]=A[lo++];
//        }


//        map<int, int> m;
//        for (int i : A) m[i]++;
//        map<int,int>::iterator it;
//        vector<int> res;
//        for (int i : B) {
//            it = m.upper_bound(i);
//            int x = it != m.end() ? it->first : m.begin()->first;
//            if (--m[x] == 0) m.erase(x);
//            res.push_back(x);
//        }
// 不必移动元素



//Runtime: 1260 ms, faster than 5.27% of C++ online submissions for Advantage Shuffle.
//Memory Usage: 32.9 MB, less than 99.38% of C++ online submissions for Advantage Shuffle.
    vector<int> lt0870a(vector<int>& A, vector<int>& B)
    {
        sort(begin(A), end(A));
        for (int i = 0; i < B.size(); i++)
        {
            vector<int>::iterator it = upper_bound(A.begin() + i, A.end(), B[i]);
            if (it == A.end())
                continue;
            int t3 = std::distance(A.begin(), it);
            int t4 = A[t3];
            for (int j = t3; j > i; j--)
            {
                A[j] = A[j - 1];
            }
            A[i] = t4;
        }
        return A;
    }

};

int main()
{

//    vector<int> a = {2,7,11,15};
//    vector<int> b = {1,10,4,11};

//    vector<int> a = {12,24,8,32};
//    vector<int> b = {13,25,32,11};

    vector<int> a = {9,1,2,4,5};
    vector<int> b = {6,2,9,1,4};


    LT0870 lt;

    vector<int> v = lt.lt0870a(a, b);

    for_each(begin(v), end(v), fun_cout);
    cout<<endl;

    return 0;
}
