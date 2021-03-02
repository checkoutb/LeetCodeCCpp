
#include "../header/myheader.h"

class LT1720
{
public:

// D D

// xor

//	for (int &n : encoded) {
//		swap(n, first);
//		first ^= n;
//	}
//	encoded.push_back(first);
//	return encoded;


//        vector<int> res = {cur};
//        for (int& a: A)
//            res.push_back(cur ^= a);
//        return res;



//Runtime: 32 ms, faster than 70.73% of C++ online submissions for Decode XORed Array.
//Memory Usage: 24.7 MB, less than 96.07% of C++ online submissions for Decode XORed Array.
    vector<int> lt1720a(vector<int>& encoded, int first)
    {
        int sz1 = encoded.size();
        vector<int> ans(sz1 + 1);
        ans[0] = first;
        for (int i = 0; i < sz1; ++i)
        {
            ans[i + 1] = ans[i] ^ encoded[i];
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3};
//    int fst = 1;

    myvi v = {6,2,7,3};
    int fst = 4;

    LT1720 lt;

    myvi v2 = lt.lt1720a(v, fst);

    showVectorInt(v2);

    return 0;
}
